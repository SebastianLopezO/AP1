Algoritmo produccion_de_leche
	Definir Cventa Como Entero
	Definir V1,V2,V3,Tleche,Pl1,Pl2,Pl3 Como Real
	Definir Ds Como Caracter
	Escribir 'Calculo de Produccion de Leche'
	Escribir 'Ingrese los litros de leche producidos por la vaca#1: '
	Leer V1
	Escribir 'Ingrese los litros de leche producidos por la vaca#2: '
	Leer V2
	Escribir 'Ingrese los litros de leche producidos por la vaca#3: '
	Leer V3
	Tleche <- V1+V2+V3
	Pl1 <- (V1/Tleche)*100
	Pl2 <- (V2/Tleche)*100
	Pl3 <- (V3/Tleche)*100
	Si Tleche>300 Entonces
		Ds <- ' vender dicha producción '
		Cventa <- Tleche*2.000
		Escribir 'El propietario ha decidido: ',Ds
		Escribir 'El valor de la venta es: ',Cventa,' pesos'
		Escribir 'El porcentaje de leche de la vaca#1 es: ',Pl1,'%'
		Escribir 'El porcentaje de leche de la vaca#1 es: ',Pl2,'%'
		Escribir 'El porcentaje de leche de la vaca#1 es: ',Pl3,'%'
	SiNo
		Ds <- ' No vender dicha producción '
		Escribir 'El propietario ha decidido: ',Ds
		Escribir 'El porcentaje de leche de la vaca#1 es: ',Pl1,'%'
		Escribir 'El porcentaje de leche de la vaca#1 es: ',Pl2,'%'
		Escribir 'El porcentaje de leche de la vaca#1 es: ',Pl3,'%'
	FinSi
FinAlgoritmo
