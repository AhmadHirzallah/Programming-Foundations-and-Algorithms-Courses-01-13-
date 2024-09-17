#include <iostream>
#include "my_time_lib.h"

using namespace std;
using namespace my_time_lib;
/*
s_date	ft_decrease_date_by_x_days(int x_days_nbr, s_date date_s)
{
	int	i;

	i = 0;
	while (++i <= x_days_nbr)
		date_s = ft_decrease_date_by_one_day(date_s);
	return (date_s);
}
*/
int	main (void)
{
	s_date  date_s;

    date_s = ft_read_date_s();
    printf("\n\nThe date before:  %hd/%hd/%hd\n\n", date_s.day, date_s.month, date_s.year);
    date_s = ft_decrease_date_by_x_days(ft_set_nbr_general("\n\nPlease enter the number of days to decrease from the date:  "), date_s);
    printf("\nThe date after:  %hd/%hd/%hd\n\n", date_s.day, date_s.month, date_s.year);
    return (0);

}
