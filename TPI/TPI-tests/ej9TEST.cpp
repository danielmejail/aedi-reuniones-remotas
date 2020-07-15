#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(hablantesSuperpuestos, tresSuperpuestos) {
    int prof = 16;
    int freq = 10;
    int umbral = 12;

    senial s_a = {10, 51, 82, 97, 39, 2, 1, 0, 21, 15, 7};
    senial s_b = {2, 3, 2, -100, -32, -55, -4, -6, -100, -75, 20 };
    senial s_c = {-61, -9, -7, -65, -77, -8, -30, -3, 27, 36, 5};
    pair <senial, hablante> h_a (s_a, 0);
    pair <senial, hablante> h_b (s_b, 1);
    pair <senial, hablante> h_c (s_c, 2);

    reunion r = {h_a, h_b, h_c};

    EXPECT_TRUE(hablantesSuperpuestos(r, prof, freq, umbral));
}

TEST(hablantesSuperpuestos, tresHablantesSeSuperponen) {
	// Caso 1, tres hablantes se superponen
	int p = 16;
	int f = 10;
	int u = 12;

	senial sigA = {10, 51, 82, 97, 39, 2, 1, 0, 21, 25, 7};
	senial sigB = {2, 3, 2, -100, -32, -55, -4, -6, -100, -75, 20};
	senial sigC = {-61, -9, -7, -65, -77, -8, -30, -3, 27, 36, 5};
	reunion r = {make_pair(sigA, 0), make_pair(sigB, 1),
		make_pair(sigC, 2)};
	EXPECT_TRUE(hablantesSuperpuestos(r, p, f, u));
}

TEST(hablantesSuperpuestos, unUnicHablante) {
	// Caso 2, un 'unic hablante
	int p = 16;
	int f = 10;
	int u = 12;
	senial sigA = {10, 51, 82, 97, 39, 2, 1, 0, 21, 25, 7};
	reunion r = {make_pair(sigA, 0)};
	EXPECT_FALSE(hablantesSuperpuestos(r, p, f, u));
}

TEST(hablantesSuperpuestos, tresHablantesSeRespetan) {
	// Caso 3, tres hablantes que se respetan
	int p = 16;
	int f = 10;
	int u = 12;
	senial sigA = {10, 9, -4, 2, 0, 56, -98, 100, 23, 65, 7, -5, -6, 7, 2,
		4, -5, 3, 3, 11};
	senial sigB = {74, 76, 77, -84, 45, 0, -1, 2, 11, 9, 0, 0, -2, 0, 1,
		36, 27, -78, 98, -65};
	senial sigC = {-1, 11, 2, 3, -5, 3, -3, -4, -6, 5, 7, 10, -9, -4, -8,
		0, 3, 4, -3, 5};
	reunion r = {make_pair(sigA, 0), make_pair(sigB, 1),
		make_pair(sigC, 2)};
	EXPECT_FALSE(hablantesSuperpuestos(r, p, f, u));
}

TEST(hablantesSuperpuestos, dosHablantesSeSuperponenAlFinal) {
	// Caso 4, dos hablantes que se superponen al final
	int p = 16;
	int f = 10;
	int u = 12;
	senial sigA = {10, 9, -4, 2, 0, 56, -98, 100, 23, 65, 7, -5, -6, 7, 2,
		4, -5, 3, 3, 81};
	senial sigB = {74, 76, 77, -84, 45, 0, -1, 2, 11, 9, 0, 0, -2, 0, 1,
		36, 27, -78, 98, -65};
	reunion r = {make_pair(sigA, 0), make_pair(sigB, 1)};
	EXPECT_TRUE(hablantesSuperpuestos(r, p, f, u));
}

