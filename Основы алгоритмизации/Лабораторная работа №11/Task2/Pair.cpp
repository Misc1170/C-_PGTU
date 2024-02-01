#include "Pair.h"

// ���������� �������� ������������
Pair& Pair::operator = (const Pair& p) {
	if (&p == this) { 
		return *this; 
	}
	first = p.first;
	second = p.second;
	return *this;
}

// ���������� ���������� �������-�������� �����
istream& operator >> (istream& in, Pair& p) {
	cout << "������� ������ ����� (int): ";
	in >> p.first;
	cout << "������� ������ ����� (double): ";
	in >> p.second;
	return in;
}

// ���������� ���������� �������-�������� ������
ostream& operator << (ostream& out, const Pair& p) {
	return (out << p.first << " : " << p.second);
}

bool Pair::operator < (const Pair& p) {
	if (first < p.first) return true; 
	if (first == p.first && second < p.second) return true;
	return false;
}

bool Pair::operator > (const Pair& p) {
	if (first > p.first) return true;
	if (first == p.first && second > p.second) return true;
	return false;
}

// ���������� ��������� ��� �����
Pair Pair::operator-(const Pair& t) {
	int temp = first;
	int temp2 = t.first;
	double tempDouble = second;
	double tempDouble2 = t.second;
	Pair p;
	p.first = temp - temp2;
	p.second = tempDouble - tempDouble2;
	return p;
}

// ���������� �������� ��� �����
Pair Pair::operator+(const Pair& t) {
	int temp = first;
	int temp2 = t.first;
	double tempDouble = second;
	double tempDouble2 = t.second;
	Pair p;
	p.first = temp + temp2;
	p.second = tempDouble + tempDouble2;
	return p;
}

// ���������� ������� ��� �����
Pair Pair::operator/(const Pair& t) {
	int temp = first;
	int temp2 = t.first;
	double tempDouble = second;
	double tempDouble2 = t.second;
	Pair p;
	p.first = temp / temp2;
	p.second = tempDouble / tempDouble2;
	return p;
}

// ���������� �������� ���������� ��������� � ����
Pair Pair::operator*(const Pair& a) {
	const double number = 10.5;
	int temp = first;
	double temp2 = second;
	Pair p;
	if ((int)number == number) {
		p.first = temp + number;
		p.second = temp2;
	}
	else {
		p.second = temp2 + number;
		p.first = temp;
	}
	return p;
}

bool Pair::operator==(const Pair& a) {
	if (first == a.first && second == a.second) return true;
	return false;
}

// ���������� ��������� ��������������
/*Pair Pair::operator[](const Pair& t) {
	Pair* p;
	p->first = 0;
	p->second = 0;
	return p[10];
}*/
