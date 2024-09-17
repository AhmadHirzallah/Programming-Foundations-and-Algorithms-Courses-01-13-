#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
enum	e_numbers_types
{
	odd = 1,
	even = 2
};

void ft_print_number_type(enum e_numbers_types number_type);
enum e_numbers_types ft_check_number_type(int number);

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		ft_print_number_type(ft_check_number_type(atoi(argv[1])));
		return (0);
	}
	else
	{
		printf("ERROR!\n");
		return (1);
	}
}

enum e_numbers_types	ft_check_number_type (int number)
{
	short result;

	result = number % 2; 
	if (result == 0)
		return (even);
	else 
		return (odd);
}

void ft_print_number_type(enum e_numbers_types number_type)
{
	if (number_type == even)
		printf("The number is Even.\n");
	else if (number_type == odd)
		printf("The number is Odd.\n");
}

