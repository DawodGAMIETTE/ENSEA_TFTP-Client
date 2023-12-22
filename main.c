#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <netdb.h>

#include "main.h"

int main(int argc,char* argv[]){
    struct addrinfo hints;
    struct addrinfo *res;
    memset(&hints,0,sizeof hints);
    //configuration of socktype
    hints.ai_family=AF_INET; //"IPv4"~2
    hints.ai_protocol=IPPROTO_TCP; // "TCP"~6
    hints.ai_socktype=SOCK_STREAM; //1

    int statut=getaddrinfo(argv[1],NULL,&hints,&res);

    //Reservation of a socket to the server

        int sockfd=socket(res->ai_family,res->ai_socktype,res->ai_protocol);
        //connect(sockfd,res->ai_addr,res->ai_addrlen);
        char msg[256];
        msg[0]='1'; //Read mode
        for (int i=0;i< strlen(argv[1]);i++){
            msg[1+i]=argv[1][i];
        }
        strcpy(&msg[1+ strlen(argv[1])],"netascii"); //transfer mode
        msg[1+ strlen(argv[1])+ strlen("netascii")]='\0'; // end of the message to send
    write(sockfd,argv[2],strlen(argv[2])); //request sent

    /* Reception*/
    char* data;
    ssize_t reply=recv(sockfd,data,sizeof data,0);

    close(sockfd);
    freeaddrinfo(res);
}