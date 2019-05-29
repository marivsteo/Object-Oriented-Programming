#pragma once
#include<stdlib.h>
#include<string.h>
#include<exception>
#include<iostream>

template <class T>
class Vector {
private:
	int VectorSize;
	int cap;
	T* array;

	void resize() {
		T* elems = new T[this->cap * 2];
		for (int i = 0;i < this->VectorSize; i++)
			elems[i] = this->array[i];
		this->cap *= 2;
		delete[] this->array;
		this->array = elems;
	}

public:

	Vector() {
		this->VectorSize = 0;
		this->cap = 1;
		this->array = new T[this->cap];
	}

	int size() const {
		return this->VectorSize;
	}

	Vector<T>& operator = (const Vector<T>& v) {
		this->VectorSize = v.VectorSize;
		this->cap = v.cap;
		delete[] this->array;
		this->array = new T[this->cap];
		for (int i = 0; i < v.size(); i++)
			this->array[i] = v.array[i];
		return *this;
	}

	/*Vector<T>& operator + (const Vector<T>& v, const T& elem) {
		if (v.VectorSize == v.cap)
			v.resize();
		v.array[v.VectorSize++] = elem;
		return *v;
	}*/
	
	Vector<T>& operator + (const T& elem) {
		if (this->VectorSize == this->cap)
			this->resize();
		this->array[this->VectorSize++] = elem;
		return *this;
	}

	Vector(const Vector & v) {
		VectorSize = v.VectorSize;
		cap = v.cap;
		this->array = new T[this->cap];
		for (int i = 0; i < v.size(); i++)
			this->array[i] = v.array[i];
	}

	void addElem(T elem) {
		if (this->VectorSize == this->cap)
			this->resize();
		this->array[this->VectorSize++] = elem;
	}

	void remove(int index) {
		if (index < 0 or index >= this->VectorSize)
			throw std::exception();
		std::copy(this->array + index + 1, this->array + VectorSize, this->array + index);
		this->VectorSize--;
	}

	T& operator [] (int i) const {
		if (i < 0 or i >= this->VectorSize)
			throw std::exception();
		return this->array[i];
	}

	friend std::ostream& operator << (std::ostream& os, const Vector<T>& v) {
		for (int i = 0; i < v.size(); i++)
			os << i << ".  " << v[i] << "\n";
		return os;
	}

	~Vector() {
		delete[] this->array;
	}
};