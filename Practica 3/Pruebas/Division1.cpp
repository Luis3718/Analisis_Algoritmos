/*
  Instituto Politécnico Nacional
  ESCOM
  Alvarado Romero Luis Manuel
  Reyes Becerra Lizeth Angelica
  Materia: Analisis y diseño de Algoritmos
  Grupo: 3CV1
*/
#include <stdlib.h>
#include <iostream>
#include <time.h>
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

int main()
{
	int n=1;
	FILE *pf=fopen("Dision3.csv","at");
	for(int i=0;i<35;i++)
	{
		ctd=0;
		division3(n,n+1,&ctd);
		n+=1;
		cout<<"\nNumero de pasos: " <<ctd;
		fprintf(pf,"%d,%d\n",n,ctd);
	}
}
