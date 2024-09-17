#include <iostream>
#include "my_time_lib.h"

using namespace std;
using namespace my_time_lib;
/*
s_date	ft_decrease_date_by_x_months(int x_months_nbr, s_date date_s)
{
	int	i;
	
	i = 0;
	while (++i <= x_months_nbr)
		date_s = ft_decrease_date_by_one_month(date_s);
	return (date_s);
}
*/

int	main (void)
{
	s_date  date_s;

    date_s = ft_read_date_s();
    printf("\n\nThe date before:  %hd/%hd/%hd\n\n", date_s.day, date_s.month, date_s.year);
    date_s = ft_decrease_date_by_x_months(ft_set_nbr_general("\nPlease enter the number of months which you want to decrease:  "), date_s);
    printf("\nThe date after:  %hd/%hd/%hd\n\n", date_s.day, date_s.month, date_s.year);
    return (0);

}
