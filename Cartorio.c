#include <stdio.h>//biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de  alocação de espaço em memória
#include <locale.h>//biblioteca de alocações de texto por região
#include <string.h>//biblioteca responsável por cuidar dos strings

int registro() //função responável por cadastrar usuarios no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informação do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // responsavel por copiar valores do string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ","); // salvar
	fclose(file); //fechar
	
	printf("Digite o nome a ser cadastrado: "); // coletando informação
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //atualiza
	fprintf(file, nome); //salva
	fclose(file); //fecha

	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);		
	
	system("pause");
	
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: "); //coletando informação
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível encontrar o arquivo! \n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("digite o cpf a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema! \n");
		system("pause");
	
	}
	
	
	}


int main ()
{
	
	setlocale(LC_ALL, "Portuguese");
	int opcao=0; //definindo variáveis
	int x=1;
	char senhadigitada[10]="a";
	
	int comparacao;
	
	printf("Cartório da EBAC\n\n");
	printf("Login de Administrador\n\n Digite sua Senha:");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada,"admin");
	
	if(comparacao == 0)
	{
	
	system("cls");
	
        for(x=1;x=1;)
	    {
	
    	system("cls");

    	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
    	printf("\t Cartório da EBAC \n\n");//inicio do menu
    	printf("Escolha a opção desejada do menu:\n\n");
    	printf("\t1 Registro de usuários\n\t2 Consulta de usuários\n\t3 Deletar usuários\n\n\t4 Sair do sistema\n\n");
    	printf("opção:"); //fim do menu
	
    	scanf("%d", &opcao); // armazenando a escolha do usuário
	
    	system("cls");// responsavel por limpar a tela
    	
    	    switch(opcao) //inicio da seleção do menu
    	    {
    		case 1://chamada de funções
			registro();
    		break;
    		
    		case 2:
    		consulta();		    
			break;
			    
		    case 3:
		    deletar();
		    break;
		    
		    case 4:
		    printf("Obrigado por usar o sistema!\n");
		    return 0;
			break;
					
		    default:
		    printf("essa opção está indisponivel\n");
		    system("pause");
		    break;
		    // fim da seleção
		    }
	
	    }
    }
    
    else
	{
	
    printf("\nSenha incorreta!\n\n");
    system("pause");
    system("cls");
    main();
    
    }
}
