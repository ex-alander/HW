#include <iostream>
#include <vector>
using namespace std;

#define d 256
#define q 101 // Простое число

// Алгоритм Рабина-Карпа
void rabinKarp(const std::string& text, const std::string& pattern) {
    int m = pattern.length();
    int n = text.length();
    int i, j;
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
                cout << "Patten was found on position " << i << endl;
        }
        // Вычисляем хэш значения для следующего окна текста
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // Может получиться отрицательное значение t, в таком случае приводим его к положительному
            if (t < 0)
                t += q;
        }
    }
}

// простой (наивный) поиск
void searchNaive(string txt, string pat) {
    bool foundcheck = false;
    int n = txt.size();
    int m = pat.size();

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (txt[i + j] != pat[j]) {
                break;
            }
        }
        if (j == m) {
            cout << "Pattern was found on position " << i << endl;
            foundcheck = true;
        }
    }
    if (!foundcheck) cout << "Pattern not found" << endl;
}


//Массив для хранения Длин Префиксов (Суффиксов) в подстроке
void ArrayLPS(const string& pat, vector<int>& lps) {
    int len = 0;
    int i = 1;
    lps[0] = 0;
    int R = pat.size();

    while (i < R) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
// реализация алгоритма Кнута-Морриса-Пратта (КМП)
void KMPSearch(const string& tex, const string& pat) {
    int M = pat.size(); // длинна строки
    int N = tex.size(); // длинна подстроки

    vector<int> lps(M, 0);
    ArrayLPS(pat, lps);

    int i = 0; // Индекс для текста
    int j = 0; // Индекс для образца
    bool found = false;

    while (i < N) {
        if (pat[j] == tex[i]) {
            j++;
            i++;
        }

        if (j == M) {
            found = true;
            cout << i - j << ';';
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != tex[i]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }

    if (!found) {
        cout << "no" << endl;
    }
}

int GoodSuffix(int j, string& pat) {
    int terminator = pat.length() - 1;
    int index = -1;
    j--;
    while (j >= 0) {
        if (pat[j] == pat[terminator]) {
            index = j;
            break;
        }
        else j--;
    }
    return terminator - index;
}
// получаем расстояние перемещения правила плохого символа
int BogviewChard(int j, char temp, string str)
{

    int index = -1;
    for (int i = j - 1; i >= 0; --i)
    {
        if (str[i] == temp)
        {
            index = i;
            break;
        }
    }
    return j - index;
}
int BW(string source, string target)
{
    int i = 0, j = 0, soulen = source.length(), tarlen = target.length(); // инициализация
    int badvalue = 0, distance = 0;
    if (soulen < tarlen) {// сравниваю длину
        printf("Длина строки меньше длины поискового запроса \n");
        return -1;
    }

    i = tarlen - 1; j = tarlen - 1; // совпадение с конца

    while (i < soulen) {
        if (source[i] == target[j]) {// совпадение символов успешно
            if (j == 0) {
                //printf("Успешное совпадение \n");
                return i;
            }

            i--; j--;
        }
        else {// не найдено 
            if (j == tarlen - 1) {// если последний символ не соответствует успешно, "правило плохого символа"
                badvalue = BogviewChard(j, source[i], target);
                //cout << "Плохое движение символа:" << badvalue << endl;
                i = i + tarlen - 1 - j + badvalue;
                j = tarlen - 1;
            }
            else {// имеет суффикс, сравните "правила плохих символов" и "правила суффиксов"
                badvalue = BogviewChard(j, source[i], target);
                if (badvalue == -1)
                    badvalue = target.length();
                distance = badvalue > GoodSuffix(j, target) ? badvalue : GoodSuffix(j, target);
                //cout << "Хороший суффикс:" << GoodSuffix(j, target) << "\nПлохой символ:" << badvalue << "\nПереместить после сравнения:" << distance << endl;
                i = i + tarlen - 1 - j + distance; // обновляю позицию i
                j = tarlen - 1; // обновляю позицию j

            }
        }
    }
}