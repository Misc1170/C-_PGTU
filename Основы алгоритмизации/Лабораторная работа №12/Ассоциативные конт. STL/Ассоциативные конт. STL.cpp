#include <iostream>
#include <set>
using namespace std;

// Определяем тип для работы контейнера
typedef set<double> TSet;
// Итератор
typedef TSet::iterator it;

// Формирование контейнера
TSet MakeSet(int n) {
	// Пустой контейнер
	TSet v;
	double a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		// Добавляем значение в контейнер
		v.insert(a);
	}
	cout << "\n";
	//cin.get();
	return v;
}

// Вывод контейнера на экран
void PrintSet(TSet v) {
	it p;
	int i;
	for (p = v.begin(), i = 0; p != v.end(); ++p, ++i) { 
		cout << i << " : " << *p << " \n"; 
	}
}

// Добавляем среднее арифметическое в контейнер
TSet Average(TSet v) {
	it p;
	double sum = 0;
	int i;
	for (p = v.begin(), i = 0; p != v.end(); ++p, ++i) {
		sum += *p;
	}
	int size = v.size();
	double avg = sum / size;
	cout << "\nВысчитываем среднее арифметическое и добавляем в контейнер: " << avg << "\n";
	v.insert(avg);

	return v;
}

// Удаление элементов в заданном диапазоне (10-50)
TSet DeleteRange(TSet v) {
	for (auto i = v.begin(); i != v.end(); ) {
		if (*i >= 10 && *i <= 50) {
			i = v.erase(i);
		}
		else {
			++i;
		}
	}
	return v;
}

// Сумма каждого элемента с мин. и макс. значениями
TSet Sum(TSet v) {
	TSet newSet;
	double min = *v.begin();
	double max = NULL;
	for (auto i = v.begin(); i != v.end(); i++) {
		if (max == NULL || max < *i) {
			max = *i;
		}
	}
	double value;

	for (auto i = v.begin(); i != v.end(); ) {
		value = *i;
		i = v.erase(i);
		newSet.insert(value + min + max);
	}
	return newSet;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	TSet s;
	int n;
	cout << "Введите кол-во значений контейнера: ";
	cin >> n;
	cout << "\n";
	//cin.get();
	cout << "Введите значения (double):\n";
	s = MakeSet(n);
	cout << "Наш контейнер:\n";
	PrintSet(s);
	//cin.get();
	//s.insert();
	s = Average(s);
	PrintSet(s);

	cout << "\nУдаляем элементы в диапазоне 10-50:\n";
	s = DeleteRange(s);
	PrintSet(s);

	cout << "\nДобавляем к каждому элементу сумму макс. и мин. значений:\n";
	s = Sum(s);
	PrintSet(s);

	return 0;
}