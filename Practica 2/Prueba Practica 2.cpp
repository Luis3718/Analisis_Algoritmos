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
#include <cmath>
using namespace std;
int ctd;

int mostrarperfecto(int n, int *ctd)
{
	long int div,i,perfecto=0,num=1;
	while(n!=perfecto)
	{
		for(i=1;i<num;i++)
		{
			if(num%i==0)
			{
				div+=i;
			}
		}
		if(num==div)
		{
			cout<<num <<", ";
			perfecto++; 
		}
		else
		{
		}
		num++;
		div=0;	
	}
}


void perfecto(int n, int *ctd)
{
	int div,i;
	for(i=1;i<n;i++)
	{
		if(n%i==0)
		{
			div+=i;
		}
	}
	if(n==div)
	{
		cout<<"El " <<n <<" Es un numero perfecto";
	}
	else
	{
		cout<<"El " <<n <<" No es perfecto";
	}
}

void fibonacci(int n, int *ctd)
{
	int i,fibo=1,aux,ant=0; 
	if(n>0)
	{
		for(i=1;i<=n;i++)
		{
			cout<<fibo <<", ";
			aux=fibo; 
			fibo+=ant; 
			ant=aux; 
		}
	}
}

int fibonaccir(int n, int *ctd)
{
	if(n>1)
	{
		return fibonaccir((n-1),ctd)+fibonaccir((n-2),ctd);
	}	
	else 
	{
		if(n==0)
		{
			return 0; 
		}
		if(n==1)
		{
			return 1; 
		}
	}
}

int main(){
	int n,i,p,r,j; 
	int pts=20;
	int pts2=15;
	int pasos3=4;
	long int perf=15;
	FILE *pf=fopen("Fibonacci.csv","at");
	FILE *pd=fopen("Fibonacci recursivo.csv","at");
	FILE *ps=fopen("Numeros perfectos.csv","at");
	FILE *pr=fopen("Mostrar Numeros perfectos.csv","at");
	n=10;
	p=10;
	r=1;
	srand(time(NULL));
	int s=rand()%100;
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
	
	for(i=1;i<=perf;i++)
	{
		ctd=0;
		perfecto(s,&ctd); 
		s+=50;	
		cout<<"\nNumero de pasos: " <<ctd <<endl;
		fprintf(ps,"%d,%d\n",s,ctd);
	}
	
	for(j=1;j<=pasos3;j++)
	{	
		ctd=0;
		mostrarperfecto(r,&ctd); 
		r+=1;	
		cout<<"\nNumero de pasos: " <<ctd <<endl;
		fprintf(pr,"%d,%d\n",r,ctd);
	}
	fclose(pr);
	fclose(pf);
	fclose(pd);
	fclose(ps);
}
