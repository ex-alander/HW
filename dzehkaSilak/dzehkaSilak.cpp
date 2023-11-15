﻿#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shift-or.h"
#include <iostream>

using namespace std;

void preprocess(WORD** B, const char* p, unsigned int m)
{
    unsigned int i;
    WORD x = (1ul << m) - 1;

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
    WORD a = (1ul << m) - 1;
    //z заканчивает последовательность
    WORD z = 1ul << (m - 1);

    unsigned int i;
    for (i = 0; i < n; i++)
    {
        a = (a << 1) | B[t[i]];

        //инвертируем а и если 1 находится в конце последовательности то найдено совпадение
        if (~a & z) {
            printf("Pattern found at position %u\n", i - m + 1);
        }
        else if ((!(~a & z)) && (i == n)) {
            printf("Pattern not found");
        }
    }

    free(B);
}

void Silakov(string text, string pattern) {
    const char* c_text;
    const char* c_pattern;

    c_text = text.c_str();//Преобразуем string в const char*
    c_pattern = pattern.c_str();

    unsigned int n = strlen(c_text);//Определяем длину строки
    unsigned int m = strlen(c_pattern);//Определяем длину шаблона
    if (m > n) {
        fprintf(stderr, "Pattern must be shorter than text!\n");//Проверяем введённые данные на корректность
    }
    else if (m > BITSINWORD) {
        fprintf(stderr, "Pattern too long!\n");
    }
    else {
        search(c_text, n, c_pattern, m);
    }
}

int main()
{
    string text;
    string pattern;

    text = "Hello, my name is Nikita";
    pattern = "my";

    Silakov(text, pattern);

    return 0;
}