#include <iostream>
#include "my_time_lib.h"

using namespace std;
using namespace my_time_lib;
/*
typedef	struct	s_period
{
	s_date	start_date_s;
	s_date	end_date_s;
}	t_s_period;

t_s_period	ft_t_read_period()
{
	t_s_period	period_s;

	printf("\nPlease enter the start date:\n");
	period_s.start_date_s = ft_read_date_s();
	printf("\n\nPlease enter the end date:\n");
	period_s.end_date_s= ft_read_date_s();
	return (period_s);
}

bool	ft_check_if_2_periods_overlap(t_s_period period1, t_s_period period2)
{
	if (ft_t_e_compare_dates(period1.start_date_s, period2.end_date_s) == t_e_date_compare::after)
		return (false);
	else if (ft_t_e_compare_dates(period1.end_date_s, period2.start_date_s) == t_e_date_compare::before)
		return (false);
	else
		return (true);
}
*/
int	main (void)
{
	t_s_period	period1;
	t_s_period	period2;

	printf("Period 1:\n\n");
	period1 = ft_t_read_period();
	printf("\n\nPeriod 2:\n\n");
	period2 = ft_t_read_period();
	if (ft_check_if_2_periods_overlap(period1, period2))
		printf("\n\nYes, Periods Overlap.\n\n");
	else
		printf("\n\nNo, Periods Aren't Overlapping.\n\n");
	return (0);
}
