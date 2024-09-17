#include <iostream>
#include "my_time_lib.h"

using namespace std;
using namespace my_time_lib;
/*
bool    ft_check_is_date1_after_date2(s_date date1, s_date date2)
{
	return ((!ft_check_date1_less_than_date2(date1, date2)) && (!ft_check_date1_equal_date2(date1, date2)));
}
*/
int     main (void)
{
	s_date  date1;
	s_date  date2;

	printf("Please enter Date 1:\n");
	date1 = ft_read_date_s();
	printf("\n\nPlease enter Date 2:\n");
	date2 = ft_read_date_s();
	if (ft_check_is_date1_after_date2(date1, date2))
		printf("\n\nYes, Date 1 is after Date 2\n\n");
	else
		printf("\n\nNo, Date 1 ISNOT after Date 2\n\n");
	return (0);
}
