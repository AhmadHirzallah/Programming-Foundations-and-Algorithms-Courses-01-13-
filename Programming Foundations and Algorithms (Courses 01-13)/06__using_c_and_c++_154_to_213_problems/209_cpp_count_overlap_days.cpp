#include <iostream>
#include "my_time_lib.h"

using namespace std;
using namespace my_time_lib;

/*
int	ft_count_overlap_days_of_2_periods(t_s_period period_s_1, t_s_period period_s_2)
{
	int	overlapped_days_counter;
	int	period1_len;
	int	period2_len;

	if (!ft_check_if_2_periods_overlap(period_s_1, period_s_2))
		return (0);
	period1_len = ft_calculate_period_length_in_days(period_s_1); 
	period2_len = ft_calculate_period_length_in_days(period_s_2); 
	overlapped_days_counter = 0;
	if (period1_len < period2_len)
	{
		while (ft_t_e_compare_dates(period_s_1.start_date_s, period_s_1.end_date_s) == t_e_date_compare::before)
		{
			if (ft_check_is_date_within_time_period(period_s_1.start_date_s, period_s_2))
				(overlapped_days_counter)++;
			(period_s_1.start_date_s) = ft_increase_date_by_1_day(period_s_1.start_date_s);
		}
	}
	else
	{
		while (ft_t_e_compare_dates(period_s_2.start_date_s, period_s_2.end_date_s) == t_e_date_compare::before)
		{
			if (ft_check_is_date_within_time_period(period_s_2.start_date_s, period_s_1))
				(overlapped_days_counter)++;
			(period_s_2.start_date_s) = ft_increase_date_by_1_day(period_s_2.start_date_s);
		}
	}
	return (overlapped_days_counter);
}
*/

int     main (void)
{
	t_s_period	period_s_1;
	t_s_period	period_s_2;

	printf("\nEnter The First Period:\n\n");
	period_s_1 = ft_t_read_period();
	printf("Enter The Second Period:\n\n");
	period_s_2 = ft_t_read_period();
	printf("\n\n*******\nOverlap days count is: (%d)\n\n", ft_count_overlap_days_of_2_periods(period_s_1, period_s_2));
	return (0);
}
