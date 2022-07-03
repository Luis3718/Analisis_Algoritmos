//Alvarado Romero Luis Manuel
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void ordenburbuja(int *num,int n,int *cont)
{
	int i,j,buffer; (*cont)++;
	(*cont)++;
	for (i=0;i<n;i++) 
    {	
		(*cont)++; 
  		for (j=i+1;j<n;j++) 
        { 
        	(*cont)++;
        	(*cont)++;
      		if (num[j]<num[i]) 
      		{
			  	(*cont)++;	 	 
        		buffer=num[j]; (*cont)++;
        		num[j]=num[i]; (*cont)++;
        		num[i]=buffer; (*cont)++; 
        	}
			(*cont)++;
		(*cont)++;	 
        }
	(*cont)++;	 
    (*cont)++;
	} 
	(*cont)++;
}

int main() 
{   
	int i,j,buffer,n,cont,pasos;
	int *num;
	num =  (int *) calloc(n, sizeof(int));	
	if (num  == NULL) 
	{
		return 0;
	}
	pasos=15;
	FILE *pc=fopen("Orden_burbuja.csv","at");
	n=5;
	for(int k=0;k<pasos;k++)
	{
		cont=0;
		srand(time(NULL));
		for(int i=0; i<n; i++)
	 	{
	 		num[i]=14;
	   	}
	   	ordenburbuja(num,n,&cont);
		for (int i=0;i<n;i++) 
	  	{ 
	    	cout<<num[i];
			if(i!=(n-1))
			{	
				cout<<",";	
			} 
	  	}
		n+=5;
		cout<<"\nNumero de pasos: " <<cont;
		cout<<endl;
		fprintf(pc,"%d,%d\n",n,cont);
	}
	fclose(pc);
	/*ordenamiento por burbuja
	for (i=0;i<n;i++) 
    { 
  		for (j=i+1;j<n;j++) 
        { 
      		if (num[j]<num[i]) 
      		{	 	 
        		buffer=num[j]; 
        		num[j]=num[i]; 
        		num[i]=buffer; 
        	} 
        } 
    }*/ 
	return 0;
}
