#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(acelerar, segnalLargoImpar) {
	// Caso 1, provisto por la materia, acelerar una s'ola segnal
	// de longitiud impar.
	// Notar que no se verifica la condici'on longitudesValidas
	// ?`No es 1000 un tanto grande?
	int p = 16;
	int f = 10;
	senial sig = {9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45, -60,
		9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45, -60, 9};
	reunion reunionIO = {make_pair(sig,0)};
	senial sig_res = {43, 103, 59, -44, -104, -60, 43, 103, 59, -44,
		-104, -60};
	reunion r_esperada = {make_pair(sig_res,0)};
	acelerar(reunionIO, p , f);
	EXPECT_EQ(r_esperada, reunionIO);
}

TEST(acelerar, acelerarVariasSegnales) {
	// Caso 2, acelerar varias segnales.
	// Los valores de p y f se mantienen
	int p = 16;
	int f = 10;
	senial sig = {9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45, -60,
		9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45, -60, 9};
	senial sig1 = {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
	senial sig2 = {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0};
	reunion reunionIO = {make_pair(sig,0), make_pair(sig1,1),
		make_pair(sig2,2)};
	
	senial sig_esperada = {43, 103, 59, -44, -104, -60, 43, 103, 59, -44,
		-104, -60};
	senial sig1_esperada = {0,0,0,0,0,0,0,0,0,0,0,0};
	senial sig2_esperada = {1,1,1,1,1,1,1,1,1,1,1,1};
	reunion r_esperada = {make_pair(sig_esperada,0),
		make_pair(sig1_esperada,1), make_pair(sig2_esperada,2)};
	acelerar(reunionIO, p, f);
	EXPEC_EQ(r_esperada, reunionIO);
}

TEST(acelerar, segnalesDeLongitudPar) {
	// Caso 3, segnales de longitud par
	int p = 16;
	int f = 10;
	senial sig = {9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45, -60,
		9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45, -60, 9,
		2, 7, 3, -10, 2};
	senial sig1 = {0,1,-1,0,1,-1,0,1,-1,0,1,-1,0,1,-1,
		0,1,-1,0,1,-1,0,1,-1,0,1,-1,0,1,-1};
	senial sig2 = {1,0,20,1,0,20,1,0,20,1,0,20,1,0,20,
		1,0,20,1,0,20,1,0,20,1,0,20,1,0,20};

	senial sig_esperada = {43, 103, 59, -44, -104, -60, 43, 103, 59, -44,
		-104, -60, 2, 3, 2};
	senial sig1_esperada = {1,0,-1,1,0,-1,1,0,-1,1,0,-1,1,0,-1};
	senial sig2_esperada = {0,1,20,0,1,20,0,1,20,0,1,20,0,1,20};

	reunion reunionIO = {make_pair(sig,0), make_pair(sig1,1),
		make_pair(sig2,2)};
	reunion r_esperada = {make_pair(sig_esperada,0),
		make_pair(sig1_esperada,1), make_pair(sig2_esperada,2)};
	acelerar(reunionIO, p, f);
	EXPECT_EQ(r_esperada, reunionIO);
}

