#include <iostream>
#include <string>
using namespace std;

char cifrar(char a,char b)
{
  int c = (int) a;
  int d = (int) b;
  int pass = d&15;
  int left = c&240;
  int right = c&15;
  int left2;
  int right2;
  right=(right>>2)+((right&3)<<2);
  right=right^pass;
  right2=left>>4;
  left=right<<4;
  a=(char)(left2+right2);
  return a;
}

char descifrar(char a, char b)
{
  int c = (int) a;
  int d = (int) b;
  int pass = d&15;
  int left = c&240;
  int right = c&15;
  int left2;
  int right2;
  right2=left>>4;
  left=right<<4;
  a=(char)(left2+right2);
  return a;
}

int main()
{
  string mensaje, password;
  int opc,n,m,i,j;
  cout<<"Bienvenido elija una opcion: \n1- Cifrar mensaje \n2- Decifrar un mensaje" <<endl;
  cin>>opc;
  switch (opc)
  {
    case 1: cout<<"Ingresa el mensaje a cifrar: " <<endl;
            cin>>mensaje;
            cout<<"Ingresa la contraseña: " <<endl;
            cin>>password;
            n=mensaje.size();
            m=password.size();
            char b[n];
            for(i=0;i<n;i++)
            {
              for(j=0;j<m;j++)
              {
                b[i]=cifrar(mensaje[i],password[j]);
              }
            }
            cout<<"El mensaje cifrado es: " <<endl;
            cout<<b <<endl;
    break;
    case 2: cout<<"Ingresa el mensaje a cifrar: " <<endl;
            cin>>mensaje;
            cout<<"Ingresa la contraseña: " <<endl;
            cin>>password;
    break;
  }
}
