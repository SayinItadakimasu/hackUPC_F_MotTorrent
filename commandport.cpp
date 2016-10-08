#include <cstdio>
#include <iostream>
#include <netinet/in.h>
#include <stdlib.h>
#include <malloc.h>
#include <unistd.h>
#include <boost/thread/thread.hpp>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

typedef void (*command_handler_funcType)(char *bufferStart, size_t bufferSize);

void command_handler(char *bufferStart, size_t bufferSize) //this function is responsible for free()ing bufferStart once it's done with it.
{

}

void accept_connection(int socket)
{
    int connection_fd = accept(socket, NULL, NULL); //we use NULL because we don't care who is connecting to us
    boost::thread listener_thread(&accept_connection,socket); //after accepting and binding to a new connection, we launch a listener right away again
    listener_thread.detach();

    size_t recv_buffer_size = 1024;
    char *recv_buffer = (char*) malloc(recv_buffer_size);
    unsigned int total_bytes_read = 0;
    ssize_t partial_bytes_read;
    do
    {
        partial_bytes_read = read(connection_fd,recv_buffer+total_bytes_read,recv_buffer_size-total_bytes_read);
        total_bytes_read += partial_bytes_read;
    } while (partial_bytes_read != 0);

    write(1,recv_buffer,total_bytes_read);
}


void init_listener(command_handler_funcType command_handler) //this parameter is the callback that will be executed once we have received the data
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

    boost::thread listener_thread(&accept_connection,listen_socket, command_handler);
    listener_thread.detach();

}


int main(int argc, char *argv[])
{
    init_listener();
    while(1);
    return 0;
}