#include "clients_management.h"
#include "user_interface.h"
#include "constants.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


void    ft_print_client_record(s_client s_client)
{
    printf("| %-15s | %-10s | %-40s | %-18s | %-15.2f |\n",
            s_client.str_id_nbr.c_str(),
            s_client.str_pin_nbr.c_str(),
            s_client.str_name.c_str(),
            s_client.str_phone_nbr.c_str(),
            s_client.d_balance);
}

void	ft_show_all_clients_data(string str_filename)
{
	vector <s_client>	v_clients_s;

	v_clients_s = ft_v_convert_file_data_to_clients_data(str_filename);
	printf("\n__________________________________________________________________________________________________________________\n");
    printf("__________________________________________________________________________________________________________________\n");
    printf("\n\t\t\t\t\tClient List (%zu) Client(s).\n", v_clients_s.size());
    printf("__________________________________________________________________________________________________________________\n");
    printf("__________________________________________________________________________________________________________________\n");
    printf("| %-15s | %-10s | %-40s | %-18s | %-15s |\n", "Account Number", "Pin Code", "Client Name", "Phone", "Balance");
    printf("__________________________________________________________________________________________________________________\n");
    for (s_client &client : v_clients_s)
        ft_print_client_record(client);
    printf("__________________________________________________________________________________________________________________\n");
    printf("__________________________________________________________________________________________________________________\n");
}

void press_any_key_to_get_main_menu() 
{
    std::cout << "\nPress (Enter ⏎) key to return to the main menu... ";
    std::cin.ignore(); // To consume any leftover characters in the buffer
    std::cin.get();
    ft_show_main_menu();
}

void	ft_execute_main_menu_option(e_main_menu_options entered_option)
{
	if (entered_option == e_main_menu_options::show_clients_list)
	{
		system("clear");
		ft_show_all_clients_data(CLIENTS_FILENAME);
		press_any_key_to_get_main_menu();
	}
	else if (entered_option == e_main_menu_options::add_new_client)
	{
		system("clear");
		ft_add_new_client();
		press_any_key_to_get_main_menu();
	}
	else if (entered_option == e_main_menu_options::delete_client)
	{
		system("clear");
		ft_delete_client();
		press_any_key_to_get_main_menu();
	}
	else if (entered_option == e_main_menu_options::update_client)
	{
		system("clear");
		ft_update_client();
		press_any_key_to_get_main_menu();
	}
	else if (entered_option == e_main_menu_options::find_client)
	{
		system("clear");
		ft_find_client();
		press_any_key_to_get_main_menu();
	}
	else if (entered_option == e_main_menu_options::quit)
	{
		system("clear");
		printf("\n");
		printf("*************************************\n");
		printf("*        Exiting Application       *\n");
	    printf("*************************************\n");
	    printf("\nThank you for using our client management system. Goodbye!\n\n");
	    exit(0);
	}
}

short	ft_get_main_menu_option()
{
	short	entered_option;
	
	entered_option = 0;
	while (!(entered_option >= 1 && entered_option <= 6))
	{
		printf("Please enter your choice [1-6]: ");
		cin >> entered_option;
	}
	return (entered_option);
}

void	ft_show_main_menu()
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
    printf("6. Exit\n");
    printf("---------------------------------------\n");
	ft_execute_main_menu_option((e_main_menu_options)ft_get_main_menu_option());
}
