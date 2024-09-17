#include <iostream>
#include "my_time_lib.h"

using namespace std;
using namespace my_time_lib;
/*
int	ft_calculate_period_length_in_days(t_s_period period_s, bool include_last_day = true)
{
	return (ft_calculate_diff_in_days_between_2dates_advanced(period_s.start_date_s, period_s.end_date_s, include_last_day));
}
*/
int     main (void)
{
	t_s_period	period_s;
	int	period_length_in_days;

    printf("Period:\n\n");
	period_s = ft_t_read_period();
	period_length_in_days = ft_calculate_period_length_in_days(period_s);
	printf("\n\nPeriod Length in days including last day:  (%d)\n\n", period_length_in_days);
	period_length_in_days = ft_calculate_period_length_in_days(period_s, false);
	printf("\n\nPeriod Length in days excluding last day:  (%d)\n\n", period_length_in_days);
    return (0);
}
