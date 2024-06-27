#include <stdio.h>//biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h>//biblioteca de aloca��o de texto por regi�o
#include <string.h>//biblioteca respons�vel por cuitar das string

int Registro() //Fun��o respns�vel de cadastrar o usu�rio no sistema
{
	//inicio cria��o de vari�ves/string
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final cria��o de vari�ves/string
	
	printf("Digite o cpf a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); //%s usado para salvar uma string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza
	fprintf(file, ","); //separa por virgulas
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,nome); 
	fclose(file); 
	
	file = fopen(arquivo, "a"); 
	fprintf(file,","); 
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,sobrenome); 
	fclose(file); 
	
	file = fopen(arquivo, "a"); 
	fprintf(file,","); 
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,cargo); 
	fclose(file);
		system("pause");
			
}

int Consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;	
	file = fopen(cpf,"r"); //ler o arquivo
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); 
		printf("%s", conteudo);
		printf("\n\n");	
	}
	
		system("pause");		
}

int Deletar()
{
	char cpf[40];
	printf("Digite o cpf do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	printf("O usu�rio foi deletado com sucesso!.\n");
	system("pause");
	
	FILE *file;	
	file = fopen(cpf,"r"); //ler o arquivo
	
	if(file == NULL)
	{
		
		printf("O usu�rio n�o se encontra no sistema!.\n");
	}
		system("pause");	
}

int main()
	{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); //limpar a tela
		 
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("###Cart�rio da EBAC###\n\n"); //Inicio do menu
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n");
		printf("\t4 - Sair do Sistema \n\n"); 
		printf("Opcao: "); //Fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls");
		
		switch(opcao)
		{
		case 1: 
		Registro(); //chamada de fun��es
		break;
		
		case 2:
		Consulta();
		break;
		
		case 3:
		Deletar();
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema!.\n");
		return 0;
		break;
		
		default:
		printf("Esta opcao nao esta disponivel!\n");
		system("pause"); 
		break;	 
		}//Fim da sele��o
	}
	
}
