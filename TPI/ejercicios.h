#ifndef REUNIONESREMOTAS_SOLUCION_H
#define REUNIONESREMOTAS_SOLUCION_H

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

#include "definiciones.h"
#include "auxiliares.h"

bool esSenial(vector<int> const &s, int prof, int freq);
bool seEnojo(senial const &s, int umbral, int prof, int freq);
bool esReunionValida(reunion const &r, int prof, int freq);
void acelerar(reunion &r, int prof, int freq);
void ralentizar(reunion &r, int prof, int freq);
vector<hablante> tonosDeVozElevados(reunion const &r, int prof, int freq);
void ordenar(reunion &r, int prof, int freq);
vector<pair<int,int> > silencios(senial const &s, int prof, int freq, int umbral);
bool hablantesSuperpuestos(reunion const &r, int prof, int freq, int umbral);
senial reconstruir(senial const& s, int prof, int freq);
void filtradoMediana(senial& s, int r, int prof, int freq);

#endif //REUNIONESREMOTAS_SOLUCION_H
