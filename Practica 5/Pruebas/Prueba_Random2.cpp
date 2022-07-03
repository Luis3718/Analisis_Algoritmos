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
#include<time.h>
using namespace std;
int i,j,sum,x,num;

generararreglo(int *c, int n)
{
	c[0]=0;
	x=rand()%10;
	for(i=1;i<n;i++)
	{
		x+=num=1+rand()%20;
		c[i]=x;
		if(c[i]<c[i-1] and i-1!=0)
		{
			c[i]=x+rand()%20;
			i--;	
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<c[i] <<", "; 
	}
	cout<<endl;
}
/*
imprimir(int *c, int *s,int n)
{
	cout<<"Arreglo de dias: " <<endl;
	for(i=0;i<n;i++)
	{
		cout<<c[i] <<", "; 
	}
	cout<<endl;
	cout<<"Arreglo solucion: " <<endl;
	for(i=0;i<n;i++)
	{
		cout<<s[i] <<", "; 
	}
	cout<<endl;	
}
generararreglo(int *c, int n)
{
	c[0]=0;
	for(i=1;i<=n;i++)
	{
		c[i]=5+rand()%125;
		if(c[i]<c[i-1] and i-1!=0)
		{
			c[i]=5+rand()%100;
			i--;	
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<c[i] <<", "; 
	}
	cout<<endl;
}*/

granjero(int *c, int *s, int n, int f)
{
	j=0;
	//s[0]=0;
	cout<<"Fertilizante: " <<f <<endl;
	for(i=1;i<n;i++)
	{
		cout<<"indice: " <<c[i] <<endl;
		if(c[i]>=sum)
		{
			sum=f+c[i-1];
			cout<<"Nuevo fertilizante: " <<sum <<endl;
			s[j]=c[i-1];
			j++;	
		}
	}
	if(c[n-1]<=sum)
	{
		s[j]=c[n-1];	
	}
	cout<<"Arreglo solucion" <<endl;
	for(i=0;i<j+1;i++)
	{
		cout<<s[i] <<", "; 
	}
}

int main()
{
	srand (time(NULL));
	int n;
	int s[n];
	//int c[n];
	int f=30;
	n=10;
	int c[]={0,29,31,40,45,46,70,85,100,117,133,159};
	//cout<<"Arreglo de dias: " <<endl;
	//generararreglo(c,n);
	cout<<endl;
	granjero(c,s,n,f);
}
