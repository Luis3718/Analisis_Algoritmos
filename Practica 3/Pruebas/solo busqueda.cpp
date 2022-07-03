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

int busquedaternariar(int *num1, int x, int ini, int fin, int *ctd)
{
	(*ctd)++;
	if(ini<fin)
	{
		(*ctd)++;
		int i1=(ini+fin)/3; (*ctd)++;
		int i2=(i1+1+fin)/2; (*ctd)++;
		if(num1[i1]==x)
		{
			(*ctd)++;
			(*ctd)++;
			(*ctd)++;
			cout<<"Numero encontrado" <<num1[i1] <<endl;
			return 0; 
		}
		else
		{
			(*ctd)++;
			if(x<num1[i1])
			{
				(*ctd)++;
				(*ctd)++;
				return busquedaternariar(num1,x,ini,i1,ctd);
			}
			else
			{
				(*ctd)++;
				if(num1[i2]==x)
				{
					(*ctd)++;
					(*ctd)++;
					(*ctd)++;
					cout<<"Numero encontrado" <<num1[i2] <<endl;
					return 0;
				}
				else
				{
					(*ctd)++;
					if(x<num1[i2])
					{
						(*ctd)++;
						(*ctd)++;
						return busquedaternariar(num1,x,i1+1,i2,ctd);
					}
					else
					{
						(*ctd)++;
						if(num1[fin]==x)
						{
							(*ctd)++;
							(*ctd)++;
							(*ctd)++;
							cout<<"Numero encontrado" <<num1[fin] <<endl;
							return 0;	
						}
						else
						{
							(*ctd)++;
							return busquedaternariar(num1,x,i2+1,fin,ctd);
						}
					}
				}
			}
		}
	}
	else
	{
		(*ctd)++;
		(*ctd)++;
		cout<<"No se encontro el elemento" <<endl;
		return 0;
	}
}


int main()
{
	int n,i,s,x,pts=15;
	int *num1; 
	n=1;
	free(num1);
	FILE *pf=fopen("Busqueda_Terciaria.csv","at");
	/*for(i=0;i<pts;i++)
	{
		ctd=0;
		num1 =  (int *) calloc(n, sizeof(int));
		if (num1  == NULL) 
		{
			cout<<"Error al generar memoria" <<endl;
			return 0;
		}
		generar(num1,n);
		//imprimir(num1,n);
		busquedaternaria(num1,15,n,&ctd);
		n+=1;	
		cout<<"\nNumero de pasos: " <<ctd;
		fprintf(pf,"%d,%d\n",n,ctd);
	}
	for(i=0;i<6;i++)
	{
		num1 =  (int *) calloc(n, sizeof(int));
		if (num1  == NULL) 
		{
			cout<<"Error al generar memoria" <<endl;
			return 0;
		}
		generar(num1,n);
		imprimir(num1,n);
		busquedaternariar(num1,10,0,(n-1));
		n+=2;
		//cout<<"\nNumero de pasos: " <<ctd;
		//fprintf(pr,"%d,%d\n",n,ctd);
	}*/
	fclose(pf);
	free(num1);
	
}
