#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(silencios, tresIntervalosDeLongitudAlMenosDos) {
	// Caso 1, tres intervalos de silencio de longitud al menos 2
	int p = 32;
	int f = 10;
	int u = 80;
	senial s = {5, -3, 2, 1, 66, 734, -1803, -551, -19, 27, 396, 231,
		32, 33, 14};
	vector<pair<int, int>> intervalos = silencios(s, p, f, u);
	vector<pair<int, int>> esperado = {make_pair(0, 4), make_pair(8, 9),
		make_pair(12, 14)};
	EXPECT_EQ(intervalos, esperado);
}

TEST(silencios, segnalDeCeros) {
	// Caso 2, segnal de ceros
	int p = 32;
	int f = 10;
	int u = 80;
	senial s = {};
	for(int i=0; i<15; i++){
		s.push_back(0);
	}
	vector<pair<int, int>> intervalos = silencios(s, p, f, u);
	vector<pair<int, int>> esperado = {make_pair(0,14)};
	EXPECT_EQ(intervalos, esperado);
}

TEST(silencios, segnalDeSilencio) {
	// Caso 3, segnal de silencio
	int p = 32;
	int f = 10;
	int u = 80;
	senial s = {};
	for(int i=0; i<20; i++){
		int  v = rand() % 100 - 50;
		s.push_back(v);
	}
	vector<pair<int, int>> intervalos = silencios(s, p, f, u);
	vector<pair<int, int>> esperado = {make_pair(0,19)};
	EXPECT_EQ(intervalos, esperado);
}


TEST(silencios, segnalQueAlcanzaElUmbral) {
	// Caso 4, segnal que alcanza el umbral en alg'un momento
	int p = 32;
	int f = 10;
	int u = 80;
	senial s = {};
	for(int i=0; i<10; i++){
		s.push_back(10);
	}
	s.push_back(80);
	for(int i=1; i<10; i++){
		s.push_back(-10);
	}
	vector<pair<int, int>> intervalos = silencios(s, p, f, u);
	vector<pair<int, int>> esperado = {make_pair(0,9),make_pair(11,19)};
	EXPECT_EQ(intervalos, esperado);
}

TEST(silencios, intervaloDeSilencioDeLongitudUno) {
	// Caso 5, un intervalo de silencio de longitud 1
	int p = 32;
	int f = 10;
	int u = 80;
	senial s = { 99, 96, 100, -420, -400, -429, 10, 500, 510, 403, 504, 554,
		450, 354, 320};
	vector<pair<int, int>> intervalos = silencios(s, p, f, u);
	vector<pair<int, int>> esperado = {};
	EXPECT_EQ(intervalos, esperado);
}

TEST(silencios, unValorBajoUmbral) {
	// Caso 5bis, un valor bajo umbral
	int p = 8;
	int f = 10;
	int u = 21;
	senial s = {1, 66, 76, 41, 9, -80, -81, -80, -5, 40, 3, -101, 66};
	vector<pair<int, int>> intervalos = silencios(s, p, f, u);
	vector<pair<int, int>> esperado = {};
	EXPECT_EQ(intervalos, esperado);
}


TEST(silencios, dosIntervalosDeSilencioSeparadosPorUno) {
	// Caso 6, dos intervalos de silencio separados por una s'ola muestra
	int p = 32;
	int f = 10;
	int u = 80;
	senial s = { 9, 9, 10, -42, -40, -42, 145, 50, 51, 40, 50, 55,
		45, 35, 32};
	vector<pair<int, int>> intervalos = silencios(s, p, f, u);
	vector<pair<int, int>> esperado = {make_pair(0,5), make_pair(7,14)};
	EXPECT_EQ(intervalos, esperado);
}

TEST(silencios, segnalDeSilencioSalvoFinal) {
	// Caso 7, segnal de silencio salvo una muestra al final
	int p = 32;
	int f = 10;
	int u = 80;
	senial s = { 9, 9, 10, -42, -40, -42, 14, 50, 51, 40, 50, 55,
		45, 35, 320};
	vector<pair<int, int>> intervalos = silencios(s, p, f, u);
	vector<pair<int, int>> esperado = {make_pair(0,13)};
	EXPECT_EQ(intervalos, esperado);
}

TEST(silencios, segnalDeSilencioSalvoComienzo) {
	// Caso 8, segnal de silencio salvo una muestra al comienzo
	int p = 32;
	int f = 10;
	int u = 80;
	senial s = { 90, 9, 10, -42, -40, -42, 14, 50, 51, 40, 50, 55,
		45, 35, 32};
	vector<pair<int, int>> intervalos = silencios(s, p, f, u);
	vector<pair<int, int>> esperado = {make_pair(1,14)};
	EXPECT_EQ(intervalos, esperado);
}

