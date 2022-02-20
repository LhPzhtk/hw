/*
*										ЗАДАЧА 1
* 
* 1. Реализовать класс Person, содержащий члены для хранения ФИО, возраста, average score on the assesment.
* 2. Определить массив объектов.
* 3. Разработать сортировку массива по среднему баллу и нахождение среднего возраста всех объектов класса Person.
*/

#include "task1.h"
#include <iostream>
#include <string>
#include <array>
#include <algorithm> // std::sort
#include "Person.h"

using namespace std;


struct PersonInit
{
    string		firstName;//имя
    string		lastName;//фамилия
    string		patronymic;//отчество
    uint16_t	age;//возраст
    double		averageScoreAssesment;//средний бал
};

struct PersonInit personsArrayIni[] = {
    {"Еатерина",    "Скрипач",      "Сергеевна",    21u, 73.0},
    {"Анастасия",   "Меньшова",     "Андреевна",    27u, 67.72},
    {"Елена",       "Яковлева",     "Эдуардовна",   31u, 84.849},
    {"Эдуард",      "Бунос",        "Сергеевич",    19u, 88.1236},
    {"Иннокентий",  "Смоктуновский","Альбертович",  35u, 56.1},
    {"Дмитрий",     "Токарев",      "Анатольевич",  41u, 81.844},
    {"Василий",     "Лашкевич",     "Игоревич",     28u, 76.927},
};

#define ERROR_OUT   cerr << "ERROR: " << __FILE__ << " #" << __LINE__ << endl;


void task1()
{
uint16_t ageAverage = 0;

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Task 1 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "1. Реализовать класс Person, содержащий члены для хранения ФИО, возраста, \n   average score on the assesment.\n";
	cout << "2. Определить массив объектов.\n";
	cout << "3. Разработать сортировку массива по среднему баллу и нахождение среднего \n   возраста всех объектов класса Person.\n\n";
    
    //------------------------------------------------------------------------------------------
    cout << " ------------------------------------ Example with simple array ------------------------------------" << endl;

    Person persons[SIZE_OF_ARRAY(personsArrayIni)];//Обычный массив (ниже - см. std::array)

    for (uint32_t i = 0; i < SIZE_OF_ARRAY(personsArrayIni); ++i)
    {
        if (!persons[i].setFirstName(personsArrayIni[i].firstName))
        {
            ERROR_OUT;
        }

        if (!persons[i].setLastName(personsArrayIni[i].lastName))
        {
            ERROR_OUT;
        }

        if (!persons[i].setPatronymic(personsArrayIni[i].patronymic))
        {
            ERROR_OUT;
        }

        if (!persons[i].setAge(personsArrayIni[i].age))
        {
            ERROR_OUT;
        }

        if (!persons[i].setAverageScoreAssesment(personsArrayIni[i].averageScoreAssesment))
        {
            ERROR_OUT;
        }

        persons[i].toPrint();
    }


    
    if (Person::calcAgeAverageArrOfPersons(persons, SIZE_OF_ARRAY(personsArrayIni), &ageAverage))
    {
        cout << "\nСреднй возраст всех персон = " << ageAverage << " лет." << endl;
    }

    
    //--------------------------------------------------------------------------------------
    cout << "\n\n ------------------------------------ Example with std::array ------------------------------------" << endl;

    std::array<Person*, SIZE_OF_ARRAY(personsArrayIni)> arrPerson;

    for (uint32_t i = 0; i < SIZE_OF_ARRAY(personsArrayIni); ++i)
    {
        arrPerson[i] = Person::createNewPerson(personsArrayIni[i].firstName,
            personsArrayIni[i].lastName, 
            personsArrayIni[i].patronymic, 
            personsArrayIni[i].age, 
            personsArrayIni[i].averageScoreAssesment);
    }

    //сортировать массив объектов Person по среднему баллу с помощью лямбда
    std::sort(arrPerson.begin(), arrPerson.end(), [](Person* a, Person* b) {
        return a->getAverageScoreAssesment() > b->getAverageScoreAssesment();
        }
    );

    cout << "\nСортировка по среднему баллу выполнена.\n" << endl;

    for (auto& iPerson : arrPerson)
    {
        iPerson->toPrint();
    }

    if (Person::calcAgeAverageArrOfPersons(persons, SIZE_OF_ARRAY(personsArrayIni), &ageAverage))
    {
        cout << "\nСреднй возраст всех персон = " << ageAverage << " лет." << endl;
    }

    //Освободить ресурсы
    for (auto& iPerson : arrPerson)
    {
        delete iPerson;
    }
}