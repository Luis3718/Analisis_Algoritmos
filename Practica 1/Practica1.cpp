/*
  Suma binaria y su Big O
  Instituto Polit�cnico Nacional
  ESCOM
  Alvarado Romero Luis Manuel
  Reyes Becerra Lizeth Angelica
  Materia: Analisis y dise�o de Algoritmos
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

void suma(int *oper1,int *oper2, int *result, int n){
	int i,num=0;
   	int acarreo = 0;
	for(i=0;i<=n+1;i++)
	{
		result[i]=0;
   	}
	for(i=n+1;i>=1;i--){
	   	if(oper1[i-1] == 0 && oper2[i-1] == 0)
		{
	      	if (acarreo == 1)
			{
	         	result[i] = 1;
	            acarreo = 0;
	        }
	        else
			{
	         	result[i] = 0;
	            acarreo = 0;
	        }
	    }
	    if(oper1[i-1] == 0 && oper2[i-1] == 1)
		{
	      	if(acarreo == 1)
			{
	            result[i] = 1;
	            acarreo = 0;
	        }
	        else
			{
	         	result[i] = 1;
	            acarreo = 0;
	        }
	    }
	    if(oper1[i-1] == 1 && oper2[i-1] == 0)
		{
	      	if(acarreo == 1)
			{
	            result[i] = 0;
	            acarreo = 1;
	        }
	        else
			{
	         	result[i] = 1;
	            acarreo = 0;
	        }
	    }
	    if(oper1[i-1] == 1 && oper2[i-1] == 1)
		{
	      	if(i==1)
			{
	         	if(acarreo == 1)
				{
	               	result[i] = 1;
	               	result[0] = 1;
	         	}
	            else
				{
	            	result[i] = 0;
	               	result[0] = 1;
	         	}
	        }
	        else
			{
	         	if(acarreo == 1)
				{
	               	result[i] = 1;
	            	acarreo = 1;
	         	}
	            else
				{
	            	result[i] = 0;
	            	acarreo = 1;
	         	}
	         }
	      }
    }
   	for(i=0;i<=n+1;i++)
   	{
		printf("%d",result[i]);
   	}
   	for(i=n+1;i>=1;i--)
	{
   		if(result[i]==1)
		{
			num+=pow(i, 2);   
		}
   	}
   	printf("\n El numero en decimal es: %d",num);
}

generar(int *oper1,int *oper2,int n)
{
	srand(time(NULL));
 	for(int i=0; i<=n; i++)
 	{
 	    oper1[i]=rand()%2;
 	    oper2[i]=rand()%2;
   	}
}

int main(){
	int i,j;
	int n;
	int oper1[n];
	int oper2[n];
	int result[n+1];
	printf("Dame el tama�o de los arreglos: \n");
	scanf("%d",&n);
	generar(oper1,oper2,n);
   	printf("Operando uno es:  ");
   	for(i=0;i<=n;i++){
   	printf("%d",oper1[i]);
   	}
   	printf("\nOperando dos es:  ");
   	for(j=0;j<=n;j++)
	{
   	printf("%d",oper2[j]);
   	}
   	printf("\nResultado:       ");
   	suma(oper1,oper2,result,n);
}
