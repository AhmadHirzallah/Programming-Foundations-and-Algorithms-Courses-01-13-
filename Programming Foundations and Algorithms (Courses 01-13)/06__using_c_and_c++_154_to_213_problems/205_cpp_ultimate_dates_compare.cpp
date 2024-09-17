#include <iostream>
#include "my_time_lib.h"

using namespace std;
using namespace my_time_lib;
/*
typedef	enum	e_date_compare
{
	before = -1,
	equal = 0,
	after = 1
}	t_e_date_compare;

t_e_date_compare	ft_t_e_compare_dates(s_date date1_s, s_date date2_s)
{
	if (ft_check_is_date1_after_date2(date1_s, date2_s))
		return (t_e_date_compare::after);
	else if (ft_check_date1_equal_date2(date1_s, date2_s))
		return (t_e_date_compare::equal);
	else
		return (t_e_date_compare::before);
}
*/
int     main (void)
{
        s_date  date1;
        s_date  date2;

        printf("Please enter Date 1:\n");
        date1 = ft_read_date_s();
        printf("\n\nPlease enter Date 2:\n");
        date2 = ft_read_date_s();
		printf("\n\nCompare result is: %d\n\n", static_cast<int> (ft_t_e_compare_dates(date1, date2)));
        return (0);
}
