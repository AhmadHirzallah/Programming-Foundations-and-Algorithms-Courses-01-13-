#include <iostream>

using namespace std;

bool	ft_is_leap_year(short year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

short	ft_day_of_week_order(short day, short month, short year)
{
    short	a;
    short	y;
    short	m;

    a = (14 - month) / 12;
    y = year - a;
    m = month + (12 * a) - 2;
    // Gregorian:
    // 0:sun, 1:Mon, 2:Tue...etc
    return ((day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7);
}

short	ft_nbr_of_days_in_a_month(short month, short year) 
{
    int	days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (month < 1 || month > 12)
        return (0);
    return ((month == 2) ? (ft_is_leap_year(year) ? 29 : 28) : days[month - 1]);
}

string	ft_month_short_name(short month_number) 
{
    string	months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

    return (months[month_number - 1]);
}

void	ft_print_month_calendar(short month, short year) 
{
    short	number_of_days;
    short	current;
	
	current = ft_day_of_week_order(1, month, year);
    number_of_days = ft_nbr_of_days_in_a_month(month, year);

    // Print the current month name
    printf("\n  _______________%s_______________\n\n", ft_month_short_name(month).c_str());
    // Print the columns
    printf("   Sun  Mon  Tue  Wed  Thu  Fri  Sat\n\n");
    // Print appropriate spaces
	short	i;
    for (i = 0; i < current; i++)
        printf("     ");
    for (short j = 1; j <= number_of_days; j++) 
	{
        printf("%5d", j);
        if (++i == 7) 
		{
            i = 0;
            printf("\n\n");
        }
    }
    printf("\n  _________________________________\n");
}

void	ft_print_year_calendar(short year) 
{
    printf("\n  _--_--_________________________________--_--\n\n");
    printf("     \t        Calendar - %d\n", year);
    printf("  _--_--________________________________--_--\n");
    for (short i = 1; i <= 12; i++)
        ft_print_month_calendar(i, year);
    return;
}

short	ft_read_year() 
{
    short	year;

    cout << "\nPlease enter a year? ";
    cin >> year;
    return (year);
}

int main() 
{
	system("clear");
    ft_print_year_calendar(ft_read_year());
    return (0);
}
