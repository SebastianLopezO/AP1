Funcion res <- mostrar(start,end)
	Para x<-start Hasta end Hacer
		Escribir ''
		Escribir 'Tabla de multiplicar de ',x
		Para z<-1 Hasta 10 Hacer
			res <- z*x
			Escribir z,' x ',x,' = ',res
		FinPara
	FinPara
FinFuncion

Algoritmo TablasDeMultiplicar
	// variables
	Definir P,Q Como Entero
	Escribir 'Ingrese la primera tabla de multiplicar que desea conocer: '
	Leer P
	Escribir 'Ingrese la ultima tabla de multiplicar que desea conocer: '
	Leer Q
	Si (P>Q) Entonces
		llamar_a <- mostrar(Q,P)
	SiNo
		Si (P<Q) Entonces
			llamar_a <- mostrar(P,Q)
		FinSi
	FinSi
FinAlgoritmo
