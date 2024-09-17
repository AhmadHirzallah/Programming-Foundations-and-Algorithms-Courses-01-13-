#pragma warning(disable : 4996)
#include <iostream>
#include "my_time_lib.h"

using namespace std;
using namespace my_time_lib;
/*
s_date	ft_set_current_date_by_system()
{
	s_date	current_date_s;

	time_t	t = time(0);
	tm	*now = localtime(&t);
	current_date_s.year = now->tm_year + 1900;
	current_date_s.month = now->tm_mon + 1;
	current_date_s.day = now->tm_mday;
	return (current_date_s);
}

int	ft_calculate_age_in_days()
{
	s_date	date_s;
	s_date	current_date_s;
	int	age_days;

	current_date_s = ft_set_current_date_by_system();
	printf("\n\nPlease enter your birth info:\n");
	date_s = ft_read_date_s();
	age_days = ft_calculate_diff_in_days_between_2dates(date_s, current_date_s);
	return (age_days);
}
*/
int	main(void)
{
	int	age_days;

	age_days = ft_calculate_age_in_days();
	printf("\n\nYour Age in days is:  %d Days.\n\n", age_days);
	return (0);
}
