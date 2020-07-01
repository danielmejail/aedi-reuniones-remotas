#include <iostream>
#include <string>
#include <vector>

#include "../definiciones.h"
#include "../auxiliares.h"
#include "../ejercicios.h"
#include "TestSuite.h"

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

/*
class TestCase{}
	private:
		//contenido...
	public:
		//setContenido(algo)
Mejor no agregar esta clase
*/

/*
class Test{
}
*/

//-----Funciones de la clase TestEjercicio01-----

TestEjercicio01::TestEjercicio01(string nom, senial s, int p, int f, bool val){
	nombre = nom;
	senal = s;
	prof = p;
	freq = f;
	valorEsperado = val;
}

string TestEjercicio01::getNombre(void){
	return nombre;
}

void TestEjercicio01::setNombre(string nom){
	nombre = nom;
}

bool TestEjercicio01::correrTest(void){
	return (valorEsperado == esSenial(senal, prof, freq));
}

void TestEjercicio01::mostrar(void){
	cout << "Test: " << nombre << endl;
	cout << "Valor esperado: " << valorEsperado << endl;
}
