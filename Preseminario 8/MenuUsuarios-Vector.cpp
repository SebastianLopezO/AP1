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

using namespace std;


//Funciones del programa
/* Declarar las funciones que se utilizarán en el programa. */
void IngresarDatos(vector<string>&, vector<string>&, vector<string>&,bool&);
void ModificarDatos(vector<string>&, vector<string>&, vector<string>&,string,bool);
void AgregarUsuario(vector<string>&, vector<string>&, vector<string>&,int,bool);
void EliminarUsuario(vector<string>&, vector<string>&, vector<string>&);
void BuscarUsuario(vector<string>&, vector<string>&, vector<string>&);
void ImprimirDB(vector<string>&, vector<string>&, vector<string>&);
void Terminar();

//Operaciones de uso
/* El código anterior declara funciones y procedimientos que se utilizarán en el programa. */
bool FindAny(string, vector<string>);
int FindPos(string, vector<string>);
int Partition(vector<string>&,vector<string>&,vector<string>&,int,int,bool);
void QuickSort(vector<string>&,vector<string>&,vector<string>&,int,int,bool);
void Swap(string&,string&);
void Write(vector<string>&, vector<string>&, vector<string>&);
void Read(vector<string>&, vector<string>&, vector<string>&);
void clearCin();

int main(){
	/* Declarar las variables que se utilizarán en el programa. */
	vector<string> nombres,cedulas,edades;
	int funcion;
	string pass;
	bool app=true,state=true;
	
	/* Configuración de la configuración regional en español. */
	setlocale(LC_ALL,"Spanish");
	
	/* Leer los datos del archivo y almacenarlos en las matrices. */
	Read(nombres,cedulas,edades);

	/* El código anterior es un menú que permite al usuario elegir entre diferentes funciones. */
	do{
		/* Imprimiendo el menú para que el usuario elija. */
		cout<<"Funciones: \n "
		<<" 1. Captura de datos \n "
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
		pass="";
		system("cls");
		switch(funcion){
			case 1:
				
				/* Preguntar al usuario si desea continuar con la acción. */
				if(state==true){
					cout<<"Esta accion eliminara todos los registros \n"
					<<"Esta accion pedira valores iniaciales para la DB \n"
					<<"Ingrese si para continuar la accion o no para cancelar: ";
					
					cin>>pass;
					system("cls");
					/* Preguntar al usuario si desea introducir datos. Si dice que sí, llamará a la función
					IngresarDatos. Si dice que no, imprimirá "Acción cancelada" */
					if(pass=="si"){
						IngresarDatos(nombres,cedulas,edades,state);
					}else{
						cout<<"Accion cancelada"<<endl;
					}
					
				}else{
					cout<<"Esta accion esta desactivada, ya ha hecho uso de esta"<<endl;	
				}
				
				break;
			case 2:
				ModificarDatos(nombres,cedulas,edades,"",false);
				break;
			case 3:
				AgregarUsuario(nombres,cedulas,edades,0,false);
				break;
			case 4:
				/* Preguntar al usuario si desea continuar con la acción. */
				cout<<"Esta accion eliminara los datos \n"
					<<"los datos eliminados no se pueden recuperar \n"
					<<"Ingrese si para continuar la accion o no para cancelar: ";
				cin>>pass;
				system("cls");
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
				system("cls");
				if(pass=="si"){
					cout<<"Guardando los cambios y Saliendo del programa"<<endl;
					Write(nombres,cedulas,edades);
					Terminar();
				}else{
					cout<<"Saliendo del programa"<<endl;
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
bool FindAny(string element,vector<string> array){
	/* Comprobando si el elemento está en la matriz. */
	for(int i=0;i<array.size();i++){
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
int FindPos(string element,vector<string> array){
	/* Búsqueda de un elemento en una matriz. */
	for(int i=0;i<array.size();i++){
		if(array[i]==element){
			return i;
		}
	}
	return -1;
}

/**
 * Toma un vector de cadenas, un índice inicial y un índice final, y devuelve el índice del pivote.
 * 
 * @param cedulas vector de cadenas que contiene los ID de las personas.
 * @param nombres vector de cadenas que contiene los nombres de las personas.
 * @param edades vector de edades
 * @param start El índice del primer elemento de la matriz.
 * @param end El último índice de la matriz.
 * @param order verdadero para orden ascendente, falso para orden descendente.
 * 
 * @return El índice del último elemento de la matriz que es menor o igual que el destino.
 */
int Partition(vector<string>&cedulas,vector<string>&nombres,vector<string>&edades,int start,int end,bool order){
	/* Tomando el primer elemento de la matriz y convirtiéndolo en el pivote. */
	int piv=stoi(cedulas[start]);
	int i=start+1;
	for(int j=i;j<=end;j++){
		/* Ordenando los vectores por las cédulas. */
		if(order){
			/* Ordenar los vectores de cadenas en orden ascendente. */
			if(stoi(cedulas[j])<piv){
				/* Ordenando los vectores por las cédulas. */
				Swap(cedulas[i],cedulas[j]);
				Swap(nombres[i],nombres[j]);
				Swap(edades[i],edades[j]);
				i++;
			}
		}else{
			/* Ordenar los vectores de cadenas en orden descendente. */
			if(stoi(cedulas[j])>piv){
				/* Ordenando los vectores por las cédulas. */
				Swap(cedulas[i],cedulas[j]);
				Swap(nombres[i],nombres[j]);
				Swap(edades[i],edades[j]);
				i++;
			}
		}
	}
	/* Intercambiando los valores de los vectores. */
	Swap(cedulas[start],cedulas[i-1]);
	Swap(nombres[start],nombres[i-1]);
	Swap(edades[start],edades[i-1]);
	/* Encontrar el índice del último elemento de la matriz que es menor o igual que el objetivo. */
	return i-1;
}

/**
 * Ordena los vectores en orden ascendente
 * 
 * @param cedulas vector de cadenas que contienen los ID de las personas.
 * @param nombres vector de nombres
 * @param edades vector de edades
 * @param start El primer índice del vector.
 * @param end El último índice del vector.
 * @param order verdadero para orden ascendente, falso para orden descendente.
 */
void QuickSort(vector<string>&cedulas,vector<string>&nombres,vector<string>&edades,int start,int end,bool order){
	/* Ordenar los vectores en orden ascendente. */
	if(start<end){
		/* Partición de los vectores */
		int piv=Partition(cedulas,nombres,edades,start,end,order);
		/* Ordenar los vectores en orden ascendente. */
		QuickSort(cedulas,nombres,edades,start,piv-1,order);
		QuickSort(cedulas,nombres,edades,piv+1,end,order);
	}
}

/**
 * Intercambiar los valores de a y b.
 * 
 * @param a La primera cadena que se intercambiará.
 * @param b La matriz que se va a ordenar.
 */
void Swap(string&a,string&b){
    /* Intercambiando los valores de a y b. */
	string aux = a;
    a = b;
    b = aux;
}

/**
 * Escribe el contenido de los vectores nombres, cedulas y edades en un archivo llamado datos.txt
 * 
 * @param nombres vector de nombres
 * @param cedulas vector de cadenas que contiene los números de identificación de las personas.
 * @param edades vector de edades
 */
void Write(vector<string>&nombres, vector<string>&cedulas, vector<string>&edades){
	
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
	for(int i=0;i<nombres.size();i++){
		file<<nombres[i]<<endl;
	}
	file<<"exit"<<endl;
	
	/* Escritura de las cédulas vectoriales en un archivo. */
	for(int i=0;i<cedulas.size();i++){
		file<<cedulas[i]<<endl;
	}
	file<<"exit"<<endl;
	
	/* Escribir el vector edades en un archivo. */
	for(int i=0;i<edades.size();i++){
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
void Read(vector<string>&nombres, vector<string>&cedulas, vector<string>&edades){
	/* Declarando una variable de tipo ifstream, una cadena y un entero. */
    ifstream file; //definios variable tipo archivo
	string date;
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
	while(getline(file, date)){
		if(date=="exit"){
			break;
		}else{
			nombres.push_back(date);
		}
	}
	
	
	/* Leyendo el archivo y empujando los datos a un vector. */
	while(getline(file, date)){
		if(date=="exit"){
			break;
		}else{
			cedulas.push_back(date);
		}
	}
	

	/* Leyendo el archivo y empujando los datos a un vector. */
	while(getline(file, date)){
		if(date=="exit"){
			break;
		}else{
			edades.push_back(date);				
		}
	}
	
	/* Cerrando el archivo. */
	file.close();
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
void IngresarDatos(vector<string>&nombres, vector<string>&cedulas, vector<string>&edades, bool&state){
	/* Declarar una variable de cadena llamada documento, nombre y edad. También está declarando una
    variable entera llamada persona. */
    string document,name,age;
	int person,funcion;
	bool next;
	
	
	/* Borrando los elementos de los vectores. */
    nombres.erase(nombres.begin(),nombres.end());
	cedulas.erase(cedulas.begin(),cedulas.end());
	edades.erase(edades.begin(),edades.end());
	
	/* El código anterior le pide al usuario que ingrese el nombre, la edad y la identificación de una
    persona. */
    cout<<"Funciones: \n "
	<<" 1. Insertar al final del arreglo \n "
	<<" 2. Insertar en un arreglo ordenado \n\n "
	<<" 3. Volver al menu principal \n\n "
	
	/* Pedir al usuario que introduzca un número para elegir una función. */
	<<"Ingrese el numero de la funcion que desea hacer: ";
	cin>>funcion;
	system("cls");
	switch(funcion){
		case 1:case 2: case 3:
			next=true;
			break;
		default:
			next=false;
			break;
	}
    
    if(next){
    	/* Solicitar al usuario que ingrese la cantidad de personas que desea ingresar. */
	    cout<<"Ingrese la cantidad de personas que deseea ingresar: ";
		cin>>person;
		cout<<endl;
		system("cls");
    	/* El código anterior le pide al usuario que ingrese los datos de los usuarios. */
		for(int i=1;i<=person;i++){
			cout<<"Datos de usuario#"<<i<<": "<<endl;
			AgregarUsuario(nombres,cedulas,edades,funcion,true);
			cout<<endl;
			system("pause");
			system("cls");
		}
		/* Imprimiendo el número de usuarios agregados correctamente. */
		cout<<person<<" usuarios agregados correctamente"<<endl;
		state=false;
	}else{
		cout<<"Esta funcion no existe"<<endl;
	}
}

/**
 * Esta función se utiliza para modificar los datos de un usuario en la base de datos.
 * Solicita el documento del usuario para modificar, luego verifica si el usuario existe en la base de
 * datos, si existe, solicita los datos nuevos y reemplaza los datos antiguos
 * @param nombres vector de nombres
 * @param cedulas vector de cadenas que contiene los números de documento de los usuarios.
 * @param edades vector de edades
 * @param document El documento del usuario a modificar.
 * @param docstate Es un booleano que le dice a la función si el documento ya está en la función.
 */
void ModificarDatos(vector<string>&nombres, vector<string>&cedulas, vector<string>&edades,string document,bool docstate){
	/* Declaración de variables */
    string name,age,pass;
	int pos,funcion;
	bool state,modf;
	
	if(!docstate){
		cout<<"Ingrese el documento del usuario a modificar: ";
		cin>>document;
	}

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
        	/* Un menú para que el usuario elija lo que quiere hacer. */
			cout<<"Funciones: \n "
			<<" 1. Modificar documento \n "
			<<" 2. Modificar nombre \n "
			<<" 3. Modificar edad \n "
			<<" 4. Modifcar Todo \n\n "
			<<" 5. Regresa al menu principal \n\n "
			
			/* Pedir al usuario que introduzca un número para elegir una función. */
			<<"Ingrese el numero de la funcion que desea hacer: ";
			cin>>funcion;
			system("cls");

			/* El código anterior es una declaración de cambio que se usa para determinar qué quiere hacer el
			usuario. */
			switch(funcion){
				case 1:
					/* Solicitar al usuario que ingrese el nuevo documento del usuario. */
					cout<<"Ingrese el nuevo documento del usuario: ";
					cin>>document;
					name=nombres[pos];
					age=edades[pos];
					modf=true;
					break;
				case 2:
					/* Limpiando el búfer cin. */
					clearCin();
					/* Una forma de obtener una cadena con espacios. */
		            /* Solicitar al usuario que ingrese un nuevo nombre para el usuario. */
					cout<<"Ingrese el nuevo nombre del usuario: ";
					getline(cin,name);
					document=cedulas[pos];
					age=edades[pos];
					modf=true;
					break;
				case 3:
					/* Pedirle al usuario que ingrese a la nueva era del usuario. */
					cout<<"Ingrese la nueva edad del usuario: ";
					cin>>age;
					name=nombres[pos];
					document=cedulas[pos];
					modf=true;
					break;
				case 4:
					/* Limpiando el búfer cin. */
					clearCin();
					/* Una forma de obtener una cadena con espacios. */
		            /* Solicitar al usuario que ingrese el nuevo nombre, documento y edad del usuario. */
					cout<<"Ingrese el nuevo nombre del usuario: ";
					getline(cin,name);
					cout<<"Ingrese el nuevo documento del usuario: ";
					cin>>document;
					cout<<"Ingrese la nueva edad del usuario: ";
					cin>>age;
					modf=true;
				case 5:
					/* Una declaración de cambio que se utiliza para determinar lo que el usuario quiere hacer. */
					modf=false;
					state=true;
					cout<<"Volviendo al menu"<<endl;
					break;
			}
            
		
			/* El código anterior está verificando si el usuario existe en la matriz, si lo hace, le preguntará
			al usuario si desea modificar a otro usuario, si lo hace, le pedirá el nombre del usuario, el
			documento y la edad, si el usuario no Si no existe, modificará el nombre del usuario, el
			documento y la edad. */
			if(modf){
				/* Comprobando si el número de documento ya existe en la matriz. */
	            if(FindAny(document,cedulas) && document!=cedulas[pos]){
					cout<<"Ya existe un usuario con este documento, ingrese otro"<<endl;
					cout<<endl;
					/* Preguntar al usuario si desea modificar otro usuario. */
					cout<<"¿Desea ingresar otro usuario? \n"
						<<"Ingrese si para modificar otro usuario o no para cancelar la accion: ";
					cin>>pass;
					system("cls");
					
					/* Preguntar al usuario si desea continuar. */
					if(pass=="si"){
						state=false;
					}else{
						cout<<"Accion cancelada"<<endl;
						state=true;
					}
				}else{
					/* Reemplazando los valores del vector con los nuevos valores. */
	                nombres[pos]=name;
					cedulas[pos]=document;
					edades[pos]=age;
					cout<<"Usuario modificado correctamente "<<endl;
					state=true;
				}
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
 * @param nombres vector de nombres
 * @param cedulas vector de cadenas que contiene los números de documento de los usuarios.
 * @param edades vector de edades
 * @param funcion La función que el usuario elige.
 * @param stateFunction Esta es una variable booleana que se utiliza para determinar si la función se
 * llama desde la función principal o desde otra función.
 */
void AgregarUsuario(vector<string>&nombres, vector<string>&cedulas, vector<string>&edades,int funcion,bool stateFunction){
	/* Declarar las variables 'documento', 'nombre', 'edad' y 'estado' como cadenas. */
    string document,name,age,pass;
	bool state,insert;

	/* En un cilo pide al usuario el nombre, documento y edad de una persona. Comprueba si el documento
    ya está en la base de datos y si lo está, solicita al usuario que ingrese otro documento. Si el
    documento no está en la base de datos, agrega a la persona a la base de datos. */
    do{
    	if(!stateFunction){
    		/* Imprimiendo el menú para que el usuario elija. */
			cout<<"Funciones: \n "
			<<" 1. Insertar al final del arreglo \n "
			<<" 2. Insertar en un arreglo ordenado \n\n "
			<<" 3. Volver al menu principal \n\n "
			
			/* Pedir al usuario que introduzca un número para elegir una función. */
			<<"Ingrese el numero de la funcion que desea hacer: ";
			cin>>funcion;
			system("cls");
		}
		/* Una declaración de cambio que verifica el valor de la función variable. Si la función es igual a
		1, 2 o 3, entonces la inserción variable se establece en verdadero. Si la función es igual a 3,
		entonces el estado de la variable se establece en verdadero. */
		switch(funcion){
			case 1:
				insert=true;
			case 2:
				insert=true;
			case 3:
				insert=false;
				state=true;
				
		}
		/* Limpiando el bÃºfer cin. */
		clearCin();
		/* Una forma de obtener una cadena con espacios. */
		cout<<"Ingrese el nombre del usuario: ";
		getline(cin,name);
		cout<<"Ingrese el documento del usuario: ";
		cin>>document;
		cout<<"Ingrese la edad del usuario: ";
		cin>>age;
		cout<<endl;
		
		/* Comprobando si el documento ya estÃ¡ en la base de datos y si no estÃ¡ vacÃ­o. */
		if(FindAny(document,cedulas) && document!=""){
			cout<<"Ya existe un usuario con este documento, ingrese otro"<<endl;
			cout<<endl;
			cout<<"Â¿Desea ingresar otro usuario? \n"
				<<"Ingrese si para agregar otro usuario o no para cancelar la accion: ";
			cin>>pass;
			system("cls");
			/* Preguntar al usuario si desea continuar. */
			if(pass=="si"){
				state=false;
			}else{
				cout<<"Accion cancelada"<<endl;
				state=true;
			}
		}else{
			/* Añadiendo el nombre, documento y edad a los vectores. */
			nombres.push_back(name);
			cedulas.push_back(document);
			edades.push_back(age);
			cout<<"Usuario agregado correctamente "<<endl;
			state=true;
		}
	}while(!state);
}

/**
 * Elimina un usuario de la base de datos.
 * 
 * @param nombres vector de nombres
 * @param cedulas vector de cadenas que contienen los ID de los usuarios.
 * @param edades vector de edades
 */

void EliminarUsuario(vector<string>&nombres, vector<string>&cedulas, vector<string>&edades){
	/* Declaración de variables. */
    string document;
	int pos;

	/* Solicitar al usuario que ingrese la identificación del usuario que se eliminará. */
    cout<<"Ingrese el documento del usuario a eliminar: ";
	cin>>document;

	/* Eliminación del usuario de la base de datos. */
    if(FindAny(document,cedulas)){
		pos=FindPos(document,cedulas);
		nombres.erase(nombres.begin()+pos);
		cedulas.erase(cedulas.begin()+pos);
		edades.erase(edades.begin()+pos);
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
 * @param cedulas vector de cadenas que contienen los ID de los usuarios.
 * @param edades vector de edades
 */
void BuscarUsuario(vector<string>&nombres, vector<string>&cedulas, vector<string>&edades){
	/* Declarando las variables `document` y `pos` */
    string document;
    string pass;
	int pos;

	/* Solicitar al usuario que ingrese un número de documento. */
    cout<<"Ingrese el documento del usuario a buscar: ";
	cin>>document;

	/* Búsqueda de un usuario en la base de datos e impresión de su información. */
    if(FindAny(document,cedulas)){
		pos=FindPos(document,cedulas);
		cout<<"\t "<<nombres[pos]<<" \t | \t "<<cedulas[pos]<<" \t | \t "<<edades[pos]<<endl;
		cout<<"El usuario se encuentra en la posicion "<<pos<<" del DB"<<endl;
		cout<<endl;
		/* Preguntar al usuario si desea modificar los datos del usuario. */
		cout<<"¿Desea modificar los datos del usuario? \n"
			<<"Ingrese si para modificar o no para cancelar accion: ";
		cin>>pass;
		system("cls");
		/* Solicitando al usuario una respuesta para llamará a la función
		ModificarDatos. */
		if(pass=="si"){
			ModificarDatos(nombres, cedulas, edades,cedulas[pos],true);
		}else{
			cout<<"Accion cancelada"<<endl;
		}
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
void ImprimirDB(vector<string>&nombres, vector<string>&cedulas, vector<string>&edades){
	bool print;
	int funcion;
	
	/* Imprimiendo el menú para que el usuario elija. */
	cout<<"Funciones: \n "
		<<" 1. Imprimir en orden ascendente \n "
		<<" 2. Imprimir en orden descendente \n "
		<<" 3. Imprimir en orden de ingreso \n\n "
		<<" 4. Volver al menú anterior \n\n "
		
		/* Pedir al usuario que introduzca un número para elegir una función. */
		<<"Ingrese el numero de la funcion que desea hacer: ";
		cin>>funcion;
		system("cls");
		
		/* Ordenar el vector en orden ascendente o descendente. */
		switch(funcion){
			case 1:
				/* Ordenar el vector en orden ascendente. */
				/*ascendente*/
				QuickSort(cedulas,nombres,edades,0,cedulas.size()-1,true);
				print=true;
				break;
			case 2:
				/* Ordenar el vector en orden descendente. */
				/*descendente*/
				QuickSort(cedulas,nombres,edades,0,cedulas.size()-1,false);
				print=true;
				break;
			case 3:
				print=true;
				break;
			case 4:
				print=false;
				cout<<"Volviendo al menu principal"<<endl;
				break;
			default:
				print=false;
				cout<<"Esta funcion no existe"<<endl;
				break;
		}
		
		/* El código anterior está imprimiendo la base de datos. */
		if(print==true){
			/* Imprimiendo el encabezado de la tabla. */
		    cout<<"Impresion de la base de datos: "<<endl;
			cout<<endl;
			cout<<"\t Documento \t | \t Nombre \t | \t Edad"<<endl;
		
			/* Impresión de los datos de la base de datos. */
		    for(int i=0;i<cedulas.size();i++){
				cout<<"\t "<<cedulas[i]<<" \t | \t "<<nombres[i]<<" \t | \t "<<edades[i]<<endl;
			}
		}
		
}


/**
 * Termina el programa
 */
void Terminar(){
	exit(EXIT_SUCCESS);
}