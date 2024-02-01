#pragma once
#include <iostream>
#include <queue>
#include <vector>

template <class T>
class Listing {
	queue <T> q;
	int len;
public:
	Listing();
	Listing(int n);
	Listing(const Listing<T>&);
	void Print();
	T Average();
	void Add(T el);
	T Min();
	T Max();
	void Sum();
};

template <class T>
vector<T> copyQueueToVector(queue<T> q) {
	vector<T> v;
	while (!q.empty())
		{ v.push(q.front()); q.pop(); }
	return v;
}

template <class T>
queue<T> copyVectorToQueue(vector<T> v) {
	queue<T> q;
	for (int i = 0; i < v.size(); i++)
		{ q.push(v[i]); }
	return q;
}

template <class T>
Listing<T>::Listing() { len = 0; }

template <class T>
Listing<T>::Listing(int n) {
	T a;
	for (int i = 0; i < n; i++)
		{ cin >> a; q.push(a); }
	len = q.size();
}

template <class T>
Listing<T>::Listing(const Listing<T>& Lis) {
	len = v.len;
	vector v = copyQueueToVector(Lis.q);
	q = copyVectorToQueue(v);
}

template <class T>
void Listing<T>::Print() {
	vector<T> v = copyQueueToVector(q);
	while (!q.empty())
		{ cout << q.front }
}

template <class T>
T Listing<T>::Average() {
	vector<T> v = copyQueueToVector(q);
	int n = 1;
	T sum = q.front();
	q.pop();
	while (!q.empty())
		{ sum = sum + q.front(); q.pop(); n++; }
	q = copyVectorToQueue(v);
	return sum / n;
}

template <class T>
void Listing<T>::Add(T el) {
	vector <T>v;
	T t;
	int i = 1;
	while (!q.empty()) {
		t = q.front();
		if (i == pos) { v.push_back(el); }
		v.push_back(t);
		q.pop();
		i++;
	}
	q = copyVectorToQueue(v);
}

template <class T>
T Listing<T>::Min() {
	T m = q.front();
	vector<T> v = copyQueueToVector(q);
	while (!q.empty()) { 
		if (q.front() < mi)mi = q.front(); 
		q.pop(); 
	}
	q = copyVectorToQueue(v);
	return mi;
}

template <class T>
T Listing<T>::Max() {
	T m = q.front();
	vector<T> v = copyQueueToVector(q);
	while (!q.empty()) { 
		if (q.front() > ma)ma = q.front(); 
		q.pop(); 
	}
	q = copyVectorToQueue(v);
	return ma;
}

template <class T>
void Listing<T>::Sum() {
	T mi = Min();
	T ma = Max();
	vector<T> v;
	T t;
	while (!q.empty()) {
		t.front();
		v.push_back(t + mi + ma);
		q.pop();
	}
	q = copyVectorToQueue(v);
}