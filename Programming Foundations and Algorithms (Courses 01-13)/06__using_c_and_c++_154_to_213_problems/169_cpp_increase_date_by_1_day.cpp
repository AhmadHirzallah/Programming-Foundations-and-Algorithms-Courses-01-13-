#include <iostream>
#include "my_time_lib.h"

using namespace std;
using namespace my_time_lib;

s_date	ft_increase_date_by_1_day(s_date date)
{
	if (ft_check_is_last_day_in_month(date))
	{
		if(ft_check_is_last_month_in_year(date))
		{
			(date.year)++;
			date.day = 1;
			date.month = 1;
		}
		else
		{
			(date.month)++;
			date.day = 1;
		}
	}
	else
		(date.day)++;
	return (date);
}

int	main (void)
{
	s_date	date_s;

	date_s	= ft_read_date_s();
	printf("\n___________\n\nDate Before: (%hd/%hd/%hd)\n\n", date_s.day, date_s.month, date_s.year);
	date_s = ft_increase_date_by_1_day(date_s);
	printf("\nDate After: (%hd/%hd/%hd)\n\n", date_s.day, date_s.month, date_s.year);
	return (0);
}
