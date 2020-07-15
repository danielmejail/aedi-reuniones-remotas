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

class Test {
	private:
		string nombre;
	public:
		Test(string nom);
		string getNombre(void);
		void setNombre(string nom);
		//bool getValorEsperado(void);
		bool correrTest(void);
		//void mostrar(void);
};

class TestEjercicio01: public Test {
	/* hereda de Test (?)
	 * objeto test de
	 * bool esSenial(vector<int> const& s, int prof, int freq)
	 */
	private:
		senial sig;
		int prof;
		int freq;
		bool valorEsperado;
	public:
		TestEjercicio01(string nom, senial s, int p, int f,
				bool esperado);
		// string getNombre(void);
		// void setNombre(string nom);
		bool correrTest(void);
		bool getValorEsperado(void);
		void mostrar(void);
};

class TestEjercicio02 : public Test {
	private:
		senial sig;
		int umbral;
		int prof;
		int freq;
		bool valorEsperado;
	public:
		TestEjercicio02(string nom, senial s, int u, int p, int f,
				bool esperado);
		bool correrTest(void);
		bool getValorEsperado(void);
		void mostrar(void);
};

class TestEjercicio03 : public Test {
	private:
		reunion reu;
		int prof;
		int freq;
		bool valorEsperado;
	public:
		TestEjercicio03(string nom, reunion r, int p, int f,
				bool esperado);
		bool correrTest(void);
		bool getValorEsperado(void);
		void mostrar(void);
};

class TestEjercicio04 : public Test {
	private:
		reunion reu;
		int prof;
		int freq;
		reunion valorEsperado;
	public:
		TestEjercicio04(string nom, reunion r, int p, int f,
				reunion esperado);
		bool correrTest(void);
		//pair<int, bool> getValorEsperado(void);
		reunion getValorEsperado(void);
		void mostrar(void);
};

class TestEjercicio05 : public Test {
	private:
		reunion reu;
		int prof;
		int freq;
		reunion valorEsperado;
	public:
		TestEjercicio05(string nom, reunion r, int p, int f,
				reunion esperado);
		bool correrTest(void);
		//pair<int, bool> getValorEsperado(void);
		reunion getValorEsperado(void);
		void mostrar(void);
};

class TestEjercicio06 : public Test {
	private:
		reunion reu;
		int freq;
		int prof;
		vector<hablante> valorEsperado;
	public:
		TestEjercicio06(string nom, reunion r, int p, int f,
				vector<hablante> esperado);
		bool correrTest(void);
		vector<hablante> getValorEsperado(void);
		void mostrar(void);
};

class TestEjercicio07 : public Test {
	private:
		reunion reu;
		int prof;
		int freq;
		reunion valorEsperado;
	public:
		TestEjercicio07(string nom, reunion r, int p, int f,
				reunion esperado);
		bool correrTest(void);
		reunion getValorEsperado(void);
		void mostrar(void);
};


class TestEjercicio08 : public Test {
	private:
		senial sig;
		int prof;
		int freq;
		int umbral;
		vector<pair<int,int>> valorEsperado;
	public:
		TestEjercicio08(string nom, senial s, int p, int f, int u,
				vector<pair<int,int>> esperado);
		bool correrTest(void);
		vector<pair<int,int>> getValorEsperado(void);
		void mostrar(void);
};


class TestEjercicio09 : public Test {
	private:
		reunion reu;
		int prof;
		int freq;
		int umbral;
		bool valorEsperado;
	public:
		TestEjercicio09(string nom, reunion r, int p,
			int f, int u, bool esperado);
		bool correrTest(void);
		bool getValorEsperado(void);
		void mostrar(void);
};


class TestEjercicio10 : public Test {
	private:
		senial sig;
		int prof;
		int freq;
		senial valorEsperado;
	public:
		TestEjercicio10(string nom, senial s, int p, int f,
				senial esperado);
		bool correrTest(void);
		senial getValorEsperado(void);
		void mostrar(void);
};


class TestEjercicio11 : public Test {
	private:
		senial sig;
		int prof;
		int freq;
		int lateral;
		senial valorEsperado;
	public:
		TestEjercicio11(string nom, senial s, int p, int f, int r,
				senial esperado);
		bool correrTest(void);
		senial getValorEsperado(void);
		void mostrar(void);
};


/*
class TestSuite{
	private:
		string nombre;
		vector<Test> tests;
		int cantidad_de_tests;
	public:
		TestSuite(void);
		string getNombre(void);
		vector<Test> getTests();
		int getCantidadDeTests();
		void addTest(Test test0);
		void correrTestSuite(void);
};
*/


#endif
