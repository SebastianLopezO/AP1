Algoritmo EstadisticasPoli
	// variables
	Definir estadoCivil,estadoPsA,genero,programa Como Caracter
	Definir edad,contM18F,contIC,contIMF,contCCC,edadMI,edadMinI,cont Como Entero
	contCCC <- 0
	contIC <- 0
	contM18F <- 0
	contIMF <- 0
	edadMI <- 0
	edadMinI <- 200
	cont<-1
	Mientras cont<=100 Hacer
		Escribir 'Estudiante#',cont
		Escribir ''
		Escribir 'Ingrese su carrera 1.Informatica || 2. Civil y Control  : '
		Leer programa
		Escribir 'Ingrese su edad: '
		Leer edad
		Escribir 'Ingrese su genero (mujer-hombre): '
		Leer genero
		Escribir 'Ingrese su estado frente a las sustancias psicoactivas (si-no): '
		Leer estadoPsA
		Escribir 'Ingrese su estado civil 1.soltero || 2.casado || 3.viudo || 4.union libre : '
		Leer estadoCivil
		Si (edad<18) Entonces
			contM18F <- contM18F+1
		FinSi
		Si (Minusculas(programa)='informatica') Entonces
			Si (edad>edadMI) Entonces
				edadMI <- edad
			FinSi
			Si (edad<edadMinI) Entonces
				edadMinI <- edad
			FinSi
		FinSi
		Si (Minusculas(programa)='informatica' Y Minusculas(estadoCivil)='casado') Entonces
			contIC <- contIC+1
		FinSi
		Si (Minusculas(programa)='informatica' Y Minusculas(estadoPsA)='si') Entonces
			contIMF <- contIMF+1
		FinSi
		Si (Minusculas(estadoCivil)='casado' Y Minusculas(programa)='control y civil') Entonces
			contCCC <- contCCC+1
		FinSi
		Escribir ''
		cont=cont+1
	FinMientras
	
	Escribir 'Hay ',contM18F,' estudiantes menores de 18 a?os que fuman'
	Escribir 'Hay ',contIC,' estudiantes del programa Informatica que son casados'
	Escribir 'Hay ',contIMF,' estudiantes del programa Informatica que son mujeres y fuman'
	Escribir 'Hay ',contCCC,' estudiantes Hombres del programa Control y Civil que son casados'
	Escribir 'La menor edad del grupo de estudiantes de informatica es: ',edadMinI,' a?os'
	Escribir 'La mayor edad del grupo de estudiantes de informatica es: ',edadMI,' a?os'
FinAlgoritmo