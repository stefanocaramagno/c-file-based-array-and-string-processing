/*
----------------------------------------------------------------------------------------------------------------------------------------------
Scrivere un programma in ANSI C che, dato un file di testo che contiene in ogni riga una coppia di numeri interi, esegua le seguenti operazioni:
	1. Carichi in un array il secondo elemento della coppia solo se questo è un divisore del primo elemento della coppia.
	2. Visualizzi gli elementi di indice dispari dell’array.
	3. Calcoli la media degli elementi dispari dell’array.
	4. Salvi nel file “uscita.txt” tutti gli elementi dell’array strettamente minori al valore calcolato al punto precedente.
     
Specifiche:
	- La dimensione dell’array è N pari a 10
	- Il nome del file di ingresso deve essere inserito da input.
	- Il numero di righe (cioè di coppie) nel file non è noto all’inizio. 
	- Eventuali coppie di elementi nel file oltre la riga N-esima (cioè oltre la decima riga) non devono essere prese in considerazione.

Esempio di File:
12 4
15 3
17 5
22 11
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
	int A[MAX_DIM_VETTORE];
	int Dim_Effettiva = 0;
	int a;
	int b;
	
	while(Dim_Effettiva<MAX_DIM_VETTORE && fscanf(fp,"%d %d",&a,&b) == 2){
		if(a%b==0){
			A[Dim_Effettiva] = b;
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
	printf("\nI Valori del Vettore di Indice Dispari sono: ");
	for(i=0; i<Dim_Effettiva; i++){
		if(i%2!=0){
			printf("%d\n",A[i]);
		}
	}
	
	// --> PUNTO 3 <--
	int Contatore_Dispari = 0;
	int Somma_Dispari = 0;
	for(i=0; i<Dim_Effettiva; i++){
		if(A[i]%2!=0){
			Somma_Dispari = Somma_Dispari + A[i];
			Contatore_Dispari++;
		}
	}
	float Media_Dispari = (float)Somma_Dispari / (float)Contatore_Dispari;
	printf("\nLa MEDIA dei solo VALORI DISPARI e': %.2f",Media_Dispari);
	
	// --> PUNTO 4 <--

	// APERTURA FILE (Solo Scrittura)
	fp = fopen("Uscita.txt","w");
	
	printf("\n\nSono stati caricati tutti i valori MINORI DEL VALORE DELLA MEDIA in un altro File.");
		
	for(i=0; i<Dim_Effettiva; i++){
		if(A[i]<Media_Dispari){
			fprintf(fp,"%.2f\n",A[i]);
		}
	}	
	
	// CHIUSURA FILE
	fp = close(fp);
	
}



