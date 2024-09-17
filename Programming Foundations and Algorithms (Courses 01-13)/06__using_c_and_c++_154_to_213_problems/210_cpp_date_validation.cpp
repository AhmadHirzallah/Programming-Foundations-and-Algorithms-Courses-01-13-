#include <iostream>
#include "my_time_lib.h"

using namespace std;
using namespace my_time_lib;
/*
bool	ft_validate_a_date(s_date date_s)
{
	if (date_s.month >= 13 || date_s.month <= 0)
		return (false);
	else if (date_s.day > ft_nbr_of_days_in_a_month(date_s)
			|| date_s.day < 1)
		return (false);
	else
		return (true);
}
*/
int     main (void)
{
        s_date	date_s;

        printf("\n\n\nEnter the Date:\n\n");
        date_s = ft_read_date_s();
        if (ft_validate_a_date(date_s))
                printf("\nYes, date is a validate date.\n\n");
        else
                printf("\nNo, date is NOT a validate data.\n\n");
        return (0);
}
