// Name: Comisiones
// Copyright:
// Author: Sebastian Lopez Osorno
// Date: 01/05/2022
// Description: 2) Un vendedor recibe un sueldo base m�s un 10 MOD  extra por comisi�n de sus ventas, el vendedor desea saber cu�nto dinero obtendr� por concepto de comisiones por las tres ventas que realiza en el mes y el total que recibir� en el mes tomando en cuenta su sueldo base y comisiones.
Algoritmo Comisiones
	Definir base,venta1,venta2,venta3,Cven1,Cven2,Cven3,Tcom,Tsueldo Como Entero
	Escribir 'Ingrese su salario base: '
	Leer base
	Escribir 'Ingrese el valor de la venta#1: '
	Leer venta1
	Escribir 'Ingrese el valor de la venta#2: '
	Leer venta2
	Escribir 'Ingrese el valor de la venta#3: '
	Leer venta3
	Cven1 <- venta1*(10/100)
	Cven2 <- venta2*(10/100)
	Cven3 <- venta3*(10/100)
	Tcom <- Cven1+Cven2+Cven3
	Tsueldo <- base+Tcom
	Escribir 'Total de las Comisiones: ',Tcom
	Escribir 'Pago total: ',Tsueldo,' de una base de: ',base
FinAlgoritmo
