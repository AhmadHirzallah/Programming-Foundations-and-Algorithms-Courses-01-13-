#include <iostream>
#include "my_time_lib.h"

using namespace std;
using namespace my_time_lib;
/*
s_date ft_set_vacation_info_s()
{
	s_date  vacation_start_date_s;

	printf("\nVacation Start:  \n");
    vacation_start_date_s = ft_read_date_s();
	return (vacation_start_date_s);
}

s_date	ft_set_vacation_return_date_s(int vacation_days_nbr, s_date &vacation_start_date_s)
{
	int	i;

	i = 0;
	while (++i <= vacation_days_nbr)
	{
		if (ft_check_is_a_business_day(vacation_start_date_s))
			vacation_start_date_s = ft_increase_date_by_1_day(vacation_start_date_s);
		else
		{
			i--;
			vacation_start_date_s = ft_increase_date_by_1_day(vacation_start_date_s);
		}
	}
	while (ft_check_is_a_weekend_day(vacation_start_date_s))
		vacation_start_date_s = ft_increase_date_by_1_day(vacation_start_date_s);
	return (vacation_start_date_s);
}
*/
int	main (void)
{
	s_date	vacation_start_date_s;
	s_date	vacation_end_date_s;
	int	vacation_days_nbr;
	string  day_short_name;

	vacation_start_date_s = ft_set_vacation_info_s();
    day_short_name = ft_day_short_name(ft_day_of_week_order(vacation_start_date_s));
	vacation_days_nbr = ft_set_nbr_general("\n\nPlease enter vacation days number:  ");
	printf("\n\n\nVacation From: ( %s ), %hd/%hd/%hd\n\n", day_short_name.c_str(), vacation_start_date_s.day, vacation_start_date_s.month, vacation_start_date_s.year);
	vacation_end_date_s = ft_set_vacation_return_date_s(vacation_days_nbr, vacation_start_date_s);
	day_short_name = ft_day_short_name(ft_day_of_week_order(vacation_end_date_s));
	printf("Vacation To: ( %s ), %hd/%hd/%hd\n\n", day_short_name.c_str(), vacation_end_date_s.day, vacation_end_date_s.month, vacation_end_date_s.year);
	return (0);
}
