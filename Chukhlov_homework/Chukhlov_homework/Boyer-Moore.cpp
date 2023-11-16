/*MADE BY RUDNITSKIY B. AA_22_07*/
#include <iostream>
#include <vector>
using namespace std;

// Boyer-Moore algo
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
// получаем рассто€ние перемещени€ правила плохого символа
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
void BW(string source, string target)
{
    bool foundcheck = false;
    int i = 0, j = 0, soulen = source.length(), tarlen = target.length(); // инициализаци€
    int badvalue = 0, distance = 0;
    if (soulen < tarlen) {// сравниваю длину
        printf("ƒлина строки меньше длины поискового запроса \n");
    }

    i = tarlen - 1; j = tarlen - 1; // совпадение с конца

    while (i < soulen) {
        if (source[i] == target[j]) {// совпадение символов успешно
            if (j == 0) {
                //printf("”спешное совпадение \n");
                cout << "Pattern found at index " << i << endl;
                foundcheck = true;
            }

            i--; j--;
        }
        else {// не найдено 
            if (j == tarlen - 1) {// если последний символ не соответствует успешно, "правило плохого символа"
                badvalue = BogviewChard(j, source[i], target);
                //cout << "ѕлохое движение символа:" << badvalue << endl;
                i = i + tarlen - 1 - j + badvalue;
                j = tarlen - 1;
            }
            else {// имеет суффикс, сравните "правила плохих символов" и "правила суффиксов"
                badvalue = BogviewChard(j, source[i], target);
                if (badvalue == -1)
                    badvalue = target.length();
                distance = badvalue > GoodSuffix(j, target) ? badvalue : GoodSuffix(j, target);
                //cout << "’ороший суффикс:" << GoodSuffix(j, target) << "\nѕлохой символ:" << badvalue << "\nѕереместить после сравнени€:" << distance << endl;
                i = i + tarlen - 1 - j + distance; // обновл€ю позицию i
                j = tarlen - 1; // обновл€ю позицию j

            }
        }
    }
    if (!foundcheck) cout << "Pattern not found" << endl;
}