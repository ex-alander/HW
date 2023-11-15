# include<iostream>
# include<string>
#include <clocale>

using namespace std;

// максимальная длина совпадения
# define MAX_SIZE 1000


 // получение расстояния перемещения суффиксного правила
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
// получаем расстояние перемещения правила плохого символа
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
int BW(string source, string target)
{
	int i = 0, j = 0, soulen = source.length(), tarlen = target.length(); // инициализация
	int badvalue = 0, distance = 0;
	if (soulen < tarlen) {// сравниваю длину
		printf("Длина строки меньше длины поискового запроса \n");
		return -1;
	}

	i = tarlen - 1; j = tarlen - 1; // совпадение с конца

	while (i < soulen) {
		if (source[i] == target[j]) {// совпадение символов успешно
			if (j == 0) {
				printf("Успешное совпадение \n");
				return i;
			}

			i--; j--;
		}
		else {// не найдено 
			if (j == tarlen - 1) {// если последний символ не соответствует успешно, "правило плохого символа"
				badvalue = BogviewChard(j, source[i], target);
				cout << "Плохое движение символа:" << badvalue << endl;
				i = i + tarlen - 1 - j + badvalue;
				j = tarlen - 1;
			}
			else {// имеет суффикс, сравните "правила плохих символов" и "правила суффиксов"
				badvalue = BogviewChard(j, source[i], target);
				if (badvalue == -1)
					badvalue = target.length();
				distance = badvalue > GoodSuffix(j, target) ? badvalue : GoodSuffix(j, target);
				cout << "Хороший суффикс:" << GoodSuffix(j, target) << "\nПлохой символ:" << badvalue << "\nПереместить после сравнения:" << distance << endl;
				i = i + tarlen - 1 - j + distance; // обновляю позицию i
				j = tarlen - 1; // обновляю позицию j

			}
		}
	}
}
int main()
{
	// таблица хороших суффиксов: сохраняет расстояние перемещения целевой строки вправо, когда встречается хороший суффикс.
	setlocale(LC_ALL, "Russian");
	int* goodSuffix = new int[MAX_SIZE];
	string model = "THERE SHIT IS A SIMPLE EXAMPLE";
	string str = "SHIT ";
	cout << "+-----------------------------------------+" << endl;
	cout << "Начальная позиция успешного совпадения:" << BW(model, str) + 1 << endl;
	delete[]goodSuffix;
	cout << "+-----------------------------------------+" << endl;
	return 0;
}
