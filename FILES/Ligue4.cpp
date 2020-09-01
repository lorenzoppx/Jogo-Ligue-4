#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<ctype.h>

void ImprimirTabuleiro(char Tabuleiro[7][8]);
int TestarLigados(char Tabuleiro[7][8],int Placar[3]);
int InsereJogada(char Tabuleiro[7][8],char jogador,int Placar[3]);
char TrocarJogador(char jogador);
int TabuleiroCheio(char Tabuleiro[7][8],int Placar[3]);
void ColocarBranco(char Tabuleiro[7][8]);
int Ganhador(int x,int y);
void Animacao(int aquele);
int MenuFinal();
int MenuInicial();
void ImprimirPlacar(int Placar[3]);
int SinglePlayer(char Tabuleiro[7][8],int opcao,int Placar[3]);
int menu(int Placar[3]);

int main ()
{
	int Placar[3];
	Placar[2]=Placar[1]=Placar[0]=0;
	menu(Placar);
	system("pause");
	return 0;
}

int menu(int Placar[3])
{
	char Tabuleiro[7][8];
	int cheio=0,i=0,ligados=0,pode=0,opcao=0;
	char jogador='O';
	ColocarBranco(Tabuleiro);
	Animacao(420);
	opcao=MenuInicial();
	printf("%c%c",1,3);
	Animacao(2);//animaçao inicial
	ImprimirPlacar(Placar);
	ImprimirTabuleiro(Tabuleiro);
		for(i=0;i<=100;i++)
		{
			if(cheio==0 && ligados==0)
			{
				pode=InsereJogada(Tabuleiro,jogador,Placar);
				if(pode==1 && opcao==0){jogador=TrocarJogador(jogador);}
				else SinglePlayer(Tabuleiro,opcao,Placar);
				cheio=TabuleiroCheio(Tabuleiro,Placar);
				ligados=TestarLigados(Tabuleiro,Placar);			
				ImprimirPlacar(Placar);
				ImprimirTabuleiro(Tabuleiro);
			}
		}
	if(MenuFinal()==1)
    {system("cls");menu(Placar);}	  
	printf("cheio: %d",cheio);
	printf("ligados: %d",ligados);
	system("pause");
	return 0;
	
}

void ColocarBranco(char Tabuleiro[7][8])//Para não deixar nenhum das matrizes sem valor
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
int TabuleiroCheio(char Tabuleiro[7][8],int Placar[3])//Verifica se Tabuleiro Está cheio contando os espaços vazios
{
	int linha,coluna,x=1,aquele;
	for(linha=1;linha<=6;linha++)
		{
			for(coluna=1;coluna<=7;coluna++)
			{
				if(Tabuleiro[linha][coluna]!=' ')
				{
					x++;
				}
			}
		}
	if(x==43)
		{
			Animacao(0);
			printf("\nTabuleiroCheio...\n");
			Placar[3]++;
			system("pause");
			return 1;
		}
	return 0;

}
void ImprimirPlacar(int Placar[3])
{	

	printf("\nVitorias  %c:%d",1,Placar[1]);
	printf("\nVitorias  %c:%d",3,Placar[0]);
	printf("\nEmpates  %c%c:%d",1,3,Placar[3]);
}
void ImprimirTabuleiro(char Tabuleiro[7][8])
{
	int linha,coluna,x,i;
	printf("\n\n");
	for(linha=1;linha<=7;linha++)
	{
		for(x=1;x<=7;x++)
			{	
				if(x==1){printf("     ");}
				printf("+---");
			}
		printf("+\n");
		if(linha==7)
			{
				printf("\n");
				for(i=1;i<=7;i++)
				{
					if(i==1){printf("    ");}
					printf("   %d",i);
				}
				printf("\n");
				break;
			}
		else
		{
			for(coluna=1;coluna<=8;coluna++)
			{
				if(coluna==8)printf("|");
				else if(coluna!=8)
				{
					if(coluna==1){printf("  %d  ",linha);}
					printf("| ");
					if(Tabuleiro[linha] [coluna] == 'X'){printf ("%c ",3);} //Imprime X//
					else if(Tabuleiro [linha] [coluna] == 'O'){printf ("%c ",1);} //Imprime O//
					else if(Tabuleiro[linha] [coluna] == ' '){printf ("  ");}
				}
			}
		}
		printf("\n");
	}
}
int SinglePlayer (char Tabuleiro[7][8],int opcao,int Placar[3])
{
	int x=0,y=0,coluna,linha,espaco=1,linha1,pimba=1,slk=1,tey;
		for (coluna=1;coluna<=7;coluna++)//teste vertical
		{
			for(linha=6;linha>=1;linha--)
			{		
				if(Tabuleiro[linha][coluna]==' '){y=x=0;}
				if(Tabuleiro[linha][coluna]=='X')
					{	
						x++;
						y=0;
					}
					if(Tabuleiro[linha][coluna]=='O')
					{	
						y++;
						x=0;
						if (y==3 && opcao==1 && Tabuleiro [linha-1][coluna]== ' ')
						{
								espaco=1;
							for(tey=6;tey>=1;tey--)
							{
								if (Tabuleiro[7-tey][coluna]==' ')
								{
									Tabuleiro[7-tey][coluna]='X';
									ImprimirPlacar(Placar);
								   	ImprimirTabuleiro(Tabuleiro); 
									Tabuleiro[7-tey][coluna]=' ';
									Sleep(85);
									system("cls");
								}
							}
					
							for (linha1=6;linha1>=1;linha1--)
							{
								if (Tabuleiro[linha1-1][coluna]!=' '){espaco++;}
								if(espaco==7){return 0;}
								else if(Tabuleiro[linha1-1][coluna]==' '){Tabuleiro[linha1-1][coluna]='X';pimba=0;break;}
							}
						}
					}
			}
			y=x=0;
		}
	for (linha=1;linha<=7;linha++)//teste horizontal
	{
		for(coluna=7;coluna>=1;coluna--)
		{
			if(Tabuleiro[linha][coluna]==' '){y=x=0;}
			if(Tabuleiro[linha][coluna]=='X')
				{	
					x++;
		       		y=0;
				}
					
			if(Tabuleiro[linha][coluna]=='O')
			{	
				y++;
				x=0;
				if(pimba==1)
				{
					if (y==3 && opcao==1 && Tabuleiro [linha][coluna+3]==' ')
					{
						espaco=1;
						for(tey=6;tey>=1;tey--)
						{
							if (Tabuleiro[7-tey][coluna+3]==' ')
							{
								Tabuleiro[7-tey][coluna+3]='X';
								ImprimirPlacar(Placar);
							   	ImprimirTabuleiro(Tabuleiro); 
								Tabuleiro[7-tey][coluna+3]=' ';
								Sleep(85);
								system("cls");
							}
						}
				
						for (linha1=6;linha1>=1;linha1--)
						{
							if (Tabuleiro[linha1][coluna+3]!=' '){espaco++;}
							if(espaco==7){return 0;}
							else if(Tabuleiro[linha1][coluna+3]==' '){Tabuleiro[linha1][coluna+3]='X';pimba=0;break;}
						}
					}
					else if (y==3 && opcao==1 && Tabuleiro [linha][coluna-1]==' ')
					{
						espaco=1;
						for(tey=6;tey>=1;tey--)
							{
							if (Tabuleiro[7-tey][coluna]==' ')
								{
										Tabuleiro[7-tey][coluna-1]='X';
										ImprimirPlacar(Placar);
										ImprimirTabuleiro(Tabuleiro); 
										Tabuleiro[7-tey][coluna-1]=' ';
										Sleep(85);
										system("cls");
								}
							}
						for (linha1=6;linha1>=1;linha1--)
						{
							if (Tabuleiro[linha1][coluna-1]!=' '){espaco++;}
							if(espaco==7){return 0;}
							else if(Tabuleiro[linha1][coluna-1]==' '){Tabuleiro[linha1][coluna-1]='X';pimba=0;break;}
						}
					}
				}
			}
		}
		y=x=0;		
	}
	if (pimba==1 && opcao==1)
	{
		espaco=1;
		for(linha=1;linha<=6;linha++)
		{
			for(coluna=1;coluna<=7;coluna++)
			{
				if(slk==1)
				{
					if(Tabuleiro[linha][coluna]==' ')
					{							
						for(tey=6;tey>=1;tey--)
						{
							if (Tabuleiro[7-tey][coluna]==' ')
							{
									Tabuleiro[7-tey][coluna]='X';
									ImprimirPlacar(Placar);
						    		ImprimirTabuleiro(Tabuleiro); 
									Tabuleiro[7-tey][coluna]=' ';
									Sleep(85);
									system("cls");
							}
						}
						for (linha1=6;linha1>=1;linha1--)
						{

							if (Tabuleiro[linha1][coluna]!=' '){espaco++;}
							if(espaco==7){return 0;}
							else if(Tabuleiro[linha1][coluna]==' '){Tabuleiro[linha1][coluna]='X';slk=0;break;}
						}
					}
				}
			}
		}
	}		
	return 0;
}
	
int TestarLigados(char Tabuleiro[7][8],int Placar[3])
{
	int coluna,linha,x=0,y=0,a=0,meioesquerda=1,meiodireita=1,coluna1=0,linha1=0;	
////	ligadosX=x;
//	ligadosO=o;
for (coluna=1;coluna<=7;coluna++)//teste vertical
	{
		for(linha=6;linha>=1;linha--)
		{		
			if(Tabuleiro[linha][coluna]==' '){y=x=0;}
			if(Tabuleiro[linha][coluna]=='X')
				{	
					x++;
					y=0;
			if(Ganhador(x,y)==1){Placar[0]++;return 1;}
				}
				if(Tabuleiro[linha][coluna]=='O')
				{	
					y++;
					x=0;
			if(Ganhador(x,y)==1){Placar[1]++;return 1;}
				}
		}
		y=x=0;
	}
	
for (linha=1;linha<=6;linha++)//teste horizontal
	{
		for(coluna=7;coluna>=1;coluna--)
		{
			if(Tabuleiro[linha][coluna]==' '){y=x=0;}
			if(Tabuleiro[linha][coluna]=='X')
				{	
					x++;
					y=0;
			if(Ganhador(x,y)==1){Placar[0]++;return 1;}
				}
				
				if(Tabuleiro[linha][coluna]=='O')
				{	
					y++;
					x=0;
					if(Ganhador(x,y)==1){Placar[1]++;return 1;}
						//if (y==3 && opcao==1){Tabuleiro [linha][coluna-1]= 'X';}//
						//if (y==3 && opcao==1){Tabuleiro [linha][coluna+3]= 'X';}//
				}
		}
		y=x=0;
	}
	
for (linha=6,coluna=1;linha>=1;linha--,coluna++)//teste diagonal primaria1(direita p/ esquerda)
	{
		if(Tabuleiro[linha][coluna]==' '){y=x=0;}
			if (Tabuleiro[linha][coluna]=='X')
				{	
					x++;
					y=0;
			if(Ganhador(x,y)==1){Placar[0]++;return 1;}
				}
			if (Tabuleiro[linha][coluna]=='O')
				{	
					y++;
					x=0;
			if(Ganhador(x,y)==1){Placar[1]++;return 1;}
				}
	}
	y=x=0;
		for (linha=6,coluna=2;linha>=1;linha--,coluna++)//teste diagonal primaria2(direita p/ esquerda)
	{
	//	printf("%d e %d ",linha,coluna);
	if(Tabuleiro[linha][coluna]==' '){y=x=0;}
			if (Tabuleiro[linha][coluna]=='X')
				{	
					x++;
					y=0;
			if(Ganhador(x,y)==1){Placar[0]++;return 1;}
				}
				if (Tabuleiro[linha][coluna]=='O')
				{	
					y++;
					x=0;
			if(Ganhador(x,y)==1){Placar[1]++;return 1;}
				}
	}
	y=x=0;
	for (linha=6,coluna=3;linha>=2;linha--,coluna++)//teste diagonal secundaria1direita(direita p/ esquerda)
	{
	//	printf("%d e %d ",linha,coluna);
	if(Tabuleiro[linha][coluna]==' '){y=x=0;}
			if (Tabuleiro[linha][coluna]=='X')
				{	
					x++;
					y=0;
			if(Ganhador(x,y)==1){Placar[0]++;return 1;}
				}
				if (Tabuleiro[linha][coluna]=='O')
				{	
					y++;
					x=0;
			if(Ganhador(x,y)==1){Placar[1]++;return 1;}
				}
	}
	y=x=0;
		for (linha=5,coluna=1;linha>=1;linha--,coluna++)//teste diagonal secundaria2esquerda(direita p/ esquerda)
	{
	//	printf("%d e %d ",linha,coluna);
	if(Tabuleiro[linha][coluna]==' '){y=x=0;}
				if (Tabuleiro[linha][coluna]=='X')
				{	
					x++;
					y=0;
			if(Ganhador(x,y)==1){Placar[0]++;return 1;}
				}
				if (Tabuleiro[linha][coluna]=='O')
				{	
					y++;
					x=0;
			if(Ganhador(x,y)==1){Placar[1]++;return 1;}
				}
	}
	y=x=0;
	for (linha=6,coluna=6;linha>=1;linha--,coluna--)//teste diagonal primaria1(esquerda p/ direita)
	{
	//	printf("%d e %d ",linha,coluna);
	if(Tabuleiro[linha][coluna]==' '){y=x=0;}
				if (Tabuleiro[linha][coluna]=='X')
				{	
					x++;
					y=0;
			if(Ganhador(x,y)==1){Placar[0]++;return 1;}
				}
				if (Tabuleiro[linha][coluna]=='O')
				{	
					y++;
					x=0;
			if(Ganhador(x,y)==1){Placar[1]++;return 1;}
				}
	}
	y=x=0;
		for (linha=6,coluna=7;linha>=1;linha--,coluna--)//teste diagonal primaria2(esquerda p/ direita)
	{
	//	printf("%d e %d ",linha,coluna);
	if(Tabuleiro[linha][coluna]==' '){y=x=0;}
				if (Tabuleiro[linha][coluna]=='X')
				{	
					x++;
					y=0;
			if(Ganhador(x,y)==1){Placar[0]++;return 1;}
				}
				if (Tabuleiro[linha][coluna]=='O')
				{	
					y++;
					x=0;
			if(Ganhador(x,y)==1){Placar[1]++;return 1;}
				}
	}
	y=x=0;
	for (linha=6,coluna=5;linha>=2;linha--,coluna--)//teste diagonal secundaria1direita(esquerda p/ direita)
	{
	//	printf("%d e %d ",linha,coluna);
	if(Tabuleiro[linha][coluna]==' '){y=x=0;}
				if (Tabuleiro[linha][coluna]=='X')
				{	
					x++;
					y=0;
			if(Ganhador(x,y)==1){Placar[0]++;return 1;}
				}
				if (Tabuleiro[linha][coluna]=='O')
				{	
					y++;
					x=0;
			if(Ganhador(x,y)==1){Placar[1]++;return 1;}
				}
	}
	y=x=0;
		for (linha=5,coluna=7;linha>=1;linha--,coluna--)//teste diagonal secundaria2esquerda(esquerda p/ direita)
	{
	//	printf("%d e %d ",linha,coluna);
	if(Tabuleiro[linha][coluna]==' '){y=x=0;}
				if (Tabuleiro[linha][coluna]=='X')
				{	
					x++;
					y=0;
			if(Ganhador(x,y)==1){Placar[0]++;return 1;}
				}
				if (Tabuleiro[linha][coluna]=='O')
				{	
					y++;
					x=0;
			if(Ganhador(x,y)==1){Placar[1]++;return 1;}
				}
	}
	for (linha=6,coluna=4;linha>=3;linha--,coluna--)//teste diagonal terciaria2esquerda(direita p/ esquerda )
	{
		//printf("%d e %d ",linha,coluna);
	if(Tabuleiro[linha][coluna]==' '){y=x=0;}
				if (Tabuleiro[linha][coluna]=='X')
				{	
					x++;
					y=0;
			if(Ganhador(x,y)==1){Placar[0]++;return 1;}
				}
				if (Tabuleiro[linha][coluna]=='O')
				{	
					y++;
					x=0;
			if(Ganhador(x,y)==1){Placar[1]++;return 1;}
				}
	}
	for (linha=4,coluna=7;linha>=1;linha--,coluna--)//teste diagonal terciaria3direita(direita p/ esquerda )
	{
	//	printf("%d e %d ",linha,coluna);
	if(Tabuleiro[linha][coluna]==' '){y=x=0;}
				if (Tabuleiro[linha][coluna]=='X')
				{	
					x++;
					y=0;
			if(Ganhador(x,y)==1){Placar[0]++;return 1;}
				}
				if (Tabuleiro[linha][coluna]=='O')
				{	
					y++;
					x=0;
			if(Ganhador(x,y)==1){Placar[1]++;return 1;}
				}
	}
	for (linha=4,coluna=1;linha>=1;linha--,coluna++)//teste diagonal terciaria2esquerda(esquerda p/ direita )
	{
		//printf("%d e %d ",linha,coluna);
	if(Tabuleiro[linha][coluna]==' '){y=x=0;}
				if (Tabuleiro[linha][coluna]=='X')
				{	
					x++;
					y=0;
			if(Ganhador(x,y)==1){Placar[0]++;return 1;}
				}
				if (Tabuleiro[linha][coluna]=='O')
				{	
					y++;
					x=0;
			if(Ganhador(x,y)==1){Placar[1]++;return 1;}
				}
	}
		for (linha=6,coluna=4;linha>=3;linha--,coluna++)//teste diagonal terciaria2direita(esquerda p/ direita )
	{
		//printf("%d e %d ",linha,coluna);
	if(Tabuleiro[linha][coluna]==' '){y=x=0;}
				if (Tabuleiro[linha][coluna]=='X')
				{	
					x++;
					y=0;
			if(Ganhador(x,y)==1){Placar[0]++;return 1;}
				}
				if (Tabuleiro[linha][coluna]=='O')
				{	
					y++;
					x=0;
			if(Ganhador(x,y)==1){Placar[1]++;return 1;}
				}
	}
	
return 0;
}	
	

int InsereJogada(char Tabuleiro[7][8],char jogador,int Placar[3])
{
	int linha,f=1,coluna,tey,espaco=1;
	printf("\n\nDigite a coluna:");
	scanf("%d",&coluna);
	if(coluna==0 || coluna>7)
	{
		printf("\nColuna Invalida...\n");Sleep(1000);system("cls");ImprimirPlacar(Placar);ImprimirTabuleiro(Tabuleiro);InsereJogada(Tabuleiro,jogador,Placar);
	}
		system("cls");
		for(tey=6;tey>=1;tey--)
		{
		if (Tabuleiro[7-tey][coluna]==' ')
			{
					Tabuleiro[7-tey][coluna]=jogador;
					ImprimirPlacar(Placar);
					ImprimirTabuleiro(Tabuleiro); 
					Tabuleiro[7-tey][coluna]=' ';
					Sleep(85);
					system("cls");
			}
		}
		for (linha=6;linha>=1;linha--)
		{
		if (Tabuleiro[linha][coluna]!=' ')
			{
				espaco++;
			}
		if(espaco==7){printf("\nColuna Completa...\n");Sleep(2000);	ImprimirPlacar(Placar);ImprimirTabuleiro(Tabuleiro);InsereJogada(Tabuleiro,jogador,Placar);}
		else if(Tabuleiro[linha][coluna]==' '){Tabuleiro[linha][coluna]=jogador;break;}
		}
	system("cls");
	return 1;
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

int Ganhador(int x,int y)
{
	int aquele;
	 if(x==4)
	 {
	 	aquele=3;
	 	Animacao(aquele);
	 	return 1;
	 }
	else if(y==4)
	 {
	 	aquele=1;
	 	Animacao(aquele);
	 	return 1;
	 }
	 else  {return 0;}
	 
}
void Animacao(int aquele)
{	
char Tabuleiro[7][8];
int animacao,animacao2,a,linha,coluna;
	if(aquele==1 || aquele==3)
	{
          for(animacao=0;animacao<9;animacao++)//faz as ações abaixo se repetirem seguidamente
            {
              for(animacao2=0;animacao2<5;animacao2++)//boneco pulando e subindo
              {
                system("cls");
                printf("\n                      Parabens!! %c Venceu!! Eh tetra !!\n\n",aquele);
                printf("_._._._._._._._._._.   \n|                  |   \n|             ____.|.____\n|            |           |\n|            |  ~ EVF ~  |\n|            |___________|\n|\n|         O \n|        /|\\\n|        / \\\n|\n|_._._._._._._._._._._._._._._._._._._._._._._._\n\n"); 
				system("color 07");
              }
              for(animacao2=0;animacao2<5;animacao2++)//boneco pulando e subindo
              {system("cls");
                printf("\n                  Parabens!! %c Venceu!! Eh tetra !!\n\n",aquele);
           		printf("_._._._._._._._._._.   \n|                  |   \n|             ____.|.____\n|            |           |\n|            |  - EVF -  |\n|            |___________|\n|\n|        \\O/\n|         |\n|        / \\\n|\n|_._._._._._._._._._._._._._._._._._._._._._._._\n\n"); 
				system("color 07");
			  }
              for(animacao2=0;animacao2<5;animacao2++)//boneco pulando e subindo
              {
                system("cls");system("color 50");
                printf("\n                        Parabens!! %c Venceu!! Eh tetra !!\n \n",aquele);
                printf("_._._._._._._._._._.   \n|                  |   \n|             ____.|.____\n|            |           |\n|            |  + EVF +  |\n|            |___________|\n|\n|\n|        _O_\n|         |\n|        / \\\n|_._._._._._._._._._._._._._._._._._._._._._._._\n\n"); 
				system("color 07");        
              }
            }
          system("cls");system("color 07"); 
          printf("\n                     Parabens!! %c Venceu!! Eh tetra !!\n\n",aquele);
          printf("_._._._._._._._._._.   \n|                  |   \n|             ____.|.____\n|            |           |\n|            |    EVF    |\n|            |___________|\n|\n|\n|        \\O/\n|         |\n|        / \\\n|_._._._._._._._._._._._._._._._._._._._._._._._\n\n");
          Sleep(2000);system("cls");
	}
	if(aquele==2)
	{
		system("color 05");
		printf("\n\n\n\n\n\n\n\n\n\n\n    ");
		for (a=0;a<6;a++)
		{printf("~~~~");}Sleep(1000);
		printf("O jogo sera iniciado...");Sleep(1000);
    	for (a=0;a<6;a++)
    	{printf("~~~~"); } 	printf("\n\n"); system("cls");Sleep(1000);
    	system("color 07"); 
	}
	if(aquele==0)
	{
		system("cls");
		printf("Infelizmente nem %c nem %c ganhou!!!! \n",1,3);
  	  printf("_._._._._._._._._._.   \n|                  |   \n|             ____.|.____\n|            |           |\n|            |  ~ EVF ~  |\n|            |___________|\n|\n|\n|         O \n|        /|\\\n|        / \\\n|_._._._._._._._._._._._._._._._._._._._._._._._\n\n"); system("color 07");
	}
	if(aquele==420)
	{
		system("color 07"); 
        printf("\n                               Seje Bem Vindo!!\n\n",aquele);
        printf("_._._._._._._._._._.   \n|                  |   \n|             ____.|.____\n|            |           |\n|            | ^ lig-4 ^ |     LaMAFIAPRODUCOES(evf) CTAII-1M/2016\n|            |___________|\n|\n|\n|        \\%c/\n|         |\n|        / \\\n|_._._._._._._._._._._._._._._._._._._._._._._._\n\n",2);
        Sleep(2000);
	}
}
int MenuFinal()
{
	int opcao;
	Sleep(1000);printf("\nDeseja jogar novamente (S)sim e (N)nao:\n");fflush(stdin);opcao=toupper(getchar());
    if(opcao=='S'){ return 1;}
    if(opcao=='N'){ system("cls");printf("\nAte a proxima... %c%c\n",1,3);Sleep(2000);return 0;}
    if(opcao!='N' && opcao!='S'){system("cls");printf("\nOpcao Invalida...\n");Sleep(2000);MenuFinal();}
	return 1;
}
int MenuInicial()
{
	int opcao;
	system("color 05");
	Sleep(1000);printf("\nDeseja jogar Versus (C)computador ou (M)multiplayer:\n");fflush(stdin);opcao=toupper(getchar());
    if(opcao=='C'){ system("cls");system("color 07");printf("\nVoce e' o jogador %c...\n",1);Sleep(4000);system("cls");return 1;}
    if(opcao=='M'){ system("cls");system("color 07");printf("\n O primeiro jogador e' %c...\n O segundo jogador e' %c...\n",1,3);Sleep(4000);system("cls");return 0;}
    if(opcao!='C' && opcao!='M'){system("cls");printf("\nOpcao Invalida...\n");Sleep(2000);MenuInicial();}
	return 1;
}

