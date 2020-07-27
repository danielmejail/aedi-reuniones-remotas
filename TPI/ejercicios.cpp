#include <algorithm>
#include "ejercicios.h"

// Ejercicios

bool esSenial(vector<int> const& s, int prof, int freq) {
	// Toma un vector de interos (senial) y par'ametros enteros
	// prof y freq (profundidad y frecuencia) y determina si
	// el vector es una segnal v'alida con respecto a estos par'ametros
	bool resp = false;
	resp = esValida(s, prof, freq);
	return resp;
}

bool seEnojo(senial const& s, int umbral, int prof, int freq) {
	// se asume que esValida(s, prof, freq)==true
	// determina si existe una subsecuencia (subsegnal) de s de tipo
	// senial de longitud al menos 2*freq, tal que tono > umbral
	// (es decir, superaUmbral == true)
	bool resp = false;
	int largo = s.size();
	int i = 0;
	while(i<(largo-1) && !resp){
		senial subSig = {s[i]};
		int k = i+1;
		while(k<largo-1 && !resp){
			// la subsegnal debe ser propia, la 'ultima entrada
			// de la subsegnal es, a lo sumo, |s|-2
			subSig.push_back(s[k]);
			if(duraMasDe(subSig,freq,2) &&
					superaUmbral(subSig,umbral)){
				resp = true;
				//cout << "tono: " << tono(subSig) << endl;
				//cout << i << " ~ " << k << "<" << largo-1
				//	<< endl;
			}
			k++;
		}
		i++;
	}
	return resp;
}

bool esReunionValida(reunion const& r, int prof, int freq) {
	// Determina si r de tipo vector<pair<senial,int>> es una
	// reuni'on v'alida
	bool resp = true;
	resp = reunionValida(r, prof, freq);
	return resp;
}

void acelerar(reunion& r, int prof, int freq) {
	// Se asume que r es reunion v'alida para los par'ametros
	// prof y freq y que las longitudes (todas iguales) de las segnales
	// son v'alidas, es decir, se verifica longitudesValidas(r,freq).
	// El par'ametro r pasado por referencia es modificado de manera
	// que cada segnal de la reuni'on tenga el mismo id de hablante,
	// pero la nueva segnal sea una segnal acelerada de la segnal
	// original. No se verifica que la nueva reuni'on sea una
	// reuni'on v'alida.
	int cant_de_hablantes = r.size();
	for(int i=0; i<cant_de_hablantes; i++){
		senial sig = get<0>(r[i]);
		acelerarSenal(sig, prof, freq);
		get<0>(r[i]) = sig;
	}
}

void ralentizar(reunion& r, int prof, int freq) {
	// Se asume que r es reuni'on v'alida para los par'ametros
	// prof y freq. El par'ametro r pasado por referencia es
	// modificado de manera que cada segnal de la reuni'on tenga el
	// mismo id de hablante pero la nueva segnal sea una segnal
	// interpolada de la original. No se verifica que la nueva
	// reuni'on sea una reuni'on v'alida.
	int cant_de_hablantes = r.size();
	for(int i=0; i<cant_de_hablantes; i++){
		senial sig = get<0>(r[i]);
		senial sigRalent = ralentizarSenal(sig, prof, freq);
		// a diferencia de acelerarSenal, el tipo es senial y no void
		get<0>(r[i]) = sigRalent;
	}
}

vector<hablante> tonosDeVozElevados(reunion const& r, int freq, int prof) {
	// Asume que r es una reuni'on v'alida. Devuelve una lista (vector)
	// de elementos de tipo hablante. Los elementos de esta lista
	// son exactamente los ids de hablantes de la reuni'on cuyas
	// segnales posee el tono m'aximo de entre las segnales de la
	// reuni'on.
	vector<hablante> maximos = {};
	float tono_superior = 0.0;
	int cant_de_hablantes = r.size();
	for(int i=0; i<cant_de_hablantes; i++){
		float tono_i = tono(get<0>(r[i]));
		if(tono_i >= tono_superior){
			hablante id_i = get<1>(r[i]);
			maximos.push_back(id_i);
			if(tono_i > tono_superior){
				tono_superior = tono_i;
				maximos = {id_i};
			}
		}
	}
	return maximos;
}

void ordenar(reunion& r, int freq, int prof) {
	// Asume que r es una reuni'on v'alida. El par'ametro r pasado por
	// referencia es modificado de manera que las segnales queden
	// ordenadas de manera creciente en el vector de acuerdo al tono.
	// No se verifica que los ids no hayan sido modificados.
	// 
	int cant_de_hablantes = r.size();
	vector<float> vector_de_tonos = {};
	for(int i=0; i<cant_de_hablantes; i++){
		float tono_i = tono(get<0>(r[i]));
		vector_de_tonos.push_back(tono_i);
	}
	for(int i=0; i<cant_de_hablantes; i++){
		float tono_max = vector_de_tonos[i];
		int ind_de_max = i;
		int j = i+1;
		while(j<cant_de_hablantes){
			if(vector_de_tonos[j]>tono_max){
				tono_max = vector_de_tonos[j];
				ind_de_max = j;
			}
			j++;
		}
		// modificar el vector de tonos
		float tono_temp = vector_de_tonos[i];
		vector_de_tonos[i] = vector_de_tonos[ind_de_max];
		vector_de_tonos[ind_de_max] = tono_temp;
		// hacer la misma modificaci'on en el orden de los hablantes
		pair<senial, hablante> par_temp = r[i];
		r[i] = r[ind_de_max];
		r[ind_de_max] = par_temp;
	}
}

vector<pair<int,int> > silencios(senial const& s, int prof, int freq,
		int umbral) {
	// Asume que la sengnal s es una segnal v'alida para los
	// par'ametros prof y freq y que umbral es un umbral
	// v'alido. Devuelve una secuencia de intervalos (pares de enteros)
	// sin elementos repetidos (ver la especificaci'on de hayRepetidos
	// para la noci'on de igualdad) que verifican ser intervalos
	// maximales respecto a la inclusi'on en donde la segnal s no
	// supera un determinado umbral de silencio (int umbral).
	return calcularSilencios(s, freq, umbral);
}

bool hablantesSuperpuestos(reunion const& r, int prof, int freq, int umbral) {
	// Asume que r es una reuni'on v'alida y que umbral es un umbral
	// v'alido. Determina si existen dos hablantes h1 y h2 de la reuni'on
	// tales que, para alg'un instante tal que h1 no est'e en silencio,
	// h2 tampoco est'a en silencio.
	bool res = false;
	int cant_de_hablantes = r.size();
	for(int h=0; h<cant_de_hablantes-1; h++){
		for(int k=h+1; k<cant_de_hablantes; k++){
			if(!seRespetan(r,h,k,freq,umbral)){
				res = true;
			}
		}
	}
	return res;
}

senial reconstruir(senial const& s, int prof, int freq) {
	// Asume que s es una segnal v'alida, que el primer y el 'ultimo
	// valor de la segnal son distintos de cero y que la segnal puede
	// reconstruirse. Devuelve una nueva segnal que verifica ser una
	// segnal reconstruida a partir de s.
	senial senalReconstruida = {};
	int largo_de_s = s.size();
	for(int a=0; a<largo_de_s; a++){
		if(s[a]!=0){
			senalReconstruida.push_back(s[a]);
		} else {
			if(esPasajePorCero(s,a)){
				senalReconstruida.push_back(s[a]);
			} else {
				int promedio = promediarSenalEn(s,a);
				senalReconstruida.push_back(promedio);
			}
		}
	}
	return senalReconstruida;
}

/*
void filtradoMediana(senial& s, int R, int prof, int freq){
	// Asume que s es una segnal v'alida. R = 2 o 4. El par'ametro
	// s pasado por referencia es modificado de manera que la nueva
	// segnal sea una segnal filtrada de la segnal original con
	// par'ametro R. La implementaci'on necesita de un vector para
	// almancenar algunos de los valores de la segnal original a medida
	// que se procede con el filtrado
	int largo = s.size();
	vector<int> vector_de_medianas;
	for(int i=0; i<R+1; i++){
		vector_de_medianas.push_back(mediana(subsenal(s,i,i+2*R+1)));
	}
	// modificar desde el lugar R, hasta largo-(2*R+1) (sin inc)
	for(int j=R; j<largo-(2*R+1); j++){
		s[j] = vector_de_medianas[0];
		for(int i=0; i<R; i++){
			vector_de_medianas[i] = vector_de_medianas[i+1];
		}
		vector_de_medianas[R] = mediana(subsenal(s,j+1,(j+1)+2*R+1));
	}
	// modificar desde el lugar largo-(2*R+1), hasta largo-R-1 (sin inc)
	for(int j=largo-(2*R+1); j<largo-R-1; j++){
		s[j] = vector_de_medianas[0];
		for(int i=0; i<R; i++){
			vector_de_medianas[i] = vector_de_medianas[i+1];
		}
		vector_de_medianas[R] = s[j+R+1];
	}
	// modificar desde el lugar largo-1-R, hasta el lugar largo
	for(int t=0; t<R+1; t++){
		s[largo-1-R+t] = vector_de_medianas[t];
	}
	// fin
}
*/

void filtradoMediana(senial& s, int R, int prof, int freq) {
	int m;
	vector<int> w = {};
	int largo = s.size();
	w = subsenal(s,0,2*R+1);
	for(int i=R;i<largo-R-1; i++){
		m = mediana(w);
		s[i] = m;
		transportar(w,s,i+R+1);
	}
	s[largo-R-1] = mediana(w);
	for(int j=1; j<R+1; j++) {
		s[largo-R-1+j] = w[R+j];
	}
}


