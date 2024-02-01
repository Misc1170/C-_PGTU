#include <C:\Users\arsenii.stashkov\Documents\Политех\Лабораторные работы C++\2 семестр\Основы алгоритмизации\Лабораторная работа №11\Task2\Pair.h>
#include <iostream>
#include <queue>
#include <vector>
#include "Listing.h"

int main()
{
	setlocale(LC_ALL, "RUS");

	Listing<Pair>l(3);
	l.Print();
	Pair p = l.Average();
	cout << "\nСреднее значение: " << p << endl;
	cout << "Добавляем среднее значение:" << endl;
	l.Add(p);
	l.Print();
	l.Sum();
	l.Print();
}
