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

int main(){
	int n,i,s,pts=50;
	int *num1; 
	FILE *pd=fopen("Division2.csv","at");
	srand(time(NULL));
	n=rand()%75;
	cout<<"Division 2: " <<endl;
	for(i=0;i<pts;i++)
	{
		ctd=0;
		division2(n,n+1,&ctd);	
		n+=5;
		cout<<"\nNumero de pasos: " <<ctd <<endl;
		fprintf(pd,"%d,%d\n",n,ctd);
	}
	fclose(pd);
}
