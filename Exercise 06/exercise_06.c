/*
----------------------------------------------------------------------------------------------------------------------------------------------
Scrivere un programma in ANSI C che, dato un file di testo che contiene in ogni riga una coppia di numeri (un intero ed un reale), esegua le seguenti operazioni:
	1. Carichi in un array i numeri reali delle righe in cui il valore intero è pari.
	2. Visualizzi gli elementi di indice dispari dell’array.
	3. Calcoli la media degli elementi positivi dell’array.
	4. Salvi nel file “uscita.txt” tutti gli elementi dell’array strettamente minori al valore calcolato al punto precedente.
     
Specifiche:
	- La dimensione dell’array è N pari a 10
	- Il nome del file di ingresso deve essere inserito da input.
	- Il numero di righe (cioè di coppie) nel file non è noto all’inizio. 
	- Eventuali coppie di elementi nel file oltre la riga N-esima (cioè oltre la decima riga) non devono essere prese in considerazione.   

Esempio di File:
2  4.3
4 -9.6
5 -0.7
8  6.8
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
	int a;
	float b;
	
	while(Dim_Effettiva<MAX_DIM_VETTORE && fscanf(fp,"%d %f",&a,&b) == 2){
		if(a%2==0){
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
	
	// --> PUNTO 2 <--
	printf("\nI Valori del Vettore di Indice Dispari sono: \n");
	for(i=0; i<Dim_Effettiva; i++){
		if(i%2!=0){
			printf("%.2f\n",A[i]);
		}
	}
	
	// --> PUNTO 3 <--
	int Contatore_Positivi;
	float Somma_Positivi = 0;
	for(i=0; i<Dim_Effettiva; i++){
		if(A[i]>0){
			Somma_Positivi = Somma_Positivi + A[i];
			Contatore_Positivi++;
		}
	}
	float Media_Positivi = Somma_Positivi / Contatore_Positivi;
	printf("\nLa MEDIA dei solo VALORI POSITIVI e': %.2f",Media_Positivi);
	
	// --> PUNTO 4 <--
	
	
	// APERTURA FILE (Solo Scrittura)
	fp = fopen("Uscita.txt","w");
	
	printf("\n\nSono stati caricati tutti i valori MINORI DEL VALORE DELLA MEDIA in un altro File.");
		
	for(i=0; i<Dim_Effettiva; i++){
		if(A[i]<Media_Positivi){
			fprintf(fp,"%.2f\n",A[i]);
		}
	}	
	
	// CHIUSURA FILE
	fp = close(fp);
	
}

