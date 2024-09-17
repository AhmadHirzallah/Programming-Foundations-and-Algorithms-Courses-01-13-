#include <iostream>
using namespace std;

bool	ft_is_leap_year(short year) 
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

short	ft_nbr_of_days_in_a_month(short month, short year) 
{
    short	days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month < 1 || month > 12)
        return (0);
    return ((month == 2) ? (ft_is_leap_year(year) ? 29 : 28) : days[month - 1]);
}

short	ft_nbr_of_days_from_the_beginning_of_the_year(short day, short month, short year) 
{
    short	total_days;
	
	total_days = 0;
    for (int i = 1; i <= month - 1; i++)
        total_days += ft_nbr_of_days_in_a_month(i, year);
    total_days += day;
    return (total_days);
}

short	ft_read_day() {
    short	day;

    cout << "\nPlease enter a Day? ";
    cin >> day;
    return (day);
}

short	ft_read_month() 
{
    short	month;

    cout << "\nPlease enter a Month? ";
    cin >> month;
    return (month);
}

short ft_read_year() {
    short	year;
    cout << "\nPlease enter a Year? ";
    cin >> year;
    return (year);
}

int main() 
{
	system("clear");

    short	day = ft_read_day();
    short	month = ft_read_month();
    short	year = ft_read_year();


    cout << "\nNumber of Days from the beginning of the year is "
         << ft_nbr_of_days_from_the_beginning_of_the_year(day, month, year) << endl << endl;
    return (0);
}
