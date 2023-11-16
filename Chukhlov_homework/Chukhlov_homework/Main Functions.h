#pragma once
#define WORD unsigned long int
#define WORDSIZE sizeof(WORD)
#define BITSINWORD WORDSIZE * 8
#define CHARLIMIT 127
#include <vector>
#include <string>
using namespace std;
void divide();
string rectangle(const string x);
void preprocess(WORD** B, const char* p, unsigned int m);
void search(const char* t, unsigned int n, const char* p, unsigned int m);
void Silakov(string text, string pattern);
void rabinKarp(const string& text, const string& pattern);
void ArrayLPS(const string& pat, vector<int>& lps);
void KMPSearch(const string& tex, const string& pat);
void searchNaive(string txt, string pat);
int BogviewChard(int j, char temp, string str);
int BW(string source, string target);