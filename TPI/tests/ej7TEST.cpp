#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(ordenar, reunionOrdenadaAscendiente) {
    int p = 32;
    int f = 10;

    senial s_a = {-413, -422, -521, -500, 487, 549, 498, -456, -502, 599};
    senial s_b = {-213, -222, -321, -300, 287, 349, 298, -256, -302, 399};
    senial s_c = {-13, -22, -121, -100, 87, 149, 98, -56, -102, 199};
    reunion r = {std::make_pair(s_c, 2),
	    std::make_pair(s_b, 1), std::make_pair(s_a, 0)};

    ordenar(r, p, f);
    reunion esperada = {std::make_pair(s_a, 0),
	    std::make_pair(s_b, 1), std::make_pair(s_c, 2)};

    EXPECT_EQ(r, esperada);
}

TEST(ordenar, tresDistintas) {
	// Caso 1, ordenar tres segnales distintas
	int p = 32;
	int f = 10;
	senial sigA = {-413, -422, -521, -500, 487, 549, 498, -456, -502, 599};
	for(int i=0; i<10; i++){
		sigA.push_back(sigA[i]);
	}
	senial sigB = {};
	senial sigC = {};
	for(int i=0; i<20; i++){
		sigB.push_back(sigA[i]+200);
		sigC.push_back(sigB[i]+200);
	}
	reunion reunionIO = {make_pair(sigC,2),
		make_pair(sigB,1),make_pair(sigA,0)};
	reunion esperada = {make_pair(sigA, 0), make_pair(sigB, 1),
		make_pair(sigC,2)};
	ordenar(reunionIO, p, f);
	EXPECT_EQ(esperada, reunionIO);
}

TEST(ordenar, cuatroSegnalesDosMasBajas) {
	// Caso 2, ordenar cuatro segnales, dos iguales m'as bajas
	int p = 32;
	int f = 10;
	senial sigA = {-413, -422, -521, -500, 487, 549, 498, -456, -502, 599};
	for(int i=0; i<10; i++){
		sigA.push_back(sigA[i]);
	}
	senial sigB = {};
	senial sigC = {};
	for(int i=0; i<20; i++){
		sigB.push_back(sigA[i]+200);
		sigC.push_back(sigB[i]+200);
	}
	senial sigD = sigC;
	reunion reunionIO = {make_pair(sigC,2),
		make_pair(sigB,1),make_pair(sigA,0),make_pair(sigD,3)};
	reunion esperada_a = {make_pair(sigA, 0), make_pair(sigB,1),
		make_pair(sigC,2), make_pair(sigD,3)};
	reunion esperada_b = {make_pair(sigA,0), make_pair(sigB, 1),
		make_pair(sigD,3), make_pair(sigC,2)};
	ordenar(reunionIO, p , f);
	EXPECT_TRUE((esperada_a==reunionIO)||(esperada_b==reunionIO));
}

TEST(ordenar, cuatroSegnalesDosIntermedias) {
	// Caso 3, ordenar cuatro segnales, dos intermedias
	int p = 32;
	int f = 10;
	senial sigA = {-413, -422, -521, -500, 487, 549, 498, -456, -502, 599};
	for(int i=0; i<10; i++){
		sigA.push_back(sigA[i]);
	}
	senial sigB = {};
	senial sigC = {};
	for(int i=0; i<20; i++){
		sigB.push_back(sigA[i]+200);
		sigC.push_back(sigB[i]+200);
	}
	senial sigD = sigB;
	reunion reunionIO = {make_pair(sigC,2),
		make_pair(sigB,1),make_pair(sigA,0),make_pair(sigD,3)};
	reunion esperada_a = {make_pair(sigA,0),make_pair(sigB,1),
		make_pair(sigD,3), make_pair(sigC, 2)};
	reunion esperada_b = {make_pair(sigA,0),make_pair(sigD,1),
		make_pair(sigB,3), make_pair(sigC, 2)};
	ordenar(reunionIO, p, f);
	EXPECT_TRUE((esperada_a==reunionIO)||(esperada_b==reunionIO));
}

TEST(ordenar, cuatroSegnalesDosAltas) {
	// Caso 4, ordenar cuatro segnales, dos m'as altas
	int p = 32;
	int f = 10;
	senial sigA = {-413, -422, -521, -500, 487, 549, 498, -456, -502, 599};
	for(int i=0; i<10; i++){
		sigA.push_back(sigA[i]);
	}
	senial sigB = {};
	senial sigC = {};
	for(int i=0; i<20; i++){
		sigB.push_back(sigA[i]+200);
		sigC.push_back(sigB[i]+200);
	}
	senial sigD = sigA;
	reunion reunionIO = {make_pair(sigC,2),
		make_pair(sigB,1),make_pair(sigA,0),make_pair(sigD,3)};
	reunion esperada_a = {make_pair(sigA,0),
		make_pair(sigD,3),make_pair(sigB,1),make_pair(sigC,2)};
	reunion esperada_b = {make_pair(sigD,3),
		make_pair(sigA,0),make_pair(sigB,1),make_pair(sigC,2)};
	ordenar(reunionIO, p, f);
	EXPECT_TRUE((esperada_a==reunionIO)||(esperada_b==reunionIO));
}

TEST(ordenar, dosSegnalesAltasEnOtroOrden) {
	// Caso 5, ordenar cuatro segnales, dos m'as altas dadas en otro orden
	int p = 32;
	int f = 10;
	senial sigA = {-413, -422, -521, -500, 487, 549, 498, -456, -502, 599};
	for(int i=0; i<10; i++){
		sigA.push_back(sigA[i]);
	}
	senial sigB = {};
	senial sigC = {};
	for(int i=0; i<20; i++){
		sigB.push_back(sigA[i]+200);
		sigC.push_back(sigB[i]+200);
	}
	senial sigD = sigA;
	reunion reunionIO = {make_pair(sigC,2),make_pair(sigD,3),
		make_pair(sigB,1),make_pair(sigA,0)};
	reunion esperada_a = {make_pair(sigA,0),
		make_pair(sigD,3),make_pair(sigB,1),make_pair(sigC,2)};
	reunion esperada_b = {make_pair(sigD,3),
		make_pair(sigA,0),make_pair(sigB,1),make_pair(sigC,2)};
	ordenar(reunionIO, p, f);
	EXPECT_TRUE((esperada_a==reunionIO)||(esperada_b==reunionIO));
}

