#include<iostream>
#include<string>
#include "List.h"
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n-------------------------------------------------\n"
/*
-------------------------------------
Class - ������� �����;
Class<type> - ��������� �����;
Class<T> .....
Class<double> ....
-------------------------------------
*/

//template - ���������� �������� �������.
//typename - ������� ��������� ��� ������.
//T - ��� ���������� ����.



////////////////////////////////////////////////////////////////////////////////
////////////					   CONSTITERATORS				  	////////////
////////////////////////////////////////////////////////////////////////////////
//                                 ConstreverseIterator
template<typename T> List<T>::ConstReverseIterator::ConstReverseIterator(Element* Temp) :ConstBaseIterator(Temp)
{
#ifdef DEBUG
	cout << "RItConstructor:\t" << this << endl;
#endif // DEBUG
}
template<typename T> List<T>::ConstReverseIterator::~ConstReverseIterator()
{
#ifdef DEBUG
	cout << "RItDestructor:\t" << this << endl;
#endif // DEBUG
}

//					Incremento/Decremento:
template<typename T>typename List<T>::ConstReverseIterator& List<T>::ConstReverseIterator:: operator++()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return *this;
}
template<typename T>typename List<T>::ConstReverseIterator List<T>::ConstReverseIterator::operator++(int)
{
	ConstReverseIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return old;
}
template<typename T>typename List<T>::ConstReverseIterator& List<T>::ConstReverseIterator:: operator--()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return *this;
}
template<typename T>typename List<T>::ConstReverseIterator List<T>::ConstReverseIterator::operator--(int)
{
	ConstReverseIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;

	return old;
}



///////////////////////////////////////////////////////////////////////////////
///                        ConstIterator                             //////////
template<typename T>List<T>::ConstIterator::ConstIterator(Element* Temp) :ConstBaseIterator(Temp)
{

}
template<typename T>List<T>::ConstIterator::~ConstIterator()
{

}

template<typename T>typename List<T>::ConstIterator& List<T>::ConstIterator:: operator++()	//Prefix increment
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return *this;
}
template<typename T>typename List<T>::ConstIterator List<T>::ConstIterator:: operator++(int)//Postfix increment
{
	ConstIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return old;
}
template<typename T>typename List<T>::ConstIterator& List<T>::ConstIterator:: operator--()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return *this;
}
template<typename T>typename List<T>::ConstIterator List<T>::ConstIterator:: operator--(int)
{
	ConstIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return old;
}

//					Comparison operators:
template<typename T>typename bool List<T>::ConstBaseIterator:: operator==(const ConstBaseIterator& othe)const
{
	return this->Temp == othe.Temp;
}
template<typename T>typename bool List<T>::ConstBaseIterator:: operator!=(const ConstBaseIterator& othe)const
{
	return this->Temp != othe.Temp;
}

/////////// Dereference operator
template<typename T> const  T& List<T>::ConstBaseIterator::operator*() const
{
	return Temp->Data;
}
////////////////////////////////////////////////////////////////////////////////
////////////					   ITERATORS				    	////////////
////////////////////////////////////////////////////////////////////////////////
////////////					   					                ////////////
template<typename T>T& List<T>::Iterator:: operator*()
{
	return ConstBaseIterator::Temp->Data;
}
template<typename T>T& List<T>::ReverseIterator:: operator*()
{
	return ConstBaseIterator::Temp->Data;
}

////////////////////////////////////////////////////////////////////////////////
////////////					   List members						////////////
////////////////////////////////////////////////////////////////////////////////

//type name(parameters)
template<typename T>typename List<T>::ConstIterator List<T>::begin()const
{
	return Head;
}
template<typename T>typename List<T>::ConstIterator List<T>::end()const
{
	return nullptr;
}
template<typename T>typename List<T>::Iterator List<T>::begin()
{
	return Head;
}
template<typename T>typename List<T>::Iterator List<T>::end()
{
	return nullptr;
}

template<typename T>typename List<T>::ConstReverseIterator List<T>::rbegin()const
{
	return Tail;
}
template<typename T>typename List<T>::ConstReverseIterator List<T>::rend()const
{
	return nullptr;
}
template<typename T>typename List<T>::ReverseIterator List<T>::rbegin()
{
	return Tail;
}
template<typename T>typename List<T>::ReverseIterator List<T>::rend()
{
	return nullptr;
}

//				Constructors:
template<typename T>List<T>::List()
{
	Head = Tail = nullptr;
	size = 0;
	cout << "LConstructor:\t" << this << endl;
}
template<typename T>List<T>::List(const std::initializer_list<T>& il) :List()
{
	for (T const* it = il.begin(); it != il.end(); ++it)
		push_back(*it);
}
template<typename T>List<T>::List(const List<T>& other) : List()
{
	*this = other;
	cout << "CopyConstructor:" << this << endl;
}
template<typename T>List<T>::~List()
{
	//while (Head)pop_front();
	while (Tail)pop_back();
	cout << "LDestructor:\t" << this << endl;
}

//				Operators:
//type	  name	(	parameters	)
template<typename T>List<T>& List<T>::operator=(const List<T>& other)
{
	if (this == &other)return *this;
	while (Head)pop_front();
	for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)push_back(Temp->Data);
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}

//				Adding elements:
template<typename T>void List<T>::push_front(T Data)
{
	if (Head == nullptr && Tail == nullptr)
	{
		Head = Tail = new Element(Data);
	}
	else
	{
		Element* New = new Element(Data);	//1)
		New->pNext = Head;	//2)
		Head->pPrev = New;	//3)
		Head = New;	//4) 
	}
	size++;
}
template<typename T>void List<T>::push_back(T Data)
{
	if (Head == nullptr && Tail == nullptr)
	{
		Head = Tail = new Element(Data);
	}
	else
	{
		Element* New = new Element(Data);//1)
		New->pPrev = Tail;//2)
		Tail->pNext = New;//3)
		Tail = New;//4)
	}
	size++;
}
template<typename T>void List<T>::insert(T Data, int index)
{
	Element* Temp;
	if (index < size / 2)
	{
		Temp = Head;
		for (int i = 0; i < index; i++)	Temp = Temp->pNext;
	}
	else
	{
		Temp = Tail;
		for (int i = index; i < size - 1; i++)Temp = Temp->pPrev;
	}
	Element* New = new Element(Data);	//1)
	New->pNext = Temp;			//2)
	New->pPrev = Temp->pPrev;	//3)
	Temp->pPrev->pNext = New;	//4)
	Temp->pPrev = New;			//5)
}

//				Removing elements:
template<typename T>void List<T>::pop_front()
{
	if (Head == nullptr && Tail == nullptr)return;
	if (Head == Tail)
	{
		delete Head;
		Head = Tail = nullptr;
	}
	else
	{
		Head = Head->pNext;		//1)
		delete Head->pPrev;		//2)
		Head->pPrev = nullptr;	//3) 
	}
	size--;
}
template<typename T>void List<T>::pop_back()
{
	if (Head == nullptr && Tail == nullptr)return;
	if (Head == Tail)
	{
		delete Tail;
		Head = Tail = nullptr;
	}
	else
	{
		Tail = Tail->pPrev;		//1)
		delete Tail->pNext;		//2)
		Tail->pNext = nullptr;	//3)
	}
	size--;
}

//				Methods:
template<typename T>void List<T>::print()const
{
	cout << delimiter << endl;
	cout << "Head:\t" << Head << endl;

	//��������� 'Start' ����������� 1 ��� - ����� ������ ���������;
	//'Stop' - ������� ���������� ��� ����������� �����. 
	//��������� 'Stop' ����������� ����� ������ ���������;
	//'Step' - ��� �����, ����� �� ��������� �� ��������� �������.
	//��������� 'Step' ����������� ����� ������ ��������
//		for (		Start;		   Stop;		Step	   )
	for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		cout
		<< Temp->pPrev << tab
		<< Temp << tab
		<< Temp->Data << tab
		<< Temp->pNext << endl;

	cout << "Tail:\t" << Tail << endl;
	cout << "���������� ��������� ������: " << size << endl;
	cout << delimiter << endl;
}
template<typename T>void List<T>::reverse_print()const
{
	cout << delimiter << endl;
	cout << "Tail:\t" << Tail << endl;
	for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
		cout
		<< Temp->pPrev << tab
		<< Temp << tab
		<< Temp->Data << tab
		<< Temp->pNext << endl;

	cout << "Head:\t" << Head << endl;
	cout << "���������� ��������� ������: " << size << endl;
	cout << delimiter << endl;
}
////////////					   List members						////////////
////////////////////////////////////////////////////////////////////////////////

template<typename T>List<T> operator+(const List<T>& left, const List<T>& right)
{
	List<T> buffer = left;	//CopyConstructor
	for (typename List<T>::ConstIterator it = right.begin(); it != right.end(); ++it)
	{
		buffer.push_back(*it);
		//*it *= 10;
	}
	return buffer;
}
template<typename T>void Grow(List<T>& list)
{
	for (typename List<T>::Iterator it = list.begin(); it != list.end(); ++it)
		*it *= 10;
}
