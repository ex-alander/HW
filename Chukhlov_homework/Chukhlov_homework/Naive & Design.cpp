/*MADE BY CHUKHLOV A. AA_22_07*/
#include <iostream>
#include <vector>
using namespace std;

// design stuff
void divide()
{
    cout << "------------------------------\n";
}
string rectangle(const string x)
{
    string rect_x;
    string horiz_line = "";
    for (int i = 0; i < x.length(); i++)
    {
        horiz_line += "-";
    }
    rect_x = "+" + horiz_line + "+" + "\n"
        + "|" + x + "|" + "\n"
        + "+" + horiz_line + "+";
    return rect_x;
}

// Naive algo
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
            cout << "Pattern found at index " << i << endl;
            foundcheck = true;
        }
    }
    if (!foundcheck) cout << "Pattern not found" << endl;
}
