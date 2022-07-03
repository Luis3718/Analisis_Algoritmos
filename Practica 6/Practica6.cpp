/*
  La subsecuencia mas larga y su Big O 
  Instituto Politécnico Nacional
  ESCOM
  Alvarado Romero Luis Manuel
  Reyes Becerra Lizeth Angelica
  Materia: Analisis y diseño de Algoritmos
  Grupo: 3CV1
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#define tam 500
using namespace std;
int n,m;

void implementacionarchivo2(char p2[])
{
	FILE *Archivo;
	Archivo=fopen("Archivo2.txt","r");
	if(Archivo!=NULL)
	{
		fgets(p2,200,Archivo);
	}
	else
	{
		printf("Error al abrir archivo\n");
	}
	fclose(Archivo);
}

void implementacionarchivo(char p1[])
{
	FILE *Archivo;
	Archivo=fopen("Archivo1.txt","r");
	if(Archivo!=NULL)
	{
		fgets(p1,200,Archivo);
	}
	else
	{
		printf("Error al abrir archivo\n");
	}
	fclose(Archivo);
}

void encontrarcamino(char p1[],char p2[], int tabla[tam][tam], int n, int m, char sub[])
{
		int i=0;
		while(n>0 && m>0)
		{
			if(p1[n-1]==p2[m-1])
			{
				sub[i]+=p1[n-1];
				i++;
				n--;
				m--;
			}
			else
			{
				if(tabla[n-1][m]>=tabla[n][m-1])
				{
					n--;
				}
				else
				{
					m--;
				}
			}
		}
}

void subsecuencia(char p1[],char p2[], int tabla[tam][tam], int n, int m)
{
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<m;j++)
			{
				if(p1[i-1]==p2[j-1])
				{
					tabla[i][j]=tabla[i-1][j-1]+1;
				}
				else
				{
					if(tabla[i-1][j]>=tabla[i][j-1])
					{
						tabla[i][j]=tabla[i-1][j];
					}
					else
					{
						tabla[i][j]=tabla[i][j-1];
					}
				}
			}
		}
}

void Mostrar(int tabla[tam][tam],int n,int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			tabla[n][m]=1;
			printf("%d, ",tabla[i][j]);
		}
		printf("\n");
	}
}

void Alta(int tabla[tam][tam],int n,int m)
{
	for(int i=0;i<n;i++)
	{
		tabla[i][0]=0;
	}
	for(int j=0;j<m;j++)
	{
		tabla[0][j]=0;
	}
}

void eliminarduplicado(char p[])
{
	int i=0;
	while(p[i]!='\0')
	{
		p[i]=toupper(p[i]);
		i++;
	}
}

void eliminarespacios(char p1[],char p2[],int n,int m)
{
		int e=strlen(p1);
		int a=strlen(p2);
		int i=0;
		while(p1[i]!='\0')
		{
			if(p1[i]==' ')
			{
				for(int j=i;j<e;j++)
				{
					p1[j]=p1[j+1];
				}
				e--;
			}
			i++;
		}
		printf("Primera frase: \n");
		puts(p1);
		printf("\n");
		i=0;
		while(p2[i]!='\0')
		{
			if(p2[i]==' ')
			{
				for(int j=i;j<a;j++)
				{
					p2[j]=p2[j+1];
				}
				a--;
			}
			i++;
		}
		printf("Segunda frase: \n");
		puts(p2);
		printf("\n");
}

int main()
{
	int i=0,k=0,opc;
	int tabla[tam][tam];
	char p1[200];
	char p2[200];
	char sub[200];
	do
	{
		cout<<"1-Escribir las frases: \n2-Leer archivos \n3-salir\n";
		cout<<"Elija una opcion: \n";
		cin>>opc;
		fflush(stdin);
		switch (opc)
		{
			case 1:
							cout<<"Escriba la primer frase: ";
							gets(p1);
							fflush(stdin);
							cout<<"Escriba la segunda frase: ";
							gets(p2);
							fflush(stdin);
							printf("\n");
							n=strlen(p1);
							m=strlen(p2);
							eliminarduplicado(p1);
							eliminarduplicado(p2);
							eliminarespacios(p1,p2,n,m);
							n=strlen(p1);
							m=strlen(p2);
							tabla[n][m];
							printf("Tabla de coincidencias: \n");
							Alta(tabla,n,m);
							subsecuencia(p1,p2,tabla,n,m);
							Mostrar(tabla,n,m);
							encontrarcamino(p1,p2,tabla,n,m,sub);
							strrev(sub);
							printf("\nLa subsecuencia mas larga es: %s\n",sub);
							printf("\n");
			break;
			case 2:	implementacionarchivo(p1);
							implementacionarchivo2(p2);
							n=strlen(p1);
							m=strlen(p2);
							eliminarduplicado(p1);
							eliminarduplicado(p2);
							eliminarespacios(p1,p2,n,m);
							n=strlen(p1);
							m=strlen(p2);
							tabla[n][m];
							printf("Tabla de coincidencias: \n");
							Alta(tabla,n,m);
							subsecuencia(p1,p2,tabla,n,m);
							Mostrar(tabla,n,m);
							encontrarcamino(p1,p2,tabla,n,m,sub);
							strrev(sub);
							printf("\nLa subsecuencia mas larga es: %s\n",sub);
							printf("\n");
			break;
			case 3: printf("Adios\n");
			break;
		}
	}while(opc!=3);
}
