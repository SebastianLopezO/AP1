/*
Name: Restaurante.cpp
	Copyright: 
		Author: Sebastian Lopez Osorno
		Date: 05/07/22 23:36
	Description: 
		En un restaurante desean almacenar en un arreglo el valor de venta por cada cliente que asistió en un día x
		Al final del día desean conocer el total de ventas del día 
		Promedio de venta
		Venta mayor y venta menor


*/

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <string>
#include <iomanip>
#define MAX_LEN 256

using namespace std;


int main(){
	int ventas[MAX_LEN];
	int ventaMax=0, ventaMin=10000000, venta, sumVentas,promVentas,cont=0;
	string des,dia;
	cout<<"Ingrese la fecha del dia de hoy: ";
	getline(cin,dia);
	do{
		cont++;
		venta=0;
		cout<<"Ingrese las ventas del cliente#"<<cont<<": "<<endl;
		cin>>venta;
		sumVentas+=venta;
		ventas[cont-1]=venta;
		
		if(venta>ventaMax){
			ventaMax=venta;
		}else if(venta<ventaMin){
			ventaMin=venta;
		}
		
		cout<<"Desea ingresar otro usuario? (si-no)"<<endl;
		cin>>des;
	}while(des=="si");
	promVentas=sumVentas/cont;
	cout<<endl;
	cout<<dia<<": "<<endl;
	cout<<"- Promedio de ventas: "<<promVentas<<endl;
	cout<<"- Venta Mayor: "<<ventaMax<<" Venta Menor: "<<ventaMin<<endl;
	
}