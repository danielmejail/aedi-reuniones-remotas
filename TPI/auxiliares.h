//
// Created by Sebastian Vita on 2020-05-25.
//

#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

#include "definiciones.h"

using namespace std;

int absoluto(int e);
//E01
bool esValida(senial s, int profundidad, int frec);
bool frecValida(int frec);
bool enRango(senial s, int profundidad);
bool profValida(int profundidad);
bool duraMasDe(senial s, int frec, float t);

//E02
bool superaUmbral(senial s, int umbral);
float tono(senial s);

//E03
bool reunionValida(reunion r, int prof, int freq);
bool esMatriz(vector<pair<senial,int>> r);
bool senalesValidas(reunion r, int prof, int freq);
bool hablantesDeReunionValidos(reunion r, int prof, int freq);

//E04
void acelerarSenal(senial &s, int prof, int freq);

//E05
senial ralentizarSenal(senial s, int prof, int freq);
// la implementaci'on de esta 'ultima funci'on hace que s no se pueda
// pasar por referencia

//E06

//E07

//E08
bool noPerteneceANinguno(int k, vector<intervalo> intervalos);

//E09
bool seRespetan(reunion r, hablante h1, hablante h2, int freq, int umbral);
bool haySilencioQueLoContiene(senial s, int i, int freq, int umbral);
vector<intervalo> calcularSilencios(senial s, int freq, int umbral);

//E10
senial subsenal(senial s, int i, int j);
bool esPasajePorCero(senial s, int i);
int distancia(int j, int i);
int signo(int i);
int promediarSenalEn(senial s, int a);
int masCercanoAnteriorNoNulo(senial s, int a);
int masCercanoPosteriorNoNulo(senial s, int a);

//E11
int mediana(senial b);
void ordenarSenal(senial& b);

#endif //REUNIONESREMOTAS_AUXILIARES_H
