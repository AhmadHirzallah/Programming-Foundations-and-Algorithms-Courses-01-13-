#ifndef CLIENTS_MANAGEMENT_H
 #define CLIENTS_MANAGEMENT_H

#include <vector>
#include <string>
#include "constants.h"

using namespace std;

typedef	enum	e_atm_main_menu_options
{
	quick_withdraw = 1,
	normal_withdraw = 2,
	deposit,
	show_balance,
	logout = 5
}	t_e_atm_main_menu_options;

enum e_quick_withdraw_options 
{
    withdraw_20 = 1,
    withdraw_50,
    withdraw_100,
    withdraw_200,
    withdraw_400,
    withdraw_600,
    withdraw_800,
    withdraw_1000,
    exit_from
};

// Function declarations

short ft_set_atm_main_menu_option();
void ft_display_quick_withdraw_options();
short   ft_set_quick_withdraw_option_of_value();
short ft_get_widraw_value_of_the_choice(e_quick_withdraw_options entered_option);
void ft_deposit_balance_to_client_and_give_notification(short d_money_amount);
void ft_perfrom_quick_withdraw();
void ft_execute_atm_main_menu_option(t_e_atm_main_menu_options chosen_atm_option_t_e);
bool    ft_are_you_sure_to_do_operation_to_balance();
void    ft_perform_deposit_by_acc_nbr_on_file(string str_id_nbr, double d_money_amount, vector <s_client> &clients_v);
void    ft_perfrom_quick_withdraw();
int ft_set_withdraw_mltpls_5_from_user();
void    ft_perform_normal_withdraw();
void    ft_get_client_balance();
char    ft_set_choice_of_perfroming_transactions();
double  ft_set_deposit_entered_value();
void    ft_perform_deposit();
void    ft_show_client_balance();
bool    ft_find_client_and_get_ref(string str_id_nbr, vector <s_client> v_clients_s, s_client &client_s);
void    ft_execute_atm_main_menu_option_using_user(t_e_atm_main_menu_options chosen_atm_option_t_e);
void    ft_perfrom_quick_withdraw_using_user();
void    ft_perform_normal_withdraw_using_user();
void    ft_perform_deposit_using_user();
void    ft_show_client_balance_using_user();
string  ft_set_client_id_using_user();
void    press_any_key_to_get_main_menu_of_clients_for_user();


// Declare other functions used in this file (ensure they exist in your codebase)
void ft_show_atm_main_menu_for_clients();
void ft_print_screen_header(string str_screen_name);
void ft_perform_normal_withdraw();
void ft_perform_deposit();
void ft_check_a_client_balance();
void ft_show_login();

#endif
