/*
  Instituto Politécnico Nacional
  ESCOM
  Alvarado Romero Luis Manuel
  Reyes Becerra Lizeth Angelica
  Materia: Analisis y diseño de Algoritmos
  Grupo: 3CV1
*/
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#define tam 32
using namespace std;
int di,i,j,t,ini,fin,ctd;
char a[tam][tam],b[tam][tam],c[tam][tam],d[tam][tam];

int unir(char matriz[tam][tam],int t,int *ctd)
{
	char n[t][t]; (*ctd)++;
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
		for(j=0;j<t;j++)
		{
			(*ctd)++;
			cout<<n[i][j]; (*ctd)++;
			(*ctd)++;
		}
		(*ctd)++;
	}
	(*ctd)++;
}

int rotar(char matriz[tam][tam],int t, int ini, int fin,int inic, int finc,int *ctd)
{
	di=t*2; (*ctd)++;
	char a[tam][tam],b[tam][tam],c[tam][tam],d[tam][tam]; (*ctd)++;
	(*ctd)++;
	if(di==tam)
	{
		(*ctd)++;
		(*ctd)++;
		for(i=0+ini;i<di+fin;i++)
		{
			(*ctd)++;
			for(j=0+inic;j<di+finc;j++)
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
		for(i=0+ini;i<di+fin;i++)
		{
			(*ctd)++;
			for(j=0+inic;j<di+finc;j++)
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
int dividirmatriz(char matriz[tam][tam], int t, int ini, int fin, int inic, int finc,int cuadrante,int *ctd)
{	
	di=t/2; (*ctd)++;
	ini=ini/2; 	(*ctd)++;
	inic=inic/2; 	(*ctd)++;
	fin=fin/2; 	(*ctd)++;
	finc=finc/2; 	(*ctd)++;
	char a[tam][tam],b[tam][tam],c[tam][tam],d[tam][tam]; 	(*ctd)++;
	(*ctd)++;
	if(di>=2)
	{
		(*ctd)++;
		for(i=0+ini;i<di+fin;i++)
		{
			(*ctd)++;
			for(j=0+inic;j<di+finc;j++)
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
		for(i=0;i<di;i++) (*ctd)++;
		{ 
			(*ctd)++;
			(*ctd)++;
			for(j=0;j<di;j++) 
			{ 
				(*ctd)++;
				cout<<a[i][j]; (*ctd)++;
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
			(*ctd)++;
			for(j=0;j<di;j++)
			{
				(*ctd)++;
				cout<<b[i][j]; (*ctd)++;
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
			(*ctd)++;
			for(j=0;j<di;j++)
			{
				(*ctd)++;
				cout<<c[i][j]; (*ctd)++;
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
			(*ctd)++;
			for(j=0;j<di;j++)
			{
				(*ctd)++;
				cout<<d[i][j]; (*ctd)++;
			}
			(*ctd)++;
		}
		(*ctd)++;
		(*ctd)++;
		if(cuadrante==1)
		{
			dividirmatriz(a,di,ini,fin,inic,finc,1,ctd); (*ctd)++;
			rotar(a,di,ini,fin,inic,finc,ctd); (*ctd)++;
		} 
		(*ctd)++;
		if(cuadrante==2)
		{
			dividirmatriz(b,di,ini,fin,inic,finc,2,ctd); (*ctd)++;	
			rotar(b,di,ini,fin,inic,finc,ctd); (*ctd)++;
		}
		(*ctd)++;
		if(cuadrante==3)
		{
			dividirmatriz(c,di,ini,fin,inic,finc,3,ctd); (*ctd)++;	
			rotar(c,di,ini,fin,inic,finc,ctd); (*ctd)++;
		}
		(*ctd)++;
		if(cuadrante==4)
		{
			dividirmatriz(d,di,ini,fin,inic,finc,4,ctd); (*ctd)++;
			rotar(d,di,ini,fin,inic,finc,ctd); 	(*ctd)++;
		}
	}
	(*ctd)++;
}

int main()
{
	FILE *pf=fopen("Matriz.csv","at");
	FILE *fptr;
	t=tam;
	char matriz[tam][tam];
	fptr = fopen("ascii8.txt", "r+t");
	for(i=0;i<t;i++)
	{
		for(j=0;j<t;j++)
		{
			fscanf(fptr, "%c", &matriz[i][j]);
		}
	}
	for(i=0;i<t;i++)
	{
		for(j=0;j<t;j++)
		{
			cout<<matriz[i][j];
		}
	}
	dividirmatriz(matriz,t,0,0,0,0,1,&ctd);
	dividirmatriz(matriz,t,0,0,0,0,2,&ctd);
	dividirmatriz(matriz,t,0,0,0,0,3,&ctd);
	dividirmatriz(matriz,t,0,0,0,0,4,&ctd);
	cout<<endl <<"Matriz Rotada" <<endl;
	unir(matriz,t,&ctd);
	cout<<"\nNumero de pasos: " <<ctd <<endl;
	fprintf(pf,"%d,%d\n",tam,ctd);
	fclose(pf);
}
