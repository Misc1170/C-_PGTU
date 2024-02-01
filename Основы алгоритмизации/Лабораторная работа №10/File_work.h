#pragma once
#include "Pair.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int MakeFile(const char* f_first) {
	fstream stream(f_first, ios::out | ios::trunc);
	if (!stream) return -1;
	cout << "\nФайл создан!\n";
	stream.close();
	return 0;
}

void PrintFile(const char* f_first) {
	string text;
	ifstream f(f_first);
	if (f.is_open()) {
		getline(f, text, '\f');
	}
	else {
		cout << "Невозможно прочитать файл!\n";
	}
	cout << text << endl;
	f.close();
}

int ClearFile(const char* f_first, int k) {
	string text = f_first;
	fstream temp("temp ", ios::out);
	fstream stream(f_first, ios::in);
	if (!stream) return -1;
	stream.close();
	temp.close();
	remove(f_first);
	rename("temp", f_first);
	cout << "\nВсе записи из файла удалены!\n";
	return 0;
}

int AddFile(const char* f_first, Pair pp) {
	fstream temp("temp", ios::out);
	fstream stream(f_first, ios::in);
	if (!stream) return -1;
	Pair p;
	int i = 0, l = 0;
	while (stream >> p) {
		if (stream.eof()) break;
		i++;
	}
	stream.close();
	temp.close();
	remove(f_first);
	rename("temp", f_first);
	return l;
}

int AddNote(const char* f_first, Pair pp) {
	fstream stream(f_first, ios::app);
	if (!stream) return -1;
	stream << pp;
	cout << "\nФайл изменен!\n";
	return 1;
}

int ChangeFile(const char* f_first, Pair pp) {
	fstream temp("temp", ios::out);
	fstream stream(f_first, ios::in);
	if (!stream) { return -1; }
	Pair p;
	int i, l;
	i = 0;
	l = 0;
	while (stream >> p) {
		if (stream.eof()) break;
		i++;
		temp << p;
	}
	stream.close();
	temp.close();
	remove(f_first);
	rename("temp", f_first);
	cout << "\nФайл изменен!\n";
	return l;
}

void HandleFile1(const char* f_first, const char* f_result, int nMoreThan) {
	ifstream streamInput(f_first);
	ofstream streamOutput(f_result);

	int a = 0;
	
	while (streamInput >> a) {
		if (a > nMoreThan) {
			string s = to_string(a);
			streamOutput << s << endl;
		}
	}

	streamInput.close();
	streamOutput.close();
}

void HandleFile2(const char* f_first, const char* f_result, int nValue, int L) {
	ifstream streamInput(f_first);
	ofstream streamOutput(f_result);

	int a = 0;

	while (streamInput >> a) {
		if (a == nValue) {
			a += L;
		}

		string s = to_string(a);
		streamOutput << s << endl;
	}

	streamInput.close();
	streamOutput.close();
}

void HandleFile3(const char* f_first, const char* f_result, int nNumber, int nCount) {
	ifstream streamInput(f_first);
	ofstream streamOutput(f_result);

	int a = 0;
	int nLine = 1;

	while (streamInput >> a) {

		string s = to_string(a);
		streamOutput << s << endl;

		if (nLine == nNumber) {
			for (int i = 0; i < nCount; i++) {
				streamOutput << i << "\n";
			}
		}
		nLine++;
	}

	streamInput.close();
	streamOutput.close();
}
