#include <iostream>
using namespace std;

bool	ft_is_leap_year(short year) 
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

short	ft_day_of_week_order(short day, short month, short year) 
{
    short	a, y, m;

    a = (14 - month) / 12;
    y = year - a;
    m = month + (12 * a) - 2;
    return ((day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7);
}

string	ft_day_short_name(short day_of_week_order) 
{
    string	arr_day_names[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

    return (arr_day_names[day_of_week_order]);
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
    int	number_of_days;
    int	current;
	short	i;
	
	current = ft_day_of_week_order(1, month, year);
    number_of_days = ft_nbr_of_days_in_a_month(month, year);

    printf("\n  _______________%s_______________\n\n", ft_month_short_name(month).c_str());
    printf("   Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
    for (i = 0; i < current; i++) {
        printf("     ");
    }
    for (int j = 1; j <= number_of_days; j++) 
	{
        printf("%5d", j);
        if (++i == 7) {
            i = 0;
            printf("\n\n");
        }
    }
    printf("\n  _________________________________\n");
}

short	ft_read_month() 
{
    short	month;

    cout << "\nPlease enter a Month? ";
    cin >> month;
    return (month);
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
    short	year = ft_read_year();
    short	month = ft_read_month();

    ft_print_month_calendar(month, year);
    return (0);
}
