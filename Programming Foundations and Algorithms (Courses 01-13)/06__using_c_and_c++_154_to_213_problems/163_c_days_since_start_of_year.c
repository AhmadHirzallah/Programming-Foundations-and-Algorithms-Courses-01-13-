#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct  s_extracted_date_info
{
	short   day_grgian_order;
	char    *day_name;
	char    *formatted_date;
	short   nbr_of_month_days;
	short	nbr_of_year_days;

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

short   ft_get_nbr_of_days_in_month(short year, short month)
{
        short   month_days_nbr;
        short   days_nbrs_in_months[13] = {-1 , 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        month_days_nbr = ((month == 2) ? (ft_check_is_a_leap_year(year) ? 29 : 28) : days_nbrs_in_months[month]);
        return (month_days_nbr);
}

char    *ft_set_day_name_by_day_gergorian_order(short day_grgian_order)
{
        char *days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

        return (days[day_grgian_order]);
}

short   ft_set_day()
{
        short   day;

        printf("Please enter the day:  ");
        scanf("%hd", &day);
        return (day);
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

        printf("\nPlease enter the year:  ");
        scanf("%hd", &year);
        return (year);
}

char    *ft_month_short_name(short month_number)
{
    char *months[] =
        {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
		};

    return (months[month_number - 1]);
}

t_date	ft_read_date_data()
{
	t_date	date_s;

	system("clear");
	date_s.day = ft_set_day();
	date_s.month = ft_set_month();
	date_s.year = ft_set_year();
	return (date_s);
}

short	ft_get_nbr_of_year_days_till_month(short year, short month)
{
	short	nbr_of_year_days;
	short	every_month;

	nbr_of_year_days = 0;
	every_month = 0;
	while(++every_month < month)
		nbr_of_year_days += ft_get_nbr_of_days_in_month(year, every_month);
	return (nbr_of_year_days);
}

t_extracted_date_info	ft_set_date_info(t_date date_data_s)
{
	t_extracted_date_info	extracted_date_data;

	extracted_date_data.nbr_of_month_days = ft_get_nbr_of_days_in_month(date_data_s.year , date_data_s.month);
	extracted_date_data.nbr_of_year_days = (ft_get_nbr_of_year_days_till_month(date_data_s.year, date_data_s.month)) + date_data_s.day;
	return (extracted_date_data);
}

int	main()
{
	t_date	date_data_s;
	t_extracted_date_info	extracted_date_data_t;

	date_data_s = ft_read_date_data();
	extracted_date_data_t = ft_set_date_info(date_data_s);
	printf("\n\nNumber of days from the begining of the year is:  \"%hd\"\n\n", extracted_date_data_t.nbr_of_year_days);
	return (0);
}
