#include <iostream>
#include <fstream>
#include <string>
#include "Cpp.cpp"
#include "C.cpp"
#pragma warning(disable : 4996)
using namespace std;

// Функция С++
int FirstStyle(string path)
{
	Handle1 handle1;
	
	// Создаем файл
	ofstream FileCar(path);

	string car1 = "Chevrolet\n2010\n1000000\nblack\n\n";
	string car2 = "BMW\n2001\n1500000\ngray\n\n";
	string car3 = "Mercedes-Benz\n1996\n1200000\nblack\n\n";

	FileCar << car1 << car2 << car3;
	FileCar.close();
	cout << "C++ style:\n\n";
	handle1.PrintFile1(path);

	// Добавляем в файл строчку
	string car4 = "Peugeot\n2008\n500000\nblue\n";
	handle1.AddString1(path, car4);
	cout << "--------------------\n\n";
	handle1.PrintFile1(path);

	// Удаляем элементы, у которых год выпуска меньше 2000
	//handle1.DeleteLessNotes1(path, 2000);
	//cout << "--------------------\n\n";
	//handle1.PrintFile1(path);

	return 0;
}

// Функция С
int SecondStyle(string path)
{
	Handle2 handle2;

	FILE* FileCar;
	FileCar = fopen("car (C).txt", "w");

	if (FileCar == NULL) {
		printf("Ошибка открытия файла!\n");
	}

	fprintf(FileCar, "Chevrolet 2010 1000000 black\n");
	fprintf(FileCar, "BMW 2001 1500000 gray\n");
	fprintf(FileCar, "Mercedes-Benz 1996 1200000 black\n");

	fclose(FileCar);

	printf("C style:\n\n");
	handle2.PrintFile2(3);
	printf("--------------------\n\n");

	// Добавляем в файл строчку
	FILE* out;
	out = fopen("car (C).txt", "a");

	fprintf(out, "Peugeot 2008 500000 blue\n");

	fclose(out);

	// Выводим файл в консоль 2-й раз (измененный)
	char line2[255];
	FILE* fin2;
	fin2 = fopen("car (C).txt", "r");

	handle2.PrintFile2(4);

	fclose(fin2);

	return 0;
}

int main()
{
	FirstStyle("car (C++).txt");
	SecondStyle("car (C).txt");

	return 0;
}