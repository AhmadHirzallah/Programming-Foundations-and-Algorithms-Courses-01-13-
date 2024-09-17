#ifndef USER_INTERFACE_H
 #define USER_INTERFACE_H

#include <string>
#include "file_management.h"

enum	e_main_menu_options
{
	show_clients_list = 1,
	add_new_client = 2,
	delete_client,
	update_client,
	find_client,
	transaction = 6,
	quit
};

void    ft_show_main_menu();
short   ft_get_main_menu_option();
void    ft_execute_main_menu_option(e_main_menu_options entered_option);
void    ft_show_all_clients_data(string str_filename = CLIENTS_FILENAME);
void    ft_print_client_record(s_client s_client);
void press_any_key_to_get_main_menu();

#endif

