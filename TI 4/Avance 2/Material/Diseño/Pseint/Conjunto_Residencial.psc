// Name: TRABAJO INDEPENDIENTE 4
// Copyright:
// Author: Sebastian Lopez Osorno
// Date: 11/05/22 11:50
//	Description: Conjunto Residencial
Algoritmo Conjunto_Residencial
	Definir Mtlnm,Padmin Como Real
	Definir Estr,CantP,CantGymM,CantGymH,Vmetro,CantGymP,Cadmin,Caseo,Cgym,Tpagar Como Entero
	Definir TpInm,gym Como Caracter
	Escribir 'Factura por Concepto de Servicios: '
	Escribir 'Ingrese los Metros Cuadrados del Inmueble: '
	Leer Mtlnm
	Escribir 'Ingrese el tipo de Inmueble (Casa)(Departamento): '
	Leer TpInm
	Escribir 'Ingrese su Estrato Socio Economico: '
	Leer Estr
	Escribir 'Ingrese la cantidad de Personas del Predio: '
	Leer CantP
	Escribir 'Ingrese si en el Predio Usan el Gym Si(S) No(N): '
	Leer gym
	Escribir 'Ingrese la cantidad de Mujeres que usan el Gym: '
	Leer CantGymM
	Escribir 'Ingrese la cantidad de Hombres que usan el Gym: '
	Leer CantGymH
	Cadmin <- 0
	Caseo <- 0
	Cgym <- 0
	Si TpInm='casa' O TpInm='apartamento' Entonces
		Segun TpInm  Hacer
			'casa':
				Cadmin <- Mtlnm*2500+10000
			'apartamento':
				Cadmin <- Mtlnm*1500+5000
			De Otro Modo:
				Cadmin <- 0
		FinSegun
	SiNo
		TpInm <- Minusculas(TpInm)
		Segun TpInm  Hacer
			'casa':
				Cadmin <- Mtlnm*2500+10000
			'apartamento':
				Cadmin <- Mtlnm*1500+5000
			De Otro Modo:
				Cadmin <- 0
		FinSegun
	FinSi
	Padmin <- Cadmin*0.10
	Si Estr>0 Y Estr<7 Entonces
		Si Estr>=1 Y Estr<=3 Entonces
			Vmetro <- Mtlnm*1000
		FinSi
		Si Estr>=4 Y Estr<=6 Entonces
			Vmetro <- Mtlnm*2000
		FinSi
	FinSi
	Caseo <- Padmin+Vmetro
	CantGymP <- CantGymH+CantGymM
	Si (gym='S' O gym='N') O (gym='s' O gym='n') Entonces
		Segun CantP  Hacer
			1:
				Cgym <- CantGymP*30000
			2:
				Cgym <- CantGymP*25000
			3:
				Cgym <- CantGymP*20000
			4:
				Cgym <- CantGymP*15000
			5:
				Cgym <- CantGymP*10000
			De Otro Modo:
				Si CantGymP>=6 Entonces
					Cgym <- (CantGymM*4000)+(CantGymH*5000)
				SiNo
					Cgym <- 0
				FinSi
		FinSegun
	SiNo
		Cgym <- 0
	FinSi
	Tpagar <- Cadmin+Caseo+Cgym
	Escribir 'El pago de la Cuota de Administracion es: ',Cadmin
	Escribir 'El pago de la Cuota de Aseo es: ',Caseo
	Escribir 'El pago de la Cuota de Gym es: ',Cgym
	Escribir 'El pago Total por los tres Servicios es: ',Tpagar
FinAlgoritmo
