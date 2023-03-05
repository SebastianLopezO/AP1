// Name: Numero de Pulsaciones
// Copyright:
// Author: Sebastian Lopez Osorno
// Date: 07/05/2022
// Description: 1) Dada una cantidad en pesos, obtener la equivalencia en dólares, asumiendo que la unidad
// cambiaría es un dato desconocido.
Algoritmo Conversion_Dolares
	Definir Dp Como Entero
	Definir Vp,Cd Como Real
	Escribir 'ingrese el dinero en pesos'
	Leer Dp
	Escribir 'ingrese el valor del peso en dolares'
	Leer Vp
	Cd <- Dp*Vp
	Escribir 'el valor en dólares es de',Cd
FinAlgoritmo
