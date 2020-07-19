#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(reconstruir, faltantesDeUnaMuestra) {
    int prof = 8;
    int freq = 10;

    senial s = {50, 24, 0, 30, 1, -17, -60, 0, -55, -77,
                -80, 0, -91};
    senial rec = reconstruir(s, prof, freq);
    senial esperada = {50, 24, 27, 30, 1, -17, -60, -57, -55, -77, 
                       -80, -85, -91};

    EXPECT_EQ(rec, esperada);
}

TEST(reconstruir, tresCerosAislados) {
	// Caso 1, tres ceros aislados, todos a reconstruir
	int p = 8;
	int f = 10;
	senial s = {50, 24, 0, 30, 1, -17, -60, 0, -55, -77, -80, 0, -91};
	senial sRec = {50, 24, 27, 30, 1, -17, -60, -57, -55, -77, -80,
		-85, -91};
	senial reconstruida = reconstruir(s, p, f);
	EXPECT_EQ(sRec, reconstruida);
}

TEST(reconstruir, unIntervaloDeCerosDeLongitudTres) {
	// Caso 2, un intervalo de ceros de longitud tres
	int p = 8;
	int f = 10;
	senial s = {50, 60, 50, 0, 0, 0, 5, -25, -34, -78, -14, 3, 34, 45, 96};
	senial sRec = {50, 60, 50, 27, 27, 27, 5, -25, -34, -78, -14, 3, 34, 45, 96};
	senial reconstruida = reconstruir(s, p, f);
	EXPECT_EQ(sRec, reconstruida);
}

TEST(reconstruir, intervaloDeCerosDeLongitudCuatro) {
	// Caso 3, un itervalo de ceros de longitud cuatro
	int p = 8;
	int f = 10;
	senial s = {50, 60, 60, 28, 31, 14, -5, -25, -34, -78, 0, 0, 0, 0, -23};
	senial sRec = {50, 60, 60, 28, 31, 14, -5, -25, -34, -78, -50,
		-50, -50, -50, -23};
	senial reconstruida = reconstruir(s, p, f);
	EXPECT_EQ(sRec, reconstruida);
}

TEST(reconstruir, pasajesPorCero) {
	// Caso 4, pasajes por cero
	int p = 8;
	int f = 10;
	senial s = {50, 60, 60, 28, 31, 14, 0, -25, -34, -78, -46, 0, 23, 73, 96};
	senial sRec = {50, 60, 60, 28, 31, 14, 0, -25, -34, -78, -46, 0, 23, 73, 96};
	senial reconstruida = reconstruir(s, p, f);
	EXPECT_EQ(sRec, reconstruida);
}

TEST(reconstruir, pasajePorCeroYOmision) {
	// Caso 5, un pasaje por cero y una omisi'on
	int p = 8;
	int f = 10;
	senial s = {50, 60, 60, 28, 31, 14, 0, -25, 0, -78, -46, -11, 23, 72, 96};
	senial sRec = {50, 60, 60, 28, 31, 14, 0, -25, -51, -78, -46,
		-11, 23, 72, 96};
	senial reconstruida = reconstruir(s, p, f);
	EXPECT_EQ(sRec, reconstruida);
}

TEST(reconstruir, pasajePorCeroPorIntervaloLargoQueNoEsPasaje) {
	// Caso 6, pasaje por cero por un intervalo largo (igual promedia,
	// es decir, no es pasaje por cero)
	int p = 8;
	int f = 10;
	senial s = {50, 60, 60, 28, 31, 14, 0, 0, 0, -78, -46, -11, 23, 72, 96};
	senial sRec = {50, 60, 60, 28, 31, 14, -32, -32, -32, -78, -46,
		-11, 23, 72, 96};
	senial reconstruida = reconstruir(s, p, f);
	EXPECT_EQ(sRec, reconstruida);
}

