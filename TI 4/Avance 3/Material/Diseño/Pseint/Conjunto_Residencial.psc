// Name: TRABAJO INDEPENDIENTE 4
// Copyright:
// Author: Sebastian Lopez Osorno
// Date: 11/05/22 11:50
// Description: Conjunto Residencial
Funcion res <- ValidarDatos (Mtlnm,TpInm,Estr,CantP,gym)
	Definir ds Como Logico
	ds <- Verdadero
	Escribir ''
	Si ( NO (Mtlnm>0 Y Mtlnm<1000)) Entonces
		Escribir 'Metros Cuadrados Erroneos, debe ingresar un dato entre 1 y 9999 '
		ds <- falso
	FinSi
	Si ( NO (TpInm='Casa' O TpInm='Apartamento' O TpInm='casa' O TpInm='apartamento' O TpInm='CASA' O TpInm='APARTAMENTO')) Entonces
		Escribir 'El tipo de Inmueble solo puede ser (casa)(apartamento): '
		ds <- falso
	FinSi
	Si ( NO (Estr>=1 Y Estr<=6)) Entonces
		Escribir 'El estrato es erroneo, debe ingresar entre 1 y 6  '
		ds <- falso
	FinSi
	Si ( NO (CantP>0 Y CantP<100)) Entonces
		Escribir 'Cantidad de Personas Erroneas, debe ingresar un dato entre 1 y 99 '
		ds <- falso
	FinSi
	Si ( NO (gym='S' O gym='N' O gym='s' O gym='n')) Entonces
		Escribir 'Decision erronea, debe ingresar S para Si y N para no '
		ds <- falso
	FinSi
	res <- ds
	Escribir ''
FinFuncion

Funcion res <- CuotaAdministracion (TipoInmueble,MetroCuadrado)
	Definir admin Como Entero
	admin <- 0
	Si (TipoInmueble='casa' O TipoInmueble='CASA' O TipoInmueble='Casa') Entonces
		admin <- MetroCuadrado*2500+10000
	FinSi
	Si (TipoInmueble='apartamento' O TipoInmueble='APARTAMENTO' O TipoInmueble='Apartamento') Entonces
		admin <- MetroCuadrado*1500+5000
	FinSi
	res <- admin
FinFuncion

Funcion res <- CuotaAseo (ValorAdmin,Estrato,MetroCuadrados)
	Definir ValorMetro,PorcentajeAdmin Como Entero
	PorcentajeAdmin <- ValorAdmin*0.10
	Si (Estrato>=1 Y Estrato<=3) Entonces
		ValorMetro <- MetroCuadrados*1000
	FinSi
	Si (Estrato>=4 Y Estrato<=6) Entonces
		ValorMetro <- MetroCuadrados*2000
	FinSi
	res <- PorcentajeAdmin+ValorMetro
FinFuncion

Funcion res <- CuotaGimnasio (PersonasPredio)
	Definir CantGymP,CantGymM,CantGymH Como Entero
	Escribir 'Ingrese la cantidad de Mujeres que usan el Gym: '
	Leer CantGymM
	Escribir 'Ingrese la cantidad de Hombres que usan el Gym: '
	Leer CantGymH
	CantGymP <- CantGymM+CantGymH
	Segun PersonasPredio  Hacer
		1:
			res <- PersonasPredio*30000
		2:
			res <- PersonasPredio*25000
		3:
			res <- PersonasPredio*20000
		4:
			res <- PersonasPredio*15000
		5:
			res <- PersonasPredio*10000
		De Otro Modo:
			Si (PersonasPredio>=6) Entonces
				res <- (CantGymM*4000)+(CantGymH*5000)
			SiNo
				res <- 0
			FinSi
	FinSegun
FinFuncion

Algoritmo Conjunto_Residencial
	Definir Mtlnm Como Real
	Definir Estr,CantP,Cadmin,Caseo,Cgym,Tpagar Como Entero
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
	Cadmin <- 0
	Caseo <- 0
	Cgym <- 0
	Si (ValidarDatos(Mtlnm,TpInm,Estr,CantP,gym)) Entonces
		Cadmin <- CuotaAdministracion(TpInm,Mtlnm)
		Caseo <- CuotaAseo(Cadmin,Estr,Mtlnm)
		Si (gym='S' O gym='s') Entonces
			Cgym <- CuotaGimnasio(CantP)
		FinSi
	FinSi
	Tpagar <- Cadmin+Caseo+Cgym
	Escribir 'El pago de la Cuota de Administracion es: ',Cadmin
	Escribir 'El pago de la Cuota de Aseo es: ',Caseo
	Escribir 'El pago de la Cuota de Gym es: ',Cgym
	Escribir 'El pago Total por los tres Servicios es: ',Tpagar
FinAlgoritmo
