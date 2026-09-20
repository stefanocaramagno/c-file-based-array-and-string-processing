/*
--------------------------------------------------------------------------------------------------------------------------------
Scrivere un programma in ANSI C che, dato un file di testo che contiene in ogni riga una coppia di numeri 
(un intero ed un numero reale), esegua le seguenti operazioni:
	1. Carichi in un array i valori reali presenti nelle righe del file in cui il corrispondente valore intero è dispari.
	2. Visualizzi gli elementi di indice dispari dell’array.
	3. Calcoli e visualizzi la somma degli elementi positivi e la somma degli elementi negativi dell’array.
	4. Salvi nel file "uscita.txt" gli elementi dell’array inferiori ad un valore soglia inserito da tastiera.

Specifiche: 
	- La dimensione dell’array è N pari a 10.
	- Il nome del file di ingresso deve essere inserito da input. 
	- Il numero di righe (cioè di coppie) nel file non è noto all’inizio. 
	- Eventuali coppie di elementi nel file che soddisfano la condizione in 1, ma che non possono essere caricati nel 
	  vettore poiché pieno, non devono essere prese in considerazione.

Esempio di File:
12 32.4
25 -43.5
34 -4.56
18 5.65
17 24.6
49 14.8
31 4.3
28 -5.6
55 -7.8
23 10.6
34 12.3
70 3.5
-------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>

#define MAX_DIM_NOMEFILE 20
#define MAX_DIM_VETTORE 10

int main(void){
	
	FILE *fp;
	
	// SI INSERISCE IL NOME DEL FILE DA APRIRE
	char nomefile[MAX_DIM_NOMEFILE];
	printf("Inserisci il Nome del File da caricare: ");
	scanf("%s",nomefile);
	
	// APERTURA FILE (Solo lettura)
	fp = fopen(nomefile,"r");
	
	// SE IL FILE DA APRIRE NON ESISTE, SI ESCE DAL PROGRAMMA DANDO UN CODICE DI ERRORE = 1
	if (fp == NULL){
		printf("Errore! Il File inserito NON ESISTE.");
		return 1;
	}
	
	// --> Punto 1 <--
	int a;
	float b;
	float A[MAX_DIM_VETTORE];
	int Dim_Effettiva = 0;
	
	while(Dim_Effettiva<MAX_DIM_VETTORE && fscanf(fp, "%d %f", &a,&b)==2){
		if(a%2!=0){
			A[Dim_Effettiva] = b;
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
	
	// --> Punto 2 <--
	printf("\nIl Vettore stampando solo i valori di Indice Dispari e' il seguente: \n");
	for(i=0; i<Dim_Effettiva; i++){
		if(i%2!=0){
			printf("%.2f\n",A[i]);
		}
	}
	
	// --> Punto 3 <--
	float Somma_Positivi = 0;
	printf("\nLa SOMMA dei Valori Positivi del Vettore e': ");
	for(i=0; i<Dim_Effettiva; i++){
		if(A[i]>0){
			Somma_Positivi = Somma_Positivi + A[i];
		}
	}
	printf("%.2f",Somma_Positivi);
		
    float Somma_Negativi = 0;
	printf("\nLa SOMMA dei Valori Negativi del Vettore e': ");
	for(i=0; i<Dim_Effettiva; i++){
		if(A[i]<0){
			Somma_Negativi = Somma_Negativi + A[i];
		}
	}	
	printf("%.2f",Somma_Negativi);
	
	// --> Punto 4 <--
	
	int k;
	printf("\n\nInserisci un Valore Soglia: ");
	scanf("%d",&k);
	
	printf("Sono stati caricati tutti i Valori SUPERIORI a %d in un altro File.",k);
	
	// APERTURA FILE (Solo Scrittura)
	fp = fopen("Uscita.txt","w");
		
	for(i=0; i<Dim_Effettiva; i++){
		if(A[i]>k){
			fprintf(fp, "%.2f\n",A[i]);
		}	
	}
	
	// CHIUSURA FILE
	fclose(fp);	
}

