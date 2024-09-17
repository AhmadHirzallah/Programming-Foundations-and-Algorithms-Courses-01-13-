#include <iostream>
using namespace std;

bool	ft_is_leap_year(short year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

short	ft_nbr_of_days_in_a_month(short month, short year) 
{
    short arr31_days[8] = {-1 ,1, 3, 5, 7, 8, 10, 12};

    if (month < 1 || month > 12) 
		return (0);
    if (month == 2) 
        return (ft_is_leap_year(year) ? 29 : 28);
    for (short i = 1; i <= 7; i++) 
	{
        if (arr31_days[i] == month)
			return (31);
    }
    return (30);
}

short ft_nbr_of_hours_in_a_month(short month, short year) 
{
    return (ft_nbr_of_days_in_a_month(month, year) * 24);
}

int ft_nbr_of_minutes_in_a_month(short month, short year) 
{
    return (ft_nbr_of_hours_in_a_month(month, year) * 60);
}

int ft_nbr_of_seconds_in_a_month(short month, short year) 
{
    return (ft_nbr_of_minutes_in_a_month(month, year) * 60);
}

short ft_read_month() {
    short month;
    cout << "\nPlease enter a Month to check? ";
    cin >> month;
    return (month);
}

short ft_read_year() {
    short year;
    cout << "\nPlease enter a year to check? ";
    cin >> year;
    return (year);
}

int main() 
{
	system("clear");
    short year; 
    short month;

	year = ft_read_year(); 
	month = ft_read_month();
	printf("\n___________________\n{%d} Year and {%d} Month Information:\n___________________\n", year, month);
    cout << "\nNumber of Days    in Month [" << month << "] is " << ft_nbr_of_days_in_a_month(month, year);
    cout << "\nNumber of Hours   in Month [" << month << "] is " << ft_nbr_of_hours_in_a_month(month, year);
    cout << "\nNumber of Minutes in Month [" << month << "] is " << ft_nbr_of_minutes_in_a_month(month, year);
    cout << "\nNumber of Seconds in Month [" << month << "] is " << ft_nbr_of_seconds_in_a_month(month, year) << endl << endl;
    return (0);
}
