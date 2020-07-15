#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(ralentizar, unHablanteSenialAscendente) {
    int prof = 16;
    int freq = 10;

    senial sig1={ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    reunion meet_out = { make_pair(sig1,0 )  };

    senial sig1_res={1, 1, 2, 2, 3, 3, 4, 4, 5, 5,
                     6, 6, 7, 7, 8, 8, 9, 9, 10};

    reunion meet_res = { make_pair(sig1_res,0 ) };

    ralentizar(meet_out,prof,freq);

    EXPECT_EQ(meet_res, meet_out);
}

TEST(ralentizar, unaSegnalDeLogitudImpar) {
	// Caso 1, provisto por la materia, ralentizar una s'ola segnal
	// de longitiud impar. Aprovechamos los casos del ejercicio
	// anterior
	int p = 16;
	int f = 10;
	senial sig = {9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45, -60,
		9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45, -60, 9};
	reunion reunionIO = {make_pair(sig,0)};
	senial sig_res = {9, 26, 43, 48, 54, 78, 103, 73, 44, 51, 59, 23,
		-10, -27, -44, -49, -55, -79, -104, -74, -45, -52, -60, -25,
		9, 26, 43, 48, 54, 78, 103, 73, 44, 51, 59, 23, -10, -27,
		-44, -49, -55, -79, -104, -74, -45, -52, -60, -25, 9};
	reunion res = {make_pair(sig_res,0)};
	ralentizar(reunionIO, p, f);
	EXPECT_EQ(res, reunionIO);
}

TEST(ralentizar, ralentizarVariasSegnales) {
	// Caso 2, ralentizar varias segnales.
	// Los valores de p y f se mantienen
	int p = 16;
	int f = 10;
	senial sig = {9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45, -60,
		9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45, -60, 9};
	senial sig1 = {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
	senial sig2 = {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0};

	senial sig_res = {9, 26, 43, 48, 54, 78, 103, 73, 44, 51, 59, 23,
		-10, -27, -44, -49, -55, -79, -104, -74, -45, -52, -60, -25,
		9, 26, 43, 48, 54, 78, 103, 73, 44, 51, 59, 23, -10, -27,
		-44, -49, -55, -79, -104, -74, -45, -52, -60, -25, 9};
	senial sig1_res = {1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,
		0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1};
	senial sig2_res = {0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,
		0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0};
	reunion reunionIO = {make_pair(sig,0), make_pair(sig1,1),
		make_pair(sig2,2)};
	reunion res = {make_pair(sig_res,0), make_pair(sig1_res,1),
		make_pair(sig2_res,2)};
	ralentizar(reunionIO, p, f);
	EXPECT_EQ(res, reunionIO);
}

TEST(ralentizar, segnalDeLongitudPar) {
	// Caso 3, segnal de longitud par
	int p = 16;
	int f = 10;
	senial sig = {9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45, -60,
		9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45, -60, 9,
		2, 7, 3, -10, 2};
	senial sig_res = {9, 26, 43, 48, 54, 78, 103, 73, 44, 51, 59, 23,
		-10, -27, -44, -49, -55, -79, -104, -74, -45, -52, -60, -25,
		9, 26, 43, 48, 54, 78, 103, 73, 44, 51, 59, 23, -10, -27,
		-44, -49, -55, -79, -104, -74, -45, -52, -60, -25, 9, 5, 2,
		4, 7, 5, 3, -3, -10, -4, 2};
	reunion reunionIO = {make_pair(sig,0)};
	reunion res ={make_pair(sig_res, 0)};
	ralentizar(reunionIO, p, f);
	EXPECT_EQ(res, reunionIO);
}

TEST(ralentizar, segnalesConstantes) {
	// Caso 4, segnales constantes
	int p = 16;
	int f = 10;
	senial sig = {};
	senial sig1 = {};
	for(int i=0; i<51; i++){
		sig.push_back(0);
		sig1.push_back(9);
	}
	senial sig_res = {};
	senial sig1_res = {};
	for(int i=0; i<50; i++){
		sig_res.push_back(0);
		sig_res.push_back(0);
		sig1_res.push_back(9);
		sig1_res.push_back(9);
	}
	sig_res.push_back(0);
	sig1_res.push_back(9);

	reunion reunionIO = {make_pair(sig,0), make_pair(sig1,1)};
	reunion res = {make_pair(sig_res,0), make_pair(sig1_res,1)};
	ralentizar(reunionIO, p, f);
	EXPECT_EQ(res, reunionIO);
}

TEST(ralentizar, segnalQueAlterna) {
	// Caso 5, segnal que alterna entre valores positivos y negativos
	int p = 16;
	int f =10;
	senial sig = {-11,11,-11,11,-11,11,-11,11,-11,11,
		-11,11,-11,11,-11,11,-11,11};
	senial sig_res = {-11,0,11,0,-11,0,11,0,-11,0,11,0,-11,0,11,
		0,-11,0,11,0,-11,0,11,0,-11,0,11,0,-11,0,11,0,-11,0,11}
	reunion reunionIO = {make_pair(sig,0)};
	reunion res = {make_pair(sig_res,0)};
	ralentizar(reunionIO, p, f);
	EXPECT_EQ(res, reunionIO);
}

