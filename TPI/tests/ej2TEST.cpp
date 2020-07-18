#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(seEnojo, checkForSubseqOfMinSizeTwoTimesFreq) {
	int p = 8;
	int f = 10;
	int u = 65;

	senial s = {17, 32, 80, 85, 99, 62, 7, -55, -107, -101, -88, -26,
		-3, 52, 62, 99, 89, 67, 7, -61, -97, -115, -71, -45, 17};

	EXPECT_TRUE(seEnojo(s, u, p, f));
}

TEST(seEnojo, umbralAltoNoSeEnoja) {
	// Caso 1, umbral inv'alido. Aun as'i, de acuerdo con la
	// implementaci'on, se deber'ia poder correr el programa sin errores
	// y esperar falso.
	senial s = { 9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45,
	       -60, 9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45, -60, 9};
	int u = 1000;
	int p = 8;
	int f = 10;

	EXPECT_FALSE(seEnojo(s, u, p, f));
}

TEST(seEnojo, permaneceEnSilencio) {
	// Caso 2, permanece en silencio
	senial sig = {};
	for(int i=0;i<25;i++){
		sig.push_back(0);
	}
	int u = 100;
	int p = 16;
	int f = 10;

	EXPECT_FALSE(seEnojo(sig, u, p, f));
}

TEST(seEnojo, estallaAlFinal) {
	// Caso 3, estalla al final
	senial s = {};
	for(int i=0;i<500; i++){
		s.push_back(0);
	}
	s.push_back(100);
	int u = 99;
	int p = 8;
	int f = 10;

	EXPECT_FALSE(seEnojo(s, u, p, f));
}

TEST(seEnojo, seEnojaDosSegundos) {
	// Caso 4, justo dos segundos de enojo
	senial s = {};
	for(int i=0;i<20; i++){
		s.push_back(100);
	}
	s.push_back(0);
	int u = 99;
	int p = 8;
	int f = 10;
	EXPECT_TRUE(seEnojo(s, u, p, f));
}

TEST(seEnojo, dosSegundos) {
	// Caso 5, dos segundos dura la segnal
	senial s = {};
	for(int i=0;i<20; i++){
		s.push_back(100);
	}
	int u = 99;
	int p = 8;
	int f = 10;
	EXPECT_FALSE(seEnojo(s, u, p, f));
}

TEST(seEnojo, seEnojaJustoDespuesDeDosSegundos) {
	// Caso 6, se enoja justo despu'es de los dos
	senial s = {};
	for(int i=0;i<19; i++){
		s.push_back(100);
	}
	s.push_back(80);
	s.push_back(100);
	s.push_back(0);
	int u = 99;
	int p = 8;
	int f = 10;
	EXPECT_TRUE(seEnojo(s, u, p, f));
}

TEST(seEnojo, justoDespuesDeDosSegundosNoEsPropia){
	// Caso 7, se enoja justo despu'es de los dos, pero no es propia.
	// No se enoja
	senial s = {};
	for(int i=0;i<19; i++){
		s.push_back(100);
	}
	s.push_back(80);
	s.push_back(100);
	int u = 99;
	int p = 8;
	int f = 10;
	EXPECT_FALSE(seEnojo(s, u, p, f));
}

