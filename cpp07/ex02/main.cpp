#include <iostream>
#include <string>
#include <stdlib.h>
#include "Array.hpp"

#define MAX_VAL 10 
int main(void)
{
	std::cout << "-----REGULAR-----" << std::endl;
	{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL]();
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "Numbers: ";
    for (int i = 0; i < MAX_VAL; i++)
        std::cout << numbers[i];
    std::cout << std::endl;
    std::cout << "Mirror: ";
    for (int i = 0; i < MAX_VAL; i++)
        std::cout << mirror[i];
    std::cout << std::endl;
    //SCOPE
    {
        Array<int> tmp = numbers;
    	std::cout << "Tmp: ";
        for (int i = 0; i < MAX_VAL; i++)
			std::cout << tmp[i];
        std::cout << std::endl;
    	std::cout << "Test: ";
        Array<int> test(tmp);
        for (int i = 0; i < MAX_VAL; i++)
			std::cout << test[i];
        std::cout << std::endl;
        tmp = numbers;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
	}

	std::cout << "-----CONSTANT ARRAY-----" << std::endl;

	{
	Array<int> const numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL]();
    std::cout << "Numbers: ";
    for (int i = 0; i < MAX_VAL; i++)
        std::cout << numbers[i];
    std::cout << std::endl;
    std::cout << "Mirror: ";
    for (int i = 0; i < MAX_VAL; i++)
        std::cout << mirror[i];
    std::cout << std::endl;
    //SCOPE
    {
        Array<int> tmp = numbers;
    	std::cout << "Tmp: ";
        for (int i = 0; i < MAX_VAL; i++)
			std::cout << tmp[i];
        std::cout << std::endl;
    	std::cout << "Test: ";
        Array<int> test(tmp);
        for (int i = 0; i < MAX_VAL; i++)
			std::cout << test[i];
        std::cout << std::endl;
        tmp = numbers;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    delete [] mirror;//
	}

    return 0;
}