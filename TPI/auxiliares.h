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

bool esValida(senial s, int profundidad, int frec);
bool frecValida(int frec);
bool enRango(senial s, int profundidad);
bool profValida(int profundidad);
bool duraMasDe(senial s, int frec, float t);



#endif //REUNIONESREMOTAS_AUXILIARES_H
