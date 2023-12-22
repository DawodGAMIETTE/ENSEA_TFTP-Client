#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <netdb.h>
#include <stdlib.h>

// #include "main.h"

int main(int argc,char* argv[]){
    struct addrinfo hints;
    struct addrinfo *res;
    memset(&hints,0,sizeof (hints));

    //configuration of socktype
    hints.ai_family=AF_INET; //"IPv4"~2
    hints.ai_protocol=IPPROTO_TCP; // "TCP"~6
    hints.ai_socktype=SOCK_STREAM; //1

    printf("Hello\n");
    char* host=argv[1];

    int statut=getaddrinfo(host,NULL,&hints,&res);

    printf("After\n");

    //Reservation of a socket to the server

     int sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    //int sockfd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
    if (sockfd== -1){
        printf("EXIT_FAILURE");
        exit(0);
    }

    printf("After socket\n");

    // connect(sockfd,res->ai_addr,res->ai_addrlen);
    char msg[256];
    msg[0]='\1'; //Read mode
    //msg[1]='\1';
    for (int i=0;i< strlen(argv[2]);i++){
        msg[1+i]=argv[2][i];
    }
    //msg[2+ strlen(argv[2])]='\0';

    strcpy(&msg[2+ strlen(argv[2])],"netascii"); //transfer mode
    msg[2+ strlen(argv[2])+ strlen("netascii")]='\0'; // end of the message to send
    send(sockfd,msg,strlen(msg),0); //request sent

    /* Reception*/
    char* data;
    // ssize_t reply=recv(sockfd,data,sizeof data,0);

    close(sockfd);
    freeaddrinfo(res);
}