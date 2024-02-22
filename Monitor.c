#include "Util.h"

bool fimSimulacao = false;
int numClientesDiscotecaMonitor = 0;
int tempEsperaP = 0;

void recebeMensaSimulador(int newsockfd){

    int mensagemChegou = 0;
    int estado = 0;
    int numPessoasSistema = 0;
    int numZona1 = 0;
    int numZona2 = 0;
    int numZona3 = 0;
    int numZona4 = 0;
    int numZona5 = 0;
    int numPessoasPista1 = 0;
    int numPessoasPista2 = 0;
    int tempo = 0;
    int numClientesDisco = 0;

    int tempMedioEsperaP = 0;

    FILE* output=fopen("output.txt","a");

    if(output==NULL){
		printf("Erro, ficheiro não criado");
	}
    else{
		while(estado!=20){
			char linhaRecebe[MAXLINE+1];
			mensagemChegou=recv(newsockfd,linhaRecebe,MAXLINE,0);

            sscanf(linhaRecebe,"%d %d %d %d %d %d %d %d %d %d",&estado,&numClientesDisco,&numZona1,&numZona2,&numZona3,&numZona4,&numZona5,&numPessoasPista1,&numPessoasPista2,&tempo);

            switch(estado){
                case 1:{
                    fprintf(output,"Simulacao - Discoteca \n");					
					printf("Simulacao - Discoteca \n");							
					break;
                }
                case 2:{
                    fprintf(output,"Clientes: %d\n", numClientesDisco);
                    printf("Clientes: %d\n", numClientesDisco);
                }
                case 3:{
                    fprintf(output,"Zona 1: %d\n", numZona1);
                    printf("Zona 1: %d\n", numZona1);
                }
                case 4:{
                    fprintf(output,"Zona 2: %d\n", numZona2);
                    printf("Zona 2: %d\n", numZona2);
                }
                case 5:{
                    fprintf(output,"Zona 3: %d\n", numZona3);
                    printf("Zona 3: %d\n", numZona3);
                }
                case 6:{
                    fprintf(output,"Zona 4: %d\n", numZona4);
                    printf("Zona 4: %d\n", numZona4);
                }
                case 7:{
                    fprintf(output,"Zona 5: %d\n", numZona5);
                    printf("Zona 5: %d\n", numZona5);
                }
                case 8:{
                    fprintf(output, "Pista 1: %d\n", numPessoasPista1);
                    printf("Pista 1: %d\n", numPessoasPista1);
                }
                case 9:{
                    fprintf(output, "Pista 12: %d\n", numPessoasPista2);
                    printf("Pista 2: %d\n", numPessoasPista2);
                }
                /*
                case 10:{
                    tempEsperaP += tempo;
                    numClientesDiscotecaMonitor += numPessoasDisco;

                    tempMedioEsperaP = (double)tempEsperaP / (double)numClientesDiscotecaMonitor;

                    fprintf(output, "Tempo médio na Discoteca: %d\n",tempMedioEsperaP);
                    printf("Tempo médio na Discoteca: %d\n",tempMedioEsperaP);
                }
                */
            }
        }
    }
    if (estado==20){
        fprintf(output,"Fim da simulação da Discoteca, Volte Sempre");
        printf("Fim da simulação da Discoteca, Volte Sempre");
        fclose(output);
    }
}

void iniciaSimulador(){
    int sockfd, newsockfd, clilen, childpid, servlen;
	struct sockaddr_un cli_addr, serv_addr;

    if ((sockfd = socket(AF_UNIX,SOCK_STREAM,0))<0){
		perror ("server: Nao consegue abrir o stream socket");
	}

    bzero((char*)&serv_addr, sizeof(serv_addr));
	serv_addr.sun_family = AF_UNIX;
	strcpy(serv_addr.sun_path, UNIXSTR_PATH);
	servlen = strlen(serv_addr.sun_path) + sizeof(serv_addr.sun_family);
	unlink(UNIXSTR_PATH);

    if(bind(sockfd, (struct sockaddr *) &serv_addr, servlen) < 0){
	perror("O socket nao consegue ligar ao endereco especificado");
	}

    printf("Esperar Simulador \n");
	listen (sockfd,1);

    clilen = sizeof(cli_addr);
	newsockfd = accept (sockfd, (struct sockaddr *) &cli_addr, &clilen);
	if(newsockfd < 0){
		perror ("ERRO: erro na criacao do socket");
	}

    if((childpid = fork()) < 0){
		perror("ERRO: nao foi possivel criar o processo filho");
	}
	else if(childpid==0){
		close(sockfd);
		recebeMensaSimulador(newsockfd);
		exit(0);
	}

    close(newsockfd);
}

int main(int argc, char const * argv[]){

    printf ("Clique 1 para inicializar a simulação \n");
    
    int um = 0;
    
    while(!fimSimulacao){
        while(um !=1){
            printf("Selecione a opção pretendida:");
            scanf("%d",&um);
        }

        if (um == 1) {
            iniciaSimulador();
        }

    }
    return 0;
}