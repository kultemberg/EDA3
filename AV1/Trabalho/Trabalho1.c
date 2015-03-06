#include <stdio.h>
#include <stdlib.h>
#include "FunctionsArvore.h"

int main()
{

   int op=-1;
   int c=0,id=0;
   float n1=0,n2=0,n3=0;
   char nome[50];

    Arv* a;
    a = inicializa();
do{

printf("   ______________________* CADASTRO DE ALUNOS *_______________________\n");
printf("\n\n ----MENU----\n\n");
printf("[0]:Sair \n");
printf("[1]:Inserir estudante \n");
printf("[2]:PrintInOrdem \n");
printf("[3]:PrintPreOrdem \n");
printf("[4]:PrintPosOrdem\n");
printf("[5]:Excluir\n");
printf("[6]:busca\n");
printf("[7]:Ler do arquivo\n\n");
printf("Op: ");
    scanf("%d",&op);
    system ("cls");

    switch(op){

        case 0:
            printf("\n\nTCHAU :D !\n");
            break;

        case 1:

            printf("Cadastro do aluno\n");
            printf("ID: ");
            scanf("%d", &id);
            fflush(stdin);
            printf("nota1: ");
            scanf("%f", &n1);
            fflush(stdin);
            printf("nota 2: ");
            scanf("%f", &n2);
            printf("nota 3: ");
            scanf("%f", &n3);
            fflush(stdin);
            printf("nome: ");
            scanf("%[^\n]",nome);
            fflush(stdin);

           a = insere(a,id,n1,n2,n3,nome);

            system ("cls");
            break;

        case 2:
            printf("Imprimindo valores em ordem\n\n");
           imprimeInOrdem(a);
            break;
        case 3:
            printf("Imprimindo valores em pre ordem\n\n");
           imprimePreOrdem(a);
            break;
        case 4:
            printf("Imprimindo valores em Pos ordem\n\n");
           imprimePosOrdem(a);
            break;
        case 5:
            printf("\nDigite o valor a ser excluido\n");
            scanf("%d",&c);
            retira (a, c);
            break;
        case 6:
            printf("entre com o id a procurar");
            scanf("%d",&c);

            if(busca(a,c)){
                printf("\nencontrado!\n");
            }else{
                printf("\nNAO encontrado!\n");
            }
            break;

            case 7:
            a = lerDoArquivo("notas.dat",a);
            break;

        default:
            printf("digite uma opção valida\n");
    }
}while(op);




    //imprimeInOrdem(a);
    //imprimePreOrdem(a);

    //a = retira(a,6);

    //printf("Arvore impressa \n");
    if(binaria(a)==1){
    printf("\n\nArvore estritamente binaria\n");
    }else{
    printf("\n\nArvore NAO he binaria\n");
    }

    int test = qtdNos(a);
    printf("\nQTD NOS %d\n",test);

    int folha = qtdFolha(a);
    printf("\nQTD FOLHAS %d\n",folha);
    //imprimePreOrdem(a);

    int soma = somaNos(a);
    printf("\nSoma dos nos %d\n\n",soma);

    int alt = altura(a);
    printf("\nAltura da arvore %d \n", alt);

    int ce = CalculaEscalar(a,10);
    if(ce == NULL){
        printf("\nVALOR NAO EXITE NA ARVORE \n");
    }else{
        printf("\nTotal no Escalar: %d\n", ce);
    }


    //imprimePreOrdem(a);
    //imprimePosOrdem(a);



    return 0;
}
