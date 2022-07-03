/*
  Rotar una matriz de NxN donde n es par 
  y su Big O
  Instituto Polit�cnico Nacional
  ESCOM
  Alvarado Romero Luis Manuel
  Reyes Becerra Lizeth Angelica
  Materia: Analisis y dise�o de Algoritmos
  Grupo: 3CV1
*/
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#define tam 16
using namespace std;
int di,i,j,t,ini,fin,ctd;
int a[tam][tam],b[tam][tam],c[tam][tam],d[tam][tam];

int mostrar(int matriz[tam][tam],int t,int *ctd)
{
	int n[t][t]; (*ctd)++;
	(*ctd)++;
	for(i=0;i<t;i++)
	{
		(*ctd)++;
		for(j=0;j<t;j++)
		{
			(*ctd)++;
			n[i][j]=matriz[j][i]; (*ctd)++;
			(*ctd)++;
		}
		(*ctd)++;
	}
	(*ctd)++;
	for(i=0;i<t;i++)
	{
		(*ctd)++;
		cout<<endl; (*ctd)++;
		for(j=0;j<t;j++)
		{
			(*ctd)++;
			cout<<n[i][j]; (*ctd)++;
			cout<<", "; (*ctd)++;
			(*ctd)++;
		}
		(*ctd)++;
	}
	(*ctd)++;
}

int unir(int matriz[tam][tam],int t,int *ctd)
{
	di=t*2; (*ctd)++;
	int a[tam][tam],b[tam][tam],c[tam][tam],d[tam][tam]; (*ctd)++;
	(*ctd)++;
	if(di==tam)
	{
		(*ctd)++;
		(*ctd)++;
		for(i=0;i<di;i++)
		{
			(*ctd)++;
			for(j=0;j<di;j++)
			{
				(*ctd)++;
				a[i][j]=a[j][i]; (*ctd)++;
				b[i][j]=b[j][i]; (*ctd)++;
				c[i][j]=c[j][i]; (*ctd)++;
				d[i][j]=d[j][i]; (*ctd)++;
			}
			(*ctd)++;
		}
		(*ctd)++;
		(*ctd)++;
		for(i=0;i<di;i++)
		{
			(*ctd)++;
			for(j=0;j<di;j++)
			{
				(*ctd)++;
				matriz[i][j]=a[i][j]; (*ctd)++;
				matriz[i][j+di]=b[i][j]; (*ctd)++;
				matriz[i+di][j]=c[i][j]; (*ctd)++;
				matriz[i+di][j+di]=d[i][j]; (*ctd)++;
				(*ctd)++;
			}
			(*ctd)++;
		}
	}
	(*ctd)++;
}
int dividirmatriz(int matriz[tam][tam], int t, int cuadrante,int *ctd)
{	
	di=t/2; (*ctd)++;
	int a[tam][tam],b[tam][tam],c[tam][tam],d[tam][tam]; 	(*ctd)++;
	(*ctd)++;
	if(di>=2)
	{
		(*ctd)++;
		for(i=0;i<di;i++)
		{
			(*ctd)++;
			for(j=0;j<di;j++)
			{
				(*ctd)++;
				a[i][j]=matriz[i][j]; (*ctd)++;
				b[i][j]=matriz[i][j+di]; (*ctd)++;
				c[i][j]=matriz[i+di][j]; (*ctd)++;
				d[i][j]=matriz[i+di][j+di]; (*ctd)++;
			}
			(*ctd)++;
		}
		(*ctd)++;
		cout<<endl; (*ctd)++;
		cout<<"Matriz A" <<endl; (*ctd)++;
		(*ctd)++;
		for(i=0;i<di;i++)
		{
			(*ctd)++;
			cout<<endl; (*ctd)++;
			(*ctd)++;
			for(j=0;j<di;j++)
			{
				(*ctd)++;
				cout<<a[i][j]; (*ctd)++;
				cout<<", "; (*ctd)++;
			}
			(*ctd)++;
		}
		(*ctd)++;
		cout<<endl; (*ctd)++;
		cout<<"Matriz B" <<endl; (*ctd)++;
		(*ctd)++;
		for(i=0;i<di;i++)
		{
			(*ctd)++;
			cout<<endl; (*ctd)++;
			(*ctd)++;
			for(j=0;j<di;j++)
			{
				(*ctd)++;
				cout<<b[i][j]; (*ctd)++;
				cout<<", "; (*ctd)++;
			}
			(*ctd)++;
		}
		(*ctd)++;
		cout<<endl; (*ctd)++;
		cout<<"Matriz C" <<endl; (*ctd)++;
		(*ctd)++;
		for(i=0;i<di;i++)
		{
			(*ctd)++;
			cout<<endl; (*ctd)++;
			(*ctd)++;
			for(j=0;j<di;j++)
			{
				(*ctd)++;
				cout<<c[i][j]; (*ctd)++;
				cout<<", "; (*ctd)++;
			}
			(*ctd)++;
		}
		(*ctd)++;
		cout<<endl; (*ctd)++;
		cout<<"Matriz D" <<endl; (*ctd)++;
		(*ctd)++;
		for(i=0;i<di;i++)
		{
			(*ctd)++;
			cout<<endl; (*ctd)++;
			(*ctd)++;
			for(j=0;j<di;j++)
			{
				(*ctd)++;
				cout<<d[i][j]; (*ctd)++;
				cout<<", "; (*ctd)++;
			}
			(*ctd)++;
		}
		(*ctd)++;
		(*ctd)++;
		if(cuadrante==1)
		{
			dividirmatriz(a,di,1,ctd); (*ctd)++;
			unir(a,di,ctd); (*ctd)++;
		} 
		(*ctd)++;
		if(cuadrante==2)
		{
			dividirmatriz(b,di,2,ctd); (*ctd)++;	
			unir(b,di,ctd); (*ctd)++;
		}
		(*ctd)++;
		if(cuadrante==3)
		{
			dividirmatriz(c,di,3,ctd); (*ctd)++;	
			unir(c,di,ctd); (*ctd)++;
		}
		(*ctd)++;
		if(cuadrante==4)
		{
			dividirmatriz(d,di,4,ctd); (*ctd)++;
			unir(d,di,ctd); (*ctd)++;
		}
	}
	(*ctd)++;
}

int main()
{
	FILE *pf=fopen("Matriz.csv","at");
	t=tam;
	int matriz[tam][tam];
	for(i=0;i<t;i++)
	{
		for(j=0;j<t;j++)
		{
			matriz[i][j]=rand()%10;
		}
	}
	for(i=0;i<t;i++)
	{
		cout<<endl;
		for(j=0;j<t;j++)
		{
			cout<<matriz[i][j];
			cout<<", ";
		}
	}
	dividirmatriz(matriz,t,1,&ctd);
	dividirmatriz(matriz,t,2,&ctd);
	dividirmatriz(matriz,t,3,&ctd);
	dividirmatriz(matriz,t,4,&ctd);
	cout<<endl <<"Matriz Rotada" <<endl;
	mostrar(matriz,t,&ctd);
	cout<<"\nNumero de pasos: " <<ctd <<endl;
	fprintf(pf,"%d,%d\n",tam,ctd);
	fclose(pf);
}
