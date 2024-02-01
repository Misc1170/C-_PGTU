#pragma once
#include <vector>
#include <iostream>
using namespace std;

template <class T>
class Listing {
	vector <T> l;
	int len;
public:
	Listing(void);
	Listing(double n);
	void Print();
	~Listing(void);
	T Average();
	void Add(T el);
	double Min();
	double Max();
	void Sum();
};

// ����������� ��� ���������
template <class T>
Listing<T>::Listing() { len = 0; }

// ����������
template <class T>
Listing<T>::~Listing(void) {}

// ����������� � ����������
template <class T>
Listing<T>::Listing(double n) {
	T a;
	for (int i = 0; i < n; i++)
		{ cin >> a; l.push_back(a); }
	len = l.size();
}

// ����� ������ �� �����
template <class T>
void Listing<T>::Print() {
	for (int i = 0; i < l.size(); i++)
		{ cout << l[i] << " "; }
	cout << endl;
}

// ������� ��������������
template <class T>
T Listing<T>::Average() {
	T s = l[0];
	for (int i = 1; i < l.size(); i++)
		{ s = s + l[i]; }
	int n = l.size();
	return s / n;
}

// ���������� �������� � �����
template <class T>
void Listing<T>::Add(T el) {
	int pos = l.size();
	l.insert(l.begin(), pos, el);
}
// ����� ������������ ��������
template <class T>
double Listing<T>::Min() {
	T mi = l[0];
	double n = 0;
	for (int i = 1; i < l.size(); i++) {
		if (l[i] < mi) { mi = l[i]; n = i; }
		return n;
	}
}

// ����� ������������� ��������
template <class T>
double Listing<T>::Max() {
	T ma = l[0];
	double n = 0;
	for (int i = 1; i < l.size(); i++) {
		if (l[i] > ma) { ma = l[i]; n = i; }
		return n;
	}
}

// ��������� � ������� �������� ����� ����. � ���. ���������
template <class T>
void Listing<T>::Sum() {
	double mi = Min();
	T min = l[mi];
	double ma = Max();
	T max = l[ma];
	for (int i = 0; i < l.size(); i++)
		{ l[i] = l[i] + (l[mi] + l[ma]); }
}