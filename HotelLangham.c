#include <ctype.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define VERMELHO "\x1b[31m"
#define VERDE   "\x1b[32m"
#define AZUL    "\x1b[36m"
#define RESET   "\x1b[0m"
#define AMARELO "\x1b[33m"

// FUNCOES DO PROGRAMA

void infoInicial(float priceF, float priceB) {
    printf("\nBem Vindo ao processo de Membership do hotel The Langham.\n\n");
    printf("Sendo membro do nosso hotel, voce e sua familia possuem "
           "oportunidades \ne acessos exclusivos a servios oferecidos pelo "
           "The Langham sem custo \nadicional, alem de prioridade e descontos "
           "nas reservas de aposentos.\n\n");
    printf(
        "A Membership family oferece descontos e prioridade em reservas de "
        "aposentos, \npreferencia em  acesso a espacos como spa, boate, free "
        "access ao bar \ne restaurantes. Alem de em reservas em quadras de "
        "tenis, golfe, \nequipamento de esgrima, canoagem windsurf e hipismo. "
        "Descontos em \ninternal shops e livre em diversos produtos oferecidos "
        "pelo hotel. \nEspacos que sua familia e voces podem aproveitar.\n\n");
    printf(
        "Se for para uma relacao business, para uma pessoa somente, lhe \n"
        "oferecemos rapidas estadias em apartamentos de ponta, com servicos \n"
        "de internet wi-fi, cabeada de alta velocidade para suas \n"
        "necessidades. Alem de acesso a todos os outros servicos oferecidos \n"
        "no pacote famalia.\n");

    printf("---------------------------Precos----------------------------\n\n");
	printf("Membership Family - $%.2f / mensais\n\n", priceF);
    printf("Membership Business - $%.2f / mensais\n", priceB);
}

void infoUser() {

    printf("\nOpcao 0 - Mostrar Menu\n"
           "Opcao 1 - Mostrar display\n"
           "Opcao 2 - Alterar Nome\n"
           "Opcao 3 - Alterar Sobrenome\n"
           "Opcao 4 - Alterar CPF\n"
           "Opcao 5 - Alterar RG\n"
           "Opcao 6 - Alterar Membership\n"
           "Opcao 7 - Concluido\n");
}


int identifyDigitInString(char input[]) {

    // return 1 for digit | 0 for no digit

    int len, result;

    result = 0;
    len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (isdigit(input[i])) {
            result = 1;
            break;
        }
    }

    return result;
}


int identifyLetterInString(char input[]) {

    // return 1 for letter| 0 for no letter

    int len, result;

    result = 0;
    len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (isalpha(input[i])) {
            result = 1;
            break;
        }
    }

    return result;
}

struct info_Cartao{
	char numeroCartao[12];
	char nomeTitular[30];
	char codigoSeg [3];
}solicitar_cartao[0];

int main() {
setlocale(LC_ALL, "Portuguese");

    const float MEMBERSHIP_FAMILY = 12000.00;
    const float MEMBERSHIP_BUSINESS = 7000.00;
    const float VIP = 1500.00;
    const float TURISMO = 2500.00;
    const float APOSENTO = 900.00;
    const float CLUB_GOLF = 1000.00;
    const float CLUB_PESCA = 700.00;
    char pass[2];

    // informacao inicial sobre a Membership
    infoInicial(MEMBERSHIP_FAMILY, MEMBERSHIP_BUSINESS);


    char cadastro[3], concluido = 0, cpf[11], primeiroNome[20], sobreNome[60], rg[10];
    float conta = 0;
    printf("*********************************************\n");
    printf("*Ola, seja bem vindo(a) ao The Langham Hotel*\n");
    printf("*Gostaria de fazer o seu cadastro?          *\n");
    printf("*               [SIM] - [NAO]               *\n");
    printf("*********************************************\n");
    
    

    scanf("%s", &cadastro);

    int cadastrando = 0, ponto = 1;

    if (((strcmp(cadastro, "sim") == 0) || strcmp(cadastro, "SIM") == 0) || strcmp(cadastro, "Sim") == 0) {
        cadastrando = 0;
        system("clear||cls");
        while (cadastrando == 0) {

            printf("\n");
            if (ponto == 1) {
                printf("Informe seu nome: ");
                scanf("%s", &primeiroNome);
                if (identifyDigitInString(primeiroNome) == 1) {
                    printf(VERMELHO "Erro, Nome invalido." RESET);					                  
                } else {
                    ponto = 2;
                    system("clear||cls");
                }

            } else if (ponto == 2) {
                printf("Informe seu sobrenome: ");
                scanf("%s", &sobreNome);
                if (identifyDigitInString(sobreNome) == 1) {
                    printf(VERMELHO "Erro, Sobrenome invalido." RESET);
                } else {
                    ponto = 3;
                    system("clear||cls");
                }

            } else if (ponto == 3) {
                printf("Informe seu CPF: ");
                scanf("%s", &cpf);
                int len = strlen(cpf);
                if (len != 11 || identifyLetterInString(cpf) == 1) {
                    printf(VERMELHO "Erro, CPF invalido." RESET);
                } else {
                    ponto = 4;
                    system("clear||cls");
                }
            } else if (ponto == 4) {
                printf("Informe seu RG: ");
                scanf("%s", &rg);
                long len = strlen(rg);
                if (len != 10 || identifyLetterInString(rg) == 1) {
                    printf(VERMELHO "Erro, RG invalido." RESET);
                } else {
                    ponto = 5;
                    system("clear||cls");
                }
            }
            if (ponto > 4) {
                int tipo, opcao;

                if (ponto == 5) {

                    printf("Qual plano deseja "
                           "inscrever-se?\nFamily[1] - $12000.00\nBusiness[2] - $7000.00\n");
                    scanf("%d", &tipo);
                    if (tipo != 1 && tipo != 2) {
                        printf(VERMELHO "Erro, escolha invalida." RESET);
                    } else if (tipo == 1) {
                        conta += MEMBERSHIP_FAMILY;
                        ponto = 6;
                        system("clear||cls");
                        printf(AZUL"Valor do carrinho: $%.2f \n" RESET, conta);
                    } else if (tipo == 2) {
                        conta += MEMBERSHIP_BUSINESS;
                        ponto = 6;
                        system("clear||cls");
                        printf(AZUL "Valor do carrinho: $%.2f \n" RESET, conta);
                    }
                } else if (ponto == 6) {
                    int next = 0;
                    infoUser();
                    while (concluido <= 0) {
                        next = 0;
                        printf("\n\nDigite a opcao do menu: ");
                        scanf("%d", &opcao);
                        switch (opcao) {
                        default:
                        	system("clear||cls");
                        	printf(VERMELHO"Voce so pode escolher as opcoes abaixo!\n"RESET);
                        	infoUser();
                        	break;
                        case 0:
                            system("clear||cls");
                            infoUser();
                            break;
                        case 1:
                        	system("clear||cls");
                            printf("Nome: %s %s\nCPF: %s\nRG: %s\n", primeiroNome,
                                   sobreNome, cpf, rg);
                            infoUser();
                            break;
                        case 2:
                            while (next == 0) {
                                printf("Informe seu nome: ");
                                scanf("%s", &primeiroNome);
                                if (identifyDigitInString(primeiroNome) == 1) {
                                    printf(VERMELHO "\nErro, Nome invalido.\n" RESET);
                                } else {
                                    next = 1;
                                    system("clear||cls");
                                    printf(VERDE"\nNome alterado com sucesso.\n\n"RESET);
                                    infoUser();
                                }
                            }
                            break;
                        case 3:
                            while (next == 0) {
                                printf("Informe seu sobrenome: ");
                                scanf("%s", &sobreNome);
                                if (identifyDigitInString(sobreNome) == 1) {
                                    printf(VERMELHO"Erro, Sobrenome invalido.\n"RESET);
                                } else {
                                    next = 1;
                                    system("clear||cls");
                                    printf(VERDE "\nSobrenome alterado com "
                                           "sucesso.\n\n"RESET );
                                    infoUser();
                                }
                            }
                            break;
                        case 4:
                            while (next == 0) {
                                printf("Informe seu CPF: ");
                                scanf("%s", &cpf);
                                int len = strlen(cpf);

                                if (len != 11 ||
                                    identifyLetterInString(cpf) == 1) {
                                    printf(VERMELHO "Erro, CPF invalido.\n" RESET);
                                } else {
                                    next = 1;
                                    system("clear||cls");
                                    printf(VERDE"\nCPF alterado com sucesso.\n\n"RESET);
                                    infoUser();
                                }
                            }
                            break;
                        case 5:
                            while (next == 0) {
                                printf("Informe seu RG: ");
                                scanf("%s", &rg);
                                long len = strlen(rg);

                                if (len != 10 || identifyLetterInString(rg) == 1) {
                                    printf(VERMELHO "Erro, RG invalido.\n"RESET );
                                } else {
                                    next = 1;
                                    system("clear||cls");
                                    printf(VERDE "\nRG alterado com sucesso.\n\n" RESET);
                                    infoUser();
                                }
                            }
                            break;
                        case 6:
                            while (next == 0) {
                                printf("Qual plano deseja "
                                       "inscrever-se?\nFamily[1]\nBusiness[2]"
                                       "\n\n");
                                scanf("%d", &tipo);
                                if (tipo != 1 && tipo != 2) {
                                    printf(VERMELHO "Erro, escolha invalida.\n"RESET);
                                } else if (tipo == 1) {
                                	conta = 0;
                                    conta += MEMBERSHIP_FAMILY;
                                    next = 1;
                                    system("clear||cls");
                                    printf(VERDE "\nPlano alterado com sucesso.\n\n" RESET);
                                    printf(AZUL"Valor do carrinho: $%.2f \n"RESET, conta);
                                    infoUser();
                                } else if (tipo == 2) {
                                	conta = 0;
                                    conta += MEMBERSHIP_BUSINESS;
                                    next = 1;
                                    system("clear||cls");
                                    printf(VERDE "\nPlano alterado com sucesso.\n\n"RESET);
                                    printf(AZUL"Valor do carrinho: $%.2f \n"RESET, conta);
                                    infoUser();
                                }
                            }
                            break;
                        case 7:
                        	system("clear||cls");
                            concluido = 1;
                            cadastrando = 2;
                        }
                    }
                }
            }
        }

        int op, check[5], out = 0;
        do {
        	printf(AZUL"Valor do carrinho: $%.2f \n"RESET, conta);
            printf("\n\nDeseja comprar junto com o pacote:\n\n"
                   "[1] Persona VIP em cassino, bares, clubs - $%.2f\n"
                   "[2] Pacote de passeios turisticos - $%.2f\n"
                   "[3] Aposentos para eventos - $%.2f\n"
                   "[4] Club de golf - $%.2f\n"
                   "[5] Club de pesca - $%.2f\n"
                   "[6] Concluido\n",
                   VIP, TURISMO, APOSENTO, CLUB_GOLF, CLUB_PESCA);

            scanf("%d", &op);

            switch (op) {
            default:
            	system("clear||cls");
            	printf(VERMELHO"Voce so pode escolher as opcoes abaixo!\n"RESET);
            	break;
            case 1:
                if (check[0] != 1) {
                    conta += VIP;
                    check[0] = 1;
                    system("clear||cls");
                    printf(VERDE"Item adicionado.\n"RESET);
                    break;
                } else {
                    system("clear||cls");
                    printf(VERMELHO"Voce nao pode adcionar o mesmo item ao carrinho!\n"RESET);
                    break;
                }
            case 2:
                if (check[1] != 1) {
                    conta += TURISMO;
                    check[1] = 1;
                    system("clear||cls");
                    printf(VERDE"Item adicionado.\n"RESET);
                    break;
                } else {
                    system("clear||cls");
                    printf(VERMELHO"Voce nao pode adcionar o mesmo item ao carrinho!\n"RESET);
                    break;
                }
            case 3:
                if (check[2] != 1) {
                    conta += APOSENTO;
                    check[2] = 1;
                    system("clear||cls");
                    printf(VERDE"Item adicionado.\n"RESET);
                    break;
                } else {
                    system("clear||cls");
                    printf(VERMELHO"Voce nao pode adcionar o mesmo item ao carrinho!\n"RESET);
                    break;
                }
            case 4:
                if (check[3] != 1) {
                    conta += CLUB_GOLF;
                    check[3] = 1;
                    system("clear||cls");
                    printf(VERDE"Item adicionado.\n"RESET);
                    break;
                } else {
                    system("clear||cls");
                    printf(VERMELHO"Voce nao pode adcionar o mesmo item ao carrinho!\n"RESET);
                    break;
                }
            case 5:
                if (check[4] != 1) {
                    conta += CLUB_PESCA;
                    system("clear||cls");
                    check[4] = 1;
                    printf(VERDE"Item adicionado.\n"RESET);
                    break;
                } else{
                    system("clear||cls");
                    printf(VERMELHO"Voce nao pode adcionar o mesmo item ao carrinho!\n"RESET);
                    break;
                }
            case 6:
                system("clear||cls");
                out = 1;
                break;
            }
        } while (out != 1);
        {
        	printf("Processando dados");
        	for(int x = 0; x < 3; x++){
        		printf(".");
        		Sleep(1000);	
			}
			system("clear||cls");
            printf("Obrigado pela confianca, boa estadia.\n"
                   "Siga para o check out.\n");
            printf(AZUL"\n* O total do seu carrinho foi de $%.2f * \n"RESET, conta);       
        }
        
        if (cadastrando == 2) {
            time_t t;

            srand(time(&t));
            char text[2];
            int numeros[8];
            for (int i = 0; i < 9; i++) {
                int num = rand() % 10;
                sprintf(text, "%d", num);
                pass[i] = text[0];
            }

            printf("\nAnote sua senha, voce precisara dela! -> %s\n", pass);
            system("pause");
            
        }
	    int qnt;
        printf("\n\nDeseja realizar o pagamento usando quantos cartoes?: ");
        scanf("%d",&qnt);
		
        for(int x = 0; x < qnt; x++){
        	printf("\nInsira os dados do cartao %d!", x + 1);
        	
			printf("\nDigite o numero do cartao: ");
			fflush(stdin);
			gets(solicitar_cartao[x].numeroCartao);
			
			printf("\nCodigo de seguranca: ");
			fflush(stdin);
			gets(solicitar_cartao[x].codigoSeg);
			
			printf("\nNome do titular: ");
			fflush(stdin);
			gets(solicitar_cartao[x].nomeTitular);	 	
		}
		
		char verfSenha[8];
		int verf;
		
		do{
			printf("\nDigite a sua senha: ");
			scanf("%s", &verfSenha);
			
			if(strcmp(verfSenha, pass) == 0){
				printf(VERDE"A senha esta correta!\n"RESET);
				verf = 1;
			}else{
				printf(VERMELHO"Senha Invalida!\n"RESET);
				verf = 2;
		}
	}while(verf == 2);
	
	Sleep(3000);
	system("clear||cls");
	for(int y = 0; y < 2; y++){
		printf("Processando Pagamento");
		    	for(int x = 0; x < 3; x++){
		    		printf(".");
		    		Sleep(1000);	
			}
			system("clear||cls");
		}
		
		char nota_Fiscal[3];
		printf(VERDE"Pagmento realizado com sucesso!\n\n"RESET);
		printf("deseja imprimir a nota fiscal?\n[sim] - [nao]: ");
		scanf("%s", &nota_Fiscal);
		system("clear||cls");
		
		if (strcmp(nota_Fiscal, "sim") == 0){
			printf(AMARELO"HOTEL The Langham_____________________________________||	\n");
			printf("______________________________________________________||	\n");
			printf("Nome:%s              valor pago: $%.2f	\n",primeiroNome, conta);
			printf("______________________________________________________||	\n");
			printf("______________________________________________________||	\n");
			printf("____________________________Obrigado pela preferencia!||	\n");
			printf("______________________________________________________||	\n");
		}else{
			printf(AMARELO"Obrigado pela preferencia!"RESET);
		}
		}else{
    	system("clear||cls");
    	printf(AMARELO"\nAte a proxima!\n\n"RESET);
    }
}
