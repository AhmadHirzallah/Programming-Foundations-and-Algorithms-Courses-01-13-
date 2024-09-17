#include "my_time_lib.h"
#include <vector>


namespace my_time_lib {

bool ft_is_leap_year(short year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

short ft_nbr_of_days_in_a_year(short year) {
    return (ft_is_leap_year(year) ? 366 : 365);
}

short ft_nbr_of_hours_in_a_year(short year) {
    return (ft_nbr_of_days_in_a_year(year) * 24);
}

int ft_nbr_of_minutes_in_a_year(short year) {
    return (ft_nbr_of_hours_in_a_year(year) * 60);
}

int ft_nbr_of_seconds_in_a_year(short year) {
    return (ft_nbr_of_minutes_in_a_year(year) * 60);
}

void ft_display_time_categories_of_a_year(short year) {
    system("clear");
    printf("\n___________________\n{%hd} Year Information:\n___________________\n", year);
    cout << "\nNumber of Days    in Year [" << year << "] is " << ft_nbr_of_days_in_a_year(year);
    cout << "\nNumber of Hours   in Year [" << year << "] is " << ft_nbr_of_hours_in_a_year(year);
    cout << "\nNumber of Minutes in Year [" << year << "] is " << ft_nbr_of_minutes_in_a_year(year);
    cout << "\nNumber of Seconds in Year [" << year << "] is " << ft_nbr_of_seconds_in_a_year(year);
    printf("\n________________\n\tEnd\n________________\n\n");
}

short   ft_nbr_of_days_in_a_month(short month, short year)
{
    short	days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month < 1 || month > 12)
        return (0);
    return ((month == 2) ? (ft_is_leap_year(year) ? 29 : 28) : days[month - 1]);
}

short   ft_nbr_of_days_in_a_month(s_date date_s)
{
	return (ft_nbr_of_days_in_a_month(date_s.month, date_s.year));
}

short ft_nbr_of_hours_in_a_month(short month, short year) {
    return (ft_nbr_of_days_in_a_month(month, year) * 24);
}

int ft_nbr_of_minutes_in_a_month(short month, short year) {
    return (ft_nbr_of_hours_in_a_month(month, year) * 60);
}

int ft_nbr_of_seconds_in_a_month(short month, short year) {
    return (ft_nbr_of_minutes_in_a_month(month, year) * 60);
}


short ft_read_day() {
    short day;
    cout << "\nPlease enter a Day:  ";
    cin >> day;
    return (day);
}

short ft_read_month() {
    short month;
    cout << "\nPlease enter a Month:  ";
    cin >> month;
    return (month);
}

short ft_read_year() {
    short year;
    cout << "\nPlease enter a year: ";
    cin >> year;
    return (year);
}

short ft_day_of_week_order(short day, short month, short year) {
    short a, y, m;

    a = (14 - month) / 12;
    y = year - a;
    m = month + (12 * a) - 2;

    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short ft_day_of_week_order(s_date date_s)
{
	return (ft_day_of_week_order(date_s.day, date_s.month, date_s.year));
}

string ft_day_short_name(short day_of_week_order) {
    string arr_day_names[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

    return (arr_day_names[day_of_week_order]);
}

string ft_month_short_name(short month_number) {
    string months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

    return (months[month_number - 1]);
}

void ft_print_month_calendar(short month, short year) 
{
    int number_of_days;
    int current;
    short i;

    current = ft_day_of_week_order(1, month, year);
    number_of_days = ft_nbr_of_days_in_a_month(month, year);

    printf("\n  _______________%s_______________\n\n", ft_month_short_name(month).c_str());
    printf("   Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
    for (i = 0; i < current; i++) {
        printf("     ");
    }
    for (int j = 1; j <= number_of_days; j++) {
        printf("%5d", j);
    printf("\n  _________________________________\n");
}
}

void ft_print_year_calendar(short year) 
{
    printf("\n  _--_--_________________________________--_--\n\n");
    printf("     \t        Calendar - %d\n", year);
    printf("  _--_--________________________________--_--\n");
    for (short i = 1; i <= 12; i++)
        ft_print_month_calendar(i, year);
    return;
}

short ft_nbr_of_days_from_the_beginning_of_the_year(short day, short month, short year) 
{
    short total_days;

	total_days = 0;
    for (int i = 1; i <= month - 1; i++)
        total_days += ft_nbr_of_days_in_a_month(i, year);
    total_days += day;
    return (total_days);
}

short ft_nbr_of_days_from_the_beginning_of_the_year(s_date date_s)
{
	return (ft_nbr_of_days_from_the_beginning_of_the_year(date_s.day, date_s.month, date_s.year));
}

s_extracted_date_info	ft_get_extracted_date_info(s_date date) {
    s_extracted_date_info extracted_info;
    extracted_info.day_grgian_order = ft_day_of_week_order(date.day, date.month, date.year);
    extracted_info.day_name = ft_day_short_name(extracted_info.day_grgian_order);
    extracted_info.formatted_date = to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
    extracted_info.nbr_of_month_days = ft_nbr_of_days_in_a_month(date.month, date.year);
    extracted_info.nbr_of_year_days = ft_nbr_of_days_from_the_beginning_of_the_year(date.day, date.month, date.year);
    return (extracted_info);
}

s_date  ft_date_from_day_of_year(short days_nbr_frm_year_beginning, short year)
{
        s_date  final_date_s;
        int     remaining_days;
        short   month_days;

        remaining_days = days_nbr_frm_year_beginning;
        final_date_s.year = year;
        final_date_s.month = 1;
        month_days = 0;
        while (1)
        {
                month_days = ft_nbr_of_days_in_a_month(final_date_s.month, final_date_s.year);
                if (remaining_days > month_days)
                {
                        remaining_days -= month_days;
                        (final_date_s.month)++;
                }
                else
                {
                        (final_date_s.day) = remaining_days;
                        break;
                }
        }
        return (final_date_s);
}

s_date  ft_add_days_to_a_date(int nbr_of_adding_days, s_date prev_date_s)
{
        short   remaining_days;
        short   month_days;

        remaining_days = (ft_nbr_of_days_from_the_beginning_of_the_year(prev_date_s) + nbr_of_adding_days);
        prev_date_s.month = 1;
        while (1)
        {
                month_days = ft_nbr_of_days_in_a_month(prev_date_s);
                if (remaining_days > month_days)
                {
                        remaining_days -= month_days;
                        (prev_date_s.month)++;
                        if((prev_date_s.month) > 12)
                        {
                                (prev_date_s.month) = 1;
                                (prev_date_s.year)++;
                        }
                }
                else
                {
                        prev_date_s.day = remaining_days;
                        break;
                }
        }
        return (prev_date_s);
}

s_date  ft_read_date_s()
{
        s_date  date_s;

        date_s.day = ft_read_day();
        date_s.month = ft_read_month();
        date_s.year = ft_read_year();
        return (date_s);
}

int     ft_set_nbr_of_adding_days()
{
        int     nbr_of_adding_days;

        printf("\n\nPlease enter how many days you want to add:  ");
        cin >> nbr_of_adding_days;
        return (nbr_of_adding_days);
}

bool    ft_check_date1_less_than_date2(s_date date1, s_date date2)
{
        return (date1.year < date2.year ? true : (date2.year == date1.year ? (date1.month < date2.month ? true : (date1.day < date2.day)) : false ));
}

bool    ft_check_date1_equal_date2(s_date date1, s_date date2)
{
        return ((date1.year == date2.year) && (date2.month == date1.month) && (date1.day == date2.day)) ? true : false;
}

bool    ft_check_is_last_day_in_month(s_date date_s)
{
        short   month_days_nbr;

        month_days_nbr = ft_nbr_of_days_in_a_month(date_s);
        if (date_s.day == month_days_nbr)
                return (1);
        return (0);
}


bool    ft_check_is_last_month_in_year(s_date date_s)
{
        return (date_s.month == 12);
}

s_date  ft_increase_date_by_1_day(s_date date)
{
        if (ft_check_is_last_day_in_month(date))
        {
                if(ft_check_is_last_month_in_year(date))
                {
                        (date.year)++;
                        date.day = 1;
                        date.month = 1;
                }
                else
                {
                        (date.month)++;
                        date.day = 1;
                }
        }
        else
                (date.day)++;
        return (date);
}

int	ft_calculate_diff_in_days_between_2dates(s_date date1_s, s_date date2_s, bool include_last_day)
{
        int     days_diff;

        days_diff = 0;
        while (!ft_check_date1_equal_date2(date1_s, date2_s))
        {
                days_diff++;
                date1_s = ft_increase_date_by_1_day(date1_s);
        }
        return (include_last_day ? ++days_diff : days_diff);
}

s_date  ft_set_current_date_by_system()
{
        s_date  current_date_s;

        time_t  t = time(0);
        tm      *now = localtime(&t);
        current_date_s.year = now->tm_year + 1900;
        current_date_s.month = now->tm_mon + 1;
        current_date_s.day = now->tm_mday;
        return (current_date_s);
}

int     ft_calculate_age_in_days()
{
        s_date  date_s;
        s_date  current_date_s;
        int     age_days;

        current_date_s = ft_set_current_date_by_system();
        printf("\n\nPlease enter your birth info:\n");
        date_s = ft_read_date_s();
        age_days = ft_calculate_diff_in_days_between_2dates(date_s, current_date_s);
        return (age_days);
}

void    ft_swap_dates_s(s_date &date1_s, s_date &date2_s)
{
        s_date  tmp_date_s;

        tmp_date_s.day = date1_s.day;
        tmp_date_s.month = date1_s.month;
        tmp_date_s.year = date1_s.year;
        date1_s.day = date2_s.day;
        date1_s.month = date2_s.month;
        date1_s.year = date2_s.year;
        date2_s.day = tmp_date_s.day;
        date2_s.month = tmp_date_s.month;
        date2_s.year = tmp_date_s.year;
}

int     ft_calculate_diff_in_days_between_2dates_advanced(s_date date1_s, s_date date2_s, bool include_last_day)
{
        int     days_diff;
        short   swap_falg;

        swap_falg = 1;
        if (!ft_check_date1_less_than_date2(date1_s, date2_s))
        {
                ft_swap_dates_s(date1_s, date2_s);
                swap_falg = -1;
        }
        days_diff = 0;
        while (!ft_check_date1_equal_date2(date1_s, date2_s))
        {
                days_diff++;
                date1_s = ft_increase_date_by_1_day(date1_s);
        }
        return (swap_falg * (include_last_day ? (days_diff + 1) : (days_diff)));
}

int     ft_set_nbr_general(string message)
{
        int     nbr;

        printf("%s", message.c_str());
        cin >> nbr;
        return (nbr);
}

s_date  ft_increase_date_by_x_days(int x_days_nbr ,s_date date_s)
{
        int     i;

        i = 0;
        while (++i <= x_days_nbr)
                date_s = ft_increase_date_by_1_day(date_s);
        return (date_s);
}

s_date  ft_increase_date_by_1_week(s_date date_s)
{
        date_s = ft_increase_date_by_x_days(7 ,date_s);
        return (date_s);
}

s_date  ft_increase_date_by_1_month(s_date date_s)
{
        short   month_days_nbr;

        if (date_s.month == 12)
        {
                date_s.month = 1;
                (date_s.year)++;
        }
        else
                (date_s.month)++;
        month_days_nbr = ft_nbr_of_days_in_a_month(date_s);
        if (month_days_nbr < date_s.day)
                date_s.day = month_days_nbr;
        return (date_s);
}

s_date  ft_increase_date_by_x_months(int x_months_nbr, s_date date_s)
{
        int     i;

        i = 0;
        while (++i <= x_months_nbr)
                date_s = ft_increase_date_by_1_month(date_s);
        return (date_s);
}

s_date  ft_increase_date_by_1_year(s_date date_s)
{
        short   month_days_nbr;

        (date_s.year)++;
        month_days_nbr = ft_nbr_of_days_in_a_month(date_s);
        if (date_s.day > month_days_nbr)
                date_s.day = month_days_nbr;
        return (date_s);
}

s_date  ft_increase_date_by_x_years(int x_years_nbr, s_date date_s)
{
        int     i;

        i = 0;
        while (++i <= x_years_nbr)
                date_s = ft_increase_date_by_1_year(date_s);
        return (date_s);
}

s_date	ft_increase_date_by_one_decade(s_date date_s)
{
        short   month_days_nbr;

        date_s.year += 10;
        month_days_nbr = ft_nbr_of_days_in_a_month(date_s);
        if (date_s.day > month_days_nbr)
                date_s.day = month_days_nbr;
        return (date_s);
}

s_date  ft_increase_date_by_x_decades(int x_decades_nbr, s_date date_s)
{
        int     i;

        i = 0;
        while(++i <= x_decades_nbr)
                date_s = ft_increase_date_by_one_decade(date_s);
        return (date_s);
}

s_date  ft_increase_date_by_one_century(s_date date_s)
{
        short   month_days_nbr;

        date_s.year += 100;
        month_days_nbr = ft_nbr_of_days_in_a_month(date_s);
        if (month_days_nbr < date_s.day)
        date_s.day = month_days_nbr;
    return (date_s);
}

s_date  ft_increase_date_by_one_millennium(s_date date_s)
{
        short   month_days_nbr;

        date_s.year += 1000;
    month_days_nbr = ft_nbr_of_days_in_a_month(date_s);
    if (month_days_nbr < date_s.day)
                date_s.day = month_days_nbr;
        return (date_s);
}

s_date  ft_decrease_date_by_one_day(s_date date_s)
{
        if (date_s.day == 1)
        {
                if (date_s.month == 1)
                {
                        date_s.month = 12;
                        date_s.day = ft_nbr_of_days_in_a_month(date_s);
                        (date_s.year)--;
                }
                else
                {
                        (date_s.month)--;
                        date_s.day = ft_nbr_of_days_in_a_month(date_s);
                }
        }
        else
                (date_s.day)--;
        return (date_s);
}

s_date  ft_decrease_date_by_x_days(int x_days_nbr, s_date date_s)
{
        int     i;

        i = 0;
        while (++i <= x_days_nbr)
                date_s = ft_decrease_date_by_one_day(date_s);
        return (date_s);
}

s_date  ft_decrease_date_by_one_week(s_date date_s)
{
	date_s = ft_decrease_date_by_x_days(7, date_s);
	return (date_s);
}

s_date  ft_decrease_date_by_x_weeks(int x_weeks_nbr, s_date date_s)
{
        int     i;

        i = 0;
        while(++i <= x_weeks_nbr)
                date_s = ft_decrease_date_by_one_week(date_s);
        return (date_s);
}

s_date  ft_decrease_date_by_one_month(s_date date_s)
{
        short   month_days;

        if (date_s.month == 1)
        {
                date_s.month = 12;
                (date_s.year)--;
        }
        else
        {
                month_days = ft_nbr_of_days_in_a_month(date_s);
                (date_s.month)--;
                if (date_s.day == month_days)
                        date_s.day = ft_nbr_of_days_in_a_month(date_s);
        }
        return (date_s);
}

s_date  ft_decrease_date_by_x_months(int x_months_nbr, s_date date_s)
{
        int     i;

        i = 0;
        while (++i <= x_months_nbr)
                date_s = ft_decrease_date_by_one_month(date_s);
        return (date_s);
}

s_date  ft_decrease_date_by_one_year(s_date date_s)
{
        short   month_days_nbr;

        (date_s.year)--;
        month_days_nbr = ft_nbr_of_days_in_a_month(date_s);
        if (date_s.day > month_days_nbr)
                date_s.day = month_days_nbr;
        return (date_s);
}

s_date  ft_decrease_date_by_x_years(int x_years_nbr, s_date date_s)
{
        int     i;

        i = 0;
        while (++i <= x_years_nbr)
                date_s = ft_decrease_date_by_one_year(date_s);
        return (date_s);
}

s_date  ft_decrease_date_by_one_decade(s_date date_s)
{
        short   month_days_nbr;

        date_s.year -= 10;
        month_days_nbr = ft_nbr_of_days_in_a_month(date_s);
        if (date_s.day > month_days_nbr)
                date_s.day = month_days_nbr;
        return (date_s);
}

s_date  ft_decrease_date_by_x_decades(int x_decades_nbr, s_date date_s)
{
        int     i;

        i = 0;
        while (++i <= x_decades_nbr)
                date_s = ft_decrease_date_by_one_decade(date_s);
        return (date_s);
}

s_date  ft_decrease_date_by_one_century(s_date date_s)
{
        short   month_days_nbr;

        date_s.year -= 100;
        month_days_nbr = ft_nbr_of_days_in_a_month(date_s);
        if (month_days_nbr < date_s.day)
                        date_s.day = month_days_nbr;
    return (date_s);
}

s_date  ft_decrease_date_by_one_millennium(s_date date_s)
{
        short   month_days_nbr;

        date_s.year -= 1000;
        month_days_nbr = ft_nbr_of_days_in_a_month(date_s);
        if (month_days_nbr < date_s.day)
                date_s.day = month_days_nbr;
        return (date_s);
}

bool    ft_check_if_day_is_the_end_of_week(s_date date_s)
{
        short   day_of_week_order;

        day_of_week_order = ft_day_of_week_order(date_s);
        return (day_of_week_order == 6);
}

bool    ft_check_is_a_weekend_day(s_date date_s)
{
        short   day_of_week_order;

        day_of_week_order = ft_day_of_week_order(date_s);
        return (day_of_week_order == 6 || day_of_week_order == 5);
}

bool    ft_check_is_a_business_day(s_date date_s)
{
        return (!ft_check_is_a_weekend_day(date_s));
}

short   ft_count_of_days_until_the_end_of_week(s_date date_s)
{
        short   days_count;
        short   day_order;

        day_order = ft_day_of_week_order(date_s);
        days_count = 0;
        while (day_order != 6)
                ++days_count;
        return (days_count);
}

short   ft_count_of_days_until_end_of_the_month(s_date date_s)
{
        s_date  month_end_s;
        short   days_count;
        short   month_days_nbr;

        month_end_s = date_s;
        month_end_s.day = ft_nbr_of_days_in_a_month(date_s);
        days_count = ft_calculate_diff_in_days_between_2dates_advanced(date_s, month_end_s);
        return (days_count);
}

short   ft_count_of_days_until_end_of_the_year(s_date date_s)
{
    s_date  year_end_s;
    short   days_count;

        year_end_s.year = date_s.year;
        year_end_s.month = 12;
        year_end_s.day = 31;
        if (ft_check_date1_equal_date2(date_s, year_end_s))
                return (0);
    days_count = ft_calculate_diff_in_days_between_2dates_advanced(date_s, year_end_s);
    return (days_count);
}

int     ft_calculate_vacation_period_days(s_date vacation_start_date_s, const s_date &vacation_end_date_s)
{
        int     count_of_vacation_days;

        count_of_vacation_days = 0;
        while(!ft_check_date1_equal_date2(vacation_start_date_s, vacation_end_date_s))
        {
                if (ft_check_is_a_business_day(vacation_start_date_s))
                        count_of_vacation_days++;
                vacation_start_date_s = ft_increase_date_by_1_day(vacation_start_date_s);
        }
        return (count_of_vacation_days);
}

void    ft_get_and_display_vacation_info(s_date vacation_start_date_s, s_date vacation_end_date_s)
{
        string  day_short_name;

        day_short_name = ft_day_short_name(ft_day_of_week_order(vacation_start_date_s));
        printf("\n\n\nVacation From: ( %s ), %hd/%hd/%hd\n\n", day_short_name.c_str(), vacation_start_date_s.day, vacation_start_date_s.month, vacation_start_date_s.year);
        day_short_name = ft_day_short_name(ft_day_of_week_order(vacation_end_date_s));
        printf("Vacation To: ( %s ), %hd/%hd/%hd\n\n", day_short_name.c_str(), vacation_end_date_s.day, vacation_end_date_s.month, vacation_end_date_s.year);
}

void    ft_set_vacation_info(s_date &vacation_start_date_s, s_date &vacation_end_date_s)
{
        printf("\nVacation Start:  ");
        vacation_start_date_s = ft_read_date_s();
        printf("\n\nVacation End:  ");
        vacation_end_date_s = ft_read_date_s();
}

s_date ft_set_vacation_info_s()
{
        s_date  vacation_start_date_s;

        printf("\nVacation Start:  \n");
    vacation_start_date_s = ft_read_date_s();
        return (vacation_start_date_s);
}

s_date  ft_set_vacation_return_date_s(int vacation_days_nbr, s_date &vacation_start_date_s)
{
        int     i;

        i = 0;
        while (++i <= vacation_days_nbr)
        {
                if (ft_check_is_a_business_day(vacation_start_date_s))
                        vacation_start_date_s = ft_increase_date_by_1_day(vacation_start_date_s);
                else
                {
                        i--;
                        vacation_start_date_s = ft_increase_date_by_1_day(vacation_start_date_s);
                }
        }
		while (ft_check_is_a_weekend_day(vacation_start_date_s))
			vacation_start_date_s = ft_increase_date_by_1_day(vacation_start_date_s);
        return (vacation_start_date_s);
}

bool    ft_check_is_date1_after_date2(s_date date1, s_date date2)
{
        return ((!ft_check_date1_less_than_date2(date1, date2)) && (!ft_check_date1_equal_date2(date1, date2)));
}

t_e_date_compare        ft_t_e_compare_dates(s_date date1_s, s_date date2_s)
{
        if (ft_check_is_date1_after_date2(date1_s, date2_s))
                return (t_e_date_compare::after);
        else if (ft_check_date1_equal_date2(date1_s, date2_s))
                return (t_e_date_compare::equal);
        else
                return (t_e_date_compare::before);
}

t_s_period      ft_t_read_period()
{
        t_s_period      period_s;

        printf("\nPlease enter the start date:\n");
        period_s.start_date_s = ft_read_date_s();
        printf("\n\nPlease enter the end date:\n");
        period_s.end_date_s= ft_read_date_s();
        return (period_s);
}

bool    ft_check_if_2_periods_overlap(t_s_period period1, t_s_period period2)
{
        if (ft_t_e_compare_dates(period1.start_date_s, period2.end_date_s) == t_e_date_compare::after)
                return (false);
        else if (ft_t_e_compare_dates(period1.end_date_s, period2.start_date_s) == t_e_date_compare::before)
                return (false);
        else
                return (true);
}

int     ft_calculate_period_length_in_days(t_s_period period_s, bool include_last_day)
{
        return (ft_calculate_diff_in_days_between_2dates_advanced(period_s.start_date_s, period_s.end_date_s, include_last_day));
}

bool    ft_check_is_date_within_time_period(s_date wanted_to_check_date_s, t_s_period period_s)
{
        bool    is_within_result;

        is_within_result = (ft_t_e_compare_dates(wanted_to_check_date_s, period_s.start_date_s) != t_e_date_compare::before
                                                && ft_t_e_compare_dates(wanted_to_check_date_s, period_s.end_date_s) != t_e_date_compare::after);
        return (is_within_result);
}

int     ft_count_overlap_days_of_2_periods(t_s_period period_s_1, t_s_period period_s_2)
{
        int     overlapped_days_counter;
        int     period1_len;
        int     period2_len;

        if (!ft_check_if_2_periods_overlap(period_s_1, period_s_2))
                return (0);
        period1_len = ft_calculate_period_length_in_days(period_s_1);
        period2_len = ft_calculate_period_length_in_days(period_s_2);
        overlapped_days_counter = 0;
        if (period1_len < period2_len)
        {
                while (ft_t_e_compare_dates(period_s_1.start_date_s, period_s_1.end_date_s) == t_e_date_compare::before)
                {
                        if (ft_check_is_date_within_time_period(period_s_1.start_date_s, period_s_2))
                                (overlapped_days_counter)++;
                        (period_s_1.start_date_s) = ft_increase_date_by_1_day(period_s_1.start_date_s);
                }
        }
        else
        {
                while (ft_t_e_compare_dates(period_s_2.start_date_s, period_s_2.end_date_s) == t_e_date_compare::before)
                {
                        if (ft_check_is_date_within_time_period(period_s_2.start_date_s, period_s_1))
                                (overlapped_days_counter)++;
                        (period_s_2.start_date_s) = ft_increase_date_by_1_day(period_s_2.start_date_s);
                }
        }
        return (overlapped_days_counter);
}

bool    ft_validate_a_date(s_date date_s)
{
        if (date_s.month >= 13 || date_s.month <= 0)
                return (false);
        else if (date_s.day > ft_nbr_of_days_in_a_month(date_s)
                        || date_s.day < 1)
                return (false);
        else
                return (true);
}

string  ft_read_date_string(string message)
{
        string str_date;

        printf("%s", message.c_str());
        getline(cin >> ws, str_date);
        return (str_date);
}

vector <string> ft_v_str_convert_str_date_to_fields(string str_date, string str_fields_separator)
{
        vector <string> v_str_date_fields;
        short   index;
        short   len;

        len = str_fields_separator.length();
        while ((index = str_date.find(str_fields_separator)) != string::npos)
        {
                v_str_date_fields.emplace_back(str_date.substr(0, index));
                str_date.erase(0, index + len);
        }
        if (str_date != "")
                v_str_date_fields.emplace_back(str_date);
        return (v_str_date_fields);
}

s_date  ft_convert_str_date_to_date_s(string str_date, string str_fields_separator)
{
        s_date  date_s;
        vector <string> v_str_date_fields;

        v_str_date_fields = ft_v_str_convert_str_date_to_fields(str_date, str_fields_separator);
        date_s.day = (short)stoi(v_str_date_fields[0]);
        date_s.month = (short)stoi(v_str_date_fields[1]);
        date_s.year = (short)stoi(v_str_date_fields[2]);
        return (date_s);
}

void    ft_print_date_separately(s_date date_s)
{
        printf("\n\nDay: (%hd)\nMonth: (%hd)\nYear: (%hd)\n\n", date_s.day, date_s.month, date_s.year);
}

string  ft_convert_date_s_to_str_date(s_date date_s)
{
        return (to_string(date_s.day) + "/" + to_string(date_s.month) + "/" + to_string(date_s.year));
}

string  ft_replace_words_in_str(string str, string str_replace, string str_replace_to)
{
        short   index;

        while ((index = str.find(str_replace)) != std::string::npos)
                str = str.replace(index, str_replace.length(), str_replace_to);
        return (str);
}

string  ft_format_str_date(s_date date_s, string str_date_format)
{
        string  str_formatted_date;

        str_formatted_date = "";
        str_formatted_date = ft_replace_words_in_str(str_date_format, "dd", to_string(date_s.day));
        str_formatted_date = ft_replace_words_in_str(str_formatted_date, "mm", to_string(date_s.month));
        str_formatted_date = ft_replace_words_in_str(str_formatted_date, "yyyy", to_string(date_s.year));
        return (str_formatted_date);
}

} // namespace my_time_lib

