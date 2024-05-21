#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Pair {
	int first;
	double second;
public:
	Pair();
	Pair(int, double);
	Pair(const Pair&);
	Pair operator = (const Pair&);
	friend ostream& operator << (ostream& out, const Pair& p);
	friend istream& operator >> (istream& in, Pair& p);
	friend fstream& operator >> (fstream& fin, Pair& p);
	friend fstream& operator << (fstream& fout, const Pair& p);
	~Pair();
};
