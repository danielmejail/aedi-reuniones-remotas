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

//------- nuevos tests
TEST(filtradoMediana, senialDesordenadaR4) {
    int p = 16;
    int f = 10;
    int R = 4;

    senial s = {54, 23, -65, 90, -42, -20, 10, 67, 89, -33, -14, -23, 11,
                28, 28, 65, 31, 74, 19, -58, -72, -98, -102, 34, 71, -35, 77,
                13, -46};

    filtradoMediana(s, R, p, f);
    senial esperada = {54, 23, -65, 90, 23, 10, -14, -14, -14, 10,
                       11, 28, 28, 28, 28, 28, 28, 28, 19, 19, 19, -35, -35,
                       -35, -35, -35, 77, 13, -46};

    EXPECT_EQ(esperada, s);
}

TEST(filtradoMediana, senialDesordenadaR4ConRuido) {
    int p = 16;
    int f = 10;
    int R = 4;

    senial s = {154, -230, -165, 190,
                -42, -20, 10, 67, 89, -133, -14, -23, 11, 128, 28,
                65, 31, 74, 19, -158, -172, -98, -102, 34, 71,
                -135, 177, 113, -146};

    filtradoMediana(s, R, p, f);
    senial esperada = {154, -230, -165, 190,
                       10, -20, -14, -14, -14, 10, 11, 28, 28, 28 , 28,
                       28, 28, 28, 19, 19, 19, -98, -98, -98, -98,
                       -135, 177, 113, -146};

    EXPECT_EQ(esperada, s);
}
