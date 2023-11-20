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
    int p = 0; // ��� �������� ��� pattern
    int t = 0; // ��� �������� ��� text
    int h = 1;

    
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // ��������� ��� �������� ��� �������� � ������� ���� ������
    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // �������� �� ������ � �����, ������� ����������
    for (i = 0; i <= n - m; i++) {
        // ���� ��� �������� ���������, ��������� ������ ������ ���� �� ������
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            // ���� ��� ������� �������, �� ������� ������
            if (j == m)
            {
                std::cout << "Pattern found at index " << i << std::endl;
            }
        }
        // ��������� ��� �������� ��� ���������� ���� ������
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // ����� ���������� ������������� �������� t, � ����� ������ �������� ��� � ��������������
            if (t < 0)
                t += q;

        }
    }

    if (j!=m) std::cout << "Pattern not found " << std::endl;
}
