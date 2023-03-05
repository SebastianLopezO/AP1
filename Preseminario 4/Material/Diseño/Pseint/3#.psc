// Name: Descuento
// Copyright:
// Author: Sebastian Lopez Osorno
// Date: 01/05/2022
// Description: 3) Una tienda ofrece un descuento del 15 MOD  sobre el total de la compra y un cliente desea saber cuánto deberá pagar finalmente por su compra.
Algoritmo Descuento
	Definir Tcompra,Pfinal Como Entero
	Escribir 'Ingrese el Valor total de la compra: '
	Leer Tcompra
	Pfinal <- Tcompra-Tcompra*(15/100)
	Escribir 'El precio final con descuento: ',Pfinal,' del precio inicial: ',Tcompra
FinAlgoritmo
