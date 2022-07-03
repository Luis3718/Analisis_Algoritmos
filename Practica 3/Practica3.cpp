/*
  Busqueda binaria, busqueda ternaria 
  tipos de divisiones y su Big O
  Instituto Polit�cnico Nacional
  ESCOM
  Alvarado Romero Luis Manuel
  Reyes Becerra Lizeth Angelica
  Materia: Analisis y dise�o de Algoritmos
  Grupo: 3CV1
*/
#include <stdio.h>
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
	cout<<"\nNumero no encontrado"; (*ctd)++;
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

int main(){
	int n,i,s,pts=15;
	int *num1; 
	FILE *pf=fopen("Division1.csv","at");
	FILE *pd=fopen("Division2.csv","at");
	FILE *ps=fopen("Division3.csv","at");
	FILE *pr=fopen("Busqueda ternarea.csv","at");
	FILE *pq=fopen("Busqueda ternarea recursiva.csv","at");
	srand(time(NULL));
	n=rand()%75;
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
		busquedaternaria(num1,n,n,&ctd);
		n+=10;	
		cout<<"\nNumero de pasos: " <<ctd;
		fprintf(pr,"%d,%d\n",n,ctd);
		free(num1);
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
		busquedaternariar(num1,n,0,n,&ctd);
		n+=10;	
		cout<<"\nNumero de pasos: " <<ctd;
		fprintf(pq,"%d,%d\n",n,ctd);
		free(num1);
	}
	fclose(pr);
	fclose(pf);
	fclose(pd);
	fclose(ps);
	fclose(pq);
}
