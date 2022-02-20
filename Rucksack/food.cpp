#include "Food.h"


Food::Food()
{
	erase();
}

Food::Food(std::string name, double weight_kg, double cost)
{
	make(name, weight_kg, cost);
}

bool Food::make(std::string name, double weight_kg, double cost)
{
	if ((name.empty()) || (weight_kg <= 0.0) || (cost <= 0.0))
	{
		erase();
		return false;
	}
	else
	{
		this->name = name;
		this->weight_kg = utils::round(weight_kg, 0.001);
		this->cost = utils::round(cost, 0.01);
		this->price_1kg = utils::round(this->cost / this->weight_kg, 0.01);
		return true;
	}
}

void Food::erase()
{
	name = "";//название
	weight_kg = 0.0;//вес в килограммах
	price_1kg = 0.0;//цена за 1 килограмм
	cost      = 0.0;//текущая цена с учетом веса
}

bool Food::isMade()
{
	return ((!name.empty()) && (weight_kg > 0.0) && (cost > 0.0));
}

void Food::print()
{
	int w = 11;
	std::cout	<< std::setw(w) << std::left  << name << "|"
				<< std::setw(w) << std::right << weight_kg << "|"
				<< std::setw(w) << std::right << cost << "|"
				<< std::setw(w) << std::right << price_1kg << "|"
	<< std::endl;
}