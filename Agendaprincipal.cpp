
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

typedef struct Agenda
{
        char nome[50];
        char fone[17];
}T_agenda;


void incluir(void);
void listar(void);
void quick_struct(int);
void qs_struct(int,int);
void pesquisar_nome(void);
void alterar();
char validaresp();

static int qtd = 0;

T_agenda Tab[100];
FILE *fp;


// =================================================================
// ======Incluir dados no arquivo ==================================

void incluir(void){
     int total = 0, retorno;
     char op = 's';

     if ((fp = fopen("agenda.db", "a")) == NULL)
     {
        printf ("O arquivo não pode ser aberto!\n");
        printf ("Insira dados!\n");
        getch();
        exit(1);
     }
     while ((total < 100) && (op == 's'))
     {
           printf ("Digite o nome do contato: ");
           gets(Tab[total].nome);
           printf ("Digite o numero do contato: ");
           gets(Tab[total].fone);
           

           retorno = fwrite (&Tab[total], sizeof(struct Agenda) ,1,fp);

           if (retorno == 1) {
               printf(" \nOperação feita com sucesso ! ");
           }
           total++;
           op = validaresp();
           qtd++;
     }
     fclose (fp);
}

//======================================================================
// ======Valida resposta ===============================================

char validaresp() {
   char op;
   do {
      printf(" \nDeseja inserir novos contatos? [S ou N] ? " );
      op = getch();
      printf("\n" );
   } while (op != 's' && op != 'n');
   return op;
}

// Função para fazer a pesquisa do contato no arquivo, verificar se existe e imprimir na tela os dados 
void pesquisar(void){
     int indice = 0, retorno = 1, cont = 0;
     char nome[80],op;

     if ((fp = fopen("agenda.db", "r")) == NULL){
     printf ("O arquivo não pode ser aberto!\n");
     printf ("Insira dados!\n");
     getch();
     exit(1);
     }
     printf ("Digite o nome do contato: ");
     gets(nome);

     retorno = fread(&Tab[indice], sizeof(struct Agenda), 1, fp);

        while (retorno == 1){
            if (strcmp(nome, Tab[indice].nome) == 0 ){
            printf ("\nNome ..: %s\nFone ..: %s\n", nome, Tab[indice].fone);
            cont++;
            }
            indice++;
            retorno = fread(&Tab[indice], sizeof(struct Agenda), 1, fp);
        }
        if(cont == 0){
                     printf("não existe ninguem com esse nome!\n");
                     }
        getch();
        fclose(fp);
   }
  
  
//função que vai mostrar os usuarios que já foram cadastrados

void listar(void){
int i = 0, retorno;

    if ((fp = fopen("agenda.db", "r")) == NULL)
    {
    printf ("O arquivo da lista não pode ser aberto!\n");
    printf ("Insira dados!\n");
    getch();
    exit(1);
    }

    retorno = fread(&Tab[i], sizeof(struct Agenda), 1, fp);
   //  retorna a quantidade de itens ...

   while ( retorno == 1) {
      printf("\n Nome ..: %s",   Tab[i].nome);
      printf("\n Fone ..: %s",   Tab[i].fone);
      i++;
      retorno = fread(&Tab[i], sizeof(struct Agenda), 1, fp);  
      }
      printf(" \n\n %d Contatos salvos!\n", i);
      getch();
      fclose(fp);
}
//======================================================================
// ======Alterar dados==================================================
void alterar()
{
    char nome[80];

    if ((fp = fopen("agenda.db", "r+")) == NULL)
	{
     printf ("O arquivo da lista não pode ser aberto!\n");
     printf ("Insira dados!\n");
     getch();
     exit(1);
    }
     printf ("Digite o nome do contato: ");
     gets(nome); 
		   
		                      
 fwrite(&Tab, sizeof(Tab), 1, fp);
 fread(&Tab, sizeof(Tab), 1, fp); 
 fclose(fp);
}


//======================================================================
// ======Menu ==========================================================

void menu(void){
char op;
int teste;

if ((fp = fopen("agenda.db", "r")) != NULL){
        qtd = 0;       
        do {
             teste = fread(&Tab, sizeof(struct Agenda), 1, fp);
             qtd++;
        }while ( teste == 1 );
        qtd--;
}

do{
system("cls");
printf("\n(1)Incluir\n(2)Listar\n(3)Pesquisar por nome\n");
printf("(4)Qualquer outra tecla para sair\n\n");
op = getch();
switch(op){
case '1':
     inclusao();
break;
case '2':
     listar();
break;
case '3':
     pesquisar();
break;
case '4':
     alterar();
break;
case '5':
     
break;
case '6':
     
break;
default:
exit(1);
}
}while (op < '7');
}

int main (){
    

    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("                  .::AGENDA ELETRONICA:.  \n\n");
    
menu();
system("pause");
}
