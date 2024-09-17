#include <iostream>
#include "my_time_lib.h"

using namespace std;
using namespace my_time_lib;

/*
bool	ft_check_is_a_business_day(s_date date_s)
{
	return (!ft_check_is_a_weekend_day(date_s));
}
*/

int     main(void)
{
        s_date  current_system_date_s;

        current_system_date_s = ft_set_current_date_by_system();
        printf("Today is: ( %s ), %hd/%hd/%hd\n\n", ft_day_short_name(ft_day_of_week_order(current_system_date_s)).c_str(), current_system_date_s.day, current_system_date_s.month, current_system_date_s.year);
        if (ft_check_is_a_business_day(current_system_date_s))
                printf("Yes, it is a business day.\n\n");
        else
                printf("No, it is not a business day.\n\n");
        return (0);
}
