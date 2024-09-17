#include <iostream>
#include "my_time_lib.h"

using namespace std;
using namespace my_time_lib;

/*
int	ft_calculate_vacation_period_days(s_date vacation_start_date_s, const s_date &vacation_end_date_s)
{
	int	count_of_vacation_days;

	count_of_vacation_days = 0;
	while(!ft_check_date1_equal_date2(vacation_start_date_s, vacation_end_date_s))
	{
		if (ft_check_is_a_business_day(vacation_start_date_s))
			count_of_vacation_days++;
		vacation_start_date_s = ft_increase_date_by_1_day(vacation_start_date_s);
	}
	return (count_of_vacation_days);
}

void	ft_get_and_display_vacation_info(s_date vacation_start_date_s, s_date vacation_end_date_s)
{
	string	day_short_name;

	day_short_name = ft_day_short_name(ft_day_of_week_order(vacation_start_date_s));
	printf("\n\n\nVacation From: ( %s ), %hd/%hd/%hd\n\n", day_short_name.c_str(), vacation_start_date_s.day, vacation_start_date_s.month, vacation_start_date_s.year);
	day_short_name = ft_day_short_name(ft_day_of_week_order(vacation_end_date_s));
	printf("Vacation To: ( %s ), %hd/%hd/%hd\n\n", day_short_name.c_str(), vacation_end_date_s.day, vacation_end_date_s.month, vacation_end_date_s.year);
}

void	ft_set_vacation_info(s_date &vacation_start_date_s, s_date &vacation_end_date_s)
{
	printf("\nVacation Start:  ");
	vacation_start_date_s = ft_read_date_s();
	printf("\n\nVacation End:  ");
	vacation_end_date_s = ft_read_date_s();
}
*/
int	main (void)
{
	s_date	vacation_start_date_s;
	s_date	vacation_end_date_s;

	ft_set_vacation_info(vacation_start_date_s, vacation_end_date_s);
	ft_get_and_display_vacation_info(vacation_start_date_s, vacation_end_date_s);
	printf("Actual Vacation Days Number is:  ( %d ).\n\n", ft_calculate_vacation_period_days(vacation_start_date_s, vacation_end_date_s));
	return (0);
}
