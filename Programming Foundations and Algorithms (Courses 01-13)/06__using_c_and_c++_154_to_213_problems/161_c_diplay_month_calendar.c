#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct  s_extracted_date_info
{
        short   day_grgian_order;
		short	month_days_nbr;
        char    *day_name;
        char    *formatted_date;

}       t_extracted_date_info;

typedef struct  s_date
{
        short   day;
        short   month;
        short   year;
}       t_date;

short   ft_calculate_day_order_in_gregorian_calendar(t_date entered_date)
{
        short   day_order;
        short   a;
        short   y;
        short   m;

        a = ((14 - entered_date.month) / 12);
        y = (entered_date.year - a);
        m = (entered_date.month + (12 * a) - 2);
        day_order = (entered_date.day + y + (y / 4)  - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
        return (day_order);
}

short   ft_check_is_a_leap_year(short year)
{
	return ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)));
}

short	ft_get_nbr_of_days_in_month(short year, short month)
{
	short	month_days_nbr;
	short   days_nbrs_in_months[13] = {-1 , 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	month_days_nbr = ((month == 2) ? (ft_check_is_a_leap_year(year) ? 29 : 28) : days_nbrs_in_months[month]);
	return (month_days_nbr);
}

char    *ft_set_day_name_by_day_gergorian_order(short day_grgian_order)
{
        char *days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

        return (days[day_grgian_order]);
}

short   ft_set_month()
{
        short   month;

        printf("\nPlease enter the month:");
        printf("\n(1 for January, 2 for February, 3 for March, 4 for April, 5 for May, 6 for June, 7 for July, 8 for August, 9 for September, 10 for October, 11 for November, 12 for December): ");
        scanf("%hd", &month);
        return (month);
}

short   ft_set_year()
{
        short   year;

        printf("Please enter the year:  ");
        scanf("%hd", &year);
        return (year);
}

char	*ft_month_short_name(short month_number) 
{
    char *months[] = 
	{
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    return (months[month_number - 1]);
}

void	ft_read_date_and_display_calendar_of_month()
{
	t_date	entered_date;
	t_extracted_date_info	info_t;
	short	starting_with_spaces;
	short	calender_day_set;
	
	system("clear");
	entered_date.day = 1;
	entered_date.year = ft_set_year();
	entered_date.month = ft_set_month();

	info_t.day_grgian_order = ft_calculate_day_order_in_gregorian_calendar(entered_date);
	info_t.month_days_nbr = ft_get_nbr_of_days_in_month(entered_date.year, entered_date.month);
	printf("\n  _______________[%s]_______________\n\n", ft_month_short_name(entered_date.month));
	/* Print the columns */

	printf("   Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
	starting_with_spaces = -1;
	while (++starting_with_spaces < info_t.day_grgian_order)
		printf("     ");
	calender_day_set = 0;
	while (++calender_day_set <= info_t.month_days_nbr)
	{
		printf("%5hd", calender_day_set);
		if (++starting_with_spaces == 7)
		{
			starting_with_spaces = 0;
			printf("\n\n");
		}
	}
	printf("\n  ___________________________________\n");
}

int	main ()
{
	ft_read_date_and_display_calendar_of_month();
	return (0);
}
