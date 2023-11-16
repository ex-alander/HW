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
// �������� ���������� ����������� ������� ������� �������
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
    int i = 0, j = 0, soulen = source.length(), tarlen = target.length(); // �������������
    int badvalue = 0, distance = 0;
    if (soulen < tarlen) {// ��������� �����
        printf("����� ������ ������ ����� ���������� ������� \n");
    }

    i = tarlen - 1; j = tarlen - 1; // ���������� � �����

    while (i < soulen) {
        if (source[i] == target[j]) {// ���������� �������� �������
            if (j == 0) {
                //printf("�������� ���������� \n");
                cout << "Pattern found at index " << i << endl;
                foundcheck = true;
            }

            i--; j--;
        }
        else {// �� ������� 
            if (j == tarlen - 1) {// ���� ��������� ������ �� ������������� �������, "������� ������� �������"
                badvalue = BogviewChard(j, source[i], target);
                //cout << "������ �������� �������:" << badvalue << endl;
                i = i + tarlen - 1 - j + badvalue;
                j = tarlen - 1;
            }
            else {// ����� �������, �������� "������� ������ ��������" � "������� ���������"
                badvalue = BogviewChard(j, source[i], target);
                if (badvalue == -1)
                    badvalue = target.length();
                distance = badvalue > GoodSuffix(j, target) ? badvalue : GoodSuffix(j, target);
                //cout << "������� �������:" << GoodSuffix(j, target) << "\n������ ������:" << badvalue << "\n����������� ����� ���������:" << distance << endl;
                i = i + tarlen - 1 - j + distance; // �������� ������� i
                j = tarlen - 1; // �������� ������� j

            }
        }
    }
    if (!foundcheck) cout << "Pattern not found" << endl;
}