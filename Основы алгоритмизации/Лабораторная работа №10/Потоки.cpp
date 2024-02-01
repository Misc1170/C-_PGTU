#include "Pair.h"
#include <iostream>
#include <fstream>
#include <string>
#include "File_work.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	Pair p, p1, p2;
	int k, c, num1, num2;
	char fileName[30];
	do {
		cout << "\n1. Создать файл"
			"\n2. Вывести файл в консоль"
			"\n3. Очистить файл"
			"\n4. Изменить запись в файле"
			"\n5. Добавить запись в файл"
			"\n0. Выйти\n\n"
			"\n6. Удалить все записи меньше заданного значения"
			"\n7. Увеличить все записи с заданным значением на число L"
			"\n8. Добавить K записей после элемента с заданным номером\n\n";
		cin >> c;
		switch (c) {
			case 1:
				cout << "\nНаименование файла (без пробелов, через .txt) ";
				cin >> fileName;
				k = MakeFile(fileName);
				if (k < 0) { 
					cout << "Невозможно создать файл!"; 
				}
				break;
			case 2:
				cout << "\nНаименование файла (без пробелов, через .txt) ";
				cin >> fileName;
				PrintFile(fileName);
				break;
			case 3:
				cout << "\nНаименование файла (без пробелов, через .txt) ";
				cin >> fileName;
				k = ClearFile(fileName, 0);
				if (k < 0) { 
					cout << "Невозможно прочитать файл!"; 
				}
				break;
			case 4:
				cout << "\nНаименование файла (без пробелов, через .txt) ";
				cin >> fileName;
				cin >> p1;
				k = AddFile(fileName, p1);
				if (k < 0) { 
					cout << "\nНевозможно прочитать файл!"; 
				}
				k = AddNote(fileName, p1);
				break;
			case 5:
				cout << "\nНаименование файла (без пробелов, через .txt) ";
				cin >> fileName;
				cin >> p2;
				k = AddNote(fileName, p2);
				if (k < 0) { 
					cout << "\nНевозможно прочитать файл!"; 
				}
				break;
			case 6:
				cout << "\nНаименование файла (без пробелов, через .txt) ";
				cin >> fileName;
				cout << "Укажите значение: ";
				cin >> num1;
				HandleFile1(fileName, "result1.txt", num1);
				break;
			case 7:
				cout << "\nНаименование файла (без пробелов, через .txt) ";
				cin >> fileName;
				cout << "Укажите значение и число, на которое увеличить: ";
				cin >> num1 >> num2;
				HandleFile2(fileName, "result1.txt", num1, num2);
				break;
			case 8:
				cout << "\nНаименование файла (без пробелов, через .txt) ";
				cin >> fileName;
				cout << "Укажите номер элемента и сколько строк добавить: ";
				cin >> num1 >> num2;
				HandleFile3(fileName, "result1.txt", num1, num2);
				break;
		}
	} while (c != 0 && c <= 0);

	return 0;
}
