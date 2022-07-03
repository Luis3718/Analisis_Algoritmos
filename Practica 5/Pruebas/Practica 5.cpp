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
int i,j,sum;
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
}

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
	n=16;
	int c[]={0,29,36,50,52,66,71,85,100,117,127,129,135,146,150,180};
	//generararreglo(c,n);
	granjero(c,s,n,f);
}
