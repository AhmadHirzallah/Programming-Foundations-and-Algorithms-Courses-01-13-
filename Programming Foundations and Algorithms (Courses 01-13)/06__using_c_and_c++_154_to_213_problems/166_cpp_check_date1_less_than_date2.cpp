#include <iostream>
#include "my_time_lib.h"

using namespace std;
using namespace my_time_lib;

bool	ft_check_date1_less_than_date2(s_date date1, s_date date2)
{
	return (date1.year < date2.year ? true : (date2.year == date1.year ? (date1.month < date2.month ? true : (date1.day < date2.day)) : false ));
}

int	main (void)
{
	s_date	date1;
	s_date	date2;

	date1 = ft_read_date_s();
	date2 = ft_read_date_s();
	if (ft_check_date1_less_than_date2(date1, date2))
		printf("\n\nYes, Date 1 is less than Date 2\n\n");
	else
		printf("\n\nNo, Date 1 ISNOT less than Date 2\n\n");
	return (0);
}
