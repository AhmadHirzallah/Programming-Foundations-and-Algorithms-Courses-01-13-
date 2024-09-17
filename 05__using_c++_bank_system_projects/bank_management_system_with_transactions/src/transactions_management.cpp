#include "transactions_management.h"
#include "clients_management.h"
#include "file_management.h"
#include "user_interface.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

void	ft_show_transactions_and_balances_menu()
{
	system("clear");
    printf("\n=======================================\n");
    printf("          Transactions Menu Screen          \n");
    printf("=======================================\n");
    printf("[1] Deposit\n");
    printf("[2] Withdraw\n");
    printf("[3] Total Balances\n");
    printf("[4] Main Menu\n");
    printf("=======================================\n");
    ft_execute_transaction_menu_option((e_transactions_and_balances_menu)ft_get_transactions_menu_option());
}

short	ft_get_transactions_menu_option()
{
	short	entered_choice;

	while (!(entered_choice >= 1 && entered_choice <= 4))
	{
		printf("\nPlease enter your choice [1-4]: ");
		cin >> entered_choice;
	}
	return (entered_choice);	
}

void	ft_execute_transaction_menu_option(e_transactions_and_balances_menu choice_e)
{
	if (choice_e == e_transactions_and_balances_menu::deposit)
	{
		system("clear");
		ft_set_deposit();
		ft_press_enter_to_back_to_tranasctions_menu();
	}
	else if (choice_e == e_transactions_and_balances_menu::withdraw)
	{
		system("clear");
		ft_set_a_withdraw();
		ft_press_enter_to_back_to_tranasctions_menu();

	}
	else if (choice_e == e_transactions_and_balances_menu::total_balances)
	{
		system("clear");
		ft_get_total_balances();
		ft_press_enter_to_back_to_tranasctions_menu();
	}
	else if (choice_e == e_transactions_and_balances_menu::quit_2)
	{
		system("clear");
		ft_show_main_menu();
	}
}

void	ft_get_total_balances()
{
	vector <s_client>   clients_v;

	clients_v = ft_v_convert_file_data_to_clients_data();
	ft_display_total_balances_screen(clients_v);


}

void	ft_display_total_balances_screen(vector <s_client> &clients_v)
{
	double total_balance;

	total_balance = 0.0;
    printf("\n__________________________________________________________________________________\n");
    printf("__________________________________________________________________________________\n");
    printf("\n\t\t\t\t\tBalances List (%zu) Client(s).\n", clients_v.size());
    printf("__________________________________________________________________________________\n");
    printf("__________________________________________________________________________________\n");
    printf("| %-15s | %-40s | %-15s |\n", "Account Number", "Client Name", "Balance");
    printf("__________________________________________________________________________________\n");

    for (const s_client &client : clients_v) 
	{
        printf("| %-15s | %-40s | %-15.2f |\n", client.str_id_nbr.c_str(), client.str_name.c_str(), client.d_balance);
        total_balance += client.d_balance;
    }

    printf("__________________________________________________________________________________\n");
    printf("Total Balances = %.2f\n", total_balance);
    printf("__________________________________________________________________________________\n");
}

void	ft_set_a_withdraw()
{
	string	str_acc_nbr;
	s_client	client_s;
	vector <s_client>   clients_v;
	double	d_withdraw_value;

	ft_print_screen_header("Withdraw Screen");
	str_acc_nbr = ft_set_acc_nbr();
	if (ft_check_is_client_exist_by_acc_nbr(str_acc_nbr))
	{
		client_s = ft_find_and_get_client(str_acc_nbr);
		ft_print_client_details(client_s);
		d_withdraw_value = ft_set_a_withdraw_value();
		clients_v = ft_v_convert_file_data_to_clients_data();
		while (d_withdraw_value > client_s.d_balance)
		{
			printf("\nThe amount exceeds the balance!\n\nRedo the operation\n");
			d_withdraw_value = ft_set_a_withdraw_value();
		}
		ft_deposit_balance_to_client_by_acc_nbr(str_acc_nbr, (-1 * d_withdraw_value), clients_v);
	}
	else 
		printf("\nClient with ID `%s` isn't exist.\n", str_acc_nbr.c_str());
}

double	ft_set_a_withdraw_value()
{
	double	d_withdraw_value;

	printf("\nPlease enter Withdraw Amount: ");
	cin >> d_withdraw_value;
	return (d_withdraw_value);
}

string	ft_set_acc_nbr()
{
	string str_acc_nbr;

	printf("\nPlease enter Account ID Number: ");
	cin >> str_acc_nbr;
	return (str_acc_nbr);
}

void	ft_set_deposit()
{
	string	str_acc_nbr;
	s_client	client_s;
	vector <s_client>   clients_v;
	double	d_deposit_value;

	ft_print_screen_header("Deposit Screen");
	str_acc_nbr = ft_set_acc_nbr();
	if (ft_check_is_client_exist_by_acc_nbr(str_acc_nbr))
	{
		client_s = ft_find_and_get_client(str_acc_nbr);
		ft_print_client_details(client_s);
		d_deposit_value = ft_set_deposit_value();
		clients_v = ft_v_convert_file_data_to_clients_data();
		ft_deposit_balance_to_client_by_acc_nbr(str_acc_nbr, d_deposit_value, clients_v);
	}
	else 
		printf("\nClient with ID `%s` isn't exist.\n", str_acc_nbr.c_str());
}

double	ft_set_deposit_value()
{
	double	d_deposit_value;

	printf("\nPlease enter Deposit Amount: ");
	cin >> d_deposit_value;
	return (d_deposit_value);
}

void	ft_deposit_balance_to_client_by_acc_nbr(string str_id_nbr, double d_money_ammount, vector <s_client> &clients_v)
{
	char	confirm_deposit_choice;

	confirm_deposit_choice = ft_set_deposit_choice();
	if (toupper(confirm_deposit_choice) == 'Y')
	{
		for (s_client &client_s2 : clients_v)
			if (client_s2.str_id_nbr == str_id_nbr)
			{
				client_s2.d_balance += d_money_ammount;
				printf ("\nDone successfully; `%s` New Balance is: %.3f", client_s2.str_name.c_str(), client_s2.d_balance);
				ft_update_client_data_in_file(clients_v);
				break ;
			}
	}
}

void	ft_press_enter_to_back_to_tranasctions_menu()
{
	cout << "\nPress any key to return to the transactions menu... ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
    ft_show_transactions_and_balances_menu();
}


void	ft_balance_depos_and_withdraw(string str_acc_nbr, double d_deposit_value, vector <s_client> &clients_v)
{
	
}

char	ft_set_deposit_choice()
{
	char	confirm_deposit_choice;

	printf("\nAre you sure that you want to proceed this transaction (Y/N): ");
	cin >> confirm_deposit_choice;
	return (confirm_deposit_choice);
}

double	t_set_deposit_value()
{
	double	d_deposit_value;

	printf("\nPlease enter Deposit Amount: ");
	cin >> d_deposit_value;
	return (d_deposit_value);
}


