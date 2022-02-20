/*
*										������ 2
*
* 1. ������� ������-��������� ��� ������ ��������� �������.
* 2. ������� ������-��������� ��� �������� ���������� ������������ ���
*		���������� ���������� ��������� �������.
*/

#include "task2.h"
#include <iostream>
#include <vector>
#include <algorithm> 
#include <iomanip>


void task2()
{
	size_t counter = 0;
	std::vector<double> vD = { 23.50, 87.12, 1.045, 123.76, 9.132, 0.001, 5.89, 12.76, 1.7607, 65.217 };

	std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Task 2 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "1. ������� ������-��������� ��� ������ ��������� �������.\n";
	std::cout << "2. ������� ������-��������� ��� �������� ���������� ������������ ���\n   ���������� ���������� ��������� �������.\n";

	//����� ���������������������� �������
	std::cout << "\n������ ������������������:\n";
	for_each(vD.begin(), vD.end(), [](double d) {std::cout << std::setw(7) << std::right << d << " "; });
	std::cout << std::endl;

	//���������� ��������� �������
	std::sort(vD.begin(), vD.end(), [&counter](double& a, double& b) {
		++counter;//�������� ���������� �������������
		return a < b;
		}
	);

	//����� ���������������� �������
	std::cout << "\n������ ������������:\n";
	for_each(vD.begin(), vD.end(), [](double d) {std::cout << std::setw(7) << std::right << d << " "; });
	std::cout << std::endl;

	//����� ���-�� ������������
	std::cout << "���������� ������������ ��� ���������� = " << counter << std::endl;

}