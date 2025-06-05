#pragma once
#include <iostream>

template <typename T>

class MyVector {

public:
	MyVector();
	MyVector(const MyVector& other);
	MyVector& operator=(const MyVector& other);
	~MyVector();

	void push_back(const T& obj);
	T pop_back();
	T removeAt(size_t index);

	T& operator[](size_t index);

	const T& operator[](size_t index) const;

	const size_t getSize() const;
	const size_t getCapacity() const;

	void print();

private:

	void copyFrom(const MyVector<T>& other);
	void free();
	void resize();


	T* data;
	size_t size;
	size_t capacity;
};

template<typename T>
MyVector<T>::MyVector()
{
	this->capacity = 4;
	this->size = 0;
	this->data = new T[capacity];
}

template<typename T>
MyVector<T>::MyVector(const MyVector<T>& other)
{
	copyFrom(other);
}


template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other)
{
	if (this != &other)
	{
		free();

		copyFrom(other);
	}
	return *this;
}


template<typename T>
MyVector<T>::~MyVector<T>()
{
	free();
}

template<typename T>
void MyVector<T>::push_back(const T& obj)
{
	if (this->size >= this->capacity)
	{
		resize();
	}
	this->data[size++] = obj;

}

template<typename T>
T MyVector<T>::pop_back()
{
	if (size == 0)
	{
		throw std::out_of_range("The vector is empty");
	}

	T result = data[--size];
	return result;
}

template<typename T>
T MyVector<T>::removeAt(size_t index)
{
	if (index >= size)
	{
		throw std::out_of_range("Index out of bounds");
	}

	T removedElement = data[index];
	for (size_t i = index; i < size - 1; ++i)
	{
		data[i] = data[i + 1];
	}
	--size;
	return removedElement;
}

template<typename T>
T& MyVector<T>::operator[](size_t index)
{
	if (index >= size)
	{
		throw std::out_of_range("Index out of bounds.");
	}
	return this->data[index];
}

template<typename T>
const T& MyVector<T>::operator[](size_t index) const
{
	if (index >= size)
	{
		throw std::out_of_range("Index out of bounds.");
	}

	return this->data[index];
}


template<typename T>
const size_t MyVector<T>::getSize() const
{
	return this->size;
}

template<typename T>
const size_t MyVector<T>::getCapacity() const
{
	return this->capacity;
}

template<typename T>
inline void MyVector<T>::print()
{
	for (size_t i = 0; i < this->size; i++)
	{
		std::cout << data[i] << " ";
	}
}

template<typename T>
void MyVector<T>::copyFrom(const MyVector<T>& other)
{
	size = other.size;
	capacity = other.capacity;
	data = new T[capacity];
	for (size_t i = 0; i < size; ++i)
	{
		data[i] = other.data[i];
	}
}

template<typename T>
void MyVector<T>::free()
{
	delete[] data;
	data = nullptr;
	size = 0;
	capacity = 0;
}

template<typename T>
void MyVector<T>::resize()
{
	capacity *= 2;
	T* newData = new T[capacity];
	for (size_t i = 0; i < size; ++i)
	{
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
}