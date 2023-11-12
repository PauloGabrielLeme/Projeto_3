//Paulo Gabriel Gonçalves Leme - R.A: 24.123.075-4

#include "biblioteca.h"


int main() {

  Tarefas_armazem *lista_tarefas;

  lista_tarefas = leitura("lista.txt"); // Le o arquivo .txt e coloca no lista
                                        // todos as tarefas presentes no arquivo
    
  while (true) {
    lobby();

    int desejo;

    scanf("%d", &desejo);

    if (desejo == 1) {
      lista_tarefas = cadastrarTarefa(
          lista_tarefas); // Chama a funcao para cadastrar uma tarefa
    } else if (desejo == 2) {
      listar_tarefas(lista_tarefas); // Chama a funcao para mostrar na tela do
                                     // usuario todas as tarefas
    } else if (desejo == 3) {
      lista_tarefas =
          deletarTarefa(lista_tarefas); // Chama a funcao para listar todas as
                                        // tarefas ja criadas pelo usuario
    } else {
      escreve(lista_tarefas,
              "lista.txt"); // Fecha o programa e salva a lista no arquivo .txt
      break;
    }
  }

  return 0;
}