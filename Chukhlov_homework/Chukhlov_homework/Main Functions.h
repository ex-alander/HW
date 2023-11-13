#pragma once
using namespace std;
void searchNaive(string txt, string pat) {
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
            cout << "Pattern occurs at shift " << i << endl;
        }
    }
}