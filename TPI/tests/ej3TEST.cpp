#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(esReunionValida, reunionCuadra) {
	// Caso 0, reuni'on v'alida
	senial sig1 = {17, -128, 127, 18, 15, -16, 0, 17, -20, 19, -18};
	senial sig2 = {17, -128, 127, 18, 15, -16, 0, 17, -20, 19, -18};
	senial sig3 = {17, -128, 127, 18, 15, -16, 0, 17, -20, 19, -18};
	reunion r = {make_pair(sig1,0), make_pair(sig2,1), make_pair(sig3,2)};
	int p = 8;
	int f = 10;
	EXPECT_TRUE(esReunionValida(r, p, f));


TEST(esReunionValida, reunionNoCuadra) {
	// Caso 1, provisto por la materia. La reuni'on no es v'alida
	// porque una de las segnales es m'as corta. Adem'as, dependiendo
	// de la implementaci'on, la raz'on tambi'en puede ser que
	// por lo menos dos de las tres segnales no son v'alidas
	senial sig1 = {17, -128, 128, 18, 15, -16, 0, 17, -20, 19, -18};
	senial sig2 = {17, -128, 127, 18, 15, -16, 0, 17, -20, 19, -18};
	senial sig3 = {17, -128, 127, 18, 15, -16, 0, 17, -20, 19};

	reunion r = {make_pair(sig1,0), make_pair(sig2,1), make_pair(sig3,2)};
	int p = 8;
	int f = 10;
	EXPECT_FALSE(esReunionValida(r, p, f));
}

TEST(esReunionValida, segnalFueraDeRango) {
	// Caso 2, una segnal (justo) fuera de rango
	senial sig1 = {17, -120, 128, 18, 15, -16, 0, 17, -20, 19, -18};
	senial sig2 = {17, -120, 120, 18, 15, -16, 0, 17, -20, 19, -18};
	senial sig3 = {17, -120, 120, 18, 15, -16, 0, 17, -20, 19, -18};
	for(int i=0; i<10; i++){
		sig1.push_back(0);
		sig2.push_back(0);
		sig3.push_back(0);
	}
	reunion r = {make_pair(sig1,0), make_pair(sig2,1), make_pair(sig3,2)};
	int p = 8;
	int f = 10;
	EXPECT_FALSE(esReunionValida(r, p, f));
}

TEST(esReunionValida, dosSegnalesConMismoId) {
	// Caso 3, dos segnales comparten id
	senial sig1 = {17, -120, 120, 18, 15, -16, 0, 17, -20, 19, -18};
	senial sig2 = {17, -120, 120, 18, 15, -16, 0, 17, -20, 19, -18};
	senial sig3 = {17, -120, 120, 18, 15, -16, 0, 17, -20, 19, -18};
	for(int i=0; i<10; i++){
		sig1.push_back(0);
		sig2.push_back(0);
		sig3.push_back(0);
	}
	reunion r = {make_pair(sig1,0), make_pair(sig2,1),
		make_pair(sig3,0)};
	int p = 8;
	int f = 10;
	EXPECT_FALSE(esReunionValida(r, p, f));
}

TEST(esReunionValida, segnalConIdInv'alido) {
	// Caso 4, una segnal con id inv'alido
	senial sig1 = {17, -120, 120, 18, 15, -16, 0, 17, -20, 19, -18};
	senial sig2 = {17, -120, 120, 18, 15, -16, 0, 17, -20, 19, -18};
	senial sig3 = {17, -120, 120, 18, 15, -16, 0, 17, -20, 19, -18};
	for(int i=0; i<10; i++){
		sig1.push_back(0);
		sig2.push_back(0);
		sig3.push_back(0);
	}
	reunion r = {make_pair(sig1,0), make_pair(sig2,3),
		make_pair(sig3,2)};
	int p = 8;
	int f = 10;
	EXPECT_FALSE(esReunionValida(r, p, f));
}

