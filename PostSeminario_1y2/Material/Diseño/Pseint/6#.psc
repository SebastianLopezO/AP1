// Name: Numero de Pulsaciones
// Copyright:
// Author: Juan Camilo Alzate Bedoya
// Date: 07/05/2022
// Description: Calcular el número de pulsaciones que una persona debe tener por cada 10 segundos de ejercicio,
// si la fórmula es:
// Num_Pulsaciones <- (220 - edad)/10 cuando la persona tiene menos de 30 años y es hombre
// Num_Pulsaciones <- (220 - edad)/7 cuando la persona tiene 30 años o más y es mujer
Algoritmo numero_pulsaciones
	Definir edad Como Entero
	Definir numPulsaciones Como Real
	Definir genero Como Caracter
	Escribir 'Femenino(F), Masculino(M)'
	Escribir 'Ingrese su Genero: '
	Leer genero
	Escribir 'Edad: '
	Leer edad
	Si (genero='M' O genero='m') Y edad<30 Entonces
		numPulsaciones <- (220-edad)/10
		Escribir 'Su numero de Pulsaciones es: ',numPulsaciones
	FinSi
	Si (genero='F' O genero='f') Y edad>=30 Entonces
		numPulsaciones <- (220-edad)/7
		Escribir 'Su numero de Pulsaciones es: ',numPulsaciones
	FinSi
FinAlgoritmo
