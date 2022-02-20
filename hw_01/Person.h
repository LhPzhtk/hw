/*								Класс Person.

	Cодержит члены для хранения:
	- ФИО;
	- возраста;
	- average score on the assesment.

	Умеет:
	- печатать информацию о себе в консоль;
	- находить средний возраст всех объектов класса Person из массива (static метод);
	- проверять валидность входных данных, допустимый д-н которых можно настроить в #define определениях здесь же;
	- т.к. нельзя задать значения данных вне д-на, вместо public конструктора с инициализацией
		используй шаблон Builder, который вернёт указатель на объект либо nullptr в случае неудачи;

	Примечание:
	Все ф-ции возвращают bool в значении успешно(true) ли выполнилась ф-ция. 
	А входные/выходные данные передаются через параметры.
*/

#pragma once
#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>

using namespace std;

/*------------------ TOOLS OF LIMITATION -------------------*/

/* firstName, lastName, patronymic limitation */
#define PERSON_TOOLS_NAME_MAX_LENGTH			((uint8_t) 255)
#define PERSON_TOOLS_NAME_MIN_LENGTH			((uint8_t)   1)

/* age limitation */
#define PERSON_TOOLS_AGE_MAX_VALUE				((uint16_t) 65)
#define PERSON_TOOLS_AGE_MIN_VALUE				((uint16_t)  7)

/* average score on the assesment limitation */
#define PERSON_TOOLS_AVERAGE_SCORE_MAX_VALUE	((double) 100.0)
#define PERSON_TOOLS_AVERAGE_SCORE_MIN_VALUE	((double)   0.0)
#define PERSON_TOOLS_AVERAGE_SCORE_PRECISION	((double)   0.01)

/*--------------------- CLASS PERSON ------------------------*/


class Person
{
private: 
	string		firstName;	//имя
	string		lastName;	//фамилия
	string		patronymic;	//отчество
	uint16_t	age;		//возраст
	double		averageScoreAssesment;//средний бал

private:
	Person(string mFirstName, string mLastName, string mPatronymic, uint16_t mAge, double mAverageScoreAssesment);

public:
	Person();
	~Person();

// get/set
public:
	string		getFirstName();
	bool		setFirstName(string firstName);

	string		getLastName();
	bool		setLastName(string lastName);

	string		getPatronymic();
	bool		setPatronymic(string patronymic);

	uint16_t	getAge();
	bool		setAge(uint16_t age);
 
	double		getAverageScoreAssesment();
	bool		setAverageScoreAssesment(double averageScore);

//private behavior
private:
	static double round(double in_raw, double in_precision);

	template <typename T, typename L>
	static bool isInRange(T in_value, L in_minLimit, L in_maxLimit);

	template <typename D>
	static bool isInRange(D in_value, D in_minLimit, D in_maxLimit);

//public behavior
public:
	void	toPrint();
	
	static bool	   calcAgeAverageArrOfPersons(Person* in_arrayPersons, uint32_t in_arrayPersonsSize, uint16_t* out_result);
	static Person* createNewPerson(string firstName, string lastName, string patronymic, uint16_t age, double averageScoreAssesment);
};

#endif // !_PERSON_H_

