#include <cstdio>
#include <netinet/in.h>
#include <stdlib.h>
#include <malloc.h>
#include <unistd.h>
#include <thread>
#include <json.hpp> //from

static const int PADLENGTH = 10;

void error(const char* msg) {
    perror(msg);
    exit(1);
}

/* Commands accepted
 * allStatus
 * addMagnet
 *
 * The command format is: 'commandName', followed by '\n', followed by 'bodyPayload' until the end of the message.
 */

void process_client_command(const char* bufferBegin, size_t bufferSize, int socket_fd) {
    char* message;

    write(1, bufferBegin, bufferSize); //DEBUG write

    size_t commandLength = strcspn(bufferBegin, "\n");

    if (!memcmp(bufferBegin, "getStatus", commandLength))
    {
        //return status of all torrents
    }
    else if (!memcmp(bufferBegin, "addMagnet", commandLength))
    {
        //add a magnet link (found in the body)
    }
    else
    {
        //invalid/unrecognized question.

    }

    write(socket_fd, message, sizeof(message));
    write(1, message, sizeof(message));

    free(message); //RESPONSIBLE deallocates here

    close(socket_fd);
}


void accept_connection(int socket) {
    int connection_fd = accept(socket, NULL, NULL); //we use NULL because we don't care who is connecting to us

    std::thread(accept_connection, socket).detach();

    size_t recv_buffer_size = 1024;
    char* recv_buffer = (char*) malloc(recv_buffer_size); //RESPONSIBLE for deallocating
    char msglentext[10];

    read(connection_fd, msglentext,
         PADLENGTH); //the 1st PADLENGTH bytes of the connection represent (in ascii) the number of bytes that follow
    size_t msglen = atoi(msglentext); //consider safety-checking this to be an actual number (using strtol or some such)
    while (msglen > 0)
        msglen -= read(connection_fd, recv_buffer,
                       msglen); //read exactly the number of bytes we've been told we're about to receive
    //TODO handle the case that we reach TCP EOF (read returns 0) before we read the advertised number of bytes - the above instruction would hang forever then.
    process_client_command(recv_buffer, msglen, connection_fd);

    free(recv_buffer); //RESPONSIBLE deallocates here
}

void init_listener() //this parameter is the callback that will be executed once the socket is bound and listening
{
    /* Establishes a command listener in port 8492
     * Will listen for connections, accept them, then fork off a thread that reads the data into a command buffer
     */
    //TODO consider SO_REUSEPORT (man 7 socket) as the solution to the "thundering-herd" problem?
    in_port_t listen_port = 8492;
    int max_waiting_connections = 5;
    struct sockaddr_in serv_addr;
    int listen_socket = socket(AF_INET, SOCK_STREAM,
                               0); //TODO use SO_REUSEADDR (man 2 setsockopt, man 7 socket) to prevent the TIME_WAIT annoyance
    if (listen_socket < 0)
        error("Socket syscall failed/");
    serv_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(listen_port);
    if (bind(listen_socket, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
        error("Bind failed/");
    if (listen(listen_socket, max_waiting_connections) < 0)
        error("Listen failed/"); //start accepting connections on the socket

    std::thread(accept_connection, listen_socket).detach(); //launch AND detach a listener
}


int main(int argc, char* argv[]) {
    init_listener();
    pthread_exit(NULL); //This statement here because the main thread doesn't need to hang around
}