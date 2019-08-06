#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int listenSocket;

void startServer()
{
    /*
     * Create and configure a socket to wait for incoming requests here.
     * You can find more info about the necessary syscalls (bind, listen, socket) in the lecture slides.
     * Look in the appendix of the "Rechnernetze" slide set.
     * Extend the following lines of code and fix the order of the syscalls.
     */
	
	
    struct sockaddr_in my_addr;
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(8080);
    my_addr.sin_addr.s_addr = INADDR_ANY;
    
    if((listenSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        printf("Fehler! Kann Socket nicht erstellen.\n");
    
    if (bind(listenSocket, (struct sockaddr *) &my_addr, sizeof(my_addr)) == -1){
        printf("Fehler");
        exit(1);
    }
    
    listen(listenSocket, 1);
    
    
}

void handleConnections()
{
    /* Once the socket is ready, this function shall answer incoming requests.
     * You can start by sending back a fixes string containing the necessary HTTP text.
     *
     * To debug, use telnet or netcat
     */
    struct sockaddr_in cl_addr;
    socklen_t atts = sizeof(cl_addr);
    int connection_f = accept(listenSocket, (struct sockaddr *) &cl_addr , &atts);

    printf("%ld",send(connection_f, "Hallo World", 12, 0));

    /*
     * Once the simple request works, extend the program here.
     * It should read and parse the HTTP-request from a client.
     */
    //recv(connection_f, ..., ..., ...);
    //fopen();
    //send();
}

int main()
{
    startServer();
    handleConnections();
    close(listenSocket);
    return 0;
}
