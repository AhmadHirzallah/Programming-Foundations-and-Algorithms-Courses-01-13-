#include <iostream>
#include "my_time_lib.h"

using namespace std;
using namespace my_time_lib;
/*
s_date	ft_increase_date_by_1_month(s_date date_s)
{
	short	month_days_nbr;

	if (date_s.month == 12)
	{
		date_s.month = 1;
		(date_s.year)++;
	}
	else
		(date_s.month)++;
	month_days_nbr = ft_nbr_of_days_in_a_month(date_s);
	if (month_days_nbr < date_s.day)
		date_s.day = month_days_nbr;
	return (date_s);
}
*/
int	main (void)
{
	s_date  date_s;

	date_s = ft_read_date_s();
	printf("\n\nThe date before:  %hd/%hd/%hd\n\n", date_s.day, date_s.month, date_s.year);
	date_s = ft_increase_date_by_1_month(date_s);
	printf("\nThe date after:  %hd/%hd/%hd\n\n", date_s.day, date_s.month, date_s.year);
	return (0);
}
