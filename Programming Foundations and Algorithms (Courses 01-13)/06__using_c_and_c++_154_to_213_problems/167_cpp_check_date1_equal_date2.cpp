#include <iostream>
#include "my_time_lib.h"

using namespace std;
using namespace my_time_lib;

bool	ft_check_date1_equal_date2(s_date date1, s_date date2)
{
	return ((date1.year == date2.year) && (date2.month == date1.month) && (date1.day == date2.day)) ? true : false;
}

int	main(void)
{
	s_date  date1;
	s_date  date2;

    date1 = ft_read_date_s();
    date2 = ft_read_date_s();
	if (ft_check_date1_equal_date2(date1, date2))
		printf("\n\nYes, Date1 Equals Date2\n\n");
	else
		printf("\n\nNo, Date1 ISN'T Equals Date2\n\n");
	return (0);
}
