#include <iostream>
#include "my_time_lib.h"

using namespace std;
using namespace my_time_lib;

/*
void	ft_swap_dates_s(s_date &date1_s, s_date &date2_s)
{
	s_date	tmp_date_s;
	
	tmp_date_s.day = date1_s.day;
	tmp_date_s.month = date1_s.month;
	tmp_date_s.year = date1_s.year;
	date1_s.day = date2_s.day;
	date1_s.month = date2_s.month;
	date1_s.year = date2_s.year;
	date2_s.day = tmp_date_s.day;
	date2_s.month = tmp_date_s.month;
	date2_s.year = tmp_date_s.year;
}

int	ft_calculate_diff_in_days_between_2dates_advanced(s_date date1_s, s_date date2_s, bool include_last_day = true)
{
	int     days_diff;
	short	swap_falg;

	swap_falg = 1;
	if (!ft_check_date1_less_than_date2(date1_s, date2_s))
	{
		ft_swap_dates_s(date1_s, date2_s);
		swap_falg = -1;
	}
	days_diff = 0;
	while (!ft_check_date1_equal_date2(date1_s, date2_s))
	{
		days_diff++;
		date1_s = ft_increase_date_by_1_day(date1_s);
	}
	return (swap_falg * (include_last_day ? (days_diff + 1) : (days_diff)));
}
*/

int	main(void)
{
	s_date  date1_s;
	s_date  date2_s;
	int     days_diff;

	printf("\nDate 1:\n\n");
	date1_s = ft_read_date_s();
	printf("\n\nDate 2:\n\n");
	date2_s = ft_read_date_s();
	days_diff = ft_calculate_diff_in_days_between_2dates_advanced(date1_s, date2_s);
	printf("________\nThe days difference (Including last day):  %hd\n\n", days_diff);
	days_diff = ft_calculate_diff_in_days_between_2dates_advanced(date1_s, date2_s, false);
	printf("________\nThe days difference (Excluding last day):  %hd\n\n", days_diff);
	return (0);
}
