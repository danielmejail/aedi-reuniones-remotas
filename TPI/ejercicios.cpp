#include <algorithm>
#include "ejercicios.h"

// Ejercicios

bool esSenial(vector<int> const& s, int prof, int freq) {
    bool resp = false; // este valor puede ser cambiado de acuerdo a la propia implementacion
    // Implementacion
    resp = esValida(s, prof, freq);
    return resp;
}

bool seEnojo(senial const& s, int umbral, int prof, int freq) {
    bool resp = false; // este valor puede ser cambiado de acuerdo a la propia implementacion    // Implementacion
    return resp;
}

bool esReunionValida(reunion const& r, int prof, int freq) {
    bool resp = true; // este valor puede ser cambiado de acuerdo a la propia implementacion    // Implementacion
    return resp;
}

void acelerar(reunion& r, int prof, int freq) {
    // Implementacions
    return;
}

void ralentizar(reunion& r, int prof, int freq) {
    // Implementacions
    return;
}

vector<hablante> tonosDeVozElevados(reunion const& r, int freq, int prof) {
    vector<hablante> maximos;
    // Implementacion
    return maximos;
}

void ordenar(reunion& r, int freq, int prof) {
    // Implementacion
    return;
}

vector<pair<int,int> > silencios(senial const& s, int prof, int freq, int umbral) {
    vector<pair<int,int> > intervalos;
    // Implementacion
    return intervalos;
}

bool hablantesSuperpuestos(reunion const& r, int prof, int freq, int umbral) {
    bool resp = false; // este valor puede ser cambiado de acuerdo a la propia implementacion    // Implementacion
    return resp;
}

senial reconstruir(senial const& s, int prof, int freq) {
    senial senalReconstruida;
    // Implementacion
    return senalReconstruida;
}

void filtradoMediana(senial& s, int r, int prof, int freq){
    // Implementacion
    return;
}

