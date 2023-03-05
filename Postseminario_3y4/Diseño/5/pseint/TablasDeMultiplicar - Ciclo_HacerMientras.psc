Funcion res <- mostrar(start,end)
	x <- start
	Repetir
		Escribir ''
		Escribir 'Tabla de multiplicar de ',x
		z <- 1
		Repetir
			res <- z*x
			Escribir z,' x ',x,' = ',res
			z <- z+1
		Hasta Que z>10
		x <- x+1
	Hasta Que x>end
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
