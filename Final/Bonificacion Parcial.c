#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Name: Auxilio
//CopyRight:
//	Autor: Sebastian Lopez Osorno
//	Grupo:25
void CALCULO_PROMEDIO(float*Prm, int*T_c){
	float Nota_1,Nota_2;
	int Cred_1,Cred_2;
	
	printf("Ingrese la nota de la asignatura#1: ");
	scanf("%f",&Nota_1);
	printf("Ingrese la cantidad de creditos de la asignatura#1: ");
	scanf("%d",&Cred_1);
	printf("Ingrese la nota de la asignatura#2: ");
	scanf("%f",&Nota_2);
	printf("Ingrese la cantidad de creditos de la asignatura#2: ");
	scanf("%d",&Cred_2);
	
	*T_c=Cred_1+Cred_2;
	*Prm=(Nota_1*Cred_1+Nota_2*Cred_2)/(*T_c);
	return;
}

int CALCULO_PUNTOS(float Pr){
	int Punt;
	
	if(Pr>4){
		Punt=5;
	}else{
		if(Pr>3.5 && Pr<=4.0){
			Punt=3;
		}else{
			if(Pr<=3.0 && Pr>=3.0){
				Punt=2;
			}
		}
	}
	return Punt;
}

int main(){
	int Vr_Aux,Tot_Cr, Puntos, Vr_Cr;
	float Prom;
	
	Prom=0;
	Tot_Cr=0;
	
	CALCULO_PROMEDIO(&Prom,&Tot_Cr);
	Puntos=CALCULO_PUNTOS(Prom);
	Vr_Cr=Tot_Cr*100000;
	if(Tot_Cr>4){
		switch(Puntos){
			case 5:
				Vr_Aux=Vr_Cr*0.20;
				break;
			case 3:
				Vr_Aux=Vr_Cr*0.10;
				break;
			case 2:
				Vr_Aux=Vr_Cr*0.02;
				break;
		}
	}
	printf("El valor del auxilio es de %d",Vr_Aux);
}

