// MAIN del Trabajo Practico de Implementacion

#include <iostream>
#include <string>

#include "gtest/gtest.h"

#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"
//#include "TPI-tests/test_suites.h"
//#include "TPI-tests/Test.h"

using namespace std;


int main(int argc, char **argv) {
    std::cout << "Implementando TPI!!" << std::endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


/*
int main(void){
	iniciarTestsEjercicio01();
	iniciarTestsEjercicio02();
	iniciarTestsEjercicio03();
	iniciarTestsEjercicio04();
	iniciarTestsEjercicio05();
	iniciarTestsEjercicio06();
	iniciarTestsEjercicio07();
	iniciarTestsEjercicio08();
	iniciarTestsEjercicio09();
	iniciarTestsEjercicio10();
	iniciarTestsEjercicio11();
	return 0;
}
*/

