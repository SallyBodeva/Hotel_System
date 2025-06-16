/**
*
* Solution to course project #5
* Object-Oriented Programming course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2024 / 2025
*
* @author Salihe Ali Bodeva
* @idnumber 9MI0600468
* @compiler VS
*
*
*/


#pragma once
#include <iostream>

class MyString {
public:

	MyString();
	MyString(const char* input);
	MyString(const MyString& other);
	MyString(MyString&& other) noexcept;
	MyString& operator=(const MyString& other);
	MyString& operator=(MyString&& other) noexcept;
	~MyString();

	int getSize() const;
	int getCapacity() const;
	const char* c_str() const;

	MyString substr(int startIndex, int len) const;

	bool empty() const;
	void clear();

	char& operator[](int index);
	char operator[](int index) const;
	MyString& operator+=(const char* data);
	MyString& operator+=(const MyString& other);
	MyString& operator+=(char symbol);
	MyString toLower() const;

	int toInt() const;
	double toDouble() const;
	static MyString toStr(int value);

	friend std::istream& operator>>(std::istream& is, MyString& obj);
	friend std::ostream& operator<<(std::ostream& os, const MyString& obj);

private:
	void moveFrom(MyString&& other);
	void copyFrom(const MyString& other);
	void free();
	void resize(int newCapacity);

	int capacity;
	char* data;
};

MyString operator+(const MyString& lhs, const MyString& rhs);

bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);