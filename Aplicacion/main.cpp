#include <iostream>
#include <string>
#include <fstream>

using namespace std;
//Declaracion de funciones

string lectura();
string lectura1();
/*Funcion para leer un archivo que se encuentra en la carpeta build y
 * me retorna un string con la inforrmacion*/
string Descodificar_metodo2(string Bipalabra, int n);
//Funcion que descodifica el metodo 2
string ToString(string Bipalabra);
//convierte un string en binario a un string en palabras
void ingrUsuarios(string a);
void escribir(string a);
/*Funcion que toma un string y lo escribe en un archivo .txt en la
 * carpeta build*/
bool Coincidencia(string cedula);
string lectura2();
string SegundoMetodo(unsigned int n,string cadena2);
string Invertir (string r);
string Tobinary(char n);
void escribir1(string a);
void menu( string cedula);
string user(bool*tf);
void retirar(string cedula);
int Charaint(string numchar);
void Saldo(string cedula);
void Eliminar();

int main()
{
    string contraAdmin, contraSudo, Usuarios, Documento, UsuariosF;
    string Bipalabra,Newpalabra;
    int n = 4;
    int OpcionBanco = 0;
    bool w;
    bool admit;
    Usuarios = lectura();
    while(OpcionBanco != 3){
        cout << "BIENVENIDO AL BANCO." << endl;
        cout << endl;
        cout << "Que tipo de persona es?" << endl;
        cout << "1. Administrador" << endl;
        cout << "2. Usuario" << endl;
        cout << "3. Salir" << endl;
        cin >> OpcionBanco;
        system("cls");

        switch (OpcionBanco) {
        case 1://Administrador
        {contraSudo = lectura1();
            cout << "Buen dia Administrador, porfavor ingrese la contrasena" << endl;
            cin>>contraAdmin;
            system("cls");
            contraSudo = Descodificar_metodo2(contraSudo,n);
            contraSudo = ToString(contraSudo);

            if (contraSudo.length() != contraAdmin.length()){
                cout << "La contraseÃ±a es incorrecta" << endl;
                    break;
            }

            else
            {
                int contador = 0;

                for(int t = 0; t < contraSudo.length(); t++){
                    if(contraAdmin[t] != contraSudo[t]){
                        cout << "La contrasena es incorrecta" << endl;
                        contador += 1;}}

                if(contador != 0){
                    cout << "La contrasena es incorrecta" << endl;
                    break;}
            }

            cout << "La verificacion fue exitosa" << endl;

            Usuarios = Descodificar_metodo2(Usuarios,n);
            Usuarios = ToString(Usuarios);

            escribir(Usuarios);

            cout << "Ingrese el numero de docuento del usuario que desea registrar" << endl;
            cin >> Documento;
            system("cls");

            w = Coincidencia(Documento);
            if(w == false){
                ingrUsuarios(Usuarios);
            }
            else{
                cout<<"Usuario ya existe."<<endl;
            }

            UsuariosF = lectura2();

            for(int i = 0; i < UsuariosF.length()+1; i++){
                Bipalabra.append(Tobinary(UsuariosF[i])) ;}

            Newpalabra = "";
            Newpalabra = SegundoMetodo(n,Bipalabra);
            escribir1(Newpalabra);
        }
        break;

        case 2:

            cout << "Digite su numero de cedula.";
            cin >> Documento;
            Usuarios = Descodificar_metodo2(Usuarios,n);
            Usuarios = ToString(Usuarios);
            escribir(Usuarios);
            Documento = user(&admit);
            if (admit == true){
                menu(Documento);
            }
            else {
                cout << "Cedula o clave incorrectas."<< endl;
            }

            break;
        case 3:
            Eliminar();
            cout << "Gracias por utilizar nuestros cajeros seguros del banco." << endl;
            break;
        default:
            cout <<"La opcion ingresada no es valida" << endl;
            break;
        }

    }
    return 0;
}

string lectura(){
    ifstream archivo;
    string texto, nombreArchivo1;
    archivo.open("Usuarios.txt",ios::in);
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

string lectura2(){
    ifstream archivo;
    string texto, nombreArchivo1;
    archivo.open("Usuarios1.txt",ios::in);
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
    archivo.open("Usuarios1.txt",ios::out);
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    archivo<<a;
    archivo.close();

}

void escribir1(string a){
    ofstream archivo;
    string nombreArchivo;
    archivo.open("Usuarios.txt",ios::out);
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    archivo<<a;
    archivo.close();

}

string lectura1(){
    ifstream archivo;
    string texto;
    archivo.open("sudo.txt",ios::in);
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
    return palabra;
}

void ingrUsuarios(string a){
    string Cedula,Clave,Saldo,total;
    unsigned short int term = 1;
    unsigned int con = 0;
    ifstream fin;               //stream de entrada, lectura
    ofstream fout;              //stream de salida, escritura
    fout.open("Usuarios1.txt");       //abre el archivo para escritura
    cout << "Registro de usuarios: " << endl;
    while(term == 1){
        cout << "Cedula: ";
        cin >> Cedula;
        cout <<"Clave (sin ',' ni ';'): ";
        cin >> Clave;
        cout << "Saldo: ";
        cin >> Saldo;
        total += "\n"+Cedula + ',' + Clave + ',' + Saldo + '.';
        cout << "Ingresa 0 si ya terminaste o 1 si quiere ingresar otro usuario: ";
        cin >> term;
        system("cls");
        if (term == 0){
            fout<<a<<total;
            break;
        }
        fout << endl;
    }
    fout.close();
}

bool Coincidencia(string cedula){
    string cedularch,saldo;
    unsigned short int con = 0;
    ifstream fin;               //stream de entrada, lectura
    ofstream fout;              //stream de salida, escritura
    try{

        fin.open("Usuarios1.txt");        //abre el archivo para lectura
        if(!fin.is_open()){
            throw '2';
        }
        while(fin.good()){              //lee caracter a caracter hasta el fin del archivo
            char temp=fin.get();
            if(fin.good()){
                if (temp != ',' && con < 1){
                    cedularch += temp;     //Asigna cada caracter leido a la cadena de caracteres
                }
                if(temp == ',') {
                    con += 1;
                }

                if (temp == ';') {
                    if (cedula == cedularch){
                        break;
                    }
                    con = 0;
                    cedula = "";
                }

            }
        }

    }
    catch (char c){
        cout<<"Error # "<<c<<": ";
        if(c=='1'){
            cout<<"Error al abrir el archivo para escritura.\n";
        }
        else if(c=='2'){
            cout<<"Error al abrir el archivo para lectura.\n";
        }
    }
    catch (...){
        cout<<"Error no definido\n";
    }
    if(cedula == cedularch){
        return true;
    }
    else{
        return false;}

}

string Tobinary(char n){ //Funcion para generar el binario invertido
    string r = "";
    string D = "";
    while(n != 0)
    {r += (n % 2 == 0 ? "0" : "1");
        n/=2;}
    r = r + "0";
    while(r.length() <8)
        r = r + "0";

    D = Invertir(r);

    return D;
}

string Invertir (string r){ //Funcion para invertir el binario para que quede normal
    string A = "";
    for(reverse_iterator rit=r.rbegin(); rit != r.rend(); ++rit)
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

void menu( string cedula){
    unsigned short int num,num2;
    while (true) {
        cout << "Si quiere consultar su saldo ingrese 1 "<< endl;
        cout << "Si quiere retirar dinero ingrese 2"<< endl;
        cin >> num;
        if (num == 1){
            Saldo(cedula);
        }
        if (num == 2){
            retirar(cedula);
        }
        cout << "Si quiere repetir el menu ingrese 1";
        cin >> num2;
        if (num2 != 1){
            break;
        }
    }
}

string user(bool *tf){
    string cedula,clave,cedularch,clavearch;
    unsigned short int con = 0;
    ifstream fin;               //stream de entrada, lectura
    ofstream fout;              //stream de salida, escritura
    cout << "Cedula: ";
    cin >> cedula;
    cout << "Clave: ";
    cin >> clave;
    try{

        fin.open("Usuarios1.txt");        //abre el archivo para lectura
        if(!fin.is_open()){
            throw '2';
        }

        while(fin.good()){              //lee caracter a caracter hasta el fin del archivo
            char temp=fin.get();
            if(fin.good()){
                if (temp != ',' && con < 2){
                    if (con < 1 ){
                        cedularch += temp;     //Asigna cada caracter leido a la cadena de caracteres
                    }
                    else {
                        clavearch += temp;
                    }
                }
                if(temp == ',') {
                    con += 1;
                }
                if (temp == '.') {
                    if (cedula == cedularch && clave == clavearch){
                        *tf = true;
                        return cedula;
                    }
                    con = 0;
                    cedula = "";
                    clavearch ="";
                }
            }
        }
        fin.close();                //Cierra el archivo de lectura.

    }
    catch (char c){
        cout<<"Error # "<<c<<": ";
        if(c=='1'){
            cout<<"Error al abrir el archivo para escritura.\n";
        }
        else if(c=='2'){
            cout<<"Error al abrir el archivo para lectura.\n";
        }
    }
    catch (...){
        cout<<"Error no definido\n";
    }
    *tf = false;
    return cedula;
}

void retirar(string cedula) {
    string cedularch,saldo,clavearch;
    unsigned short int con = 0;
    int saldoint = 0;
    int dinero = 0;
    ifstream fin;               //stream de entrada, lectura
    ofstream fout;              //stream de salida, escritura
    try{

        fin.open("Usuarios1.txt");        //abre el archivo para lectura
        if(!fin.is_open()){
            throw '2';
        }
        while(fin.good()){              //lee caracter a caracter hasta el fin del archivo
            char temp=fin.get();
            if(fin.good()){
                if (temp != ',' && con < 1){
                    cedularch += temp;     //Asigna cada caracter leido a la cadena de caracteres
                }
                if(temp == ',') {
                    con += 1;
                }

                if (temp == '.') {
                    if (cedula == cedularch){
                        break;
                    }
                    con = 0;
                    cedula = "";
                }
                else  if (cedula == cedularch && con == 2){
                    if (temp != ','){
                        saldo += temp;
                    }
                }
            }
        }
        saldoint = Charaint(saldo);
        fin.close();                //Cierra el archivo de lectura.
        cout << "Cuanto dinero va a retirar: ";
        cin >> dinero;
        saldoint = saldoint - dinero;
        if (saldoint<0){
            cout << "Esa cantidad excede su saldo ";
        }
    }
    catch (char c){
        cout<<"Error # "<<c<<": ";
        if(c=='1'){
            cout<<"Error al abrir el archivo para escritura.\n";
        }
        else if(c=='2'){
            cout<<"Error al abrir el archivo para lectura.\n";
        }
    }
    catch (...){
        cout<<"Error no definido\n";
    }
}

int Charaint(string numchar) {
    int longi = numchar.length();
    unsigned short int num = 0;
    unsigned int mul = 1;
    unsigned int suma = 0;
    longi = longi-1;
    for(longi; longi >=  0 ; longi--) {
        char temp = numchar[longi];
        if (temp == '0'){
            num = 0;
        }
        if (temp == '1'){
            num = 1;
        }
        if (temp == '2'){
            num = 2;
        }
        if (temp == '3'){
            num = 3;
        }
        if (temp == '4'){
            num = 4;
        }
        if (temp == '5'){
            num = 5;
        }
        if (temp == '6'){
            num = 6;
        }
        if (temp == '7'){
            num = 7;
        }
        if (temp == '8'){
            num = 8;
        }
        if (temp == '9'){
            num = 9;
        }
        suma += num * (mul);
        mul = mul * 10;

    }
    return suma;
}

void Saldo(string cedula){
    string cedularch,saldo;
    unsigned short int con = 0;
    int saldoint = 0;
    ifstream fin;               //stream de entrada, lectura
    ofstream fout;              //stream de salida, escritura
    try{

        fin.open("Usuarios1.txt");        //abre el archivo para lectura
        if(!fin.is_open()){
            throw '2';
        }
        while(fin.good()){              //lee caracter a caracter hasta el fin del archivo
            char temp=fin.get();
            if(fin.good()){
                if (temp != ',' && con < 1){
                    cedularch += temp;     //Asigna cada caracter leido a la cadena de caracteres
                }
                if(temp == ',') {
                    con += 1;
                }

                if (temp == '.') {
                    if (cedula == cedularch){
                        break;
                    }
                    con = 0;
                    cedula = "";
                }
                else  if (cedula == cedularch && con == 2){
                    if (temp != ','){
                        saldo += temp;
                    }
                }
            }
        }
        saldoint = Charaint(saldo);
        saldoint = saldoint - 1000;
        cout << "Saldo: " << saldoint << endl;
        fin.close();                //Cierra el archivo de lectura.

    }
    catch (char c){
        cout<<"Error # "<<c<<": ";
        if(c=='1'){
            cout<<"Error al abrir el archivo para escritura.\n";
        }
        else if(c=='2'){
            cout<<"Error al abrir el archivo para lectura.\n";
        }
    }
    catch (...){
        cout<<"Error no definido\n";
    }

}

void Eliminar(){
    ifstream archivo;
    archivo.open("Usuarios1.txt",ios::in);
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    archivo.close();
    remove("Usuarios1.txt");

}
