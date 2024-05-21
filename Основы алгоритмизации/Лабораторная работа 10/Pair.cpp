#include "Pair.h"

Pair::Pair() { first = 0; second = 0; }
Pair::~Pair() {}
Pair::Pair(int F, double S) { first = F; second = S; }
Pair::Pair (const Pair& p) { first = p.first; second = p.second; }

Pair Pair::operator = (const Pair& p) {
	if (&p == this) { return *this; }
	first = p.first;
	second = p.second;
	return *this;
}

ostream& operator << (ostream& out, const Pair& p) {
	out << "Первое число (int): " << p.first << " Второе число (double): " << p.second << "\n";
	return out;
}

istream& operator >> (istream& in, Pair& p) {
	cout << "Введите первое число (int): ";
	in >> p.first;
	cout << "Введите второе число (double): ";
	in >> p.second;
	return in;
}

fstream& operator >> (fstream& fin, Pair& p) {
	fin >> p.first;
	fin >> p.second;
	return fin;
}

fstream& operator << (fstream& fout, const Pair& p) {
	fout << p.first << "\n" << p.second << "\n";
	return fout;
}