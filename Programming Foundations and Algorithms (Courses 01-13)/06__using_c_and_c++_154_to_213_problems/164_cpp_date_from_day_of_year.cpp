#include <iostream>
#include "my_time_lib.h"

using namespace std;
using namespace my_time_lib;

s_date	ft_date_from_day_of_year(short days_nbr_frm_year_beginning, short year)
{
	s_date	final_date_s;
	int	remaining_days;
	short	month_days;

	remaining_days = days_nbr_frm_year_beginning;
	final_date_s.year = year;
	final_date_s.month = 1;
	month_days = 0;
	while (1)
	{
		month_days = ft_nbr_of_days_in_a_month(final_date_s.month, final_date_s.year);
		if (remaining_days > month_days)
		{
			remaining_days -= month_days;
			(final_date_s.month)++;
		}
		else
		{
			(final_date_s.day) = remaining_days;
			break;
		}
	}
	return (final_date_s);
}

int	main(void)
{
	s_date	date_s;

	date_s.day = ft_read_day();
	date_s.month = ft_read_month();
	date_s.year = ft_read_year();
	cout << "_______________________________\n\n";
	cout << "\n\nThe number of days from the beginning of the year:  " << ft_nbr_of_days_from_the_beginning_of_the_year(date_s.day, date_s.month, date_s.year) << endl << endl;
	cout << "_______________________________\n\n";

	date_s = ft_date_from_day_of_year(ft_nbr_of_days_from_the_beginning_of_the_year(date_s.day, date_s.month, date_s.year), date_s.year);
	printf("Date is:	%hd/%hd/%hd\n\n", date_s.day, date_s.month, date_s.year);
	return (0);
}
