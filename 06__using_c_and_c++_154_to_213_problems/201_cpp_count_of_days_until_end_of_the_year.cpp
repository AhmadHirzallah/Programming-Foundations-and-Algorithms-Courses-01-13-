#include <iostream>
#include "my_time_lib.h"

using namespace std;
using namespace my_time_lib;


/*
short   ft_count_of_days_until_end_of_the_year(s_date date_s)
{
    s_date  year_end_s;
    short   days_count;

	year_end_s.year = date_s.year;
	year_end_s.month = 12;
	year_end_s.day = 31;
	if (ft_check_date1_equal_date2(date_s, year_end_s))
		return (0);
    days_count = ft_calculate_diff_in_days_between_2dates_advanced(date_s, year_end_s);
    return (days_count);
}
*/

int     main(void)
{
        s_date  current_system_date_s;

        current_system_date_s = ft_set_current_date_by_system();
        printf("Today is: ( %s ), %hd/%hd/%hd\n\n", ft_day_short_name(ft_day_of_week_order(current_system_date_s)).c_str(), current_system_date_s.day, current_system_date_s.month, current_system_date_s.year);
                printf("The days count until the end of the year:  (%hd)\n\n", ft_count_of_days_until_end_of_the_year(current_system_date_s));
        return (0);
}
