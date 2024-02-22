#include "Util.h"

//*********************************************************************************************************//
//											Variáveis											     	  //	
//*******************************************************************************************************//

// ------------ SOCKETS: ------------
int sockfd = 0;

// ------------ Semaforos: ------------
sem_t SemInformacaoEnviar;																		//Controla o número de mensagem que são enviadas

sem_t SemFilaPrioridadeDiscoteca;    															//Controla o número de pessoas com prioridade que estão na fila
sem_t SemFilaNPrioridadeDiscoteca;																//Controla o número de pessoas sem prioridade que estão na fila
sem_t SemEsperaVezNP;																			//Bloquear os processos com prioridade 0 quando existem processos na fila das prioridades.

sem_t SemNumPessoasNaDisco;																		//Controla o número de pessoas que se entram na Disco

sem_t SemNumPessoasNaPista1;
sem_t SemNumPessoasNaPista2;

sem_t SemEsperaZona1;																			
sem_t SemEsperaZona2; 																			
sem_t SemEsperaZona3;																			
sem_t SemEsperaZona4; 																			
sem_t SemEsperaZona5;																			

sem_t SemNumPessoasZona1;																		//Controla o número máximo de pessoas nas zona 1
sem_t SemNumPessoasZona2;																		//Controla o número máximo de pessoas nas zona 2
sem_t SemNumPessoasZona3;																		//Controla o número máximo de pessoas nas zona 3
sem_t SemNumPessoasZona4;																		//Controla o número máximo de pessoas nas zona 4
sem_t SemNumPessoasZona5;																		//Controla o número máximo de pessoas nas zona 5

sem_t semEsperaEntrarZona1;																		//Mantem na Zona enquanto não é possível entrar na pista
sem_t semEsperaEntrarZona2;
sem_t semEsperaEntrarZona3;
sem_t semEsperaEntrarZona4;
sem_t semEsperaEntrarZona5;


//struct discoteca [1];	

//------------ Trincos: ------------

pthread_mutex_t ordem;	

pthread_mutex_t trinconumClientesSimu;																	//protege a variável numClientesSimu
pthread_mutex_t trincoEntradaPistaDanca;																//Vai controlar a colocação na pista de danca 

pthread_mutex_t trincoCliente;

pthread_mutex_t trincoAcompanhaZona1;
pthread_mutex_t trincoAcompanhaZona2;
pthread_mutex_t trincoAcompanhaZona3;
pthread_mutex_t trincoAcompanhaZona4;
pthread_mutex_t trincoAcompanhaZona5;
pthread_mutex_t trincoCalculaZona;																		

pthread_mutex_t trincoFilaZona1;
pthread_mutex_t trincoFilaZona2;
pthread_mutex_t trincoFilaZona3;
pthread_mutex_t trincoFilaZona4;
pthread_mutex_t trincoFilaZona5;		

pthread_mutex_t trinconumZona1Simu;

pthread_mutex_t trincoClienteEsperaZona;																							

pthread_mutex_t trincoRemoveZona1;
pthread_mutex_t trincoRemoveZona2;

pthread_mutex_t trincoAcompanhaPista;
pthread_mutex_t trincoAcompanhaPista2;																//Contorla a ordem que as pessoas voltam na pista 
pthread_mutex_t controlaEntradaPista;
pthread_mutex_t mensagemPista1;																			//Controla as mensagens referentes às pessoas a voltar a pista
pthread_mutex_t mensagemPista2;																			//Controla as mensagens referentes às pessoas a voltar a pista
pthread_mutex_t trincoEspera1;
pthread_mutex_t trincoEspera2;
pthread_mutex_t trincoEspera3;
pthread_mutex_t trincoEspera4;
pthread_mutex_t trincoEspera5;



//--------- Tarefas ------------------

//pthread_t IDTarefasDiscoteca;
pthread_t IDTarefasClientes[50];																		//Array com o ID das tarefas correspondentes à criação de clientes.

//--------- Variaveis do ficheiro: ------------

int numMaxPessoasACriar = 50; 																			//numero máximo de pessoas a criar para este projeto

int probDesistir = 50;																					//probabilidade de Desistir. Esta no ficheiro do ponto de vista de percentagem

//Variaveis

//---------- Variáveis globais -------------
int idCliente = 0;

int numPessoasPista1 = 0;																						//Guarda o número de pessoas na Pista 1
int numPessoasPista2 = 0;																						//Guarda o número de pessoas na Pista 2

int closer = 0;
int closer2 = 0;

int filaCPLugaresDisco = 15;																					//Guarda o número de lugares livres na fila das prioridades da Disco
int numLugaresLivresDisco = 50;																					//Simula o contador do semaforo	SemNumPessoasDisco

int esperarNPrioritario = 0;																					//Vai permitir saber quando é que um não prioritário esta á espera de maneira a que faça post do semaforo SemEsperaVezNP apenas quando é necessário 

int numLugaresLivresZona1 = 5;																					//Numero de lugares vazios na Zona 1
int numLugaresLivresZona2 = 5;																					//Numero de lugares vazios na Zona 2
int numLugaresLivresZona3 = 5;																					//Numero de lugares vazios na Zona 3
int numLugaresLivresZona4 = 5;																					//Numero de lugares vazios na Zona 4
int numLugaresLivresZona5 = 5;																					//Numero de lugares vazios na Zona 5

int esperaZona1 =  0;																							//0, Significa que existe lugares na zona 1
int esperaZona2 =  0;																							//0, Significa que existe lugares na zona 2
int esperaZona3 =  0;																							//0, Significa que existe lugares na zona 3
int esperaZona4 =  0;																							//0, Significa que existe lugares na zona 4
int esperaZona5 =  0;																							//0, Significa que existe lugares na zona 5

int numFilaZona1 = 6;																						//Guarda o número de lugares livres na fila da zona 1
int numFilaZona2 = 6;																						//Guarda o número de lugares livres na fila da zona 2
int numFilaZona3 = 6;																						//Guarda o número de lugares livres na fila da zona 3
int numFilaZona4 = 6;																						//Guarda o número de lugares livres na fila da zona 4
int numFilaZona5 = 6;																						//Guarda o número de lugares livres na fila da zona 5

int numPessoasZona1 = 0;
int numPessoasZona2 = 0;
int numPessoasZona3 = 0;
int numPessoasZona4 = 0;
int numPessoasZona5 = 0;


int desistir = 0;
int giveUp = 0;	
int NovaZona = 2;
int probabilidade = 1;

//Variaveis para o monitor

int numClientesSimu = 0;																						//Conta o número total de clientes


//Função de ler o ficheiro ConfiguracaoSimulacao.txt
/*
void leitura(){

	FILE* config;

		config = fopen("configuracaoSimulacao.txt", "r"); 												
		                                                   												
		if(config != NULL){

			char linha[50];
			int valor;
			char parametro[50];

			while(fgets(linha, sizeof(linha), config) != NULL){
				//valor = strtok(linha, ":");
				sscanf(linha, "%s : %d", parametro , &valor);
				if(strcmp(parametro, "numeroMaxPessoasACriar") == 0){
					numMaxPessoasACriar = valor;
				}
				if(strcmp(parametro, "probabilidadeDeDesistencia") == 0){
					probDesistir = valor;												 				
				}
			}
			fclose(config);
		}
		else {
			printf("====== Erro ao abrir o Ficheiro. Tente Novamente. ======\n ");
	}
}
*/

//Funcao responsavel por criar um socket 
int criarSocket(){

     struct sockaddr_un serv_addr;																			//endereco do servidor
     int servlen;																							//comprimento do servidor

     //Comecamos por criar o socket
     if ((sockfd = socket(AF_UNIX, SOCK_STREAM,0))<0)  														// cria o socket stream
        perror(" Erro ao criar o stream socket! ");

    //Socket a 0 -> Limpeza
    bzero((char*)&serv_addr, sizeof(serv_addr));

    //Informa o dominio do socket
    serv_addr.sun_family=AF_UNIX;
	strcpy(serv_addr.sun_path,UNIXSTR_PATH);
   	servlen=strlen(serv_addr.sun_path)+sizeof(serv_addr.sun_family);

   	//Realiza a ligacao com o socket
   	bool simulacaoOcorre = false;
   	while (connect(sockfd, (struct sockaddr *) &serv_addr, servlen) < 0){
   		if(simulacaoOcorre == false){
			printf("Espera monitor \n");
			simulacaoOcorre = true;
		}
	}

	if(sockfd<0){
		perror ("ACCEPT ERROR");
	}

	printf ("Simulador feito \n");
	return sockfd;
}


// Funcao responsável por enviar a mensagem pelo socket

void InformacaoEnviar(int sockfd,int estado,int numPessoasSistema,int numPessoasZona1,int numFilaZona2,int numFilaZona3, int numFilaZona4, int numFilaZona5, int numPessoasPista1, int numPessoasPista2, int tempo){

	sem_wait(&SemInformacaoEnviar);														    				
	char buffer[MAXLINE];																					
	int lenInformacao=0;																					

	sprintf(buffer,"%d %d %d %d %d %d %d %d %d",estado,numPessoasSistema,numPessoasZona1, numFilaZona2, numFilaZona3, numFilaZona4, numFilaZona5, numPessoasPista1, numPessoasPista2, tempo);
	lenInformacao=strlen(buffer)+1;																			

	//printf("conteudo do buffer:%s\n",&buffer[0]);
	if(send(sockfd,buffer,lenInformacao,0)!=lenInformacao){													
		perror("******Erro ao enviar os dados******\n");													
	}
	sleep(1);
	sem_post(&SemInformacaoEnviar);														    				

}

//*********************************************************************************************************//
//										Criacao das varias entidades		 					    	  //	
//*******************************************************************************************************//

//Entidades: Cliente
struct cliente criaCliente(){

	pthread_mutex_lock(&trincoCliente);
	//cria cliente
	struct cliente c;
	c.idCliente = idCliente;

	int valPrioridade[2] = {0,1};																			//1 tem prioridade, 0 não tem prioridade
	int valAleatorioPrioridade = valPrioridade[rand()%2];
	c.prioridade = valAleatorioPrioridade;	
    
	c.numPista = 0;																							//0 porque ainda não está definido a pista em que ele fica (se for necessario saber)				
	c.numZona = 0;																							//0 signfica que não esta em nenhuma zona
	c.desistiu = 0;																							//0 significa que ainda não desistiu

	idCliente++;																							//Sempre que uma pessoa é criada o ID do paciente é uncrementado
	
	pthread_mutex_unlock(&trincoCliente);
	return c;
}



//Funções realizadas pelas tarefas após criadas	

int determinaProbabilidadeMudarZona(int * probabilidade, int idCliente) {
	*probabilidade = rand() % 2;										//Gera um número aleatório para a probabilidade de mudar de Zona
}

int determinaNovaZona(int * NovaZona, int idCliente){
	*NovaZona = rand() %5;     //tem que ser aleatorio entre 1 e 5
}

int MudarZona(int numPista, int tempoEntradaZona, int prioridade,int idCliente){
	determinaProbabilidadeMudarZona(&probabilidade,idCliente);

	if(probabilidade == 1){

		determinaNovaZona(&NovaZona, idCliente);

		if (NovaZona == 1){
			if (numFilaZona1 == 0){													//Significa que não estava antes na zona 1
				esperaZona1 = 1;																				//Ativa a existencia de um processo que quer ir para a Zona1
				printf(ANSI_COLOR_RED "Espera vaga na Zona 1: %d\n" ANSI_COLOR_RESET,idCliente);
				sem_wait(&SemEsperaZona1); 																		//Ficam à espera na pista de dança, que haja lugares na Zona 1, enquanto isso, como estão a ocupar o ponto mais nenhum outro cliente vai entrar
				desistir = giveUP();

				if(desistir){
					sleep(5);																					//Tem que esperar um tempo antes de oficializar que desiste. Porque não faz sentido chegar à fila e desistir
					printf(ANSI_COLOR_RED "Não prioritário desistiu: %d desistiu da fila da zona1 \n" ANSI_COLOR_RESET, idCliente);
					sem_post(&SemEsperaZona1); 
				}
			}else if(numPessoasZona1 <6){
				if(numPista==1){
					pthread_mutex_lock(&trincoAcompanhaPista);
					numPessoasPista1--;
					pthread_mutex_unlock(&trincoAcompanhaPista);																 			//Retira uma pessoa da Pista1	
					sem_post(&SemNumPessoasNaDisco);
				}
				else if(numPista==2){
					pthread_mutex_lock(&trincoRemoveZona2);
					numPessoasPista2--;																 			//Retira uma pessoa da Pista2	
					pthread_mutex_unlock(&trincoRemoveZona2);
					sem_post(&SemNumPessoasNaDisco);
				}

				pthread_mutex_lock(&trincoAcompanhaZona1);	
				numPessoasZona1++;
				pthread_mutex_unlock(&trincoAcompanhaZona1);							
				sem_wait(&SemNumPessoasZona1);
				pthread_mutex_lock(&trincoFilaZona1);											
				numFilaZona1--;
				pthread_mutex_unlock(&trincoFilaZona1);


				pthread_mutex_lock(&trincoCalculaZona);								//Garantir que apenas um processo de cada vez calcula o tempo

				int tempoEsperaZona1 = 0;
				tempoEsperaZona1 = (int)difftime(time(NULL),tempoEntradaZona);		//Obtem o tempo que o utilizador esteve à espera na fila para entrar na Zona 1

				printf(ANSI_COLOR_MAGENTA "ENTROU na Zona 1: %d. Esteve na Fila por:%d\n" ANSI_COLOR_RESET,idCliente,tempoEntradaZona);

				//********************* ENVIAR PARA MONITOR ********************************/	
					InformacaoEnviar(sockfd,2,numClientesSimu,numPessoasZona1,numPessoasZona2,numPessoasZona3,numPessoasZona4,numPessoasZona5,numPessoasPista1,numPessoasPista2,0);
				//*************************************************************************/

				pthread_mutex_unlock(&trincoCalculaZona);

				pthread_mutex_lock(&trincoClienteEsperaZona);												

				if(prioridade == 1){													//Se os clientes tiverem prioridade podem ficar mais tempo na zona para a zona não ficar muito tempo com os mesmos clientes
					sleep(10);
				}
				if(prioridade == 0){																				
					sleep(5);
				}
				pthread_mutex_lock(&trincoFilaZona1);
				numFilaZona1++;
				pthread_mutex_unlock(&trincoFilaZona1);

				pthread_mutex_lock(&trincoAcompanhaZona1);
				numPessoasZona1--;
				pthread_mutex_unlock(&trincoAcompanhaZona1);

				if(numFilaZona1!=0 && esperaZona1 == 1){										
					sem_post(&SemEsperaZona1);
				}

				pthread_mutex_unlock(&trincoClienteEsperaZona);	
				sem_post (&SemNumPessoasZona1);


				pthread_mutex_lock(&controlaEntradaPista);
				//O CLIENTE VAI PARA A PISTA 1
				if(numPessoasPista1 < 25){

					pthread_mutex_lock(&trincoAcompanhaPista);															
					sem_wait(&SemNumPessoasNaPista1);																	
					numPessoasPista1++;																				//Mais uma pessoa na pista 1
					pthread_mutex_unlock(&trincoAcompanhaPista);		

					pthread_mutex_lock(&mensagemPista1);										
					printf(ANSI_COLOR_YELLOW "VOLTOU para a Pista 1: %d\n" ANSI_COLOR_RESET,idCliente);
					pthread_mutex_unlock(&mensagemPista1);

					pthread_mutex_unlock(&controlaEntradaPista);

					pthread_mutex_lock(&trincoEspera1);
		
					if(numFilaZona1!=0 && esperaZona1 == 1){
						esperaZona1 = 0;
						sem_post(&SemEsperaZona1);															//Solta os processos à espera
					}

					pthread_mutex_unlock(&trincoEspera1);
		


					//********************* ENVIAR PARA MONITOR ********************************/     //ENVIAR MENAGEM COM O NUMERO DE PESSOAS NA PISTA 
						InformacaoEnviar(sockfd,2,numClientesSimu,numPessoasZona1,numPessoasZona2,numPessoasZona3,numPessoasZona4,numPessoasZona5,numPessoasPista1,numPessoasPista2,0);
					//*************************************************************************/
					sem_post(&SemNumPessoasNaPista1);

				} else if(numPessoasPista2<25){
					pthread_mutex_lock(&trincoAcompanhaPista);															
					sem_wait(&SemNumPessoasNaPista2);																	
					numPessoasPista2++;																				//Mais uma pessoa na pista 1
					pthread_mutex_unlock(&trincoAcompanhaPista);		

					pthread_mutex_lock(&mensagemPista2);										
					printf(ANSI_COLOR_YELLOW "VOLTOU para na Pista 2: %d\n" ANSI_COLOR_RESET,idCliente);
					pthread_mutex_unlock(&mensagemPista2);

					pthread_mutex_unlock(&controlaEntradaPista);

					pthread_mutex_lock(&trincoEspera1);
		
					if(numFilaZona1!=0 && esperaZona1 == 1){
						esperaZona1 = 0;
						sem_post(&SemEsperaZona1);															//Solta os processos à espera
					}

					pthread_mutex_unlock(&trincoEspera1);
		


					//********************* ENVIAR PARA MONITOR ********************************/      //ENVIAR MENAGEM COM O NUMERO DE PESSOAS NA PISTA 
						InformacaoEnviar(sockfd,2,numClientesSimu,numPessoasZona1,numPessoasZona2,numPessoasZona3,numPessoasZona4,numPessoasZona5,numPessoasPista1,numPessoasPista2,0);
					//*************************************************************************/
					sem_post(&SemNumPessoasNaPista1);
				}
				
			}
		}

		else if (NovaZona == 2){
				if (numFilaZona2 != 0){																				//Significa que não ha espaço na FilaZona 2
					esperaZona2 = 1;																				//Ativa a existencia de um processo que quer ir para a Zona 2
					printf(ANSI_COLOR_RED "Espera vaga na Zona 2: %d\n" ANSI_COLOR_RESET,idCliente);
					sem_wait(&SemEsperaZona2); 																		//Ficam à espera na pista de dança, que haja lugares na Zona 2, enquanto isso, como estão a ocupar o ponto mais nenhum outro cliente vai entrar
					desistir = giveUP();

					if(desistir){
						sleep(5);																					//Tem que esperar um tempo antes de oficializar que desiste. Porque não faz sentido chegar à fila e desistir
						printf(ANSI_COLOR_RED "Não prioritário desistiu: %d desistiu da fila da zona 2 \n" ANSI_COLOR_RESET, idCliente);
						sem_post(&SemEsperaZona2);
					}
				}else if(numPessoasZona2 <6){
					if(numPista==1){
						pthread_mutex_lock(&trincoAcompanhaPista);
						numPessoasPista1--;																 			//Retira uma pessoa da Pista1	
						sem_post(&SemNumPessoasNaDisco);
						pthread_mutex_unlock(&trincoAcompanhaPista);
					}
					else if(numPista==2){
						pthread_mutex_lock(&trincoAcompanhaPista2);
						numPessoasPista2--;																 			//Retira uma pessoa da Pista2	
						sem_post(&SemNumPessoasNaDisco);
						pthread_mutex_unlock(&trincoAcompanhaPista2);
					}
					pthread_mutex_lock(&trincoAcompanhaZona2);
					numPessoasZona2++;
					pthread_mutex_unlock(&trincoAcompanhaZona2);
					pthread_mutex_lock(&trincoFilaZona2);
					numFilaZona2--;			
					pthread_mutex_unlock(&trincoFilaZona2);			
					sem_wait(&SemNumPessoasZona2);
					
			

					pthread_mutex_lock(&trincoCalculaZona);								//Garantir que apenas um processo de cada vez calcula o tempo

					int tempoEsperaZona2 = 0;
					tempoEsperaZona2 = (int)difftime(time(NULL),tempoEntradaZona);		//Obtem o tempo que o utilizador esteve à espera na fila para entrar na Zona 2

					printf(ANSI_COLOR_MAGENTA "ENTROU na Zona 2: %d. Esteve na Fila por:%d \n" ANSI_COLOR_RESET,idCliente, tempoEntradaZona);

					//********************* ENVIAR PARA MONITOR ********************************/  
						InformacaoEnviar(sockfd,2,numClientesSimu,numPessoasZona1,numPessoasZona2,numPessoasZona3,numPessoasZona4,numPessoasZona5,numPessoasPista1,numPessoasPista2,0);
					//*************************************************************************/

					pthread_mutex_unlock(&trincoCalculaZona);

					pthread_mutex_lock(&trincoClienteEsperaZona);												

					if(prioridade == 1){																				//Se os clientes tiverem prioridade podem ficar mais tempo na zona para a zona não ficar muito tempo com os mesmos clientes
						sleep(10);
					}
					if(prioridade == 0){																				
						sleep(5);
					}
					pthread_mutex_lock(&trincoAcompanhaZona2);
					numPessoasZona2--;
					pthread_mutex_unlock(&trincoAcompanhaZona2);
					pthread_mutex_lock(&trincoFilaZona2);
					numFilaZona2++;
					pthread_mutex_unlock(&trincoFilaZona2);

					if(numFilaZona2!=0 && esperaZona2 == 1){											
						sem_post(&SemEsperaZona2);
					}

					pthread_mutex_unlock(&trincoClienteEsperaZona);
					sem_post (&SemNumPessoasZona2);

					pthread_mutex_lock(&controlaEntradaPista);
						//O CLIENTE VAI PARA A PISTA 1
						if(numPessoasPista1 < 25){
		
						pthread_mutex_lock(&trincoAcompanhaPista);															
						sem_wait(&SemNumPessoasNaPista1);																
						numPessoasPista1++;																				//Mais uma pessoa na pista 1
						pthread_mutex_unlock(&trincoAcompanhaPista);		

						pthread_mutex_lock(&mensagemPista1);										
						printf(ANSI_COLOR_YELLOW "VOLTOU para a Pista 1: %d\n" ANSI_COLOR_RESET,idCliente);
						pthread_mutex_unlock(&mensagemPista1);

						pthread_mutex_unlock(&controlaEntradaPista);

						pthread_mutex_lock(&trincoEspera2);
		
						if(numFilaZona2!=0 && esperaZona2 == 1){
							esperaZona2 = 0;
							sem_post(&SemEsperaZona2);															//Solta os processos à espera
						}

						pthread_mutex_unlock(&trincoEspera2);
		


						//********************* ENVIAR PARA MONITOR ********************************/       //ENVIAR MENAGEM COM O NUMERO DE PESSOAS NA PISTA
							InformacaoEnviar(sockfd,2,numClientesSimu,numPessoasZona1,numPessoasZona2,numPessoasZona3,numPessoasZona4,numPessoasZona5,numPessoasPista1,numPessoasPista2,0);
						//*************************************************************************/
						sem_post(&SemNumPessoasNaPista1);

					} else if(numPessoasPista2<25){
						pthread_mutex_lock(&trincoAcompanhaPista);															
						sem_wait(&SemNumPessoasNaPista2);																	
						numPessoasPista2++;																				//Mais uma pessoa na pista 1
						pthread_mutex_unlock(&trincoAcompanhaPista);		

						pthread_mutex_lock(&mensagemPista2);										
						printf(ANSI_COLOR_YELLOW "VOLTOU para a Pista 2: %d\n" ANSI_COLOR_RESET,idCliente);
						pthread_mutex_unlock(&mensagemPista2);

						pthread_mutex_unlock(&controlaEntradaPista);

						pthread_mutex_lock(&trincoEspera2);
		
						if(numFilaZona2!=0 && esperaZona2 == 1){
							esperaZona2 = 0;
							sem_post(&SemEsperaZona2);															//Solta os processos à espera
						}

						pthread_mutex_unlock(&trincoEspera2);
		


						//********************* ENVIAR PARA MONITOR ********************************/       //ENVIAR MENAGEM COM O NUMERO DE PESSOAS NA PISTA
							InformacaoEnviar(sockfd,2,numClientesSimu,numPessoasZona1,numPessoasZona2,numPessoasZona3,numPessoasZona4,numPessoasZona5,numPessoasPista1,numPessoasPista2,0);
						//*************************************************************************/
						sem_post(&SemNumPessoasNaPista1);
					}
				
			}
		}

		else if (NovaZona == 3){
				if (numFilaZona3 == 0){															//Significa que não ha espaço na FilaZona 3
					esperaZona3 = 1;																				//Ativa a existencia de um processo que quer ir para a Zona 3
					printf(ANSI_COLOR_RED "Espera vaga na Zona 3: %d\n" ANSI_COLOR_RESET,idCliente);
					sem_wait(&SemEsperaZona3); 																		//Ficam à espera na pista de dança, que haja lugares na Zona 3, enquanto isso, como estão a ocupar o ponto mais nenhum outro cliente vai entrar
					desistir = giveUP();
					if(desistir){
						sleep(5);																					//Tem que esperar um tempo antes de oficializar que desiste. Porque não faz sentido chegar à fila e desistir
						printf(ANSI_COLOR_RED "Não prioritário desistiu: %d desistiu da fila da zona 3 \n" ANSI_COLOR_RESET, idCliente);
						sem_post(&SemEsperaZona3);
					} 
				}else if(numPessoasZona3 <6){
					if(numPista==1){
						pthread_mutex_lock(&trincoAcompanhaPista);
						numPessoasPista1--;																 			//Retira uma pessoa da Pista1	
						sem_post(&SemNumPessoasNaDisco);
						pthread_mutex_unlock(&trincoAcompanhaPista);
					}
					else if(numPista==2){
						pthread_mutex_lock(&trincoAcompanhaPista2);
						numPessoasPista2--;																 			//Retira uma pessoa da Pista2	
						sem_post(&SemNumPessoasNaDisco);
						pthread_mutex_unlock(&trincoAcompanhaPista2);
					}
					pthread_mutex_lock(&trincoAcompanhaZona3);									
					numPessoasZona3++;
					pthread_mutex_unlock(&trincoAcompanhaZona3);

					sem_wait(&SemNumPessoasZona3);
					pthread_mutex_lock(&trincoFilaZona3);
					numFilaZona3--;
					pthread_mutex_unlock(&trincoFilaZona3);


					pthread_mutex_lock(&trincoCalculaZona);								//Garantir que apenas um processo de cada vez calcula o tempo

					int tempoEsperaZona3 = 0;
					tempoEsperaZona3 = (int)difftime(time(NULL),tempoEntradaZona);		//Obtem o tempo que o utilizador esteve à espera na fila para entrar na Zona 3

					printf(ANSI_COLOR_MAGENTA "ENTROU na Zona 3: %d. Esteve na fila \n" ANSI_COLOR_RESET,idCliente, tempoEntradaZona);

					////********************* ENVIAR PARA MONITOR ********************************/  
						InformacaoEnviar(sockfd,2,numClientesSimu,numPessoasZona1,numPessoasZona2,numPessoasZona3,numPessoasZona4,numPessoasZona5,numPessoasPista1,numPessoasPista2,0);
					///*************************************************************************/

					pthread_mutex_unlock(&trincoCalculaZona);

					pthread_mutex_lock(&trincoClienteEsperaZona);												//Garantir o isolamento da variavel global tempoNoIsolamento

					if(prioridade == 1){																	//Se os clientes tiverem prioridade podem ficar mais tempo na zona para a zona não ficar muito tempo com os mesmos clientes
						sleep(10);
					}
					if(prioridade == 0){																				
						sleep(5);
					}
					pthread_mutex_lock(&trincoFilaZona3);
					numFilaZona3++;
					pthread_mutex_unlock(&trincoFilaZona3);
					pthread_mutex_lock(&trincoAcompanhaZona3);
					numPessoasZona3--;
					pthread_mutex_unlock(&trincoAcompanhaZona3);

					if(numFilaZona3!=0 && esperaZona3 == 1){											//Se for diferente de 0 significa que existe pelo menos 1 lugar livre no isolamento E existe um processo (paciente) à espera, logo temos que dizer que ele pode entrar
						sem_post(&SemEsperaZona3);
					}

					pthread_mutex_unlock(&trincoClienteEsperaZona);
					sem_post (&SemNumPessoasZona3);

					pthread_mutex_lock(&controlaEntradaPista);
					//O CLIENTE VAI PARA A PISTA 1
					if(numPessoasPista1 < 25){
		
						pthread_mutex_lock(&trincoAcompanhaPista);															
						sem_wait(&SemNumPessoasNaPista1);																	
						numPessoasPista1++;																				//Mais uma pessoa na pista 1
						pthread_mutex_unlock(&trincoAcompanhaPista);		

						pthread_mutex_lock(&mensagemPista1);										
						printf(ANSI_COLOR_YELLOW "VOLTOU para a Pista 1: %d\n" ANSI_COLOR_RESET,idCliente);
						pthread_mutex_unlock(&mensagemPista1);

						pthread_mutex_unlock(&controlaEntradaPista);

						pthread_mutex_lock(&trincoEspera3);
		
						if(numFilaZona3!=0 && esperaZona3 == 1){
							esperaZona3 = 0;
							sem_post(&SemEsperaZona3);															//Solta os processos à espera
						}

						pthread_mutex_unlock(&trincoEspera3);
		


						///********************* ENVIAR PARA MONITOR ********************************/      //ENVIAR MENAGEM COM O NUMERO DE PESSOAS NA PISTA 
							InformacaoEnviar(sockfd,2,numClientesSimu,numPessoasZona1,numPessoasZona2,numPessoasZona3,numPessoasZona4,numPessoasZona5,numPessoasPista1,numPessoasPista2,0);
						//*************************************************************************/
						sem_post(&SemNumPessoasNaPista1);

					} else if(numPessoasPista2<25){
						pthread_mutex_lock(&trincoAcompanhaPista);															
						sem_wait(&SemNumPessoasNaPista2);																	
						numPessoasPista2++;																				//Mais uma pessoa na pista 1
						pthread_mutex_unlock(&trincoAcompanhaPista);		

						pthread_mutex_lock(&mensagemPista2);										
						printf(ANSI_COLOR_YELLOW "VOLTOU para a PISTA 2: %d\n" ANSI_COLOR_RESET,idCliente);
						pthread_mutex_unlock(&mensagemPista2);

						pthread_mutex_unlock(&controlaEntradaPista);

						pthread_mutex_lock(&trincoEspera3);
		
						if(numFilaZona3!=0 && esperaZona3 == 1){
							esperaZona2 = 0;
							sem_post(&SemEsperaZona3);															//Solta os processos à espera
						}

						pthread_mutex_unlock(&trincoEspera3);
		


						///********************* ENVIAR PARA MONITOR ********************************/      //ENVIAR MENAGEM COM O NUMERO DE PESSOAS NA PISTA 
							InformacaoEnviar(sockfd,2,numClientesSimu,numPessoasZona1,numPessoasZona2,numPessoasZona3,numPessoasZona4,numPessoasZona5,numPessoasPista1,numPessoasPista2,0);
						//*************************************************************************/
						sem_post(&SemNumPessoasNaPista1);
					}
				
			}
		}
		else if (NovaZona == 4){
				if (numFilaZona4 == 0){															//Significa que não ha espaço na FilaZona4
					esperaZona4 = 1;																				//Ativa a existencia de um processo que quer ir para a Zona4
					printf(ANSI_COLOR_RED "Espera vaga na Zona 4: %d\n" ANSI_COLOR_RESET,idCliente);
					sem_wait(&SemEsperaZona4); 																		//Ficam à espera na pista de dança, que haja lugares na Zona 4, enquanto isso, como estão a ocupar o ponto mais nenhum outro cliente vai entrar
					desistir = giveUP();

					if(desistir){
						sleep(5);																					//Tem que esperar um tempo antes de oficializar que desiste. Porque não faz sentido chegar à fila e desistir
						printf(ANSI_COLOR_RED "Não prioritário desistiu: %d desistiu da fila da zona 4 \n" ANSI_COLOR_RESET, idCliente);
						sem_post(&SemEsperaZona4);
					}
				}else if(numPessoasZona4 <6){
					if(numPista==1){
						pthread_mutex_lock(&trincoAcompanhaPista);
						numPessoasPista1--;																 			//Retira uma pessoa da Pista1	
						sem_post(&SemNumPessoasNaDisco);
						pthread_mutex_unlock(&trincoAcompanhaPista);
					}
					else if(numPista==2){
						pthread_mutex_lock(&trincoAcompanhaPista);
						numPessoasPista2--;																 			//Retira uma pessoa da Pista2	
						sem_post(&SemNumPessoasNaDisco);
						pthread_mutex_unlock(&trincoAcompanhaPista);
					}

					pthread_mutex_lock(&trincoAcompanhaZona4);									
					numPessoasZona4++;
					pthread_mutex_unlock(&trincoAcompanhaZona4);

					sem_wait(&SemNumPessoasZona4);
					pthread_mutex_lock(&trincoFilaZona4);										
					numFilaZona4--;
					pthread_mutex_unlock(&trincoFilaZona4);

				

					pthread_mutex_lock(&trincoCalculaZona);								//Garantir que apenas um processo de cada vez calcula o tempo

					int tempoEsperaZona4 = 0;
					tempoEsperaZona4 = (int)difftime(time(NULL),tempoEntradaZona);		//Obtem o tempo que o utilizador esteve à espera na fila para entrar na Zona 4

					printf(ANSI_COLOR_MAGENTA "ENTROU na Zona 4: %d. Esteve na fila por: %d\n" ANSI_COLOR_RESET,idCliente,tempoEntradaZona);

					//********************* ENVIAR PARA MONITOR ********************************/  
						InformacaoEnviar(sockfd,2,numClientesSimu,numPessoasZona1,numPessoasZona2,numPessoasZona3,numPessoasZona4,numPessoasZona5,numPessoasPista1,numPessoasPista2,0);
					//*************************************************************************/

					pthread_mutex_unlock(&trincoCalculaZona);

					pthread_mutex_lock(&trincoClienteEsperaZona);												

					if(prioridade == 1){																				//Se os clientes tiverem prioridade podem ficar mais tempo na zona para a zona não ficar muito tempo com os mesmos clientes
						sleep(10);
					}
					if(prioridade == 0){																				
						sleep(5);
					}
					pthread_mutex_lock(&trincoFilaZona4);
					numFilaZona4++;
					pthread_mutex_unlock(&trincoFilaZona4);
					pthread_mutex_lock(&trincoAcompanhaZona4);
					numPessoasZona4--;
					pthread_mutex_unlock(&trincoAcompanhaZona4);

					if(numFilaZona4!=0 && esperaZona4 == 1){											
						sem_post(&SemEsperaZona4);
					}


					pthread_mutex_unlock(&trincoClienteEsperaZona);
					sem_post (&SemNumPessoasZona4);

					pthread_mutex_lock(&controlaEntradaPista);
					//O CLIENTE VAI PARA A PISTA 1
					if(numPessoasPista1 < 25){
		
						pthread_mutex_lock(&trincoAcompanhaPista);															
						sem_wait(&SemNumPessoasNaPista1);																	
						numPessoasPista1++;																				//Mais uma pessoa na pista 1
						pthread_mutex_unlock(&trincoAcompanhaPista);		

						pthread_mutex_lock(&mensagemPista1);										
						printf(ANSI_COLOR_YELLOW "VOLTOU para a Pista 1: %d\n" ANSI_COLOR_RESET,idCliente);
						pthread_mutex_unlock(&mensagemPista1);

						pthread_mutex_unlock(&controlaEntradaPista);

						pthread_mutex_lock(&trincoEspera4);
		
						if(numFilaZona4!=0 && esperaZona4 == 1){
							esperaZona4 = 0;
							sem_post(&SemEsperaZona4);															//Solta os processos à espera
						}

						pthread_mutex_unlock(&trincoEspera4);
		


						//********************* ENVIAR PARA MONITOR ********************************/       //ENVIAR MENAGEM COM O NUMERO DE PESSOAS NA PISTA
							InformacaoEnviar(sockfd,2,numClientesSimu,numPessoasZona1,numPessoasZona2,numPessoasZona3,numPessoasZona4,numPessoasZona5,numPessoasPista1,numPessoasPista2,0);
						//*************************************************************************/
						sem_post(&SemNumPessoasNaPista1);

					} else if(numPessoasPista2<25){
						pthread_mutex_lock(&trincoAcompanhaPista);															
						sem_wait(&SemNumPessoasNaPista2);																	
						numPessoasPista2++;																				//Mais uma pessoa na pista 1
						pthread_mutex_unlock(&trincoAcompanhaPista);		

						pthread_mutex_lock(&mensagemPista2);										
						printf(ANSI_COLOR_YELLOW "VOLTOU para a PISTA 2: %d\n" ANSI_COLOR_RESET,idCliente);
						pthread_mutex_unlock(&mensagemPista2);

						pthread_mutex_unlock(&controlaEntradaPista);

						pthread_mutex_lock(&trincoEspera4);
		
						if(numFilaZona4!=0 && esperaZona4 == 1){
							esperaZona4 = 0;
							sem_post(&SemEsperaZona4);															//Solta os processos à espera
						}

						pthread_mutex_unlock(&trincoEspera4);
		


						//********************* ENVIAR PARA MONITOR ********************************/        //ENVIAR MENAGEM COM O NUMERO DE PESSOAS NA PISTA
							InformacaoEnviar(sockfd,2,numClientesSimu,numPessoasZona1,numPessoasZona2,numPessoasZona3,numPessoasZona4,numPessoasZona5,numPessoasPista1,numPessoasPista2,0);
						//*************************************************************************/
						sem_post(&SemNumPessoasNaPista1);
					}
				}
			}
		
		else if (NovaZona == 5){
				if (numFilaZona5 == 0){															//Significa que não ha espaço na FilaZona 5
					esperaZona5 = 1;																				//Ativa a existencia de um processo que quer ir para a Zona 5
					printf(ANSI_COLOR_RED "Espera vaga na Zona 5: %d\n" ANSI_COLOR_RESET,idCliente);
					sem_wait(&SemEsperaZona5); 																		//Ficam à espera na pista de dança, que haja lugares na Zona 5, enquanto isso, como estão a ocupar o ponto mais nenhum outro cliente vai entrar
					desistir = giveUP();

					if(desistir){
						sleep(5);																					//Tem que esperar um tempo antes de oficializar que desiste. Porque não faz sentido chegar à fila e desistir
						printf(ANSI_COLOR_RED "Não prioritário desistiu: %d desistiu da fila da zona 5 \n" ANSI_COLOR_RESET, idCliente);
						sem_post(&SemEsperaZona5);
					}
				}else if(numPessoasZona5 <6){
					if(numPista==1){
						pthread_mutex_lock(&trincoAcompanhaPista);
						numPessoasPista1--;																 			//Retira uma pessoa da Pista1	
						sem_post(&SemNumPessoasNaDisco);
						pthread_mutex_unlock(&trincoAcompanhaPista);
					}
					else if(numPista==2){
						pthread_mutex_lock(&trincoAcompanhaPista2);
						numPessoasPista2--;																 			//Retira uma pessoa da Pista2	
						sem_post(&SemNumPessoasNaDisco);
						pthread_mutex_unlock(&trincoAcompanhaPista2);
					}
				}
				pthread_mutex_lock(&trincoAcompanhaZona5);									
				numPessoasZona5++;
				pthread_mutex_unlock(&trincoAcompanhaZona5);

				sem_wait(&SemNumPessoasZona5);
				pthread_mutex_lock(&trincoFilaZona5);										
				numFilaZona5--;
				pthread_mutex_unlock(&trincoFilaZona5);


				pthread_mutex_lock(&trincoCalculaZona);								//Garantir que apenas um processo de cada vez calcula o tempo

				int tempoEsperaZona5 = 0;
				tempoEsperaZona5 = (int)difftime(time(NULL),tempoEntradaZona);		//Obtem o tempo que o utilizador esteve à espera na fila para entrar na Zona 3

				printf(ANSI_COLOR_MAGENTA "ENTROU na Zona 5: %d. Esteve na fila por: %d\n" ANSI_COLOR_RESET,idCliente,tempoEntradaZona);

				//********************* ENVIAR PARA MONITOR ********************************/ 
					InformacaoEnviar(sockfd,2,numClientesSimu,numPessoasZona1,numPessoasZona2,numPessoasZona3,numPessoasZona4,numPessoasZona5,numPessoasPista1,numPessoasPista2,0);
				//*************************************************************************/

				pthread_mutex_unlock(&trincoCalculaZona);

				pthread_mutex_lock(&trincoClienteEsperaZona);												

				if(prioridade == 1){																		
					sleep(10);
				}
				if(prioridade == 0){																				
					sleep(5);
				}
				pthread_mutex_lock(&trincoFilaZona5);
				numFilaZona5++;
				pthread_mutex_unlock(&trincoFilaZona5);
				pthread_mutex_lock(&trincoAcompanhaZona5);
				numPessoasZona5--;
				pthread_mutex_unlock(&trincoAcompanhaZona5);

				if(numFilaZona5!=0 && esperaZona5 == 1){											
				}


				pthread_mutex_unlock(&trincoClienteEsperaZona);
				sem_post (&SemNumPessoasZona5);

				pthread_mutex_lock(&controlaEntradaPista);
				//O CLIENTE VAI PARA A PISTA 1
				if(numPessoasPista1 < 25){
		
					pthread_mutex_lock(&trincoAcompanhaPista);															
					sem_wait(&SemNumPessoasNaPista1);																	
					numPessoasPista1++;																				//Mais uma pessoa na pista 1
					pthread_mutex_unlock(&trincoAcompanhaPista);		

					pthread_mutex_lock(&mensagemPista1);										
					printf(ANSI_COLOR_YELLOW "VOLTOU para a Pista 1: %d\n" ANSI_COLOR_RESET,idCliente);
					pthread_mutex_unlock(&mensagemPista1);

					pthread_mutex_unlock(&controlaEntradaPista);

					pthread_mutex_lock(&trincoEspera5);
		
					if(numFilaZona5!=0 && esperaZona5 == 1){
						esperaZona5 = 0;
						sem_post(&SemEsperaZona5);															//Solta os processos à espera
					}

					pthread_mutex_unlock(&trincoEspera5);
		


					//********************* ENVIAR PARA MONITOR ********************************/      //ENVIAR MENAGEM COM O NUMERO DE PESSOAS NA PISTA 
						InformacaoEnviar(sockfd,2,numClientesSimu,numPessoasZona1,numPessoasZona2,numPessoasZona3,numPessoasZona4,numPessoasZona5,numPessoasPista1,numPessoasPista2,0);
					//*************************************************************************/
					sem_post(&SemNumPessoasNaPista1);

				} else if(numPessoasPista2<25){
					pthread_mutex_lock(&trincoAcompanhaPista);															
					sem_wait(&SemNumPessoasNaPista2);																	
					numPessoasPista2++;																				//Mais uma pessoa na pista 1
					pthread_mutex_unlock(&trincoAcompanhaPista);		

					pthread_mutex_lock(&mensagemPista2);										
					printf(ANSI_COLOR_YELLOW "VOLTOU para a PISTA 2: %d\n" ANSI_COLOR_RESET,idCliente);
					pthread_mutex_unlock(&mensagemPista2);

					pthread_mutex_unlock(&controlaEntradaPista);

					pthread_mutex_lock(&trincoEspera5);
		
					if(numFilaZona5!=0 && esperaZona5 == 1){
						esperaZona5 = 0;
						sem_post(&SemEsperaZona5);															//Solta os processos à espera
					}

					pthread_mutex_unlock(&trincoEspera5);
		


					//********************* ENVIAR PARA MONITOR ********************************/       //ENVIAR MENAGEM COM O NUMERO DE PESSOAS NA PISTA 
						InformacaoEnviar(sockfd,2,numClientesSimu,numPessoasZona1,numPessoasZona2,numPessoasZona3,numPessoasZona4,numPessoasZona5,numPessoasPista1,numPessoasPista2,0);
					//*************************************************************************/
					sem_post(&SemNumPessoasNaPista1);
				}
			
		}
	}
}



//função responsável por calcular a probabilidade de desistir
int giveUP() {

	int random = rand() % 99;

	int valor_maximo = (int)(probDesistir);

	if (random < valor_maximo) {
		giveUp = 1;
	}
	else {
		giveUp = 0;
	}

	return giveUp;
}



void * cliente(void * ptr){

	bool defineDesistir=false;

	//criacao de cliente
    struct cliente c = criaCliente();																		//Só liberto quando entra na fila 

	//struct discoteca d = discotecass();

	c.tempo_total = time(NULL);

	pthread_mutex_lock(&ordem);

	if(c.prioridade==1){
		sem_wait(&SemFilaPrioridadeDiscoteca);													//Podem estar até 15 pessoas na fila com prioridade
		
		filaCPLugaresDisco--;																				//A fila com prioridade fica com menos 1 lugar livre

		//O Cliente ENTRE NA FILA PARA A DISCOTECA: FIFO
		//Vai para a fila 
		printf(ANSI_COLOR_YELLOW "Prioritário chegou: %d CHEGOU à fila da discoteca \n" ANSI_COLOR_RESET, c.idCliente);

		//********************* ENVIAR PARA MONITOR ********************************/	
			pthread_mutex_lock(&trinconumClientesSimu);
			numClientesSimu++;
			InformacaoEnviar(sockfd,2,numClientesSimu,numPessoasZona1,numPessoasZona2,numPessoasZona3,numPessoasZona4,numPessoasZona5,numPessoasPista1,numPessoasPista2,0);
			pthread_mutex_unlock(&trinconumClientesSimu);
		//*************************************************************************/

		c.tempoEntradaFilaDiscoteca = time(NULL);												//marcar o tempo que o cliente entrou na fila

		if(numLugaresLivresDisco==0){														//significa que não há lugares livres aó faz sentido definir uma desistência
			desistir = giveUP();

			if(desistir){
				sleep(5);																			//Tem que esperar um tempo antes de oficializar que desiste. Porque não faz sentido chegar à fila e desistir
				printf(ANSI_COLOR_GREEN "Prioritário desistiu: %d desistiu da fila da discoteca %d\n" ANSI_COLOR_RESET, c.idCliente);
				filaCPLugaresDisco++;
				sem_post(&SemFilaPrioridadeDiscoteca);
				pthread_mutex_unlock(&ordem); 

				//********************* ENVIAR PARA MONITOR ********************************/	
					pthread_mutex_lock(&trinconumClientesSimu);
					numClientesSimu--;
					InformacaoEnviar(sockfd,2,numClientesSimu,numPessoasZona1,numPessoasZona2,numPessoasZona3,numPessoasZona4,numPessoasZona5,numPessoasPista1,numPessoasPista2,0);
					pthread_mutex_unlock(&trinconumClientesSimu);
				//*************************************************************************/

				pthread_exit(NULL);
			}
		}

		

		sleep(2);
			
		//ATRIBUI PISTA DE DANCA
		pthread_mutex_lock(&trincoEntradaPistaDanca); 												
		pthread_mutex_unlock(&ordem);																//Ordem na fila garantida
			
		sem_wait(&SemNumPessoasNaDisco);															
		numLugaresLivresDisco--;																	//decrementa o número de lugares livres
			
		pthread_mutex_unlock(&trincoEntradaPistaDanca);
			
		//atribuição da pista de danca
		if(numPessoasPista1<25){	
			//Esta livre 
			c.numPista=1;																			
			numPessoasPista1++;												  					
					
			int tempoEsperaPista1 = 0;
			tempoEsperaPista1 = (int)difftime(time(NULL),c.tempoEntradaFilaDiscoteca);			//Obtem o tempo que o utilizador esteve à espera na fila para entrar na pista

			printf(ANSI_COLOR_CYAN "ENTROU %d na pista 1:. Esteve na fila por: %d\n" ANSI_COLOR_RESET, c.idCliente, tempoEsperaPista1);
										
			filaCPLugaresDisco++;																		//A fila com prioridade fica com mais 1 lugar
					
			if(filaCPLugaresDisco==15 && esperarNPrioritario == 1){
				sem_post(&SemEsperaVezNP);															//Liberta os processos sem prioridade que estão à espera
			}		

			sem_post(&SemFilaPrioridadeDiscoteca);											//Assinalo que sairam oficialmente da fila com prioridades
					
		}
		else if(numPessoasPista2<25){  
			//Esta livre 
			pthread_mutex_lock(&trincoAcompanhaPista);
			c.numPista=2;																	
			numPessoasPista2++;
			pthread_mutex_unlock(&trincoAcompanhaPista);														
					
			int tempoEsperaPista2 = 0;
			tempoEsperaPista2 = (int)difftime(time(NULL),c.tempoEntradaFilaDiscoteca);		//Obtem o tempo que o utilizador esteve à espera na fila para entrar na pista

			printf(ANSI_COLOR_CYAN "ENTROU %d na pista 2. Esteve na fila por: %d\n" ANSI_COLOR_RESET, c.idCliente,tempoEsperaPista2);
							
			filaCPLugaresDisco++;																		//A fila com prioridade fica com mais 1 lugar
					
			if(filaCPLugaresDisco==15 && esperarNPrioritario == 1){
				sem_post(&SemEsperaVezNP);															//Liberta os processos sem prioridade que estão à espera
			}		
					
			sem_post(&SemFilaPrioridadeDiscoteca);											//Assinalo que sairam oficialmente da fila com prioridades
					
		}
	
	}
	else if(c.prioridade==0){

		sem_wait(&SemFilaNPrioridadeDiscoteca);													//Podem estar até 15 pessoas na fila sem prioridade
		
		//O PACIENTE ENTRA NA FILA PARA A DISCOTECA: FIFO
			
		//Vai para a fila
		printf(ANSI_COLOR_BLUE "Não prioritário chegou: %d CHEGOU à fila da discoteca \n" ANSI_COLOR_RESET, c.idCliente);

		//********************* ENVIAR PARA MONITOR ********************************/	
			pthread_mutex_lock(&trinconumClientesSimu);
			numClientesSimu++;
			InformacaoEnviar(sockfd,2,numClientesSimu,numPessoasZona1,numPessoasZona2,numPessoasZona3,numPessoasZona4,numPessoasZona5,numPessoasPista1,numPessoasPista2,0);
			pthread_mutex_unlock(&trinconumClientesSimu);
		//*************************************************************************/

		c.tempoEntradaFilaDiscoteca = time(NULL);	//marcar o tempo que o paciente entrou na fila

		if(numLugaresLivresDisco==0){														//significa que não há lugares livres aó faz sentido definir uma desistência
			desistir = giveUP();

			if(desistir){
				sleep(5);																			//Tem que esperar um tempo antes de oficializar que desiste. Porque não faz sentido chegar à fila e desistir
				printf(ANSI_COLOR_RED "Não prioritário desistiu: %d desistiu da fila da discoteca \n" ANSI_COLOR_RESET, c.idCliente);
				sem_post(&SemFilaNPrioridadeDiscoteca);
				pthread_mutex_unlock(&ordem);
				int tempototal = 0;
				tempototal = (int)difftime(time(NULL),c.tempo_total);

				//********************* ENVIAR PARA MONITOR ********************************/	
					pthread_mutex_lock(&trinconumClientesSimu);
					numClientesSimu--;
					InformacaoEnviar(sockfd,2,numClientesSimu,numPessoasZona1,numPessoasZona2,numPessoasZona3,numPessoasZona4,numPessoasZona5,numPessoasPista1,numPessoasPista2,tempototal);
					pthread_mutex_unlock(&trinconumClientesSimu);
				//*************************************************************************/

				pthread_exit(NULL);
			}
		}
			

		sleep(2);																						

		//ATRIBUI PISTA DE DANCA
		pthread_mutex_lock(&trincoEntradaPistaDanca); 												
		pthread_mutex_unlock(&ordem);																//Ordem na fila garantida
			
		sem_wait(&SemNumPessoasNaDisco);															
		numLugaresLivresDisco--;																	//decrementa o número de lugares livres
			
		pthread_mutex_unlock(&trincoEntradaPistaDanca);
			
	
		if(filaCPLugaresDisco!=15){																		    //Há pessoas na fila
			esperarNPrioritario = 1;
			printf(ANSI_COLOR_RED "Cede prioridade: %d \n" ANSI_COLOR_RESET,c.idCliente);
			sem_wait(&SemEsperaVezNP); 
		}

		esperarNPrioritario = 0;

		//atribuição da pista
		if(numPessoasPista1<25){
			//Esta livre 
			c.numPista=1;															
			numPessoasPista1++;													
					
			int tempoEsperaPista1 = 0;
					
			tempoEsperaPista1 = (int)difftime(time(NULL),c.tempoEntradaFilaDiscoteca);		

			printf(ANSI_COLOR_CYAN "ENTROU %d na pista 1:. Esteve na fila por: %d\n" ANSI_COLOR_RESET, c.idCliente, tempoEsperaPista1);

			sem_post(&SemFilaNPrioridadeDiscoteca);											//Assinalo que sairam da fila oficialmente sem prioridade
					
				
		}
		else if(numPessoasPista2<25){
			//Esta livre
			pthread_mutex_lock(&trincoAcompanhaPista); 
			c.numPista=2;															
			numPessoasPista2++;
			pthread_mutex_unlock(&trincoAcompanhaPista);															
					
			int tempoEsperaPista2 = 0;
			tempoEsperaPista2 = (int)difftime(time(NULL),c.tempoEntradaFilaDiscoteca);		

			printf(ANSI_COLOR_CYAN "ENTROU %d na pista 2. Esteve na fila por: %d\n" ANSI_COLOR_RESET, c.idCliente,tempoEsperaPista2);
					
			sem_post(&SemFilaNPrioridadeDiscoteca);											//Assinalo que sairam da fila oficialmente sem prioridade
					
		}
	}

	MudarZona(c.numPista, c.tempoEntradaZona,c.prioridade,c.idCliente);
	MudarZona(c.numPista, c.tempoEntradaZona,c.prioridade,c.idCliente);
	MudarZona(c.numPista, c.tempoEntradaZona,c.prioridade,c.idCliente);

	int tempototal = 0;
	tempototal = (int)difftime(time(NULL),c.tempo_total);
	if (c.numPista==1){
		pthread_mutex_lock(&trincoAcompanhaPista);
		numPessoasPista1--;
		pthread_mutex_unlock(&trincoAcompanhaPista);
	}else if (c.numPista==2){
		pthread_mutex_lock(&trincoAcompanhaPista2);
		numPessoasPista2--;
		pthread_mutex_unlock(&trincoAcompanhaPista2);
	}
	pthread_mutex_lock(&trinconumClientesSimu);
	numClientesSimu--;
	pthread_mutex_unlock(&trinconumClientesSimu);
	printf(ANSI_COLOR_GREEN "O cliente %d, SAIU da discoteca, esteve durante %d segundos \n" ANSI_COLOR_RESET, c.idCliente, tempototal);


	//********************* ENVIAR PARA MONITOR ********************************/	
		InformacaoEnviar(sockfd,2,numClientesSimu,numPessoasZona1,numPessoasZona2,numPessoasZona3,numPessoasZona4,numPessoasZona5,numPessoasPista1,numPessoasPista2,tempototal);
	//*************************************************************************/
}



//Inicializar os valores necessarios para a simulacao
void InicializaValores(){

	srand((unsigned)time(NULL));																		

    //Inicialização de semaforos
    sem_init(&SemInformacaoEnviar,0,1);
	
	sem_init(&SemFilaPrioridadeDiscoteca,0,15);															//Na fila sem prioridade para entrar na pista vão haver 15 pessoas max
	sem_init(&SemFilaNPrioridadeDiscoteca,0,15);														//Na fila com prioridade para entrar na pista1 vão haver 15 pessoas max
	sem_init(&SemEsperaVezNP,0,0);																	    //Vou ver com este semaforo consigo bloquear os processos com prioridade 0, quando existem pessoas na fila da prioridade

	sem_init(&SemNumPessoasNaDisco,0,50);																//Na pista so pode haver 50 clientes na discoteca
	sem_init(&SemNumPessoasNaPista1,0,25);
	sem_init(&SemNumPessoasNaPista2,0,25);

	sem_init(&SemEsperaZona1,0,6);
	sem_init(&SemEsperaZona2,0,6);
	sem_init(&SemEsperaZona3,0,6);
	sem_init(&SemEsperaZona4,0,6);
	sem_init(&SemEsperaZona5,0,6);																	    
	sem_init(&SemNumPessoasZona1,0,6);	
	sem_init(&SemNumPessoasZona2,0,6);
	sem_init(&SemNumPessoasZona3,0,6);
	sem_init(&SemNumPessoasZona4,0,6);
	sem_init(&SemNumPessoasZona5,0,6);

	sem_init(&semEsperaEntrarZona1,0,0);															
	sem_init(&semEsperaEntrarZona2,0,0);
	sem_init(&semEsperaEntrarZona3,0,0);
	sem_init(&semEsperaEntrarZona4,0,0);
	sem_init(&semEsperaEntrarZona5,0,0);


    //leitura();
    printf("FEZ LEITURAA - verificacao \n");

}
	

void simulacao(int sockfd){

    // Inicio Da Simulacao
    InicializaValores();
    InformacaoEnviar(sockfd,1,0,0,0,0,0,0,0,0,0);															//Envia a mensagem 1 -> Simulação a começar

	
	int i=0;
	for(int i=0;i<numMaxPessoasACriar;i++){
		if (pthread_create(&IDTarefasClientes[i],NULL,cliente,NULL) !=0){//;
			perror("Failed to create thread");
		}
	}

    for(int i=0;i<numMaxPessoasACriar;i++){
		pthread_join(IDTarefasClientes[i],NULL);
    }

    InformacaoEnviar(sockfd,20,0,0,0,0,0,0,0,0,0);

}

// ***************** FUNcaO PRINCIPAL (MAIN) ******************
int main(int argc, char*argv[]){

    //Criacao do socket
    sockfd = criarSocket();

    //INICIO DA SIMULAcaO
    simulacao(sockfd);

    //Fechar socket
    close(sockfd);
    return 0;

}


