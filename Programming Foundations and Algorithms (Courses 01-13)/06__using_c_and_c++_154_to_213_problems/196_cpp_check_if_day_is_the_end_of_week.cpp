#include <iostream>
#include "my_time_lib.h"

using namespace std;
using namespace my_time_lib;
/*
bool	ft_check_if_day_is_the_end_of_week(s_date date_s)
{
	short	day_of_week_order;
	
	day_of_week_order = ft_day_of_week_order(date_s);
	return (day_of_week_order == 6);
}
*/
int	main(void)
{
	s_date	current_system_date_s;

	current_system_date_s = ft_set_current_date_by_system();
	printf("Today is: ( %s ), %hd/%hd/%hd\n\n", ft_day_short_name(ft_day_of_week_order(current_system_date_s)).c_str(), current_system_date_s.day, current_system_date_s.month, current_system_date_s.year);
	if (ft_check_if_day_is_the_end_of_week(current_system_date_s))
		printf("Yes, it is the end of the week.\n\n");
	else
		printf("No, it is not the end of the week.\n\n");
	return (0);
}
