/*MADE BY ZAKHAROV M. AA_22_07*/
#include <iostream>
#include <vector>
using namespace std;

// for Rabin-Karp

#define d 256
#define q 101

// Rabin-Karp algo
void rabinKarp(const std::string& text, const std::string& pattern) {
    int m = pattern.length();
    int n = text.length();
    int i, j{};
    int p = 0; // Хэш значение для pattern
    int t = 0; // Хэш значение для text
    int h = 1;

    
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Вычисляем хэш значения для паттерна и первого окна текста
    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Проходим по тексту с окном, которое сдвигается
    for (i = 0; i <= n - m; i++) {
        // Если хэш значения совпадают, проверяем каждый символ один за другим
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            // Если все символы совпали, то паттерн найден
            if (j == m)
            {
                std::cout << "Pattern found at index " << i << std::endl;
            }
        }
        // Вычисляем хэш значения для следующего окна текста
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // Может получиться отрицательное значение t, в таком случае приводим его к положительному
            if (t < 0)
                t += q;

        }
    }

    if (j!=m) std::cout << "Pattern not found " << std::endl;
}
