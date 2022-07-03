/*
  Ciclo Hamiltoneano y su Big O
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
using namespace std;
#define nodos 5
//#define nodos 20
int ctd;
/*
int matriza[nodos][nodos]=
{
  {0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //nodo 0
  {1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0}, //nodo 1
  {0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0}, //nodo 2
  {0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0}, //nodo 3
  {1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0}, //nodo 4
  {1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0}, //nodo 5
  {0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0}, //nodo 6
  {0,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0}, //nodo 7
  {0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0}, //nodo 8
  {0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0}, //nodo 9
  {0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0}, //nodo 10
  {0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0}, //nodo 11
  {0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1}, //nodo 12
  {0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0}, //nodo 13
  {0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0}, //nodo 14
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1}, //nodo 15
  {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0}, //nodo 16
  {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0}, //nodo 17
  {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1}, //nodo 18
  {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0}, //nodo 19
};

// certificados para la matriz de 20x20
int certificado[]={0,1,2,3,4,13,14,15,16,17,18,19,12,11,10,9,8,7,6,5,0}; //certificado que acepta
int certificado2[]={0,1,2,3,4,13,14,15,13,17,18,19,12,11,10,9,8,7,6,5,0}; //certificado lo rechaza
int certificado3[]={0,1,2,3,4,13,14,15,16,17,0,19,12,11,10,9,8,7,6,5,0}; //certificado lo rechaza
*/

int matriza[nodos][nodos]=
{
    {0,1,0,1,1}, //nodo 0
    {1,0,1,1,1}, //nodo 1
    {0,1,0,1,0}, //nodo 2
    {1,1,1,0,1}, //nodo 3
    {1,1,0,1,0} //nodo 4
};
// certidicados para la matriz de 5x5
int certificado1[]={0,1,2,3,4,0}; // certificado que acepta
int certificado2[]={4,3,2,1,0,4}; // certificado que acepta
int certificado3[]={4,3,2,1,0,4,5}; //certificado que rechaza
int certificado4[]={0,3,4,2,1,0}; // certificado que rechaza


void hamilton(int matriz[nodos][nodos], int certificado[nodos+1],int tam,int *ctd)
{
  int k=0,flag=0; (*ctd)++;
  printf("El tamanio del certificado es: %d\n",tam); (*ctd)++;
  (*ctd)++;
  for(int k=1;k<tam;k++)
  {
    (*ctd)++;
    (*ctd)++;
    for(int s=k+1;s<tam;s++)
    {
      (*ctd)++;
      (*ctd)++;
      if(certificado[k]==certificado[s])
      {
        (*ctd)++;
        printf("Econtre un duplicado %d y %d\n",certificado[k],certificado[s]); (*ctd)++;
        flag=1; (*ctd)++;
      }
      (*ctd)++;
      (*ctd)++;
    }
    (*ctd)++;
    (*ctd)++;
  }
  (*ctd)++;
  (*ctd)++;
  if(tam>nodos+1 || tam<nodos ||flag==1)
  {
    (*ctd)++;
    (*ctd)++;
    (*ctd)++;
    printf("El certificado no es un recorrido hamiltoneano\n"); (*ctd)++;
  }
  else
  {
    (*ctd)++;
    (*ctd)++;
    for(int i=0;i<nodos;i++)
    {
      (*ctd)++;
      printf("El primer indice es: %d el segundo indice es: %d\n",certificado[i],certificado[i+1]); (*ctd)++;
      (*ctd)++;
      if(matriz[certificado[i]][certificado[i+1]]==1)
      {
        (*ctd)++;
        printf("El nodo: %d tiene conexion con: %d\n",certificado[i],certificado[i+1]); (*ctd)++;
        k++; (*ctd)++;
        //printf("K vale: %d\n",k);
      }
      else
      {
        (*ctd)++;
        printf("El nodo: %d no tiene conexion con: %d\n",certificado[i],certificado[i+1]); (*ctd)++;
      }
      (*ctd)++;
    }
    (*ctd)++;
    (*ctd)++;
    if(tam-1==k)
    {
      (*ctd)++;
      printf("El certificado si es un ciclo hamiltoneano\n"); (*ctd)++;
    }
    else
    {
      (*ctd)++;
      printf("El certificado no es es un ciclo hamiltoneano\n");
    }
  }
}

void mostrarmatriz(int Grafo[nodos][nodos],int *ctd)
{
  printf("Matriz de adyacencia: \n"); (*ctd)++;
  (*ctd)++;
  for (int i=0;i<nodos;i++)
  {
    (*ctd)++;
    (*ctd)++;
    for (int j=0; j<nodos;j++)
    {
      (*ctd)++;
      printf("%d, ",Grafo[i][j]); (*ctd)++;
      (*ctd)++;
    }
    (*ctd)++;
    printf("\n"); (*ctd)++;
    (*ctd)++;
  }
  (*ctd)++;
}

int main()
{
  int n=0;
  FILE *pq=fopen("Ciclo hamilton.csv","at");
  ctd=0;

  //pruebas de la matriz de 5x5
  mostrarmatriz(matriza,&ctd);
  printf("\n");
  int tam=sizeof(certificado1)/sizeof(certificado1[0]);
  hamilton(matriza,certificado1,tam,&ctd);
  printf("\n");
  n=1;
  int tam2=sizeof(certificado2)/sizeof(certificado2[0]);
  hamilton(matriza,certificado2,tam2,&ctd);
  printf("\n");
  n=2;
  int tam3=sizeof(certificado3)/sizeof(certificado3[0]);
  hamilton(matriza,certificado3,tam3,&ctd);
  printf("\n");
  n=3;
  int tam4=sizeof(certificado4)/sizeof(certificado4[0]);
  hamilton(matriza,certificado4,tam4,&ctd);
  n=4;

  /*
  //pruebas con la matriz de 20x20
  mostrarmatriz(matriza,&ctd);
  printf("\n");
  int tam=sizeof(certificado)/sizeof(certificado[0]);
  hamilton(matriza,certificado,tam,&ctd);
  printf("\n");
  n=5;
  int tam2=sizeof(certificado2)/sizeof(certificado2[0]);
  hamilton(matriza,certificado2,tam2,&ctd);
  printf("\n");
  n=6;
  int tam3=sizeof(certificado3)/sizeof(certificado3[0]);
  hamilton(matriza,certificado3,tam3,&ctd);
  printf("\n");
  */

  cout<<"\nNumero de pasos: " <<ctd;
	fprintf(pq,"%d,%d\n",n,ctd);
  fclose(pq);
}
