#include <stdio.h>

short	ft_set_year()
{
	short	year;

	printf("Please enter a year: ");
	scanf("%hd", &year);
	return (year);
}

short	ft_check_is_a_leap_year(short year)
{
	return ((year % 400 == 0)? (1) : ((year % 4) == 0 && (year % 100) == 0) ? (0) : ((year % 4) == 0) ? 1 : 0);
}

void	ft_display_is_leap_year_result(short result)
{
	if (result == 1)
		printf("\nYes; This year is a Leap Year.\n");
	else
		printf("\nNo; This year isn't a Leap Year.\n");
}

int	main (void)
{
	ft_display_is_leap_year_result(ft_check_is_a_leap_year(ft_set_year()));
	return (0);
}
