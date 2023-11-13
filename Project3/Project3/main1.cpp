#include<iostream>
#include<string>
using namespace std;

// Функция для вычисления хеш-значения строки
int calculateHashValue(string str, int q, int d)
{
    int hash = 0;
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        hash = (d * hash + str[i]) % q;
    }
    return hash;
}

// Функция для проверки совпадения подстроки со строкой
bool checkMatch(string str, string pattern, int q, int d)
{
    int n = str.length();
    int m = pattern.length();
    int patternHash = calculateHashValue(pattern, q, d);
    int strHash = calculateHashValue(str.substr(0, m), q, d);

    for (int i = 0; i <= n - m; i++)
    {
        if (patternHash == strHash)
        {
            bool flag = true;
            for (int j = 0; j < m; j++)
            {
                if (pattern[j] != str[i + j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return true;
        }

        if (i < n - m)
        {
            strHash = (int)(d * (strHash - str[i] * pow(d, m - 1)) + str[i + m]) % q;
            if (strHash < 0)
                strHash += q;
        }
    }
    return false;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    string str = "ABABDABACDABABCABAB";
    string pattern = "DAB";
    int q = 101; // Простое число для деления
    int d = 256; // Основание для вычисления хеш-значения
    if (checkMatch(str, pattern, q, d))
        cout << "Подстрока найдена.";
    else
        cout << "Подстрока не найдена.";
    return 0;
}
