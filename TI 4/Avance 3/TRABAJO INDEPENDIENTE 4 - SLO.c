/*
	Name: TRABAJO INDEPENDIENTE 4
	Copyright:
	Author: Sebastian Lopez Osorno
	Date: 11/05/22 11:50
	Description: 
	
		REQUERIMIENTO:
			Un Conjunto residencial, desea saber cuánto debe facturar por concepto de: diversos servicio que 
			se prestan a uno de los predios que el conjunto posee, dependiendo de ciertos gastos que se deben facturar.
	
		1er gasto. Cuota de administración:
			El valor a cancelar por concepto de cuota de administración, depende de los metros cuadrados 
			del inmueble (Mt) y del tipo de inmueble ya sea “apartamento” o “casa”. Su fórmula es:
		 	
			Administración = (Mt x 1.500 + 5.000) Cuando el tipo del inmueble sea = “apartamento”
			Administración = (Mt x 2.500 + 10.000) Cuando el tipo del inmueble sea = “casa”
		
		2do gasto. Cuota de Aseo: 
			El valor a cancelar por concepto de cuota de aseo se calcula así: se toma el 10% del valor 
			de la cuota de administración y por cada metro cuadrado del predio se le suman un valor 
			dependiendo del estrato de la vivienda así: Estrato Valor a sumar x cada/metro cuadrado
			
			1,2, 3 1.000 pesos.
			4,5 y 6 2.000 pesos.
		
		3er. Gasto. Cuota Gimnasio: 
			Corresponde al valor a cancelar por derechos de gimnasio, el cual depende de 
			la cantidad de personas que viven en el predio según la siguiente tabla:
			
	
			
			Cantidad de
			habitantes			Valor derecho
			del predio			Uso de gimnasio
			1 					30.000 (por persona)
			2 					25.000 (por persona)
			3 					20.000 (por persona)
			4 					15.000 (por persona)
			5 					10.000 (por persona)
			6 o más 			5.000 (por persona hombre), 4.000 (por persona mujer)
			
			Se debe imprimir el valor a pagar por concepto de cada servicio y el total de
			todos los servicios
		
		NOTAS

		Nota 1: 
			Se debe realizar todas las actividades relacionadas con la resolución de problemas
			por computador y hacer uso de todas las estructuras vistas hasta el momento.
			
		Nota 2: 
			El total a pagar por concepto de servicios es igual a la suma de los tres gastos.
			
		Nota 3: 
			Hacer uso de decisiones anidadas no compuesta para el cálculo de la cuota de aseo.
			
		Nota 4: 
			hacer uso de decisiones múltiples para el cálculo de la cuota de gimnasio. La cuota
			de gimnasio solo se calcula si el usuario manifiesta hacer uso de este servicio 
			(hacer uso de una variable carácter para averiguar por el uso del servicio de gimnasio,
			donde sus posibles valores son ‘S’ o ‘N’ Se debe tener en cuenta la cantidad de 
			personas del grupo familiar que van hacer uso del gimnasio.
			
		Nota 5: 
			Para el tipo de inmueble se debe manejar el dato completo “casa” o “apartamento”.
			
		Nota 6: 
			Tenga en cuenta que todos los datos susceptibles de validación deben ser validados 
			haciendo uso de decisiones compuestas.
			
	Datos

			Cuota de Administracion
				Metros Cuadrados
				Tipo de Inmueble("Casa", "Apartamento")
			Cuota de Aseo
				10% de Cuota de Administracion
				Valor Extra por Metro Cuadrado
					Estrato
			Cuota de Gym
				Cantidad de Personas del Predio
			Total a Pagar por Servicios
	
	Analisis

		Modelamiento

			Tipo 				Nombre 						ID

			DE		
					Metros cuadrados del Inmueble			MtInm
					Tipo de Inmueble						TpInm
					Estrato	Socio Economico					Estr
					Cantidad de Personas del Predio			CantP
					Uso del Gimnasio						Gym
					Cantidad de Mujeres que usan el Gym		CantGymM
					Cantidad de Hombres que usan el Gym		CantGymH

			DA
					10% de Cuota Admin						Padmin
					Valor Extra por Metro Cuadrado			Vmetro
					Cantidad de Personas que usan el Gym	CantGymP

			DS		
					Cuota de Administracion					Cadmin
					Cuota de Aseo							Caseo
					Cuota Gym								Cgym
					Total a pagar por servicios				Tpagar

		Especificaciones

			PreCondiciones									PostCondiciones
			
			MtInm e {real>0}								Cadmin e {entero}
			TpInm e {cadena[“casa” , “apartamento”]}		Caseo e {entero}
			Estr e {0>entero<7}								Cgym e {entero}
			CantP e {entero>0}								Tpagar e {entero}
			Gym e {logico}	
			CantGymM e {entero>=0}	
			CantGymH e {entero>=0}	
			Padmin e {real>0}
			Vmetro e {entero>0}
			CantGymP e e {entero>=0}	

		Proceso
		
			Cadmin <- (MtInm*1500+5000)					Cuando TpInm= 'apartamento'
			Cadmin <- (MtInm*2500+10000)				Cuando TpInm= 'casa'
			Padmin <- Cadmin*0.10
			Vmetro <- MtInm*1000						Cuando Estr= 1 or Estr=2 or Estr=3
			Vmetro <- MtInm*2000						Cuando Estr= 4 or Estr=5 or Estr=6
			Caseo <- Padmin + Vmetro
			CantGymP <- CantGymH +CantGymM
			Cgym <- CantGymP*30000						Cuando CantP=1
			Cgym <- CantGymP*25000						Cuando CantP=2
			Cgym <- CantGymP*20000						Cuando CantP=3
			Cgym <- CantGymP*15000						Cuando CantP=4
			Cgym <- CantGymP*10000						Cuando CantP=5
			Cgym <- (CantGymM*4000)+(CantGymH*5000)		Cuando CantP>=6

	Diseño
		// Name: TRABAJO INDEPENDIENTE 4
		// Copyright:
		// Author: Sebastian Lopez Osorno
		// Date: 11/05/22 11:50
		// Description: Conjunto Residencial
		
		booleano Funcion_ValidarDatos (Mtlnm,TpInm,Estr,CantP,gym)
		Inicio
			Variables:
				booleano: ds
		
			ds <- Verdadero
			Escribir ( ''
			Si ( NO (Mtlnm>0 Y Mtlnm<1000)) Entonces
				Escribir ( 'Metros Cuadrados Erroneos, debe ingresar un dato entre 1 y 9999 ' )
				ds <- falso
			FinSi
			Si ( NO (TpInm='Casa' O TpInm='Apartamento' O TpInm='casa' O TpInm='apartamento' O TpInm='CASA' O TpInm='APARTAMENTO')) Entonces
				Escribir ( 'El tipo de Inmueble solo puede ser (casa)(apartamento): ' )
				ds <- falso
			FinSi
			Si ( NO (Estr>=1 Y Estr<=6)) Entonces
				Escribir ( 'El estrato es erroneo, debe ingresar entre 1 y 6  '
				ds <- falso
			FinSi
			Si ( NO (CantP>0 Y CantP<100)) Entonces
				Escribir ( 'Cantidad de Personas Erroneas, debe ingresar un dato entre 1 y 99 ' )
				ds <- falso
			FinSi
			Si ( NO (gym='S' O gym='N' O gym='s' O gym='n')) Entonces
				Escribir ( 'Decision erronea, debe ingresar S para Si y N para no ' )
				ds <- falso
			FinSi
			devolver ( ds )
			Escribir ( '' )
		Fin
		
		entero Funcion_CuotaAdministracion (TipoInmueble,MetroCuadrado)
		Inicio
			Variables:	
				Entero: admin
		
			admin <- 0
			Si (TipoInmueble='casa' O TipoInmueble='CASA' O TipoInmueble='Casa') Entonces
				admin <- MetroCuadrado*2500+10000
			FinSi
			Si (TipoInmueble='apartamento' O TipoInmueble='APARTAMENTO' O TipoInmueble='Apartamento') Entonces
				admin <- MetroCuadrado*1500+5000
			FinSi
			devolver ( admin )
		Fin
		
		entero Funcion_CuotaAseo (ValorAdmin,Estrato,MetroCuadrados)
		Inicio
			Variables:
				Entero: ValorMetro,PorcentajeAdmin
		
			PorcentajeAdmin <- ValorAdmin*0.10
			Si (Estrato>=1 Y Estrato<=3) Entonces
				ValorMetro <- MetroCuadrados*1000
			FinSi
			Si (Estrato>=4 Y Estrato<=6) Entonces
				ValorMetro <- MetroCuadrados*2000
			FinSi
			devolver ( PorcentajeAdmin+ValorMetro )
		Fin
		
		entero Funcion_CuotaGimnasio (PersonasPredio)
		Inicio
			Variables:
				Entero: CantGymP,CantGymM,CantGymH
		
			Escribir ( 'Ingrese la cantidad de Mujeres que usan el Gym: '
			Leer (CantGymM
			Escribir ( 'Ingrese la cantidad de Hombres que usan el Gym: '
			Leer (CantGymH
			CantGymP <- CantGymM+CantGymH
			Segun PersonasPredio  Hacer
				1:
					devolver ( PersonasPredio*30000 )
					salir
				2:
					devolver ( PersonasPredio*25000 )
					salir
				3:
					devolver ( PersonasPredio*20000 )
					salir
				4:
					devolver ( PersonasPredio*15000 )
					salir
				5:
					devolver ( PersonasPredio*10000 )
					salir
				De Otro Modo:
					Si (PersonasPredio>=6) Entonces
						devolver ( (CantGymM*4000)+(CantGymH*5000) )
					SiNo
						devolver ( 0 )
					FinSi
					salir
			FinSegun
		Fin
		
		Algoritmo_Conjunto_Residencial
		Inicio
			Variables:
				Real: Mtlnm
				Entero: Estr,CantP,Cadmin,Caseo,Cgym,Tpagar
				Cadena: TpInm
				Caracter: gym
		
			Escribir ( 'Factura por Concepto de Servicios: ' )
			Escribir ( 'Ingrese los Metros Cuadrados del Inmueble: ' )
			Leer (Mtlnm)
			Escribir ( 'Ingrese el tipo de Inmueble (Casa)(Departamento): ' )
			Leer (TpInm)
			Escribir ( 'Ingrese su Estrato Socio Economico: ' )
			Leer (Estr)
			Escribir ( 'Ingrese la cantidad de Personas del Predio: ' )
			Leer (CantP)
			Escribir ( 'Ingrese si en el Predio Usan el Gym Si(S) No(N): ' )
			Leer (gym)
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
			Escribir ( 'El pago de la Cuota de Administracion es: ',Cadmin )
			Escribir ( 'El pago de la Cuota de Aseo es: ',Caseo )
			Escribir ( 'El pago de la Cuota de Gym es: ',Cgym )
			Escribir ( 'El pago Total por los tres Servicios es: ',Tpagar )
		Fin

*/

