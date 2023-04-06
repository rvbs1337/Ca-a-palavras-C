#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.c>
#define tam 25
#define maxpal 100

char pal[tam][tam];
char palCol[tam][tam];
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
void color();
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
		system("cls");
		
		color();
		printf("A palavra esta na matriz\n");
	}else{
		system("cls");
		
		color();
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
         pal[x][y]=vog[rand()%5];			//sortea uma vogal toda vez q cont for 1 ou 3
      }   
      else
      {
         pal[x][y]=con[rand()%21]; 			//sortea uma consoante toda vez q cont for 2
      }   
      cont++;
      if (cont>3)
      {	
        cont=1;			//se cont for maior doq 3 reseta pra 1
      }  
    }      
}                                                                                                                                                                                                                                                                                                                    
//---------------------------------------------
void mostra(){
	for (int x=0; x<tam; x++){
	    for (int y=0; y<tam; y++){
		
	       printf("%c ",pal[x][y]);			//escreve a matriz das letras
		}
	    printf("\n");   
	}   
}
//---------------------------------------------
void pegaPalavra(){
	int qpal = 0;

	arq = fopen("palavras.txt", "r");

	while(fgets(palavra[qpal],20,arq)){	//enquanto houver palavras ele vai rodar esse loop
	palavra[qpal][strlen(palavra[qpal])-1]='\0'; //retira o \n do final 
	qpal++;
	}
	
	fclose(arq); 	

}
//---------------------------------------------
void insere(){
    int linha, coluna, random;
    random = rand() % 4;
    strcpy(palavraSort, palavra[rand() % maxpal]);
    
    switch (random) {
        case 0:
            // Insere esquerda -> direita
            linha = rand() % 25;
            coluna = rand() % 9;
            for (int i = 0; i < strlen(palavraSort); i++) {
                pal[linha][coluna + i] = palavraSort[i];
                palCol[linha][coluna + i] = palavraSort[i];
            }
            break;
        case 1:
            // Insere baixo <- cima
            linha = rand() % 9;
            coluna = rand() % 25;
            for (int i = 0; i < strlen(palavraSort); i++) {
                pal[linha + i][coluna] = palavraSort[i];
                palCol[linha + i][coluna] = palavraSort[i];
            }
            break;
        case 2:
            // Insere baixo -> cima
            linha = 15 + rand() % 10;
            coluna = rand() % 25;
            for (int i = 0; i < strlen(palavraSort); i++) {
                pal[linha - i][coluna] = palavraSort[i];
                palCol[linha - i][coluna] = palavraSort[i];
            }
            break;
        case 3:
            // Insere esquerda <- direita
            linha = rand() % 25;
            coluna = 15 + rand() % 10;
            for (int i = 0; i < strlen(palavraSort); i++) {
                pal[linha][coluna - i] = palavraSort[i];
                palCol[linha][coluna - i] = palavraSort[i];
            }
            break;
    }
    printf("%s\n", palavraSort);
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
	scanf("%s", pesq);				//recebe uma palavra do usuario
	fflush(stdin);
	
	strupr(pesq);
	
	for(int x = 0; x < 25; x++){
		for(int y = 0; y < 25; y++){ //procura palavra da esquerda -> direita
			
			if(pesq[cont] == pal[x][y]){
			cont++;							//roda verificando cada letra da palavra
			}else{
			cont = 0;		//se não tiver a letra reseta o contador
			}	
					
			if(cont == strlen(pesq)){
			return 1;		// se a quantidade de letras encontradas satisfazer
			}
		}
	}
	cont=0;
	
	for(int y = 0; y < 25; y++){
		for(int x = 0; x < 25; x++){  //procura palavra de cima -> baixo
			
			if(pesq[cont] == pal[x][y]){
			cont++;
			}else{
			cont = 0;
			}	
					
			if(cont == strlen(pesq)){
			return 1;
			}
		}
	}
	cont=0;
	
	for(int y = 25; y >= 0; y--){
		for(int x = 25; x >= 0; x--){  //procura palavra de baixo -> cima
			
			if(pesq[cont] == pal[x][y]){
			cont++;
			}else{
			cont = 0;
			}	
					
			if(cont == strlen(pesq)){
			return 1;
			}
		}
	}
	cont=0;
	
	for(int x = 25; x >= 0; x--){
		for(int y = 25; y >= 0; y--){  //procura palavra da direita -> esquerda
			
			if(pesq[cont] == pal[x][y]){
			cont++;
			}else{
			cont = 0;
			}	
					
			if(cont == strlen(pesq)){
			return 1;
			}
		}
	}
	cont=0;
	
	return 0;
}
void color(){
	for(int x = 0; x < 25; x++){
		for(int y = 0; y < 25; y++){
			if(palCol[x][y] == pal[x][y]){
				textcolor(2);
				printf("%c ", palCol[x][y]);
			}else{
				textcolor(15);
				printf("%c ", pal[x][y]);
			}
		}
		printf("\n");
	}
}


