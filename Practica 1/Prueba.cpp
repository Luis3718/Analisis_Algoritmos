/*
  Instituto Politécnico Nacional
  ESCOM
  Alvarado Romero Luis Manuel
  Reyes Becerra Angelica
  Materia: Analisis y diseño de Algoritmos
  Grupo: 3CV1
*/
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;
int ctd;

void perfecto(int n,int *ctd)
{
	int div,sum,i,j; (*ctd)++;
	(*ctd)++;
	for(i=1;i<=n;i++)
	{
		(*ctd)++;
		for(j=1;j<i;j++)
		{
			(*ctd)++;
			if(i%j==0)
			{
				(*ctd)++;
				(*ctd)++;
				div=j; (*ctd)++;
				sum+=div; (*ctd)++;
			}
			(*ctd)++;
		}
		if(sum==i)
		{
			(*ctd)++;
			(*ctd)++;
			cout<<i <<" Es un numero perfecto" <<endl;
		}
		(*ctd)++;
		(*ctd)++;
	}
	(*ctd)++;
}

void fibonacci(int n, int *ctd)
{
	int i,fibo=1,aux,ant=0; (*ctd)++;
	if(n>0)
	{
		(*ctd)++;
		(*ctd)++;
		for(i=1;i<=n;i++)
		{
			(*ctd)++;
			cout<<fibo <<", "; (*ctd)++;
			aux=fibo; (*ctd)++;
			fibo+=ant; (*ctd)++;
			ant=aux; (*ctd)++;
			(*ctd)++;
		}
		(*ctd)++;
	}
	(*ctd)++;
}

int fibonaccir(int n, int *ctd)
{
	if(n>1)
	{
		(*ctd)++;
		(*ctd)++;
		return fibonaccir((n-1),ctd)+fibonaccir((n-2),ctd);
	}	
	else 
	{
		(*ctd)++;
		if(n==0)
		{
			(*ctd)++;
			(*ctd)++;
			return 0; 
		}
		(*ctd)++;
		if(n==1)
		{
			(*ctd)++;
			(*ctd)++;
			return 1; 
		}
		(*ctd)++;
	}
}

int main(){
	int n,i,p; 
	int pts=20;
	int pts2=15;
	long int perf=30;
	FILE *pf=fopen("Fibonacci.csv","at");
	FILE *pd=fopen("Fibonacci recursivo.csv","at");
	FILE *ps=fopen("Numeros perfectos.csv","at");
	n=10;
	p=10;
	int s=0;
	for(i=0;i<pts;i++)
	{
		ctd=0;
		fibonacci(n,&ctd); 
		n+=10;	
		cout<<"\nNumero de pasos: " <<ctd;
		fprintf(pf,"%d,%d\n",n,ctd);
	}
	for(i=0;i<pts2;i++)
	{
		ctd=0;
		fibonaccir(p,&ctd); 
		p+=1;	
		cout<<"\nNumero de pasos: " <<ctd;
		fprintf(pd,"%d,%d\n",p,ctd);
	}
	for(i=0;i<perf;i++)
	{
		ctd=0;
		perfecto(s,&ctd); 
		s+=2;	
		cout<<"\nNumero de pasos: " <<ctd;
		fprintf(ps,"%d,%d\n",s,ctd);
	}
	fclose(pf);
	fclose(pd);
	fclose(ps);
}
