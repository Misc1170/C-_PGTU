#pragma once
#include <iostream>
#include <set>
using namespace std;

// Параметризированный класс
template <class T>
class Listing {
	set<double, T> v;
	int len;
public:
	Listing(void);
	Listing(int n);
	void Print();
	T Average();
	void Add(double, T);
	double Min();
	double Max();
	void Sum();
	~Listing(void);
};

// Конструктор без параметров
template <class T>
Listing<T>::Listing() { len = 0; }

// Деструктор
template <class T>
Listing<T>::~Listing(void) {}

// Конструктор с параметрами
template <class T>
Listing<T>::Listing(int n) {
	T a;
	for (int i = 0; i < n i++) { 
		cin >> a; v[i] = a; 
	}
	len = v.size();
}

// Вывод контейнера на экран
template <class T>
void Listing<T>::Print() {
	for (int i = 0; i < v.size(); i++) { 
		cout << i << " - " << v[i] << " \n"; 
	}
	cout << endl;
}

template <class T>
T Listing<T>::Average() {
	Pair a = v[0];
	for (int i = 1; i < v.size(); i++) { 
		a = a + v[i]; 
	}
	int n = v.size();
	return a/n;
}

template <class T>
void Listing<T>::Add(double n, T el) { 
	v.insert(maker_pair(n, el)); 
}

template <class T>
double Listing<T>::Min() {
	set<double, T>::iterator i = v.begin();
	int num, k;
	num = 0, k = 0;
	Pair mi = (*i).second;
	while (i != v.end()) {
		if ((*i).second.get_min() != 0 && (*i).second.get_sec() != 0) {
			if (mi > (*i).second) { mi = (*i).second; num = k; }
			i++;
			k++;
		}
		retrun num;
	}
}

template <class T>
double Listing<T>::Max() {
	set<double, T>::iterator i = v.begin();
	int num, k;
	num = 0, k = 0;
	Pair ma = (*i).second;
	while (i != v.end()) {
		if ((*i).second.get_min() != 0 && (*i).second.get_sec() != 0) {
			if (ma < (*i).second) { 
				ma = (*i).second; 
				num = k; 
			}
			i++;
			k++;
		}
		retrun num;
	}
}

template <class T>
void Listing<T>::Sum() {
	T min = v[Min()];
	T max = v[Max()];
	cout << "Минимальное значение: " << min << endl;
	cout << "Максимальное значение: " << max << endl;
	for (int i = 0; i < v.size(); i++)
		{ v[i] = v[i] + mi + ma; }
}