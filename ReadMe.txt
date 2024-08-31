﻿https://github.com/okovtun/PV_319.git
https://www.youtube.com/playlist?list=PLeqyOOqxeiIMoZmXHC4xATi6sucdKobIg

TODO:
1. Проверить то что мы сделали на типах данных 'double' и 'std::string';
2. От ветки 'TemplatedList2' создать ветку 'SeparatedList2', и в этой ветке
   вынести класс 'List' в отдельные файлы;
3. Если будет совсем скучно, проделать все те же вещи с односвязным списком
   (шаблонизировать и разнести по файлам).

   Всем приятных выходных ;-)

DONE:
Добить итераторы;

DONE:
1. Для двусвязного списка перегрузить оператор +;

DONE:
1. insert()/erase();
2. Создать COMMIT!!!;
3. Оптимизировать общий случай добавления элемента до одного выражения;

DONE:
В отдельном проекте реализовать двусвязный список;

DONE:
Проверочный код в секции 'RANGE_BASED_FOR_LIST' должен заработать:
	https://github.com/okovtun/PV_319/blob/00f51e173906e5400c6e2d1eebd3e649d981c320/DataContainers/ForwardList/main.cpp#L326C1-L334C31

DONE:
0.			!!!		Отдохнуть		!!!
1. Реализовать MoveSemantic;

DONE:
В односвязный список добавить следующте методы:
	??? pop_front(???);	//удаляет начальный элемент списка		DONE
	??? pop_back(???);	//удаляет последний элемент списка		DONE
	??? insert(???);	//вставляет значение в список по указанному индексу
	??? erase(???);		//удаляет элемент из списка по указанному индексу

DONE:
Выучить теорию по динамическим стуктурам данных.

DONE:
1. !!! Слелать COMMIT !!!;
2. Создать ветку 'SingleDrawInGeometry';
3. В этой ветке, код, повторяющийся в разных функциях draw() вынести в базовый класс;	HARDCORE!!!!

DONE:
В иерархию треугольников добавить следующие классы:
	EquilateralTriangle - Равносторонний треугольник;
	IsoscalesTriangle	- Равнобедренный треугольник;
	RightTrinagle		- Прямоугольный треугольник;

TODO:
1. Посмотреть документацию по WinGDI (на уроке);
2. Решить проблему с выходом фигур за пределы экрана;	DONE

DONE:
Реализовать круг и треугольник
	https://en.wikipedia.org/wiki/Disk_(mathematics)

DONE:
Реализовать иерархию геометрических фигур: квадрат, прямоугольник, круг, треугольник.......
Сгенерировать фигуры в случайном порядке, и для каждой фигуры вывести ее первичные своиства: длина стороны, радиус .....
и вторичные свойства, такие как: площадь и периметр. Каждую фигуру так же нужно нарисовать.

DONE:
1. Сохранить группу в файл;			DONE
2. Загрузить группу из файла:
	-пергрузить std::istream operator>>(...);
	-применить его в функции Load();
3. Вынести классы в отдельные файлы;

DONE:
1. В проект 'Academy' добавить класс 'Graduate', который описывает дипломника.
	Дипломник - это студент, который пишет дипломный проект.
2. Используя VisualStudio установить "Конструктор классов";
3. Построить диагрмму классов для проекта 'Academy';

DONE:
1. На ветке 'String separation' вынести классы 'Point' и 'Fraction' в отдельные файлы;
2. Выучить теорию по наследованию;

TOREAD:
https://stackoverflow.com/questions/72927820/c20-visual-studio-2022-complier-optimization-setting-to-implement-move-constru
https://learn.microsoft.com/en-us/cpp/build/reference/zc-nrvo?view=msvc-170
--------------------------------------------------------------------------------
https://en.wikipedia.org/wiki/Copy_elision
https://en.cppreference.com/w/cpp/language/copy_elision

TODO:
"Погонять" делегирование конструкторов в отладчике.

DONE:
Реализовать и проветрить MoveAssignment;

DONE:
1. Решить эту проблему: 
	https://github.com/okovtun/PV_319/blob/a781e5195a215730369fdaaa3ce290e46e596296/IntroductionToOOP/String/main.cpp#L107
2. Решить эту проблему:
	https://github.com/okovtun/PV_319/blob/9977c0bc0cc67c441698218e0841dc042a024dd1/IntroductionToOOP/String/main.cpp#L78-L91
3. Что такое The rule of Five:
	https://legacy.cplusplus.com/doc/tutorial/classes2/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DONE:
Реализовать класс 'String', описывающий строку.
Обеспечить следующие варианты создания объектов:
	String str1;			//Создается пустая строка размером 80 Байт	DONE
	String str2(8);			//Создается пустая строка, размером 8 Байт	DONE
	String str3 = "Hello";	
	String str4 = "World";
	String str5 = str3 + str4;
	cout << str5 << endl;

DONE:
1. Учим теорию!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
2. Проверочный код в секции 'CONVERSIONS_HOME_WORK' должен заработать:
	https://github.com/okovtun/PV_319/blob/2229e78a7a935523bb527141da19287c60f68f33/IntroductionToOOP/Fraction/main.cpp#L361

DONE:
0. !!!!!!!!!!!!!!!!!!!!!!	Выучить теорию	!!!!!!!!!!!!!!!!!!!!!!
1. В проекте 'Point' написать метод ??? distance(???), который возвращает		DONE
   расстояние до указанной точки;
2. В проекте 'Point' написать функцию ??? distance(???), которая возвращает
   расстояние между двумя точками;