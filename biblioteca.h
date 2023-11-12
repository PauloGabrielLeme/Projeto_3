#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int prioridade;
  char descricao[300];
  char categoria[100];
  char status[50];  //Se a tarefa está completa, incompleta, ou não iniciada
} Tarefa;

typedef struct {
  Tarefa tarefas[100];
  int tam;
} Tarefas_armazem;

void lobby();
Tarefas_armazem *leitura(char *nome);
void escreve(Tarefas_armazem *v, char *nome);
Tarefas_armazem *cadastrarTarefa(Tarefas_armazem *lista);
Tarefas_armazem *deletarTarefa(Tarefas_armazem *lista);
void listar_tarefas(Tarefas_armazem *lista);
Tarefas_armazem *filtrar_prioridade(Tarefas_armazem *lista);
Tarefas_armazem *filtrar_categoria(Tarefas_armazem *lista);
Tarefas_armazem *filtrar_status(Tarefas_armazem *lista);
Tarefas_armazem *filtrar_prioridade_categoria(Tarefas_armazem *lista);
char *input(char *str);
Tarefas_armazem *exportar_prioridade(Tarefas_armazem *lista);
Tarefas_armazem *exportar_categoria(Tarefas_armazem *lista);
Tarefas_armazem *exportar_prioridade_categoria(Tarefas_armazem *lista);
Tarefas_armazem *alterar(Tarefas_armazem *lista);