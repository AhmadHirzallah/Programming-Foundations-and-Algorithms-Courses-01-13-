/*
Problem:
Write a program to check if year
is a leap year or not.

Note:
Leap year have 366 not 365 because of Feb month is 29 rather than 28 in it.

All years which are perfectly
divisible by 4 are leap years
except for century years (years
ending with 00), which are leap
years only if they are perfectly
divisible by 400.
*/


#include <stdio.h>
#include <stdlib.h>

short	ft_set_year()
{
	short	year;

	printf("Please enter a year: ");
	scanf("%hd", &year);
	return (year);
}

short	ft_check_is_a_leap_year(short year)
{
	if (year % 400 == 0)
		return (1);
	else if ((year % 4 == 0) && (year % 100 == 0))
		return (0);
	else if (year % 4 == 0)
		return (1);
	else 
		return (0);
}

int	main(void)
{
	short	year;
	short	is_leap_year;

	year = ft_set_year();
	if (is_leap_year = ft_check_is_a_leap_year(year))
		printf("\nYes; The year `%hd` is a Leap Year.\n", year);
	else 
		printf("\nNo; The year `%hd` isn't a Leap Year.\n", year);

	return (0);
}
