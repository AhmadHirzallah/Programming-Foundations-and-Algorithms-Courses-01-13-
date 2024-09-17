#include <iostream>
#include "my_time_lib.h"

using namespace std;
using namespace my_time_lib;

s_date	ft_add_days_to_a_date(int nbr_of_adding_days, s_date prev_date_s)
{
	short	remaining_days;
	short	month_days;

	remaining_days = (ft_nbr_of_days_from_the_beginning_of_the_year(prev_date_s) + nbr_of_adding_days);
	prev_date_s.month = 1;
	while (1)
	{
		month_days = ft_nbr_of_days_in_a_month(prev_date_s);
		if (remaining_days > month_days)
		{
			remaining_days -= month_days;
			(prev_date_s.month)++;
			if((prev_date_s.month) > 12)
			{
				(prev_date_s.month) = 1;
				(prev_date_s.year)++;
			}
		}
		else 
		{
			prev_date_s.day = remaining_days;
			break;
		}
	}
	return (prev_date_s);
}

s_date	ft_read_date_s()
{
	s_date  date_s;

	date_s.day = ft_read_day();
	date_s.month = ft_read_month();
	date_s.year = ft_read_year();
	return (date_s);
}

int	ft_set_nbr_of_adding_days()
{
	int	nbr_of_adding_days;

	printf("\n\nPlease enter how many days you want to add:  ");
	cin >> nbr_of_adding_days;
	return (nbr_of_adding_days);
}

int	main (void)
{
	s_date	date_s;

	date_s = ft_read_date_s();
	date_s = ft_add_days_to_a_date(ft_set_nbr_of_adding_days(), date_s);
	printf("\n\nThe date after adding the days is:   %hd/%hd/%hd\n\n", date_s.day, date_s.month, date_s.year);



	return (0);
}
