#include <stdio.h>
#include <stdlib.h>

typedef	struct	s_time_cate
{
	int	year;
	int	month;
	long	days;
	long	hours;
	long	minutes;
	long	seconds;
	short	is_leap;
}	t_time_cate;

short	ft_set_year()
{
	short	year;

	system("clear");
	printf("Please enter a year:  ");
	scanf("%hd", &year);
	return (year);
}

short	ft_set_month()
{
	short	month;

	system("clear");
	printf("Please enter a month:  ");
	scanf("%hd", &month);
	return (month);
}

short	ft_check_is_a_leap_year(short year)
{
	return ((year % 400 == 0) || ((year % 4) == 0 && (year % 100) != 0));
}

void	*ft_set_days_nbrs_in_leap_months(short *days_nbrs_in_leap_month)
{
	days_nbrs_in_leap_month[0] = 0;
    days_nbrs_in_leap_month[1] = 31;
    days_nbrs_in_leap_month[2] = 29;
    days_nbrs_in_leap_month[3] = 31;
    days_nbrs_in_leap_month[4] = 30;
    days_nbrs_in_leap_month[5] = 31;
    days_nbrs_in_leap_month[6] = 30;
    days_nbrs_in_leap_month[7] = 31;
    days_nbrs_in_leap_month[8] = 31;
    days_nbrs_in_leap_month[9] = 30;
    days_nbrs_in_leap_month[10] = 31;
    days_nbrs_in_leap_month[11] = 30;
    days_nbrs_in_leap_month[12] = 31;
}

void	*ft_set_days_nbrs_in_months(short *days_nbrs_in_months)
{
	days_nbrs_in_months[0] = 0;
    days_nbrs_in_months[1] = 31;
    days_nbrs_in_months[2] = 28;
    days_nbrs_in_months[3] = 31;
    days_nbrs_in_months[4] = 30;
    days_nbrs_in_months[5] = 31;
    days_nbrs_in_months[6] = 30;
    days_nbrs_in_months[7] = 31;
    days_nbrs_in_months[8] = 31;
    days_nbrs_in_months[9] = 30;
    days_nbrs_in_months[10] = 31;
    days_nbrs_in_months[11] = 30;
    days_nbrs_in_months[12] = 31;
}

t_time_cate	ft_set_time_categories(short year, short month)
{
	t_time_cate	the_time_cate_t;
	short	*days_nbrs_in_months;
	short	*days_nbrs_in_leap_month;

	days_nbrs_in_months = (short *) malloc(sizeof(short) * 13);
	days_nbrs_in_leap_month = (short *) malloc(sizeof(short) * 13);
	ft_set_days_nbrs_in_months(days_nbrs_in_months);
	ft_set_days_nbrs_in_leap_months(days_nbrs_in_leap_month);
	the_time_cate_t.year = year;
	the_time_cate_t.month = month;
	the_time_cate_t.is_leap = ft_check_is_a_leap_year(the_time_cate_t.year); 
	if (the_time_cate_t.is_leap)
		the_time_cate_t.days = days_nbrs_in_leap_month[the_time_cate_t.month];
	else
		the_time_cate_t.days = days_nbrs_in_months[the_time_cate_t.month];
	the_time_cate_t.hours = (the_time_cate_t.days) * 24;
	the_time_cate_t.minutes = (the_time_cate_t.hours) * 60;
	the_time_cate_t.seconds = (the_time_cate_t.minutes) * 60;
	return (the_time_cate_t);
}

void    ft_display_time_categories_of_a_year(t_time_cate time_cate_of_year_t)
{
        system("clear");
		printf("\n___________________\n{%d} Year and {%d} Month Information:\n___________________\n", time_cate_of_year_t.year, time_cate_of_year_t.month);
        printf("Number of Days is:  %ld\n", time_cate_of_year_t.days);
        printf("Number of Hours is:  %ld\n", time_cate_of_year_t.hours);
        printf("Number of Minutes is:  %ld\n", time_cate_of_year_t.minutes);
        printf("Number of Seconds is:  %ld\n", time_cate_of_year_t.seconds);
        printf("________________\n\tEnd\n________________\n\n");
}

int	main ()
{
	ft_display_time_categories_of_a_year(ft_set_time_categories(ft_set_year(), ft_set_month()));
	return (0);
}

