#include <iostream>
#include <chrono>
#include <thread>
#include "Main Functions.h"
#include <Windows.h>
#define __STDC_WANT_LIB_EXT1__ 1
using namespace std;
int main()
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const string text = "Some";
    const string search_word = "So";
    cout << "INPUT STRING (TEXT):        " << text << "\n" 
         << "STRING TO SEARCH (PATTERN): " << search_word << "\n\n";

    // check if the pattern isn't bigger than the text
    if (search_word.length() > text.length())
    {
        SetConsoleTextAttribute(hConsole, 4);
        divide();
        cout << "WRONG INPUT\n";
        divide();
        SetConsoleTextAttribute(hConsole, 15);
        return 0;
    }

    // Naive
    divide();
    SetConsoleTextAttribute(hConsole, 15);
    cout << rectangle("Naive") << endl;
    SetConsoleTextAttribute(hConsole, 15);
    auto start = chrono::high_resolution_clock::now();
    searchNaive(text, search_word);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = end - start;
    cout << "time consumption: " << elapsed.count() / 1000 << " seconds"<<endl;
    divide();

    // Knuth-Morris-Pratt
    SetConsoleTextAttribute(hConsole, 14);
    cout << rectangle("Knuth-Morris-Pratt") << endl;
    SetConsoleTextAttribute(hConsole, 15);
    start = chrono::high_resolution_clock::now();
    KMPSearch(text, search_word);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "time consumption: " << elapsed.count() / 1000 << " seconds" << endl;
    divide();

    // Boyer Moore
    SetConsoleTextAttribute(hConsole, 12);
    cout << rectangle("Boyer-Moore") << endl;
    SetConsoleTextAttribute(hConsole, 15);
    start = chrono::high_resolution_clock::now();
    cout << BW(text, search_word) << endl;
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "time consumption: " << elapsed.count() / 1000 << " seconds" << endl;
    divide();

    // Rabin Karp
    SetConsoleTextAttribute(hConsole, 3);
    cout << rectangle("Rabin-Karp") << endl;
    SetConsoleTextAttribute(hConsole, 15);
    start = chrono::high_resolution_clock::now();
    rabinKarp(text, search_word);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "time consumption: " << elapsed.count() / 1000 << " seconds" << endl;
    divide();

    // Shift-Or
    SetConsoleTextAttribute(hConsole, 10);
    cout << rectangle("Shift-Or") << endl;
    SetConsoleTextAttribute(hConsole, 15);
    start = chrono::high_resolution_clock::now();
    //searchShiftOr(text, search_word);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "time consumption: " << elapsed.count() / 1000 << " seconds" << endl;
    divide();
}
