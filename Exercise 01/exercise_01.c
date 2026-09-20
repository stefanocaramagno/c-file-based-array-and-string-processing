/*
----------------------------------------------------------------------------------------------------------------------------------------------
- Scrivere un programma in ANSI C che, dato un file di testo che contiene in ogni riga una coppia di numeri interi, esegua le seguenti operazioni:
	1. Carichi in un array il valore dato dalla somma dei numeri della coppia.
	2. Visualizzi gli elementi dell’array a partire da una posizione indicata dall’utente.
	3. Calcoli il massimo degli elementi positivi dell’array.
	4. Salvi nel file “uscita.txt” gli elementi dell’array negativi o nulli.

Specifiche:
	- La dimensione dell’array è N pari a 10
	- Il nome del file di ingresso deve essere inserito da input.
	- Il numero di righe (cioè di coppie) nel file non è noto all’inizio. 
	- Eventuali coppie di elementi nel file oltre la riga N-esima (cioè oltre la decima riga) non devono essere prese in considerazione


Esempio di File:
5    7
8    9
2   -6
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
		printf("Errore! Il File cercato NON ESISTE");
		return 1;
	}
		
	// --> PUNTO 1 <--
	int Dim_Effettiva;
	int A[MAX_DIM_VETTORE];
	int a, b;
	
    while(Dim_Effettiva<MAX_DIM_VETTORE && fscanf(fp,"%d %d",&a,&b) == 2){
    	A[Dim_Effettiva] = a+b;
    	Dim_Effettiva++;
	}	
	
	int i;
	printf("\nIl Vettore ricavato dai valori del File e' il seguente: \n");
	for(i=0; i<Dim_Effettiva; i++){
			printf("%d\n",A[i]);
	}

    // CHIUSURE FILE
	fclose(fp);
	
	// --> PUNTO 2 <-- 
	int k;
    printf("\nInserire un Valore Compreso tra 0 e %d: ",Dim_Effettiva-1);
    scanf("%d",&k);
    
    printf("\nI Valori del Vettore a partire dall'Indice %d sono: \n",k);
    for(i=k; i<Dim_Effettiva; i++){
    		printf("%d\n",A[i]);	
	}
    
	// --> PUNTO 3 <-- 
	int Massimo = 0;
	for(i=0; i<Dim_Effettiva; i++){
		if(A[i]>Massimo && A[i]>0){
			Massimo = A[i];
		}
	}
	printf("\nIl MASSIMO tra gli Elementi MAGGIORI DI 0 e': %d",Massimo);
	
	
	// --> PUNTO 4 <-- 	
	
	
    // APERTURA FILE (Solo Scrittura)
	fp = fopen("Uscita.txt","w");

    printf("\n\nSono stati caricati tutti i valori NEGATIVI e NULLI in un altro File.");
		
    for(i=0; i<Dim_Effettiva; i++){
    	if(A[i]==0 || A[i]<0){
    		fprintf(fp,"%d\n",A[i]);
		}
	}

    // CHIUSURE FILE
	fclose(fp);	
}





