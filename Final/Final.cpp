/*
							
	Modelamiento					
						
						
	Tipo de dato		descripcion		ID	
	D.E		Horario de ingreso al metro		IMhora	
			Tipo de tiquete metro		TPmetro	
			estrato		estrato	
			estado de empleo		Eempleo	
			edad		edad	
			estado civil		Ecivil	
	D.A		descuento por estado civil		Dcivil	
			valor por tiquetes integrados		Vti	
			valor por tiquetes sencillos		Vts	
			total de aporte de los usuarios		Tau	
	D.S		Auxilio economico por edad y estrato		AuxEE	
			Aporte al metro según estrato		AMe	
			Valor tiquete con descuento y aporte		VTt	
			total personas beneficiadas con el auxilio		Tpaux	
			total general del auxilio		sumAux	
			total de aporte para la administracion municipal		Tam	
						



Algoritmo BeneficiosMetro
	Definir VTA,VTti,VTtsVTT,VT,cont,estrato,edad,Dcivil,Vti,Vts,Tau,AuxEE,AMe,VTT,Tpaux,sumAux,Tam Como Entero
	Definir IMhora Como Real
	Definir TPmetro,Ecivil,Eempleo,res Como Caracter
	Escribir 'Ingrese la hora en el siguiente formato {HH.MM}: '
	Leer IMhora
	cont <- 0
	Tau <- 0
	sumAux <- 0
	Tpaux <- 0
	Mientras IMhora>=5 Y IMhora<12 Hacer
		cont <- cont+1
		Escribir ''
		Escribir 'Persona#',cont
		Escribir 'Ingrese su estrato socio economico: '
		Leer estrato
		Escribir 'Ingrese (si-no) para determinar su estado de empleo: '
		Leer Eempleo
		// Beneficio
		Si estrato<4 Y Eempleo='no' Entonces
			Escribir 'Ingrese su edad para determinar el auxilio economico a dar: '
			Leer edad
			Escribir 'Ingrese su estado civil: '
			Leer Ecivil
			Segun estrato  Hacer
				1:
					Si edad<18 Entonces
						AuxEE <- 180000
					FinSi
					Si edad>=18 Entonces
						AuxEE <- 230000
					FinSi
				2:
					Si edad<18 Entonces
						AuxEE <- 150000
					FinSi
					Si edad>=18 Entonces
						AuxEE <- 200000
					FinSi
				3:
					Si edad<18 Entonces
						AuxEE <- 120000
					FinSi
					Si edad>=18 Entonces
						AuxEE <- 170000
					FinSi
				De Otro Modo:
					AuxEE <- 0
			FinSegun
			Tpaux <- Tpaux+1
		FinSi
		Escribir 'El valor total del auxilio economico es de: ',AuxEE
		sumAux <- sumAux+AuxEE
		// valor tiquete
		Vti <- 0
		Vts <- 0
		Repetir
			Escribir '¿Que tipo de tiquete desea comprar? (sencillo o integrado):'
			Leer TPmetro
			Si TPmetro='sencillo' Entonces
				VT <- 1800
				Vts <- Vts+1
			SiNo
				Si TPmetro='integrado' Entonces
					VT <- 2200
					Vti <- Vti+1
				FinSi
			FinSi
			// Aporte
			Segun estrato  Hacer
				1,2,3:
					aporte <- 0.05
					AMe <- aporte*VT
					VTT <- AMe+VT
					Escribir 'El valor inicial del tiquete ',TPmetro,'$ es de: ',VT,' pero debido al aporte del 5% quedo en: ',VTT,'$'
				4,5,6:
					aporte <- 0.10
					AMe <- aporte*VT
					VTT <- AMe+VT
					Escribir 'El valor inicial del tiquete ',TPmetro,'$ es de: ',VT,' pero debido al aporte del 10% quedo en: ',VTT,'$'
				De Otro Modo:
					aporte <- 0
					AMe <- aporte*VT
					VTT <- AMe+VT
					Escribir 'El valor inicial del tiquete ',TPmetro,'$ es de: ',VT,' pero debido al aporte del 0% quedo en: ',VTT,'$'
			FinSegun
			Si estrato<4 Y Eempleo='no' Y (Ecivil='casado' O Ecivil='casada') Entonces
				Dcivil <- 0.5*VT
			SiNo
				Dcivil <- 0
			FinSi
			Escribir ''
			Escribir '¿Desea comprar otro tiquete?(si-no): '
			Leer res
		Hasta Que res='no'
		VTti <- Vti*2200*aporte
		VTts <- 1800*aporte
		Escribir 'El valor total a pagar por ',Vti,' integrados es de: ',Vti*2200,' pero con el aporte quedo en ',VTti
		Escribir 'El valor total a pagar por ',Vts,' sencillo es de: ',Vti*2200,' pero con el aporte quedo en ',VTts
		VTA <- VTti+VTts-Dcivil
		Tau <- Tau+VTA
		Escribir 'Ingrese la hora en el siguiente formato {HH.MM}: '
		Leer IMhora
	FinMientras
	Tam <- sumAux-Tau
	Escribir 'Total de dinero que va a aportar la administracion municipal para cubir el total de beneficios',Tam
	Escribir 'Informar el total de personas beneficiadas con el auxilio ',Tpaux
	Escribir 'Informe del total general del auxilio ',sumAux
FinAlgoritmo
*/

#include<iostream>
using namespace std;


int main() {
	int ame;
	float aporte;
	int auxee;
	int cont;
	int dcivil;
	string ecivil;
	int edad;
	string eempleo;
	int estrato;
	float imhora;
	string res;
	int sumaux;
	int tam;
	int tau;
	int tpaux;
	string tpmetro;
	int vt;
	int vta;
	int vti;
	int vts;
	int vtt;
	int vtti;
	float vtts;
	int vttsvtt;
	cout << "Ingrese la hora en el siguiente formato {HH.MM}: " << endl;
	cin >> imhora;
	cont = 0;
	tau = 0;
	sumaux = 0;
	tpaux = 0;
	while (imhora>=5 && imhora<12) {
		cont = cont+1;
		cout << "" << endl;
		cout << "Persona#" << cont << endl;
		cout << "Ingrese su estrato socio economico: " << endl;
		cin >> estrato;
		cout << "Ingrese (si-no) para determinar su estado de empleo: " << endl;
		cin >> eempleo;
		// Beneficio
		if (estrato<4 && eempleo=="no") {
			cout << "Ingrese su edad para determinar el auxilio economico a dar: " << endl;
			cin >> edad;
			cout << "Ingrese su estado civil: " << endl;
			cin >> ecivil;
			switch (estrato) {
			case 1:
				if (edad<18) {
					auxee = 180000;
				}
				if (edad>=18) {
					auxee = 230000;
				}
				break;
			case 2:
				if (edad<18) {
					auxee = 150000;
				}
				if (edad>=18) {
					auxee = 200000;
				}
				break;
			case 3:
				if (edad<18) {
					auxee = 120000;
				}
				if (edad>=18) {
					auxee = 170000;
				}
				break;
			default:
				auxee = 0;
			}
			tpaux = tpaux+1;
		}
		cout << "El valor total del auxilio economico es de: " << auxee << endl;
		sumaux = sumaux+auxee;
		// valor tiquete
		vti = 0;
		vts = 0;
		do {
			cout << "¿Que tipo de tiquete desea comprar? (sencillo o integrado):" << endl;
			cin >> tpmetro;
			if (tpmetro=="sencillo") {
				vt = 1800;
				vts = vts+1;
			} else {
				if (tpmetro=="integrado") {
					vt = 2200;
					vti = vti+1;
				}
			}
			// Aporte
			switch (estrato) {
			case 1: case 2: case 3:
				aporte = 0.05;
				ame = aporte*vt;
				vtt = ame+vt;
				cout << "El valor inicial del tiquete " << tpmetro << "$ es de: " << vt << " pero debido al aporte del 5% quedo en: " << vtt << "$" << endl;
				break;
			case 4: case 5: case 6:
				aporte = 0.10;
				ame = aporte*vt;
				vtt = ame+vt;
				cout << "El valor inicial del tiquete " << tpmetro << "$ es de: " << vt << " pero debido al aporte del 10% quedo en: " << vtt << "$" << endl;
				break;
			default:
				aporte = 0;
				ame = aporte*vt;
				vtt = ame+vt;
				cout << "El valor inicial del tiquete " << tpmetro << "$ es de: " << vt << " pero debido al aporte del 0% quedo en: " << vtt << "$" << endl;
			}
			if (estrato<4 && eempleo=="no" && (ecivil=="casado" || ecivil=="casada")) {
				dcivil = 0.5*vt;
			} else {
				dcivil = 0;
			}
			cout << "" << endl;
			cout << "¿Desea comprar otro tiquete?(si-no): " << endl;
			cin >> res;
		} while (res!="no");
		vtti = vti*2200*aporte;
		vtts = 1800*aporte;
		cout << "El valor total a pagar por " << vti << " integrados es de: " << vti*2200 << " pero con el aporte quedo en " << vtti << endl;
		cout << "El valor total a pagar por " << vts << " sencillo es de: " << vti*2200 << " pero con el aporte quedo en " << vtts << endl;
		vta = vtti+vtts-dcivil;
		tau = tau+vta;
		cout << "Ingrese la hora en el siguiente formato {HH.MM}: " << endl;
		cin >> imhora;
	}
	tam = sumaux-tau;
	cout << "Total de dinero que va a aportar la administracion municipal para cubir el total de beneficios" << tam << endl;
	cout << "Informar el total de personas beneficiadas con el auxilio " << tpaux << endl;
	cout << "Informe del total general del auxilio " << sumaux << endl;
	return 0;
}

