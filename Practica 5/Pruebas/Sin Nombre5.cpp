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
int i,j,sum,ctd;

void merge(int *array, int p, int q, int r,int *ctd)
{
    int i, j, k; (*ctd)++;
    int n_1 = (q - p) + 1; (*ctd)++;
    int n_2 = (r - q); (*ctd)++;
    int *L, *R; (*ctd)++;
    L = (int*)malloc(n_1 * sizeof(int)); (*ctd)++;
    R = (int*)malloc(n_2 * sizeof(int)); (*ctd)++;
    (*ctd)++;
	for (i = 0; i < n_1; i++) 
    {
    	(*ctd)++;
        L[i] = *(array + p + i); (*ctd)++;
        (*ctd)++;
    }
    (*ctd)++;
    (*ctd)++;
    for (j = 0; j < n_2; j++)
    {
    	(*ctd)++;
        R[j] = *(array + q + j + 1); (*ctd)++;
    	(*ctd)++;
	}
    (*ctd)++;
    i = 0; (*ctd)++;
    j = 0; (*ctd)++;
    (*ctd)++;
    for (k = p; k < r + 1; k++)
    {
    	(*ctd)++;
    	(*ctd)++;
        if (i == n_1)
        {
        	(*ctd)++;
            *(array + k) = *(R + j); (*ctd)++;
            j =  j+ 1; (*ctd)++;
        }
        else if(j == n_2)
        { 
        	(*ctd)++;
            *(array + k) = *(L + i); (*ctd)++;
            i = i + 1; (*ctd)++;
        }
        else
        {
        	(*ctd)++;
            if (*(L + i) <= *(R + j))
            {
            	(*ctd)++;
                *(array + k) = *(L + i); (*ctd)++;
                i = i + 1; (*ctd)++;
            }
            else
            {
            	(*ctd)++;
                *(array + k) = *(R + j); (*ctd)++;
                j = j + 1; (*ctd)++;
            }
        }
    }
}

void merge_sort(int *array, int p, int r, int *ctd)
{
	(*ctd)++;
    if (p < r)
    {
    	(*ctd)++;
        int q = (p + r)/2; (*ctd)++;
        merge_sort(array, p, q,ctd); (*ctd)++;
        merge_sort(array, q + 1, r,ctd); (*ctd)++;
        merge(array, p, q, r,ctd); (*ctd)++;
    }
    (*ctd)++;
}

int generararreglo(int *c, int n,int *ctd)
{
	c[0]=0; (*ctd)++;
	(*ctd)++;
	for(i=1;i<=n;i++)
	{
		(*ctd)++;
		c[i]=1+rand()%250; (*ctd)++;
		(*ctd)++;
	}
	(*ctd)++;
	merge_sort(c,0,n,ctd); (*ctd)++;
	(*ctd)++;
	for(i=0;i<n;i++)
	{
		(*ctd)++;
		cout<<c[i] <<", "; (*ctd)++;
		(*ctd)++; 
	}
	cout<<endl; (*ctd)++;
}

int granjero(int *c, int *s, int n, int f, int *ctd)
{
	j=0; (*ctd)++;
	cout<<"Fertilizante: " <<f <<endl; (*ctd)++;
	(*ctd)++;
	for(i=1;i<n;i++)
	{
		(*ctd)++;
		(*ctd)++;
		if(c[i]>=sum)
		{
			(*ctd)++;
			sum=f+c[i-1]; (*ctd)++;
			cout<<"Nuevo fertilizante: " <<sum <<endl; (*ctd)++;
			s[j]=c[i-1]; (*ctd)++;
			j++; (*ctd)++;
		}
		(*ctd)++;
	}
	(*ctd)++;
	if(c[n-1]<=sum)
	{
		s[j]=c[n-1];	(*ctd)++;
	}
	(*ctd)++;
	cout<<"Arreglo solucion" <<endl;
	for(i=0;i<j+1;i++)
	{
		(*ctd)++;
		cout<<s[i] <<", "; (*ctd)++;
		(*ctd)++;
	}
	(*ctd)++;
}

int main()
{
	srand (time(NULL));
	int n;
	int s[n];
	//int c[n];
	int f=30;
	n=10;
	int c[]={0,29,36,50,52,66,71,85,100,117,127,129,135,146,150,180};
	//generararreglo(c,n);
	granjero(c,s,n,f,&ctd);
	cout<<"\nNumero de pasos: " <<ctd;
}
