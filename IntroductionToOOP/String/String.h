//String
#pragma once

//String
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n------------------------------------\n"

////////////////////////////////////////////////////////////////////////////////////
////////				Объявление класса (Class declaration)				////////

class String;
String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);

class String
{
	int size;	//Размер строки в Байтах
	char* str;	//Указатель на строку в динамической памяти
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();

	//					Constructors:
	explicit String(int size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other)noexcept;
	~String();

	//					Operators:
	String& operator=(const String& other);
	String& operator=(String&& other)noexcept;

	char operator[](int i)const;
	char& operator[](int i);


	//					Methods:
	void print()const;
};

////////		  Конец объявления класса (Class declaration end)			////////
////////////////////////////////////////////////////////////////////////////////////