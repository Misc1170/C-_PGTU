#include "Listing.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	int i;
	// Обработка исключительных ситуаций
	try {
		cout << "Пустой список из двух элементов: \n";
		// Список с 2 элементами
		Listing x(2);
		// Пустой список
		Listing y;
		cout << x << "\nВведите номер элемента: \n";
		cin >> i;
		cout << "\nВывод элемента под номером " << i << ":\n";
		cout << x[i] << endl;
		y = x * 1;
		cout << y;
	}
	catch(int) { 
		cout << "Ошибка!\n"; 
	}

	return 0;
}
