#include<iostream>
#include<string>

#include "List.cpp"

using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n-------------------------------------------------\n"



//#define BASE_CHECK
//#define ITERATORS_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef BASE_CHECK
	int n;
	cout << "������� ���������� ���������: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.print();
	list.reverse_print();
	//for (int i = 0; i < 100; i++)list.pop_back();
	//list.reverse_print();

	int index;
	int value;
	cout << "������� ������ ������������ ��������:"; cin >> index;
	cout << "������� �������� ������������ ��������:"; cin >> value;
	list.insert(value, index);
	list.print();
	list.reverse_print();
#endif // BASE_CHECK

#ifdef ITERATORS_CHECK
	List list = { 3, 5, 8, 13, 21 };
	//list.print();
	//list.reverse_print();
	for (int i : list)cout << i << tab; cout << endl;
	for (List::ReverseIterator it = list.rbegin(); it != list.rend(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
#endif // ITERATORS_CHECK

	List<int> list1 = { 3, 5, 8, 13, 21 };
	List<int> list2 = { 34, 55, 89 };
	List<int> list3 = list1 + list2;
	/*list3.print();
	list3.reverse_print();*/
	for (int i : list1)cout << i << tab; cout << endl;
	for (int i : list2)cout << i << tab; cout << endl;
	for (int i : list3)cout << i << tab; cout << endl;
	Grow(list3);
	for (int i : list3)cout << i << tab; cout << endl;

	//https://legacy.cplusplus.com/doc/tutorial/control/#:~:text=equal%20to%2050.-,Range%2Dbased%20for%20loop,-The%20for%2Dloop
	List<double> d_list = { 2.7, 3.14, 5.4, 8.3 };
	for (double i : d_list)cout << i << tab; cout << endl;

	List<std::string> s_list = { "������", "�����", "��", "�����", "����", "���" };
	for (std::string i : s_list)cout << i << tab; cout << endl;
}