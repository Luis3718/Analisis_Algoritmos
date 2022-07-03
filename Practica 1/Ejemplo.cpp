#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int oper1[15]={1,0,1,0,0,0,1,1,0,0,0,1,0,1,0};
int oper2[15]={1,1,0,0,1,1,1,1,1,0,0,1,0,1,1};
int result[16];

void suma(){
	int i;
   	int acarreo = 0;
	for(i=0;i<=16;i++){
		result[i]=0;
   }
	for(i=16;i>=1;i--){
   	if (oper1[i-1] == 0 && oper2[i-1] == 0){
      	if (acarreo == 1){
         	result[i] = 1;
            acarreo = 0;
         }
         else{
         	result[i] = 0;
            acarreo = 0;
         }
      }
      if (oper1[i-1] == 0 && oper2[i-1] == 1){
      	if(acarreo == 1){
            result[i] = 1;
            acarreo = 0;
         }
         else{
         	result[i] = 1;
            acarreo = 0;
         }
      }
      if (oper1[i-1] == 1 && oper2[i-1] == 0){
      	if(acarreo == 1){
            result[i] = 0;
            acarreo = 1;
         }
         else{
         	result[i] = 1;
            acarreo = 0;
         }
      }
      if (oper1[i-1] == 1 && oper2[i-1] == 1){
      	if(i==1){
         	if(acarreo == 1){
               result[i] = 1;
               result[0] = 1;
         	}
            else{
            	result[i] = 0;
               result[0] = 1;
         	}
         }
         else{
         	if(acarreo == 1){
               result[i] = 1;
            	acarreo = 1;
         	}
            else{
            	result[i] = 0;
            	acarreo = 1;
         	}
         }
      }
   }
   for(i=0;i<=16;i++){
		printf("%d",result[i]);
   }
}

int main(){
	int i,j;
   /*
   for(i=0;i<=7;i++){
   	oper1[i]=0;
      oper2[i]=0;
      oper3[i]=0;
   }
   */
   /*for(i=0;i<=7;i++){
   	printf("Introduce el %d digito del operando 1: ",i+1);
   	//scanf("%d",&oper1[i]);
      cin>>oper1[i];
      if (oper1[i] == 1 || oper1[i] == 0){
      	i = i;
      }
      else {
      	i--;
      }
   }
   printf("Operando uno es: ");
   for(i=0;i<=7;i++){
   	printf("%d",oper1[i]);
   }
   //printf("\n");
   //getch();
   for(j=0;j<=7;j++){
   	printf("Introduce el %d digito del operando 2: ",j+1);
   	//scanf("%d",&oper2[j]);
      cin>>oper2[j];
      if (oper2[j] == 1 || oper2[j] == 0){
      	j = j;
      }
      else {
      	j--;
      }
   }*/
   printf("Operando uno es:  ");
   for(i=0;i<=15;i++){
   	printf("%d",oper1[i]);
   }
   printf("\nOperando dos es:  ");
   for(j=0;j<=15;j++){
   	printf("%d",oper2[j]);
   }
   printf("\nResultado:       ");
   suma();
}
