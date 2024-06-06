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
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
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
	double distance(Point other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
		//sqrt() - Square Root (Квадратный корень)
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
	return distance;
}

//#define STRUCT_POINT
#define CONSTRUCTORS_CHECK
//#define DISTANCE_CHECK

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

#ifdef CONSTRUCTORS_CHECK
	Point A;		//Default constructor
//A.set_x(2);
//A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	Point B = 5;	//Single-Argument Constructor
	B.print();

	Point C(2, 3);
	C.print();

	A.distance(B);

	//	for (counter;  condition; increment)
		/*for (int i = 0; i < 10; i++)
		{
			cout << i << "\t";
		}*/
		//cout << i << endl;
		//cout << endl;
#endif // CONSTRUCTORS_CHECK

#ifdef DISTANCE_CHECK
	Point A(2, 3);
	Point B(7, 8);

	A.print();
	B.print();

	cout << "Расстояние от точки 'A' до точки 'B':" << A.distance(B) << endl;
	cout << "Расстояние от точки 'B' до точки 'A':" << B.distance(A) << endl;
	cout << "Расстояние между точками 'A' и 'B':  " << distance(A, B) << endl;
	cout << "Расстояние между точками 'B' и 'A':  " << distance(B, A) << endl;
#endif // DISTANCE_CHECK

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
	- конструктор копирования (CopyConstructor):
		DeepCopy	- Побитовое копирование;
		ShallowCopy	- Поверностное копирование;
	- конструктор переноса;
2. ~Destructor - это метод, который уничтожает обеъкт по истечении его времени жизни;
3. Assignment operator;
-------------------------------------------------------------
*/