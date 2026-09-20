/*
----------------------------------------------------------------------------------------------------------------------------------------------
Scrivere un programma in ANSI C che, dato un file di testo che contiene in ogni riga una coppia di numeri reali, 
esegua le seguenti operazioni:
	1. Carichi in un array i numeri reali corrispondenti al maggiore della coppia;
	2. Visualizzi gli elementi dell’array il cui valore è compreso tra a e a+5, dove “a” è inserito dall’utente
	3. Calcoli il quadrato della somma degli elementi dell’array;
	4. Salvi nel file “uscita.txt” gli elementi dell’array il cui valore è inferiore ad “a+1”.
	
Specifiche:
	- La dimensione dell’array è N pari a 7.
	- Il nome del file di ingresso deve essere inserito da input.
	- Il numero di righe (cioè di coppie) nel file non è noto all’inizio. 
	- Eventuali coppie di elementi nel file oltre la riga N-esima (cioè oltre la settima riga) non devono essere prese in considerazione.

Esempio di File:
3.7 1.5
2.1 8.67
9.5 2.6
4.7 6.1 
2.7 7.45
9.5 1.6
3.1 2.4
0.4 4.2
5.9 6.3
1.2 6.7
9.5 3.8
----------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>

#define MAX_DIM_NOME_FILE 20
#define MAX_DIM_VETTORE 7
int main(void){
	
	FILE *fp;
	
	// SI INSERISCE IL NOME DEL FILE DA APRIRE
	char nomefile[MAX_DIM_NOME_FILE];
	printf("Inserisci il Nome del File da aprire: ");
	scanf("%s",nomefile);
	
	// APERTURA FILE (Solo Lettura)
	fp = fopen(nomefile,"r");
	
	// SE IL FILE DA APRIRE NON ESISTE SI ESCE DAL PROGRAMMA, DANDO UN CODICE DI ERRORE = 1
	if(fp == NULL){
		printf("Errore! Il FILE cercato NON ESISTE");
		return 1;
	}
	
	// --> PUNTO 1 <--
	int Dim_Effettiva = 0;
	float A[MAX_DIM_VETTORE];
	float a,b;
	
	while(Dim_Effettiva<MAX_DIM_VETTORE && fscanf(fp,"%f %f",&a,&b) == 2){
		if(a>b){
			A[Dim_Effettiva] = a;
		}else{
			A[Dim_Effettiva] = b;
		}
		Dim_Effettiva++;
	}
	
	int i;
	printf("\nIl Vettore ricavato dai valori del File e' il seguente: \n");
	for(i=0; i<Dim_Effettiva; i++){
		printf("%.2f\n",A[i]);
	}
	
	// CHIUSURA FILE
	fclose(fp);
	
	// --> PUNTO 2 <--
	int c;
	printf("\nInserisci un Valore: ");
	scanf("%d",&c);
	
	printf("\nI Valori compresi tra %d e %d sono i seguenti: \n",c,c+5);
	for(i=0; i<Dim_Effettiva; i++){
		if(A[i]<(c+5) && A[i]>c){
			printf("%.2f\n",A[i]);
		}
	}
	
	// --> PUNTO 3 <--	
	float Somma = 0;

	for(i=0; i<Dim_Effettiva; i++){
		Somma = Somma + A[i];
	}
	printf("\nLa SOMMA di tutti gli elementi del Vettore e': %.2f",Somma);
	
	float Somma_al_Quadrato = Somma*Somma;
	
	printf("\nIl QUADRATO DELLA SOMMA di tutti gli elementi del Vettore e': %.2f",Somma_al_Quadrato);	
	
	// --> PUNTO 4 <--		
	
	// APERTURA FILE (Solo Scrittura)
	fp = fopen("Uscita.txt","w");
	
    printf("\n\nSono stati caricati tutti i valori MINORI DI c+1 in un altro File.");
    
	for(i=0; i<Dim_Effettiva; i++){
		if(A[i]<(c+1)){
			fprintf(fp,"%.2f\n",A[i]);
		}
	}
}

