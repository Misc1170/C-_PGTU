#include <C:\Users\arsenii.stashkov\Documents\Политех\Лабораторные работы C++\2 семестр\Основы алгоритмизации\Лабораторная работа №11\Task2\Pair.h>
#include "Listing.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	// Создаем список из 5 элементов
	Listing<Pair>vec(5);
	vec.Print();
	// Находим среднее арифметическое
	Pair s = vec.Average();
	cout << "Среднее значение: " << s << endl;
	vec.Add(s);
	vec.Print();
	// Находим сумму макс. и мин. элементов с каждым элементом
	vec.Sum();
	vec.Print();
}
