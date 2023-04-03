#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define tam 25
#define maxpal 100

char pal[tam][tam];
FILE* arq;
char palavra[maxpal][20];
char palavraSort[20];
int resp = 4;

int sorteado;
void sorteia();
void mostra();
bool abreArq();
void pegaPalavra();
void insere();
bool pesquisa();
//---------------------------------------------
int main () {
	
	srand(time(NULL));
	
	while(resp != 0){
	
	system("cls");
	sorteia();
	
	abreArq();
	pegaPalavra();
	insere();
	
	mostra();
	
	resp = 4;
	
	if(pesquisa()){
		printf("A palavra esta na matriz\n");
	}else{
		printf("A palavra nao esta na matriz\n");
	}
	
	printf("Deseja continuar?\n1 = sim\n0 = nao\n");
	scanf("%d", &resp);
	
	}
	  
	system("pause");
	return 0;
}
//---------------------------------------------
void sorteia(){
  char vog[6]="AEIOU";
  char con[22]="BCDFGHJKLMNPQRSTVXWYZ";
  int cont=1;
  for (int x=0; x<tam; x++)
    for (int y=0; y<tam; y++){
      if (cont==1 || cont==3)
      { 
         pal[x][y]=vog[rand()%5];
      }   
      else
      {
         pal[x][y]=con[rand()%21];
      }   
      cont++;
      if (cont>3)
      {
        cont=1;
      }  
    }      
}                                                                                                                                                                                                                                                                                                                    
//---------------------------------------------
void mostra(){
	for (int x=0; x<tam; x++){
	    for (int y=0; y<tam; y++)
	       printf("%c ",pal[x][y]);
	    printf("\n");   
	}   
}
//---------------------------------------------
void pegaPalavra(){
	int qpal = 0;

	arq = fopen("palavras.txt", "r");

	while(fgets(palavra[qpal],20,arq)){
	palavra[qpal][strlen(palavra[qpal])-1]='\0';
	qpal++;
	}
	
	fclose(arq); 	

}
//---------------------------------------------
void insere(){
	int linha;
	int coluna;
	int random = rand()%4;
	
	strcpy(palavraSort,palavra[rand()%maxpal]);
	
	if(random == 0){
	linha = rand()%25;
	coluna = rand()%9;
	
	for(int i = 0; i < strlen(palavraSort); i++){
		pal[linha][coluna + i] = palavraSort[i];
	}	
	}else if(random == 1){
	linha = rand()%9;
	coluna = rand()%25;	
		
	for(int i = 0; i < strlen(palavraSort); i++){
		pal[linha + i][coluna] = palavraSort[i];
	}
	}else if(random == 2){
	linha = 15+rand()%10;
	coluna = rand()%25;	
		
	for(int i = 0; i < strlen(palavraSort); i++){
		pal[linha - i][coluna] = palavraSort[i];
	}
	}else if(random == 3){
	linha = rand()%9;
	coluna = 15+rand()%10;	
		
	for(int i = 0; i < strlen(palavraSort); i++){
		pal[linha][coluna - i] = palavraSort[i];
	}
	}
	
		
	//printf("%s \n",palavraSort);
		
}
//---------------------------------------------
bool abreArq(){
  arq = fopen("palavras.txt", "r"); //leitura
  if (arq == NULL)
  {  // Se houve erro na leitura do arquivo
     printf("Problemas na leitura do arquivo\n");
     system("pause");
     return 0; //não conseguiu abrir o arquivo
  }   
  else
  {
     fclose(arq);
     return 1; //conseguiu abrir o arquivo
  }   
}
//---------------------------------------------
bool pesquisa(){
	int cont = 0;
	char pesq[20];
	
	printf("Digite uma palavra: ");
	scanf("%s", pesq);
	fflush(stdin);
	
	strupr(pesq);
	
	for(int x = 0; x < 25; x++){
		for(int y = 0; y < 25; y++){
			
			if(pesq[cont] == pal[x][y]){
			cont++;
			}else{
			cont = 0;
			}	
					
			if(cont == strlen(pesq)){
			return 1;
			break;
			}
		}
	}
	cont=0;
	
	for(int y = 0; y < 25; y++){
		for(int x = 0; x < 25; x++){
			
			if(pesq[cont] == pal[x][y]){
			cont++;
			}else{
			cont = 0;
			}	
					
			if(cont == strlen(pesq)){
			return 1;
			break;
			}
		}
	}
	cont=0;
	
	for(int y = 25; y >= 0; y--){
		for(int x = 25; x >= 0; x--){
			
			if(pesq[cont] == pal[x][y]){
			cont++;
			}else{
			cont = 0;
			}	
					
			if(cont == strlen(pesq)){
			return 1;
			break;
			}
		}
	}
	cont=0;
	
	for(int x = 25; x >= 0; x--){
		for(int y = 25; y >= 0; y--){
			
			if(pesq[cont] == pal[x][y]){
			cont++;
			}else{
			cont = 0;
			}	
					
			if(cont == strlen(pesq)){
			return 1;
			break;
			}
		}
	}
	cont=0;
	
	return 0;
}
