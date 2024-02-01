#include "C:\Users\arsenii.stashkov\Documents\Политех\Лабораторные работы C++\2 семестр\Основы алгоритмизации\Лабораторная работа №11\Task2\Pair.h"
#include <list>
#include <iostream>
//#include <algorithm>
using namespace std;

typedef list <Pair> TList;

// Формируем список
TList MakeList(int n) {
	Pair a;
	TList l;
	for (int i = 0; i < n; i++) { 
		cin >> a; 
		l.push_back(a); 
	}
	return l;
}

// Выводим список на экран
void PrintList(TList l) {
	for (auto i = l.begin(); i != l.end(); ++i) {
		cout << *i << "\n";
	}
	cout << endl;
}

// Находим среднее арифметическое и добавляем в список
TList Average(TList l) {
	Pair avg;
	for (auto i = l.begin(); i != l.end(); ++i) {
		avg = avg + *i;
	}
	Pair& p = avg;
	p.set_first(p.get_first() / l.size());
	p.set_second(p.get_second() / l.size());
	l.insert(l.end(), avg);

	return l;
}

//Удаляем числа из диапазона(10 - 50)
TList DeleteRange(TList l) {
	auto i = l.begin();
	while (i != l.end()) {
		Pair value = *i;

		if ((value.get_first() >= 10) && (value.get_first() <= 50) || 
			(value.get_second() >= 10) && (value.get_second() <= 50)) {
			l.erase(i++);
		}
		else {
			++i;
		}
	}

	return l;
}

// Поиск минимального значения
Pair Min(TList l) {
	Pair min;
	Pair& p = min;
	p.set_first(0);
	p.set_second(0.0);
	
	for (auto i = l.begin(); i != l.end(); ++i) {
		if (min > *i || (p.get_first() == 0 && p.get_second() == 0.0)) { min = *i; }
	}
	return min;
}

// Поиск максимального значения
Pair Max(TList l) {
	Pair max;
	for (auto i = l.begin(); i != l.end(); ++i) {
		if (max < *i) { max = *i; }
	}
	return max;
}

// Суммируем каждый элемент с мин. и макс. значениями
TList Sum(TList l) {
	Pair min = Min(l);
	Pair max = Max(l);
	for (auto i = l.begin(); i != l.end(); ++i) {
		*i = *i + min + max;
	}
	return l;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	int n;
	cout << "Введите длину списка:\n";
	cin >> n;
	cout << "\n";
	TList l;
	l = MakeList(n);
	cout << "\nНаш список:\n";
	PrintList(l);

	cout << "Находим среднее арифметическое и добавляем в конец списка:\n";
	l = Average(l);
	PrintList(l);

	cout << "Удаляем числа из диапазона (10-50):\n";
	l = DeleteRange(l);
	PrintList(l);

	cout << "К каждому элементу добавляем сумму макс. и мин. элементов:\n";
	l = Sum(l);
	PrintList(l);

	return 0;
}
