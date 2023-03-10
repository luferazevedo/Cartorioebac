#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o cpf a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salva valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //ler o arquivo
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado \n" );
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEstas são as informações do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
}
int deletar()
{
	printf("Você escolheu deletar nomes\n");
	system("pause");
}

int main()
{
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;laco++)
	{
	system("cls");
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("### Cartório da EBAC ###\n\n");
//Início do menu
	printf("Escolha a opção desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n");
	printf("Opção: ");
	
	scanf("%d", &opcao);
	
	system("cls");
	
	
	switch(opcao)
	{
		case 1:
				registro();
				break;
		case 2:
				consulta();
				break;				
		case 3:
				deletar();
				break;				
		case 4:
				printf("Esta opção é inválida \n");
				system("pause");
				break;			
	}
	printf("\n\n\nEsse Software é opensource\n");
}
}