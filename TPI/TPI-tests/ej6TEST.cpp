#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(tonosDeVozElevados, hayUnElevado){
    int prof = 8;
    int freq = 10;
    hablante a = 0;
    hablante b = 1;

    senial fstSig = { -9,   43,   -54,  103,   -44,   59,  -10,  44,  -55,   104,
                      -45,  60,   -9,   43,   -54,  103,   -44,   59,  -10,  44};

    senial rdSig = { 17, -128, 127 , -18,  15, -16,  17, -20,  19, -18,
                     1, -1,  2,  1, -2,  3,  0, -1,  3,  0,  0,  1,  1,
                     -1,  2,  1, -2, 3,  0, -1,  3,  0,  0,  1,  1};

    reunion meet6 = {make_pair(rdSig, a), make_pair(fstSig, b)};

    vector<hablante> expectedMeet = {b};

    EXPECT_EQ(tonosDeVozElevados(meet6, prof, freq), expectedMeet);
}

TEST(tonosDeVozElevados, dosHablantesUnoAlto) {
	// Caso 1, caso t'ipico comparando dos hablantes
	int p = 8;
	int f = 10;
	hablante a = 0;
	hablante b = 1;
	senial sigA = {17, -128, 127, -18, 15, -16, 17, -20, 19, -18,
		1, -1, 2, 1, -2, 3, 0, -1, 3, 0,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	senial sigB = {-9, 43, -54, 103, -44, 59, -10, 44, -55, 104,
		-45, 60, -9, 43, -54, 103, -44, 59, -10, 44,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	reunion r = {make_pair(sigA,a), make_pair(sigB, b)};
	vector<hablante> esperado = {b};
	EXPECT_EQ(tonosDeVozElevados(r, p, f), esperado);
}

TEST(tonosDeVozElevados, dosHablantesOrdenInverso) {

	// Caso 2, igual que el caso anterior, invirtiendo el orden de
	// los hablantes. La implementaci'on sobreescribe el vector
	// `maximos' cuando encuentra una segnal que supera un determinado
	// valor (el valor de tono para los vectores de `maximo'). En
	// este caso el vector resultante deber'ia estar compuesto s'olo
	// por el primer hablante. El vector no deber'ia ser sobreescrito
	// err'oneamente en iteraciones sucesivas.
	int p = 8;
	int f = 10;
	hablante a = 0;
	hablante b = 1;
	senial sigA = {-9, 43, -54, 103, -44, 59, -10, 44, -55, 104,
		-45, 60, -9, 43, -54, 103, -44, 59, -10, 44,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	senial sigB = {17, -128, 127, -18, 15, -16, 17, -20, 19, -18,
		1, -1, 2, 1, -2, 3, 0, -1, 3, 0,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	reunion r = {make_pair(sigA,a), make_pair(sigB, b)};
	vector<hablante> esperado = {a};
	EXPECT_EQ(tonosDeVozElevados(r, p, f), esperado);
}

TEST(tonosDeVozElevados, dosHablantesConTonoElevado) {
	// Caso 3, dos hablantes con tono m'as elevado
	int p = 8;
	int f = 10;
	hablante a = 0;
	hablante b = 1;
	hablante c = 2;
	senial sigA = {-9, 43, -54, 103, -44, 59, -10, 44, -55, 104,
		-45, 60, -9, 43, -54, 103, -44, 59, -10, 44,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	senial sigB = {-9, 43, -54, 103, -44, 59, -10, 44, -55, 104,
		-45, 60, -9, 43, -54, 103, -44, 59, -10, 44,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	senial sigC = {17, -128, 127, -18, 15, -16, 17, -20, 19, -18,
		1, -1, 2, 1, -2, 3, 0, -1, 3, 0,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	reunion r = {make_pair(sigA,a), make_pair(sigB, b), make_pair(sigC, c)};
	vector<hablante> esperado = {a,b};
	EXPECT_EQ(tonosDeVozElevados(r, p, f), esperado);
}

TEST(tonosDeVozElevados, ultimosDosConTonoElevado) {
	// Caso 4, 'ultiimos dos hablantes con tono m'as elevado
	int p = 8;
	int f = 10;
	hablante a = 0;
	hablante b = 1;
	hablante c = 2;
	senial sigC = {-9, 43, -54, 103, -44, 59, -10, 44, -55, 104,
		-45, 60, -9, 43, -54, 103, -44, 59, -10, 44,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	senial sigB = {-9, 43, -54, 103, -44, 59, -10, 44, -55, 104,
		-45, 60, -9, 43, -54, 103, -44, 59, -10, 44,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	senial sigA = {17, -128, 127, -18, 15, -16, 17, -20, 19, -18,
		1, -1, 2, 1, -2, 3, 0, -1, 3, 0,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	reunion r = {make_pair(sigA,a), make_pair(sigB, b), make_pair(sigC, c)};
	vector<hablante> esperado = {b,c};
	EXPECT_EQ(tonosDeVozElevados(r, p ,f), esperado);
}

TEST(tonosDeVozElevedos, dosHablantesConTonoElevadoIntercalados) {
	// Caso 5, dos hablantes con tono m'as elevado intercalados
	int p = 8;
	int f = 10;
	hablante a = 0;
	hablante b = 1;
	hablante c = 2;
	senial sigA = {-9, 43, -54, 103, -44, 59, -10, 44, -55, 104,
		-45, 60, -9, 43, -54, 103, -44, 59, -10, 44,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	senial sigC = {-9, 43, -54, 103, -44, 59, -10, 44, -55, 104,
		-45, 60, -9, 43, -54, 103, -44, 59, -10, 44,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	senial sigB = {17, -128, 127, -18, 15, -16, 17, -20, 19, -18,
		1, -1, 2, 1, -2, 3, 0, -1, 3, 0,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	reunion r = {make_pair(sigA,a), make_pair(sigB, b), make_pair(sigC, c)};
	vector<hablante> esperado = {a,c};
	EXPECT_EQ(tonosDeVozElevados(r, p, f), esperado);
}

TEST(tonosDeVozElevados, dosHablantesConTonoBajo) {
	// Caso 6, dos hablantes con tono m'as bajo
	int p = 8;
	int f = 10;
	hablante a = 0;
	hablante b = 1;
	hablante c = 2;
	senial sigA = {17, -128, 127, -18, 15, -16, 17, -20, 19, -18,
		1, -1, 2, 1, -2, 3, 0, -1, 3, 0,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	senial sigB = {17, -128, 127, -18, 15, -16, 17, -20, 19, -18,
		1, -1, 2, 1, -2, 3, 0, -1, 3, 0,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	senial sigC = {-9, 43, -54, 103, -44, 59, -10, 44, -55, 104,
		-45, 60, -9, 43, -54, 103, -44, 59, -10, 44,
		0, 1, 1, -1, 2, 1, -2, 3, 0, -1,
		3, 0, 0, 1, 1};
	reunion r = {make_pair(sigA,a), make_pair(sigB, b), make_pair(sigC, c)};
	vector<hablante> esperado = {c};
	EXPECT_EQ(tonosDeVozElevados(r, p, f), esperado);
}

