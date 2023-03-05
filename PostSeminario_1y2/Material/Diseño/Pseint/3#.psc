// Name: Numero de Pulsaciones
// Copyright:
// Author: Jaziel Garcia Ramirez
// Date: 07/05/2022
// Description: 3) Se desea conocer el total a pagar y el descuento obtenido por un cliente que llega a la caja del
// supermercado con n cantidad de desodorantes y n cantidad de kilos de papa. Tenga en cuenta que
// las papas su precio total depende del peso y los desodorantes si tiene un valor fijo de $3000 por
// unidad.
Algoritmo Descuento_Productos
	Definir CD,VKP,PTKD Como Entero
	Definir CKP,PDCT,TAP,DCTO Como Real
	Escribir ('ingrese la cantidad de desodorantes que va a comprar')
	Leer CD
	Escribir ('ingrese la cantidad de kilos de papa que va a comprar')
	Leer CKP
	Escribir ('ingrese el valor del kilo de papa')
	Leer VKP
	Escribir ('El porcentaje del descuento sin el signo de %')
	Leer PCTD
	PTKD <- ((CD*3000)+(CKP+VKP))
	DCTO <- PTKD*(PCTD/100)
	TAP <- (PTKD-DCTO)
	Escribir 'El descuento obtenido es de:',DCTO
	Escribir 'El total a pagar es de:',TAP
FinAlgoritmo
