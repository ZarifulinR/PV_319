//String
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n------------------------------------\n"

////////////////////////////////////////////////////////////////////////////////////
////////				Объявление класса (Class declaration)				////////

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

///------------------------------------------------------------------------------///

////////////////////////////////////////////////////////////////////////////////////
////////				Определение класса (Class definition)				////////

int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}


//					Constructors:
String::String(int size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	cout << "Constructor:\t" << this << endl;
}
String::String(const char str[]) :String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1;
	//Функция strlen() возвращает размер строки в символах,
	//и нам нужно добавить еще один Байт для NULL-Terminator-а
	//this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	//Deep copy (Побитовое копирование):
	//this->size = other.size;
	//this->str = new char[size] {};
	//for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyConstructor:" << this << endl;
}
String::String(String&& other)noexcept :size(other.size), str(other.str)//r-value reference
{
	//Shallow copy:
	//this->size = other.size;
	//this->str = other.str;	//Shallow copy

	//Reset other:
	other.size = 0;
	other.str = nullptr;
	cout << "MoveConstructor:" << this << endl;
}
String::~String()
{
	delete[] str;
	cout << "Destructor:\t" << this << endl;
}

//					Operators:
String& String::operator=(const String& other)
{
	//Deep copy (Побитовое копирование):
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignemt:\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)noexcept	//r-value reference
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssignment:\t" << this << endl;
	return *this;
}

char String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}


//					Methods:
void String::print()const
{
	cout << "Obj:\t\t" << this << endl;
	cout << "Size:\t\t" << size << endl;
	cout << "Addr:\t\t" << &str << endl;
	cout << "Str:\t\t" << str << endl;
	cout << delimiter << endl;
}

String operator+(const String& left, const String& right)
{
	//cout << delimiter << endl;
	cout << "Operator + " << endl;
	String buffer(left.get_size() + right.get_size() - 1);
	//buffer.print();
	for (int i = 0; i < left.get_size(); i++)
		buffer[i] = left[i];
	//buffer.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		buffer[i + left.get_size() - 1] = right[i];
	//buffer.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return buffer;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

////////		  Конец определения класса (Class definition end)			////////
////////////////////////////////////////////////////////////////////////////////////

//#define CONSTRUCTORS_CHECK
//#define OPERATOR_PLUS_CHECK
//#define TEMPORARY_UNNAMED_OBJECTS
#define CALLING_CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	String str1;		//Default constructor
	str1.print();

	//String str2 = 8;	//Conversion from 'int' to 'String'
	String str2(8);		//Single-argument 'int' constructor
	str2.print();

	String str3 = "Hello";
	str3 = str3;
	str3.print();

	String str4 = "World";
	str4.print();

	cout << str3 << endl;
	cout << str4 << endl;

	//String str5 = str3 + str4;
	String str5;
	str5 = str3 + str4;		//Copy assignment
	str5.print();
	cout << str5 << endl;
#endif // CONSTRUCTORS_CHECK

	//Shallow copy (Поверхностное копирование)

#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";

	//String str3 = str1 + str2;	//MoveConstructor
	String str3;
	cout << delimiter << endl;
	str3 = str1 + str2;	//MoveAssignment
	cout << delimiter << endl;
	cout << str3 << endl;

	cout << str1 << endl;
	cout << str2 << endl;
#endif // OPERATOR_PLUS_CHECK


#ifdef TEMPORARY_UNNAMED_OBJECTS
	//cout << delimiter << endl;
	5;	//Временный безымянный объект
	2 + 3;	//Оператор + создает временный безымянный объект
	String("Hello");	//Явно вызываем конструктор и создаем временный безымянный объект

	////////////////////////////////////

	cout << delimiter << endl;

	////////////////////////////////////

	{
		String str("World");	//Создается локальный объект 'str', который существует в пределах {} (в безымянном пространстве имен)
	}
	cout << delimiter << endl;
#endif // TEMPORARY_UNNAMED_OBJECTS

#ifdef CALLING_CONSTRUCTORS
	String str1;	//Default constructor
	str1.print();

	//Single-Argument constructor 'int'
	//String str2 = 8;	//explicit constructor так вызвать невозможно
	String str2(8);		//explicit constructor можно вызвать только так
	str2.print();

	String str3 = "Hello";	//Single-Argument constructor 'char'
	str3.print();

	String str4();	//Здесь НЕ вызывается никакой конструктор, и не создается объект,
					//здесь объявляется функция str4(), которая не принимает никаких параметров,
					//и возвращает значение типа 'String'.
					//Т.е., таким образом DefaultConstructor вызвать невозможно,
	//str4.print();
	//Если нужно явно вызвать DefaultConstructor, это делается следующим образом:
	String str5{};	//Явный вызов конструктора по умолчанию
	str5.print();

	//String str6 = str3;	//CopyConstructor
	//String str6(str3);	//CopyConstructor
	String str6{ str3 };	//CopyConstructor
	str6.print();
	//Следовательно, аюсолютно любой конструктор можно вызвать при помощи () или {}
#endif // CALLING_CONSTRUCTORS


}