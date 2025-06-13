#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void CadastrarTarefa(char Tarefas[][4][50], int *quantidade);
void ListarTarefa(char Tarefas[][4][50], int quantidade);
void EditarTarefa(char Tarefas[][4][50], int indice);
void ExcluirTarefa(char Tarefas[][4][50], int *quantidade, int indice);
void SalvarTarefasEmArquivo(char Tarefas[][4][50], int quantidade);


int main()
{
    char tarefas[MAX][4][50];
    int quantidade = 0, opcao, indice;
    while(1)
    {
        printf("\n 1. Cadastrar Tarefa\n 2. Listar Tarefas\n 3. Editar Tarefa\n 4. Excluir Tarefa\n 5. Salvar Tarefas em Arquivo\n 6. Sair\n Escolha: ");
        scanf("%d%*c", &opcao); 
        if(opcao == 1)
        {
         CadastrarTarefa(tarefas, &quantidade);    
        }   
        else
        {
            if(opcao == 2)
            {
                ListarTarefa(tarefas, quantidade);
            }
            else
            {
                if(opcao == 3)
                {
                    printf("Número da tarefa: ");
                    scanf("%d%*c", &indice);
                    if(indice >= 1 && indice <= quantidade)
                    {
                        EditarTarefa(tarefas, indice - 1);
                    }
                    else
                    {
                        printf("Tarefa não encontrada!!\n");            
                    }
                    if(opcao == 4)
                    {
                        printf("Número da tarefa: ");
                        scanf("%d%*c", &indice);
                        if(indice >= 1 && indice <= quantidade)
                        {
                            ExcluirTarefa(tarefas, &quantidade, indice - 1);
                        }
                        else
                        {
                            printf("Tarefa Inválida!!\n");
                        }
                        if(opcao == 5)
                        {
                            SalvarTarefasEmArquivo(tarefas, quantidade);
                        }
                        else
                        {
                            if(opcao == 6)
                            {
                                break;
                            }
                            else
                            {
                                printf("Opção Inválida!!\n");
                            }
                        }
                    }
                }
            }
        }
    }       
    return 0;
}

void CadastrarTarefa(char Tarefas[][4][50], int *quantidade)
{
      printf("Titulo: ");
    fgets(Tarefas[*quantidade][0], 50, stdin);
    Tarefas[*quantidade][0][strcspn(Tarefas[*quantidade][0], "\n")] = 0;

    printf("Descricao: ");
    fgets(Tarefas[*quantidade][1], 50, stdin);
    Tarefas[*quantidade][1][strcspn(Tarefas[*quantidade][1], "\n")] = 0;

    printf("Prioridade (Alta/Media/Baixa): ");
    fgets(Tarefas[*quantidade][2], 50, stdin);
    Tarefas[*quantidade][2][strcspn(Tarefas[*quantidade][2], "\n")] = 0;

    printf("Status (Pendente/Concluido): ");
    fgets(Tarefas[*quantidade][3], 50, stdin);
    Tarefas[*quantidade][3][strcspn(Tarefas[*quantidade][3], "\n")] = 0;

    (*quantidade)++;
}

void ListarTarefa(char Tarefas[][4][50], int quantidade)
{
    for(int i = 0; i < quantidade; i++)
    {
        printf("Tarefa %d: %s - %s - Prioridade: %s - Status: %s\n",
        i+1, Tarefas[i][0], Tarefas[i][1], Tarefas[i][2], Tarefas[i][3]);
    }
}

void EditarTarefa(char Tarefas[][4][50], int indice)
{
    printf("Novo titulo: ");
    fgets(Tarefas[indice][0], 50, stdin);
    Tarefas[indice][0][strcspn(Tarefas[indice][0], "\n")] = 0;

    printf("Nova descricao: ");
    fgets(Tarefas[indice][1], 50, stdin);
    Tarefas[indice][1][strcspn(Tarefas[indice][1], "\n")] = 0;

    printf("Nova prioridade: ");
    fgets(Tarefas[indice][2], 50, stdin);
    Tarefas[indice][2][strcspn(Tarefas[indice][2], "\n")] = 0;

    printf("Novo status: ");
    fgets(Tarefas[indice][3], 50, stdin);
    Tarefas[indice][3][strcspn(Tarefas[indice][3], "\n")] = 0;
}

void ExcluirTarefa(char Tarefas[][4][50], int *quantidade, int indice)
{
    for(int i = indice; i < *quantidade - 1; i++) 
    {
        for(int j = 0; j < 4; j++) 
        {
        strcpy(Tarefas[i][j], Tarefas[i+1][j]);
        }
    }
    *quantidade--;
}

void SalvarTarefasEmArquivo(char Tarefas[][4][50],int quantidade)
{
    FILE *f = fopen("tarefas.txt", "w");
    for(int i = 0; i < quantidade; i++) 
    {
        fprintf(f, "Tarefa %d: %s - %s - Prioridade: %s - Status: %s\n",
        i+1, Tarefas[i][0], Tarefas[i][1], Tarefas[i][2], Tarefas[i][3]);
    }
    fclose(f);
}