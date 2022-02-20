/*
*										ЗАДАЧА 3
*
* 1. Написать шаблонную функцию, складывающую векторы элементов любых типов,
*		допускающих сложение.
*/

#include "task3.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm> 


using namespace std;

/**
* Шаблонная функция, складывающая элементы двух векторов (разных рамеров).
* 
* @param [in] vector<T>& v1;
* @param [in] vector<T>& v2;
* 
* @return vector<T>;
* 
* @note: объявление итератора не работает без "typename".
*/
template <class t>
vector<t> addVector(vector<t>& v1, vector<t>& v2)
{
	vector<t> resv;//содержит сумму элементов двух векторов v1, v2 
	typename vector<t>::iterator itr_v1;
	typename vector<t>::iterator itr_v2;

	if (v1.size() >= v2.size())
	{
		for (itr_v1 = v1.begin(), itr_v2 = v2.begin(); itr_v1 != v1.end(); itr_v1++)
		{
			if (itr_v2 != v2.end())
			{
				resv.push_back(*itr_v1 + *itr_v2);
				itr_v2++;
			}
			else//v1.size() > v2.size(). push only v1 value.
			{
				resv.push_back(*itr_v1);
			}
		}
	}
	else//v2.size() > v1.size().
	{
		for (itr_v2 = v2.begin(), itr_v1 = v1.begin(); itr_v2 != v2.end(); itr_v2++)
		{
			if (itr_v1 != v1.end())
			{
				resv.push_back(*itr_v1 + *itr_v2);
				itr_v1++;
			}
			else//push only v2 value.
			{
				resv.push_back(*itr_v2);
			}
		}
	}

	return resv;
}

void printVector(const vector<int>& v)
{
	for_each(v.begin(), v.end(), [](int num) {std::cout << std::setw(3) << std::right << num << ", "; });
	cout << endl;
}

void printVector(const vector<double>& v)
{
	for_each(v.begin(), v.end(), [](double num) {std::cout << std::setw(3) << std::right << num << ", "; });
	cout << endl;
}

void task3()
{
	std::vector<int> v1_int = { 0, 9, 4, 6, 7 };
	std::vector<int> v2_int = { 1, 2, 3, 4, 5, 6, 7, 8 };
	std::vector<int>::iterator itr_int;

	std::vector<double> v1_double = { 10.0, 1.0, 3.0, 6.0, 7.0};
	std::vector<double> v2_double = { 1.0, 2.0, 3.0 };
	std::vector<double>::iterator itr_double;

	std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Task 3 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "1. Написать шаблонную функцию, складывающую векторы элементов любых типов,\n   допускающих сложение.\n\n";

	/* ---------------------------------------- vector<int> ---------------------------------------- */

	//сложим элеметы векторов v1,v2 в вектор vRes
	std::vector<int> vRes = addVector(v1_int, v2_int);

	//распечатаем вектора
	std::cout << "v1_int    = "; printVector(v1_int);
	std::cout << "v2_int    = "; printVector(v2_int);
	std::cout << "---------------------------------------------------\n";
	std::cout << "sum v1,v2 = "; printVector(vRes);	

	std::cout << endl;

	/* ---------------------------------------- vector<double> ---------------------------------------- */

	//сложим элеметы векторов v1,v2 в вектор vRes
	std::vector<double> vRes_double = addVector(v1_double, v2_double);

	//распечатаем вектора
	std::cout << "v1_double = "; printVector(v1_double);
	std::cout << "v2_double = "; printVector(v2_double);
	std::cout << "------------------------------------\n";
	std::cout << "sum v1,v2 = "; printVector(vRes_double);
}
