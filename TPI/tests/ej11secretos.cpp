#include "gtest/gtest.h"
#include "../ejercicios.h"

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
