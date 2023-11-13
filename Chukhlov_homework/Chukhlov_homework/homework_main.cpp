#include <iostream>
#include <chrono>
#include <thread>
#include "Main Functions.h"
#include <Windows.h>
#define __STDC_WANT_LIB_EXT1__ 1
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
using namespace std;
int main()
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    string text = "What we've got here is failure to communicate. Some men you just can't reach. So you get what we had here last week, which is the way he wants it. Well, he gets it. And I don't like it any more than you men";
    string search_word = "you men";
    cout << "Comparison of different search algorithms:\n\n" << flush;

    // Naive
    divide();
    SetConsoleTextAttribute(hConsole, 15);
    cout << rectangle("Naive") << endl;
    SetConsoleTextAttribute(hConsole, 15);
    auto start = chrono::high_resolution_clock::now();
    searchNaive(text, search_word);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = end - start;
    cout << "found in " << elapsed.count() / 1000 << " seconds"<<endl;
    divide();

    // Knuth-Morris-Pratt
    SetConsoleTextAttribute(hConsole, 14);
    cout << rectangle("Knuth-Morris-Pratt") << endl;
    SetConsoleTextAttribute(hConsole, 15);
    start = chrono::high_resolution_clock::now();
    KMPSearch(text, search_word);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "found in " << elapsed.count() / 1000 << " seconds" << endl;
    divide();

    // Boyer Moore
    SetConsoleTextAttribute(hConsole, 12);
    cout << rectangle("Boyer-Moore") << endl;
    SetConsoleTextAttribute(hConsole, 15);
    start = chrono::high_resolution_clock::now();
    searchBoyerMoore(text, search_word);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "found in " << elapsed.count() / 1000 << " seconds" << endl;
    divide();

    // Rabin Karp
    SetConsoleTextAttribute(hConsole, 3);
    cout << rectangle("Rabin-Karp") << endl;
    SetConsoleTextAttribute(hConsole, 15);
    start = chrono::high_resolution_clock::now();
    searchRabinKarp(text, search_word);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "found in " << elapsed.count() / 1000 << " seconds" << endl;
    divide();

    // Shift-Or
    SetConsoleTextAttribute(hConsole, 10);
    cout << rectangle("Shift-Or") << endl;
    SetConsoleTextAttribute(hConsole, 15);
    start = chrono::high_resolution_clock::now();
    searchShiftOr(text, search_word);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "found in " << elapsed.count() / 1000 << " seconds" << endl;
    divide();
}
