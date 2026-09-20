/*
--------------------------------------------------------------------------------------------------------------------------------
Scrivere un programma in ANSI C che, dato un file di testo che contiene in ogni riga 
una coppia di numeri interi, esegua le seguenti operazioni: 
	1. Carichi in un array i valori reali corrispondenti al rapporto fra i due interi (se il secondo intero è non nullo).
	2. Visualizzi gli elementi dell'array superiori ad un valore fornito da tastiera.
	3. Sostituisca gli eventuali elementi dell'array pari ad 1 o -1  con il valore "0".
	4. Salvi nel file "Uscita.txt" gli elementi dell'array non nulli.
     
Specifiche: 
	- La dimensione dell'array è N pari a 10. 
	- Il nome del file di ingresso deve essere inserito da input. 
	- Il numero di righe (cioè di coppie) nel file non è noto all'inizio. 
	- Eventuali coppie di elementi nel file che soddisfano la condizione in 1, ma che non possono essere caricati nel 
	vettore poichè pieno, non devono essere prese in considerazione.
	      
Esempio di File:
3	2
2	-4
7	0
0	9
8	8
12	-12
5   3
6   -7
9   0
2   1
5   0 
4   6
-------------------------------------------------------------------------------------------------------------------------------
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
		printf("Errore! Il File cercato NON ESISTE");
		return 1;
	}
	
	// --> PUNTO 1 <---
	float a,b;
	float A[MAX_DIM_VETTORE];
	int Dim_Effettiva = 0;
	
	while(Dim_Effettiva<MAX_DIM_VETTORE && fscanf(fp, "%f %f",&a,&b)==2){
		if(b!=0){
			A[Dim_Effettiva] = a / b;
			Dim_Effettiva++;
		}
	}
	
	int i;
	printf("\nIl Vettore ricavato dai valori del File e' il seguente: \n");
	for(i=0; i<Dim_Effettiva; i++){
		printf("%.2f\n",A[i]);
	}
	
	// CHIUSURA FILE
	fclose(fp);
	
	// --> PUNTO 2 <---
	int k;
	printf("\nInserisci un Valore: ");
	scanf("%d",&k);
	
	printf("\nI Valori all'interno del Vettore Superiore a %d sono i seguenti: \n",k);
	for(i=0; i<Dim_Effettiva; i++){
		if(A[i]>k){
			printf("%.2f\n",A[i]);
		}
	}

	// --> PUNTO 3 <---
    for(i=0; i<Dim_Effettiva; i++){
    	if(A[i]==1 || A[i]==-1){
    		A[i] = 0;
		}
	}
	
    printf("\nIl Vettore con 0 sostituito a tutti i valori 1 e -1 e' il seguente: \n");
	for(i=0; i<Dim_Effettiva; i++){
		printf("%.2f\n",A[i]);
	}

	// --> PUNTO 4 <---
	
    printf("\nSono stati caricati tutti i valori NON NULLI in un altro File.");
    
	// APERTURA FILE (Solo Scrittura)
	fp = fopen("Uscita.txt", "w");
	
	for(i=0; i<Dim_Effettiva; i++){
		if(A[i]!=0){
			fprintf(fp, "%.2f\n",A[i]);
		}
	}
	
	// CHIUSURA FILE
	fclose(fp);
	
}

