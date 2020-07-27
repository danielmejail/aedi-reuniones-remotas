#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "Test.h"
#include "test_suites.h"

using namespace std;

void iniciarTestsEjercicio01(void) {
	cout << "" << endl;
	cout << "Testeando ejercicio 01..." << endl;

	vector<TestEjercicio01> test_ejercicio01 = {};
	string nom;
	senial s;
	int p;
	int f;
	bool val;

	// Caso 1
	nom = "esSenial/senialEsValida";
	s = {9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45,
		-60, 9, 43, 54, 103, 44, 59, -10, -44, -55, -104,
		-45, -60, 9};
	p = 8;
	f = 10;
	val = true;
	test_ejercicio01.push_back(TestEjercicio01(nom,s,p,f,val));

	// Caso 2
	nom = "esSenial/senialInvalida";
	s = {};
	p = 16;
	f = 10;
	val = false;
	test_ejercicio01.push_back(TestEjercicio01(nom,s,p,f,val));

	int cant_de_tests = test_ejercicio01.size();
	int cant_de_tests_que_pasaron = 0;
	for(int i=0; i<cant_de_tests; i++){
		bool res = test_ejercicio01[i].correrTest();
		cout << ">>> Resultado del test " <<
			test_ejercicio01[i].getNombre() << ": ";
		if(res){
			cant_de_tests_que_pasaron += 1;
			cout << "pasa" << endl;
		} else {
			cout << "falla" << endl;
		}
	}
	cout << "Resultado: " << cant_de_tests_que_pasaron << "/" <<
		cant_de_tests << endl;
	cout << "-----" << endl;
}

//------------------

void iniciarTestsEjercicio02(void) {
	cout << "" << endl;
	cout << "Testeando ejercicio 02..." << endl;
	vector<TestEjercicio02> test_ejercicio02 = {};
	string nom;
	senial s;
	int u;
	int p;
	int f;
	bool esperado;

	// Caso 0
	nom = "seEnojo/checkForSubseqOfMinSizeTwoTimesFreq";
	s = {17, 32, 80, 85, 99, 62, 7, -55, -107, -101, -88, -26,
		-3, 52, 62, 99, 89, 67, 7, -61, -97, -115, -71, -45, 17};
	u = 65;
	p = 8;
	f = 10;
	esperado = true;
	test_ejercicio02.push_back(TestEjercicio02(nom,s,u,p,f,esperado));

	// Caso 1, umbral inv'alido. Aun as'i, de acuerdo con la
	// implementaci'on, se deber'ia poder correr el programa sin errores
	// y esperar falso.
	nom = "seEnojo/umbralAltoNoSeEnoja";
	s = { 9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45,
	       -60, 9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45, -60, 9};
	u = 1000;
	p = 8;
	f = 10;
	esperado = false;
	test_ejercicio02.push_back(TestEjercicio02(nom,s,u,p,f,esperado));

	// Caso 2, permanece en silencio
	nom = "seEnojo/permaneceEnSilencio";
	s = {};
	for(int i=0;i<25;i++){
		s.push_back(0);
	}
	u = 100;
	p = 16;
	f = 10;
	esperado = false;
	test_ejercicio02.push_back(TestEjercicio02(nom,s,u,p,f,esperado));

	// Caso 3, estalla al final
	nom = "seEnojo/estallaAlFinal";
	s = {};
	for(int i=0;i<500; i++){
		s.push_back(0);
	}
	s.push_back(100);
	u = 99;
	p = 8;
	f = 10;
	esperado = false;
	test_ejercicio02.push_back(TestEjercicio02(nom,s,u,p,f,esperado));

	// Caso 4, justo dos segundos de enojo
	nom = "seEnojo/seEnojaDosSegundos";
	s = {};
	for(int i=0;i<20; i++){
		s.push_back(100);
	}
	s.push_back(0);
	u = 99;
	p = 8;
	f = 10;
	esperado = true;
	test_ejercicio02.push_back(TestEjercicio02(nom,s,u,p,f,esperado));

	// Caso 5, dos segundos dura la segnal
	nom = "seEnojo/dosSegundos";
	s = {};
	for(int i=0;i<20; i++){
		s.push_back(100);
	}
	u = 99;
	p = 8;
	f = 10;
	esperado = false;
	test_ejercicio02.push_back(TestEjercicio02(nom,s,u,p,f,esperado));

	// Caso 6, se enoja justo despu'es de los dos
	nom = "seEnojo/seEnojaJustoDespuesDeDosSegundos";
	s = {};
	for(int i=0;i<19; i++){
		s.push_back(100);
	}
	s.push_back(80);
	s.push_back(100);
	s.push_back(0);
	u = 99;
	p = 8;
	f = 10;
	esperado = true;
	test_ejercicio02.push_back(TestEjercicio02(nom,s,u,p,f,esperado));

	// Caso 7, se enoja justo despu'es de los dos, pero no es propia.
	// No se enoja
	nom = "seEnojo/JustoDespuesDeDosSegundosNoEsPropia";
	s = {};
	for(int i=0;i<19; i++){
		s.push_back(100);
	}
	s.push_back(80);
	s.push_back(100);
	u = 99;
	p = 8;
	f = 10;
	esperado = false;
	test_ejercicio02.push_back(TestEjercicio02(nom,s,u,p,f,esperado));

	int cant_de_tests = test_ejercicio02.size();
	int cant_de_tests_que_pasaron = 0;
	for(int i=0; i<cant_de_tests; i++){
		bool res = test_ejercicio02[i].correrTest();
		cout << ">>> Resultado del test " <<
			test_ejercicio02[i].getNombre() << ": ";
		if(res){
			cant_de_tests_que_pasaron += 1;
			cout << "pasa" << endl;
		} else {
			cout << "falla" << endl;
		}
	}
	cout << "Resultado: " << cant_de_tests_que_pasaron << "/" <<
		cant_de_tests << endl;
	cout << "-----" << endl;
}

//----------------

void iniciarTestsEjercicio03(void) {
	cout << "" << endl;
	cout << "Testeando ejercicio 03..." << endl;
	vector<TestEjercicio03> test_ejercicio03 = {};
	string nom;
	reunion r;
	int p;
	int f;
	bool esperado;

	senial sig1, sig2, sig3;

	// Caso 0, reuni'on v'alida
	nom = "esReunionValida/reunionCuadra";
	sig1 = {17, -128, 127, 18, 15, -16, 0, 17, -20, 19, -18};
	sig2 = {17, -128, 127, 18, 15, -16, 0, 17, -20, 19, -18};
	sig3 = {17, -128, 127, 18, 15, -16, 0, 17, -20, 19, -18};
	r = {make_pair(sig1,0), make_pair(sig2,1), make_pair(sig3,2)};
	p = 8;
	f = 10;
	esperado = true;
	test_ejercicio03.push_back(TestEjercicio03(nom, r, p, f, esperado));

	// Caso 1, provisto por la materia. La reuni'on no es v'alida
	// porque una de las segnales es m'as corta. Adem'as, dependiendo
	// de la implementaci'on, la raz'on tambi'en puede ser que
	// por lo menos dos de las tres segnales no son v'alidas
	nom = "esReunionValida/reunionNoCuadra";
	sig1 = {17, -128, 128, 18, 15, -16, 0, 17, -20, 19, -18};
	sig2 = {17, -128, 127, 18, 15, -16, 0, 17, -20, 19, -18};
	sig3 = {17, -128, 127, 18, 15, -16, 0, 17, -20, 19};
	r = {make_pair(sig1,0), make_pair(sig2,1), make_pair(sig3,2)};
	p = 8;
	f = 10;
	esperado = false;
	test_ejercicio03.push_back(TestEjercicio03(nom, r, p, f, esperado));

	// Caso 2, una segnal (justo) fuera de rango
	nom = "esReunionValida/segnalFueraDeRango";
	sig1 = {17, -120, 128, 18, 15, -16, 0, 17, -20, 19, -18};
	sig2 = {17, -120, 120, 18, 15, -16, 0, 17, -20, 19, -18};
	sig3 = {17, -120, 120, 18, 15, -16, 0, 17, -20, 19, -18};
	for(int i=0; i<10; i++){
		sig1.push_back(0);
		sig2.push_back(0);
		sig3.push_back(0);
	}
	r = {make_pair(sig1,0), make_pair(sig2,1), make_pair(sig3,2)};
	p = 8;
	f = 10;
	esperado = false;
	test_ejercicio03.push_back(TestEjercicio03(nom, r, p, f, esperado));

	// Caso 3, dos segnales comparten id
	nom = "esReunionValida/dosSegnalesConMismoId";
	sig1 = {17, -120, 120, 18, 15, -16, 0, 17, -20, 19, -18};
	sig2 = {17, -120, 120, 18, 15, -16, 0, 17, -20, 19, -18};
	sig3 = {17, -120, 120, 18, 15, -16, 0, 17, -20, 19, -18};
	for(int i=0; i<10; i++){
		sig1.push_back(0);
		sig2.push_back(0);
		sig3.push_back(0);
	}
	r = {make_pair(sig1,0), make_pair(sig2,1), make_pair(sig3,0)};
	p = 8;
	f = 10;
	esperado = false;
	test_ejercicio03.push_back(TestEjercicio03(nom, r, p, f, esperado));

	int cant_de_tests = test_ejercicio03.size();
	int cant_de_tests_que_pasaron = 0;
	for(int i=0; i<cant_de_tests; i++){
		bool res = test_ejercicio03[i].correrTest();
		cout << ">>> Resultado del test " <<
			test_ejercicio03[i].getNombre() << ": ";
		if(res){
			cant_de_tests_que_pasaron += 1;
			cout << "pasa" << endl;
		} else {
			cout << "falla" << endl;
		}
	}
	cout << "Resultado: " << cant_de_tests_que_pasaron << "/" <<
		cant_de_tests << endl;
	cout << "-----" << endl;
}

//----------------

void iniciarTestsEjercicio04(void) {
	cout << "" << endl;
	cout << "Testeando ejercicio 04..." << endl;
	vector<TestEjercicio04> test_ejercicio04 = {};
	string nom;
	reunion r;
	int p;
	int f;
	reunion esperado;
	senial s, s_esperado;
	senial sig1, sig1_esperado;
	senial sig2, sig2_esperado;

	// Caso 1, provisto por la materia, acelerar una s'ola segnal
	// de longitiud impar.
	// Notar que no se verifica la condici'on longitudesValidas
	// ?`No es 1000 un tanto grande?
	nom = "acelerar/segnalLargoImpar";
	p = 16;
	f = 10;
	s = {9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45, -60,
		9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45, -60, 9};
	r = {make_pair(s,0)};
	s_esperado = {43, 103, 59, -44, -104, -60, 43, 103, 59, -44,
		-104, -60};
	esperado = {make_pair(s_esperado,0)};
	test_ejercicio04.push_back(TestEjercicio04(nom, r, p, f, esperado));

	// Caso 2, acelerar varias segnales.
	// Los valores de p y f se mantienen
	nom = "acelerar/acelerarVariasSegnales";
	p = 16;
	f = 10;
	s = {9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45, -60,
		9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45, -60, 9};
	sig1 = {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
	sig2 = {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0};
	r = {make_pair(s,0), make_pair(sig1,1), make_pair(sig2,2)};
	
	s_esperado = {43, 103, 59, -44, -104, -60, 43, 103, 59, -44,
		-104, -60};
	sig1_esperado = {0,0,0,0,0,0,0,0,0,0,0,0};
	sig2_esperado = {1,1,1,1,1,1,1,1,1,1,1,1};
	esperado = {make_pair(s_esperado,0),
		make_pair(sig1_esperado,1), make_pair(sig2_esperado,2)};
	test_ejercicio04.push_back(TestEjercicio04(nom, r, p, f, esperado));

	// Caso 3, segnales de longitud par
	nom = "acelerar/segnalesDeLongitudPar";
	p = 16;
	f = 10;
	s = {9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45, -60,
		9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45, -60, 9,
		2, 7, 3, -10, 2};
	sig1 = {0,1,-1,0,1,-1,0,1,-1,0,1,-1,0,1,-1,
		0,1,-1,0,1,-1,0,1,-1,0,1,-1,0,1,-1};
	sig2 = {1,0,20,1,0,20,1,0,20,1,0,20,1,0,20,
		1,0,20,1,0,20,1,0,20,1,0,20,1,0,20};

	s_esperado = {43, 103, 59, -44, -104, -60, 43, 103, 59, -44, -104,
		-60,2,3,2};
	sig1_esperado = {1,0,-1,1,0,-1,1,0,-1,1,0,-1,1,0,-1};
	sig2_esperado = {0,1,20,0,1,20,0,1,20,0,1,20,0,1,20};

	r = {make_pair(s,0), make_pair(sig1,1),
		make_pair(sig2,2)};
	esperado = {make_pair(s_esperado,0), make_pair(sig1_esperado,1),
		make_pair(sig2_esperado,2)};
	test_ejercicio04.push_back(TestEjercicio04(nom, r, p, f, esperado));

	int cant_de_tests = test_ejercicio04.size();
	int cant_de_tests_que_pasaron = 0;
	for(int i=0; i<cant_de_tests; i++){
		bool res = test_ejercicio04[i].correrTest();
		cout << ">>> Resultado del test " <<
			test_ejercicio04[i].getNombre() << ": ";
		if(res){
			cant_de_tests_que_pasaron += 1;
			cout << "pasa" << endl;
		} else {
			cout << "falla" << endl;
		}
	}
	cout << "Resultado: " <<
		cant_de_tests_que_pasaron << "/" << cant_de_tests << endl;
	cout << "-----" << endl;
}

//----------------

void iniciarTestsEjercicio05(void) {
	cout << "" << endl;
	cout << "Testeando ejercicio 05..." << endl;
	vector<TestEjercicio05> test_ejercicio05 = {};
	string nom;
	reunion r;
	int p;
	int f;
	reunion esperado;
	senial s, s_esperado;
	senial sig1, sig1_esperado;
	senial sig2, sig2_esperado;

	nom = "ralentizar/unHablanteSenialAscendente";
	p = 16;
	f = 10;
	s = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	r = {make_pair(s,0)};
	s_esperado = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6,
		7, 7, 8, 8, 9, 9, 10};
	esperado = {make_pair(s_esperado,0)};
	test_ejercicio05.push_back(TestEjercicio05(nom, r, p, f, esperado));

	nom = "ralentizar/hablanteAscendenteConAlgunosValoresNegativos";
	p = 16;
	f = 10;
	s = {-1, -2, -3, -4, 5, 6, 7, 8, 9, 10};
	r = {make_pair(s,0)};
	s_esperado = {-1, -1, -2, -2, -3, -3, -4, 0, 5, 5, 6, 6,
		7, 7, 8, 8, 9, 9, 10};
	esperado = {make_pair(s_esperado,0)};
	test_ejercicio05.push_back(TestEjercicio05(nom, r, p, f, esperado));

	// Caso 1, provisto por la materia, ralentizar una s'ola segnal
	// de longitiud impar. Aprovechamos los casos del ejercicio anterior
	nom = "ralentizar/unaSegnalDeLogitudImpar";
	p = 16;
	f = 10;
	s = {9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45, -60,
		9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45, -60, 9};
	r = {make_pair(s,0)};
	s_esperado = {9, 26, 43, 48, 54, 78, 103, 73, 44, 51, 59, 24,
		-10, -27, -44, -49, -55, -79, -104, -74, -45, -52, -60, -25,
		9, 26, 43, 48, 54, 78, 103, 73, 44, 51, 59, 24, -10, -27,
		-44, -49, -55, -79, -104, -74, -45, -52, -60, -25, 9};
	esperado = {make_pair(s_esperado,0)};
	test_ejercicio05.push_back(TestEjercicio05(nom, r, p, f, esperado));

	// Caso 2, ralentizar varias segnales.
	// Los valores de p y f se mantienen
	nom = "ralentizar/ralentizarVariasSegnales";
	p = 16;
	f = 10;
	s = {9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45, -60,
		9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45, -60, 9};
	sig1 = {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
	sig2 = {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0};

	s_esperado = {9, 26, 43, 48, 54, 78, 103, 73, 44, 51, 59, 24,
		-10, -27, -44, -49, -55, -79, -104, -74, -45, -52, -60, -25,
		9, 26, 43, 48, 54, 78, 103, 73, 44, 51, 59, 24, -10, -27,
		-44, -49, -55, -79, -104, -74, -45, -52, -60, -25, 9};
	sig1_esperado = {1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,
		0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1};
	sig2_esperado = {0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,
		0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0};
	r = {make_pair(s,0), make_pair(sig1,1), make_pair(sig2,2)};
	esperado = {make_pair(s_esperado,0), make_pair(sig1_esperado,1),
		make_pair(sig2_esperado,2)};
	test_ejercicio05.push_back(TestEjercicio05(nom, r, p, f, esperado));

	// Caso 3, segnal de longitud par
	nom = "ralentizar/segnalDeLongitudPar";
	p = 16;
	f = 10;
	s = {9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45, -60,
		9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45, -60, 9,
		2, 7, 3, -10, 2};
	s_esperado = {9, 26, 43, 48, 54, 78, 103, 73, 44, 51, 59, 24,
		-10, -27, -44, -49, -55, -79, -104, -74, -45, -52, -60, -25,
		9, 26, 43, 48, 54, 78, 103, 73, 44, 51, 59, 24, -10, -27,
		-44, -49, -55, -79, -104, -74, -45, -52, -60, -25, 9, 5, 2,
		4, 7, 5, 3, -3, -10, -4, 2};
	r = {make_pair(s,0)};
	esperado = {make_pair(s_esperado, 0)};
	test_ejercicio05.push_back(TestEjercicio05(nom, r, p, f, esperado));

	// Caso 4, segnales constantes
	nom = "ralentizar/segnalesConstantes";
	p = 16;
	f = 10;
	s = {};
	sig1 = {};
	for(int i=0; i<51; i++){
		s.push_back(0);
		sig1.push_back(9);
	}
	s_esperado = {};
	sig1_esperado = {};
	for(int i=0; i<50; i++){
		s_esperado.push_back(0);
		s_esperado.push_back(0);
		sig1_esperado.push_back(9);
		sig1_esperado.push_back(9);
	}
	s_esperado.push_back(0);
	sig1_esperado.push_back(9);
	r = {make_pair(s,0), make_pair(sig1,1)};
	esperado = {make_pair(s_esperado,0), make_pair(sig1_esperado,1)};
	test_ejercicio05.push_back(TestEjercicio05(nom, r, p, f, esperado));

	// Caso 5, segnal que alterna entre valores positivos y negativos
	nom = "ralentizar/segnalQueAlterna";
	p = 16;
	f =10;
	s = {-11,12,-11,11,-12,11,-11,11,-11,11,
		-11,11,-11,11,-11,11,-11,11};
	s_esperado = {-11,0,12,0,-11,0,11,0,-12,0,11,0,-11,0,11,
		0,-11,0,11,0,-11,0,11,0,-11,0,11,0,-11,0,11,0,-11,0,11};
	r = {make_pair(s,0)};
	esperado = {make_pair(s_esperado,0)};
	test_ejercicio05.push_back(TestEjercicio05(nom, r, p, f, esperado));

	int cant_de_tests = test_ejercicio05.size();
	int cant_de_tests_que_pasaron = 0;
	for(int i=0; i<cant_de_tests; i++){
		bool res = test_ejercicio05[i].correrTest();
		cout << ">>> Resultado del test " <<
			test_ejercicio05[i].getNombre() << ": ";
		if(res){
			cant_de_tests_que_pasaron += 1;
			cout << "pasa" << endl;
		} else {
			cout << "falla" << endl;
		}
	}
	cout << "Resultado: " <<
		cant_de_tests_que_pasaron << "/" << cant_de_tests << endl;
	cout << "-----" << endl;
}

//----------------

void iniciarTestsEjercicio06(void) {
	cout << "" << endl;
	cout << "Testeando ejercicio 06..." << endl;
	vector<TestEjercicio06> test_ejercicio06 = {};
	string nom;
	reunion r;
	int p;
	int f;
	vector<hablante> esperado;
	senial sigA, sigB, sigC;
	hablante a, b, c;

	nom = "tonosDeVozElevados/hayUnElevado";
	p = 8;
	f = 10;
	a = 0;
	b = 1;
	sigB = {-9, 43, -54, 103, -44, 59, -10, 44, -55, 104, -45,
		60, -9, 43, -54, 103, -44, 59, -10, 44};
	sigA = {17, -128, 127, -18, 15, -16, 17, -20, 19, -18, 1, -1,
		2, 1, -2, 3, 0, -1, 3, 0, 0, 1, 1, -1, 2, 1, -2, 3, 0, -1, 3,
		0, 0, 1, 1};
	r = {make_pair(sigA, a), make_pair(sigB, b)};
	esperado = {b};
	test_ejercicio06.push_back(TestEjercicio06(nom, r, p, f, esperado));

	// Caso 1, caso t'ipico comparando dos hablantes
	nom = "tonosDeVozElevados/dosHablantesUnoAlto";
	p = 8;
	f = 10;
	a = 0;
	b = 1;
	sigA = {17, -128, 127, -18, 15, -16, 17, -20, 19, -18,
		1, -1, 2, 1, -2, 3, 0, -1, 3, 0,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	sigB = {-9, 43, -54, 103, -44, 59, -10, 44, -55, 104,
		-45, 60, -9, 43, -54, 103, -44, 59, -10, 44,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	r = {make_pair(sigA, a), make_pair(sigB, b)};
	esperado = {b};
	test_ejercicio06.push_back(TestEjercicio06(nom, r, p, f, esperado));

	// Caso 2, igual que el caso anterior, invirtiendo el orden de
	// los hablantes. La implementaci'on sobreescribe el vector
	// `maximos' cuando encuentra una segnal que supera un determinado
	// valor (el valor de tono para los vectores de `maximo'). En
	// este caso el vector resultante deber'ia estar compuesto s'olo
	// por el primer hablante. El vector no deber'ia ser sobreescrito
	// err'oneamente en iteraciones sucesivas.
	nom = "tonosDeVozElevados/dosHablantesOrdenInverso";
	p = 8;
	f = 10;
	a = 0;
	b = 1;
	sigA = {-9, 43, -54, 103, -44, 59, -10, 44, -55, 104,
		-45, 60, -9, 43, -54, 103, -44, 59, -10, 44,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	sigB = {17, -128, 127, -18, 15, -16, 17, -20, 19, -18,
		1, -1, 2, 1, -2, 3, 0, -1, 3, 0,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	r = {make_pair(sigA,a), make_pair(sigB, b)};
	esperado = {a};
	test_ejercicio06.push_back(TestEjercicio06(nom, r, p, f, esperado));

	// Caso 3, dos hablantes con tono m'as elevado
	nom = "tonosDeVozElevados/dosHablantesConTonoElevado";
	p = 8;
	f = 10;
	a = 0;
	b = 1;
	c = 2;
	sigA = {-9, 43, -54, 103, -44, 59, -10, 44, -55, 104,
		-45, 60, -9, 43, -54, 103, -44, 59, -10, 44,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	sigB = {-9, 43, -54, 103, -44, 59, -10, 44, -55, 104,
		-45, 60, -9, 43, -54, 103, -44, 59, -10, 44,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	sigC = {17, -128, 127, -18, 15, -16, 17, -20, 19, -18,
		1, -1, 2, 1, -2, 3, 0, -1, 3, 0,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	r = {make_pair(sigA,a), make_pair(sigB, b), make_pair(sigC, c)};
	esperado = {a,b};
	test_ejercicio06.push_back(TestEjercicio06(nom, r, p, f, esperado));

	// Caso 4, 'ultimos dos hablantes con tono m'as elevado
	nom = "tonosDeVozElevados/ultimosDosConTonoElevado";
	p = 8;
	f = 10;
	a = 0;
	b = 1;
	c = 2;
	sigC = {-9, 43, -54, 103, -44, 59, -10, 44, -55, 104,
		-45, 60, -9, 43, -54, 103, -44, 59, -10, 44,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	sigB = {-9, 43, -54, 103, -44, 59, -10, 44, -55, 104,
		-45, 60, -9, 43, -54, 103, -44, 59, -10, 44,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	sigA = {17, -128, 127, -18, 15, -16, 17, -20, 19, -18,
		1, -1, 2, 1, -2, 3, 0, -1, 3, 0,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	r = {make_pair(sigA,a), make_pair(sigB, b), make_pair(sigC, c)};
	esperado = {b,c};
	test_ejercicio06.push_back(TestEjercicio06(nom, r, p, f, esperado));

	// Caso 5, dos hablantes con tono m'as elevado intercalados
	nom = "tonosDeVozElevedos/dosHablantesConTonoElevadoIntercalados";
	p = 8;
	f = 10;
	a = 0;
	b = 1;
	c = 2;
	sigA = {-9, 43, -54, 103, -44, 59, -10, 44, -55, 104,
		-45, 60, -9, 43, -54, 103, -44, 59, -10, 44,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	sigC = {-9, 43, -54, 103, -44, 59, -10, 44, -55, 104,
		-45, 60, -9, 43, -54, 103, -44, 59, -10, 44,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	sigB = {17, -128, 127, -18, 15, -16, 17, -20, 19, -18,
		1, -1, 2, 1, -2, 3, 0, -1, 3, 0,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	r = {make_pair(sigA,a), make_pair(sigB, b), make_pair(sigC, c)};
	esperado = {a,c};
	test_ejercicio06.push_back(TestEjercicio06(nom, r, p, f, esperado));

	// Caso 6, dos hablantes con tono m'as bajo
	nom = "tonosDeVozElevados/dosHablantesConTonoBajo";
	p = 8;
	f = 10;
	a = 0;
	b = 1;
	c = 2;
	sigA = {17, -128, 127, -18, 15, -16, 17, -20, 19, -18,
		1, -1, 2, 1, -2, 3, 0, -1, 3, 0,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	sigB = {17, -128, 127, -18, 15, -16, 17, -20, 19, -18,
		1, -1, 2, 1, -2, 3, 0, -1, 3, 0,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	sigC = {-9, 43, -54, 103, -44, 59, -10, 44, -55, 104,
		-45, 60, -9, 43, -54, 103, -44, 59, -10, 44,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	r = {make_pair(sigA,a), make_pair(sigB, b), make_pair(sigC, c)};
	esperado = {c};
	test_ejercicio06.push_back(TestEjercicio06(nom, r, p, f, esperado));

	int cant_de_tests = test_ejercicio06.size();
	int cant_de_tests_que_pasaron = 0;
	for(int i=0; i<cant_de_tests; i++){
		bool res = test_ejercicio06[i].correrTest();
		cout << ">>> Resultado del test " <<
			test_ejercicio06[i].getNombre() << ": ";
		if(res){
			cant_de_tests_que_pasaron += 1;
			cout << "pasa" << endl;
		} else {
			cout << "falla" << endl;
		}
	}
	cout << "Resultado: " <<
		cant_de_tests_que_pasaron << "/" << cant_de_tests << endl;
	cout << "-----" << endl;
}

//----------------

void iniciarTestsEjercicio07(void) {
	cout << "" << endl;
	cout << "Testeando ejercicio 07..." << endl;
	vector<TestEjercicio07> test_ejercicio07 = {};
	string nom;
	reunion r;
	int p;
	int f;
	reunion esperado;
	senial sigA, sigB, sigC, sigD;

	nom = "ordenar/reunionOrdenadaAscendiente";
	p = 32;
	f = 10;
	sigA = {-413, -422, -521, -500, 487, 549, 498, -456, -502, 599};
	sigB = {-213, -222, -321, -300, 287, 349, 298, -256, -302, 399};
	sigC = {-13, -22, -121, -100, 87, 149, 98, -56, -102, 199};
	r = {std::make_pair(sigC, 2), std::make_pair(sigB, 1),
		std::make_pair(sigA, 0)};
	esperado = {std::make_pair(sigA, 0), std::make_pair(sigB, 1),
		std::make_pair(sigC, 2)};
	test_ejercicio07.push_back(TestEjercicio07(nom, r, p, f, esperado));

	// Caso 1, ordenar tres segnales distintas
	nom = "ordenar/tresDistintas";
	p = 32;
	f = 10;
	sigA = {-413, -422, -521, -500, 487, 549, 498, -456, -502, 599};
	for(int i=0; i<10; i++){
		sigA.push_back(sigA[i]);
	}
	sigB = {};
	sigC = {};
	for(int i=0; i<20; i++){
		sigB.push_back(sigA[i]+200);
		sigC.push_back(sigB[i]+200);
	}
	r = {make_pair(sigC, 2), make_pair(sigB, 1),
		make_pair(sigA, 0)};
	esperado = {make_pair(sigA, 0), make_pair(sigB, 1),
		make_pair(sigC, 2)};
	test_ejercicio07.push_back(TestEjercicio07(nom, r, p, f, esperado));

	// Caso 2, ordenar cuatro segnales, dos iguales m'as bajas
	nom = "ordenar/cuatroSegnalesDosMasBajas";
	p = 32;
	f = 10;
	sigA = {-413, -422, -521, -500, 487, 549, 498, -456, -502, 599};
	for(int i=0; i<10; i++){
		sigA.push_back(sigA[i]);
	}
	sigB = {};
	sigC = {};
	for(int i=0; i<20; i++){
		sigB.push_back(sigA[i]+200);
		sigC.push_back(sigB[i]+200);
	}
	sigD = sigC;
	r = {make_pair(sigC, 2), make_pair(sigB, 1),
		make_pair(sigA, 0),make_pair(sigD, 3)};
	esperado = {make_pair(sigA, 0), make_pair(sigB, 1),
		make_pair(sigC, 2), make_pair(sigD, 3)};
	test_ejercicio07.push_back(TestEjercicio07(nom, r, p, f, esperado));

	// Caso 3, ordenar cuatro segnales, dos intermedias
	nom = "ordenar/cuatroSegnalesDosIntermedias";
	p = 32;
	f = 10;
	sigA = {-413, -422, -521, -500, 487, 549, 498, -456, -502, 599};
	for(int i=0; i<10; i++){
		sigA.push_back(sigA[i]);
	}
	sigB = {};
	sigC = {};
	for(int i=0; i<20; i++){
		sigB.push_back(sigA[i]+200);
		sigC.push_back(sigB[i]+200);
	}
	sigD = sigB;
	r = {make_pair(sigC, 2), make_pair(sigB, 1),
		make_pair(sigA, 0), make_pair(sigD, 3)};
	esperado = {make_pair(sigA, 0), make_pair(sigB, 1),
		make_pair(sigD, 3), make_pair(sigC, 2)};
	test_ejercicio07.push_back(TestEjercicio07(nom, r, p, f, esperado));

	// Caso 4, ordenar cuatro segnales, dos m'as altas
	nom = "ordenar/cuatroSegnalesDosAltas";
	p = 32;
	f = 10;
	sigA = {-413, -422, -521, -500, 487, 549, 498, -456, -502, 599};
	for(int i=0; i<10; i++){
		sigA.push_back(sigA[i]);
	}
	sigB = {};
	sigC = {};
	for(int i=0; i<20; i++){
		sigB.push_back(sigA[i]+200);
		sigC.push_back(sigB[i]+200);
	}
	sigD = sigA;
	r = {make_pair(sigC, 2), make_pair(sigB, 1),
		make_pair(sigA, 0), make_pair(sigD, 3)};
	esperado = {make_pair(sigA, 0), make_pair(sigD, 3),
		make_pair(sigB, 1), make_pair(sigC, 2)};
	test_ejercicio07.push_back(TestEjercicio07(nom, r, p, f, esperado));

	// Caso 5, ordenar cuatro segnales, dos m'as altas dadas en otro orden
	nom = "ordenar/dosSegnalesAltasEnOtroOrden";
	p = 32;
	f = 10;
	sigA = {-413, -422, -521, -500, 487, 549, 498, -456, -502, 599};
	for(int i=0; i<10; i++){
		sigA.push_back(sigA[i]);
	}
	sigB = {};
	sigC = {};
	for(int i=0; i<20; i++){
		sigB.push_back(sigA[i]+200);
		sigC.push_back(sigB[i]+200);
	}
	sigD = sigA;
	r = {make_pair(sigC, 2), make_pair(sigD, 3),
		make_pair(sigB, 1), make_pair(sigA, 0)};
	esperado = {make_pair(sigD, 3), make_pair(sigA, 0),
		make_pair(sigB, 1), make_pair(sigC, 2)};
	test_ejercicio07.push_back(TestEjercicio07(nom, r, p, f, esperado));

	int cant_de_tests = test_ejercicio07.size();
	int cant_de_tests_que_pasaron = 0;
	for(int i=0; i<cant_de_tests; i++){
		bool res = test_ejercicio07[i].correrTest();
		cout << ">>> Resultado del test " <<
			test_ejercicio07[i].getNombre() << ": ";
		if(res){
			cant_de_tests_que_pasaron += 1;
			cout << "pasa" << endl;
		} else {
			cout << "falla" << endl;
		}
	}
	cout << "Resultado: " <<
		cant_de_tests_que_pasaron << "/" << cant_de_tests << endl;
	cout << "-----" << endl;
}

//----------------

void iniciarTestsEjercicio08(void) {
	cout << "" << endl;
	cout << "Testeando ejercicio 08..." << endl;
	vector<TestEjercicio08> test_ejercicio08 = {};
	string nom;
	senial s;
	int p;
	int f;
	int u;
	vector<pair<int,int>> esperado;

	// Caso 1, tres intervalos de silencio de longitud al menos 2
	nom = "silencios/tresIntervalosDeLongitudAlMenosDos";
	p = 32;
	f = 10;
	u = 80;
	s = {5, -3, 2, 1, 66, 734, -1803, -551, -19, 27, 396, 231,
		32, 33, 14};
	esperado = {make_pair(0, 4), make_pair(8, 9),
		make_pair(12, 14)};
	test_ejercicio08.push_back(TestEjercicio08(nom, s, p, f, u, esperado));

	// Caso 2, segnal de ceros
	nom = "silencios/segnalDeCeros";
	p = 32;
	f = 10;
	u = 80;
	s = {};
	for(int i=0; i<15; i++){
		s.push_back(0);
	}
	esperado = {make_pair(0,14)};
	test_ejercicio08.push_back(TestEjercicio08(nom, s, p, f, u, esperado));

	// Caso 3, segnal de silencio
	nom = "silencios/segnalDeSilencio";
	p = 32;
	f = 10;
	u = 80;
	s = {};
	for(int i=0; i<20; i++){
		int  v = rand() % 100 - 50;
		s.push_back(v);
	}
	esperado = {make_pair(0,19)};
	test_ejercicio08.push_back(TestEjercicio08(nom, s, p, f, u, esperado));

	// Caso 4, segnal que alcanza el umbral en alg'un momento
	nom = "silencios/segnalQueAlcanzaElUmbral";
	p = 32;
	f = 10;
	u = 80;
	s = {};
	for(int i=0; i<10; i++){
		s.push_back(10);
	}
	s.push_back(80);
	for(int i=1; i<10; i++){
		s.push_back(-10);
	}
	esperado = {make_pair(0,9),make_pair(11,19)};
	test_ejercicio08.push_back(TestEjercicio08(nom, s, p, f, u, esperado));

	// Caso 5, un intervalo de silencio de longitud 1
	nom = "silencios/intervaloDeSilencioDeLongitudUno";
	p = 32;
	f = 10;
	u = 80;
	s = { 99, 96, 100, -420, -400, -429, 10, 500, 510, 403, 504, 554,
		450, 354, 320};
	esperado = {};
	test_ejercicio08.push_back(TestEjercicio08(nom, s, p, f, u, esperado));

	// Caso 5bis, un valor bajo umbral
	nom = "silencios/unValorBajoUmbral";
	p = 8;
	f = 10;
	u = 21;
	s = {1, 66, 76, 41, 9, -80, -81, -80, -5, 40, 3, -101, 66};
	esperado = {};
	test_ejercicio08.push_back(TestEjercicio08(nom, s, p, f, u, esperado));

	// Caso 6, dos intervalos de silencio separados por una s'ola muestra
	nom = "silencios/dosIntervalosDeSilencioSeparadosPorUno";
	p = 32;
	f = 10;
	u = 80;
	s = { 9, 9, 10, -42, -40, -42, 145, 50, 51, 40, 50, 55,
		45, 35, 32};
	esperado = {make_pair(0,5), make_pair(7,14)};
	test_ejercicio08.push_back(TestEjercicio08(nom, s, p, f, u, esperado));

	// Caso 7, segnal de silencio salvo una muestra al final
	nom = "silencios/segnalDeSilencioSalvoFinal";
	p = 32;
	f = 10;
	u = 80;
	s = { 9, 9, 10, -42, -40, -42, 14, 50, 51, 40, 50, 55,
		45, 35, 320};
	esperado = {make_pair(0,13)};
	test_ejercicio08.push_back(TestEjercicio08(nom, s, p, f, u, esperado));

	// Caso 8, segnal de silencio salvo una muestra al comienzo
	nom = "silencios/segnalDeSilencioSalvoComienzo";
	p = 32;
	f = 10;
	u = 80;
	s = { 90, 9, 10, -42, -40, -42, 14, 50, 51, 40, 50, 55,
		45, 35, 32};
	esperado = {make_pair(1,14)};
	test_ejercicio08.push_back(TestEjercicio08(nom, s, p, f, u, esperado));

	int cant_de_tests = test_ejercicio08.size();
	int cant_de_tests_que_pasaron = 0;
	for(int i=0; i<cant_de_tests; i++){
		bool res = test_ejercicio08[i].correrTest();
		cout << ">>> Resultado del test " <<
			test_ejercicio08[i].getNombre() << ": ";
		if(res){
			cant_de_tests_que_pasaron += 1;
			cout << "pasa" << endl;
		} else {
			cout << "falla" << endl;
		}
	}
	cout << "Resultado: " <<
		cant_de_tests_que_pasaron << "/" << cant_de_tests << endl;
	cout << "-----" << endl;
}

//----------------

void iniciarTestsEjercicio09(void) {
	cout << "" << endl;
	cout << "Testeando ejercicio 09..." << endl;
	vector<TestEjercicio09> test_ejercicio09 = {};
	string nom;
	reunion r;
	int p;
	int f;
	int u;
	bool esperado;
	senial sigA, sigB, sigC;
	pair<senial, hablante> h_a, h_b, h_c;

	nom = "hablantesSuperpuestos/tresSuperpuestos";
	p = 16;
	f = 10;
	u = 12;
	sigA = {10, 51, 82, 97, 39, 2, 1, 0, 21, 15, 7};
	sigB = {2, 3, 2, -100, -32, -55, -4, -6, -100, -75, 20 };
	sigC = {-61, -9, -7, -65, -77, -8, -30, -3, 27, 36, 5};
	h_a = make_pair(sigA, 0);
	h_b = make_pair(sigB, 1);
	h_c = make_pair(sigC, 2);
	r = {h_a, h_b, h_c};
	esperado = true;
	test_ejercicio09.push_back(TestEjercicio09(nom, r, p, f, u, esperado));

	// Caso 1, tres hablantes se superponen
	nom = "hablantesSuperpuestos/tresHablantesSeSuperponen";
	p = 16;
	f = 10;
	u = 12;
	sigA = {10, 51, 82, 97, 39, 2, 1, 0, 21, 25, 7};
	sigB = {2, 3, 2, -100, -32, -55, -4, -6, -100, -75, 20};
	sigC = {-61, -9, -7, -65, -77, -8, -30, -3, 27, 36, 5};
	r = {make_pair(sigA, 0), make_pair(sigB, 1),
		make_pair(sigC, 2)};
	esperado = true;
	test_ejercicio09.push_back(TestEjercicio09(nom, r, p, f, u, esperado));

	// Caso 2, un 'unic hablante
	nom = "hablantesSuperpuestos/unUnicHablante";
	p = 16;
	f = 10;
	u = 12;
	sigA = {10, 51, 82, 97, 39, 2, 1, 0, 21, 25, 7};
	r = {make_pair(sigA, 0)};
	esperado = false;
	test_ejercicio09.push_back(TestEjercicio09(nom, r, p, f, u, esperado));

	// Caso 3, tres hablantes que se alternan
	nom = "hablantesSuperpuestos/tresHablantesSeAlternan";
	p = 16;
	f = 10;
	u = 12;
	sigA = {10, 9, -4, 2, 0, 56, -98, 100, 23, 65, 7, -5, -6, 7, 2,
		4, -5, 3, 3, 11};
	sigB = {74, 76, 77, -84, 45, 0, -1, 2, 11, 9, 0, 0, -2, 0, 1,
		36, 27, -78, 98, -65};
	sigC = {-1, 11, 2, 3, -5, 3, -3, -4, -6, 5, 7, 10, -9, -4, -8,
		0, 3, 4, -3, 5};
	r = {make_pair(sigA, 0), make_pair(sigB, 1),
		make_pair(sigC, 2)};
	esperado = false;
	test_ejercicio09.push_back(TestEjercicio09(nom, r, p, f, u, esperado));

	// Caso 4, dos hablantes que se superponen al final
	nom = "hablantesSuperpuestos/dosHablantesSeSuperponenAlFinal";
	p = 16;
	f = 10;
	u = 12;
	sigA = {10, 9, -4, 2, 0, 56, -98, 100, 23, 65, 7, -5, -6, 7, 2,
		4, -5, 3, 3, 81};
	sigB = {74, 76, 77, -84, 45, 0, -1, 2, 11, 9, 0, 0, -2, 0, 1,
		36, 27, -78, 98, -65};
	r = {make_pair(sigA, 0), make_pair(sigB, 1)};
	esperado = true;
	test_ejercicio09.push_back(TestEjercicio09(nom, r, p, f, u, esperado));

	int cant_de_tests = test_ejercicio09.size();
	int cant_de_tests_que_pasaron = 0;
	for(int i=0; i<cant_de_tests; i++){
		bool res = test_ejercicio09[i].correrTest();
		cout << ">>> Resultado del test " <<
			test_ejercicio09[i].getNombre() << ": ";
		if(res){
			cant_de_tests_que_pasaron += 1;
			cout << "pasa" << endl;
		} else {
			cout << "falla" << endl;
		}
	}
	cout << "Resultado: " <<
		cant_de_tests_que_pasaron << "/" << cant_de_tests << endl;
	cout << "-----" << endl;
}

//----------------

void iniciarTestsEjercicio10(void) {
	cout << "" << endl;
	cout << "Testeando ejercicio 10..." << endl;
	vector<TestEjercicio10> test_ejercicio10 = {};
	string nom;
	senial s;
	int p;
	int f;
	senial esperado;

	// Caso 0
	nom = "reconstruir/faltantesDeUnaMuestra";
	p = 8;
	f = 10;

	s = {50, 24, 0, 30, 1, -17, -60, 0, -55, -77, -80, 0, -91};
	esperado = {50, 24, 27, 30, 1, -17, -60, -57, -55, -77,
		-80, -85, -91};
	test_ejercicio10.push_back(TestEjercicio10(nom, s, p, f, esperado));

	// Caso 1, tres ceros aislados, todos a reconstruir
	nom = "reconstruir/tresCerosAislados";
	p = 8;
	f = 10;
	s = {50, 24, 0, 30, 1, -17, -60, 0, -55, -77, -80, 0, -91};
	esperado = {50, 24, 27, 30, 1, -17, -60, -57, -55, -77, -80,
		-85, -91};
	test_ejercicio10.push_back(TestEjercicio10(nom, s, p, f, esperado));

	// Caso 2, un intervalo de ceros de longitud tres
	nom = "reconstruir/unIntervaloDeCerosDeLongitudTres";
	p = 8;
	f = 10;
	s = {50, 60, 50, 0, 0, 0, 5, -25, -34, -78, -14, 3, 34, 45, 96};
	esperado = {50, 60, 50, 27, 27, 27, 5, -25, -34, -78, -14, 3,
		34, 45, 96};
	test_ejercicio10.push_back(TestEjercicio10(nom, s, p, f, esperado));

	// Caso 3, un itervalo de ceros de longitud cuatro
	nom = "reconstruir/intervaloDeCerosDeLongitudCuatro";
	p = 8;
	f = 10;
	s = {50, 60, 60, 28, 31, 14, -5, -25, -34, -78, 0, 0, 0, 0, -23};
	esperado = {50, 60, 60, 28, 31, 14, -5, -25, -34, -78, -50,
		-50, -50, -50, -23};
	test_ejercicio10.push_back(TestEjercicio10(nom, s, p, f, esperado));

	// Caso 4, pasajes por cero
	nom = "reconstruir/pasajesPorCero";
	p = 8;
	f = 10;
	s = {50, 60, 60, 28, 31, 14, 0, -25, -34, -78, -46, 0, 23, 73, 96};
	esperado = {50, 60, 60, 28, 31, 14, 0, -25, -34, -78, -46, 0, 23, 73, 96};
	test_ejercicio10.push_back(TestEjercicio10(nom, s, p, f, esperado));

	// Caso 5, un pasaje por cero y una omisi'on
	nom = "reconstruir/pasajePorCeroYOmision";
	p = 8;
	f = 10;
	s = {50, 60, 60, 28, 31, 14, 0, -25, 0, -78, -46, -11, 23, 72, 96};
	esperado = {50, 60, 60, 28, 31, 14, 0, -25, -51, -78, -46,
		-11, 23, 72, 96};
	test_ejercicio10.push_back(TestEjercicio10(nom, s, p, f, esperado));

	// Caso 6, pasaje por cero por un intervalo largo (igual promedia,
	// es decir, no es pasaje por cero)
	nom = "reconstruir/pasajePorCeroPorIntervaloLargoQueNoEsPasaje";
	p = 8;
	f = 10;
	s = {50, 60, 60, 28, 31, 14, 0, 0, 0, -78, -46, -11, 23, 72, 96};
	esperado = {50, 60, 60, 28, 31, 14, -32, -32, -32, -78, -46,
		-11, 23, 72, 96};
	test_ejercicio10.push_back(TestEjercicio10(nom, s, p, f, esperado));

	int cant_de_tests = test_ejercicio10.size();
	int cant_de_tests_que_pasaron = 0;
	for(int i=0; i<cant_de_tests; i++){
		bool res = test_ejercicio10[i].correrTest();
		cout << ">>> Resultado del test " <<
			test_ejercicio10[i].getNombre() << ": ";
		if(res){
			cant_de_tests_que_pasaron += 1;
			cout << "pasa" << endl;
		} else {
			cout << "falla" << endl;
		}
	}
	cout << "Resultado: " <<
		cant_de_tests_que_pasaron << "/" << cant_de_tests << endl;
	cout << "-----" << endl;
}

//----------------

void iniciarTestsEjercicio11(void) {
	cout << "" << endl;
	cout << "Testeando ejercicio 11..." << endl;
	vector<TestEjercicio11> test_ejercicio11 = {};
	string nom;
	senial s;
	int p;
	int f;
	int R;
	senial esperado;

	nom = "filtradoMediana/senialDesordenada";
	p = 16;
	f = 10;
	R = 2;
	s = {54, 23, -65, -102, 34, 71, -35, 77, 13, -46};
	esperado = {54, 23, 23, 23, -35, 34, 34, 13, 13, -46};
	test_ejercicio11.push_back(TestEjercicio11(nom, s, p, f, R, esperado));

	nom = "filtradoMediana/senialCreciente";
	p = 8;
	f = 10;
	R = 2;
	s = {-1, 2, 4, 8, 9, 10, 28, 30, 39, 57, 69, 98, 112};
	esperado = {-1, 2, 4, 8, 9, 10, 28, 30, 39, 57, 69, 98, 112};
	test_ejercicio11.push_back(TestEjercicio11(nom, s, p, f, R, esperado));

	nom = "filtradoMediana/segnalConBordesPesados";
	p = 16;
	f = 10;
	R = 2;
	s = {254, 123, -65, -102, 34, 71, -35, 77, 113, -146};
	esperado = {254, 123, 34, 34, -35, 34, 71, 71, 113, -146};
	test_ejercicio11.push_back(TestEjercicio11(nom, s, p, f, R, esperado));

	nom = "filtradoMediana/senialConPicosYVallesCentrales";
	p = 16;
	f = 10;
	R = 2;
	s = {54, 23, -65, -102, 334, -171, -35, 77, 13, -46};
	esperado = {54, 23, 23, -65, -65, -35, 13, -35, 13, -46};
	test_ejercicio11.push_back(TestEjercicio11(nom, s, p, f, R, esperado));

	// Caso 5, mesetas y llanuras
	nom = "filtradoMediana/senialConMesetasYLLanuras";
	p = 16;
	f = 10;
	R = 2;
	s = {-1, -1, 1, 1, 1, -1, -1, -1, 1, 1, 1,
		-1, -1, -1, 1, 1, 1, -1, -1, -1, 1, 1};
	esperado = {-1, -1, 1, 1, 1, -1, -1, -1, 1, 1, 1,
		-1, -1, -1, 1, 1, 1, -1, -1, -1, 1, 1};
	test_ejercicio11.push_back(TestEjercicio11(nom, s, p, f, R, esperado));

	// Caso 6, r=4
	nom = "filtradoMediana/segnalDesordenadaR4";
	p = 16;
	f = 10;
	R = 4;

	s = {54, 23, -65, 90, -42, -20, 10, 67, 89, -33, -14, -23, 11,
		28, 28, 65, 31, 74, 19, -58, -72, -98, -102, 34, 71, -35, 77,
		13, -46};
	esperado = {54, 23, -65, 90, 23, 10, -14, -14, -14, 10,
		11, 28, 28, 28, 28, 28, 28, 28, 19, 19, 19, -35, -35,
		-35, -35, -35, 77, 13, -46};
	test_ejercicio11.push_back(TestEjercicio11(nom, s, p, f, R, esperado));

	// Caso 7, r=4 con ruido
	nom = "filtradoMediana/segnalDesordenadaR4ConRuido";
	p = 16;
	f = 10;
	R = 4;
	s = {154, -230, -165, 190,
		-42, -20, 10, 67, 89, -133, -14, -23, 11, 128, 28,
		65, 31, 74, 19, -158, -172, -98, -102, 34, 71,
		-135, 177, 113, -146};
	esperado = {154, -230, -165, 190,
		10, -20, -14, -14, -14, 10, 11, 28, 28, 28 , 28,
		28, 28, 28, 19, 19, 19, -98, -98, -98, -98,
		-135, 177, 113, -146};
	test_ejercicio11.push_back(TestEjercicio11(nom, s, p, f, R, esperado));

	p = 16;
	f = 10;
	R = 4;
	s = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15};
	esperado = {1, 3, -3, 4, 1, 0, -2, -8, 9, -15};
	test_ejercicio11.push_back(TestEjercicio11(nom, s, p, f, R, esperado));

	p = 8;
	f = 10;
	R = 4;
	s = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15};
	esperado = {1, 3, -3, 4, 1, 0, -2, -8, 9, -15};
	test_ejercicio11.push_back(TestEjercicio11(nom, s, p, f, R, esperado));

	int cant_de_tests = test_ejercicio11.size();
	int cant_de_tests_que_pasaron = 0;
	for(int i=0; i<cant_de_tests; i++){
		bool res = test_ejercicio11[i].correrTest();
		cout << ">>> Resultado del test " <<
			test_ejercicio11[i].getNombre() << ": ";
		if(res){
			cant_de_tests_que_pasaron += 1;
			cout << "pasa" << endl;
		} else {
			cout << "falla" << endl;
		}
	}
	cout << "Resultado: " <<
		cant_de_tests_que_pasaron << "/" << cant_de_tests << endl;
	cout << "-----" << endl;
}

