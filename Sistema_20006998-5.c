#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#include <locale.h>


typedef struct cadastro
{
	char titulo[50];
	int quantidadeExemplares;
	int categoria;
	int caixa;
	int edicao;
	char autor[50];
	char editora[30];
	int ano;
	int isbn;
	int exemplares;
} Cadastr_obra;


void aluno_ID();
void cadastrarObra(Cadastr_obra obra[MAX]);
void ListarTodasObras(Cadastr_obra obra[MAX]);
void ListarProdutosCategoria(int buscaCategoria, Cadastr_obra obra[MAX]);
void ListarProdutosCaixa(int buscaCaixa, Cadastr_obra obra[MAX]);
int contarRegistro(Cadastr_obra obra[MAX]);

int main()
{
	
	Cadastr_obra obra[MAX];
	setlocale(LC_ALL, "Portuguese");
	
	int op, buscaCaixa, buscaCategoria;
	char resposta;
	int i;
	do{
		aluno_ID();		
		printf("\n1 - Registrar Obras");
		printf("\n2 - Listar todas as obras");
		printf("\n3 - Listar todos os livros e revistas");
		printf("\n4 - Listar obras por caixa");
		printf("\n0 - Sair");
		printf("\nEscolha opção: ");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				resposta='s';
				while(( resposta == 'S')||(resposta == 's')){
					i++;
					system("cls");
					cadastrarObra(obra);									
					printf("Deseja cadastrar nova obra [s]-Sim [n]-Não: ");
					fflush(stdin);
					scanf("%c", &resposta);					
				}
				break;
			case 2:
				ListarTodasObras(obra);
				printf("\n");
				system("pause");
				break;
			case 3: 		
				printf("Informe a categoria da obra: [1] Livros | [2] Revistas");
				fflush(stdin);
				scanf("%d", &buscaCategoria);
				ListarProdutosCategoria(buscaCategoria, obra);
				printf("\n");
				system("pause");
				break;
			case 4: 
				printf("Informe a caixa desejada:[1] Caixa 1 |[2] Caixa 2 | [3] Caixa 3");;
				fflush(stdin);
				scanf("%d", &buscaCaixa);
				ListarProdutosCaixa(buscaCaixa, obra);
				printf("\n");
				system("pause");
				break;
			case 0:
				printf("\nSaindo do sistema!!!");
				break;
			default:
				printf("Valor indefinido");
				system("pause");
				break;
		}	
	}while(op!=0);
	return 0;
}

void aluno_ID(){
	system("cls");
	int t;
	for(t=0; t<80; t++) printf("-");
	printf("\n >>>> EDSON HENRIQUE BARALDI <<<<");
	printf("\n >>>> RA: 20006998-5 <<<< ");
	printf("\n >>>> Engenharia de Software <<<< \n");
	for(t=0; t<80; t++) printf("-");
}
void cadastrarObra(Cadastr_obra obra[MAX])
{
	aluno_ID();
	int i;
	FILE * arq;
 
	arq = fopen("dadosObras.txt", "a+");

	if(arq != NULL)
	{
		for(i = 0; i < 1; i++){
			
			printf("\nCategorias: \n[1] Livros | [2] Revistas ");
			fflush(stdin);
			scanf("%d", &obra[i].categoria);
			printf("\nInforme o titulo da Obra: ");
			printf("\nDescricação............: ");
			fflush(stdin);
			gets(obra[i].titulo);
			printf("\nQuantidade de exemplares..: ");
			fflush(stdin);
			scanf("%d", &obra[i].quantidadeExemplares);
			printf("\nCaixa...................: ");
			scanf("%d", &obra[i].caixa);			
			printf("\nInforme a edição (informe somente numeros)...:");
			fflush(stdin);
			scanf("%d", &obra[i].edicao);
			printf("\nAutor..........:");
			fflush(stdin);
			gets(obra[i].autor);
			printf("\nEditora.........:");
			fflush(stdin);
			gets(obra[i].editora);
			printf("\nInforme o ano....:");
			fflush(stdin);
			scanf("%d", &obra[i].ano);
			printf("\nInforme o ISBN (números)....:");
			fflush(stdin);
			scanf("%d", &obra[i].isbn);						
			fwrite(&obra[i], sizeof(Cadastr_obra), 1, arq);
		}
		fclose(arq); // aborta o programa
	}
	else
	{
		printf("\nErro ao abrir o arquivo para leitura!\n");
		exit(1); // aborta o programa
	}
}

int contarRegistro(Cadastr_obra obra[MAX])
{
	FILE * arq = fopen("dadosObras.txt", "r");
	if(arq != NULL)
	{
		int contador = 0;
		while(1)
		{
			Cadastr_obra p;
		
			
			int registro = fread(&p, sizeof(Cadastr_obra), 1, arq);
			
			
			if(registro < 1)
				break;
			else
				obra[contador] = p;
			contador++;
		}
		fclose(arq);
		return contador;
	}
	else
	{
		printf("\nErro ao abrir o arquivo para leitura!\n");
		exit(1);
	}
}

void ListarTodasObras(Cadastr_obra obra[MAX]){	
	aluno_ID();
	
	int quantidadeobra = contarRegistro(obra);
	int i;
	
	printf("\n>>>> Lista de obras <<<< %d\n", quantidadeobra);
	
	printf("ITEM\t| TÍTULO \t| EDIÇÃO\t| AUTOR \t| EDITORA \t | ANO \t| ISBN \t\t| CATEGORIA - 1 Livros 2 Revistas | CAIXA|");
	for(i = 0; i < quantidadeobra; i++)
	{
		printf("\n%d\t| %s \t| %d\t\t| %s \t| %s \t | %d | %d \t| %d \t\t\t\t | %d", i+1, obra[i].titulo, obra[i].edicao, obra[i].autor, obra[i].editora, obra[i].ano, obra[i].isbn, obra[i].categoria, obra[i].caixa);	
	}
}

void ListarProdutosCategoria(int buscaCategoria, Cadastr_obra obra[MAX]){	
	aluno_ID();
	
	int quantidadeobra = contarRegistro(obra);
	int i;
	
	printf("\n>>>> Lista de Produtos por categoria <<<< \n");
	if (buscaCategoria == 1) {
		printf("Categoria pesquisada: Livros \n");	
		
	}
	else (buscaCategoria == 2); {
		printf("Categoria pesquisada: Revistas \n");			
	}
	
	printf("ITEM\t| TÍTULO \t| EDIÇÃO\t| AUTOR \t| EDITORA \t | ANO \t| ISBN \t\t| CATEGORIA - 1 Livros 2 Revistas | CAIXA|");
	for(i = 0; i < quantidadeobra; i++)
	{
		if(obra[i].categoria == buscaCategoria){
			printf("\n%d\t| %s \t| %d\t\t| %s \t| %s \t | %d | %d \t| %d \t\t\t\t | %d", i+1, obra[i].titulo, obra[i].edicao, obra[i].autor, obra[i].editora, obra[i].ano, obra[i].isbn, obra[i].categoria, obra[i].caixa);	
		}
	}
}
void ListarProdutosCaixa(int buscarCaixa, Cadastr_obra obra[MAX]){
	aluno_ID();
	
	int quantidadeobra = contarRegistro(obra);
	int i;
	
	printf("\n>>>> Lista de Produtos por caixa <<<< \n");
	printf("Caixa pesquisado: %d \n", buscarCaixa);
	
	printf("ITEM\t| TÍTULO \t| EDIÇÃO\t| AUTOR \t| EDITORA \t | ANO \t| ISBN \t\t| CATEGORIA - 1 Livros 2 Revistas | CAIXA|");
	for(i = 0; i < quantidadeobra; i++)
	{
		if(obra[i].caixa == buscarCaixa){
			printf("\n%d\t| %s \t| %d\t\t| %s \t| %s \t | %d | %d \t| %d \t\t\t\t | %d", i+1, obra[i].titulo, obra[i].edicao, obra[i].autor, obra[i].editora, obra[i].ano, obra[i].isbn, obra[i].categoria, obra[i].caixa);	
		}
	}
}
