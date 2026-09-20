/*
------------------------------------------------------------------------------------------------------------------------------
Scrivere un programma in ANSI C che, dato un file di testo che contiene in ogni riga tre numeri reali, esegua le seguenti operazioni:
	1. Carichi in un array la somma degli elementi di ogni riga del file.
	2. Visualizzi gli elementi dell’array il cui valore è maggiore di una soglia inserita dall’utente.
	3. Calcoli la somma degli elementi positivi dell’array.
	4. Salvi nel file “uscita.txt” gli elementi dell’array aventi indice pari.
     
Specifiche:
	- La dimensione dell’array è N pari a 10
	- Il nome del file di ingresso deve essere inserito da input.
	- Il numero di righe nel file non è noto all’inizio. 
	- Eventuali elementi nel file oltre la riga N-esima (cioè oltre la decima riga) non devono essere presi in considerazione.

Esempio di File:
3.3  2.5   -4.6
0.7  -8.3  -2.3
3.4  -0.6  7.4
5.2  -4.3  3.8
----------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>

#define MAX_DIM_NOME_FILE 20
#define MAX_DIM_VETTORE 10

int main(void){
	
	FILE *fp;
	
	// SI INSERISCE IL NOME DEL FILE DA APRIRE
	char nomefile[MAX_DIM_NOME_FILE];
	printf("Il Nome del File da aprire e': ");
	scanf("%s",nomefile);
	
	// APERTURA FILE (Solo Lettura)
	fp = fopen(nomefile,"r");
	
	// SE IL FILE DA APRIRE NON ESISTE SI ESCE DAL PROGRAMMA, DANDO UN CODICE DI ERRORE = 1
	if(fp == NULL){
		printf("Errore! Il FILE cercato NON ESISTE");
		return 1;
	}
	
	// --> PUNTO 1 <--
	float A[MAX_DIM_VETTORE];
	int Dim_Effettiva = 0;
	float a,b,c;
		
	while(Dim_Effettiva<MAX_DIM_VETTORE && fscanf(fp,"%f %f %f", &a,&b,&c) == 3){
			A[Dim_Effettiva] = a+b+c;
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
	int k;
	printf("\nInserisci un Valore Soglia: ");
	scanf("%d",&k);
	
	printf("I Valori del Vettore Superiori al valore %d sono: \n",k);
	for(i=0; i<Dim_Effettiva; i++){
		if(A[i]>k){
			printf("%.2f\n",A[i]);
		}
	}
	
	// --> PUNTO 3 <--
	float Somma_Positivi = 0;
	for(i=0; i<Dim_Effettiva; i++){
		if(A[i]>0){
			Somma_Positivi = Somma_Positivi + A[i];
		}
	}		
	printf("\nLA SOMMA dei Valori Positivi del Vettore e': %.2f\n",Somma_Positivi);	
	
	// --> PUNTO 4 <--	
	
	// APERTURA FILE (Solo Scrittura)
	fp = fopen("Uscita.txt","w");

    printf("\n\nSono stati caricati tutti i valori di indice pari del vettore in un altro File.");
    	
	for(i=0; i<Dim_Effettiva; i++){
		if(i%2==0){
			fprintf(fp,"%.2f\n",A[i]);
		}
	}
	
	// CHIUSURA FILE
	fclose(fp);
	
}
	
	