#include <stdio.h>
#include <stdlib.h>

typedef struct  s_time_cate
{
        int     year;
        int     month;
        long    days;
        long    hours;
        long    minutes;
        long    seconds;
        short   is_leap;
}       t_time_cate;

short   ft_set_year()
{
        short   year;

        printf("Please enter a year:  ");
        scanf("%hd", &year);
        return (year);
}

short   ft_set_month()
{
        short   month;

        system("clear");
        printf("Please enter a month:  ");
        scanf("%hd", &month);
        return (month);
}

short   ft_check_is_a_leap_year(short year)
{
        return ((year % 400 == 0) || ((year % 4) == 0 && (year % 100) != 0));
}

t_time_cate     ft_set_time_categories(short year, short month)
{
        t_time_cate	the_time_cate_t;
        short	days_nbrs_in_months[13] = {-1 , 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        the_time_cate_t.year = year;
        the_time_cate_t.month = month;
        the_time_cate_t.is_leap = ft_check_is_a_leap_year(the_time_cate_t.year);
		(the_time_cate_t.days) = ((the_time_cate_t.month) == 2) ? (the_time_cate_t.is_leap ? 29 : 28) : days_nbrs_in_months[the_time_cate_t.month];
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

int     main ()
{
        ft_display_time_categories_of_a_year(ft_set_time_categories(ft_set_year(), ft_set_month()));
        return (0);
}
