//#pragma once

#ifndef _FOOD_H_
#define _FOOD_H_

#include <string>
#include <iostream>
#include <iomanip>
#include "utils.h"

class Food
{
private:
	std::string 	name;//название
	double			weight_kg;//вес в килограммах
	double			cost;//текуща€ цена с учетом веса(for example: weight = 1.521 kg, the cost = 1.52$)
	double			price_1kg;//цена за 1 килограмм
	
public:
	Food();
	Food(std::string name, double weight_kg, double cost);

	bool isMade();
	void erase();
	bool make(std::string name, double weight_kg, double cost);
	void print();

	std::string getName()		{ return name; };
	double		getWeight_kg()	{ return weight_kg; };
	double		getPrice_1kg()	{ return price_1kg; };
	double		getCost()		{ return cost; };//текуща€ цена с учетом веса

};

#endif // !_FOOD_H_

