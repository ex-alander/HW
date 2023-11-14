/*MADE BY KALMUK A. AA_22_07*/
#include <iostream>
#include <vector>
using namespace std;

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
// Knuth-Morris-Pratt algo
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
