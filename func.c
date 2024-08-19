#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "bbl.h"

void criarListas(ListaDeTarefas *x)
{
	x->inicioTaf = NULL;
	x->fimTaf = NULL;
	x->numt = 0;
}

void sucesso()
{
	system("cls");
	printf("====================================\n");
	printf("====         ===       =====    ====\n");
	printf("=======   ======  ==========    ====\n");
	printf("=======   ======       =====    ====\n");
	printf("=======   ===========  =====    ====\n");
	printf("=======   ======       =====    ====\n");
	printf("====================================\n");
	printf("=             Sucesso!             =\n");
	printf("====================================\n");
	system("pause");
	system("cls");
	return;
}
void erro()
{
	system("cls");
	printf("====================================\n");
	printf("====         ===       =====    ====\n");
	printf("=======   ======  ==========    ====\n");
	printf("=======   ======       =====    ====\n");
	printf("=======   ===========  =====    ====\n");
	printf("=======   ======       =====    ====\n");
	printf("====================================\n");
	printf("=          Erro inesperado!        =\n");
	printf("====================================\n");
	system("pause");
	system("cls");
	return;
}

void adicionarTarefa(ListaDeTarefas *x, Data hoje, Informacoes info)
{
    if 
	(
		info.dat.dia == hoje.dia && 
		info.dat.mes == hoje.mes && 
		info.dat.ano == hoje.ano && 
		info.dat.hora == hoje.hora
	) 
	{
        printf("Error: Task already exists with the same date.\n");
        return;
    }
    Tarefas *newTask = (Tarefas*)malloc(sizeof(Tarefas));
    newTask->info = info;
    newTask->anteTaf = NULL;
    newTask->proxTaf = NULL;
    if 
	(
		x->inicioTaf == NULL
	) 
	{
    	x->inicioTaf = newTask;
        x->fimTaf = newTask;
        x->numt = 1;
        return;
    }
    if 
	(
		info.dat.ano < x->inicioTaf->info.dat.ano || 
		(info.dat.ano == x->inicioTaf->info.dat.ano &&
		info.dat.mes < x->inicioTaf->info.dat.mes) 
		|| 
		(info.dat.ano == x->inicioTaf->info.dat.ano &&
		info.dat.mes == x->inicioTaf->info.dat.mes && 
		info.dat.dia < x->inicioTaf->info.dat.dia)
		|| 
		(info.dat.ano == x->inicioTaf->info.dat.ano &&
		info.dat.mes == x->inicioTaf->info.dat.mes && 
		info.dat.dia == x->inicioTaf->info.dat.dia &&
		info.dat.hora < x->inicioTaf->info.dat.hora)
	) 
	{
        newTask->proxTaf = x->inicioTaf;
        x->inicioTaf->anteTaf = newTask;
        x->inicioTaf = newTask;
        x->numt++;
        return;
    }
    if 
	(
		info.dat.ano > x->fimTaf->info.dat.ano ||
		
	 	(info.dat.ano == x->fimTaf->info.dat.ano &&
	  	info.dat.mes > x->fimTaf->info.dat.mes) ||
	  	
	   	(info.dat.ano == x->fimTaf->info.dat.ano &&
	    info.dat.mes == x->fimTaf->info.dat.mes &&
		info.dat.dia > x->fimTaf->info.dat.dia) ||
		
		(info.dat.ano == x->fimTaf->info.dat.ano &&
		info.dat.mes == x->fimTaf->info.dat.mes&&
		info.dat.dia == x->fimTaf->info.dat.dia &&
		info.dat.hora > x->fimTaf->info.dat.hora)
	) 
	{
        newTask->anteTaf = x->fimTaf;
        x->fimTaf->proxTaf = newTask;
        x->fimTaf = newTask;
        x->numt++;
        return;
    }
    Tarefas *current = x->inicioTaf;
    while (current != NULL) 
	{
        if 
		(
			info.dat.ano < current->info.dat.ano ||
			
			(info.dat.ano == current->info.dat.ano &&
			info.dat.mes < current->info.dat.mes) 
			|| 
			(info.dat.ano == current->info.dat.ano &&
			info.dat.mes == current->info.dat.mes && 
			info.dat.dia < current->info.dat.dia) 
			||
			(info.dat.ano == current->info.dat.ano &&
			info.dat.mes == current->info.dat.mes && 
			info.dat.dia == current->info.dat.dia && 
			info.dat.hora < current->info.dat.hora)
		) 
		{
            newTask->anteTaf = current->anteTaf;
            newTask->proxTaf = current;
            current->anteTaf->proxTaf = newTask;
            current->anteTaf = newTask;
            x->numt++;
            return;
        }
        current = current->proxTaf;
    }
}

void exibirTarefasPorOrdem(ListaDeTarefas *x)
{
	  Tarefas *tarefaAux2;
	  Informacoes infoAux1;
	  tarefaAux2 = x->inicioTaf;
	  infoAux1 = tarefaAux2->info;
      printf("====================================\n");
      printf("====         ===       =====    ====\n");
      printf("=======   ======  ==========    ====\n");
      printf("=======   ======       =====    ====\n");
      printf("=======   ===========  =====    ====\n");
      printf("=======   ======       =====    ====\n");
      printf("====================================\n");
      printf("======== Exibir por ordem ==========\n");
      printf("====================================\n");
	  printf("= Inicio:    %p                     \n", x->inicioTaf);
      printf("= Fim:       %p                     \n", x->fimTaf);
	  printf("====================================\n");
	  while (tarefaAux2 != NULL){   
		  printf("====================================\n");
	      printf("= Nome:      %s                     \n", infoAux1.nome);
		  printf("= Data:      %d/%d/%d               \n", infoAux1.dat.dia,infoAux1.dat.mes,infoAux1.dat.ano);
		  printf("= Hora:      %d:00h                 \n", infoAux1.dat.hora);	  
	      printf("= Codigo:    %d                     \n", infoAux1.codTaf);
	      printf("= NumTarefa: %d                     \n",x->numt);
	      printf("= Prioridade:%d                     \n", infoAux1.Prio);
	      printf("= Endereco:  %p                     \n", tarefaAux2);
	      printf("= ProxTarefa:%p                     \n",tarefaAux2->proxTaf);
		  printf("= AnteTarefa:%p                     \n",tarefaAux2->anteTaf);
	      printf("====================================\n");
	      tarefaAux2 = tarefaAux2->proxTaf;
	      infoAux1 = tarefaAux2->info;
	  }
	system("pause");
	printf("xxxx");
}

void exibirTarefaPorCodigo(ListaDeTarefas x, int refCodTar)
{
	Tarefas *tarefaAux2;
	tarefaAux2 = x.inicioTaf;
	if (tarefaAux2 == NULL)
	{
		printf("Lista Vazia!\n");
		system("pause");
		return;
	}
	else
	{
		while (tarefaAux2 != NULL)
		{
			if (tarefaAux2->info.codTaf == refCodTar)
			{
				printf("====================================\n");
				printf("= Nome:      %s                     \n", tarefaAux2->info.nome);	  
				printf("= Codigo:    %d                     \n", tarefaAux2->info.codTaf);
				printf("= NumTarefa: %d                     \n",x.numt);
				printf("= Prioridade:%d                     \n", tarefaAux2->info.Prio);
				printf("= ProxTarefa:%p                     \n",tarefaAux2->proxTaf);
				printf("= AnteTarefa:%p                     \n",tarefaAux2->anteTaf);
				printf("====================================\n");
			}
			else
			{
				if (tarefaAux2->proxTaf == NULL)
				{
					printf("Codigo Inexistente!\n");
					system("pause");
					return;
				}
			}
			tarefaAux2 = tarefaAux2->proxTaf;
		}
	}
system("pause");
}

void removerTarefa(ListaDeTarefas *x, Informacoes *y, int refCodTar)
{
	Tarefas *tarefaAux2;
	tarefaAux2 = x->inicioTaf;
	if (tarefaAux2 == NULL){
		erro();
		return;
	}
	else
	{
		while (tarefaAux2 != NULL)
		{
			if (tarefaAux2->info.codTaf == refCodTar)
			{
				*y = tarefaAux2->info;
				if (x->numt == 1)
				{
					x->fimTaf = NULL;
					x->inicioTaf = NULL;
				}
				else
				{
					if (tarefaAux2->proxTaf == NULL)
					{
						tarefaAux2->anteTaf->proxTaf = NULL;
						x->fimTaf = tarefaAux2->anteTaf;
					}
					else
					{
						tarefaAux2->anteTaf->proxTaf = tarefaAux2->proxTaf;
						tarefaAux2->proxTaf->anteTaf = tarefaAux2->anteTaf;
						x->fimTaf = tarefaAux2->proxTaf;
					}
				}
				x->numt--;
				free(tarefaAux2);
				sucesso();
				return;
			}
			else
			{
				if (tarefaAux2->proxTaf == NULL)
				{
					erro();
					return;
				}
			}
			tarefaAux2 = tarefaAux2->proxTaf;
		}
	}
}

void salvaLista(ListaDeTarefas *listDaMain)
{
	FILE *arquivo;
	Tarefas *tarefaAux2;
	arquivo = fopen("listas.txt", "w");
	if (arquivo == NULL)
	{
		erro();
		return;
	}
	tarefaAux2 = listDaMain->inicioTaf;
	while (tarefaAux2 != NULL)
	{
		fprintf(arquivo, "Tarefa: %s\n", tarefaAux2->info.nome);
		fprintf(arquivo, "Data: %d/%d/%d\n", tarefaAux2->info.dat.dia, tarefaAux2->info.dat.mes, tarefaAux2->info.dat.ano);
		fprintf(arquivo, "Hora: %d\n", tarefaAux2->info.dat.hora);
		fprintf(arquivo, "Prioridade: %d\n", tarefaAux2->info.Prio);
		fprintf(arquivo, "CodTaf: %d\n", tarefaAux2->info.codTaf);
		tarefaAux2 = tarefaAux2->proxTaf;
	}
	fclose(arquivo);
	sucesso();
	system("cls");
}

void carregaLista(ListaDeTarefas *listDaMain, Data dataDeHoje)
{
	FILE *arquivo;
	Informacoes informacoesDaMain;
	arquivo = fopen("listas.txt", "r");
	if (arquivo == NULL)
	{
		printf("Erro ao abrir o arquivo!");
		return;
	}
	while (fscanf(arquivo, "Tarefa: %200[^\n]\nData: %d/%d/%d\nHora: %d\nPrioridade: %d\nCodTaf: %d\n", informacoesDaMain.nome, &informacoesDaMain.dat.dia, &informacoesDaMain.dat.mes, &informacoesDaMain.dat.ano, &informacoesDaMain.dat.hora, &informacoesDaMain.Prio, &informacoesDaMain.codTaf) != EOF)
	{
		adicionarTarefa(listDaMain, dataDeHoje, informacoesDaMain);
	}
	fclose(arquivo);
	printf("Lista carregada com sucesso!");
}
