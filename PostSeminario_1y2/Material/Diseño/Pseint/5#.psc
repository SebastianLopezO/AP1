// Name: Pareja de Numeros
// Copyright:
// Author: Juan Camilo Alzate Bedoya
// Date: 07/05/2022
// Description: 5) Leer tres n?meros enteros x, y, z, compararlos y si al menos dos son iguales pero negativos,
// escriba un mensaje que diga: "Hacen pareja negativa". Y si al menos dos son iguales pero
// positivos, escriba un mensaje que diga: "Hacen pareja positiva"
Algoritmo pareja_de_numeros
	Definir numx,numy,numz Como Entero
	Definir msj Como Caracter
	Escribir ('Escribir Numero X: ')
	Leer numx
	Escribir ('Escribir Numero Y: ')
	Leer numy
	Escribir ('Escribir Numero Z: ')
	Leer numz
	Si ((numx=numy O numx=numz) Y (numx<0)) O ((numy=numz) Y (numy<0)) Entonces
		msj <- 'Hacen pareja Negativa'
		Escribir (msj)
	FinSi
	Si ((numx=numy O numx=numz) Y (numx>0)) O ((numy=numz) Y (numy>0)) Entonces
		msj <- 'Hacen pareja Positiva'
		Escribir (msj)
	FinSi
FinAlgoritmo
