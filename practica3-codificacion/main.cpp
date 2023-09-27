#include <iostream>
#include <string>
#include <fstream>

using namespace std;


//Declaracion de funciones



string lectura();           // -> Funcion para leer un archivo que se encuentra en la carpeta y me retorna un string con la inforrmacion

void escribir(string a);    // -> Funcion que toma un string y lo escribe en un archivo .txt en la carpeta

string Tobinary(char n);                                        // -> Funcion que recibe un char que conforma una cadena de string y la convierte a binario de 8 bytes

string Invertir (string r);                                     // -> Funcion para invertir el binario despues de hacer la division y generar orden correcto de bytes

string PrimerMetodo(unsigned int n,string cadena2 = "");        // -> Toma una semilla entera y un string en binario y lo codifica en un metodo especificadoen la guia

string SegundoMetodo(unsigned int n,string cadena2);            // -> Toma una semilla entera y un string en binario y lo codifica en un metodo especificadoen la guia

string Descodificar_metodo1 (string Bipalabra, int n);          // -> Funcion que descodifica el metodo 2

string Descodificar_metodo2(string Bipalabra, int n);           // -> Funcion que descodifica el metodo 2

string ToString(string Bipalabra);                              // -> Convierte un string en binario a un string en palabras






int main(){

    string ArchivoLectura, Bipalabra, Newpalabra,NewDeco;       /* archivolectura guarda el contenido del archivo cancion, Bipalabra guarda el contenido del archivo ya en binario*/
    int codificacion,n,control,descodificacion;

    cout << "Bienvenido al sistema de codificacion de texto" << endl;
    cout << "Siga los pasos para guardar su archivo .txt" << endl;

    cout << endl << endl << endl << endl;

    cout << "Dentro de la carpeta donde se guarda el build del proyecto 3 - codificacion crearas/pegaras el archivo de texto " ;
    cout << "(te recomendamos utilizar la plataforma wordpad)" << endl;
    cout << "Este archivo de texto debe contener la cancion a codificar o texto a codificar" ;
    cout <<  "se recomienta que el archivo este en ingles, para no generar problemas con los sistemas de codificado" << endl;

    _sleep(10000);          // -> pausa el flujo del codigo durante un tiempo determinado 10 sg
    system("cls");          // -> limpia pantalla

    ArchivoLectura = lectura();                                 // Le damos a la variable el texto guardado en el archivo

    // Menu
    cout<<"presione 1 para codificar un .txt"<<endl;
    cout<<"presione 2 para descodificar un .txt"<<endl;
    cin>>control;

    switch (control) {

    // METODOS DE CODIFICACION
    case 1:
    {
        cout << "Metodo 1 o 2 de codificacion" << endl;
        cin>> codificacion;


        switch (codificacion) {

        /*
         * COMO FUNCIONAN LOS METODOS DE CODIFICACION
         *
         * Con la variable BIPALABRA guardamos el archivo ya transformado en binario
         *
         * En la variable NEWPALABRA guardamos el archivo ya codificado con el metodo elegido y segun la semilla dada
         *
         * se tiene que tener encuenta todos los procesos que se hicieron para codificar el texto (conversion a binario, inversion del numero, se guarda en una
         * variable auxiliar para pasarlo al metodo de codificacion elegido)
         *
         * Escribimos en un nuevo archivo "nombredelarchivo.txt" el archivo codificado almacenado en la variable NEWPALABRA
        */

        case 1:
        {
            // Semilla para codificar
            cout << "Ingrese semilla de codificacion"<<endl;
            cin >> n;

            for(int i = 0; i < ArchivoLectura.length()+1; i++){
            Bipalabra.append(Tobinary(ArchivoLectura[i])) ;}
            Newpalabra = "";
            Newpalabra = PrimerMetodo(n,Bipalabra);
            escribir(Newpalabra);
            break;
        }

        case 2:
        {
            // Semilla para codificar
            cout << "Ingrese semilla de codificacion"<<endl;
            cin >> n;

            for(int i = 0; i < ArchivoLectura.length()+1; i++){
            Bipalabra.append(Tobinary(ArchivoLectura[i])) ;}
            Newpalabra = "";
            Newpalabra = SegundoMetodo(n,Bipalabra);
            escribir(Newpalabra);

            break;
        }

        default:
            cout <<"La opcion ingresada no es valida" << endl;
            break;
        }

        break;
    }

    // METODOS DE DESCODIFICACION
    case 2:
    {
        /*
         * COMO FUNCIONAN LOS METODOS DE DESCODIFICACION
         *
         * Con la variable NEWDECO guardamos el archivo que originalemente se encuentra en lenguaje binario
         *
         * Se debe descodificar el archivo con el mismo metodo de codificacion
         * (DE HACER LO CONTRARIO PUEDE GENERAR ERRORES EN LA DESCODIFICACION Y SE PUEDE PERDER/DAÑAR/OLVIDAR INFORMACION IMPORTANTE)
         *
         * Como el archivo esta codificado en el orden correcto de binario no es necesario hacer una inversion o voltear el codigo asi
         * que se puede pasar directamente a la descodificacion segun la codificacion
         *
         * Pasamos la variable NEWDECO que tiene el codigo ya descodificado a la funcion que nos convertira los numeros
         * de binario a su representacion en ASCII
         *
         * Escribimos en un nuevo archivo "nombredelarchivo.txt" el archivo descodificado almacenado en la variable NEWPALABRA
        */

        cout<<"Metodo 1 o 2 de descodoficacion"<<endl;
        cin>>descodificacion;

        switch (descodificacion) {
        case 1:
        {
            cout<<"Ingrese semilla con la cual se codifico"<<endl;
            cin>>n;

            NewDeco = Descodificar_metodo1(ArchivoLectura,n);
            NewDeco = ToString(NewDeco);
            escribir(NewDeco);

            break;
        }

        case 2:
        {
            cout<<"Ingrese semilla con la cual se codifico"<<endl;
            cin>>n;

            NewDeco = Descodificar_metodo2(ArchivoLectura,n);
            NewDeco = ToString(NewDeco);
            escribir(NewDeco);

            break;
        }

        default:
            cout <<"La opcion ingresada no es valida" << endl;
            break;
        }

     break;
    }

    default:
        cout <<"La opcion ingresada no es valida" << endl;
        break;

    }

    return 0;

}







//Funciones para el programa



string lectura(){

    ifstream archivo;
    string texto, nombreArchivo1;
    cout<<"Digite el nombre del archivo con el .txt: "<< endl;
    getline(cin,nombreArchivo1);
    archivo.open(nombreArchivo1.c_str(),ios::in);
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    while(!archivo.eof()){ //Mientras no sea el final del archivo
        char temp = archivo.get();
        if(archivo.good())
        {texto.push_back(temp);}

    }
    archivo.close();
    return texto;
}

void escribir(string a){

    ofstream archivo;
    string nombreArchivo;
    archivo.open("ArchivoProcesado.txt",ios::out);
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    archivo<<a;
    cout<<"Archivo guardado en un ArchivoProcesado.txt en la carpeta build "<<endl;
    archivo.close();

}

string Tobinary(char n){ //Funcion para generar el binario invertido
    string r = "";
    string D = "";
    while(n != 0)
    {r += (n % 2 == 0 ? "0" : "1"); // -> con vertimos el valor de la letra/caracter/numero en ASCII a binario
     n/=2;}
    r = r + "0";
    while(r.length() <8)
        r = r + "0";

    D = Invertir(r);

    return D;
}

string Invertir (string r){ //Funcion para invertir el binario para que quede normal ya que con las diviciones nos queda al revez

    string A = "";
    for(reverse_iterator rit=r.rbegin(); rit != r.rend(); ++rit) // -> con esta funcion cambiamos lo que esta en la ultima posicion a la primera y se va recorriendo todo hasta completar el proceso
       A += *rit;
    return A;
}

string SegundoMetodo(unsigned int n,string cadena2)
{
    string copiacad2;
    unsigned short int  tamanio = 0, ant = 0, conin = 0;
    tamanio = cadena2.length();
    copiacad2 = cadena2;
    while (conin < tamanio )
        {
           ant = conin;
           for(unsigned short int con = 0; con < n; con ++) {
               if (conin < tamanio){
                   cadena2[conin+1] = copiacad2[conin];
                   conin += 1;
               }
               else {
                   break;
               }
           }
           cadena2[ant] = copiacad2[conin-1];
        }
    return cadena2;
}

string PrimerMetodo(unsigned int n, string cadena2){

    string   copiacad2;
    unsigned short int con1=0,con0 = 0,conin = 0, conin2 =1, tamanio, tam;
    tamanio = cadena2.length();
    tam = 0;
    copiacad2 = cadena2;
        while (tam < tamanio) {
              if(tam>=n) {
                  for(unsigned short int con = tam-(n-1); conin < n; con ++){
                      if (copiacad2[con] == '0'){
                          con0 += 1;
                      }
                      else {
                          con1 += 1;
                      }
                      conin += 1;
                  }
                  if(con0 == con1){
                      for(unsigned short int con = 0; con < n; con ++){
                          if (cadena2[tam] == '0'){
                              cadena2[tam]= '1';
                          }
                          else {
                              cadena2[tam] = '0';
                          }
                          tam += 1;
                      }
                  }
                  if (con0 > con1) {
                      for(unsigned short int con = 0; con < n; con ++){
                          if (con % 2 != 0){
                              if (cadena2[tam] == '0'){
                                  cadena2[tam] = '1';
                              }
                              else {
                                  cadena2[tam] = '0';
                              }
                          }
                          tam += 1;
                      }
                  }
                  if (con1 > con0) {
                      for(unsigned short int con = 0; con < n; con ++) {
                          if (conin2 % 3 == 0){
                              if (cadena2[tam] == '0'){
                                  cadena2[tam] = '1';
                              }
                              else {
                                  cadena2[tam] = '0';
                              }
                          }
                          conin2 += 1;
                          tam += 1;
                     }
                 }
              }
              else {
                  for(unsigned short int con = 0; con < n; con ++){
                      if (cadena2[tam] == '0'){
                          cadena2[tam]= '1';
                      }
                      else {
                          cadena2[tam] = '0';
                      }
                      tam += 1;
                   }
             }
             con0 = 0;
             con1 = 0;
             conin2 = 0;
             conin = 0;

    }
      return cadena2;
}

string Descodificar_metodo2(string Bipalabra, int n)
{
    string copiacad2;
         unsigned short int  tamanio = 0, ant = 0, conin = 0;
         tamanio = Bipalabra.length();
         copiacad2 = Bipalabra;
         while (conin < tamanio )
             {
                ant = conin;
                for(unsigned short int con = 0; con < n; con ++) {
                    if (conin < tamanio){
                        Bipalabra[conin] = copiacad2[conin+1];
                        conin += 1;
                    }
                    else {
                        break;
                    }
                }
                Bipalabra[conin-1] = copiacad2[ant];
             }
         return Bipalabra;
}

string ToString(string Bipalabra){

    //Funcion para convertir un numero en binario a su representacion en ASCII para concatenarlo
    //a una cadena que sera devuelta para seguir agregando en la variable que guardara todo el archivo decodificado

    string  palabra;

        int tam = 0;
        int tamanio = Bipalabra.length();
        string aux = "";
        int binario, resultado, resto = 0;
        int digito[8];
        char resultado1;

        while(tam<tamanio){
            for (; tam < tamanio; tam++){
                aux += Bipalabra[tam];
                if(aux.length() >= 8){
                    binario = stoi(aux);
                    for (int i = 0; i <8; i++){
                        digito[i] = binario % 10;
                        binario /= 10;
                    }

                    for(int i = 7; i >=0; i--){
                        resultado = (resto * 2) + digito[i];
                        resto = resultado;


                    }
                    aux = "";
                    resultado1 = resultado;
                    palabra.push_back(resultado1);
                    resultado = 0;
                    resto = 0;

                }

            }

        }
     return palabra;}

string Descodificar_metodo1 (string Bipalabra, int n)
{
    string   descodificada;
    unsigned short int con1=0, con0 = 0, conin = 0, conin2 =1, tamanio, tam;
    tamanio = Bipalabra.length();
    tam = 0;
    descodificada = Bipalabra;

    while (tam < tamanio)
    {
          if(tam>=n)
          {
              for(unsigned short int con = (tam - n); conin < n; con ++)
                {
                      if (descodificada[con] == '1')
                      {con1 += 1;}
                      else {con0 += 1;}
                      conin += 1;

                    }

                  if(con0 == con1)
                      {
                          for(unsigned short int con = 0; con < n; con ++)
                          { if (descodificada[tam] == '1'){descodificada[tam]= '0';}
                            else {descodificada[tam] = '1';}
                            tam += 1;
                          }
                      }

                  if (con0 > con1)
                      {for(unsigned short int con = 0; con < n; con ++)
                          {
                              if (con % 2 != 0)
                              {if (descodificada[tam] == '1') {descodificada[tam] = '0';}
                               else {descodificada[tam] = '1'; }
                              }
                              tam += 1;}
                      }

                  if (con1 > con0)
                      {for(unsigned short int con = 0; con < n; con ++)
                          {if (conin2 % 3 == 0)
                              {
                                  if (descodificada[tam] == '1'){descodificada[tam] = '0';}
                                  else {descodificada[tam] = '1';}
                              }
                              conin2 += 1;
                              tam += 1;}
                       }
            }

          else
            {for(unsigned short int con = 0; con < n; con ++)
               {
                  if (descodificada[con] == '1'){descodificada[con]= '0';}
                  else {descodificada[con] = '1';}
                  tam += 1;
               }
             }

         con0 = 0;
         con1 = 0;
         conin2 = 0;
         conin = 0;


    }
    return descodificada;
}
