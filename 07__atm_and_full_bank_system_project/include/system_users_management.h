#ifndef SYSTEM_USERS_MANAGEMENT_H
#define SYSTEM_USERS_MANAGEMENT_H

#include <vector>
#include <string>
#include "system_user_struct.h"
#include "client_struct.h"
#include "clients_management.h"
#include <iostream>

using namespace std;

// Enumeration for system user main menu options
typedef enum	e_system_user_main_menu_options
{
    show_clients_list = 1,
    add_new_client,
    delete_client,
    update_client,
    find_client,
    manage_transaction,
    manage_permissions,
    logout_from_user
}	t_e_system_user_main_menu_options;

typedef enum	e_system_user_permissions
{
	all_per = -1,
	show_clients_list_per = 1,
	add_new_client_per = 2,
	delete_client_per = 4,
	update_client_per = 8,
	find_client_per = 16,
	manage_transaction_per = 32,
	manage_users_per = 64
}	t_e_system_user_permissions;

typedef enum	e_users_managing_options
{
	showing_users_list = 1,
	adding_new_user,
	deleting_user = 3,
	updating_user,
	finding_user = 5,
	backing_to_system_of_users_main_menu_options = 6
}	t_e_users_managing_options;


// Function Prototypes
void ft_execute_system_users_main_menu_option(t_e_system_user_main_menu_options entered_choice_t_e);
bool ft_find_user_and_get_ref(string str_username, vector<s_user> user_v_s, s_user &user_s);
short ft_get_system_user_main_menu_option();
void ft_show_all_clients_data();
void    ft_print_client_record_formatted(s_client client_s);
void press_any_key_to_get_main_menu();
void    ft_add_new_client();
void    ft_add_client_system();
s_client    ft_set_client_data();
bool    ft_check_is_client_exist_by_id_nbr(string id_nbr);
void    ft_print_screen_header_inside_system_users(string str_screen_name);
void    ft_delete_client();
void    ft_print_client_details(s_client client_s);
void    ft_delete_client_by_id_nbr(string id_nbr_for_deletion);
char    ft_set_deletion_choice();
void    ft_set_deletion_mark_request(const string &id_nbr_for_deletion, vector <s_client> &clients_records_v_s);
void    ft_update_client();
s_client    ft_update_client_data(string str_client_nbr);
char    ft_set_updation_choice();
void    ft_get_client_updated(string  id_nbr_for_updation, vector <s_client> clients_records_v_s);
void    ft_find_client();
void    ft_execute_users_management_system_option(t_e_users_managing_options users_management_system_option);
void    ft_show_users_management_system();
void	ft_print_user_record_formatted(s_user user_s);
t_e_users_managing_options  ft_set_users_management_system_option();
bool    ft_find_user_and_get_ref(string str_username, vector <s_user> user_v_s, s_user &user_s);
void    ft_show_all_system_users_data();
void	ft_press_any_key_to_back_to_user_management_system_menu();
void    ft_show_access_denied_message();
bool    ft_check_access_permission_of_user(t_e_system_user_permissions the_permission);
void    ft_press_any_key_to_back_to_main_menu_of_user_management_system();
void	ft_press_any_key_to_back_to_user_management_system_menu();
void    ft_add_one_user_system();
void    ft_add_new_users();
bool	ft_check_is_user_exist_by_username(string username);
s_user	ft_set_user_data();
int	ft_set_user_permissions();
void	ft_update_user();
void	ft_set_updation_of_user(vector <s_user> &users_v_s);
s_user	ft_set_updation_s(string username);
void	ft_delete_user_after_marking(vector <s_user> &users_v_s);
void	ft_small_header_for_user_options();
void	ft_find_user();


//bool    ft_find_client_and_get_ref(string str_username, vector <s_client> client_v_s, s_client &client_s);



#endif // SYSTEM_USERS_MANAGEMENT_H

