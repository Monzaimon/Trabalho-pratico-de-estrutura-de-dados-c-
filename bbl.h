#ifndef BBL_H
#define BBL_H

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct
{
	int hora, dia, mes, ano; // Armazena a data do dia usado como parametro e a data das tarefas
} Data;

typedef struct
{
	Data dat;	   // Data da tarefa
	int Prio;	   // Prioridade da tarefa de tarefas (sao quatro listas a um, dois, tres e quatro, Prio representa o nivel de prioridade, sendo a um mais importante)
	int codTaf;	   // codigo de referencia da tarefa
	char nome[50]; // Nome da tarefa
} Informacoes;

typedef struct structTarefas Tarefas;

struct structTarefas
{
	Informacoes info; // Informacaos armazenadas em info
	Tarefas *proxTaf; // Aponta para proxima tarefa
	Tarefas *anteTaf; // Aponta para tarefa anterior
};

typedef struct
{
	Tarefas tarf;		// Dados da Tarefa
	int numt;			// numero de tarefas existentes
	Tarefas *inicioTaf; // Aponta para o inicio da lista de tarefas
	Tarefas *fimTaf;	// Aponta para o fim da lista de tarefas
} ListaDeTarefas;

void criarListas(ListaDeTarefas *x);

void adicionarTarefa(ListaDeTarefas *x, Data hoje, Informacoes info);

void removerTarefa(ListaDeTarefas *x, Informacoes *y, int refCodTar);

void exibirTarefaPorCodigo(ListaDeTarefas x, int refCodTar);

void exibirTarefasPorOrdem(ListaDeTarefas *x);

void salvaLista(ListaDeTarefas *x);

void carregaLista(ListaDeTarefas *x, Data dataDeHoje);

#endif
