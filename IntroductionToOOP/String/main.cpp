#include"String.h"

//#define CONSTRUCTORS_CHECK
#define OPERATOR_PLUS_CHECK
//#define TEMPORARY_UNNAMED_OBJECTS
//#define CALLING_CONSTRUCTORS

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