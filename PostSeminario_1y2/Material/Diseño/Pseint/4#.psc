// Name: Numero de Pulsaciones
// Copyright:
// Author: Jaziel Garcia Ramirez
// Date: 07/05/2022
// Description: 4) Una persona cuyas compras en el supermercado tuvieron un valor n desea saber de cuanto fuel el
// descuento que obtuvo teniendo en cuenta que el supermercado ofrece un 5 MOD  descuento antes de
// IVA si el día de la compra es impar y un 7 MOD  si el día de la compra es par.
Algoritmo Descuento_Ventas
	Definir DC,VC,DCTO Como Entero
	Definir PSD Como Real
	Escribir 'Ingrese el día en que ha realizado la compra en números'
	Leer DC
	Escribir 'ingrese el valor de la compra'
	Leer VC
	Si (DC MOD 2=0) Entonces
		PSD <- (VC+(VC*0.07))*1.19
	FinSi
	Si (DC MOD 2<>0) Entonces
		PSD <- (VC+(VC*0.05))*1.19
	FinSi
	DCTO <- PSD-VC
	Escribir 'El descuento obtenido es de:',DCTO
FinAlgoritmo
