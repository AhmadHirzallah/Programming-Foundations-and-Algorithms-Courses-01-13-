#include <iostream>
#include <cctype>
#include "my_time_lib.h"

using namespace std;
using namespace my_time_lib;
/*
int	ft_set_nbr_general(string message)
{
	int	nbr;

	printf("%s", message.c_str());
	cin >> nbr;
	return (nbr);
}

s_date	ft_increase_date_by_x_days(int x_days_nbr ,s_date date_s)
{
	int	i;

	i = 0;
	while (++i <= x_days_nbr)
		date_s = ft_increase_date_by_1_day(date_s);
	return (date_s);
}
*/
int	main(void)
{
	s_date	date_s;

	date_s = ft_read_date_s();
	printf("The date before:  %hd/%hd/%hd\n\n", date_s.day, date_s.month, date_s.year);
	date_s = ft_increase_date_by_x_days(ft_set_nbr_general("Please enter how many days you want to add:  "), date_s);
	printf("\nThe date after:  %hd/%hd/%hd\n\n", date_s.day, date_s.month, date_s.year);


	return (0);
}
