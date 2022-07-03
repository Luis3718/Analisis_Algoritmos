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
void generar(int *num1, int n)
{
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

int busquedaternaria(int *num1, int x, int n, int *ctd)
{
	int inf=0; (*ctd)++;
    int sup=n-1; (*ctd)++;
    int i1=(inf+sup)/3; (*ctd)++;
    int i2=(i1+1+sup)/2; (*ctd)++;
    while(i2>=inf)
    {
    	(*ctd)++;
    	(*ctd)++;
    	i1=(inf+i2)/2; (*ctd)++;
    	(*ctd)++;
    	if(num1[i1]==x)
    	{
    		(*ctd)++;
    		(*ctd)++;
    		(*ctd)++;
    		cout<<"numero encontrado " <<num1[i1];
    		return 0;
		}
		else if(x<num1[i1])
		{
			(*ctd)++;
			(*ctd)++;
			i2=i1-1;
		}
		else
		{
			(*ctd)++;
			(*ctd)++;
			inf=i1+1;
		}
	}
	inf=0; (*ctd)++;
    sup=n-1; (*ctd)++;
	i1=(inf+sup)/3; (*ctd)++;
    i2=(i1+1+sup)/2; (*ctd)++;
	while(sup>=i1) 
	{
		(*ctd)++;
		(*ctd)++;
		i2=(i1+sup)/2; (*ctd)++;
		if(num1[i2]==x) 
    	{
    		(*ctd)++;
    		(*ctd)++;
    		(*ctd)++;
    		(*ctd)++;
    		cout<<"numero encontrado " <<num1[i2];
    		return 0;
		}
		else if(x<num1[i2])
		{
			(*ctd)++;
			(*ctd)++;
			sup=i2-1;
		}
		else
		{
			(*ctd)++;
			(*ctd)++;
			i1=i2+1;
		}	
	} 
	cout<<"Numero no encontrado" <<endl; (*ctd)++;
	return 0; (*ctd)++;
}


int main()
{
	int n,i,s,x,pts=15;
	n=1;
	int num[n]; 
	//FILE *pf=fopen("Busqueda_Terciaria.csv","at");
	for(i=0;i<pts;i++)
	{
		ctd=0;
		generar(num,n);
		imprimir(num,n);
		//busquedaternaria(num,0,n,&ctd);
		n+=5;	
		//cout<<"Numero de pasos: " <<ctd <<endl;
		//fprintf(pf,"%d,%d\n",n,ctd);
	}
	//fclose(pf);
}
