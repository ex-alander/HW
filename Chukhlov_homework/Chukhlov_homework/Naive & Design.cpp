/*MADE BY CHUKHLOV A. AA_22_07*/
#include <iostream>
#include <vector>
using namespace std;

// design stuff
void divide()
{
    cout << "------------------------------------\n";
}
string rectangle(const string x) // to make this nice little rectangle around the function
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
    bool foundcheck = false; // switch for checking if anything even was found or not
    int n = txt.size();
    int m = pat.size();

    for (int i = 0; i <= n - m; i++) { // we walk through the text
        int j;
        for (j = 0; j < m; j++) { // if we find a match, we keep checking if it keeps matching
            if (txt[i + j] != pat[j]) {
                break; // matching stopped -> move forward
            }
        }
        if (j == m) { // if the index matches the length of input pattern, it means we won
            cout << "Pattern found at index " << i << endl; // print where pattern was found
            foundcheck = true; // we don't wanna print error if we found the pattern
        }
    }
    if (!foundcheck) cout << "Pattern not found" << endl; 
}
