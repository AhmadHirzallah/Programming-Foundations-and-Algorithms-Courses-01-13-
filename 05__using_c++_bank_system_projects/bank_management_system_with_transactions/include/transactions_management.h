#ifndef TRANSACTIONS_MANAGEMENT_H
 #define TRANSACTIONS_MANAGEMENT_H

#include <string>
#include <vector>
#include "clients_management.h"

using namespace std;

enum	e_transactions_and_balances_menu
{
	deposit = 1,
	withdraw,
	total_balances,
	quit_2 = 4
};

void    ft_show_transactions_and_balances_menu();
short   ft_get_transactions_menu_option();
void    ft_execute_transaction_menu_option(e_transactions_and_balances_menu choice_e);
void    ft_set_deposit();
char    ft_set_deposit_choice();
double  ft_set_deposit_value();
string  ft_set_acc_nbr();
void    ft_press_enter_to_back_to_tranasctions_menu();
void    ft_deposit_balance_to_client_by_acc_nbr(string str_id_nbr, double d_money_ammount, vector <s_client> &clients_v);
double  ft_set_a_withdraw_value();
void    ft_set_a_withdraw();
void	ft_display_total_balances_screen(vector <s_client> &clients_v);
void    ft_get_total_balances();

#endif
