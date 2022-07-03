/*
  Instituto Politécnico Nacional
  ESCOM
  Alumno
  Materia:
  Grupo:
  
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 1000

void principal();
void generaArreglo(int *A, int n);
void imprimeArreglo(int *A, int n);
int busquedaSecuencial(int *A, int n, int x, int *ct);
int sumaArreglo(int *A, int n, int *ct);
void insertionSort(int *A, int n, int *ct);

main()
{
	principal();
	return 0;
}

void principal()
{
	FILE *pf=fopen("busqSec.csv","at");
	
	int Arr[TAM];
	int tam=10;
	int ct=0;

    int i=0;
    int pts=20;

   for(i=0; i<pts; i++)
     {
       ct=0;
       generaArreglo(Arr,tam);
       imprimeArreglo(Arr,tam); 
       insertionSort(Arr,tam,&ct);
       printf("\n");
       imprimeArreglo(Arr,tam);
       printf("\n---------------------------------\n");
//     int s=sumaArreglo(Arr,tam,&ct);
//	   srand(time(NULL));
//	   int ind=rand()%tam;   
//     int x=Arr[ind];
//     int b=busquedaSecuencial(Arr,tam,x,&ct);
//     printf("\n--> %d <--", b);
       printf("\n Num. Pasos: %d\n",ct);
       fprintf(pf,"%d,%d\n",tam,ct);
       tam+=10;
	 }

    


    fclose(pf);
}

void generaArreglo(int *A, int n)
{
 	srand(time(NULL));
 	int i;
 	for(i=0; i<n; i++)
 	    A[i]=n-i;//rand()%(n+10);
}

void imprimeArreglo(int *A, int n)
{
	int i;
	for(i=0; i<n; i++)
	    printf("[ %d ]", A[i]);
}

int busquedaSecuencial(int *A, int n, int x,int *ct)
{
	int i; (*ct)++;
	
	(*ct)++;
	for(i=0; i<n; i++)
	{
	   	(*ct)++;
	   	if(A[i]==x)
	   	{
	   	  	(*ct)++;
	   	  	(*ct)++;
	   	  	return i;
		}
		(*ct)++;
		(*ct)++;
	}
	(*ct)++;
	(*ct)++;   
	return -1;
}

int sumaArreglo(int *A, int n, int *ct)
{
	int suma=0; (*ct)++;
	int i; (*ct)++;
	
	(*ct)++;
	for(i=0; i<n; i++)
	  {
	  	(*ct)++;
	  	suma+=A[i]; (*ct)++;
	  	(*ct)++;
	  }
	(*ct)++;
	(*ct)++;
	return suma;
}

void insertionSort(int *A, int n, int *ct)
{
	int i; (*ct)++;
	int j; (*ct)++;
	int key; (*ct)++;
	
	(*ct)++;
	for(i=1; i<n; i++)
	   {
	   	(*ct)++;
	   	key=A[i]; (*ct)++;
	   	j=i-1; (*ct)++;
	   	(*ct)++;
	   	
	   	
	   	while(j>=0 && A[j]>key)
	   	    {
	   	    	(*ct)++;
	   	    	(*ct)++;
	   	    	(*ct)++;
	   	    	
	   	    	A[j+1]=A[j]; (*ct)++;
	   	    	j--; (*ct)++;
			}
		(*ct)++;
	//	(*ct)++;	
			
		A[j+1]=key; (*ct)++;
	   }
	(*ct)++;
}

