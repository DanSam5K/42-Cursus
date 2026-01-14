#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/select.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>

//s_client = name if the struct, t_client = data type of the struct
typedef struct s_client
{
    int id;
    char msg[1024];
}   t_client;

//store client socket desc
t_client    clients[1024];

//fd_set is a struct repre fds
fd_set      writeFds;
fd_set      readFds;
fd_set      active;

// Identifier.3.
int         fdMax = 0;
char        idNext = 0;
char        bufferRead[120000], bufferWrite[120000];

// Take care of all error management
void ft_error(char *string)
{
    if (string)
        write(2, string, strlen(string));
    else
        write(2, "Fatal error", strlen("Fatal error"));
    write(2, "\n", 1);
    exit(1);
}

// This part is reusing the send utitlity for each section
void send_all(int fd)
{
    for (int i = 0; i <= fdMax; i++)
    {
        if (FD_ISSET(i, &writeFds) && i != fd)
        {
            send(i, bufferWrite, strlen(bufferWrite), 0);
        }
    }
}

int main(int argc, char **argv)
{
    //check if number of argument is correct
    if (argc != 2)
        ft_error("Wrong number of arguments");
    
    // create a socket with IPV4 addressing and TCP or returns -1
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);

    // check if socjket creation failed
    if (socketfd < 0)
        ft_error(NULL);

    // Initialize active sockets set
    FD_ZERO(&active);
    bzero(&clients, sizeof(clients));
    fdMax = socketfd;
    FD_SET(socketfd, &active);

    //set up the servers
    struct sockaddr_in serveraddr;
    socklen_t          len;
    bzero(&serveraddr, sizeof(serveraddr));

    // bind the newly created server socket to the IP
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(2130706433);
    serveraddr.sin_port = htons(atoi(argv[1]));

    // bind the newly created server socket to the IP
    if ((bind(socketfd, (const struct sockaddr *) &serveraddr, sizeof(serveraddr))) < 0)
        ft_error(NULL);

    // Put the socket in listening mode
    if (listen(socketfd, 10) < 0)
        ft_error(NULL);

    while(1)
    {
        // wait for activity on sockets and copy active sockets to select
        readFds = writeFds = active;

        // select files lower than fdMax + 1 which can be lower than read and writes fds
        // return -1 on error
        if (select(fdMax + 1, &readFds, &writeFds, NULL, NULL) < 0)
            continue;

        // check each socket for activity
        for (int fdI = 0; fdI <= fdMax; fdI++)
        {
            if (socketfd < 0)
                ft_error(NULL);

            // accept and  returns new sockfd for the connection or -1 on error
            if (FD_ISSET(fdI, &readFds) && fdI == socketfd)
            {
                // This is where we accept connections; new client connection
                int connfd = accept(socketfd, (struct sockaddr *)&serveraddr, &len);
                if (connfd < 0)
                    continue;
                
                // Add the new client socket to the active set
                fdMax = connfd > fdMax ? connfd : fdMax;
                clients[connfd].id = idNext++;
                FD_SET(connfd, &active);
    
                // Send a welcome message to the client socket sprintf() send formatted output
                sprintf(bufferWrite, "server: client %d just arrived\n", clients[connfd].id);
                send_all(connfd);
                break;
            }

            // When its not sockfd but another client
            if (FD_ISSET(fdI, &readFds) && fdI != socketfd)
            {
                // Recieve a message from a connected socket
                int res = recv(fdI, bufferRead, 65536, 0);
                if (res <= 0)
                {
                    // Client disconnected
                    sprintf(bufferWrite, "server: client %d just left", clients[fdI].id);
                    send_all(fdI);

                    // Close the socket and remove it from the active set
                    FD_CLR(fdI, &active);
                    close(fdI);
                    break;
                }
                else
                {
                    for (int i = 0, j = strlen(clients[fdI].msg); i < res; i++, j++)
                    {
                        clients[fdI].msg[j] = bufferRead[i];
                        if (clients[fdI].msg[j] == '\n')
                        {
                            // Broadcast the received message to all other clients
                            clients[fdI].msg[j] = '\0';
                            sprintf(bufferWrite, "client %d: %s\n", clients[fdI].id, clients[fdI].msg);
                            send_all(fdI);
                            bzero(&clients[fdI].msg, strlen(clients[fdI].msg));
                            j = -1;
                        }
                    }
                    break;

                }
    
            }
        }

        
    }

}
