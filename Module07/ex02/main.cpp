#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp;
        tmp = numbers;
		Array<int> test(tmp);
		for (int i = 0; i < MAX_VAL; i++)
			tmp[i] = rand();
		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != test[i])
			{
				std::cerr << "didn't save the same value!! <1>" << std::endl;
				return 1;
			}
		}
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!! <2>" << std::endl;
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

	Array<int> zero;
	try
	{
		zero[1] = 2;
	}
	catch (std::exception& ex)
	{
		std::cerr << ex.what() << '\n';
	}
	Array<int> zero_two;
	try
	{
		zero_two[0] = 1;
	}
	catch (std::exception& ex)
	{
		std::cerr << ex.what() << '\n';
	}
	Array<int> zero_three;

	return 0;
}
