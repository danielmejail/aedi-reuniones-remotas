#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(filtradoMediana, senialDesordenada) {
    int prof = 16;
    int freq = 10;
    int r = 2;

    senial s = {54, 23, -65, -102, 34, 71, -35, 77, 13, -46};

    filtradoMediana(s, r, prof, freq);
    senial esperada = {54, 23, 23, 23, -35, 34, 34, 13, 13, -46};

    EXPECT_EQ(esperada, s);
}

TEST(filtradoMediana, segnalConBordesPesados) {
    int prof = 16;
    int freq = 10;
    int r = 2;

    senial s = {254, 123, -65, -102, 34, 71, -35, 77, 113, -146};

    filtradoMediana(s, r, prof, freq);
    senial esperada = {254, 123, 34, 34, -35, 34, 71, 71, 113, -146};

    EXPECT_EQ(esperada, s);
}

TEST(filtradoMediana, senialConPicosYVallesCentrales) {
    int prof = 16;
    int freq = 10;
    int r = 2;

    senial s = {54, 23, -65, -102, 334, -171, -35, 77, 13, -46};

    filtradoMediana(s, r, prof, freq);
    senial esperada = {54, 23, 23, -65, -65, -35, 13, -35, 13, -46};

    EXPECT_EQ(esperada, s);
}

