// hw_01.cpp : 
// Для корректной работы программы, пожалуйста, выберите "Стандарт ISO C++20 (/std:c++20)" в настройках IDE.

#include <iostream>
#include <locale.h>
#include "task1.h"
#include "task2.h"
#include "task3.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    task1();
    task2();
    task3();
}
