#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //libreria para convertir a mayusculas la frase
#include <string.h> //comparar arreglos y encontrar longitudes

//creamos una estructura para el arbol
typedef struct Hoja
{
	char caracter;
	int frecuencia;
	struct Hoja *izquierda;
	struct Hoja *derecha;
}Arbol,Arbol2;

//Creamos una lista doblemente enlazada para almacenar las frecuencias
typedef struct Nodo
{
	char caracter;
	int frecuencia;
	char codificacion[8];
	struct Nodo *sig;
	struct Nodo *ant;
	struct Hoja *apuntadorarbol;
}Lista;

//Todo lo que utilizamos de listas
Lista* Crearnodo(char dato, int frecuencia,Arbol* apuntadorarbol);
Lista* Altainicio(Lista* Inicio, char dato, int frecuencia,Arbol* apuntadorarbol);
Lista* Altap(Lista* Inicio, int pos,char dato,int frecuencia,Arbol* apuntadorarbol);
Lista* Altafinal(Lista* Inicio,char dato,int frecuencia,Arbol* apuntadorarbol);

//Todo lo que se ocupa para la coidficacion de Huffman
Lista* Generarfrecuencias(char *frase); //contamos los carcteres de nuestra frase
Lista* Ordenar(Lista* Inicio); //ordenamos nuestra Lista
void Generararbol(Lista *Inicio, Lista *Inicioog, Arbol **Raiz); //generamos nuestro arbol a partir de nuestras frecuencias
Arbol* Crearhoja(char caracter, int frecuencia); //creamos las hojas de arbol
void Mostrararbol(Arbol *Raiz); //mostramos nuestro arbol preordenado
void Generarlistaarbol(Arbol *Raiz, Lista **Inicio);
void Creararchivoarbol(Arbol *Raiz, Lista *Inicio); //creamos un archivo para el arbol preordenado
void Codificar(Arbol *Raiz, char code[],Lista **Inicio, int i); //generamos los codigos de frecuencia variable de huffman con el arbol
void Mostrarcodigo(Lista *Inicio); //Mostramos los codigos conseguidos
void Codbinario(Lista *Codigos, char oracion[],char codb[],char codc[]);//comprimimos nuestra cadena final
void Creararchivocod(char codc[],char frase[]); //crea el archivo con el mensaje codificado

//Todo lo que necesitamos para Decodificar
Lista* Conseguirarbol();
Arbol2* Altaarbol(Lista **Inicio, Arbol* Arbol);
Arbol2* Generararbolp(Arbol* Raiz, Lista** Inicio);
void Leerarchivo(char palabra[]);
void Binarioleido(unsigned char cod[],unsigned char codbinario[]);
void Traermensaje(unsigned char codleido[],Lista* codc,char mensaje[]);

//Mostrar
void Mostrar(Lista* Inicio)
{
	int contador=0;
	if(Inicio==NULL)
	{
		printf("Lista Vacia \n");
	}
	else
	{
		printf("Caracter y frecuencia \n");
		while(Inicio!=NULL)
		{
			printf("%c: %d \n",Inicio->caracter,Inicio->frecuencia);
			contador++;
			Inicio=Inicio->sig;
		}
	}
}

//Tam
int Tam(Lista* Inicio)
{
	int contador=0;
	if(Inicio==NULL)
	{
		printf("Lista vacia \n");
	}
	else
	{
		while(Inicio->sig!=NULL)
		{
			contador++;
			Inicio=Inicio->sig;
		}
	}
	return contador;
}


Lista* Crearnodo(char dato, int frecuencia,Arbol* apuntadorarbol)
{
	Lista *Nuevonodo;
	Nuevonodo= (Lista*)malloc(sizeof(Lista));
	Nuevonodo->caracter=dato;
	Nuevonodo->frecuencia=frecuencia;
	Nuevonodo->sig=NULL;
	Nuevonodo->ant=NULL;
	Nuevonodo->apuntadorarbol=apuntadorarbol;
}

Arbol* Crearhoja(char caracter, int frecuencia)
{
	Arbol  *Nuevahoja;
	Nuevahoja=(Arbol*)malloc(sizeof(Arbol));
	Nuevahoja->caracter=caracter;
	Nuevahoja->frecuencia=frecuencia;
	Nuevahoja->izquierda=NULL;
	Nuevahoja->derecha=NULL;
}

Lista* Altainicio(Lista* Inicio, char dato, int frecuencia,Arbol* apuntadorarbol)
{
	Lista* Nuevo;
	Nuevo=Crearnodo(dato,frecuencia,apuntadorarbol);
	if(Inicio==NULL)
	{
		Inicio = Nuevo;
	}
	else
	{
		Nuevo->sig=Inicio;
		Inicio->ant=Nuevo;
		Inicio=Nuevo;
	}
	return Inicio;
}

Lista* Altap(Lista* Inicio, int pos, char dato, int frecuencia,Arbol* apuntadorarbol)
{
	Lista* Nuevo;
	Lista* apuntador;
	Nuevo= NULL;
	apuntador= NULL;
	int tam=0;
	int i=1;
	tam=Tam(Inicio);
	if(Inicio!=NULL)
	{
		if(pos > tam+1)
		{
			printf("%d\n",pos);
			printf("Posicion invalida \n");
		}
		else if (pos==1)
		{
			printf("Debug 1 \n");
			Inicio=Altainicio(Inicio,dato,frecuencia,apuntadorarbol);
		}
		else if (pos==tam+2)
		{
			printf("Debug 2 \n");
			Inicio=Altafinal(Inicio,dato,frecuencia,apuntadorarbol);
		}
		else
		{
			printf("Debug 3 \n");
			Nuevo=Crearnodo(dato,frecuencia,apuntadorarbol);
			apuntador=Inicio;
			while(i!=pos)
			{
				i++;
				apuntador=apuntador->sig;
			}
			Nuevo->ant=apuntador->ant;
			Nuevo->sig=apuntador;
			apuntador->ant->sig=Nuevo;
			apuntador->ant=Nuevo;
		}
	}
	else
	{
		printf("Lista vacia \n");
	}
	return Inicio;
}

Lista* Altafinal(Lista* Inicio,char dato,int frecuencia,Arbol* apuntadorarbol)
{
	Lista* Nuevo;
	Lista* apuntador;
	apuntador=NULL;
	Nuevo=Crearnodo(dato,frecuencia,apuntadorarbol);
	if(Inicio==NULL)
	{
		Inicio=Nuevo;
	}
	else
	{
		apuntador=Inicio;
		while(apuntador->sig!=NULL)
		{
			apuntador=apuntador->sig;
		}
		apuntador->sig=Nuevo;
		Nuevo->ant=apuntador;
	}
	return Inicio;
}

//esta funcion se encarga de crear una lista con los caracteres de nuestro arreglo frase
Lista* Generarfrecuencias(char *frase)
{
	Lista *Listagenerada;
	Lista *Auxiliar; //generamos un auxiliar para ayudarnos a recorrer nuestro arreglo
	Listagenerada=NULL;
	Auxiliar=NULL;
	int i=0;
	int flag=0;
	printf("%s \n",frase);

	while(frase[i]!='\0') //Recorremos la frase hasta el final para encontrar las frecuencias de caracteres
	{
		//Nuestro caso inicio en el que encuentra el primer carcter
		if(Listagenerada==NULL)
		{
			Listagenerada=Altainicio(Listagenerada,frase[i],1,NULL);
		}
		else
		{
			Auxiliar=Listagenerada; //igualamos nuestro auxiliar que recorrera la lista
			//preguntamos si el segundo caracter es identico al primero
			if(Auxiliar->caracter==frase[i])
			{
				Auxiliar->frecuencia++;
				flag=1; //encendemos nuestra bandera para que no entre en un recorrido
			}
			//entramos en el segundo caso
			while(Auxiliar->sig!=NULL &&  flag==0) //recorremos la lista hasta que encontremos un caracter similar
			{
				if(Auxiliar->caracter==frase[i]) //si encuentra un caracter similar le agrega un 1 a la frecuencia
				{
					Auxiliar->frecuencia++; //aumentamos la frecuencia
					flag=1; //encendemos la bandera para salir
				}
				else
				{
					Auxiliar=Auxiliar->sig; //No encontramos un caracter similar
					flag=0;
				}
				if(Auxiliar->caracter==frase[i]) //volvemos a preguntar si en verdad no es similar
				{
					Auxiliar->frecuencia++;
					flag=1;
				}
			}
			//si no encontro una similitud con algun garacter lo agregamos
			if(flag==0)
			{
				//usamos una alta final para primero generar una lista mas adelante se va a ordenar
				Listagenerada=Altafinal(Listagenerada,frase[i],1,NULL); //a�adimos un nuevo caracter a la lista
			}
			flag=0; //apagamos nuestra bandera para la siguiente iteracion
		}
		i++; //iteramos para recorrer la frase
	}
	Mostrar(Listagenerada); //mostramos la lista generada con sus frecuencias
	system("PAUSE");
	return Listagenerada;
}

//ordenamos nuestra lista mediante insertion sort en orden acendente
Lista *Ordenar(Lista* Inicio)
{
		Lista *Aux;
		Lista *Aux2;
		Lista *Aux3;
		Lista *Swap;
		Aux=Inicio;
		Aux2=Inicio;
		Aux3=Inicio;
		Swap=Crearnodo('k',1,NULL);

		Aux2=Inicio->sig;
		while (Aux2!=NULL)
		{
			Swap->caracter=Aux2->caracter;
			Swap->frecuencia=Aux2->frecuencia;
			Aux=Aux2->ant;
			while (Aux!=NULL && Swap->frecuencia<Aux->frecuencia)
			{
				Aux3=Aux->sig;
				Aux3->caracter=Aux->caracter;
				Aux3->frecuencia=Aux->frecuencia;
				Aux->caracter=Swap->caracter;
				Aux->frecuencia=Swap->frecuencia;
				Aux=Aux->ant;
			}
			Aux2=Aux2->sig;
		}
		return Inicio;
}

void Generararbol(Lista *Inicio, Lista *Inicioog, Arbol **Raiz)
{
		Arbol *apuntadorhizq;
		Arbol *apuntadorhder;
		Arbol *apuntadorpadre;

		Lista *apuntador;

		int afre=0;
		char caracteri='<';
		int tam=0;

		int i=1;
		int sel=0;
		apuntador=Inicioog;
		if (Inicio==NULL)
		{
			printf("Lista vacia generar arbol\n");
			while(apuntador->sig!=NULL)
			{
				apuntador=apuntador->sig;
			}
			//printf("Hola\n");
			*Raiz=apuntador->apuntadorarbol;
		}
		else
		{
			if(Inicio==NULL)
			{
				while(apuntador->sig!=NULL)
				{
					apuntador=apuntador->sig;
				}
				//printf("Hola 2\n");
				*Raiz=apuntador->apuntadorarbol;
			}
			else
			{
				if(Inicio->apuntadorarbol!=NULL)
				{
					apuntadorhizq=Inicio->apuntadorarbol;
				}
				else
				{
					apuntadorhizq=Crearhoja(Inicio->caracter,Inicio->frecuencia);
				}
				Inicio=Inicio->sig;
				if(Inicio->apuntadorarbol!=NULL)
				{
					apuntadorhder=Inicio->apuntadorarbol;
				}
				else
				{
					apuntadorhder=Crearhoja(Inicio->caracter,Inicio->frecuencia);
				}
				Inicio=Inicio->sig;

				afre=apuntadorhizq->frecuencia+apuntadorhder->frecuencia;

				apuntadorpadre=Crearhoja(caracteri,afre);
				apuntadorpadre->izquierda=apuntadorhizq;
				apuntadorpadre->derecha=apuntadorhder;
				//apuntador=Inicioog;
				while (apuntador!=NULL && sel==0)
				{
					if((apuntadorpadre->frecuencia+1)<=apuntador->frecuencia)
					{
						sel=1;
					}
					else
					{
						i++;
					}
					apuntador=apuntador->sig;
				}
				tam=Tam(Inicioog)+1;
				//printf("Tam %d\n",tam);
				if(tam>=i)
				{
					Inicioog=Altap(Inicioog,i,apuntadorpadre->caracter,apuntadorpadre->frecuencia,apuntadorpadre);
				}
				else
				{
					Inicioog=Altafinal(Inicioog,apuntadorpadre->caracter,apuntadorpadre->frecuencia,apuntadorpadre);
				}
				Mostrar(Inicioog);
				system("PAUSE");
				//usamos recursividad para ir generando las ramas de nuestro arbol
				Generararbol(Inicio,Inicioog,&(*Raiz));
			}
		}
}

void Generarlistaarbol(Arbol *Raiz, Lista **Inicio)
{
	if(Raiz!=NULL)
	{
		*Inicio=Altafinal(*Inicio,Raiz->caracter,Raiz->frecuencia,NULL);
		if(Raiz->izquierda!=NULL)
		{
			Generarlistaarbol(Raiz->izquierda,&*Inicio);
		}
		if(Raiz->derecha!=NULL)
		{
			Generarlistaarbol(Raiz->derecha,&*Inicio);
		}
	}
	else
	{
		printf("El arbol esta vacio\n");
	}
}

void Creararchivoarbol(Arbol *Raiz, Lista *Inicio)
{
	FILE *Archivo;
	Lista *apuntador;
	apuntador=Inicio;
	Archivo=fopen("Arbol.txt","a");
	if(Archivo==NULL)
	{
		printf("Error al abrir archivo\n");
	}
	else
	{
		Generarlistaarbol(Raiz,&apuntador);
		Mostrar(apuntador);
		while(apuntador!=NULL)
		{
			if(apuntador->caracter=='<')
			{
				fprintf(Archivo,"%c %d ",apuntador->caracter,apuntador->frecuencia);
			}
			else
			{
				fprintf(Archivo,"%c %d ",apuntador->caracter,apuntador->frecuencia);
			}
			apuntador=apuntador->sig;
		}
	}
}


void Mostrararbolpreordenado(Arbol *Raiz)
{
	if(Raiz!=NULL)
	{
		printf("%c, %d\n",Raiz->caracter,Raiz->frecuencia);
		if(Raiz->izquierda!=NULL)
		{
			Mostrararbolpreordenado(Raiz->izquierda);
		}
		if(Raiz->derecha!=NULL)
		{
			Mostrararbolpreordenado(Raiz->derecha);
		}
	}
}

void Codificar(Arbol *Raiz, char code[],Lista **Inicio, int i)
{
		Lista *apuntador;
		apuntador=NULL;
		if(Raiz!=NULL)
		{
			//Recorremos la parte izquierda de nuestro arbol para agregar los 0
			if(Raiz->izquierda!=NULL)
			{
				code[i]='0';
				Codificar(Raiz->izquierda,code,&*Inicio,i+1);
			}
			//Recorremos la parte derecha de nuestro arbol para agregar los 1
			if(Raiz->derecha!=NULL)
			{
				code[i]='1';
				Codificar(Raiz->derecha,code,&*Inicio,i+1);
			}
			if(Raiz->caracter!='<')
			{
				code[i]='\0';
				*Inicio=Altafinal(*Inicio,Raiz->caracter,0,NULL);
				apuntador=*Inicio;
				while(apuntador->sig!=NULL)
				{
					apuntador=apuntador->sig;
				}
				strcpy(apuntador->codificacion,code);
			}
		}
		else
		{
				printf("Arbol esta vacio\n");
		}
}

void Mostrarcodigo(Lista *Inicio)
{
		Lista *apuntador;
		apuntador=Inicio;
		if(Inicio!=NULL)
		{
			printf("Letra y Codigo\n");
			while(apuntador!=NULL)
			{
				printf("%c:  %s\n",apuntador->caracter,apuntador->codificacion);
				apuntador=apuntador->sig;
			}
		}
		else
		{
			printf("Lista de codigos vacia\n");
		}
}

void Codbinario(Lista *Codigos, char oracion[],char codb[],char codc[])
{
		int i=0;
		int j=0;
		int k=0;
		int h=0;
		int l=0;
		int m=0;
		int mod=0;
		int conv=0;
		char aux;
		char auxconv;
		int p[8]={128,64,32,16,8,4,2,1};
		int cant=0;
		int cantc=0;
		int auxcant=0;
		int cdec[800];
		Lista *apuntador;
		apuntador=NULL;
		while(oracion[i]!='\0')
		{
			aux=toupper(oracion[i]);
			apuntador=Codigos;
			while(apuntador->caracter!=aux)
			{
				apuntador=apuntador->sig;
			}
			j=0;
			while(apuntador->codificacion[j]!='\0')
			{
				codb[k]=apuntador->codificacion[j];
				j++;
				k++;
			}
			i++;
		}
		codb[k]='\0';
		i=0;
		printf("Longitud de la frase: %d\n",strlen(oracion));
		printf("Longitud de la frase en binario: %d\n",strlen(codb));
		while(codb[i]!='\0')
		{
			printf("%c",codb[i]);
			i++;
		}
		printf("\n");
		mod=strlen(codb)%8;
		cantc=strlen(codb);
		cant=strlen(codb)/8;
		k=0;
		if(mod!=0)
		{
			auxcant=((cantc)+((8)-(cantc-(cant*8))));
			cdec[k]=0;
			for(h=0;h<auxcant;h++)
			{
				if(l==8)
				{
					l=0;
					k++;
					cdec[k]=0;
				}
				if(h>cantc)
				{
					auxconv='0';
				}
				else
				{
					auxconv=codb[h];
				}
				if(auxconv=='1')
				{
					conv=1;
				}
				else if(auxconv=='0')
				{
					conv=0;
				}
				printf("%d- %d\n",h+1,conv);
				cdec[k]+=((conv)*(p[l]));
				l++;
			}
			cdec[k+1]='\0';
			l=0;
			while(cdec[l]!='\0')
			{
				printf("%d ",cdec[l]);
				l++;
			}
			system("PAUSE");
		}
		else
		{
			cdec[k]=0;
			for(h=0;h<cantc;h++)
			{
				if(l==8)
				{
					l=0;
					k++;
					cdec[k]=0;
				}
				auxconv=codb[h];
				if(auxconv=='1')
				{
					conv=1;
				}
				else if(auxconv=='0')
				{
					conv=0;
				}
				printf("%d- %d\n",h+1,conv);
				cdec[k]+=((conv)*(p[i]));
				l++;
			}
			cdec[k+1]='\0';
			l=0;
			while(cdec[l]!='\0')
			{
				printf("%d ",cdec[l]);
				l++;
			}
			system("PAUSE");
		}
		k=0;
		while(cdec[k]!='\0')
		{
			codc[k]=cdec[k];
			k++;
		}
		codc[l]='\0';
}

void Creararchivocod(char codc[], char frase[])
{
	FILE *Archivo;
	FILE *Archivo2;
	Archivo=fopen("Codificado de huffman.txt","w+");
	Archivo2=fopen("Codificadohuffman.txt","w+");
	if(Archivo!=NULL)
	{
		fputs("Frase original: ",Archivo);
		fputs(frase,Archivo);
		fputs("\nCifrado: ",Archivo);
		fputs(codc,Archivo);
	}
	else
	{
		printf("Error al crear el archivo \n");
	}
	if(Archivo2!=NULL)
	{
		fputs(codc,Archivo2);
	}
	else
	{
		printf("Error al crear el archivo \n");
	}
	fclose(Archivo);
	fclose(Archivo2);
}

Lista* Conseguirarbol()
{
		FILE *Archivo;
		Lista *Arbolp;
		Arbolp=NULL;
		char contenidoarbol[500];
		int i=0;
		unsigned char caux='<';
		char caux2='|';
		char caux3='|';
		int faux=0;

		Archivo=fopen("Arbol.txt","r+");
		if(Archivo==NULL)
		{
			printf("Error al encontrar archivo \n");
		}
		else
		{
			fgets(contenidoarbol,500,Archivo);
			printf("%s\n",contenidoarbol);
			fflush(stdin);
			fclose(Archivo);
			Archivo=fopen("Arbol.txt","r+");
			while(!feof(Archivo))
			{
				fscanf(Archivo,"%c %d ",&caux,&faux);
				if(caux>=48 && caux<=57)
				{
					caux='_';
				}
				Arbolp=Altafinal(Arbolp,caux,faux,NULL);
			}
      printf("\nLista obtenida de nuestro arbol: \n");
			Mostrar(Arbolp);
		}
		fclose(Archivo);
		return Arbolp;
}

Arbol2* Altaarbol(Lista **Inicio, Arbol2* Arbol)
{
    Lista *aux;
    aux=(*Inicio);
    while(aux!=NULL)
    {
      Arbol=Generararbolp(Arbol,&aux);
      aux=aux->sig;
    }
    return Arbol;
}

Arbol2* Generararbolp(Arbol2* Raiz, Lista** Inicio)
{
    Arbol2 *aux;
    Arbol2 *nhoja;
    aux=NULL;
    nhoja=NULL;
    nhoja=Crearhoja((*Inicio)->caracter,(*Inicio)->frecuencia);
    int sum=0;
    if(Raiz==NULL)
    {
      return nhoja;
    }
    else
    {
      aux=Raiz;
      while(aux!=NULL)
      {
        if(aux->izquierda==NULL && aux->derecha==NULL)
        {
          aux->izquierda=nhoja;
          return Raiz;
        }
        if(aux->derecha!=NULL)
        {
          aux=aux->derecha;
        }
        else
        {
          sum=aux->izquierda->frecuencia+nhoja->frecuencia;
          if(aux->frecuencia==sum)
          {
            aux->derecha=nhoja;
            return Raiz;
          }
          else
          {
            aux=aux->izquierda;
          }
        }
      }
    }
}

void Leerarchivo(char palabra[])
{
	FILE *Archivo;
	Archivo=fopen("Codificadohuffman.txt","r");
	if(Archivo!=NULL)
	{
		fgets(palabra,300,Archivo);
		printf("Codigo: \n");
		printf("%s",palabra);
	}
	else
	{
		printf("Error al abrir archivo\n");
	}
	fclose(Archivo);
}

void Binarioleido(unsigned char cod[],unsigned char codbinario[])
{
		int codd[300];
		int i=0,j=0,k=0,l=0;
		char codcar[9];
		while(cod[i]!='\0')
		{
			codd[i]=cod[i];
			i++;
		}
		codd[i]='\0';
		i=0;
		while(codd[i]!='\0')
		{
			printf("\n%d:\t",codd[i]);
			for(k=8;k>0;k--)
			{
				codcar[k]=codd[i]%2;
				codd[i]=codd[i]/2;
				printf("%d ",codcar[k]);
			}
			for(l=1;l<9;l++)
			{
				if(codcar[l]==0)
				{
					codbinario[j]='0';
				}
				else
				{
					codbinario[j]='1';
				}
				j++;
			}
			i++;
		}
		codbinario[j]='\0';
		printf("\n\nCadena unida: \n%s\n",codbinario);
}

void Traermensaje(unsigned char codleido[],Lista* codc,char mensaje[])
{
		int i=0,j=0,l=0,n=0,m=0,match=0,tcod=1,t=0,pre=0,tamaux=0,tamc=0,ap=0,pos=0;
		char aux[300];
		Lista *apuntador;
		apuntador=codc;
		while(codleido[i]!='\0' && t!=1)
		{
			j=0;
			if(t==0)
			{
				if(ap==0)
				{
					l=0;
					aux[l]=codleido[i];
				}
				else
				{
					aux[l]=codleido[i];
				}
				l++;
				aux[l]='\0';
				tamaux=strlen(aux);
				pos=0;
				apuntador=codc;
				while(apuntador!=NULL && match!=1)
				{
					tamc=strlen(apuntador->codificacion);
					if(tamaux==tamc)
					{
						if(strcmp(aux,apuntador->codificacion)==0)
						{
							match++;
						}
					}
					apuntador=apuntador->sig;
					pos++;
				}
				n=1;
				if(match==1)
				{
					apuntador=codc;
					while(n!=pos)
					{
						apuntador=apuntador->sig;
						n++;
					}
					mensaje[m]=apuntador->caracter;
					m++;
					mensaje[m]='\0';
					ap=0;
					match=0;
				}
				else
				{
					ap=1;
				}
			}
			else
			{
				printf("Acabe\n");
			}
			t=1;
			while(codleido[j+i]!='\0')
			{
				if(codleido[j+i]=='1')
				{
					t=0;
				}
				j++;
			}
			i++;
		}
}

int main()
{
	char frase[200];
	char code[8];
	char codb[500];
	char codc[500];
	char mensaje[500];
	char codl[500];
	unsigned char codls[500];
	unsigned char codl2[500];
	int opcion=0;
	int i=0;
	int s=0;
	Lista* Inicio;
	Lista* Arbolp;
	Lista* Arbolleido;
	Lista* Arbolleido2;
	Lista* Codigos;
	Lista* Codigos2;
	Arbol* Arbol;
	Arbol2* Ar;

	Inicio=NULL;
	Arbol=NULL;
	Arbolp=NULL;
	Arbolleido=NULL;
	Arbolleido2=NULL;
	Codigos=NULL;
	Codigos2=NULL;
	Ar=NULL;
	do
	{
		printf("Menu: \n");
		printf("1- Codificar: \n");
		printf("2- Decodificar: \n");
		printf("3- Salir \n");
		printf("Elija una opcion: \n");
		scanf("%d",&opcion);
		fflush(stdin);
		switch(opcion)
		{
				case 1:printf("Escriba la frase: \n");
							gets(frase);
							fflush(stdin);
							//Convertimos nuestra frase caracter a caracter a mayusculas
							//Para evitar duplicacion de caracteres y hacer mas larga la lista y el arbol
							while(frase[i]!='\0')
							{
								if(frase[i]==' ')
								{
									frase[i]='_';
								}
								else
								{
									frase[i]=toupper(frase[i]);
									i++;
								}
							}
							//imprimimos la frase en mayusculas
							printf("Fase: %s \n", frase);
							system("PAUSE");
							printf("Lista de frecuencias: \n");
							Inicio=Generarfrecuencias(frase); //comenzamos a hacer nuestra tabla de frecuencias
							//ordenamos nuesta lista que contiene las tablas de frecuencias mediante insertion sort
							Inicio=Ordenar(Inicio);
							printf("Lista de frecuencias ordenada: \n");
							Mostrar(Inicio);
							system("PAUSE");
							//generamos un arbol en bsae a nuestra tabla de frecuencia
							Generararbol(Inicio,Inicio,&Arbol);
							//mostramos el orden de manera preordenada
							printf("Arbol en Preorden: \n");
		          //mostramos el arbol de manera preordenada
							Mostrararbolpreordenado(Arbol);
							system("PAUSE");
		          //generamos un archivo donde se guarde nuestro arbol para decifrar despues
		          Creararchivoarbol(Arbol,Arbolp);
							printf("Se creo el archivo con el arbol correctamente\n");
		          Codificar(Arbol,code,&Codigos,0);
							printf("Codigos obtenidos de nuestro arbol: \n");
							Mostrarcodigo(Codigos);
							printf("Frase codificada: \n");
							Codbinario(Codigos,frase,codb,codc);
							Creararchivocod(codc,frase);
			break;
			case 2: printf("Decodificado de Huffman: \n");
							Arbolleido=Conseguirarbol();
							Arbolleido2=Arbolleido;
							Ar=Altaarbol(&Arbolleido2,Ar);
              printf("\nArbol construido: \n");
              Mostrararbolpreordenado(Ar);
							Codificar(Ar,code,&Codigos2,0);
							printf("\n");
							Mostrarcodigo(Codigos2);
							system("PAUSE");
							Leerarchivo(codl);
							while(codl[s]!='\0')
							{
								codls[s]=codl[s];
								s++;
							}
							printf("\n");
							Binarioleido(codls,codl2);
							Traermensaje(codl2,Codigos2,mensaje);
							printf("\nLa frase original es: %s\n",mensaje);
			break;
			case 3: printf("Adios \n");
			break;
		}
	}while(opcion!=3);
	return 0;
}
