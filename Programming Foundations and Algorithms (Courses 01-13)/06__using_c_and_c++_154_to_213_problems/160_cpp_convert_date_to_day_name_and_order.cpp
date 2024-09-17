#include <iostream>
#include <string>
using namespace std;

short	ft_day_of_week_order(short day, short month, short year) 
{
    short a;
    short y;
    short m;
    
    a = ((14 - month) / 12);
    y = (year - a);
    m = (month + (12 * a) - 2);
    
    return ((day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7);
}

string	ft_day_short_name(short day_of_week_order) 
{
    string arr_day_names[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    
    return (arr_day_names[day_of_week_order]);
}

short	ft_read_day() 
{
    short day;
    
    cout << "\nPlease enter a Day? ";
    cin >> day;    
    return (day);
}

short ft_read_month() 
{
    short month;
    
    cout << "\nPlease enter a Month? ";
    cin >> month;    
    return (month);
}

short ft_read_year() 
{
    short year;
    
    cout << "\nPlease enter a year? ";
    cin >> year;
    return (year);
}

int main() 
{
    short year;
    short month;
    short day;
    
	system("clear");
    year = ft_read_year();
    month = ft_read_month();
    day = ft_read_day();
    cout << "\nDate      : " << day << "/" << month << "/" << year;
    cout << "\nDay Order : " << ft_day_of_week_order(day, month, year);
    cout << "\nDay Name  : " << ft_day_short_name(ft_day_of_week_order(day, month, year)) << endl << endl;
    return (0);
}

