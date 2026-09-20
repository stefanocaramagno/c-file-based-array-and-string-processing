/*
----------------------------------------------------------------------------------------------------------------------------------------------
Scrivere un programma in ANSI C che, dato un file di testo che contiene in ogni riga una coppia di numeri interi, esegua le seguenti operazioni: 
	1. Carichi in un array la somma dei valori presenti in ogni riga se è positiva 
	2. Visualizzi gli elementi dell’array il cui valore è multiplo di 5. 
	3. Calcoli la media degli elementi di valore dispari dell’array. 
	4. Salvi nel file “uscita.txt” gli elementi dell’array maggiori di 10.
      
Specifiche
	- La dimensione dell’array è N pari a 10 
	- Il nome del file di ingresso deve essere inserito da input. 
	- Il numero di righe (cioè di coppie) nel file non è noto all’inizio. 
	- Eventuali coppie di elementi nel file oltre la riga N-esima (cioè oltre la decima riga) non devono essere prese in considerazione 

Esempio di File:
10   -5 
-20   45 
-10   3 
7     14 
----------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>

#define MAX_DIM_NOME_FILE 20 
#define MAX_DIM_VETTORE 10

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
	float a,b;
	int Dim_Effettiva = 0;
	int A[MAX_DIM_VETTORE];

	while(Dim_Effettiva<MAX_DIM_VETTORE && fscanf(fp,"%f %f",&a,&b) == 2){
		if((a+b)>0){
			A[Dim_Effettiva] = a + b;
			Dim_Effettiva++;
		}
	}
	
	int i;
	printf("\nIl Vettore ricavato dai valori del File e' il seguente: \n");
	for(i=0; i<Dim_Effettiva; i++){
			printf("%d\n",A[i]);
	}
	
 	// CHIUSURA FILE
 	fclose(fp);
 	
 	// --> PUNTO 2 <--		
 	printf("\nI Valori del Vettore MULTIPLI DI 5 sono: \n");
 	for(i=0; i<Dim_Effettiva; i++){
 		if(A[i]%5==0){
 			printf("%d\n",A[i]);
		 }
 		
	 }
	 
 	// --> PUNTO 3 <--	 
 	int Somma_Dispari = 0;
 	int Contatore_Dispari = 0;
 	for(i=0; i<Dim_Effettiva; i++){
 		if(A[i]%2!=0){
 			Somma_Dispari = Somma_Dispari + A[i];
 			Contatore_Dispari++;
 		}
	}
	
	float Media_Dispari = (float)Somma_Dispari / (float)Contatore_Dispari;
	printf("\nLa MEDIA dei VALORI DISPARI del Vettore e': %.2f",Media_Dispari);
	
	// --> PUNTO 4 <--	 
	
	// APERTURA FILE (Solo Scrittura)
	fp = fopen("Uscita.txt","w");
	
	printf("\n\nSono stati caricati tutti i valori MAGGIORI DI 10 in un altro File.");
	
	for(i=0; i<Dim_Effettiva; i++){
		if(A[i]>10){
			fprintf(fp,"%d\n",A[i]);
		}
	}
	
	// CHIUSURA FILE
 	fclose(fp);
}

