#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(filtradoMediana, senialDesordenada) {
	int p = 16;
	int f = 10;
	int R = 2;

	senial s = {54, 23, -65, -102, 34, 71, -35, 77, 13, -46};

	filtradoMediana(s, R, p, f);
	senial esperada = {54, 23, 23, 23, -35, 34, 34, 13, 13, -46};

	EXPECT_EQ(esperada, s);
}

TEST(filtradoMediana, senialCreciente) {
	int p = 8;
	int f = 10;
	int R = 2;
	senial s = {-1, 2, 4, 8, 9, 10, 28, 30, 39, 57, 69, 98, 112};
	filtradoMediana(s,R, p, f);
	senial esperada = {-1, 2, 4, 8, 9, 10, 28, 30, 39, 57, 69, 98, 112};
	EXPECT_EQ(esperada, s);
}

TEST(filtradoMediana, segnalConBordesPesados) {
	int p = 16;
	int f = 10;
	int R = 2;

	senial s = {254, 123, -65, -102, 34, 71, -35, 77, 113, -146};

	filtradoMediana(s, R, p, f);
	senial esperada = {254, 123, 34, 34, -35, 34, 71, 71, 113, -146};

	EXPECT_EQ(esperada, s);
}

TEST(filtradoMediana, segnalConPicosYVallesCentrales) {
	int p = 16;
	int f = 10;
	int R = 2;

	senial s = {54, 23, -65, -102, 334, -171, -35, 77, 13, -46};

	filtradoMediana(s, R, p, f);
	senial esperada = {54, 23, 23, -65, -65, -35, 13, -35, 13, -46};

	EXPECT_EQ(esperada, s);
}

TEST(filtradoMediana, segnalConMesetasYLLanuras) {
	// Caso 5, mesetas y llanuras
	int p = 16;
	int f = 10;
	int R = 2;
	senial s = {-1, -1, 1, 1, 1, -1, -1, -1, 1, 1, 1,
		-1, -1, -1, 1, 1, 1, -1, -1, -1, 1, 1};
	filtradoMediana(s, R, p, f);
	senial esperada = {-1, -1, 1, 1, 1, -1, -1, -1, 1, 1, 1,
		-1, -1, -1, 1, 1, 1, -1, -1, -1, 1, 1};
	EXPECT_EQ(esperada, s);
}

