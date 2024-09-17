#include "clients_management.h"
#include "file_management.h"
#include "system_users_management.h"
#include "constants.h"
#include "interface.h"
#include <iostream>
#include <limits>
#include <cstdio>


using namespace std;

bool	ft_find_client_and_get_ref(string str_id_nbr, vector <s_client> v_clients_s, s_client &client_s)
{
	for (s_client &tmp_client_s : v_clients_s)
	{
		if (tmp_client_s.str_id_nbr == str_id_nbr)
		{
			client_s = tmp_client_s;
			return (true);
		}
	}
	return (false);
}

short	ft_set_atm_main_menu_option()
{
	short	entered_option;

	entered_option = 0;
	while (!(entered_option >= 1 && entered_option <= 5))
	{
		printf("Please enter your choice [1 - 5]: ");
		cin >> entered_option;
	}
	return (entered_option);
}

void	ft_display_quick_withdraw_options()
{
	printf("+----------------------------------------+\n");
    printf("|           Quick Withdraw Screen        |\n");
    printf("+----------------------------------------+\n");
    printf("|   Option   |        Amount (in $)      |\n");
    printf("+------------+---------------------------+\n");
    printf("|   [1]      |        20                 |\n");
    printf("|   [2]      |        50                 |\n");
    printf("|   [3]      |        100                |\n");
    printf("|   [4]      |        200                |\n");
    printf("|   [5]      |        400                |\n");
    printf("|   [6]      |        600                |\n");
    printf("|   [7]      |        800                |\n");
    printf("|   [8]      |        1000               |\n");
    printf("|   [9]      |        Exit               |\n");
    printf("+----------------------------------------+\n");
	printf("\n-- Your balance is:  `%.3f`\n\n", g_client_s.d_balance);
}

short	ft_set_quick_withdraw_option_of_value()
{
	short	quick_withdraw_amount;

	quick_withdraw_amount = 0;
	while (!(quick_withdraw_amount >= 1 && quick_withdraw_amount <= 9))
	{
		printf("Enter the withdrawal amount (1 - 9): ");
		cin >> quick_withdraw_amount;
	}
	return (quick_withdraw_amount);
}

short	ft_get_withdraw_value_of_the_choice(e_quick_withdraw_options entered_option)
{
	if (entered_option == e_quick_withdraw_options::withdraw_20)
		return (20);
	else if (entered_option == e_quick_withdraw_options::withdraw_50)
		return (50);
	else if (entered_option == e_quick_withdraw_options::withdraw_100)
		return (100);
	else if (entered_option == e_quick_withdraw_options::withdraw_200)
		return (200);
	else if (entered_option == e_quick_withdraw_options::withdraw_400)
		return (400);
	else if (entered_option == e_quick_withdraw_options::withdraw_600)
		return (600);
	else if (entered_option == e_quick_withdraw_options::withdraw_800)
		return (800);
	else if (entered_option == e_quick_withdraw_options::withdraw_1000)
		return (1000);
	else 
		return (0);
}

void	ft_deposit_balance_to_client_and_give_notification(double d_money_amount, s_client &g_client_s)
{
	g_client_s.d_balance += d_money_amount;
	printf ("\nDone successfully; `%s` New Balance is: %.3f\n\n", g_client_s.str_name.c_str(), g_client_s.d_balance);
}

bool	ft_are_you_sure_to_do_operation_to_balance()
{
	char	choice;

	printf("\n\nAre you sure to perform this operation?  (Y to proceed):  ");
	cin >> choice;
	if (toupper(choice) == 'Y')
		return (1);
	else
		return (0);
}

void	ft_perform_deposit_by_acc_nbr_on_file(string str_id_nbr, double d_money_amount, vector <s_client> &clients_v)
{
	for (s_client &client_s : clients_v)
	{
		if (client_s.str_id_nbr == str_id_nbr)
		{
			client_s.d_balance += d_money_amount;
			ft_update_clients_data_in_a_file(clients_v);
			break;
		}
	}
}

void	ft_get_client_balance()
{
	printf("\nYour balance is:  `%.3f`\n\n", g_client_s.d_balance);
}

void	ft_perfrom_quick_withdraw()
{
	short	withdraw_value;
	vector <s_client>	clients_v = ft_v_convert_data_from_file_to_set_of_clients();

	ft_print_screen_header("Quick Withdraw Screen");
	ft_display_quick_withdraw_options();
	withdraw_value = ft_get_withdraw_value_of_the_choice(e_quick_withdraw_options(ft_set_quick_withdraw_option_of_value()));
	if (withdraw_value == 0)
		ft_show_atm_main_menu_for_clients();
	while (withdraw_value > g_client_s.d_balance)
	{
		printf("\nThe amount exceeds the balance!\n\nRedo the operation\n");
		withdraw_value = ft_get_withdraw_value_of_the_choice(e_quick_withdraw_options(ft_set_quick_withdraw_option_of_value()));
	}
	if (ft_are_you_sure_to_do_operation_to_balance())
	{
		ft_deposit_balance_to_client_and_give_notification(-1 * withdraw_value, g_client_s);
		ft_perform_deposit_by_acc_nbr_on_file(g_client_s.str_id_nbr, (-1 * withdraw_value), clients_v);
	}
}

void	ft_perfrom_quick_withdraw_using_user()
{
	short	withdraw_value;
	vector <s_client>	clients_v = ft_v_convert_data_from_file_to_set_of_clients();
	string  str_client_id;

	system("clear");
	ft_print_screen_header("Quick Withdraw Screen");
	printf("\n\nPlease enter the ID of the Client:  ");
	getline(cin >> ws, str_client_id);
	if(!ft_find_client_and_get_ref(str_client_id, clients_v, g_client_s))
	{
		printf("\nClient with Account ID Number (%s) isn't exist.\n", str_client_id.c_str());
		return;
	}
	printf ("\n\n---- Client: \"%s\" ----\n\n", g_client_s.str_name.c_str());
	ft_display_quick_withdraw_options();
	withdraw_value = ft_get_withdraw_value_of_the_choice(e_quick_withdraw_options(ft_set_quick_withdraw_option_of_value()));
	if (withdraw_value == 0)
		ft_show_atm_main_menu_for_clients();
	while (withdraw_value > g_client_s.d_balance)
	{
		printf("\nThe amount exceeds the balance!\n\nRedo the operation\n");
		withdraw_value = ft_get_withdraw_value_of_the_choice(e_quick_withdraw_options(ft_set_quick_withdraw_option_of_value()));
	}
	if (ft_are_you_sure_to_do_operation_to_balance())
	{
		ft_deposit_balance_to_client_and_give_notification(-1 * withdraw_value, g_client_s);
		ft_perform_deposit_by_acc_nbr_on_file(g_client_s.str_id_nbr, (-1 * withdraw_value), clients_v);
	}
}

int	ft_set_withdraw_mltpls_5_from_user()
{
	int	withdraw_value;

	withdraw_value = 1;
	while (withdraw_value % 5 != 0)
	{
		printf("\n\nEnter an amount multiple of 5's: ");
		cin >> withdraw_value;
	}
	return (withdraw_value);
}

char	ft_set_choice_of_perfroming_transactions()
{
	char	get_choice;

	printf("\nAre you sure you want to perform this transaction? (y to proceed):  ");
	cin >> get_choice;
	return (get_choice);
}

void	ft_perform_normal_withdraw_using_user()
{
	vector <s_client>	clients_v;
	int withdraw_value;
	char	get_choice;
	string  str_client_id;

	system("clear");
	clients_v = ft_v_convert_data_from_file_to_set_of_clients();
	ft_print_screen_header("Normal Withdraw Screen");
	printf("\n\nPlease enter the ID of the Client:  ");
	getline(cin >> ws, str_client_id);
	if(!ft_find_client_and_get_ref(str_client_id, clients_v, g_client_s))
	{
		printf("\nClient with Account ID Number (%s) isn't exist.\n", str_client_id.c_str());
		return;
	}
	printf ("\n\n---- Client: \"%s\" ----\n\n", g_client_s.str_name.c_str());
	ft_get_client_balance();
	withdraw_value = ft_set_withdraw_mltpls_5_from_user();
	while (withdraw_value > g_client_s.d_balance)
	{
		printf("\nThe amount exceeds the balance!\n\nRedo the operation\n");
		withdraw_value = ft_set_withdraw_mltpls_5_from_user();
	}
	get_choice = ft_set_choice_of_perfroming_transactions();
	if (tolower(get_choice) == 'y')
	{
		ft_perform_deposit_by_acc_nbr_on_file(g_client_s.str_id_nbr, (-1 * withdraw_value), clients_v);
		ft_deposit_balance_to_client_and_give_notification((-1 * withdraw_value), g_client_s);
	}
}

void	ft_perform_normal_withdraw()
{
	vector <s_client>	clients_v;
	int withdraw_value;
	char	get_choice;

	ft_print_screen_header("Normal Withdraw Screen");
	clients_v = ft_v_convert_data_from_file_to_set_of_clients();
	ft_get_client_balance();
	withdraw_value = ft_set_withdraw_mltpls_5_from_user();
	while (withdraw_value > g_client_s.d_balance)
	{
		printf("\nThe amount exceeds the balance!\n\nRedo the operation\n");
		withdraw_value = ft_set_withdraw_mltpls_5_from_user();
	}
	get_choice = ft_set_choice_of_perfroming_transactions();
	if (tolower(get_choice) == 'y')
	{
		ft_perform_deposit_by_acc_nbr_on_file(g_client_s.str_id_nbr, (-1 * withdraw_value), clients_v);
		ft_deposit_balance_to_client_and_give_notification((-1 * withdraw_value), g_client_s);
	}
}

double	ft_set_deposit_entered_value()
{
	double	deposit_amount;

	deposit_amount = -1;
	while (deposit_amount <= 0)
	{
		printf("Please enter a positive value:  ");
		cin >> deposit_amount;
	}
	return (deposit_amount);
}

void	ft_perform_deposit()
{
	vector <s_client>   clients_v;
	double deposit_value;
	char    get_choice;

	ft_print_screen_header("Depoist Screen");
	clients_v = ft_v_convert_data_from_file_to_set_of_clients();
	ft_get_client_balance();
	deposit_value = ft_set_deposit_entered_value();
	get_choice = ft_set_choice_of_perfroming_transactions();
	if (tolower(get_choice) == 'y')
	{
		ft_perform_deposit_by_acc_nbr_on_file(g_client_s.str_id_nbr, deposit_value, clients_v);
		ft_deposit_balance_to_client_and_give_notification(deposit_value, g_client_s);
	}
}

void	ft_perform_deposit_using_user()
{
	vector <s_client>   clients_v;
	double deposit_value;
	char    get_choice;
	string  str_client_id;


	system("clear");
	ft_print_screen_header("Depoist Screen");
	printf("\n\nPlease enter the ID of the Client:  ");
	getline(cin >> ws, str_client_id);
	clients_v = ft_v_convert_data_from_file_to_set_of_clients();
	if(!ft_find_client_and_get_ref(str_client_id, clients_v, g_client_s))
	{
		printf("\nClient with Account ID Number (%s) isn't exist.\n", str_client_id.c_str());
		return;
	}
	printf ("\n\n---- Client: \"%s\" ----\n\n", g_client_s.str_name.c_str());
	ft_get_client_balance();
	deposit_value = ft_set_deposit_entered_value();
	get_choice = ft_set_choice_of_perfroming_transactions();
	if (tolower(get_choice) == 'y')
	{
		ft_perform_deposit_by_acc_nbr_on_file(g_client_s.str_id_nbr, deposit_value, clients_v);
		ft_deposit_balance_to_client_and_give_notification(deposit_value, g_client_s);
	}
}

void	ft_show_client_balance()
{
	ft_print_screen_header("Client Balance Screen");
	ft_get_client_balance();

}

void	ft_show_client_balance_using_user()
{
	string  str_client_id;
	vector <s_client>   clients_v;

	ft_print_screen_header("Client Balance Screen");
	clients_v = ft_v_convert_data_from_file_to_set_of_clients();
	printf("\n\nPlease enter the ID of the Client:  ");
	getline(cin >> ws, str_client_id);
	if(!ft_find_client_and_get_ref(str_client_id, clients_v, g_client_s))
	{
		printf("\nClient with Account ID Number (%s) isn't exist.\n", str_client_id.c_str());
		return;
	}
	printf ("\n\n---- Client: \"%s\" ----\n\n", g_client_s.str_name.c_str());
	ft_get_client_balance();
}

void	press_any_key_to_get_main_menu_of_clients()
{
	cout << "\nPress (Enter ⏎) key to return to the main menu... ";
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.get();
	system("clear");
	ft_show_atm_main_menu_for_clients();
}

void	press_any_key_to_get_main_menu_of_clients_for_user()
{
	cout << "\nPress (Enter ⏎) key to return to the main menu... ";
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.get();
	system("clear");
	ft_show_atm_main_menu_for_clients_using_user();
}

void	ft_execute_atm_main_menu_option(t_e_atm_main_menu_options chosen_atm_option_t_e)
{
	if (chosen_atm_option_t_e == t_e_atm_main_menu_options::quick_withdraw)
	{
		system("clear");
		ft_perfrom_quick_withdraw();
		press_any_key_to_get_main_menu_of_clients();
	}
	else if (chosen_atm_option_t_e == t_e_atm_main_menu_options::normal_withdraw)
	{
		system("clear");
		ft_perform_normal_withdraw();
		press_any_key_to_get_main_menu_of_clients();
	}
	
	else if (chosen_atm_option_t_e == t_e_atm_main_menu_options::deposit)
	{
		system("clear");
		ft_perform_deposit();
		press_any_key_to_get_main_menu_of_clients();
	}
	else if (chosen_atm_option_t_e == t_e_atm_main_menu_options::show_balance)
	{
		system("clear");
		ft_show_client_balance();
		press_any_key_to_get_main_menu_of_clients();
	}
	else if (chosen_atm_option_t_e == t_e_atm_main_menu_options::logout)
	{
		system("clear");
		ft_show_login();
	}
}

void ft_reset_global_client()
{
    // Assuming g_client_s has a string and double member
    g_client_s.str_id_nbr = ""; // Reset ID number
    g_client_s.str_pin_nbr = "";
    g_client_s.str_name = "";   // Reset name
    g_client_s.str_phone_nbr = "";
    g_client_s.d_balance = 0.0; // Reset balance
								// 
}

void	ft_execute_atm_main_menu_option_using_user(t_e_atm_main_menu_options chosen_atm_option_t_e)
{
	if (chosen_atm_option_t_e == t_e_atm_main_menu_options::quick_withdraw)
	{
		system("clear");
		ft_perfrom_quick_withdraw_using_user();
		press_any_key_to_get_main_menu_of_clients_for_user();
	}
	else if (chosen_atm_option_t_e == t_e_atm_main_menu_options::normal_withdraw)
	{
		system("clear");
		ft_perform_normal_withdraw_using_user();
		press_any_key_to_get_main_menu_of_clients_for_user();
	}
	
	else if (chosen_atm_option_t_e == t_e_atm_main_menu_options::deposit)
	{
		system("clear");
		ft_perform_deposit_using_user();
		press_any_key_to_get_main_menu_of_clients_for_user();
	}
	else if (chosen_atm_option_t_e == t_e_atm_main_menu_options::show_balance)
	{
		system("clear");
		ft_show_client_balance_using_user();
		press_any_key_to_get_main_menu_of_clients_for_user();
	}
	else if (chosen_atm_option_t_e == t_e_atm_main_menu_options::logout)
	{
		system("clear");
		ft_show_login();
	}
}


