#include<stdio.h>


void ImprimirTabuleiro(char Tabuleiro[7][8]);
void TestarLigados(char Tabuleiro[7][8]);
void InsereJogada(char Tabuleiro[7][8],char jogador);
char TrocarJogador(char jogador);
int TabuleiroCheio(char Tabuleiro[7][8]);
void ColocarBranco(char Tabuleiro[7][8]);
int main()
{
	char Tabuleiro[7][8];
	int linha,coluna,cheio=0,i,a;
	char jogador='X';
	ColocarBranco(Tabuleiro);
	jogador=TrocarJogador( jogador);
	printf("Digite qualquer coisa para continuar...");
	getchar();system("PAUSE");	
		for(a=0;a<6;a++)
		{;printf("~~~~");}sleep(1);
		printf("O jogo sera iniciado...");sleep(1);
    	for(a=0;a<6;a++)
    	{printf("~~~~"); } puts("");puts(""); system("cls");sleep(1);
	for(i=0;i<=100;i++)
	{
		if(cheio==0)
		{
		if(i==0)ImprimirTabuleiro(Tabuleiro);
		InsereJogada(Tabuleiro,jogador);
		TestarLigados(Tabuleiro);
		ImprimirTabuleiro(Tabuleiro);
		jogador=TrocarJogador( jogador);
		cheio=TabuleiroCheio(Tabuleiro);
		}
	}
	system("pause");
	return 0;
	
}
void ColocarBranco(char Tabuleiro[7][8])
{
	int linha,coluna;
	for(linha=0;linha<=7;linha++)
	{
		for(coluna=0;coluna<=8;coluna++)
		{
			Tabuleiro[linha][coluna]= ' ';
		}
	}
}
int TabuleiroCheio(char Tabuleiro[7][8])
{
	int linha,coluna,x=1;
	for(linha=1;linha<=7;linha++)
	{
		for(coluna=1;coluna<=8;coluna++)
		{
			if(Tabuleiro[linha][coluna]!=' ')
			{
				x++;
			}
		}
	}
	if(x==43)
		{
			printf("\nTabuleiroCheio...\n");
			system("pause");
			return 1;
		}
	if(x!=43)
		{
			return 0;
		}
}
void ImprimirTabuleiro(char Tabuleiro[7][8])
{
	int linha,coluna,x,i;
	printf("\n\n");
	for(linha=1;linha<=7;linha++)
	{
		for(x=1;x<=7;x++)
		{	
		if(x==1)printf("     ");
			printf("+---");
		}
		printf("+\n");
		if(linha==7)
			{
				printf("\n");
				for(i=1;i<=7;i++){
					if(i==1){
						printf("    ");
					}
					printf("   %d",i);
				}
				printf("\n");
				break;
			}
		else{
		for(coluna=1;coluna<=8;coluna++)
		{
			if(coluna==8)printf("|");
			else if(coluna!=8){
				if(coluna==1)printf("  %d  ",linha);
				printf("| ");
				if(Tabuleiro [linha] [coluna] == 'O'){printf ("O ");} //Imprime O//
                else if(Tabuleiro[linha] [coluna] == 'X'){printf ("X ");} //Imprime X//
                else if(Tabuleiro[linha] [coluna] == ' '){printf ("  ");}
				}
		}
	}
	printf("\n");}
}

void TestarLigados(char Tabuleiro[7][8])
{
	int coluna,linha,x=0,y=0;	
//	ligadosX=vet[2];
//	ligadosO=vet[3];
// linha coluna ok
for (coluna=1;coluna<=7;coluna++)//teste vertical
	{
		linha=6;
		while(linha>=1)
		{
				if(Tabuleiro[linha][coluna]=='X')
				{	
					x++;
					y=0;
					if(x==4)
					{
						printf("\n\nX ganhou!!!");
					}
				}
				if(Tabuleiro[linha][coluna]=='O')
				{	
					y++;
					x=0;
					if(y==4)
					{
						printf("\n\nO ganhou!!!");
					}
				}
			linha--;
		}
		y=x=0;
	}
	
for (linha=1;linha<=6;linha++)//teste horizontal
	{
		coluna=7;
		while(coluna>=1)
		{
				if(Tabuleiro[linha][coluna]=='X')
				{	
					x++;
					y=0;
					if(x==4)
					{
						printf("\n\nX ganhou!!!");
	
					}
				}
				if(Tabuleiro[linha][coluna]=='O')
				{	
					y++;
					x=0;
					if(y==4)
					{
						printf("\n\nO ganhou!!!");
					}
				}
			coluna--;
		}
		y=x=0;
	}
	for (linha=6,coluna=1;linha>=1;linha--,coluna++)//teste diagonal primaria1
	{
				if (Tabuleiro[linha][coluna]=='X')
				{	
					x++;
					y=0;
					if(x==4)
					{
						printf("\n\nX ganhou!!!");
					}
				}
				if (Tabuleiro[linha][coluna]=='O')
				{	
					y++;
					x=0;
					if(y==4)
					{
						printf("\n\nO ganhou!!!");
					}
				}
	}
	y=x=0;
		for (linha=6,coluna=2;linha>=1;linha--,coluna++)//teste diagonal primaria2
	{
	//	printf("%d e %d ",linha,coluna);
				if (Tabuleiro[linha][coluna]=='X')
				{	
					x++;
					y=0;
					if(x==4)
					{
						printf("\n\nX ganhou!!!");
					}
				}
				if (Tabuleiro[linha][coluna]=='O')
				{	
					y++;
					x=0;
					if(y==4)
					{
						printf("\n\nO ganhou!!!");
					}
				}
	}
	y=x=0;
	for (linha=6,coluna=3;linha>=2;linha--,coluna++)//teste diagonal secundaria1direita
	{
	//	printf("%d e %d ",linha,coluna);
				if (Tabuleiro[linha][coluna]=='X')
				{	
					x++;
					y=0;
					if(x==4)
					{
						printf("\n\nX ganhou!!!");
					}
				}
				if (Tabuleiro[linha][coluna]=='O')
				{	
					y++;
					x=0;
					if(y==4)
					{
						printf("\n\nO ganhou!!!");
					}
				}
	}
	y=x=0;
		for (linha=5,coluna=1;linha>=1;linha--,coluna++)//teste diagonal secundaria2esquerda
	{
		printf("%d e %d ",linha,coluna);
				if (Tabuleiro[linha][coluna]=='X')
				{	
					x++;
					y=0;
					if(x==4)
					{
						printf("\n\nX ganhou!!!");
					}
				}
				if (Tabuleiro[linha][coluna]=='O')
				{	
					y++;
					x=0;
					if(y==4)
					{
						printf("\n\nO ganhou!!!");
					}
				}
	}
}	

void InsereJogada(char Tabuleiro[7][8],char jogador)
{
	int linha,coluna,f=1;
	printf("\n\nDigite a coluna:");
	scanf("%d",&coluna);
	if(coluna==0 || coluna>7)
	{
		printf("\nColuna Invalida...\n");sleep(3);system("cls"); 	ImprimirTabuleiro(Tabuleiro);InsereJogada(Tabuleiro,jogador);f=0;
	}
	if(f==1)
	for(linha=6;linha>=1;linha--)
	{
		if(Tabuleiro[linha][coluna]==' ')
		{
			Tabuleiro[linha][coluna]=jogador; break;
		}
	}
	system("cls");
}
char TrocarJogador(char jogador)
{
	if (jogador=='X'){
		jogador='O';
	}
	else{
		jogador='X';
	}
	return jogador;
}

