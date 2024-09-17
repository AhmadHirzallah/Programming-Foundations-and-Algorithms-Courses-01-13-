#include <iostream>
#include "my_time_lib.h"

using namespace std;
using namespace my_time_lib;

s_date	ft_increase_date_by_x_weeks(int x_weeks_nbr, s_date date_s)
{
	int	i;

	i = 0;
	while (++i <= x_weeks_nbr)
		date_s = ft_increase_date_by_1_week(date_s);
	return (date_s);
}

int	main(void)
{
	s_date  date_s;

	date_s = ft_read_date_s();
	printf("\n\nThe date before:  %hd/%hd/%hd\n\n", date_s.day, date_s.month, date_s.year);
	date_s = ft_increase_date_by_x_weeks(ft_set_nbr_general("Please enter the number of weeks:  "), date_s);
	printf("\nThe date after:  %hd/%hd/%hd\n\n", date_s.day, date_s.month, date_s.year);
	return (0);
}
