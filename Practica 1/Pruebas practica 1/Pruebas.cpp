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

void potencia(int num,int potencia,int *ctd)
{
	long int result=num; (*ctd)++;
	(*ctd)++;
	while(potencia>1)
	{
		(*ctd)++;
		result=result*num; (*ctd)++;
		potencia--; (*ctd)++;
		(*ctd)++;
	}	
}

void sumabinaria(int *num1,int *num2, int *res, int n, int *ctd)
{
	long int num=0; (*ctd)++;
	int i; (*ctd)++;
   	int llevo= 0; (*ctd)++;
   	long int r=0; (*ctd)++;
   	(*ctd)++;
	for(i=n+1;i>=1;i--) //Recorremos ambos arreglos binarios de atras para adelante para hacer la suma
	{
		(*ctd)++;
		(*ctd)++;
	   	if(num1[i-1] == 0 && num2[i-1] == 0) //evaluamos las condiciones para que se realice correctamente la suma 
		{
			(*ctd)++;
			(*ctd)++;
			(*ctd)++;
	      	if (llevo == 1)
			{
				(*ctd)++;
	         	res[i] = 1; (*ctd)++;
	            llevo = 0; (*ctd)++;
	        }
			else 
			{
				(*ctd)++;(*ctd)++;
	         	res[i] = 0; (*ctd)++;
	            llevo = 0; (*ctd)++;
	        }
	    }
	    (*ctd)++;
	    (*ctd)++;
	    if(num1[i-1] == 0 && num2[i-1] == 1)
		{
			(*ctd)++;
			(*ctd)++;
			(*ctd)++;
	      	if(llevo == 1)
			{
				(*ctd)++;
	            res[i] = 1; (*ctd)++;
	            llevo = 0; (*ctd)++;
	        }
	        else
			{
				(*ctd)++;(*ctd)++;
	         	res[i] = 1; (*ctd)++;
	            llevo = 0; (*ctd)++;
	        }    
	    }
	    (*ctd)++;
	    (*ctd)++;
	    if(num1[i-1] == 1 && num2[i-1] == 0)
		{
			(*ctd)++;
			(*ctd)++;
			(*ctd)++;
	      	if(llevo == 1)
			{
				(*ctd)++;
	            res[i] = 0; (*ctd)++;
	            llevo = 1; (*ctd)++;
	        }
	        else
			{
				(*ctd)++;(*ctd)++;
	         	res[i] = 1; (*ctd)++;
	            llevo = 0; (*ctd)++;
	        }
	    }
	    (*ctd)++;
	    (*ctd)++;
	    if(num1[i-1] == 1 && num2[i-1] == 1)
		{
			(*ctd)++;
			(*ctd)++;
			(*ctd)++;
	      	if(i==1)
			{
				(*ctd)++;
				(*ctd)++;
	         	if(llevo == 1)
				{
					(*ctd)++;
	               	res[i] = 1; (*ctd)++;
	               	res[0] = 1; (*ctd)++;
	         	}
	            else
				{
					(*ctd)++;(*ctd)++;
	            	res[i] = 0; (*ctd)++;
	               	res[0] = 1; (*ctd)++;
	         	}
	        }
	        else
			{
				(*ctd)++;(*ctd)++;
				(*ctd)++;
	         	if(llevo == 1)
				{
					(*ctd)++;
	               	res[i] = 1; (*ctd)++;
	            	llevo = 1; (*ctd)++;
	         	}
	            else
				{
					(*ctd)++;
					(*ctd)++;
	            	res[i] = 0; (*ctd)++;
	            	llevo = 1; (*ctd)++;
	         	}
	         }
	      }
	      (*ctd)++;
	      (*ctd)++;
    }
    (*ctd)++;
    (*ctd)++;
   	for(i=0;i<=n+1;i++) //recorremos el arreglo resultante de nuestra suma
   	{
   		(*ctd)++;
		cout<<res[i]; (*ctd)++;
		(*ctd)++;
   	}
   	(*ctd)++;
   	(*ctd)++;
   	int resu; (*ctd)++;
   	for(i=n+1;i>=1;i--)
	{
		(*ctd)++;
		(*ctd)++;
   		if(res[i]==1)
		{
			(*ctd)++;
			(*ctd)++;
			int potencia=r,result; (*ctd)++;
			(*ctd)++;
			while(potencia>1)
			{
				(*ctd)++;
				result=result*num; (*ctd)++;
				potencia--; (*ctd)++;
				(*ctd)++;
			}	
			num+=pow(2,r); (*ctd)++;   
		}
		(*ctd)++;
		r++; (*ctd)++;
		(*ctd)++;
   	}
   	(*ctd)++; 	
   	cout<<"\nEl numero en decimal es: " <<num; (*ctd)++;
}

void generar(int *num1, int *num2, int n)
{
	int m=n;
	srand(time(NULL));
 	for(int i=0; i<=n; i++)
 	{
 		num1[i]=rand()%2;
   	}
   	for(int k=0; k<=m; k++)
 	{
		num2[k]=rand()%2;
   	}
}

void imprimir(int *num1 ,int *num2,int n)
{
	cout<<"\nEl arreglo 1 es: \n";
   	for(int i=0;i<=n;i++)
	{
   		cout<<num1[i];
   	}
   	cout<<"\nEl arreglo 2 es: \n";
   	for(int j=0;j<=n;j++)
	{
		cout<<num2[j];
   	}
   	cout<<"\nResultado: \n";
}

void euclides(int n1, int n2,int *ctd)
{	
	int r; (*ctd)++;
	while(n2!=0)
	{
		(*ctd)++;
		r=n1%n2; (*ctd)++;
		n1=n2; (*ctd)++;
		n2=r;(*ctd)++;	
	}
	(*ctd)++;
	(*ctd)++;
	cout<<"\n El MCD segun el algoritmo de euclides es: \n"; (*ctd)++;
	cout<<n1; (*ctd)++;
}

int main(){
	int n,i,n1,n2,division,residuo,x,ctd,p; 
	//int fibo[17]={2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181};
	int pts=20;
	int pts2=15;
	int *num1,*num2,*res;
	FILE *pf=fopen("Suma_binaria.csv","at");
	FILE *pd=fopen("Euclides.csv","at");
	n=10;
	p=10;
	for(i=0;i<pts;i++)
	{
		ctd=0;
		num1 =  (int *) calloc(n, sizeof(int));
		num2 =  (int *) calloc(n, sizeof(int));
		res =  (int *) calloc((n+1), sizeof(int));	
		if (num1  == NULL) 
		{
			return 0;
		}
		if (num2  == NULL) 
		{
			return 0;
		}
		if (res  == NULL) 
		{
			return 0;
		}
		generar(num1,num2,n);
		imprimir(num1,num2,n);
	   	sumabinaria(num1,num2,res,n,&ctd);
		n+=10;	
		cout<<"\nNumero de pasos: " <<ctd;
		fprintf(pf,"%d,%d\n",n,ctd);
	}
	for(i=0;i<pts2;i++)
	{
		ctd=0;
		n1=1;
		n2=3;
		//n1=fibo[i];
		//n2=fibo[i+1];
		euclides(n1,n2,&ctd);
		p+=10;
		cout<<"\nNumero de pasos: " <<ctd;
		fprintf(pd,"%d,%d\n",p,ctd);
	}
	fclose(pf);
	fclose(pd);
}
