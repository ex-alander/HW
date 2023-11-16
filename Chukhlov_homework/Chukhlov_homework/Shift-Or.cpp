/*MADE BY SILAKOV N. AA_22_07*/
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#define WORD unsigned long int
#define WORDSIZE sizeof(WORD)
#define BITSINWORD WORDSIZE * 8
#define CHARLIMIT 127

using namespace std;

void preprocess(WORD** B, const char* p, unsigned int m)
{
    unsigned int i;
    WORD x = (1ul << m) - 1;

    //шаг 1: заполн€ем массив b от 0 до м с шагом 1 
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
    WORD a = (1ul << m) - 1;
    //z заканчивает последовательность
    WORD z = 1ul << (m - 1);

    unsigned int i;
    for (i = 0; i < n; i++)
    {
        a = (a << 1) | B[t[i]];

        //инвертируем а и если 1 находитс€ в конце последовательности то найдено совпадение
        if (~a & z) {
            printf("Pattern found at index %u\n", i - m + 1);
        }
        else if ((!(~a & z)) && (i == n-1)) {
            printf("Pattern not found\n");
    }
    }

    free(B);
}

void Silakov(string text, string pattern) {
    const char* c_text;
    const char* c_pattern;

    c_text = text.c_str();//ѕреобразуем string в const char*
    c_pattern = pattern.c_str();

    unsigned int n = strlen(c_text);//ќпредел€ем длину строки
    unsigned int m = strlen(c_pattern);//ќпредел€ем длину шаблона
    if (m > n) {
        fprintf(stderr, "Pattern must be shorter than text!\n");//ѕровер€ем введЄнные данные на корректность
    }
    else if (m > BITSINWORD) {
        fprintf(stderr, "Pattern too long!\n");
    }
    else {
        search(c_text, n, c_pattern, m);
    }
}