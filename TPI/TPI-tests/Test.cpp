#include <iostream>
#include <string>
#include <vector>

#include "../definiciones.h"
#include "../auxiliares.h"
#include "../ejercicios.h"
#include "Test.h"

using namespace std;


//-----Funciones de la clase TestSuite-----
/*
TestSuite::TestSuite(string nom) {
	nombre = nom;
	tests = {};
	cantidad_de_tests = 0;
}

string TestSuite::getNombre(void) {
	return nombre;
}

vect<Test> TestSuite::getTests(void) {
	return tests;
}

int TestSuite::getCantidadDeTests(void) {
	return cantidad_de_tests;
}

void TestSuite::addTest(Test test0) {
	tests.push_back(test0);
	cantidad_de_tests += 1;
}

void TestSuite::correrTestSuite(void) {
	cout << "Corriendo test suite " << nombre << "..." << endl;
	int cantidad_de_tests_que_pasan = 0;
	for(int i=0; i<cantidad_de_tests; i++){
		bool res = tests[i].correrTest();
		if(res){
			cout << "Test " << tests[i].getNombre() <<
				" pasa" << endl;
			cantidad_de_tests_que_pasan += 1;
		} else {
			cout << "Test " << tests[i].getNombre() <<
				" falla" << endl;
		}
	}
	cout << "Cantidad de tests: " << cantidad_de_tests << endl;
	cout << "Cantidad de tests que pasaron: " <<
		cantidad_de_tests_que_pasan << endl;
	cout << "Proporci'on de tests que pasaron: " <<
		(1.0*cantidad_de_tests_que_pasan)/cantidad_de_tests << endl;
	cout << "-----" << endl;
}
*/

//-----Funciones de la clase Test-----

Test::Test(string nom){
	nombre = nom;
}

string Test::getNombre(void){
	return nombre;
}

void Test::setNombre(string nom){
	nombre = nom;
}

bool Test::correrTest(void){}

//-----Funciones de la clase TestEjercicio01-----

TestEjercicio01::TestEjercicio01(string nom, senial s, int p, int f,
		bool esperado): Test(nom){
	sig = s;
	prof = p;
	freq = f;
	valorEsperado = esperado;
}

bool TestEjercicio01::correrTest(void){
	bool res = esSenial(sig, prof, freq);
	return (valorEsperado == res);
}

bool TestEjercicio01::getValorEsperado(void){
	return valorEsperado;
}

void TestEjercicio01::mostrar(void){
	cout << "Test: " << getNombre() << endl;
	cout << "Valor esperado: " << valorEsperado << endl;
}

//-----Funciones de la clase TestEjercicio02-----

TestEjercicio02::TestEjercicio02(string nom, senial s, int u, int p, int f,
		bool esperado) : Test(nom) {
	sig = s;
	umbral = u;
	prof = p;
	freq = f;
	valorEsperado = esperado;
}

bool TestEjercicio02::correrTest(void){
	bool res = seEnojo(sig, umbral, prof, freq);
	return (valorEsperado == res);
}

bool TestEjercicio02::getValorEsperado(void){
	return valorEsperado;
}

void TestEjercicio02::mostrar(void){
	cout << "Test: " << getNombre() << endl;
	cout << "Valor esperado: " << valorEsperado << endl;
}

//-----Funciones de la clase TestEjercicio03-----

TestEjercicio03::TestEjercicio03(string nom,
		reunion r, int p, int f, bool esperado) : Test(nom) {
	reu = r;
	prof = p;
	freq = f;
	valorEsperado = esperado;
}

bool TestEjercicio03::correrTest(void){
	bool res = esReunionValida(reu, prof, freq);
	return (valorEsperado == res);
}

bool TestEjercicio03::getValorEsperado(void){
	return valorEsperado;
}

void TestEjercicio03::mostrar(void){
	cout << "Test: " << getNombre() << endl;
	cout << "Valor esperado: " << valorEsperado << endl;
}

//-----Funciones de la clase TestEjercicio04-----

TestEjercicio04::TestEjercicio04(string nom, reunion r, int p, int f,
		reunion esperado) : Test(nom) {
	reu = r;
	prof = p;
	freq = f;
	valorEsperado = esperado;
	//int cant_de_hablantes = r.size();
	//valorEsperado = make_pair(cant_de_hablantes,true);
}

bool TestEjercicio04::correrTest(void){
	reunion reunionIO = reu;
	// acelerar es de tipo void: reescribe reunionIO
	acelerar(reunionIO, prof, freq);
	int cant_de_hablantes_acelerada = reunionIO.size();
	return (valorEsperado == reunionIO);
}

reunion TestEjercicio04::getValorEsperado(void) {
	return valorEsperado;
}

void TestEjercicio04::mostrar(void){
	cout << "Test: " << getNombre() << endl;
	cout << "Valor esperado: " << "{";
	int cant_de_hablantes = valorEsperado.size();
	for(int i=0; i<cant_de_hablantes-1; i++){
		cout << "h:" << get<1>(valorEsperado[i]) << ", ";
	}
	cout << "h:" << get<1>(valorEsperado[cant_de_hablantes-1])
		<< "}" << endl;
}

//-----Funciones de la clase TestEjercicio05-----

TestEjercicio05::TestEjercicio05(string nom, reunion r, int p, int f,
		reunion esperado) : Test(nom) {
	reu = r;
	prof = p;
	freq = f;
	valorEsperado = esperado;
}

bool TestEjercicio05::correrTest(void){
	reunion reunionIO = reu;
	// ralentizar es de tipo void: reescribe reunionIO
	ralentizar(reunionIO, prof, freq);
	return (valorEsperado == reunionIO);
}

reunion TestEjercicio05::getValorEsperado(void) {
	return valorEsperado;
}

void TestEjercicio05::mostrar(void){
	cout << "Test: " << getNombre() << endl;
	cout << "Valor esperado: " << "{";
	int cant_de_hablantes = valorEsperado.size();
	for(int i=0; i<cant_de_hablantes-1; i++){
		cout << "h:" << get<1>(valorEsperado[i]) << ", ";
	}
	cout << "h:" << get<1>(valorEsperado[cant_de_hablantes-1])
		<< "}" << endl;
}

//-----Funciones de la clase TestEjercicio06-----

TestEjercicio06::TestEjercicio06(string nom, reunion r, int p, int f,
		vector<hablante> esperado) : Test(nom) {
	reu = r;
	prof = p;
	freq = f;
	valorEsperado = esperado;
}

bool TestEjercicio06::correrTest(void){
	vector<hablante> hablantes_con_tono_mas_elevado =
		tonosDeVozElevados(reu, freq, prof);
	return (hablantes_con_tono_mas_elevado == valorEsperado);
}

vector<hablante> TestEjercicio06::getValorEsperado(void) {
	return valorEsperado;
}

void TestEjercicio06::mostrar(void){
	cout << "Test: " << getNombre() << endl;
	cout << "Valor esperado: [";
	int l = valorEsperado.size();
	for(int i=0; i<l-1; i++){
		cout << valorEsperado[i] << ", ";
	}
	cout << valorEsperado[l-1] << "]" << endl;
}

//-----Funciones Ejercicio07-----

TestEjercicio07::TestEjercicio07(string nom, reunion r, int p, int f,
		reunion esperado) : Test(nom) {
	reu = r;
	prof = p;
	freq = f;
	valorEsperado = esperado;
}

bool TestEjercicio07::correrTest(void){
	reunion reunionIO = reu;
	// ordenar es de tipo void: reescribe reunionIO
	ordenar(reunionIO, prof, freq);
	return (valorEsperado == reunionIO);
}

reunion TestEjercicio07::getValorEsperado(void) {
	return valorEsperado;
}

void TestEjercicio07::mostrar(void){
	cout << "Test: " << getNombre() << endl;
	cout << "Valor esperado: " << "{";
	int cant_de_hablantes = valorEsperado.size();
	for(int i=0; i<cant_de_hablantes-1; i++){
		cout << "h:" << get<1>(valorEsperado[i]) << ", ";
	}
	cout << "h:" << get<1>(valorEsperado[cant_de_hablantes-1])
		<< "}" << endl;
}

//-----Funciones TestEjercicio08-----

TestEjercicio08::TestEjercicio08(string nom, senial s, int p, int f, int u,
		vector<pair<int,int>> esperado) : Test(nom) {
	sig = s;
	prof = p;
	freq = f;
	umbral = u;
	valorEsperado = esperado;
}

bool TestEjercicio08::correrTest(void) {
	vector<intervalo> intervalos = silencios(sig, prof, freq, umbral);
	return (intervalos == valorEsperado);
}

vector<pair<int,int>> TestEjercicio08::getValorEsperado(void) {
	return valorEsperado;
}

void TestEjercicio08::mostrar(void) {
	cout << "Test: " << getNombre() << endl;
	cout << "Valor esperado: " << "[";
	int cant_de_intervalos = valorEsperado.size();
	for(int i=0; i<cant_de_intervalos-1; i++){
		cout << "(" << get<0>(valorEsperado[i]) << ","
			<< get<1>(valorEsperado[i]) << "), ";
	}
	cout << "(" << get<0>(valorEsperado[cant_de_intervalos-1]) << ","
		<< get<1>(valorEsperado[cant_de_intervalos]) << ")]" << endl;
}

//-----Funciones TestEjercicio09-----

TestEjercicio09::TestEjercicio09(string nom, reunion r, int p,
		int f, int u, bool esperado) : Test(nom) {
	reu = r;
	prof = p;
	freq = f;
	umbral = u;
	valorEsperado = esperado;
}

bool TestEjercicio09::correrTest(void) {
	bool res = hablantesSuperpuestos(reu, prof, freq, umbral);
	return (valorEsperado == res);
}

bool TestEjercicio09::getValorEsperado(void) {
	return valorEsperado;
}

void TestEjercicio09::mostrar(void) {
	cout << "Test: " << getNombre() << endl;
	cout << "Valor esperado: " << valorEsperado << endl;
}

//-----Funciones TestEjercicio10-----

TestEjercicio10::TestEjercicio10(string nom, senial s, int p, int f,
		senial esperado) : Test(nom) {
	sig = s;
	prof = p;
	freq = f;
	valorEsperado = esperado;
}

bool TestEjercicio10::correrTest(void){
	senial reconstruida = reconstruir(sig, prof, freq);
	return (reconstruida == valorEsperado);
}

senial TestEjercicio10::getValorEsperado(void){
	return valorEsperado;
}

void TestEjercicio10::mostrar(void){
	cout << "Test: " << getNombre() << endl;
	cout << "Valor esperdado: " << "{";
	int l = valorEsperado.size();
	for(int i=0; i<l-1; i++){
		cout << valorEsperado[i] << ", ";
	}
	cout << valorEsperado[l-1] << "}" << endl;
}

//-----Funciones TestEjercicio11-----

TestEjercicio11::TestEjercicio11(string nom, senial s, int p, int f, int r,
		senial esperado) : Test(nom) {
	sig = s;
	prof = p;
	freq = f;
	lateral = r;
	valorEsperado = esperado;
}

bool TestEjercicio11::correrTest(void){
	senial sigIO = sig;
	int largo = valorEsperado.size();
	cout << "Esperado: " << "{";
	for(int i=0; i<largo-1; i++){
		cout << valorEsperado[i] << ", ";
	}
	cout << valorEsperado[largo-1] << "}" << endl;

	int largo_res = sig.size();
	filtradoMediana(sigIO, lateral, prof, freq);
	cout << "Resultado: " << "{";
	for(int i=0; i<largo_res-1; i++){
		cout << sigIO[i] << ", ";
	}
	cout << sigIO[largo_res-1] << "}" << endl;

	return (sigIO == valorEsperado);
}

senial TestEjercicio11::getValorEsperado(void){
	return valorEsperado;
}

void TestEjercicio11::mostrar(void){
	cout << "Test: " << getNombre() << endl;
	cout << "Valor esperdado: " << "{";
	int l = valorEsperado.size();
	for(int i=0; i<l-1; i++){
		cout << valorEsperado[i] << ", ";
	}
	cout << valorEsperado[l-1] << "}" << endl;
}

