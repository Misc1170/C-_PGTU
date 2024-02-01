#include "C:\Users\arsenii.stashkov\Documents\Политех\Лабораторные работы C++\2 семестр\Основы алгоритмизации\Лабораторная работа №11\Task2\Pair.h"
#include "Container.h"
#include <iostream>

int main()
{
	setlocale(LC_ALL, "Rus");

	int n;
	cout << "N?";
	cin >> n;
	Listing <Pair> v(n);
	v.Print();
	Pair p = v.Average();
	cout << "Среднее значение: " << p << endl;
	cout << "Добавляем значение 2.5" << endl;
	v.Add(2.5, p);
	v.Print();
	cout << "Сумма: \n";
	v.Sum();
	v.Print();
}
