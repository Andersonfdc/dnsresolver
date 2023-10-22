#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <stdbool.h>

int main (int argc, char *argv[]){

	char *alvo;
	alvo = argv[1];
	struct hostname *host;
	char *result;
	char txt[2000000];
	FILE *subdomains;
	subdomains = fopen(argv[3],"r");
	int meusocket;
        int conecta;
        struct sockaddr_in alvo2;

	printf("\x1b[1;34m ######   ##   ##   #####            ######   #######   #####    #####    ####     ##  ##  #######  ######  \x1b[0m\n");
 	printf("\x1b[1;34m ##   ##  ###  ##  ##   ##            ##  ##   ##  ##  ##   ##  ##   ##    ##      ##  ##   ##  ##   ##  ##  \x1b[0m\n");
 	printf("\x1b[1;34m ##   ##  #### ##  ##                 ##  ##   ##      ##       ##   ##    ##      ##  ##   ##       ##  ##  \x1b[0m\n");
 	printf("\x1b[1;34m ##   ##  ## ####   #####             #####    ####     #####   ##   ##    ##      ##  ##   ####     #####  \x1b[0m\n");
 	printf("\x1b[1;34m ##   ##  ##  ###       ##            ####     ##           ##  ##   ##    ##      ##  ##   ##       ####  \x1b[0m\n");
 	printf("\x1b[1;34m ##   ##  ##   ##  ##   ##            ## ##    ##  ##  ##   ##  ##   ##    ## ##    ####    ##  ##   ## ##  \x1b[0m\n");
 	printf("\x1b[1;34m ######   ##   ##   #####            ###  ##  #######   #####    #####    ######     ##    #######  ###  ##  \x1b[0m\n");

	printf("\n");
	printf("by Anderson Costa \n");
	printf("MODO DE USO: ./dnsresolver .alvo.com.br porta subdomains.txt \n");
	printf("versão 1.2 \n");


	if(argc<=3){
		printf("\n\n");
		printf("\x1b[1;31m[*] Verifique o modo de uso \x1b[0m");
		return 0;
	} else {
		
		printf("\n");
		printf("\x1b[1;32m[+] Realizando busca... \x1b[0m");
		printf("\n\n\n");
		while(fscanf(subdomains,"%s",&txt) != EOF){
			result = (char *) strcat(txt,alvo);
			struct hostent *host=gethostbyname(result);
			if(host == NULL){
				continue;
			}
				printf("\x1b[1;33m HOST ENCONTRADO: %s =====> IP: %s \x1b[0m", result, inet_ntoa(*((struct in_addr *)host->h_addr)));
				
							
				meusocket = socket (AF_INET, SOCK_STREAM, 0);
        			alvo2.sin_family = AF_INET;
        			alvo2.sin_port = htons((uint16_t) atoi(argv[2]));
        			alvo2.sin_addr.s_addr = inet_addr (inet_ntoa(*((struct in_addr *)host->h_addr)));

        			conecta = connect(meusocket, (struct sockaddr *)&alvo2, sizeof alvo2);
				
				
        			if(conecta == 0){
                			printf("\x1b[1;36m ======> Porta %s Aberta \x1b[0m\n", argv[2]);
                			close (meusocket);
                			close (conecta);
        			} else {
                			printf("\x1b[31m ======> Porta %s Fechada \x1b[0m\n", argv[2]);
        			}
			
			}

	}


return 0;

}
