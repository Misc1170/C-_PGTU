#include <iostream>
#include <list>
#include <cstdlib>
#include "Pair.h"
using namespace std;

typedef list<double>Listing;
Listing MakeVector(double n) {
	Listing l;
	for (int i = 0; i < n; i++) 
		{ int a = rand() % 100 - 50; l.push_back(a); }
	return l;
}

void PrintVector(Listing l) {
	for (auto i = l.begin(); i != l.end(); ++i) { 
		cout << *i << " "; 
	}
	cout << endl;
}

double Average(Listing l) {
	double a = 0;
	for (auto i = l.begin(); i != l.end(); ++i) {
		a += *i; 
	}
	int n = l.size();
	return a / n;
}

void AddValue(Listing& l, double el) {
	l.push_back(Average(l));
}

int Min(Listing l) {
	int min = NULL;
	for (auto i = l.begin(); i != l.end(); ++i) {
		if (min > * i || min == NULL) {
			min = *i;
		}
	}
	return min;
}

int Max(Listing l) {
	int max = NULL;
	for (auto i = l.begin(); i != l.end(); ++i) {
		if (max < *i || max == NULL) {
			max = *i;
		}
	}
	return max;
}

void Sum(Listing& l) {
	double min = Min(l);
	double max = Max(l);
	for (auto i = l.begin(); i != l.end(); ++i)
	{
		*i = *i + min + max;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	try {
		list<double> l;
		list<double>::iterator vi = l.begin();
		int n;
		cout << "Введите длину списка: ";
		cin >> n;
		l = MakeVector(n);
		PrintVector(l);
		double el = Average(l);
		AddValue(l, el);
		PrintVector(l);
	}
	catch (int) {
		cout << "Ошибка!\n";
	}
}

