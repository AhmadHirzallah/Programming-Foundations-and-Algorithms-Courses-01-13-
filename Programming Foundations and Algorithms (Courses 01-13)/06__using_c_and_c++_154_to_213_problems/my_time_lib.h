#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace my_time_lib {

struct s_extracted_date_info {
    short day_grgian_order;
    string day_name;
    string formatted_date;
    short nbr_of_month_days;
    short nbr_of_year_days;
};

struct s_date {
    short day;
    short month;
    short year;
};

typedef enum    e_date_compare
{
        before = -1,
        equal = 0,
        after = 1
}       t_e_date_compare;

typedef struct  s_period
{
        s_date  start_date_s;
        s_date  end_date_s;
}       t_s_period;

// Function declarations
bool ft_is_leap_year(short year);
short ft_nbr_of_days_in_a_year(short year);
short ft_nbr_of_hours_in_a_year(short year);
int ft_nbr_of_minutes_in_a_year(short year);
int ft_nbr_of_seconds_in_a_year(short year);
void ft_display_time_categories_of_a_year(short year);
short ft_nbr_of_hours_in_a_month(short month, short year);
int ft_nbr_of_minutes_in_a_month(short month, short year);
int ft_nbr_of_seconds_in_a_month(short month, short year);
short ft_day_of_week_order(short day, short month, short year);
string ft_day_short_name(short day_of_week_order);
string ft_month_short_name(short month_number);
void ft_print_month_calendar(short month, short year);
void ft_print_year_calendar(short year);
s_extracted_date_info   ft_get_extracted_date_info(s_date date);
short ft_read_day();
short ft_read_month();
short ft_read_year();
s_date  ft_date_from_day_of_year(short days_nbr_frm_year_beginning, short year);
short ft_day_of_week_order(s_date date_s);
short ft_nbr_of_days_from_the_beginning_of_the_year(short day, short month, short year);
short ft_nbr_of_days_from_the_beginning_of_the_year(s_date date_s);
short ft_nbr_of_days_in_a_month(short month, short year);
short ft_nbr_of_days_in_a_month(s_date date_s);
s_date  ft_add_days_to_a_date(int nbr_of_adding_days, s_date prev_date_s);
s_date  ft_read_date_s();
int     ft_set_nbr_of_adding_days();
bool    ft_check_date1_less_than_date2(s_date date1, s_date date2);
bool    ft_check_date1_equal_date2(s_date date1, s_date date2);
bool    ft_check_is_last_month_in_year(s_date date_s);
bool    ft_check_is_last_day_in_month(s_date date_s);
s_date  ft_increase_date_by_1_day(s_date date);
int     ft_calculate_diff_in_days_between_2dates(s_date date1_s, s_date date2_s, bool include_last_day = true);
s_date  ft_set_current_date_by_system();
int	ft_calculate_age_in_days();
void    ft_swap_dates_s(s_date &date1_s, s_date &date2_s);
int ft_calculate_diff_in_days_between_2dates_advanced(s_date date1_s, s_date date2_s, bool include_last_day = true);
s_date  ft_increase_date_by_x_days(int x_days_nbr ,s_date date_s);
int     ft_set_nbr_general(string message);
s_date  ft_increase_date_by_1_week(s_date date_s);
s_date  ft_increase_date_by_1_month(s_date date_s);
s_date  ft_increase_date_by_x_months(int x_months_nbr, s_date date_s);
s_date  ft_increase_date_by_1_year(s_date date_s);
s_date  ft_increase_date_by_x_years(int x_years_nbr, s_date date_s);
s_date  ft_increase_date_by_one_decade(s_date date_s);
s_date  ft_increase_date_by_x_decades(int x_decades_nbr, s_date date_s);
s_date  ft_increase_date_by_one_century(s_date date_s);
s_date  ft_increase_date_by_one_millennium(s_date date_s);
s_date  ft_decrease_date_by_one_day(s_date date_s);
s_date  ft_decrease_date_by_x_days(int x_days_nbr, s_date date_s);
s_date  ft_decrease_date_by_one_week(s_date date_s);
s_date  ft_decrease_date_by_x_weeks(int x_weeks_nbr, s_date date_s);
s_date  ft_decrease_date_by_one_month(s_date date_s);
s_date  ft_decrease_date_by_x_months(int x_months_nbr, s_date date_s);
s_date  ft_decrease_date_by_one_year(s_date date_s);
s_date  ft_decrease_date_by_x_years(int x_years_nbr, s_date date_s);
s_date  ft_decrease_date_by_one_decade(s_date date_s);
s_date  ft_decrease_date_by_x_decades(int x_decades_nbr, s_date date_s);
s_date  ft_decrease_date_by_one_century(s_date date_s);
s_date  ft_decrease_date_by_one_millennium(s_date date_s);
bool    ft_check_if_day_is_the_end_of_week(s_date date_s);
bool    ft_check_is_a_weekend_day(s_date date_s);
bool    ft_check_is_a_business_day(s_date date_s);
short   ft_count_of_days_until_the_end_of_week(s_date date_s);
short   ft_count_of_days_until_end_of_the_month(s_date date_s);
short   ft_count_of_days_until_end_of_the_year(s_date date_s);
void    ft_set_vacation_info(s_date &vacation_start_date_s, s_date &vacation_end_date_s);
void    ft_get_and_display_vacation_info(s_date vacation_start_date_s, s_date vacation_end_date_s);
int     ft_calculate_vacation_period_days(s_date vacation_start_date_s, const s_date &vacation_end_date_s);
s_date ft_set_vacation_info_s();
s_date  ft_set_vacation_return_date_s(int vacation_days_nbr, s_date &vacation_start_date_s);
bool    ft_check_is_date1_after_date2(s_date date1, s_date date2);
t_e_date_compare        ft_t_e_compare_dates(s_date date1_s, s_date date2_s);
t_s_period      ft_t_read_period();
bool    ft_check_if_2_periods_overlap(t_s_period period1, t_s_period period2);
int     ft_calculate_period_length_in_days(t_s_period period_s, bool include_last_day = true);
bool    ft_check_is_date_within_time_period(s_date wanted_to_check_date_s, t_s_period period_s);
int     ft_count_overlap_days_of_2_periods(t_s_period period_s_1, t_s_period period_s_2);
bool    ft_validate_a_date(s_date date_s);
string  ft_read_date_string(string message = "\nPlease Enter Date (dd/mm/yyyy):  ");
vector <string> ft_v_str_convert_str_date_to_fields(string str_date, string str_fields_separator);
s_date  ft_convert_str_date_to_date_s(string str_date, string str_fields_separator = "/");
void    ft_print_date_separately(s_date date_s);
string  ft_convert_date_s_to_str_date(s_date date_s);
string  ft_replace_words_in_str(string str, string str_replace, string str_replace_to);
string  ft_format_str_date(s_date date_s, string str_date_format = "dd/mm/yyyy");
} // namespace my_time_lib
