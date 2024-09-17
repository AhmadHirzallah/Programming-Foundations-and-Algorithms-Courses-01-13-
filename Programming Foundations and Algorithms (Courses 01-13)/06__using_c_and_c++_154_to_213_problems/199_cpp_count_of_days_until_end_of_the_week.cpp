#include <iostream>
#include "my_time_lib.h"

using namespace std;
using namespace my_time_lib;

/*
short	ft_count_of_days_until_the_end_of_week(s_date date_s)
{
	short	days_count;
	short	day_order;

	day_order = ft_day_of_week_order(date_s);
	days_count = 0;
	while (day_order != 6)
		++days_count;
	return (days_count);
}
*/

int     main(void)
{
        s_date  current_system_date_s;

        current_system_date_s = ft_set_current_date_by_system();
        printf("Today is: ( %s ), %hd/%hd/%hd\n\n", ft_day_short_name(ft_day_of_week_order(current_system_date_s)).c_str(), current_system_date_s.day, current_system_date_s.month, current_system_date_s.year);
		printf("The days count until the end of the week:  (%hd)\n\n", ft_count_of_days_until_the_end_of_week(current_system_date_s));
        return (0);
}
