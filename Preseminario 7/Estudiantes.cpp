/*
	Name: Menu de Usuarios
	Copyright: 
	Author: 
	Date: 06/07/22 16:12
	Description:	Pedir cedula;
	
	Realizar un programa que, a través de subprogramas realice las siguientes tareas:
	• Capturare las cédulas de los N estudiantes de un grupo. Se sabe que un grupo nunca
	tiene más de 50 alumnos
	• Mostrar las cédulas de los N estudiantes de un grupo.
	• Buscar una cédula en al arreglo (Secuencial y binaria)
	• Insertar una nueva cédula (ordenado y desordenado)
	Para cada uno de las búsquedas e inserciones realizar las respectivas pruebas de escritorio
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

#define MAX_ARRAYLEN 50

void Lectura();
void Impresion();
void BuscarSecuencial();
void BuscarBinaria();
void InsertarOrdenada();
void InsertarDesordenada();


int main(){
	string documents[MAX_ARRAYLEN];
	int person;
	
	cout<<"Ingrese la cantidad de estudiantes que va a ingresar (maximo "<<MAX_ARRAYLEN<<": ";
	cin>>person;
	
	
	
}