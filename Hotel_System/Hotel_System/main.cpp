#include <iostream>
#include <sstream>
#include "System.h"
#include "MyVector.hpp"

int main()
{
	System s;
	s.run();
}



//
//const int BUFFER_SIZE = 1024;
//char buffer[BUFFER_SIZE];
//
//std::cin.getline(buffer, BUFFER_SIZE);
//
//std::istringstream iss(buffer);
//
//char word[256];
//MyVector<MyString> words;
//
//while (iss >> word) {
//    words.push_back(MyString(word));
//}
//
//// Демонстрация
//
//words.removeAt(0);
//
//int count = words.getSize();
//
//for (size_t i = 0; i < count; i++)
//{
//    std::cout << words[i] << std::endl;
//}
//
//return 0;