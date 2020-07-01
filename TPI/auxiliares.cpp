#include <iostream>
#include <vector>

#include "definiciones.h"
#include "auxiliares.h"

// aqui se pueden ubicar todas las funciones auxiliares de soporte para la resolucion de los ejercicios

//Funciones auxiliares para esSenal

bool esValida(senial s, int profundidad, int frec){
	bool res = true;
	/*
	if(frecValida(frec)){
		cout << "frecuencia v'alida" << endl;
	} else {
		cout << "frecuencia inv'alida" << endl;
	}
	if(profValida(profundidad)){
		cout << "profundidad v'alida" << endl;
	} else {
		cout << "profundidad inv'alida" << endl;
	}
	if(enRango(s,profundidad)){
		cout << "en rango" << endl;
	} else {
		cout << "fuera de rango" << endl;
	}
	if(duraMasDe(s,frec,1)){
		cout << "dura m'as de un segundo" << endl;
	} else {
		cout << "no dura m'as de un segundo" << endl;
	}
	*/
	if(!(frecValida(frec) && profValida(profundidad) &&
		enRango(s,profundidad) && duraMasDe(s,frec,1))){
		res = false;
	}
	return res;
}

bool frecValida(int frec){
	return (frec==10^2);
}

bool enRango(senial s, int profundidad){
	int i = 0;
	int n = s.size();
	bool enrango = true;
	int cotasup = pow(2,(profundidad-1))-1;
	int cotainf = (-1)*pow(2,(profundidad-1));
	while(i<n && enrango){
		int amplitud = s[i];
		if((amplitud>cotasup) || (amplitud<cotainf)){
			enrango = false;
		}
		i++;
	}
	return enrango;
}

bool profValida(int profundidad){
	bool res = false;
	if(profundidad==8 || profundidad==16 || profundidad==32){
		res = true;
	}
	return res;
}

bool duraMasDe(senial s, int frec, float t){
	int n = s.size();
	return (n >= (frec*t));
}
