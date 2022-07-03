/*
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
int matriza[nodos][nodos]=
{
    {0,1,0,1,1},
    {1,0,1,1,1},
    {0,1,0,1,0},
    {1,1,1,0,1},
    {1,1,0,1,0}
};

int certificado1[]={0,1,2,3,4,0};
int certificado2[]={4,4,2,4,2,4};
int certificado3[]={4,3,2,1,0,4,5};
int certificado4[]={0,3,4,2,1,0};

void hamilton1(int matriz[nodos][nodos], int certificado[nodos+1],int tam)
{
  int k=0,flag=0;
  printf("El tamanio del certificado es: %d\n",tam);
  for(int k=1;k<tam;k++)
  {
    for(int s=k+1;s<tam;s++)
    {
      if(certificado[k]==certificado[s])
      {
        printf("Econtre un duplicado %d y %d\n",certificado[k],certificado[s]);
        flag=1;
      }
    }
  }
  if(tam>nodos+1 || tam<nodos ||flag==1)
  {
    printf("El certificado no es un recorrido hamiltoneano\n");
  }
  else
  {
    for(int i=0;i<nodos;i++)
    {
      printf("El primer indice es: %d el segundo indice es: %d\n",certificado[i],certificado[i+1]);
      if(matriz[certificado[i]][certificado[i+1]]==1)
      {
        printf("El nodo: %d tiene conexion con: %d\n",certificado[i],certificado[i+1]);
        k++;
        //printf("K vale: %d\n",k);
      }
      else
      {
        printf("El nodo: %d no tiene conexion con: %d\n",certificado[i],certificado[i+1]);
      }
    }
    if(tam-1==k)
    {
      printf("El certificado si es un ciclo hamiltoneano\n");
    }
    else
    {
      printf("El certificado no es es un ciclo hamiltoneano\n");
    }
  }
}

/*
void hamilton(int matriza[nodos][nodos],int certificado1[20])
{
    int k=0;
    int tam=(sizeof(certificado1)/sizeof(certificado1[0]));
    if(tam>nodos+1 || tam<nodos)
    {
      printf("No es un recorrido hamiltoneano\n");
    }
    else
    {
      for(int i=0;i<nodos;i++)
      {
        printf("El certificando apuntando a: %d\n",certificado1[i]);
        printf("%d\n",matriza[i][certificado1[i]]);
        if(matriza[i][certificado1[i]]==1)
        {
          printf("El nodo: %d tiene conexion con: %d\n",certificado1[i],cerficado1[i+1]);
          k++;
          printf("K vale: %d\n",k);
        }
        if(i==nodos-1)
        {
          if(matriza[i][certificado1[i+1]]==1)
          {
            printf("El nodo: %d tiene conexion con: %d\n",certificado1[i],cerficado1[i+1]);
            k++;
            printf("K vale: %d\n",k);
          }
        }
      }
    }
    if(((sizeof(certificado1)/sizeof(cerficado1[0]))-1)==k)
    {
      printf("El certificado si es un ciclo hamiltoneano\n");
    }
    else
    {
      printf("El certificado no es es un ciclo hamiltoneano\n");
    }
}*/

int main()
{
  printf("Grafo: \n");
  for (int i=0;i<nodos;i++)
  {
    for (int j=0; j<nodos;j++)
    {
      printf("%d, ",matriza[i][j]);
    }
    printf("\n");
  }
  int tam=sizeof(certificado1)/sizeof(certificado1[0]);
  printf("El tamaño es de: %d\n",sizeof(certificado1)/sizeof(certificado1[0]));
  hamilton1(matriza,certificado1,tam);
  printf("\n");
  int tam2=sizeof(certificado2)/sizeof(certificado2[0]);
  hamilton1(matriza,certificado2,tam2);
  printf("\n");
  int tam3=sizeof(certificado3)/sizeof(certificado3[0]);
  hamilton1(matriza,certificado3,tam3);
  printf("\n");
  int tam4=sizeof(certificado4)/sizeof(certificado4[0]);
  hamilton1(matriza,certificado4,tam4);
}
