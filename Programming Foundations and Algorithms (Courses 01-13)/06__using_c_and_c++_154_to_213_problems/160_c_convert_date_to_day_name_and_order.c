#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_date
{
	short	day;
	short	month;
	short	year;
}	t_date;

typedef	struct	s_extracted_date_info
{
	short	day_grgian_order;
	char	*day_name;
	char	*formatted_date;

}	t_extracted_date_info;

short	ft_set_day()
{
	short	day;

	printf("\nPlease enter the day:  ");
	scanf("%hd", &day);
	return (day);
}

short	ft_set_month()
{
	short	month;

	printf("\nPlease enter the month:");
	printf("\n(1 for January, 2 for February, 3 for March, 4 for April, 5 for May, 6 for June, 7 for July, 8 for August, 9 for September, 10 for October, 11 for November, 12 for December): ");
	scanf("%hd", &month);
	return (month);
}

short	ft_set_year()
{
	short	year;

	printf("Please enter the year:  ");
	scanf("%hd", &year);
	return (year);
}

t_date	ft_set_entered_date(t_date entered_date)
{
	system("clear");
	entered_date.year = ft_set_year();
	entered_date.month = ft_set_month();
	entered_date.day = ft_set_day();
	return (entered_date);
}

short	ft_calculate_day_order_in_gregorian_calendar(t_date entered_date)
{
	short	day_order;
	short	a;
	short	y;
	short	m;

	a = ((14 - entered_date.month) / 12);
	y = (entered_date.year - a);
	m = (entered_date.month + (12 * a) - 2);

	day_order = (entered_date.day + y + (y / 4)  - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return (day_order);
}

char	*ft_set_day_name_by_day_gergorian_order(short day_grgian_order)
{
	char *days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

	return (days[day_grgian_order]);
}

char	*ft_set_date_format(t_date entered_date)
{
	char	*date_format;

	date_format = malloc(sizeof(char) * 11);
	if (date_format != NULL)
		sprintf(date_format, "%02d/%02d/%04d", entered_date.day, entered_date.month, entered_date.year);
	return (date_format);
}

t_extracted_date_info	ft_set_day_order_and_name_and_format(t_date entered_date)
{
	t_extracted_date_info	date_info;

	date_info.day_grgian_order = ft_calculate_day_order_in_gregorian_calendar(entered_date);
	date_info.day_name = ft_set_day_name_by_day_gergorian_order(date_info.day_grgian_order);
	date_info.formatted_date = ft_set_date_format(entered_date);
	return (date_info);
}

void	ft_get_formatted_date(char *formatted_date)
{
	printf("\n\nDate\t\t: %s\n", formatted_date);
}

void	ft_get_day_order(short day_order)
{
	printf("Day Order\t: %hd\n", day_order);
}

void	ft_get_day_name(char *day_name)
{
	printf("Day Name:\t: %s\n\n", day_name);
}

void	ft_display_extracted_data(t_extracted_date_info date_info)
{
	ft_get_formatted_date(date_info.formatted_date);
	ft_get_day_order(date_info.day_grgian_order);
	ft_get_day_name(date_info.day_name);
}

int	main (void)
{
	t_date	entered_date;
	t_extracted_date_info date_info;

	entered_date = ft_set_entered_date(entered_date);
	date_info = ft_set_day_order_and_name_and_format(entered_date);
	ft_display_extracted_data(date_info);
	return (0);
}
