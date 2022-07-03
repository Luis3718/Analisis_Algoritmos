#include <iostream>
#include <string>
using namespace std;

char cifrado(char, char);
char descifrado(char, char);

int main(int argc, char const *argv[]){
  string mensaje;
  string password;
  string numero;
  cout<<"Bienvenido, que desea hacer: \n1.-Cifrar mensaje \n2.-Descifrar mensaje"<<endl;
  getline(cin, numero);
    if(numero == "1"){
        cout<<"Ingrese mensaje a cifrar: "<<endl;
          getline(cin,mensaje);
        cout<<"Ingrese la contraseña para cifrar: "<<'\n';
          getline(cin, password);

        int n = mensaje.size();
        int m = password.size();
        char b[n];

        for(int i = 0; i < n; i++)
          for( int j = 0; j<m; j++)
            b[i] = cifrado(mensaje[i],password[j]);


        cout<<"El mensaje cifrado es: "<<endl;
        cout<< b <<endl;
      }else if(numero == "2"){
        cout<<"Ingrese mensaje a descifrar: "<<endl;
          getline(cin, mensaje);
        cout<<"Ingrese la contraseña para descifrar: "<<'\n';
          getline(cin, password);

        int n = mensaje.size();
        int m = password.size();
        char d[n];
        for(int i = 0; i < n; i++)
          for(int k = 0; k < m; k++)
            d[i] = descifrado(mensaje[i],password[k]);

        cout<<"El mensaje descifrado es: "<<endl;
        cout<< d <<endl;
      }
  return 0;
}
char cifrado(char a, char b){
  int c = (int) a;
  int d = (int) b;
  int contra = d&15;
  int izq = c&240;
  int der = c&15;

  //Funcion  f(abcd)=cdab
  der = (der>>2)+((der&3)<<2);

  //Empleo de la contraseña.
  der = der^contra;

  int der1 = izq >> 4;
  int izq1 = der << 4;
  a = (char) (izq1 + der1);

  return a;
}

char descifrado(char a, char b){
  int c = (int) a;
  int d = (int) b;
  int contra = d&15;
  int izq = c&240;
  int der = c&15;

  int der1 = izq>>4;
  //Empleo de la contraseña
  der1 = der1^contra;

  //funcion f-1(cdab)=abcd
  der1 = (der1>>2)+((der1&3)<<2);

  int izq1 = der<<4;
  a = (char) (izq1 + der1);

  return a;
}
