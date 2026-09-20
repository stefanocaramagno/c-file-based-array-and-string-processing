/*
--------------------------------------------------------------------------------------------------------------
Scrivere un programma in ANSI C che, dato un file di testo che contiene in ogni riga una stringa senza spazi 
di lunghezza massima 25 caratteri e un numero reale, esegua le seguenti operazioni: 
	1. Carichi in un array i valori reali corrispondenti a stringhe di lunghezza superiore a 5 caratteri.
	2. Visualizzi gli elementi negativi dell’array. 
	3. Visualizzi l’elemento minimo e la sua posizione all’interno dell’array. 
	4. Salvi nel file “uscita.txt” gli elementi dell’array positivi.
      
Specifiche: 
	- La dimensione dell’array è N pari a 10. 
	- Il nome del file di ingresso deve essere inserito da input. 
	- Il numero di righe (cioè di coppie) nel file non è noto all’inizio.   
	- Eventuali coppie di elementi nel file che soddisfano la condizione in 1, ma che non possono essere 
	  caricati nel vettore poichè pieno, non devono essere prese in considerazione.

Esempio File:
previsione	  -3.7
cucina 		  1.23
dado		  6.78
opera		  3
supercalifragili  -10
comenondetto	  -11.1
zeroassoluto	  0
zeromeno1	  -1
unpo		  200.3
senzanessuno	  -2.5
cent		  -1.1
cico		  -1000
-----------------------------------------------------------------------------------------------------------------
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
	
	// APERTURA FILE (Solo Lettura)
	fp = fopen(nomefile,"r");
	
	// SE IL FILE DA APRIRE NON ESISTE SI ESCE DAL PROGRAMMA, DANDO UN CODICE DI ERRORE = 1
	if(fp == NULL){
		printf("Errore! Il FILE cercato NON ESISTE");
		return 1;	
	}
	
	// --> PUNTO 1 <--	
	float A[MAX_DIM_VETTORE];
	
	char Stringa[MAX_DIM_STRINGA];
	float a;
	int Dim_Effettiva = 0;
	
	while(Dim_Effettiva<MAX_DIM_VETTORE && fscanf(fp,"%s %f",Stringa,&a) == 2){
		if(strlen(Stringa)>5){
			A[Dim_Effettiva] = a;
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
	printf("\nI Valori del Vettore minori di 0 sono: \n");
	for(i=0; i<Dim_Effettiva; i++){
		if(A[i]<0){
			printf("%.2f\n",A[i]);
		}
	}	
	
	// --> PUNTO 3 <--
	int Indice = -1;
	float Minimo = 0;
	for(i=0; i<Dim_Effettiva; i++){
		if(A[i]<Minimo){
			Minimo = A[i];
			Indice++;
		}
	}
    printf("\nIl Valore MINIMO del Vettore e': %.2f",Minimo);
    printf("\nL'Indice del Valore MINIMO del Vettore e': %d",Indice);

	// --> PUNTO 4 <--
	
	// APERTURA FILE (Solo Scrittura)
	fp = fopen("Uscita.txt","w");	
	printf("\n\nSono stati caricati tutti i valori MAGGIORI di 0 in un altro File");
	
	for(i=0; i<Dim_Effettiva; i++){
		if(A[i]>0){
			fprintf(fp,"%.2f",A[i]);
		}
	}

	// CHIUSURA FILE
	fclose(fp);

