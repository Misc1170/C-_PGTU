#include <C:\Users\arsenii.stashkov\Documents\Политех\Лабораторные работы C++\2 семестр\Основы алгоритмизации\Лабораторная работа №11\Task2\Pair.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef queue<Pair>Qu;
typedef vector<Pair>Vec;

// Формирование очереди
Qu MakeQueue(double n) {
	Qu q;
	Pair p;
	for (int i = 0; i < n; i++) { 
		cin >> p; q.push(p); 
	}
}

// Копирование очереди в вектор
Vec CopyQueueToVector(Qu q) {
	Vec v;
	while (!q.empty()) {
		v.push_back(q.front());
		q.pop();
	}
	return v;
}

// Копирование вектора в очередь
Qu CopyQueueToVector(Vec v) {
	Qu q;
	for (int i = 0; i < v.size(); i++) { 
		q.push(v[i]); 
	}
	return q;
}

// Добавление элемента
void AddToQueue(Qu& q, Pair el) {
	Vec v;
	Pair p;
	int i = 1;
	while (!q.empty()) {
		p = q.front();
		q.push(p);
		i++;
	}
	q = CopyQueueToVector(v);
}

// Вывод очереди на экран
template <class T>
void Print() {
	vector<T> v = CopyQueueToVector(q);
	while (!q.empty()) { 
		cout << q.front; 
	}
}

// Нахождение макс. элемента
Pair Max(Qu q) {
	Pair ma = q.front();
	Vec v = CopyQueueToVector(q);
	while(!q.empty()) {
		if (q.front() > ma) { 
			ma = q.front(); 
		}
		q.pop();
	}
	q = CopyQueueToVector(v);
	return ma;
}

// Нахождение мин. элемента
Pair Min(Qu q) {
	Pair mi = q.front();
	Vec v = CopyQueueToVector(q);
	while (!q.empty()) {
		if (q.front() < mi) { 
			mi = q.front(); 
		}
		q.pop();
	}
	q = CopyQueueToVector(v);
	return mi;
}

//Нахождение суммы макс и мин. элементов
void Sum(Qu& q) {
	Pair mi = Min(q);
	Pair ma = Max(q);
	Vec v;
	Pair p;
	while (!q.empty()) {
		p = q.front();
		v.push_back(p + mi + ma);
		q.pop();
	}
	q = CopyQueueToVector(v);
}

int main()
{
	Pair p;
	Qu q;
	double n;
	cout << "n?";
	cin >> n;
	q = MakeQueue(n);
	Print<int>();
	AddToQueue(q, p);
	cout << "Sum: \n";
	Sum(q);
	Print<int>();
}