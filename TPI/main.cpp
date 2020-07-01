// MAIN del Trabajo Practico de Implementacion

#include <iostream>
#include <string>

//#include "gtest/gtest.h"

#include "TPI-tests/TestSuite.h"
#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

/*
int main(int argc, char **argv) {
    std::cout << "Implementando TPI!!" << std::endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/

string informe(bool res){
	string pasa = "asgf";
	if(res){
		pasa = "pasa";
	} else {
		pasa = "falla";
	}
}

int main(void){
	cout << "Corriendo algunos tests..." << endl;
	senial sig = { 9,   43,   54,  103,   44,   59,  -10,  -44,  -55, -104,  -45,
        -60,    9,   43,   54,  103,   44,   59,  -10,  -44,  -55, -104,
        -45,  -60,    9};
    for(int i=0;i<100;i++){
		sig.push_back(0);
	}
	int p = 8;
	int f = 100;
	bool val = true;

	TestEjercicio01 test01("test01",sig,p,f,val);
	bool res = test01.correrTest();

	cout << "Resultado del test " << test01.getNombre() << ": ";
	if(res){
		cout << "pasa" << endl;
	} else {
		cout << "falla" << endl;
	}
	return 0;
}
