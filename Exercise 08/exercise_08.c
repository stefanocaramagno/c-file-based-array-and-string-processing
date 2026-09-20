/*
----------------------------------------------------------------------------------------------------------------------------------------------
Scrivere un programma in ANSI C che, dato un file di testo che contiene in ogni riga un numero intero e una stringa, esegua le seguenti operazioni:
	1. Carichi in un array il numero intero se la lunghezza della corrispondente stringa è maggiore al numero.
	2. Visualizzi gli elementi di indice pari dell’array.
	3. Calcoli la somma dei quadrati degli elementi pari dell’array.
	4. Salvi nel file “uscita.txt” tutti gli elementi dell’array che sono divisori del valore calcolato al punto precedente.
     
Specifiche:
	- La dimensione dell’array è N pari a 10
	- Il nome del file di ingresso deve essere inserito da input.
	- Il numero di righe (cioè di coppie) nel file non è noto all’inizio. 
	- Eventuali coppie di elementi nel file oltre la riga N-esima (cioè oltre la decima riga) non devono essere prese in considerazione

Esempio di File:
5 pippo
3 pluto
4 paperino
2 minnie
----------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <string.h>

#define MAX_DIM_NOME_FILE 20
#define MAX_DIM_VETTORE 10
#define MAX_DIM_STRINGA 25

int main(void){
	
	FILE *fp;
	
	// SI INSERISCE IL NOME DEL FILE DA APRIRE
	char nomefile[MAX_DIM_NOME_FILE];
	printf("Inserisci il nome del file da aprire: ");
	scanf("%s",nomefile);
	
	// APERTURA FILE (Solo Apertura)
	fp = fopen(nomefile,"r");
	
	// SE IL FILE DA APRIRE NON ESISTE SI ESCE DAL PROGRAMMA, DANDO UN CODICE DI ERRORE = 1
	if(fp == NULL){
		printf("Errore! Il FILE cercato NON ESISTE");
		return 1;
    }
    
	// --> PUNTO 1 <--	
	int A[MAX_DIM_VETTORE];	
	char Stringa[MAX_DIM_STRINGA];
	
	int a;
	int Dim_Effettiva = 0;
	
	while(Dim_Effettiva<MAX_DIM_VETTORE && fscanf(fp,"%d %s",&a,Stringa) == 2){
		if(strlen(Stringa)>a){
			A[Dim_Effettiva] = a;
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
	printf("\nI Valori del Vettore di Indice Pari sono: \n");
	for(i=0; i<Dim_Effettiva; i++){
		if(i%2==0){
			printf("%d\n",A[i]);
		}
	}	
	
	// --> PUNTO 3 <--
	int Somma_Quadrati_Pari = 0;
	for(i=0; i<Dim_Effettiva; i++){
		if(A[i]%2!=0){
			Somma_Quadrati_Pari = A[i]*A[i]; 
		}
	}	
	printf("\nLa SOMMA DEI QUADRATI DEI VALORI PARI e': %d",Somma_Quadrati_Pari);
	
	
	// --> PUNTO 4 <--

	// APERTURA FILE (Solo Scrittura)
	fp = fopen("Uscita.txt","w");
	
	printf("\n\nSono stati caricati tutti i valori DIVISORI DELLA SOMMA DEI QUADRATI DEI VALORI PARI in un altro File.");
		
	for(i=0; i<Dim_Effettiva; i++){
		if(Somma_Quadrati_Pari % A[i] == 0){
			fprintf(fp,"%d\n",A[i]);
		}
	}	
	
	// CHIUSURA FILE
	fp = close(fp);
	
}