/*
	Name: Menu de Usuarios
	Copyright: 
	Author: 
	Date: 06/07/22 16:12
	Description: Pedir nombre,cedula y edad
	
	Crear un programa que basado en un menú
	1. Ingresar datos de un usuario: nombre, edad, cédula 
	2. Modificar datos de un usuario 
	3. Agregar un usuario a la base de datos
	4. Eliminar un usuario 
	5.  Buscar un usuario
	6. Imprimir la base de datos 
	7. Termninar
*/

/* El código anterior está importando las bibliotecas necesarias para que se ejecute el programa. */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <locale>
#include <vector>
#include <windows.h>
#include <fstream>

/*Variables globales*/
#define MAX_ARRAYLEN 100

using namespace std;


//Funciones del programa
/* Declarar las funciones que se utilizarán en el programa. */
void IngresarDatos(string[], string[], string[]);
void ModificarDatos(string[], string[], string[]);
void AgregarUsuario(string[], string[], string[]);
void EliminarUsuario(string[], string[], string[]);
void BuscarUsuario(string[], string[], string[]);
void ImprimirDB(string[], string[], string[]);
void Terminar();

//Operaciones de uso
/* El código anterior declara funciones y procedimientos que se utilizarán en el programa. */
bool FindAny(string, string[]);
int FindPos(string, string[]);
int SizeVirtual(string[]);
void Write(string[], string[], string[]);
void Read(string[], string[], string[]);
void Erase(string []);
void ErasePos(string [],int);
void clearCin();


int main(){
	/* Declarar las variables que se utilizarán en el programa. */
	string nombres[MAX_ARRAYLEN],cedulas[MAX_ARRAYLEN],edades[MAX_ARRAYLEN];
	int funcion;
	string pass;
	bool app=true;
	
	/* Configuración de la configuración regional en español. */
	setlocale(LC_ALL,"Spanish");
	
	/* Leer los datos del archivo y almacenarlos en las matrices. */
	Read(nombres,cedulas,edades);

	/* El código anterior es un menú que permite al usuario elegir entre diferentes funciones. */
	do{
		/* Imprimiendo el menú para que el usuario elija. */
		cout<<"Funciones: \n "
		<<" 1. Ingresar datos de un usuario \n "
		<<" 2. Modificar datos de un usuario \n "
		<<" 3. Agregar un usuario a la base de datos \n "
		<<" 4. Eliminar un usuario \n "
		<<" 5. Buscar un usuario \n "
		<<" 6. Imprimir la base de datos \n "
		<<" 7. Termninar \n\n"
		
		/* Pedir al usuario que introduzca un número para elegir una función. */
		<<"Ingrese el numero de la funcion que desea hacer: ";
		cin>>funcion;
		cout<<endl;
		
		switch(funcion){
			case 1:
				/* Preguntar al usuario si desea continuar con la acción. */
				cout<<"Esta accion eliminara todos los registros \n"
					<<"Esta accion pedira valores iniaciales para la DB \n"
					<<"Ingrese si para continuar la accion o no para cancelar: ";
					
				cin>>pass;
				
				/* Preguntar al usuario si desea introducir datos. Si dice que sí, llamará a la función
				IngresarDatos. Si dice que no, imprimirá "Acción cancelada" */
				if(pass=="si"){
					IngresarDatos(nombres,cedulas,edades);
				}else{
					cout<<"Accion cancelada"<<endl;
				}
				break;
			case 2:
				ModificarDatos(nombres,cedulas,edades);
				break;
			case 3:
				AgregarUsuario(nombres,cedulas,edades);
				break;
			case 4:
				/* Preguntar al usuario si desea continuar con la acción. */
				cout<<"Esta accion eliminara los datos \n"
					<<"los datos eliminados no se pueden recuperar \n"
					<<"Ingrese si para continuar la accion o no para cancelar: ";
				cin>>pass;
				
				/* Solicitando al usuario si desea continuar con la accion y si decisión es si llamará a la función
				EliminarUsuario. */
				if(pass=="si"){
					EliminarUsuario(nombres,cedulas,edades);
				}else{
					cout<<"Accion cancelada"<<endl;
				}
				break;
			case 5:
				BuscarUsuario(nombres,cedulas,edades);
				break;
			case 6:
				ImprimirDB(nombres,cedulas,edades);
				break;
			case 7:
				/* Preguntar al usuario si desea guardar sus cambios antes de salir del programa. */
				cout<<"¿Desea guardar los cambios antes de terminar? \n"
					<<"Ingrese si para guardar o no para terminar sin guardar: ";
				cin>>pass;
				if(pass=="si"){
					Write(nombres,cedulas,edades);
					Terminar();
				}else{
					Terminar();
				}
				break;
			default:
				cout<<"Esta funcion no existe"<<endl;
				break;
		}
		cout<<endl;
		system("pause");
		system("cls");
		Write(nombres,cedulas,edades);
	}while(app);
	
}

//Operaciones de uso

/**
 * Devuelve verdadero si el elemento está en la matriz y falso si no lo está.
 * 
 * @param element El elemento a buscar.
 * @param array La matriz a buscar.
 * 
 * @return Un valor booleano.
 */
bool FindAny(string element,string array[]){
	/* Comprobando si el elemento está en la matriz. */
	for(int i=0;i<MAX_ARRAYLEN;i++){
		if(array[i]==element){
			return true;
		}
	}
	return false;
}

/**
 * Busca un elemento en una matriz y devuelve su posición
 * 
 * @param element El elemento a buscar.
 * @param array La matriz a través de la cual buscar.
 * 
 * @return La posición del elemento en la matriz.
 */
int FindPos(string element,string array[]){
	/* Búsqueda de un elemento en una matriz. */
	for(int i=0;i<MAX_ARRAYLEN;i++){
		if(array[i]==element){
			return i;
		}
	}
	return -1;
}

int SizeVirtual(string array[]){
	int size;
	for(int i=0;i<MAX_ARRAYLEN;i++){
		if(array[i]!=""){
			size++;
		}
	}
	return size-100;
}

/**
 * Escribe el contenido de los vectores nombres, cedulas y edades en un archivo llamado datos.txt
 * 
 * @param nombres vector de nombres
 * @param cedulas vector de cadenas que contiene los números de identificación de las personas.
 * @param edades vector de edades
 */
void Write(string nombres[], string cedulas[], string edades[]){
	
	/* Crear un objeto de archivo llamado archivo. */
	ofstream file; //definios variable tipo archivo
	
	/* Abriendo un archivo llamado datos.txt en el modo de salida. */
	file.open("datos.txt",ios::out);
	
	
	/* Comprobando si el archivo está abierto. */
	if(file.fail()){ //file.fail devuelve true o false
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	/* Guardar los datos de los vectores en un archivo. */
	
	/* Escribir los nombres de los archivos en el directorio en un archivo llamado "datos.txt" */
	for(int i=0;i<SizeVirtual(nombres);i++){
		file<<nombres[i]<<endl;
	}
	file<<"exit"<<endl;
	
	/* Escritura de las cédulas vectoriales en un archivo. */
	for(int i=0;i<SizeVirtual(cedulas);i++){
		file<<cedulas[i]<<endl;
	}
	file<<"exit"<<endl;
	
	/* Escribir el vector edades en un archivo. */
	for(int i=0;i<SizeVirtual(edades);i++){
		file<<edades[i]<<endl;
	}
	file<<"exit"<<endl;
	
	/* Cerrando el archivo. */
	file.close();
}



/**
 * Lee los datos de un archivo y los almacena en un vector
 * 
 * @param nombres vector de cuerdas
 * @param cedulas vector de cuerdas
 * @param edades vector de edades
 */
void Read(string nombres[], string cedulas[], string edades[]){
	/* Declarando una variable de tipo ifstream, una cadena y un entero. */
    ifstream file; //definios variable tipo archivo
	string date;
	int name,doc,age;
	
	/* Abriendo el archivo datos.txt en modo lectura. */
	file.open("datos.txt",ios::in);
	
	/* Comprobando si el archivo está abierto. */
	if(file.fail()){ // fail devuelve true o false
		
		/* Crear un objeto de archivo llamado archivo. */
		ofstream file; //definios variable tipo archivo
		
		
		/* Abriendo un archivo llamado datos.txt en el modo de salida. */
		file.open("datos.txt",ios::out);
		
		/* Comprobando si el archivo está abierto. */
		if(file.fail()){ //file.fail devuelve true o false
			cout<<"No se pudo abrir el archivo";
			exit(1);
		}
	}
	
	/* Leer el archivo y almacenar los datos en los vectores. */
	
	/* Leyendo el archivo y empujando los datos a un vector. */
	name=0;
	while(getline(file, date) && name<MAX_ARRAYLEN){
		if(date=="exit"){
			break;
		}else{
			nombres[name]=date;
			name++;
		}
	}
	
	
	/* Leyendo el archivo y empujando los datos a un vector. */
	doc=0;
	while(getline(file, date) && doc<MAX_ARRAYLEN){
		if(date=="exit"){
			break;
		}else{
			cedulas[doc]=date;
			doc++;
		}
	}
	

	/* Leyendo el archivo y empujando los datos a un vector. */
	age=0;
	while(getline(file, date) && age<MAX_ARRAYLEN){
		if(date=="exit"){
			break;
		}else{
			edades[age]=date;
			age++;			
		}
	}
	
	/* Cerrando el archivo. */
	file.close();
}

void Erase(string array[]){
	for(int i=0;i<MAX_ARRAYLEN;i++){
		array[i]="";
	}
}

void ErasePos(string array[],int pos){
	array[pos]="";
	for(int i=0;i<MAX_ARRAYLEN-1;i++){
		array[i]=array[i+1];
	}
}

/**
 * Borra el flujo de entrada e ignora cualquier carácter hasta el carácter de nueva línea
 */
void clearCin(){
    /* Borrar el búfer de entrada. */
	cin.clear();
    /* Ignorando el búfer de entrada. */
	cin.ignore( INT_MAX, '\n' );
}

//Funciones del programa

/**
 * Le pide al usuario que ingrese el número de personas que desea ingresar, luego le pide al usuario
 * que ingrese el nombre, edad e identificación de cada persona
 * 
 * @param nombres vector de cuerdas
 * @param cedulas vector de cuerdas
 * @param edades vector<string>&edades
 */
void IngresarDatos(string nombres[], string cedulas[], string edades[]){
	/* Declarar una variable de cadena llamada documento, nombre y edad. También está declarando una
    variable entera llamada persona. */
    string document,name,age;
	int person;
	
	/* Solicitar al usuario que ingrese la cantidad de personas que desea ingresar. */
    cout<<"Ingrese la cantidad de personas que deseea ingresar: ";
	cin>>person;
	cout<<endl;
	
	/* Borrando los elementos de los vectores. */
    Erase(nombres);
	Erase(cedulas);
	Erase(edades);
	
	/* El código anterior le pide al usuario que ingrese el nombre, la edad y la identificación de una
    persona. */
    for(int i=1;i<=person;i++){
		cout<<"Datos de usuario#"<<i<<": "<<endl;
		AgregarUsuario(nombres,cedulas,edades);
		cout<<endl;
	}
}


/**
 * Solicita el documento del usuario para modificar, luego verifica si el usuario existe en la base de
 * datos, si existe, solicita los datos nuevos y reemplaza los datos antiguos
 * 
 * @param nombres vector de nombres
 * @param cedulas vector de cadenas que contiene los números de identificación de los usuarios.
 * @param edades vector de edades
 */
void ModificarDatos(string nombres[], string cedulas[], string edades[]){
	/* Declaración de variables */
    string document,name,age;
	int pos;
	bool state;
	
	cout<<"Ingrese el documento del usuario a modificar: ";
	cin>>document;

	/* Comprobando si el usuario existe en la base de datos y si existe, pide los nuevos datos y reemplaza
    los antiguos. */
    if(FindAny(document,cedulas)){
       /* Encontrar la posición del elemento en el vector. */
        pos=FindPos(document,cedulas);

        /* Impresión de la información del usuario. */
		cout<<"\t "<<nombres[pos]<<" \t | \t "<<cedulas[pos]<<" \t | \t "<<edades[pos]<<endl;
		cout<<endl;
		
		/* Solicitar el nuevo nombre, documento y edad del usuario. Luego comprueba si el documento ya está
        en la base de datos y si lo está, pide otro documento. Si el documento no está en la base de
        datos, agrega al usuario a la base de datos. */
        do{
            /* Limpiando el búfer cin. */
			clearCin();
			/* Una forma de obtener una cadena con espacios. */
            cout<<"Ingrese el nuevo nombre del usuario: ";
			getline(cin,name);
			cout<<"Ingrese el nuevo documento del usuario: ";
			cin>>document;
			cout<<"Ingrese la nueva edad del usuario: ";
			cin>>age;
		
		
			/* Comprobando si el número de documento ya existe en la matriz. */
            if(FindAny(document,cedulas) && document!=cedulas[pos]){
				cout<<"Ya existe un usuario con este documento, ingrese otro"<<endl;
				state=false;
			}else{
				/* Reemplazando los valores del vector con los nuevos valores. */
                nombres[pos]=name;
				cedulas[pos]=document;
				edades[pos]=age;
				cout<<"Usuario agregado correctamente "<<endl;
				state=true;
			}
		}while(!state);
	}else{
		cout<<"El usuario a modificar no se ecuentra en la DB";
	}
	cout<<endl;
}

/**
 * Solicita al usuario nombre, documento y edad, verifica si el documento ya está en la base de datos y
 * si lo está, solicita al usuario que ingrese otro documento. Si el documento no está en la base de
 * datos, agrega a la persona a la base de datos
 * 
 * @param nombres vector de cadenas que contiene los nombres de los usuarios.
 * @param cedulas vector de cadenas que contiene los ID de los usuarios.
 * @param edades vector de edades
 */
void AgregarUsuario(string nombres[], string cedulas[], string edades[]){
	/* Declarar las variables 'documento', 'nombre', 'edad' y 'estado' como cadenas. */
    string document,name,age;
	bool state;
	
	if(SizeVirtual(nombres)<100){
		/* Un bucle que pide al usuario el nombre, documento y edad de una persona. Comprueba si el documento
	    ya está en la base de datos y si lo está, solicita al usuario que ingrese otro documento. Si el
	    documento no está en la base de datos, agrega a la persona a la base de datos. */
	    do{
	        /* Limpiando el búfer cin. */
			clearCin();
			/* Una forma de obtener una cadena con espacios. */
	        cout<<"Ingrese el nombre del usuario: ";
			getline(cin,name);
	        cout<<"Ingrese el documento del usuario: ";
			cin>>document;
	        cout<<"Ingrese la edad del usuario: ";
			cin>>age;
			cout<<endl;
	
			/* Comprobando si el documento ya está en la base de datos y si no está vacío. */
	        if(FindAny(document,cedulas) && document!=""){
				cout<<"Ya existe un usuario con este documento, ingrese otro"<<endl;
				state=false;
				cout<<endl;
			}else{
				nombres[SizeVirtual(nombres)]=name;
				cedulas[SizeVirtual(cedulas)]=document;
				edades[SizeVirtual(edades)]=age;
				cout<<"Usuario agregado correctamente "<<endl;
				state=true;
			}
		}while(!state);
	}else{
		cout<<"No hay mas espacio para agregar usuarios"<<endl;
	}
	
}

/**
 * Elimina un usuario de la base de datos.
 * 
 * @param nombres vector de nombres
 * @param cedulas vector de cadenas que contienen los ID de los usuarios.
 * @param edades vector de edades
 */

void EliminarUsuario(string nombres[], string cedulas[], string edades[]){
	/* Declaración de variables. */
    string document;
	int pos;

	/* Solicitar al usuario que ingrese la identificación del usuario que se eliminará. */
    cout<<"Ingrese el documento del usuario a eliminar: ";
	cin>>document;

	/* Eliminación del usuario de la base de datos. */
    if(FindAny(document,cedulas)){
		pos=FindPos(document,cedulas);
		ErasePos(nombres,pos);
		ErasePos(cedulas,pos);
		ErasePos(edades,pos);
		cout<<"Se ha eliminado correctamente el usuario";	
	}else{
		cout<<"El usuario a eliminar no se ecuentra en la DB";
	}
	cout<<endl;
}

/**
 * Busca un usuario en la base de datos e imprime su información
 * 
 * @param nombres vector de nombres
 * @param cedulas vector de cedulas
 * @param edades vector de edades
 */
void BuscarUsuario(string nombres[], string cedulas[], string edades[]){
	/* Declarando las variables `document` y `pos` */
    string document;
	int pos;

	/* Solicitar al usuario que ingrese un número de documento. */
    cout<<"Ingrese el documento del usuario a buscar: ";
	cin>>document;

	/* Búsqueda de un usuario en la base de datos e impresión de su información. */
    if(FindAny(document,cedulas)){
		pos=FindPos(document,cedulas);
		cout<<"\t "<<nombres[pos]<<" \t | \t "<<cedulas[pos]<<" \t | \t "<<edades[pos]<<endl;
	}else{
		cout<<"El usuario no se encontro en la DB, ingrese otro "<<endl;
	}
}

/**
 * Imprime la base de datos.
 * 
 * @param nombres vector de cadenas que contiene los nombres de las personas
 * @param cedulas vector de cedulas
 * @param edades vector de edades
 */
void ImprimirDB(string nombres[], string cedulas[], string edades[]){
	/* Imprimiendo el encabezado de la tabla. */
    cout<<"Impresion de la base de datos: "<<endl;
	cout<<endl;
	cout<<"\t Nombre \t | \t Documento \t | \t Edad"<<endl;

	/* Impresión de los datos de la base de datos. */
    for(int i=0;i<SizeVirtual(nombres);i++){
		cout<<"\t "<<nombres[i]<<" \t | \t "<<cedulas[i]<<" \t | \t "<<edades[i]<<endl;
	}
}


/**
 * Termina el programa
 */
void Terminar(){
	exit(EXIT_SUCCESS);
}