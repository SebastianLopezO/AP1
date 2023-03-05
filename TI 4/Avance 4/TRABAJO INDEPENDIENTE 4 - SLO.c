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
	
	Booleano Funcion ValidarDatos (MetrosCuadrados,TipoInmueble,Estrato,PersonasPredio,UsoGym,HombresGym,MujeresGym)
		//Variables
			Booleano: ds 
	
		Ds <- Verdadero
		Escribir ( '' )
		Si ( NO (MetrosCuadrados>0 Y MetrosCuadrados<1000)) Entonces
			Escribir ( 'Metros Cuadrados Erroneos, debe ingresar un dato entre 1 y 9999 ' )
			Ds <- falso
		FinSi
		Si ( NO (TipoInmueble='Casa' O TipoInmueble='Apartamento' O TipoInmueble='casa' O TipoInmueble='apartamento' O TipoInmueble='CASA' O TipoInmueble='APARTAMENTO')) Entonces
			Escribir ( 'El tipo de Inmueble solo puede ser (casa)(apartamento): ' )
			Ds <- falso
		FinSi
		Si ( NO (Estrato>=1 Y Estrato<=6)) Entonces
			Escribir ( 'El estrato es erroneo, debe ingresar entre 1 y 6  ' )
			Ds <- falso
		FinSi
		Si ( NO (PersonasPredio>0 Y PersonasPredio<100)) Entonces
			Escribir ( 'Cantidad de Personas Erroneas, debe ingresar un dato entre 1 y 99 ' )
			Ds <- falso
		FinSi
		Si ( NO (UsoGym='S' O UsoGym='N' O UsoGym='s' O UsoGym='n')) Entonces
			Escribir ( 'Decision erronea, debe ingresar S para Si y N para no ' )
			Ds <- falso
		FinSi
		Si (UsoGym='S' O UsoGym='s') Entonces
			Si ( NO (PersonasPredio>=1 Y (HombresGym+MujeresGym)<=PersonasPredio)) Entonces
				Escribir ( 'Cantidad de Personas que usan el gym erronea, debe ingresar una cantidad menor o igual a las que viven en el predio' )
				Ds <- falso
			FinSi
		FinSi
		Escribir ( '' )
		devolver (Ds)
	FinFuncion
	
	entero Funcion CuotaAdministracion (TipoInmueble,MetrosCuadrados)
		//Variables
			Entero: Admin
	
		Admin <- 0
		Si (TipoInmueble='casa' O TipoInmueble='CASA' O TipoInmueble='Casa') Entonces
			Admin <- MetrosCuadrados*2500+10000
		FinSi
		Si (TipoInmueble='apartamento' O TipoInmueble='APARTAMENTO' O TipoInmueble='Apartamento') Entonces
			Admin <- MetrosCuadrados*1500+5000
		FinSi
		devolver (Admin)
	FinFuncion
	
	entero Funcion CuotaAseo (ValorAdmin,Estrato,MetrosCuadrados)
		//Variables
			Entero: ValorMetro,PorcentajeAdmin
	
		PorcentajeAdmin <- ValorAdmin*0.10
		Si (Estrato>=1 Y Estrato<=3) Entonces
			ValorMetro <- MetrosCuadrados*1000
		FinSi
		Si (Estrato>=4 Y Estrato<=6) Entonces
			ValorMetro <- MetrosCuadrados*2000
		FinSi
		devolver (PorcentajeAdmin+ValorMetro)
	FinFuncion
	
	entero Funcion CuotaGimnasio (PersonasPredio,HombresGym,MujeresGym)
		//Variables
			Entero: PersonasGym
	
		PersonasGym <- HombresGym+MujeresGym
		Segun PersonasPredio  Hacer
			1:
				devolver (PersonasGym*30000)
			2:
				devolver (PersonasGym*25000)
			3:
				devolver (PersonasGym*20000)
			4:
				devolver (PersonasGym*15000)
			5:
				devolver (PersonasGym*10000)
			De Otro Modo:
				Si (PersonasPredio>=6) Entonces
					devolver (MujeresGym*4000)+(HombresGym*5000)
				SiNo
					devolver (0)
				FinSi
		FinSegun
	FinFuncion
	
	Algoritmo Conjunto_Residencial
		//Variables
			Definir Mtlnm Como Real
			Definir Estr,CantGymM,CantGymH,CantP,Cadmin,Caseo,Cgym,Tpagar Como Entero
			Definir TpInm,gym Como Caracter
			
		//Inicializar
			Cadmin <- 0
			Caseo <- 0
			Cgym <- 0
			CantGymM <- 0
			CantGymH <- 0
			
		//Lectura de Datos
			Escribir ( 'Factura por Concepto de Servicios: ' )
			Escribir ( 'Ingrese los Metros Cuadrados del Inmueble: ' )
			Leer (Mtlnm)
			Escribir ( 'Ingrese el tipo de Inmueble (Casa)(Apartamento): ' )
			Leer (TpInm)
			Escribir ( 'Ingrese su Estrato Socio Economico: '
			Leer (Estr)
			Escribir ( 'Ingrese la cantidad de Personas del Predio: ' )
			Leer (CantP)
			Escribir ( 'Ingrese si en el Predio Usan el Gym Si(S) No(N): ' )
			Leer (gym
			
			Si (gym='S' O gym='s') Entonces
				Escribir ( 'Ingrese la cantidad de Mujeres que usan el Gym: '
				Leer (CantGymM)
				Escribir ( 'Ingrese la cantidad de Hombres que usan el Gym: '
				Leer (CantGymH)
			FinSi
			
		Si (ValidarDatos(Mtlnm,TpInm,Estr,CantP,gym,CantGymH,CantGymM)) Entonces
			Cadmin <- CuotaAdministracion(TpInm,Mtlnm)
			Caseo <- CuotaAseo(Cadmin,Estr,Mtlnm)
			Si (gym='S' O gym='s') Entonces
				Cgym <- CuotaGimnasio(CantP,CantGymH,CantGymM)
			FinSi
		FinSi
		
		//Valores de Salida
			Tpagar <- Cadmin+Caseo+Cgym
			Escribir ( 'El pago de la Cuota de Administracion es: ',Cadmin )
			Escribir ( 'El pago de la Cuota de Aseo es: ',Caseo )
			Escribir ( 'El pago de la Cuota de Gym es: ',Cgym )
			Escribir ( 'El pago Total por los tres Servicios es: ',Tpagar )
	FinAlgoritmo


*/

#include<stdio.h>
#include<stdbool.h>
#include<string.h>


/* Name: TRABAJO INDEPENDIENTE 4 */
/* Copyright: */
/* Author: Sebastian Lopez Osorno */
/* Date: 11/05/22 11:50 */
/* Description: Conjunto Residencial */

//funciones
bool ValidarDatos(float MetrosCuadrados, char *TipoInmueble, int Estrato, int PersonasPredio, char *UsoGym, int HombresGym, int MujeresGym);
int CuotaAdministracion(char *TipoInmueble, float MetrosCuadrados);
int CuotaAseo(int ValorAdmin, int Estrato, float MetrosCuadrados);
int CuotaGimnasio(int PersonasPredio, int HombresGym, int MujeresGym);

bool ValidarDatos(float MetrosCuadrados, char *TipoInmueble, int Estrato, int PersonasPredio, char *UsoGym, int HombresGym, int MujeresGym) {
	bool Ds;
	Ds = true;
	printf("\n");

	if ((!(MetrosCuadrados>0 && MetrosCuadrados<1000))) {
		printf("Metros Cuadrados Erroneos, debe ingresar un dato entre 1 y 9999 \n");
		Ds = false;
	}
	if ((!(strcmp(TipoInmueble,"Casa")==0 || strcmp(TipoInmueble,"Apartamento")==0 || strcmp(TipoInmueble,"casa")==0 || strcmp(TipoInmueble,"apartamento")==0 || strcmp(TipoInmueble,"CASA")==0 || strcmp(TipoInmueble,"APARTAMENTO")==0))) {
		printf("El tipo de Inmueble solo puede ser (casa)(apartamento): \n");
		Ds = false;
	}
	if ((!(Estrato>=1 && Estrato<=6))) {
		printf("El Estrato es erroneo, debe ingresar entre 1 y 6  \n");
		Ds = false;
	}
	if ((!(PersonasPredio>0 && PersonasPredio<100))) {
		printf("Cantidad de Personas Erroneas, debe ingresar un dato entre 1 y 99 \n");
		Ds = false;
	}
	if ((!(strcmp(UsoGym,"S")==0 || strcmp(UsoGym,"N")==0 || strcmp(UsoGym,"s")==0 || strcmp(UsoGym,"n")==0))) {
		printf("Decision erronea, debe ingresar S para Si y N para no \n");
		Ds = false;
	}
	if ((strcmp(UsoGym,"S")==0 || strcmp(UsoGym,"s")==0)) {
		if ((!(PersonasPredio>=1 && (HombresGym+MujeresGym)<=PersonasPredio))) {
			printf("Cantidad de Personas que usan el gym erronea, debe ingresar una cantidad menor o igual a las que viven en el predio\n");
			Ds = false;
		}
	}

	printf("\n");
	return Ds;
}

int CuotaAdministracion(char *TipoInmueble, float MetrosCuadrados) {
	int Admin;
	Admin = 0;
	if ((strcmp(TipoInmueble,"casa")==0 || strcmp(TipoInmueble,"CASA")==0 || strcmp(TipoInmueble,"Casa")==0)) {
		Admin = MetrosCuadrados*2500+10000;
	}
	if ((strcmp(TipoInmueble,"apartamento")==0 || strcmp(TipoInmueble,"APARTAMENTO")==0 || strcmp(TipoInmueble,"Apartamento")==0)) {
		Admin = MetrosCuadrados*1500+5000;
	}
	return Admin;
}

int CuotaAseo(int ValorAdmin, int Estrato, float MetrosCuadrados) {
	int PorcentajeAdmin;
	int ValorMetro;
	PorcentajeAdmin = ValorAdmin*0.10;
	if ((Estrato>=1 && Estrato<=3)) {
		ValorMetro = MetrosCuadrados*1000;
	}
	if ((Estrato>=4 && Estrato<=6)) {
		ValorMetro = MetrosCuadrados*2000;
	}
	return PorcentajeAdmin+ValorMetro;

}

int CuotaGimnasio(int PersonasPredio, int HombresGym, int MujeresGym) {
	int PersonasGym;
	PersonasGym = HombresGym+MujeresGym;
	switch (PersonasPredio) {
	case 1:
		return PersonasGym*30000;
		break;
	case 2:
		return PersonasGym*25000;
		break;
	case 3:
		return PersonasGym*20000;
		break;
	case 4:
		return PersonasGym*15000;
		break;
	case 5:
		return PersonasGym*10000;
		break;
	default:
		if ((PersonasPredio>=6)) {
			return (MujeresGym*4000)+(HombresGym*5000);
		} else {
			return 0;
		}
	}
}

int main() {
	/* Variables */
	int Cadmin, CantGymH, CantGymM, CantP, Caseo, Cgym, Estr, Tpagar;
	float Mtlnm;
	char gym[1];
	char TpInm[12];
	
	/* Inicializar */
	Cadmin = 0;
	Caseo = 0;
	Cgym = 0;
	CantGymM = 0;
	CantGymH = 0;

	/* Lectura de Datos */
	printf("Factura por Concepto de Servicios: \n");
	printf("Ingrese los Metros Cuadrados del Inmueble: \n");
	scanf("%f",&Mtlnm);
	printf("Ingrese el tipo de Inmueble (Casa)(Apartamento): \n");
	scanf("%s",TpInm);
	printf("Ingrese su Estrato Socio Economico: \n");
	scanf("%i",&Estr);
	printf("Ingrese la cantidad de Personas del Predio: \n");
	scanf("%i",&CantP);
	printf("Ingrese si en el Predio Usan el Gym Si(S) No(N): \n");
	scanf("%s",gym);
	if ((strcmp(gym,"S")==0 || strcmp(gym,"s")==0)) {
		printf("Ingrese la cantidad de Mujeres que usan el Gym: \n");
		scanf("%i",&CantGymM);
		printf("Ingrese la cantidad de Hombres que usan el Gym: \n");
		scanf("%i",&CantGymH);
	}
	if ((ValidarDatos(Mtlnm,TpInm,Estr,CantP,gym,CantGymH,CantGymM))) {
		Cadmin = CuotaAdministracion(TpInm,Mtlnm);
		Caseo = CuotaAseo(Cadmin,Estr,Mtlnm);
		if ((strcmp(gym,"S")==0 || strcmp(gym,"s")==0)) {
			Cgym = CuotaGimnasio(CantP,CantGymH,CantGymM);
		}
	}
	
	/* Valores de Salida */
	Tpagar = Cadmin+Caseo+Cgym;
	printf("El pago de la Cuota de Administracion es: %i\n",Cadmin);
	printf("El pago de la Cuota de Aseo es: %i\n",Caseo);
	printf("El pago de la Cuota de Gym es: %i\n",Cgym);
	printf("El pago Total por los tres Servicios es: %i\n",Tpagar);
	return 0;
}





