/*
----------------------------------------------------------------------------------------------------------------------------------------------
Un file contiene per ogni riga una stringa alfanumerica ed un numero intero positivo. 
Scrivere un programma che implementi le seguenti operazioni:
	1. Caricare in un vettore di interi l'elenco dei numeri interi calcolati come di seguito. Per ogni riga del file, nel 
		formato 'stringa' 'numero', se il carattere di posizione 'numero' di 'stringa':
		- Se e' una vocale, allora il numero intero generato da memorizzare nel vettore è 1 se la vocale è 'a', 2 se 'e', 3 se 'i' e così via, 
		- Mentre è 0 se non è una vocale.
	2. Contare e visualizzare il numero di 0 contenuti nel vettore.
	3. Calcolare e visualizzare la media degli elementi non nulli del vettore.
	4. Salvare in un file denominato "risultato.txt" i valori del vettore compresi tra 2 e 4 (estremi compresi).

Specifiche:
	- La dimensione del vettore è 10.
	- Il numero di righe presenti nel file non è noto a priori.
	- Il nome del file di ingresso deve essere letto da tastiera.

ESEMPIO DI FUNZIONAMENTO INGRESSO/USCITA
Contenuto del file di ingresso:
pippo 2 
paperino 1
paperino 5
toodles 3
clarabella 3
pluto 3
paperina 4 
minnie 3

Elementi del vettore
0, 1, 3, 0, 0, 0, 0, 0
 
Risultati visualizzati:
Il vettore contiene 5 elementi nulli
La media degli elementi non nulli e' 1.7

Contenuto del file risultato.txt
3
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
	
	// APERTURA FILE (Solo Lettura)
	fp = fopen(nomefile,"r");
	
	// SE IL FILE DA APRIRE NON ESISTE SI ESCE DAL PROGRAMMA, DANDO UN CODICE DI ERRORE = 1
	if(fp == NULL){
		printf("Errore! Il FILE cercato NON ESISTE");
		return 1;	
	}	
		
	// --> PUNTO 1 <--
    int Dim_Effettiva = 0;
    int A[MAX_DIM_VETTORE];
    int a;
    char Stringa[MAX_DIM_STRINGA];
    
    while(Dim_Effettiva<MAX_DIM_VETTORE && fscanf(fp,"%s %d",Stringa,&a) == 2){
		switch (Stringa[a]){
		  	case 'a':
		      A[Dim_Effettiva] = 1;
		      break;
		      
		  	case 'e':
		      A[Dim_Effettiva] = 2;
		      break;
		
		    case 'i':
		      A[Dim_Effettiva] = 3;
		      break;
		
		    case 'o':
		      A[Dim_Effettiva] = 4;
		      break;
		      
		    case 'u':
		      A[Dim_Effettiva] = 5;
		      break;      
		
		    default:
		      	A[Dim_Effettiva] = 0;
		}
 		Dim_Effettiva++;		
	}

    int i;
    printf("\nIl Vettore ricavato dai valori del File e' il seguente: \n");
    for(i=0; i<Dim_Effettiva; i++){
    	printf("%d\n",A[i]);
	}
	
    // CHIUSURA FILE
	fclose(fp);
	
	// --> PUNTO 2 <--
	int ContatoreZeri = 0;
	for(i=0; i<Dim_Effettiva; i++){
		if(A[i]==0){
			ContatoreZeri++;
		}
	}
	printf("\nIl Numero di ELEMENTI NULLI nel Vettore e': %d",ContatoreZeri);
	
	// --> PUNTO 3 <--	
	int Somma = 0;
	int Contatore_Non_Nulli = 0;
	for(i=0; i<Dim_Effettiva; i++){
		if(A[i]!=0){
			Somma = Somma + A[i];
			Contatore_Non_Nulli++;
		}
	}	
	float Media = (float)Somma / (float)Contatore_Non_Nulli;
	printf("\nLa MEDIA degli ELEMENTI NON NULLI del Vettore e':  %.2f",Media);
	
	// --> PUNTO 4 <--	
	
	// APERTURA FILE (Solo Scrittura)
	fp = fopen("Uscita.txt","w");
	
	printf("\n\nSono stati caricati tutti i valori compresi tra 2 e 4 (con estremi inclusi) in un altro File.");
	
	for(i=0; i<Dim_Effettiva; i++){
		if(A[i]>=2 && A[i]<=4){
			fprintf(fp,"%d\n",A[i]);
		}
	}
	
	// CHIUSURA FILE
	fclose(fp);
}