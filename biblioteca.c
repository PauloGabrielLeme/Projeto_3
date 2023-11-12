#include "biblioteca.h"

void lobby() { // Funcao que demonstra ao usuarios todas as opcoes que ele pode
    // utilizar no aplicativo
    printf("\n1 - Cadastrar nova tarefa\n");
    printf("2 - Listar tarefas ja criadas\n");
    printf("3 - Deletar uma terefa\n");
    printf("4 - Fechar programa\n");
    printf("\nDigite o numero da opcao desejada: ");
}

Tarefas_armazem *leitura(char *nome) {
    
    FILE *f = fopen(nome, "rb"); // Abre o arquivo

    
  
    Tarefas_armazem *v = (Tarefas_armazem *)malloc(
            100 * sizeof(Tarefas_armazem)); // Realiza a alocacao dinamica do array de
    // struct struct ate o tamanho 100

    if(f == NULL){
        v->tam = 0;
    }else{
        fread(v, sizeof(Tarefas_armazem), 100,
              f); // Le ate a linha 100 e coloca todas as informacoes no array de
        // struct struct
        fclose(f); // Fecha o arquivo
    }


    return v; // Retorna o array de struct struct com as informacoes do arquivo
    // .txt
}

void escreve(Tarefas_armazem *v, char *nome) {
    FILE *f = fopen(
            nome, "w"); // Realiza a abertura do arquivo com o objetivo de escrever
    // todas as possiveis tarefas feitas pelo usuario
    fwrite(v, sizeof(Tarefas_armazem), 100, f); // Escreve as tarefas
    fclose(f);                                  // Fecha o arquivo
}

Tarefas_armazem *cadastrarTarefa(Tarefas_armazem *lista) {
    int indice = lista->tam; // Declara a variavel "indice" para guardar o valor
    // do tamanho da struct

    lista->tam = indice + 1; // Somando 1 ao valor atual da lista

    printf("\n====================\n");

    printf("Digite a prioridade da tarefa de 1 a 10: ");
    scanf("%d", &lista->tarefas[indice]
            .prioridade); // Recebe a entrada da variavel de prioridade
    

    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    printf("Escreva a categoria da tarefa: ");
    fgets(lista->tarefas[indice].categoria, 100, stdin); // Recebe a entrada da variavel de categoria

    
          

  
    printf("Escreva a descricao da tarefa: ");
    fgets(lista->tarefas[indice].descricao, 300, stdin); // Recebe a entrada da variavel de descricao
    printf("\nTarefa adionada a lista com exito\n");
    printf("=================\n");
    return lista; // Retorna o novo  array de struct de struct com tamanho
    // atualizado e a nova tarefa adicionada
}

void listar_tarefas(Tarefas_armazem *lista) {

    // Realiza a verificação se a lista esta vazia

    if (lista->tam == 0) {
        printf("\n====================\n");
        printf("Lista de tarefas vazia....\n");
        printf("====================\n");
    } else {
        printf("\n====================\n");
        printf("Lista Tarefas Atual: \n");

        for (int i = 0; i < lista->tam;
             i++) { // Realiza um for que vai iterar ate o tamanho atual da lista de
            // tarefas que vai realizando o print de cada tarefa
            printf("Tarefa - %d\n", i + 1);
            printf("Prioridade: %d\n", lista->tarefas[i].prioridade);
            printf("Categoria: %s", lista->tarefas[i].categoria);
            printf("Descricao: %s\n", lista->tarefas[i].descricao);
        }
        printf("====================\n");
    }
}

Tarefas_armazem *deletarTarefa(Tarefas_armazem *lista) {

    // Realiza a verificacao se a lista esta vazia

    if (lista->tam == 0) {
        printf("\n====================\n");
        printf("Lista de tarefas vazia....\n");
        printf("====================\n");
        return lista;
    } else {
        Tarefas_armazem *lista_temp = (Tarefas_armazem *)malloc(
                100 * sizeof(Tarefas_armazem)); // Criacao de um array de struct de
        // struct temporario

        listar_tarefas(lista); // Lista todas as tarefas para o usuario escolher
        // qual deseja deletar

        int tamanho = lista->tam; // Declara a variavel tamanho para guardar o
        // tamanho atual da struct

        int indice;

        printf("\nDigite o numero da tarefa que deseja deletar: ");
        scanf("%d", &indice); // Variavel que vai receber o valor que o usuario
        // deseja deletar

        int cont = 0;

        for (int i = 0; i < tamanho;
             i++) { // For que realiza a iteracao ate o tamanho da lista e caso o
            // "i" seja igual ao "indice" o programa nao adiciona na lista
            // temporaria
            if (i != indice - 1) {
                lista_temp->tarefas[cont].prioridade = lista->tarefas[i].prioridade;
                strcpy(lista_temp->tarefas[cont].categoria,
                       lista->tarefas[i].categoria);
                strcpy(lista_temp->tarefas[cont].descricao,
                       lista->tarefas[i].descricao);
                cont++;
            }
        }

        lista_temp->tam = lista->tam - 1; // Subtraindo 1 ao valor atual da lista
        return lista_temp; // Retorna a nova lista com a tarefa que o usuario
        // desejou excluida
    }
}

Tarefas_armazem *filtrar_prioridade(Tarefas_armazem *lista){
    int p=0; 
    //Todas as tarefas que forem de prioridade igual à p serão listadas
    //Senão serão ignoradas
    printf("Digite A Prioridade Da(s) Tarefas A Serem Listadas: ");
    scanf("%d",&p); 

    if(lista->tam==0){
        printf("\n====================\n");
        printf("Lista de tarefas vazia....\n");
        printf("====================\n");
        return lista;       
    }
    else{
        printf("======================\n");
        printf("\n====================\n");
        printf("Lista Tarefas De Prioridade %d: \n",p);
        for (int i = 0; i < lista->tam;i++) {
        // Realiza um for que vai iterar ate o tamanho atual da lista de
        // tarefas que vai realizando o print de cada tarefa
            if(lista->tarefas[i].prioridade==p){
                printf("Tarefa - %d\n", i + 1);
                printf("Prioridade: %d\n", lista->tarefas[i].prioridade);
                printf("Categoria: %s\n", lista->tarefas[i].categoria);
                printf("Descricao: %s\n", lista->tarefas[i].descricao);
                printf("Status: %s\n",lista->tarefas[i].status);
                printf("====================\n");
            }
        }
        printf("====================\n");

    }

}

char *input(char *str) { //Funcao para receber strings sem dar bugs
    int c;
    scanf("%[^\n]s", str); //Recebe o array de chars/string
    while ((c = getchar()) != '\n' && c != EOF) {} //Impede Que Sejam Pulados input futuros após ser pressionada a tecla "enter"

    return str;
}

Tarefas_armazem *filtrar_categoria(Tarefas_armazem *lista){
    char p[300];
    int c;
    int cmp; //Faz as comparações de strings 0 significa igual, outros         valores diferentes
    //Todas as tarefas que forem de mesma categoria à p serão listadas
    //Senão serão ignoradas
    printf("Digite A Categoria Da(s) Tarefas A Serem Listadas: ");
    while ((c = getchar()) != '\n' && c != EOF) {}
    input(p);
  
    if(lista->tam==0){
        printf("\n====================\n");
        printf("Lista de tarefas vazia....\n");
        printf("====================\n");
        return lista;       
    }
    else{
        printf("======================\n");
        printf("\n====================\n");
        printf("Lista Tarefas De Categoria '%s': \n",p);
        for (int i = 0; i < lista->tam;i++) {
          cmp=strcmp(lista->tarefas[i].categoria,p);//Compração das strings
        // Realiza um for que vai iterar ate o tamanho atual da lista de
        // tarefas que vai realizando o print de cada tarefa
            if(cmp==0){
                printf("Tarefa - %d\n", i + 1);
                printf("Prioridade: %d\n", lista->tarefas[i].prioridade);
                printf("Categoria: %s\n", lista->tarefas[i].categoria);
                printf("Descricao: %s\n", lista->tarefas[i].descricao);
                printf("Status: %s\n",lista->tarefas[i].status);
                printf("======================\n");
            }
        }
        printf("====================\n");

    }

}

Tarefas_armazem *filtrar_status(Tarefas_armazem *lista){
    char p[50];
    int c;
    int cmp; //Faz as comparações de strings 0 significa igual, outros         valores diferentes
    //Todas as tarefas que forem de mesma categoria à p serão listadas
    //Senão serão ignoradas
    printf("Digite O Status Da(s) Tarefas A Serem Listadas: ");
    while ((c = getchar()) != '\n' && c != EOF) {}
    input(p);

    if(lista->tam==0){
        printf("\n====================\n");
        printf("Lista de tarefas vazia....\n");
        printf("====================\n");
        return lista;       
    }
    else{
        printf("======================\n");
        printf("\n====================\n");
        printf("Lista Tarefas De Status '%s': \n",p);
        for (int i = 0; i < lista->tam;i++) {
          cmp=strcmp(lista->tarefas[i].status,p); //Comparacao das strings
        // Realiza um for que vai iterar ate o tamanho atual da lista de
        // tarefas que vai realizando o print de cada tarefa
            if(cmp==0){
                printf("Tarefa - %d\n", i + 1);
                printf("Prioridade: %d\n", lista->tarefas[i].prioridade);
                printf("Categoria: %s\n", lista->tarefas[i].categoria);
                printf("Descricao: %s\n", lista->tarefas[i].descricao);
                printf("Status: %s\n",lista->tarefas[i].status);
                printf("======================\n");
            }
        }
        printf("====================\n");

    }

}

Tarefas_armazem *filtrar_prioridade_categoria(Tarefas_armazem *lista){
    char str[300];
    int p=0;
    int c;
    int cmp; //Faz as comparações de strings 0 significa igual, outros         valores diferentes
    //Todas as tarefas que forem de mesma categoria à p serão listadas
    //Senão serão ignoradas
    printf("Digite A Categoria Da(s) Tarefas A Serem Listadas: ");
    while ((c = getchar()) != '\n' && c != EOF) {}
    input(str);
    printf("Digite A Prioridade Da(s) Tarefas A Serem Listadas: ");
    scanf("%d",&p);

    if(lista->tam==0){
        printf("\n====================\n");
        printf("Lista de tarefas vazia....\n");
        printf("====================\n");
        return lista;       
    }
    else{
        printf("======================\n");
        printf("\n====================\n");
        printf("Lista Tarefas De Categoria '%s' e Prioridade '%d': \n",str,p);
        for (int i = 0; i < lista->tam;i++) {
          cmp=strcmp(lista->tarefas[i].categoria,str);//Compracao das strings
        // Realiza um for que vai iterar ate o tamanho atual da lista de
        // tarefas que vai realizando o print de cada tarefa
            if(cmp==0 && lista->tarefas[i].prioridade==p){
                printf("Tarefa - %d\n", i + 1);
                printf("Prioridade: %d\n", lista->tarefas[i].prioridade);
                printf("Categoria: %s\n", lista->tarefas[i].categoria);
                printf("Descricao: %s\n", lista->tarefas[i].descricao);
                printf("Status: %s\n",lista->tarefas[i].status);
                printf("======================\n");
            }
        }
        printf("====================\n");

    }

}

Tarefas_armazem *exportar_prioridade(Tarefas_armazem *lista){
    int p=0; //Variavel da prioridade que o usuário deseja exportar
    //Todas as tarefas que forem de mesma categoria à p serão listadas
    //Senão serão ignoradas
    printf("Digite A Prioridade Da(s) Tarefas A Serem Exportadas: ");
    scanf("%d",&p);

    FILE *f = fopen("lista_prioridade.txt","w");

    if(lista->tam==0){
        printf("\n====================\n");
        printf("Lista de tarefas vazia....\n");
        printf("====================\n");
        return lista;       
    }
    else{
        printf("======================\n");
        fprintf(f,"\n====================\n");
        fprintf(f,"Lista Tarefas De Prioridade '%d': \n",p);
        for (int i = 0; i < lista->tam;i++) {
          
        // Realiza um for que vai iterar ate o tamanho atual da lista de
        // tarefas que vai realizando o print de cada tarefa
            if(lista->tarefas[i].prioridade==p){
                fprintf(f,"Tarefa - %d\n", i + 1);
                fprintf(f,"Prioridade: %d\n", lista->tarefas[i].prioridade);
                fprintf(f,"Categoria: %s\n", lista->tarefas[i].categoria);
                fprintf(f,"Descricao: %s\n", lista->tarefas[i].descricao);
                fprintf(f,"Status: %s\n",lista->tarefas[i].status);
                fprintf(f,"======================\n");
            }
        }
        fclose(f);
        printf("Dados Exportados Com Sucesso!\n");
        printf("====================\n");

    }


}

Tarefas_armazem *exportar_categoria(Tarefas_armazem *lista){

    
}