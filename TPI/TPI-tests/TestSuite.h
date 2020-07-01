#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

#include "../definiciones.h"
#include "../auxiliares.h"
#include "../ejercicios.h"

using namespace std;

/*
class TestSuite{
	private:
		vect<Test> tests;
	public:
		vect<Test> getTests(){
			return tests;
		void addTest(test0){
			tests.append(test0);
		}
		void correrTestSuite(){
			// * correr los tests en la suite;
			// * determinar la proporci'on de tests que pasaren;
			// * mostrar la proporci'on;
			// * indicar los tests que fallaren;
		}
}
*/

class TestEjercicio01 {
	/* hereda de Test (?)
	 * objeto test de
	 * bool esSenial(vector<int> const& s, int prof, int freq)
	 */
	private:
		string nombre;
		senial senal;
		int prof;
		int freq;
		bool valorEsperado;
	public:
		TestEjercicio01(string nom, senial s, int p, int f, bool val);
		string getNombre(void);
		void setNombre(string nom);
		bool correrTest(void);
		void mostrar(void);
};

#endif
