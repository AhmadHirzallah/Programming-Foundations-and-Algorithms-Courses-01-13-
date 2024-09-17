#include <iostream>
#include "my_time_lib.h"

using namespace std;
using namespace my_time_lib;

bool	ft_check_is_last_day_in_month(s_date date_s)
{
	return (date_s.day == ft_nbr_of_days_in_a_month(date_s));
}

bool	ft_check_is_last_month_in_year(s_date date_s)
{
	return (date_s.month == 12);
}

int	main(void)
{
	s_date	entered_date_s;

	entered_date_s = ft_read_date_s();
	if (ft_check_is_last_day_in_month(entered_date_s))
		printf("\n\nYes, day is the last day in the month.\n\n");
	else
		printf("\n\nNo, day isn't the last day in the month\n\n");
	if (ft_check_is_last_month_in_year(entered_date_s))
		printf("\n\nYes, Month is the last month in the year.\n\n");
	else
		printf("\n\nNo, Month isn't the last month in the year\n\n");
	return (0);
}
