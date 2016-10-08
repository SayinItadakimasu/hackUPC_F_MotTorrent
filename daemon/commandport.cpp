#include <cstdio>
#include <iostream>
#include <netinet/in.h>
#include <stdlib.h>
#include <malloc.h>
#include <unistd.h>
#include <pthread.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

typedef struct {
    char *bufferBegin; //this is the start of the buffer that holds the client's command
    size_t bufferSize;
    int socket_fd; //this is the socket where we'll write the result of the opretaion
} process_client_command_param;

void* process_client_command(void *p)
{
    process_client_command_param ps = *(process_client_command_param*) p;
    char *bufferBegin = ps.bufferBegin;
    size_t bufferSize = ps.bufferSize;
    int socket_fd = ps.socket_fd;

    write(1, bufferBegin, bufferSize);

    char message[] =  "This is the result of the operation";
    write(socket_fd, message, sizeof(message));
    write(1, message, sizeof(message));

    close(socket_fd);
}

typedef typeof(process_client_command) process_client_command_funcType;

typedef struct {
    int socket; //this is the socket that's bound & listening for connections
} accept_connection_param;

void* accept_connection(void *p)
{
    accept_connection_param ps = *(accept_connection_param*) p;                     // unpack the
    int socket = ps.socket;                                                         // function parameters

    int connection_fd = accept(socket, NULL, NULL); //we use NULL because we don't care who is connecting to us

    pthread_t new_listener_thread;
    accept_connection_param acp;
    acp.socket = socket;

    pthread_create(&new_listener_thread, NULL, accept_connection, &acp); //after accepting and binding to a new connection, we launch a listener right away again
    pthread_detach(new_listener_thread);

    size_t recv_buffer_size = 1024;
    char *recv_buffer = (char*) malloc(recv_buffer_size);

    char msglentext[10];

    read(connection_fd, msglentext, 10); //the 1st 10 bytes of the connection represent the number of bytes that follow (in ascii)

    size_t msglen = atoi(msglentext);

    read(connection_fd,recv_buffer,msglen); //read exactly the number of bytes we've been told we're about to receive

    process_client_command_param pccp;
    pccp.bufferBegin = recv_buffer;
    pccp.bufferSize = msglen;
    pccp.socket_fd = connection_fd;
    process_client_command(&pccp);

    free(recv_buffer);

    return NULL;
}

typedef typeof(accept_connection) accept_connection_funcType;

void init_listener() //this parameter is the callback that will be executed once the socket is bound and listening
{
    /* Establishes a command listener in port 8492
     * Will listen for connections, accept them, then fork off a thread that reads the data into a command buffer
     */
    in_port_t listen_port = 8492;
    int max_waiting_connections = 5;
    struct sockaddr_in serv_addr;
    int listen_socket = socket(AF_INET,SOCK_STREAM,0);
    if (listen_socket < 0)
        error("Socket syscall failed/");
    serv_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(listen_port);
    if (bind(listen_socket, (struct sockaddr*) &serv_addr, sizeof(serv_addr) ) < 0)
        error("Bind failed/");
    if (listen(listen_socket,max_waiting_connections) < 0)
        error("Listen failed/"); //start accepting connections on the socket

    accept_connection_param p;
    p.socket = listen_socket;
//    p.callback_function = process_client_command;
    pthread_t new_listener_thread;
    pthread_create(&new_listener_thread, NULL, accept_connection, &p);
    pthread_detach(new_listener_thread);

}


int main(int argc, char *argv[])
{
    init_listener();
    while(1);
    return 0;
}