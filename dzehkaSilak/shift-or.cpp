#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "shift-or.h"

void preprocess(WORD** B, const char* p, unsigned int m)
{
    unsigned int i;
    WORD x = (1ul << m) - 1; //11111111

    //шаг 1: заполняем массив b от 0 до м с шагом 1 
    for (i = 0; i < CHARLIMIT; i++) {
        (*B)[i] = x;
    }

    //шаг 2: отмечаем позиции в матрице совпадающие с шаблоном
    for (i = 0; i < m; i++) {
        (*B)[p[i]] = (1ul << i) ^ (*B)[p[i]];
    }
}

void search(const char* t, unsigned int n, const char* p, unsigned int m)
{
    WORD* B;
    B = (WORD*)malloc(CHARLIMIT * WORDSIZE);

    preprocess(&B, p, m);

    //а начинает последовательность
    WORD a = (1ul << m) - 1; //11111111
    //z заканчивает последовательность
    WORD z = 1ul << (m - 1);

    unsigned int i;
    for (i = 0; i < n; i++)
    {
        a = (a << 1) | B[t[i]];

        //инвертируем а и если 1 находится в конце последовательности то найдено совпадение
        if (~a & z) {
            printf("Match found at position %u\n", i - m + 1);
        }
    }

    free(B);
}