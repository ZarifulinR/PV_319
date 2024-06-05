//Объектно-ориентированное программирование на языке C++
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

//Объявляя структуру или класс мы создаем новый тип данных (пользовательский тип данных).
class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//				Constrcutors:
	Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constrcutor:\t\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//				Methods:
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

//#define STRUCT_POINT

void main()
{
	setlocale(LC_ALL, "");

#if defined STRUCT_POINT
	int a;		//Объявление переменной 'a' типа 'int'
	Point A;	//Объявление переменной 'A' типа 'Point'
				//Создание объекта 'A' типа 'Point'
				//Создание экзмепляра 'A' структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

	Point A;		//Default constructor
	//A.set_x(2);
	//A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	Point B = 5;	//Single-Argument Constructor
	B.print();

	Point C(2, 3);
	C.print();

//	for (counter;  condition; increment)
	/*for (int i = 0; i < 10; i++)
	{
		cout << i << "\t";
	}*/
	//cout << i << endl;
	//cout << endl;
}

/*
-------------------------------------------------------------
.  - Оператор прямого доступа (Point operator)
-> - Оператор косвенного доступа (Arrow operator)
-------------------------------------------------------------
*/

/*
-------------------------------------------------------------
				OOP concepts:
1. Encapsulation - это сокрытие определенной части класса от внешнего мира;
	Модификаторы доступа:
		private:
		public:
		protected:
	get/set-методов
	get-методы (взять, получить)
	set-методы (задать, установить)
2. Inheritance;
3. Polymorphism;
-------------------------------------------------------------
*/

/*
-------------------------------------------------------------
1. Constructor - это метод, который создает объект;
	- с параметрами;
	- без параметров;
	- по умолчанию - это конструктор, который может быть вызван без параметров;
	- конструктор копирования;
	- конструктор переноса;
2. ~Destructor - это метод, который уничтожает обеъкт по истечении его времени жизни;
3. Assignment operator;
-------------------------------------------------------------
*/