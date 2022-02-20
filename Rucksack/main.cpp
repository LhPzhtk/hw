// Rucksack.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

/*                                  Задача о рюкзаке.
Задача состоит в том, чтобы выбрать, какие предметы, имеющие вес и стоимость, 
поместить в рюкзак ограниченной ёмкости W, да так, чтобы максимизировать общую ценность его содержимого.
Мы можем определить соотношение стоимости предмета к его весу, т. е. с «жадностью» выбирать предметы, 
имеющие высокую стоимость, но в то же время маленький вес, а затем сортировать их по этим критериям. 
В задаче с дробным рюкзаком нам разрешено брать дробные части предмета.
*/

#include <iostream>
#include "utils.h"
#include "food.h"
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

//Шаблон для вывода вектора
template <class T>
void v_print (const T& v) 
{
	int w = 11;
	std::cout << "________________________________________________\n";
	std::cout
		<< std::setw(w) << std::left << "name" << "|"
		<< std::setw(w) << std::right << "weight(kg)" << "|"
		<< std::setw(w) << std::right << "cost($)" << "|"
		<< std::setw(w) << std::right << "price(1kg)" << "|"
		<< std::endl;
	std::cout << "-----------|-----------|-----------|-----------|\n";

	for_each(v.begin(), v.end(), [](Food f) {f.print(); 
											std::cout << "------------------------------------------------\n";});

};

int main()
{
	Food cheese("cheese", 5, 23.0);
	Food bread("bread",   3, 16.0);
	Food butter("butter", 2, 10.00);

	vector<Food> vFood = {cheese, bread, butter};

	cout << "Food is made:" << endl;
	v_print(vFood);

	//---------------------------------------- SORT FOODS BY price(1kg) -----------------------------------------
	//сортировка элементов вектора
	std::sort(vFood.begin(), vFood.end(), [](Food f1, Food f2) {
		return (f1.getPrice_1kg() > f2.getPrice_1kg());
		}
	);

	cout << "\nFood is sorted by price_1kg:" << endl;
	v_print(vFood);

	//---------------------------------------- FILL RUCKSACK -----------------------------------------
	const double W = 7.5;//Вес рюкзака
	double rucksackFreeW = W;//Осталось незанятого веса в рюкзаке
	vector<Food> vRucksack;

	vector<Food>::iterator itr_food;
	for (itr_food = vFood.begin(), itr_food = vFood.begin(); itr_food != vFood.end(); itr_food++)
	{
		if (utils::round(rucksackFreeW, 0.001))
		{
			if (itr_food->getWeight_kg() <= rucksackFreeW)
			{
				vRucksack.push_back(*itr_food);
			}
			else
			{
				double new_Weight_kg = utils::round( (itr_food->getWeight_kg() - rucksackFreeW), 0.001 );
				itr_food->make(	itr_food->getName(), 
								new_Weight_kg,
								(itr_food->getPrice_1kg() * new_Weight_kg) );
				vRucksack.push_back(*itr_food);
			}
			rucksackFreeW -= itr_food->getWeight_kg();
		}
		else
		{
			break;
		}
	}
	//------------------------------------------ REPORT RUCKSACK -----------------------------------------
	cout << "\nFood in the rucksack(weight " << W << " kg)  :" << endl;
	v_print(vRucksack);

	double rucksackCost = 0.0;
	vector<Food>::iterator itr_rucksack;
	for (itr_rucksack = vRucksack.begin(); itr_rucksack != vRucksack.end(); itr_rucksack++)
	{
		rucksackCost += itr_rucksack->getCost();
	}
	rucksackCost = utils::round(rucksackCost, 0.001);

	cout << "\nThe cost of the rucksack is " << rucksackCost << "$ " << endl;
}

