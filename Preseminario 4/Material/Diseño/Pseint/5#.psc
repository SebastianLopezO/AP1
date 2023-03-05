// Name: Porcentaje
// Copyright:
// Author: Sebastian Lopez Osorno
// Date: 01/05/2022
// Description: 5) Un maestro desea saber qué porcentaje de hombres y qué porcentaje de mujeres hay en un grupo de estudiantes.
Algoritmo Porcentaje
	Definir numM,numH,numT,Phom,PMuj Como Entero
	Escribir 'Ingrese el numero total de estudiantes: '
	Leer numT
	Escribir 'Ingrese el numero total de Hombres: '
	Leer numH
	Escribir 'Ingrese el numero total de Mujeres: '
	Leer numM
	Phom <- (numH/numT)*100
	PMuj <- (numM/numT)*100
	Escribir 'Porcentaje de Hombres: ',Phom,'%'
	Escribir 'Porcentaje de Mujeres: ',PMuj,'%'
FinAlgoritmo
