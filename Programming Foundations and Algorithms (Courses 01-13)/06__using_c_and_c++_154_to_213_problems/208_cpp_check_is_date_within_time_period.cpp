#include <iostream>
#include "my_time_lib.h"

using namespace std;
using namespace my_time_lib;
/*
bool	ft_check_is_date_within_time_period(s_date wanted_to_check_date_s, t_s_period period_s)
{
	bool	is_within_result;

	is_within_result = (ft_t_e_compare_dates(wanted_to_check_date_s, period_s.start_date_s) != t_e_date_compare::before
						&& ft_t_e_compare_dates(wanted_to_check_date_s, period_s.end_date_s) != t_e_date_compare::after);
	return (is_within_result);
}
*/
int     main (void)
{
	t_s_period      period_s;
	s_date	wanted_to_check_date_s;

	printf("Enter The Period:\n\n");
	period_s = ft_t_read_period();
	printf("\n\n\nEnter the Date that you want to check:\n\n");
	wanted_to_check_date_s = ft_read_date_s();
	if (ft_check_is_date_within_time_period(wanted_to_check_date_s, period_s))
		printf("\nYes, date is within time period.\n\n");
	else
		printf("\nNo, date is NOT within time period.\n\n");
	return (0);
}
