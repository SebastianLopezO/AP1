// Name: Primero
// Copyright:
// Author: Sebastian Lopez Osorno
// Date: 02/05/2022
// Description: Una empresa que tiene dos trabajadores otorgar� un subsidio de alimentaci�n a la persona que tiene m�s a�os laborando en la empresa hoy en d�a. Se conoce que la empresa solo vincula una persona por a�o y lo hace en el mes de febrero de cada a�o.
Algoritmo beneficio
	Definir NomEmp1,NomEmp2,NomBef Como Caracter
	Definir MesTrEmp1,MesTrEmp2,HTrEmp1,HTrEmp2,VH,VS1,VS2,VrTotal,VrSub Como Entero
	Definir A�oTrEmp1,A�oTrEmp2 Como Real
	VH <- 10500
	Escribir 'Informacion Empleado#1'
	Escribir 'Ingresa el nombre: '
	Leer NomEmp1
	Escribir 'Ingrese los meses trabajados: '
	Leer MesTrEmp1
	Escribir 'Ingrese las horas Trabajadas por Mes: '
	Leer HTrEmp1
	Escribir 'Informacion Empleado#2'
	Escribir 'Ingresa el nombre: '
	Leer NomEmp2
	Escribir 'Ingrese los meses trabajados: '
	Leer MesTrEmp2
	Escribir 'Ingrese las horas Trabajadas por Mes: '
	Leer HTrEmp2
	A�oTrEmp1 <- MesTrEmp1/12
	A�oTrEmp2 <- MesTrEmp2/12
	VS1 <- (HTrEmp1*VH)*A�oTrEmp1
	VS2 <- (HTrEmp2*VH)*A�oTrEmp2
	Si A�oTrEmp1>A�oTrEmp2 Entonces
		NomBef <- NomEmp1
		VrSub <- VS1*(1.5/100)
		VrTotal <- VS1+VrSub
		Escribir 'Beneficiario: ',NomBef
		Escribir 'Salario Total con Subsidio: ',VrSub
		Escribir 'Valor Subsidio: ',VrTotal
	FinSi
	Si A�oTrEmp2>A�oTrEmp1 Entonces
		NomBef <- NomEmp2
		VrSub <- VS2*(1.5/100)
		VrTotal <- VS2+VrSub
		Escribir 'Beneficiario: ',NomBef
		Escribir 'Salario Total con Subsidio: ',VrSub
		Escribir 'Valor Subsidio: ',VrTotal
	FinSi
FinAlgoritmo
