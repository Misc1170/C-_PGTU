// Пишем файл с прототипами функций
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

// Прототипы функций
void DataInitialization();
void DataEntry();
void DataReading(string fileName);
void Print();
bool DataCleaning();
//void DataChange();
void Copy();
int AmountOfData();
//void DeleteData();
//void SaveData(string fileName);
