/*
*										������ 1
* 
* 1. ����������� ����� Person, ���������� ����� ��� �������� ���, ��������, average score on the assesment.
* 2. ���������� ������ ��������.
* 3. ����������� ���������� ������� �� �������� ����� � ���������� �������� �������� ���� �������� ������ Person.
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
    string		firstName;//���
    string		lastName;//�������
    string		patronymic;//��������
    uint16_t	age;//�������
    double		averageScoreAssesment;//������� ���
};

struct PersonInit personsArrayIni[] = {
    {"��������",    "�������",      "���������",    21u, 73.0},
    {"���������",   "��������",     "���������",    27u, 67.72},
    {"�����",       "��������",     "����������",   31u, 84.849},
    {"������",      "�����",        "���������",    19u, 88.1236},
    {"����������",  "�������������","�����������",  35u, 56.1},
    {"�������",     "�������",      "�����������",  41u, 81.844},
    {"�������",     "��������",     "��������",     28u, 76.927},
};

#define ERROR_OUT   cerr << "ERROR: " << __FILE__ << " #" << __LINE__ << endl;


void task1()
{
uint16_t ageAverage = 0;

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Task 1 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "1. ����������� ����� Person, ���������� ����� ��� �������� ���, ��������, \n   average score on the assesment.\n";
	cout << "2. ���������� ������ ��������.\n";
	cout << "3. ����������� ���������� ������� �� �������� ����� � ���������� �������� \n   �������� ���� �������� ������ Person.\n\n";
    
    //------------------------------------------------------------------------------------------
    cout << " ------------------------------------ Example with simple array ------------------------------------" << endl;

    Person persons[SIZE_OF_ARRAY(personsArrayIni)];//������� ������ (���� - ��. std::array)

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
        cout << "\n������ ������� ���� ������ = " << ageAverage << " ���." << endl;
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

    //����������� ������ �������� Person �� �������� ����� � ������� ������
    std::sort(arrPerson.begin(), arrPerson.end(), [](Person* a, Person* b) {
        return a->getAverageScoreAssesment() > b->getAverageScoreAssesment();
        }
    );

    cout << "\n���������� �� �������� ����� ���������.\n" << endl;

    for (auto& iPerson : arrPerson)
    {
        iPerson->toPrint();
    }

    if (Person::calcAgeAverageArrOfPersons(persons, SIZE_OF_ARRAY(personsArrayIni), &ageAverage))
    {
        cout << "\n������ ������� ���� ������ = " << ageAverage << " ���." << endl;
    }

    //���������� �������
    for (auto& iPerson : arrPerson)
    {
        delete iPerson;
    }
}