// Name: Calificacion_Final
// Copyright:
// Author: Sebastian Lopez Osorno
// Date: 01/05/2022
// Description: 4) Un alumno desea saber cu�l ser� su calificaci�n final en la materia de
// Algoritmos. Dicha calificaci�n se compone de los siguientes porcentajes:
// 55 MOD  del promedio de sus tres calificaciones parciales.
// 30 MOD  de la calificaci�n del examen final.
// 15 MOD  de la calificaci�n de un trabajo final.
Algoritmo Calificacion_Final
	Definir Par1,Par2,Par3,ExamF,Tfinal,CalF,ValorP1,ValorP2,ValorP3 Como Real
	Escribir 'Ingrese la Nota del Parcial#1: '
	Leer Par1
	Escribir 'Ingrese la Nota del Parcial#2: '
	Leer Par2
	Escribir 'Ingrese la Nota del Parcial#3: '
	Leer Par3
	Escribir 'Calificacion Examen Final: '
	Leer ExamF
	Escribir 'Calificacion Trabajo Final: '
	Leer Tfinal
	ValorP1 <- (Par1+Par2+Par3)/3*(55/100)
	ValorP2 <- ExamF*(30/100)
	ValorP3 <- Tfinal*(15/100)
	CalF <- ValorP1+ValorP2+ValorP3
	Escribir 'Nota Final de Algoritmos: ',CalF
FinAlgoritmo
