#include <stdio.h>
#include <stdlib.h>


typedef struct s_time
{
	long	l_year;
	long	l_days;
	long	l_hours;
	long	l_minutes;
	long	l_seconds;
	short	is_leap;
}	t_time;

short	ft_set_year()
{
	short	year;

	system("clear");
	printf("Please enter a year: ");
	scanf("%hd", &year);
	return (year);
}

short	ft_check_is_a_leap_year(short year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

t_time	ft_get_time_categories_of_a_year(long	l_year)
{
	t_time	time_cate_of_year;

	time_cate_of_year.l_year = l_year;
	time_cate_of_year.is_leap = ft_check_is_a_leap_year(time_cate_of_year.l_year);
	if (time_cate_of_year.is_leap)
		time_cate_of_year.l_days = 366;
	else
		time_cate_of_year.l_days = 365;
	time_cate_of_year.l_hours = (time_cate_of_year.l_days) * 24;
	time_cate_of_year.l_minutes = (time_cate_of_year.l_hours) * 60;
	time_cate_of_year.l_seconds = (time_cate_of_year.l_minutes) * 60;
	return (time_cate_of_year);
}

void	ft_display_time_categories_of_a_year(t_time time_cate_of_year_t)
{
	system("clear");
	printf("\n___________________\nYear Information:\n\n");
	printf("Number of Days in the year {%ld} is:  %ld\n", time_cate_of_year_t.l_year, time_cate_of_year_t.l_days);
	printf("Number of Hours in the year {%ld} is:  %ld\n", time_cate_of_year_t.l_year, time_cate_of_year_t.l_hours);
	printf("Number of Minutes in the year {%ld} is:  %ld\n", time_cate_of_year_t.l_year, time_cate_of_year_t.l_minutes);
	printf("Number of Seconds in the year {%ld} is:  %ld\n", time_cate_of_year_t.l_year, time_cate_of_year_t.l_seconds);
	printf("________________\n\tEnd\n________________\n\n");
}

int	main (void)
{
	ft_display_time_categories_of_a_year(ft_get_time_categories_of_a_year(ft_set_year()));
	return (0);
}


