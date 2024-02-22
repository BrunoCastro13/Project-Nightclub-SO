//*********************Bibliotecas*********************

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h> 									//resolve o problema do "unkown type name 'bool'"
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <semaphore.h>									//Para poder usar semafors
#include <pthread.h>									//Para utilizar as therads

#include <ctype.h>

#define _TIMESPEC_DEFINED								//Tempos

//*********************Define*************************

#define UNIXSTR_PATH "/tmp/s.2045618"
#define MAXLINE 512										//Tamanho maximo da linha

//*********************Cores**************************
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

//*********************Structs*************************

/*
struct discoteca{
	int numPessoasPista1;
	int numPessoasPista2;
	int numZonasDisco;									//Número de zonas dentro da discoteca
	int zona1;											//Vai guardar o estado da zona, isto é, se está ocupado (1) ou não ocupado (0)
	int zona2;											//Vai guardar o estado da zona, isto é, se está ocupado (1) ou não ocupado (0)
	int zona3;											//Vai guardar o estado da zona, isto é, se está ocupado (1) ou não ocupado (0)
	int zona4;											//Vai guardar o estado da zona, isto é, se está ocupado (1) ou não ocupado (0)
	int zona5;											//Vai guardar o estado da zona, isto é, se está ocupado (1) ou não ocupado (0)
};
*/

struct cliente{
	int idCliente;
	int prioridade;										//depois este valor vai ser obtido aleatoriamente
	int numZona; 										//Diz em que zona esta
	int numPista;										//Indica em que pista de dança se situa (se for necessario saber)
	int desistiu;										//Se for 2 não desistiu, se for 1 desistiu (EU IA POR 0 MAS ASSIM O 0 FICA PARA O CASO DE ESTE CAMPO NÃO SER ESPECIFICO PARA UM ESTADO)
	time_t tempoEntradaFilaDiscoteca;				//tempo que o paciente chegou à Discoteca
	time_t tempoEntradaZona;
	time_t tempo_total;
};
