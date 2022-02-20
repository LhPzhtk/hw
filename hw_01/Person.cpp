#include "Person.h"
#include <iostream>
#include <iomanip>

Person::Person(string mFirstName, string mLastName, string mPatronymic, uint16_t mAge, double mAverageScoreAssesment) :
	firstName(mFirstName), lastName(mLastName), patronymic(mPatronymic), age(mAge), averageScoreAssesment(mAverageScoreAssesment) 
{
}

Person::Person()
{
	firstName  = "";
	lastName   = "";
	patronymic = "";
	age = 0;
	averageScoreAssesment = 0;
}

Person::~Person()
{
}

string Person::getFirstName()
{
	return firstName;
}

bool Person::setFirstName(string firstName)
{
	//check limitation
	if(!Person::isInRange(firstName, PERSON_TOOLS_NAME_MIN_LENGTH, PERSON_TOOLS_NAME_MAX_LENGTH))
	{
		return false;
	}
	else
	{
		this->firstName = firstName;
		return true;
	}
}

string Person::getLastName()
{
	return lastName;
}

bool Person::setLastName(string lastName)
{
	//check limitation
	if (!Person::isInRange(lastName, PERSON_TOOLS_NAME_MIN_LENGTH, PERSON_TOOLS_NAME_MAX_LENGTH))
	{
		return false;
	}
	else
	{
		this->lastName = lastName;
		return true;
	}
}

string Person::getPatronymic()
{
	return patronymic;
}

bool Person::setPatronymic(string patronymic)
{
	//check limitation
	if (!Person::isInRange(patronymic, PERSON_TOOLS_NAME_MIN_LENGTH, PERSON_TOOLS_NAME_MAX_LENGTH))
	{
		return false;
	}
	else
	{
		this->patronymic = patronymic;
		return true;
	}
}

uint16_t Person::getAge()
{
	return age;
}

bool Person::setAge(uint16_t age)
{
	//check limitation
	if(!Person::isInRange(age, PERSON_TOOLS_AGE_MIN_VALUE, PERSON_TOOLS_AGE_MAX_VALUE))
	{
		return false;
	}
	else
	{
		this->age = age;
		return true;
	}
}

double Person::getAverageScoreAssesment()
{
	return averageScoreAssesment;
}

bool Person::setAverageScoreAssesment(double averageScore)
{
	averageScore = Person::round(averageScore, PERSON_TOOLS_AVERAGE_SCORE_PRECISION);

	//check limitation
	if (!Person::isInRange(averageScore, PERSON_TOOLS_AVERAGE_SCORE_MIN_VALUE, PERSON_TOOLS_AVERAGE_SCORE_MAX_VALUE))
	{
		return false;
	}
	else
	{
		this->averageScoreAssesment = averageScore;
		return true;
	}
}

double Person::round(double in_raw, double in_precision)
{
double precision = (1.0 / in_precision);

	//for example: the 3.4899 in_raw value will be equal to 3.49 after this floor if the in_precision = 0.01
	in_raw = floor(in_raw * precision + 0.5) / precision;
	return in_raw;
}

template <typename T, typename L>
bool Person::isInRange(T in_value, L in_minLimit, L in_maxLimit)
{
	//is empty 
	if (in_value.empty())
	{
		return false;
	}
	else
	{
		//check limitation 
		if ((in_value.length() < in_minLimit) ||
			(in_value.length() > in_maxLimit))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

template<typename D>
bool Person::isInRange(D in_value, D in_minLimit, D in_maxLimit)
{
	//check limitation 
	if ((in_value < in_minLimit) ||
		(in_value > in_maxLimit))
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Person::toPrint()
{
	cout<< std::setw(15) << std::left  << lastName
		<< std::setw(15) << std::right << firstName 
		<< std::setw(15) << std::right << patronymic
		<< std::setw(10)  << std::right << age <<" лет"
		<< std::setw(10)  << std::right << averageScoreAssesment << " - ср. балл"
		<< endl;
}

bool Person::calcAgeAverageArrOfPersons(Person* in_arrayPersons, uint32_t in_arrayPersonsSize, uint16_t* out_result)
{
	double averageAge = 0.0;

	if ((in_arrayPersons == NULL) || (out_result == NULL) || (in_arrayPersonsSize == 0))
	{
		return false;
	}
	else
	{
		for (uint32_t i = 0; i < in_arrayPersonsSize; ++i)
		{
			averageAge += (double)in_arrayPersons[i].getAge();
		}

		averageAge /= (double)in_arrayPersonsSize;
		averageAge = floor(averageAge + 0.5);

		*out_result = (uint16_t)averageAge;
		return true;
	}
}

Person* Person::createNewPerson(string firstName, string lastName, string patronymic, uint16_t age, double averageScoreAssesment)
{
	//check limitation
	if (!Person::isInRange(firstName, PERSON_TOOLS_NAME_MIN_LENGTH, PERSON_TOOLS_NAME_MAX_LENGTH))
	{
		return nullptr;
	}

	if (!Person::isInRange(lastName, PERSON_TOOLS_NAME_MIN_LENGTH, PERSON_TOOLS_NAME_MAX_LENGTH))
	{
		return nullptr;
	}

	if (!Person::isInRange(patronymic, PERSON_TOOLS_NAME_MIN_LENGTH, PERSON_TOOLS_NAME_MAX_LENGTH))
	{
		return nullptr;
	}

	if (!Person::isInRange(age, PERSON_TOOLS_AGE_MIN_VALUE, PERSON_TOOLS_AGE_MAX_VALUE))
	{
		return nullptr;
	}

	if (!Person::isInRange(averageScoreAssesment, PERSON_TOOLS_AVERAGE_SCORE_MIN_VALUE, PERSON_TOOLS_AVERAGE_SCORE_MAX_VALUE))
	{
		return nullptr;
	}

	averageScoreAssesment = Person::round(averageScoreAssesment, PERSON_TOOLS_AVERAGE_SCORE_PRECISION);

	return new Person(firstName, lastName, patronymic, age, averageScoreAssesment);
}
