#include <iostream>
#include <set>
#include "C:\Users\arsenii.stashkov\Documents\Политех\Лабораторные работы C++\2 семестр\Основы алгоритмизации\Лабораторная работа №11\Task2\Pair.h"
using namespace std;

typedef set<double, Pair>TSet;
typedef TSet::iterator it;

TSet MakeSet(int n) {
	TSet s;
	double a;
	for (int i = 0; i < n; i++) { 
		cin >> a; s.insert(a); 
	}
	return s;
}

void PrintSet(TSet s) {
	for (int i = 0; i < s.size(); i++) { 
		cout << i << " - " << i << " \n"; 
	}
}

Pair Average(TSet s) {
	Pair a = s[0];
	for (int i = 1; i < s.size(); i++) { 
		a += i; 
	}
	int n = s.size();
	return a/n;
}

int Min(TSet v) {
	it i = v.begin();
	int num, k;
	num = 0;
	k = 0;
	Pair s = (*i).second;
	while (i != v.end()) {
		if (s > (*i).second) { 
			s = (*i).second; num = k; 
		}
		i++;
		k++;
	}
	return num;
}

int Max(TSet v) {
	it i = v.begin();
	int num, k;
	num = 0;
	k = 0;
	Pair s = (*i).second;
	while (i != v.end()) {
		if (s < (*i).second) { s = (*i).second; num = k; }
		i++;
		k++;
	}
	return num;
}

void Sum(TSet& v) {
	Pair mi = v[Min(v)];
	Pair ma = v[Max(v)];
	for (int i = 0; i < v.size(); i++) { 
		v[i] = v[i] + v[mi] + v[ma]; 
	}
}

int main()
{
	int n;
	cout << "Введите значение n (int)" << endl;
	cin >> n;
	set<double, Pair> s = MakeSet(n);
	PrintSet(s);
	Pair el = Average(s);
	cout << "Среднее значение: " << el << endl;
	s.insert(n);
	PrintSet(s);
	Sum(s);
	PrintSet(s);
}
