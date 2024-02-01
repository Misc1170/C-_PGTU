#include <iostream>
#include <list>
#include <cstdlib>
using namespace std;

// Определение типа работы со списком
typedef list<double>Listing;
// Формирование списка
Listing MakeList(double n) {
	Listing l;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		// Добавляем а в конец списка
		l.push_back(a);
	}
	return l;
}

// Вывод списка на экран
void PrintList(Listing l) {
	for (auto i = l.begin(); i != l.end(); ++i) {
		cout << *i << "\t";
	}
	cout << endl;
}

// Нахождение среднего значения и добавление в конец списка
Listing AddAverageValue(Listing l) {
	double sum = 0;
	for (auto i = l.begin(); i != l.end(); ++i) {
		sum += *i;
	}
	int size = l.size();
	l.push_back(sum/size);
	return l;
}

// Удаление элементов в диапазоне (10-50)
Listing DeleteRange(Listing l) {
	auto i = l.begin();
	while (i != l.end()) {
		double value = *i;

		if ((value >= 10) && (value <= 50)) {
			l.erase(i++);
		}
		else {
			++i;
		}
	}

	return l;
}

// Поиск минимального элемента
double Min(Listing l) {
	double min = NULL;
	for (auto i = l.begin(); i != l.end(); ++i) {
		if (min > *i || min == NULL) {
			min = *i; 
		}
	}
	return min;
}

// Поиск максимального элемента
double Max(Listing l) {
	double max = NULL;
	for (auto i = l.begin(); i != l.end(); ++i) {
		if (max < *i || max == NULL) {
			max = *i;
		}
	}
	return max;
}

// Сложение каждого элемента с суммой мин. и макс. значений
Listing Sum(Listing l) {
	double min = Min(l);
	double max = Max(l);
	for (auto i = l.begin(); i != l.end(); ++i) {
		*i = *i + min + max;
	}
	return l;
};

int main()
{
	setlocale(LC_ALL, "Rus");

	try {
		list<double> l;
		list<double>::iterator vi = l.begin();

		double n;
		cout << "Введите длину списка: ";
		cin >> n;
		l = MakeList(n);
		cout << "\nНаш список:\n";
		PrintList(l);

		l = AddAverageValue(l);
		cout << "\nНаш список после добавления среднего арифметического в конец:\n";
		PrintList(l);

		l = DeleteRange(l);
		cout << "\nНаш список после удаления чисел в диапазоне (10-50):\n";
		PrintList(l);

		l = Sum(l);
		cout << "\nНаш список после прибавления к каждому элементу суммы макс. и мин. значений:\n";
		PrintList(l);
	}
	catch (int) {
		cout << "Ошибка!\n";
	}
}
