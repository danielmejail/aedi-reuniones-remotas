#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(seEnojo, checkForSubseqOfMinSizeTwoTimesFreq) {
	int prof = 8;
	int freq = 10;
	int thresh = 65;

	senial fstSig = {17, 32, 80, 85, 99, 62, 7, -55, -107, -101, -88, -26,
		-3, 52, 62, 99, 89, 67, 7, -61, -97, -115, -71, -45, 17};

	EXPECT_FALSE(seEnojo(fstSig, thresh, prof, freq));
}

TEST(seEnojo, umbralAltoNoSeEnoja) {
	// Caso 1, umbral inv'alido. Aun as'i, de acuerdo con la
	// implementaci'on, se deber'ia poder correr el programa sin errores
	// y esperar falso.
	senial sig = { 9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45,
	       -60, 9, 43, 54, 103, 44, 59, -10, -44, -55, -104, -45, -60, 9};
	int u = 1000;
	int p = 8;
	int f = 10;

	EXPECT_FALSE(seEnojo(sig, u, p, f));
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
	senial sig = {};
	for(int i=0;i<500; i++){
		sig.push_back(0);
	}
	sig.push_back(100);
	int u = 99;
	int p = 8;
	int f = 10;

	EXPECT_FALSE(seEnojo(sig, u, p, f));
}

TEST(seEnojo, arrancaEnojoYSeCalma) {
	// Caso 4, arranca enojady y se calma
	senial sig = {};
	for(int i=0;i<20; i++){
		sig.push_back(100);
	}
	sig.push_back(0);
	for(int i=0;i<30; i++){
		sig.push_back(3);
		sig.push_back(-3);
	}
	int u = 99;
	int p = 8;
	int f = 10;

	EXPECT_TRUE(seEnojo(sig, u, p, f));
}

TEST(seEnojo, seEnojaEnLaMitad) {
	// Caso 5, se enoja en la mitad de la segnal
	senial sig = {};
	for(int i=0;i<50; i++){
		sig.push_back(0);
	}
	for(int i=0;i<10; i++){
		sig.push_back(-100);
		sig.push_back(100);
	}
	sig.push_back(100);
	for(int i=0;i<30; i++){
		sig.push_back(3);
		sig.push_back(-3);
	}
	int u = 99;
	int p = 8;
	int f = 10;
	EXPECT_TRUE(seEnojo(sig, u, p, f));
}

TEST(seEnojo, longitudDeLaSubSecuenciaInsuficiente) {
	// Caso 6, longitud de la subsecuencia es insuficiente
	senial sig = {};
	for(int i=0;i<19; i++){
		sig.push_back(100);
	}
	sig.push_back(0);
	for(int i=0;i<30; i++){
		sig.push_back(3);
		sig.push_back(-3);
	}
	int u = 99;
	int p = 8;
	int f = 10;
	EXPECT_FALSE(seEnojo(sig, u, p, f));
}

