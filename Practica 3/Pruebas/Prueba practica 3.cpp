/*
  Instituto Politécnico Nacional
  ESCOM
  Alvarado Romero Luis Manuel
  Reyes Becerra Lizeth Angelica
  Materia: Analisis y diseño de Algoritmos
  Grupo: 3CV1
*/
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;
int ctd;

int division1(int n,int div,int *ctd)
{
	int res,q; (*ctd)++;
	q=0; (*ctd)++;
	(*ctd)++;
	while(n>=div)
	{
		(*ctd)++;
		(*ctd)++;
		n=n-div; (*ctd)++;
		q=q+1; (*ctd)++;
	}
	res=n; (*ctd)++;
	cout<<q <<endl; (*ctd)++;
}
int division2 (int n,int div,int *ctd)
{
	int res,q,dd,r; (*ctd)++;
	dd=div; (*ctd)++;
	q=0; (*ctd)++;
	r=n; (*ctd)++;
	(*ctd)++;
	while(dd<=n)
	{
		(*ctd)++;
		(*ctd)++;
		dd=2*dd;(*ctd)++;
	}
	(*ctd)++;
	while(dd>div)
	{
		(*ctd)++;
		(*ctd)++;
		dd=dd/2; (*ctd)++;
		q=2*q; (*ctd)++;
		(*ctd)++;
		if(dd<=r) 
		{
			(*ctd)++;
			r=r-dd; (*ctd)++;
			q=q+1; (*ctd)++;
		}
		(*ctd)++;
	}
	cout<<q <<endl; (*ctd)++;
}
int division3 (int n,int div, int *ctd)
{
	int s; (*ctd)++;
	(*ctd)++;
	if(div>n)
	{
		(*ctd)++;
		return 0; (*ctd)++;
	}
	else
	{
		return 1+division3(n-div,div,ctd);(*ctd)++;
	}
}

void generar(int *num1, int n)
{
	srand(time(NULL));
 	for(int i=0; i<=n; i++)
 	{
 		num1[i]=i;
   	}
}

void imprimir(int *num1 ,int n)
{
	printf("\nEl arreglo 1 es: \n");
   	for(int i=0;i<=n;i++)
	{
   		cout<<num1[i] <<", ";
   	}
}

int busquedaternaria()
{
}

int busquedaternariar()
{
}


int main()
{
	int n,i,s,x,pts=15;
	int *num1; 
	//FILE *pf=fopen("Division1.csv","at");
	//FILE *pd=fopen("Division2.csv","at");
	//FILE *ps=fopen("Division3.csv","at");
	//FILE *pr=fopen("Busqueda ternarea.csv","at");
	srand(time(NULL));
	/*n=rand()%75;
	for(i=0;i<pts;i++)
	{
		ctd=0;
		division1(n,1,&ctd);	
		n+=5;
		cout<<"\nNumero de pasos: " <<ctd <<endl;
		fprintf(pf,"%d,%d\n",n,ctd);
	}
	n=rand()%75;
	cout<<"Division 2: " <<endl;
	for(i=0;i<pts;i++)
	{
		ctd=0;
		division2(n,1,&ctd);	
		n+=5;
		cout<<"\nNumero de pasos: " <<ctd <<endl;
		fprintf(pd,"%d,%d\n",n,ctd);
	}
	n=rand()%75;
	for(i=0;i<pts;i++)
	{
		ctd=0;
		division3(n,1,&ctd);	
		n+=5;
		cout<<"\nNumero de pasos: " <<ctd <<endl;
		fprintf(ps,"%d,%d\n",n,ctd);
	}
	n=10;
	for(i=0;i<pts;i++)
	{
		ctd=0;
		num1 =  (int *) calloc(n, sizeof(int));
		if (num1  == NULL) 
		{
			cout<<"Error al generar memoria" <<endl;
			return 0;
		}
		generar(num1,n);
		imprimir(num1,n);
		busquedabinaria(num1,5,n);
		n+=5;	
		//cout<<"\nNumero de pasos: " <<ctd;
		//fprintf(pr,"%d,%d\n",n,ctd);
	}*/
	free(num1);
	//fclose(pr);
	//fclose(pf);
	//fclose(pd);
	//fclose(ps);
}
