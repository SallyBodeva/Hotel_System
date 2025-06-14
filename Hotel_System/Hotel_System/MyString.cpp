#include "MyString.h"

MyString::MyString()
{
	this->capacity = 4;
	this->data = new char[this->capacity];
	this->data[0] = '\0';
}

MyString::MyString(const char* input)
{
	int len = strlen(input) + 1;
	this->capacity = len * 2;
	this->data = new char[this->capacity];
	strcpy_s(this->data, len, input);
}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

MyString::MyString(MyString&& other) noexcept
{
	moveFrom(std::move(other));
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

MyString::~MyString()
{
	free();
}

int MyString::getSize() const
{
	return strlen(this->data);
}

int MyString::getCapacity() const
{
	return this->capacity;
}

const char* MyString::c_str() const
{
	return this->data;
}

MyString MyString::substr(int startIndex, int len) const
{
	int currentLen = this->getSize();

	if (startIndex >= currentLen)
	{
		return MyString{};
	}

	if (len > currentLen - startIndex)
	{
		len = currentLen - startIndex;
	}

	char* subStr = new char[len + 1];
	int insertIndex = 0;

	for (int i = 0; i < len; i++)
	{
		subStr[insertIndex++] = this->data[startIndex++];
	}

	subStr[insertIndex] = '\0';

	MyString result(subStr);
	delete[] subStr;
	return result;
}

bool MyString::empty() const
{
	return this->data[0] == '\0';
}

void MyString::clear()
{

	if (this->data != nullptr)
	{
		this->data[0] = '\0';
	}
}

char& MyString::operator[](int index)
{
	if (index < 0 || index >= this->getSize())
	{
		throw std::out_of_range("Invalid index");
	}
	return this->data[index];
}

char MyString::operator[](int index) const
{
	if (index < 0 || index >= this->getSize())
	{
		throw std::out_of_range("Invalid index");
	}
	return this->data[index];
}

MyString& MyString::operator+=(const char* data)
{
	if (data == nullptr)
	{
		return *this;
	}

	int currentLen = this->getSize();
	int dataLen = strlen(data);
	int newLen = currentLen + dataLen + 1;

	if (newLen > this->capacity)
	{
		resize(newLen * 2);
	}

	strcat_s(this->data, this->capacity, data);

	return *this;
}

MyString& MyString::operator+=(const MyString& other)
{
	return *this += other.c_str();
}

MyString& MyString::operator+=(char symbol)
{
	int currentLen = this->getSize();

	if (currentLen + 2 > this->capacity)
	{
		resize((currentLen + 2) * 2);
	}

	this->data[currentLen] = symbol;
	this->data[currentLen + 1] = '\0';

	return *this;
}

MyString MyString::toLower() const
{
	int currentLen = this->getSize();
	char* newData = new char[currentLen + 1];

	for (int i = 0; i < currentLen; i++)
	{
		if (this->data[i] >= 'A' && this->data[i] <= 'Z')
		{
			newData[i] = this->data[i] + ('a' - 'A');
		}
		else
		{
			newData[i] = this->data[i];
		}
	}

	newData[currentLen] = '\0';

	MyString result(newData);
	delete[] newData;

	return result;
}

int MyString::toInt() const 
{
	int result = 0;
	int i = 0;
	bool isNegative = false;

	if (data[i] == '-')
	{
		isNegative = true;
		i++;
	}

	while (data[i] >= '0' && data[i] <= '9') {
		result = result * 10 + (data[i] - '0');
		i++;
	}

	return isNegative ? -result : result;
}

double MyString::toDouble() const
{
	int i = 0;
	

	bool isNegative = false;
	if (data[i] == '-') {
		isNegative = true;
		i++;
	}

	double result = 0.0;

	while (data[i] >= '0' && data[i] <= '9') {
		result = result * 10 + (data[i] - '0');
		i++;
	}

	if (data[i] == '.' || data[i] == ',') {
		i++;
		double fraction = 0.0;
		double divisor = 10.0;
		while (data[i] >= '0' && data[i] <= '9') {
			fraction += (data[i] - '0') / divisor;
			divisor *= 10.0;
			i++;
		}
		result += fraction;
	}

	return isNegative ? -result : result;
}

void MyString::moveFrom(MyString&& other)
{
	this->data = other.data;
	this->capacity = other.capacity;

	other.data = nullptr;
	other.capacity = 0;
}

void MyString::copyFrom(const MyString& other)
{
	this->data = new char[other.capacity + 1];
	strcpy_s(this->data, other.capacity, other.data);
	this->capacity = other.capacity;
}

void MyString::free()
{
	delete[] this->data;
	this->capacity = 4;
	this->data = nullptr;
}

void MyString::resize(int newCapacity)
{
	int currentLen = this->getSize() + 1;

	if (newCapacity < currentLen)
		newCapacity = currentLen;

	char* newData = new char[newCapacity];
	strcpy_s(newData, newCapacity, this->data);

	delete[] this->data;
	this->capacity = newCapacity;
	this->data = newData;
}

std::istream& operator>>(std::istream& is, MyString& obj)
{
	char buffer[1024];

	is >> buffer;

	int neededLen = strlen(buffer) + 1;
	if (neededLen > obj.capacity)
	{
		int neededCapacity = neededLen * 2;
		obj.resize(neededCapacity);
	}

	strcpy_s(obj.data, neededLen, buffer);

	return is;
}

std::ostream& operator<<(std::ostream& os, const MyString& obj)
{
	os << obj.data;

	return os;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	int  len = lhs.getSize() + rhs.getSize() + 1;

	char* data = new char[len];

	strcpy_s(data, len, lhs.c_str());
	strcat_s(data, len, rhs.c_str());

	return MyString(data);
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return !(operator==(lhs, rhs));
}