https://github.com/okovtun/PV_319.git
https://www.youtube.com/playlist?list=PLeqyOOqxeiIMoZmXHC4xATi6sucdKobIg

TODO:
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