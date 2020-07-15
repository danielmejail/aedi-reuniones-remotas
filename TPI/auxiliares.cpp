#include <iostream>
#include <vector>

#include "definiciones.h"
#include "auxiliares.h"

// aqui se pueden ubicar todas las funciones auxiliares de soporte para la
// resolucion de los ejercicios


//-----Otras funciones auxiliares-----

int absoluto(int e){
	int absol = e;
	if(e<0){
		absol = (-1)*absol;
	}
	return absol;
}


//-----Ejercicio01-----

bool esValida(senial s, int profundidad, int frec){
	bool res = true;
	if(!(frecValida(frec) && profValida(profundidad) &&
		enRango(s,profundidad) && duraMasDe(s,frec,1))){
		res = false;
	}
	return res;
}

bool frecValida(int frec){
	return (frec==10);
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

//-----Ejercicio02-----

bool superaUmbral(senial s, int umbral){
	return (tono(s) > umbral);
}

float tono(senial s){
	// asume s.size()>0
	float promedio = 0.0;
	int largo = s.size();
	if(largo > 0){
		int suma = 0;
		for(int i=0; i<largo; i++){
			suma = suma + absoluto(s[i]);
		}
		promedio = (1.0*suma)/largo;
	}
	return promedio;
}



//-----Ejercicio03-----
//typedef vector<pair<senial,int>> reunion

bool reunionValida(reunion r, int prof, int freq){
	bool res = false;
	int cant_de_hablantes = r.size();
	if((cant_de_hablantes>0) && esMatriz(r) &&
			senalesValidas(r, prof, freq)
			&& hablantesDeReunionValidos(r, prof, freq)){
		res = true;
	}
	return res;
}

bool esMatriz(vector<pair<senial,int>> r){
	int dim = r.size();//cantidad de segnales
	if(dim == 0){
		//para toda pos v'alida de la sec se cumple
		//trivialmente lo pedido, aunque no sea reunion...
		return true;
	} else {
		int largo_fila_0 = (get<0>(r[0])).size();
		bool res = true;
		for(int i=0; i<dim; i++){
			int largo_fila_i = (get<0>(r[i])).size();
			if(largo_fila_i != largo_fila_0){
				res = false;
			}
		}
		return res;
	}
}
bool senalesValidas(reunion r, int prof, int freq){
	int dim = r.size();
	if(dim == 0){
		return true;
	} else {
		bool res = true;
		for(int i=0; i<dim; i++){
			senial s = get<0>(r[i]);
			if(!esValida(s, prof, freq)){
				res = false;
			}
		}
		return res;
	}
}
bool hablantesDeReunionValidos(reunion r, int prof, int freq){
	int dim = r.size();
	if(dim == 0){
		return true;
	} else {
		bool res = true;
		for(int i=0; i<dim; i++){
			int id_num = get<1>(r[i]);
			if(id_num>=dim || id_num<0){
				res = false;
			}
			for(int j=i; j<dim; j++){
				int id_otro = get<1>(r[j]);
				if((id_otro == id_num) && (j!=i)){
					res = false;
				}
			}
		}
		return res;
	}
}

//-----Ejercicio04-----

void acelerarSenal(senial &s, int prof, int freq){
	int largo_original = s.size();
	int largo_final = largo_original/2;
	for(int i=0; i<largo_final; i++){
		s[i] = s[(2*i+1)];
		//esto est'a bien definido: 
		//si i<largo_final, 2i+1<largo_original
	}
	s.resize(largo_final);// se trunca el resto del vector
}

//-----Ejercicio05-----

senial ralentizarSenal(senial s, int prof, int freq){
	// Dos opciones de implementaci'on: ir insertando el valor
	// interpolante en las posiciones impares moviendo los elementos
	// hacia la derecha, creando un nuevo espacio para el nuevo valor,
	// o bien crear un nuevo vector con los valores deseados en los
	// lugares deseados. Adoptamos la segunda forma. En caso de modificar
	// la implementaci'on para hacerlo de la otra manera, recordar
	// cambiar el tipo: deber'ia ser void y se deber'ia pasar el valor
	// de s por referencia
	int largo = s.size();
	senial sigRalent = {};
	int i = 0;
	while(i<largo-1){
		int valorInterpolado = (s[i] + s[i+1])/2;
		sigRalent.push_back(s[i]);
		sigRalent.push_back(valorInterpolado);
		i++;
	}
	sigRalent.push_back(s[i]);//agregar el valor que faltaba al final
	return sigRalent;
}

//-----Ejercicio06-----

//-----Ejercicio07-----

//-----Ejercicio08-----

bool noPerteneceANinguno(int k, vector<intervalo> intervalos){
	// ver haySilencioQueLoContiene m'as abajo
	bool res = true;
	int cant_de_intervalos = intervalos.size();
	for(int i=0; i<cant_de_intervalos; i++){
		int comienzo = get<0>(intervalos[i]);
		int fin = get<1>(intervalos[i]);
		if((comienzo <= k) && (k <= fin)){
			res = false;
		}
	}
	return res;
}

//-----Ejercicio09-----

bool seRespetan(reunion r, hablante h1, hablante h2, int freq, int umbral){
	// se asume que r es una reuni'on v'alida, con lo que
	// las longitudes de las segnales de h1 y de h2 deben ser iguales
	// el resultado es sim'etrico en h1 y en h2
	bool res = true;
	int largo_de_sig = get<0>(r[h1]).size();
	senial sig1 = get<0>(r[h1]);
	senial sig2 = get<0>(r[h2]);
	for(int i=0; i<largo_de_sig; i++){
		if(!haySilencioQueLoContiene(sig1, i, freq, umbral)
			&& !haySilencioQueLoContiene(sig2, i, freq, umbral)){
			res = false;
		}
	}
	return res;
}

bool haySilencioQueLoContiene(senial s, int i, int freq, int umbral){
	vector<intervalo> intervalos = calcularSilencios(s, freq, umbral);
	return !noPerteneceANinguno(i, intervalos);
}

vector<intervalo> calcularSilencios(senial s, int freq, int umbral){
	// esta funci'on es utilizada tanto por haySilencioQueLoContiene
	// como silencios del ejercicio 08
	// intervaloEnRango implica que los extremos de un intervalo
	// (x,y) deben cumplir 0 <= x < y <= |s|-1
	vector<pair<int,int> > intervalos = {};
	int largo = s.size();
	int i = 0;
	while(i<largo){
		if(absoluto(s[i])<umbral){
			int comienzo = i;
			while((absoluto(s[i])<umbral) && (i<largo)){
				i++;
			}
			int fin = i-1;
			if(fin - comienzo > 0){
				intervalo inter = make_pair(comienzo,fin);
				// incluye extremos
				intervalos.push_back(inter);
			}
		} else {
			i++;
		}
	}
	return intervalos;
}


//-----Ejercicio10-----

senial subsenal(senial s, int i, int j){
	// devuelve la subsegnal que contiene los elementos de i (incluido)
	// a j (excluido)
	senial subSig = {};
	for(int k=i; k<j; k++){
		subSig.push_back(s[k]);
	}
	return subSig;
}

bool esPasajePorCero(senial s, int i){
	// se asume que i-1 y que i+1 son posiciones v'alidas de la segnal
	int signo_a_izq = signo(s[i-1]);
	int signo_a_der = signo(s[i+1]);
	return (signo_a_izq*signo_a_der == -1);
}

int distancia(int j, int i){
	return absoluto(i-j);
}

int signo(int i){
	if(i < 0){
		return -1;
	} else if(i > 0){
		return 1;
	} else {
		return 0;
	}
}

int promediarSenalEn(senial s, int a){
	// Devuelve el valor promedio (parte entera) correspondiente a
	// una posici'on interior. Si 
	int j = masCercanoAnteriorNoNulo(s,a);
	int k = masCercanoPosteriorNoNulo(s,a);
	if(distancia(j,k)<=5){
		return (s[k]+s[j])/2;
	} else {
		// Este comportamiento no est'a mencionado expl'icitamente
		// en la especificaci'on, s'olo evita que se indefina
		// la funci'on para algunos valores de los par'ametros,
		// aunque talvez no sea llamada con tales valores.
		return s[a];
	}
}

int masCercanoAnteriorNoNulo(senial s, int a){
	// se asume que a > 0
	int j = a;
	while(s[j]==0){
		j--;
	}
	return j;
}

int masCercanoPosteriorNoNulo(senial s, int a){
	// se asume que a < |s|-1
	int k = a;
	while(s[k]==0){
		k++;
	}
	return k;
}

//-----Ejercicio11-----

int mediana(senial b){
	// no asume que b est'a ordenada
	int largo = b.size();
	ordenarSenal(b);
	return b[(largo-1)/2];
}

void ordenarSenal(senial& b){
	//en general se llamar'a para ordenar subsegnales de longitud 2*R+1
	int largo = b.size();
	for(int i=0; i<largo; i++){
		int amp_min = b[i];
		int ind_de_min = i;
		int j = i+1;
		while(j<largo){
			if(b[j]<amp_min){
				amp_min = b[j];
				ind_de_min = j;
			}
			j++;
		}
		// modificar la segnal b
		int amp_temp = b[i];
		b[i] = b[ind_de_min];
		b[ind_de_min] = amp_temp;
	}
}

