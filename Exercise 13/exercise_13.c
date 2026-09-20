 /*
----------------------------------------------------------------------------------------------------------------------------------
Un file contiene per ogni riga una stringa (senza spazi) ed una coppia di numeri interi. 
Scrivere un programma che implementi le seguenti operazioni:
	1. Caricare in un vettore di interi l'elenco dei numeri interi calcolati come di seguito. 
	   Per ogni riga del file, nel formato 'stringa' 'min' 'max':
		- se la lunghezza di 'stringa' è compresa tra 'min' e 'max', allora memorizzare nell'array la lughezza della stringa. 
		- se la lunghezza di 'stringa' è minore di 'min' memorizzare -1, 
		- se maggiore di 'max' memorizzare 0.

	2. Contare e visualizzare il numero di volte in cui nel vettore è presente -1 seguito da 0.

	3. Trovare e visualizzare il massimo del vettore

	4. Salvare in un file denominato "risultato.txt" il quadrato degli elementi non nulli del vettore.

Specifiche: 
	- La dimensione del vettore è 10
	- Il numero di righe presenti nel file non è noto a priori
	- Il nome del file di ingresso deve essere letto da tastiera

ESEMPIO DI FUNZIONAMENTO INGRESSO/USCITA
Contenuto del file di ingresso:
pippo 2 5
paperino 1 10
paperino 5 7
toodles 3 10
clarabella 2 15
pluto 10 20
paperina 1 6
minnie 8 16

Elementi del vettore
5
8
0
7
10
-1
0
-1

Risultati visualizzati:
Il numero di volte in cui è presente -1 seguito da 0 è 1
Il massimo è 10

Contenuto del file risultato.txt
25
64
49
100
1
1
---------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <string.h>>

#define MAX_DIM_NOME_FILE 20
#define MAX_DIM_VETTORE 10

int main(void){
	
	FILE *fp;
	
	char nomefile[MAX_DIM_NOME_FILE];
	printf("Inserisci il Nome del File da Inserire: ");
	scanf("%s",nomefile);
	
	// APERTURA FILE (Solo Lettura)
	fp = fopen(nomefile,"r");
	
	// SE IL FILE DA APRIRE NON ESISTE SI ESCE DAL PROGRAMMA, DANDO UN CODICE DI ERRORE = 1
	if(fp == NULL){
		printf("Errore! Il FILE cercato NON ESISTE");
		return 1;
	}
	
	// --> Punto 1 <--
	int A[MAX_DIM_VETTORE];
	int Dim_Effettiva = 0;
	char Stringa[25];
	int Max;
	int Min;
	
	while(Dim_Effettiva<MAX_DIM_VETTORE && fscanf(fp, "%s %d %d",Stringa,&Min,&Max) == 3){
		if(strlen(Stringa)>=Min && strlen(Stringa)<=Max){
			A[Dim_Effettiva] = strlen(Stringa);
		}
		if(strlen(Stringa)<Min){
			A[Dim_Effettiva] = -1;
		}
		if(strlen(Stringa)>Max){
			A[Dim_Effettiva] = 0;
		}
		Dim_Effettiva++;
	}
	
	printf("\nIl Vettore ricavato dai Valori del File e' il seguente: \n");
	int i;
	for(i=0; i<Dim_Effettiva; i++){
		printf("%d\n",A[i]);
	}
	
	// CHIUSURA FILE 
	fclose(fp);
		
	// --> Punto 2 <--
	int Contatore = 0;
	for(i=0; i<Dim_Effettiva-1; i++){
		if(A[i]==-1 && A[i+1]==0){
			Contatore++;
		}
	}	
	printf("\n\nIl Numero di Volte che nel Vettore si trova -1 seguito da 0 e': %d",Contatore);
	
	// --> Punto 3 <--
	int Massimo=A[0];	
	for(i=0; i<Dim_Effettiva; i++){
		if(A[i]>Massimo){
			Massimo = A[i];
		}
	}
	printf("\n\nIl MASSIMO del Vettore e': %d",Massimo);
	
	// --> Punto 4 <--
	
	// APERTURA FILE (Solo Scrittura)
	fp = fopen("Uscita.txt","w");
	
	printf("\n\nSono stati caricati tutti I QUADRATI DEGLI ELEMENTI NON NULLI del Vettore in un altro File.");
	
	int Quadrato;
	for(i=0; i<Dim_Effettiva; i++){
		if(A[i]!=0){
			Quadrato = A[i]*A[i];
				fprintf(fp,"%d\n",Quadrato);
		}
	}
	
	// CHIUSURA FILE 
	fclose(fp);	
	
}

