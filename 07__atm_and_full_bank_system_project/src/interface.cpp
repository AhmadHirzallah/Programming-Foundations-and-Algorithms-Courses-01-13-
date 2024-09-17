#include "constants.h"
#include "interface.h"
#include "clients_management.h"
#include "system_users_management.h"
#include "client_struct.h"
#include "atm_management.h"
#include "file_management.h"
#include "system_user_struct.h"
#include "main.h"
#include <iostream>  // For std::string
#include <cstdio>    // For printf
#include <cstdlib>   // For system


using namespace std;


void	ft_show_atm_main_menu_for_clients()
{
    system("clear");
    printf("\n=======================================\n");
    printf("          Welcome to the ATM          \n");
    printf("       --ATM Main Menu Screen--      \n");
    printf("=======================================\n");
    printf("1. Quick Withdraw\n");
    printf("2. Normal Withdraw (Set by client)\n");
    printf("3. Deposit\n");
    printf("4. Check Balance\n");
    printf("5. Logout\n");
    printf("---------------------------------------\n");
	ft_execute_atm_main_menu_option((t_e_atm_main_menu_options)ft_set_atm_main_menu_option());
}

void	ft_show_atm_main_menu_for_clients_using_user()
{
	if (!ft_check_access_permission_of_user(manage_transaction_per))
	{
		ft_show_access_denied_message();
		ft_press_any_key_to_back_to_main_menu_of_user_management_system();
		return ;
	}
    system("clear");
    printf("\n=======================================\n");
    printf("          Welcome to the ATM          \n");
    printf("       --ATM Main Menu Screen--      \n");
    printf("=======================================\n");
    printf("1. Quick Withdraw\n");
    printf("2. Normal Withdraw (Set by client)\n");
    printf("3. Deposit\n");
    printf("4. Check Balance\n");
    printf("5. Logout\n");
    printf("---------------------------------------\n");
	ft_execute_atm_main_menu_option_using_user((t_e_atm_main_menu_options)ft_set_atm_main_menu_option());
}

void	ft_show_main_menu_for_system_users()
{
	system("clear");
	printf("\n=======================================\n");
    printf("          Welcome to the Bank          \n");
    printf("      Management System Interface      \n");
    printf("=======================================\n");
    printf("1. Show Clients List\n");
    printf("2. Add New Client\n");
    printf("3. Delete Client\n");
    printf("4. Update Client\n");
    printf("5. Find Client\n");
	printf("6. Manage Transactions and Balances\n");
	printf("7. Manage Users & Permissions\n");
    printf("8. Logout\n");
    printf("---------------------------------------\n");
	ft_execute_system_users_main_menu_option((t_e_system_user_main_menu_options)ft_get_system_user_main_menu_option());
}

void	ft_display_login_header()
{
	system("clear");
	printf("+---------------------------------------------------------+\n");
	printf("|                     Login Screen                      |\n");
    printf("+---------------------------------------------------------+\n");
    printf("|                                                       |\n");
}

//bool	ft_get_login_ref(string  str_user_id, vector <s_client> v_clients_s, )

void	ft_show_login()
{
	vector <s_client>   v_clients_s;
	vector <s_user> user_v_s;
	string	str_user_id;
	string	str_password;
	char	want_to_login_again;

	v_clients_s = ft_v_convert_data_from_file_to_set_of_clients(CLIENTS_FILENAME);
	user_v_s = ft_v_convert_data_from_file_to_set_of_users(USERS_FILENAME);
	ft_display_login_header();
	printf("+---------------------------------------------------------+\n");
	want_to_login_again = 'Y';
	while (toupper(want_to_login_again) == 'Y')
	{
		ft_set_id_and_password(str_user_id, str_password);
		if (ft_find_client_and_get_ref(str_user_id, v_clients_s, g_client_s))
			ft_perform_login_as_client(str_user_id, str_password);
		else
			ft_perform_login_as_system_user(str_user_id, str_password);
		want_to_login_again = ft_back_after_login_fail_and_check_if_wanting_to_login_again();
	}
}



void	ft_print_screen_header(string str_screen_name)
{
	printf("%*s\n", 40, "=====================================");
	printf("%*s\n", 30, str_screen_name.c_str());
	printf("%*s\n\n", 34, "===============================================");
}

