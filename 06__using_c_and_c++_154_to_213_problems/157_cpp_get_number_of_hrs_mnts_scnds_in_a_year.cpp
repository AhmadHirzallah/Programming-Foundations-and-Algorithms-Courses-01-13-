#include <iostream>
#include <cctype>

using namespace std;

bool	ft_is_leap_year(short year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short	ft_nbr_of_days_in_a_year(short year) 
{
    return (ft_is_leap_year(year) ? 366 : 365);
}

short	ft_nbr_of_hours_in_a_year(short year) 
{
    return (ft_nbr_of_days_in_a_year(year) * 24);
}

int	ft_nbr_of_minutes_in_a_year(short year) 
{
    return (ft_nbr_of_hours_in_a_year(year) * 60);
}

int	ft_nbr_of_seconds_in_a_year(short year) 
{
    return (ft_nbr_of_minutes_in_a_year(year) * 60);
}

short ft_read_year() 
{
    short year;

	system("clear");
    cout << "\nPlease enter a year to check? ";
    cin >> year;
    return year;
}

void    ft_display_time_categories_of_a_year(short year)
{
	system("clear");
	printf("\n___________________\n{%hd} Year Information:\n___________________\n", year);
    cout << "\nNumber of Days    in Year [" << year << "] is " << ft_nbr_of_days_in_a_year(year);
    cout << "\nNumber of Hours   in Year [" << year << "] is " << ft_nbr_of_hours_in_a_year(year);
    cout << "\nNumber of Minutes in Year [" << year << "] is " << ft_nbr_of_minutes_in_a_year(year);
    cout << "\nNumber of Seconds in Year [" << year << "] is " << ft_nbr_of_seconds_in_a_year(year);
	printf("\n________________\n\tEnd\n________________\n\n");
}

int main() 
{
	ft_display_time_categories_of_a_year(ft_read_year());

    return 0;
}
