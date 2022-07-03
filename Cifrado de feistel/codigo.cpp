#include <iostream>
#include <string>

using namespace std;

char Cifrador(char letmess, char pass){
  int asclm = (int) letmess;
  int ascps = (int) pass;

  int fun = ((asclm&15)>>2)+((asclm&3)<<2);
  fun = fun^(ascps&15);

  int fun1 = (fun<<4)+((asclm&240)>>4);
  letmess = (char) (fun1);

  return letmess;
}

char Descifrador(char letmess, char pass){
  int asclm = (int) letmess;
  int ascps = (int) pass;

  int fun = ((asclm&240)>>4)^(ascps&15);
  fun = (fun>>2)+((fun&3)<<2);

  int fun1 = ((asclm&15)<<4)+fun;
  letmess = (char) (fun1);

  return letmess;
}

int main(int argc,char const*argv[]){
  int opcion;
  string accion="0";
  string mensaje=" ";
  string contra="_._._._._.";

  cout<<"Eliga el numero de la accion que decida realizar\n1.-Cifrar\n2.-Decifrar"<<endl;
  cin>>opcion;
  //getline(cin,accion);
  switch(opcion)
  {
    case 1:
          {
            cout<<"Ingrese el mensaje:"<<endl;
            getline(cin,mensaje);
            cout<<"Ingrese una contraeña sin espacios"<<endl;
            cin>>contra;
            char messcif[mensaje.size()];
            for(int posme=0; posme<mensaje.size(); posme++){
              for(int posco=0; posco<contra.size(); posco++){
                messcif[posme]=Cifrador(mensaje[posme],contra[posco]);
              }
            }
            cout<<"Mensaje cifrado es:\n"<<messcif<<endl;
          }
    break;
    case 2:
          {
            cout<<"Ingrese mensaje cifrado: "<<endl;
            cin>>mensaje;
            //getline(cin, mensaje);
            cout<<"Ingrese la contraseña:"<<endl;
            cin>>contra;
            char messde[mensaje.size()];
            for(int posme=0; posme<mensaje.size(); posme++){
              for(int posco=0; posco<contra.size(); posco++){
                messde[posme]=Descifrador(mensaje[posme],contra[posco]);
              }
            }
            cout<<"Mensaje:\n"<<messde<<endl;
          }
    break;
    default: cout<<"La opcion ingresada no existe, vuelva a intentarlo."<<endl;
    break;
  }
    /*
  if (accion=="1"){

    cout<<"Ingrese el mensaje:"<<endl;
      getline(cin,mensaje);
    cout<<"Ingrese una contraeña sin espacios"<<endl;
      cin>>contra;

    char messcif[mensaje.size()];

    for(int posme=0; posme<mensaje.size(); posme++){
      for(int posco=0; posco<contra.size(); posco++){
      messcif[posme]=Cifrador(mensaje[posme],contra[posco]);
      }
    }

    cout<<"Mensaje cifrado es:\n"<<messcif<<endl;

    }else if(accion=="2"){

      cout<<"Ingrese mensaje cifrado: "<<endl;
        getline(cin, mensaje);
      cout<<"Ingrese la contraseña:"<<endl;
        cin>>contra;

      char messde[mensaje.size()];

      for(int posme=0; posme<mensaje.size(); posme++){
        for(int posco=0; posco<contra.size(); posco++){
        messde[posme]=Descifrador(mensaje[posme],contra[posco]);
        }
      }
    cout<<"Mensaje:\n"<<messde<<endl;

  }else{
    cout<<"La opcion ingresada no existe, vuelva a intentarlo."<<endl;
  }
  */
  return 0;
}
