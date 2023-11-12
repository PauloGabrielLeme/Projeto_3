//Paulo Gabriel Gonçalves Leme - R.A: 24.123.075-4

#include "biblioteca.h"


int main(){
  int s=0; //Variavel de seleção

  Tarefas_armazem *lista_tarefas;

  lista_tarefas = leitura("lista.txt"); 
  // Le o arquivo .txt e coloca no lista
  // todos as tarefas presentes no arquivo


  do{

    lobby(); 

    scanf("%d",&s); 


    if (s == 1) {
      lista_tarefas = cadastrarTarefa(lista_tarefas); 
      // Chama a funcao para cadastrar uma tarefa
    } 
    else if (s == 2) {
      listar_tarefas(lista_tarefas); 
      // Chama a funcao para mostrar na tela do  
      // usuario todas as tarefas
    } 
    else if (s == 3) {
      lista_tarefas =
          deletarTarefa(lista_tarefas); 
          // Chama a funcao para listar todas as
          // tarefas ja criadas pelo usuario
    } 
    else if(s == 4){
    }
    else if(s==5){
      filtrar_prioridade(lista_tarefas);
    }
    else if(s==6){
      filtrar_categoria(lista_tarefas);
    } 
    else if(s==7){
      filtrar_status(lista_tarefas);
    }
    else if(s==8){
      filtrar_prioridade_categoria(lista_tarefas);
    }
    else if(s==9){
      exportar_categoria(lista_tarefas);
    }
    else if(s==10){
      exportar_prioridade(lista_tarefas);
    }
    else if(s==11){
      exportar_prioridade_categoria(lista_tarefas);
    }
    else if(s==12){
      escreve(lista_tarefas,"lista.txt"); 
      // Fecha o programa e salva a lista no arquivo .txt
      break;
    }
    else{
      printf("\nOpcao Invalida\n");
      printf("Tente Novamente\n");
    }
  }while(s!=12);

  return 0;
}