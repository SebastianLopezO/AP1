// Name: TRABAJO INDEPENDIENTE 4
// Copyright:
// Author: Sebastian Lopez Osorno
// Date: 11/05/22 11:50
// Description: Conjunto Residencial
Funcion res <- ValidarDatos (MetrosCuadrados,TipoInmueble,Estrato,PersonasPredio,UsoGym,HombresGym,MujeresGym)
	Definir Ds Como Logico
	Ds <- Verdadero
	Escribir ''
	Si ( NO (MetrosCuadrados>0 Y MetrosCuadrados<1000)) Entonces
		Escribir 'Metros Cuadrados Erroneos, debe ingresar un dato entre 1 y 9999 '
		Ds <- falso
	FinSi
	Si ( NO (TipoInmueble='Casa' O TipoInmueble='Apartamento' O TipoInmueble='casa' O TipoInmueble='apartamento' O TipoInmueble='CASA' O TipoInmueble='APARTAMENTO')) Entonces
		Escribir 'El tipo de Inmueble solo puede ser (casa)(apartamento): '
		Ds <- falso
	FinSi
	Si ( NO (Estrato>=1 Y Estrato<=6)) Entonces
		Escribir 'El estrato es erroneo, debe ingresar entre 1 y 6  '
		Ds <- falso
	FinSi
	Si ( NO (PersonasPredio>0 Y PersonasPredio<100)) Entonces
		Escribir 'Cantidad de Personas Erroneas, debe ingresar un dato entre 1 y 99 '
		Ds <- falso
	FinSi
	Si ( NO (UsoGym='S' O UsoGym='N' O UsoGym='s' O UsoGym='n')) Entonces
		Escribir 'Decision erronea, debe ingresar S para Si y N para no '
		Ds <- falso
	FinSi
	Si (UsoGym='S' O UsoGym='s') Entonces
		Si ( NO (PersonasPredio>=1 Y (HombresGym+MujeresGym)<=PersonasPredio)) Entonces
			Escribir 'Cantidad de Personas que usan el gym erronea, debe ingresar una cantidad menor o igual a las que viven en el predio'
			Ds <- falso
		FinSi
	FinSi
	res <- Ds
	Escribir ''
FinFuncion

Funcion res <- CuotaAdministracion (TipoInmueble,MetrosCuadrados)
	Definir Admin Como Entero
	Admin <- 0
	Si (TipoInmueble='casa' O TipoInmueble='CASA' O TipoInmueble='Casa') Entonces
		Admin <- MetrosCuadrados*2500+10000
	FinSi
	Si (TipoInmueble='apartamento' O TipoInmueble='APARTAMENTO' O TipoInmueble='Apartamento') Entonces
		Admin <- MetrosCuadrados*1500+5000
	FinSi
	res <- Admin
FinFuncion

Funcion res <- CuotaAseo (ValorAdmin,Estrato,MetrosCuadrados)
	Definir ValorMetro,PorcentajeAdmin Como Entero
	PorcentajeAdmin <- ValorAdmin*0.10
	Si (Estrato>=1 Y Estrato<=3) Entonces
		ValorMetro <- MetrosCuadrados*1000
	FinSi
	Si (Estrato>=4 Y Estrato<=6) Entonces
		ValorMetro <- MetrosCuadrados*2000
	FinSi
	res <- PorcentajeAdmin+ValorMetro
FinFuncion

Funcion res <- CuotaGimnasio (PersonasPredio,HombresGym,MujeresGym)
	Definir PersonasGym Como Entero
	PersonasGym <- HombresGym+MujeresGym
	Segun PersonasPredio  Hacer
		1:
			res <- PersonasGym*30000
		2:
			res <- PersonasGym*25000
		3:
			res <- PersonasGym*20000
		4:
			res <- PersonasGym*15000
		5:
			res <- PersonasGym*10000
		De Otro Modo:
			Si (PersonasPredio>=6) Entonces
				res <- (MujeresGym*4000)+(HombresGym*5000)
			SiNo
				res <- 0
			FinSi
	FinSegun
FinFuncion

Algoritmo Conjunto_Residencial
	// Variables
	Definir Mtlnm Como Real
	Definir Estr,CantGymM,CantGymH,CantP,Cadmin,Caseo,Cgym,Tpagar Como Entero
	Definir TpInm,gym Como Caracter
	// Inicializar
	Cadmin <- 0
	Caseo <- 0
	Cgym <- 0
	CantGymM <- 0
	CantGymH <- 0
	// Lectura de Datos
	Escribir 'Factura por Concepto de Servicios: '
	Escribir 'Ingrese los Metros Cuadrados del Inmueble: '
	Leer Mtlnm
	Escribir 'Ingrese el tipo de Inmueble (Casa)(Apartamento): '
	Leer TpInm
	Escribir 'Ingrese su Estrato Socio Economico: '
	Leer Estr
	Escribir 'Ingrese la cantidad de Personas del Predio: '
	Leer CantP
	Escribir 'Ingrese si en el Predio Usan el Gym Si(S) No(N): '
	Leer gym
	Si (gym='S' O gym='s') Entonces
		Escribir 'Ingrese la cantidad de Mujeres que usan el Gym: '
		Leer CantGymM
		Escribir 'Ingrese la cantidad de Hombres que usan el Gym: '
		Leer CantGymH
	FinSi
	Si (ValidarDatos(Mtlnm,TpInm,Estr,CantP,gym,CantGymH,CantGymM)) Entonces
		Cadmin <- CuotaAdministracion(TpInm,Mtlnm)
		Caseo <- CuotaAseo(Cadmin,Estr,Mtlnm)
		Si (gym='S' O gym='s') Entonces
			Cgym <- CuotaGimnasio(CantP,CantGymH,CantGymM)
		FinSi
	FinSi
	// Valores de Salida
	Tpagar <- Cadmin+Caseo+Cgym
	Escribir 'El pago de la Cuota de Administracion es: ',Cadmin
	Escribir 'El pago de la Cuota de Aseo es: ',Caseo
	Escribir 'El pago de la Cuota de Gym es: ',Cgym
	Escribir 'El pago Total por los tres Servicios es: ',Tpagar
FinAlgoritmo
