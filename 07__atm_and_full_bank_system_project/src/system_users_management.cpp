#include "system_users_management.h"
#include "file_management.h"
#include "clients_management.h"
#include "interface.h"
#include "constants.h"
#include <iostream>
#include <limits>
#include <cstdio>
#include <cctype>

using namespace std;

void	ft_execute_system_users_main_menu_option(t_e_system_user_main_menu_options entered_choice_t_e)
{
	if (entered_choice_t_e == t_e_system_user_main_menu_options::show_clients_list)
	{
		system("clear");
		ft_show_all_clients_data();
		press_any_key_to_get_main_menu();
	}
	else if (entered_choice_t_e == t_e_system_user_main_menu_options::add_new_client)
	{
		system("clear");
		ft_add_new_client();
		press_any_key_to_get_main_menu();
	}
	else if (entered_choice_t_e == t_e_system_user_main_menu_options::delete_client)
	{
		system("clear");
		ft_delete_client();
		press_any_key_to_get_main_menu();
	}
	else if (entered_choice_t_e == t_e_system_user_main_menu_options::update_client)
	{
		system("clear");
		ft_update_client();
		press_any_key_to_get_main_menu();
	}
	else if (entered_choice_t_e == t_e_system_user_main_menu_options::find_client)
	{
		system("clear");
		ft_find_client();
		press_any_key_to_get_main_menu();
	}
	else if (entered_choice_t_e == t_e_system_user_main_menu_options::manage_transaction)
	{
		system("clear");
		ft_show_atm_main_menu_for_clients_using_user();
		press_any_key_to_get_main_menu();
	}
	else if (entered_choice_t_e == t_e_system_user_main_menu_options::manage_permissions)
	{
		system("clear");
		ft_show_users_management_system();
		press_any_key_to_get_main_menu();
	}
	else if (entered_choice_t_e == t_e_system_user_main_menu_options::logout_from_user)
	{
		system("clear");
		ft_show_login();
	}
}

void	ft_show_users_management_system()
{
	if (!ft_check_access_permission_of_user(manage_users_per))
	{
		ft_show_access_denied_message();
		ft_press_any_key_to_back_to_main_menu_of_user_management_system();
		return ;
	}
	system("clear");
    printf("\n=======================================\n");
    printf("        User Management System         \n");
    printf("      -- Main Menu Options --          \n");
    printf("=======================================\n");
    printf("1. Show Users List\n");
    printf("2. Add New User\n");
    printf("3. Delete User\n");
    printf("4. Update User\n");
    printf("5. Find User\n");
    printf("6. Back to Main Menu\n");
    printf("---------------------------------------\n");		
	ft_execute_users_management_system_option(t_e_users_managing_options(ft_set_users_management_system_option()));
	
}

void	ft_execute_users_management_system_option(t_e_users_managing_options users_management_system_option)
{
	if (users_management_system_option == showing_users_list)
	{
		system("clear");
		ft_show_all_system_users_data();
		ft_press_any_key_to_back_to_user_management_system_menu();
	}
	
	else if (users_management_system_option == adding_new_user)
	{
		system("clear");
		ft_add_new_users();
		ft_press_any_key_to_back_to_user_management_system_menu();
	}
	else if (users_management_system_option == deleting_user)
	{
		system("clear");
		ft_delete_user();
		ft_press_any_key_to_back_to_user_management_system_menu();

	}
	else if (users_management_system_option == updating_user)
	{
		system("clear");
		ft_update_user();
		ft_press_any_key_to_back_to_user_management_system_menu();
	}
	else if (users_management_system_option == finding_user)
	{
		system("clear");
		ft_find_user();
		ft_press_any_key_to_back_to_user_management_system_menu();
	}
	else
	{
		system("clear");
		ft_show_main_menu_for_system_users();
	}
	
}

void	ft_find_user()
{
	vector <s_user> users_v_s;
	string  username_for_search;

	users_v_s = ft_v_convert_data_from_file_to_set_of_users();
	ft_print_screen_header_inside_system_users("--  Find User  --");
	printf("Please enter Username inorder to Search For & Find:  ");
	getline(cin >> ws, username_for_search);
	if (ft_find_user_and_get_ref(username_for_search, users_v_s, g_user_s))
	{
		printf("\n\nThe user details:\n\n");
		ft_small_header_for_user_options();
	}
	else
		printf("\n\nNo Username exist !!!\n\n");
}

void	ft_update_user()
{
	vector <s_user> users_v_s;
	string  username_for_updation;
	char	updation_confirmation;

	users_v_s = ft_v_convert_data_from_file_to_set_of_users();
	ft_print_screen_header_inside_system_users("--  Update User  --");
	printf("Please enter Username inorder to update:  ");
	getline(cin >> ws, username_for_updation);
	if (ft_find_user_and_get_ref(username_for_updation, users_v_s, g_user_s))
	{
		printf("\n\nThe user details:\n\n");
		ft_small_header_for_user_options();
		printf("\n\nAre you sure you want to Update the User?   ");
		cin >> updation_confirmation;
		if (toupper(updation_confirmation) == 'Y')
		{
			ft_set_updation_of_user(users_v_s);
			printf("\n\nUser Updated Successfully.\n\n");
		}
	}
	else
		printf("\n\nNo Username exist !!!\n\n");
}

void	ft_set_updation_of_user(vector <s_user> &users_v_s)
{
	for (s_user &user_s : users_v_s)
	{
		if (user_s.str_username == g_user_s.str_username)
		{
			user_s = ft_set_updation_s(user_s.str_username);
			break;
		}
	}
	ft_update_user_in_a_file(users_v_s);
}

s_user	ft_set_updation_s(string username)
{
	s_user	user_s;

	user_s.str_username = username;
	cout << "\n\nEnter Password? ";
    getline(cin >> ws, user_s.str_password);
	user_s.i_permissions = ft_set_user_permissions();
	return (user_s);
}

void	ft_small_header_for_user_options()
{
	printf("| %-20s | %-12s | %-12s |\n", "Username", "Password", "Permissions");
	printf("================================================================================\n");
	ft_print_user_record_formatted(g_user_s);
}

void	ft_small_header_for_user_data(s_user user_s)
{
	printf("| %-20s | %-12s | %-12s |\n", "Username", "Password", "Permissions");
	printf("================================================================================\n");
	ft_print_user_record_formatted(user_s);
}

void	ft_delete_user()
{
	vector <s_user> users_v_s;
	string	username_for_deletion;
	char	deletion_confirmation;
	s_user	tmp_user_for_deletion;

	users_v_s = ft_v_convert_data_from_file_to_set_of_users();
	ft_print_screen_header_inside_system_users("-- Delete User --");
	printf("Please enter Username inorder to delete:  ");
	getline(cin >> ws, username_for_deletion);
	if (ft_find_user_and_get_ref(username_for_deletion, users_v_s, tmp_user_for_deletion))
	{
		printf("\n\nThe user details:\n\n");
		ft_small_header_for_user_data(tmp_user_for_deletion);
		printf("\n\nAre you sure you want to delete the user?   ");
		cin >> deletion_confirmation;
		if (toupper(deletion_confirmation) == 'Y')
		{
			ft_delete_user_after_marking(ft_mark_user_for_deletion(username_for_deletion));
			printf("\n\nUser Deleted Successfully.\n\n");
		}
	}
	else
		printf("\n\nNo Username exist !!!\n\n");
}

void	ft_delete_user_after_marking(vector <s_user> users_v_s)
{
	ft_delete_marked_user_from_file(users_v_s);
	users_v_s = ft_v_convert_data_from_file_to_set_of_users();
}

vector <s_user>	ft_mark_user_for_deletion(string username_for_deletion)
{
	vector <s_user>	users_v_s;

	users_v_s = ft_v_convert_data_from_file_to_set_of_users();
	for (s_user &user_s : users_v_s)
	{
		if (username_for_deletion == user_s.str_username)
		{
			user_s.b_mark_for_delete = true;
			break ;
		}
	}
	return (users_v_s);
}

void	ft_add_new_users()
{
	char	want_to_add_more_users;

	want_to_add_more_users = 'Y';
	while(toupper(want_to_add_more_users) == 'Y')
	{
		system("clear");
		ft_add_one_user_system();
		printf("\n\nThe user is addes successfully.\nDo you want to add more users(y to proceed)?  ");
		cin >> want_to_add_more_users;
	}
}

void	ft_add_one_user_system()
{
	s_user	user_s;

	user_s = ft_set_user_data();
	ft_add_user_record_to_file(user_s);
}

s_user	ft_set_user_data()
{
	s_user  user_s;
	char	want_to_back_to_system_users_main_menu_choice;

	want_to_back_to_system_users_main_menu_choice = 'z';
	ft_print_screen_header_inside_system_users("Add New User Screen");
	printf("\nEnter User Name:  ");
	getline(cin >> ws, user_s.str_username);
	while (ft_check_is_user_exist_by_username(user_s.str_username))
	{
		printf("\n\nThe user is exist. \n\n\t\t(Details):\n\n");
		ft_small_header_for_user_options();
		printf("Enter Another Username Or Press `q` to quit:  ");
		getline(cin >> ws, user_s.str_username);
		want_to_back_to_system_users_main_menu_choice = user_s.str_username[0];
		if (toupper(want_to_back_to_system_users_main_menu_choice) == 'Q')
		{
			system("clear");
			ft_show_users_management_system();
		}
	}
	printf("\nEnter password:  ");
	getline(cin >> ws, user_s.str_password);
   	user_s.i_permissions = ft_set_user_permissions();
	return (user_s);
}

int	ft_set_user_permissions()
{
	int	permissions;
	char	c_answer;

	c_answer = 'n';
	permissions = 0;
	printf("\n\n(Answer with y/n)");
	printf("\n\nDo you want to give a full access?  ");
	cin >> c_answer;
	if (toupper(c_answer) == 'Y')
		return (-1);
	printf("\n\nDo you want to give access to: \
			\n\n\nShow list of all Clients:   ");
	cin >> c_answer;
	if (toupper(c_answer) == 'Y')
		permissions += show_clients_list_per;
	printf("\n\nAdd New Client:   ");
	cin >> c_answer;
	if (toupper(c_answer) == 'Y')
		permissions += add_new_client_per;
	printf("\n\nDelete a Client:   ");
	cin >> c_answer;
	if (toupper(c_answer) == 'Y')
		permissions += delete_client_per;
	printf("\n\nUpdate a Client:   ");
	cin >> c_answer;
	if (toupper(c_answer) == 'Y')
		permissions += update_client_per;
	printf("\n\nFind a Client:   ");
	cin >> c_answer;
	if (toupper(c_answer) == 'Y')
		permissions += find_client_per;
	printf("\n\nManage Transactions:   ");
	cin >> c_answer;
	if (toupper(c_answer) == 'Y')
		permissions += manage_transaction_per;
	printf("\n\nManage Users:   ");
	cin >> c_answer;
	if (toupper(c_answer) == 'Y')
		permissions += manage_users_per;
	return (permissions);
}

bool	ft_check_is_user_exist_by_username(string username)
{
	vector <s_user>   users_records_v_s;

	users_records_v_s = ft_v_convert_data_from_file_to_set_of_users();
	
	for (s_user &user_s : users_records_v_s)
		if (user_s.str_username == username)
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\nUser with ["
			<< user_s.str_username
			<< "] Username already exists!\n"
			<< "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n";
			return (true);
		}
	return (false);
}

bool	ft_check_access_permission_of_user(t_e_system_user_permissions the_permission)
{
	if (g_user_s.i_permissions == all_per)
		return (true);
	else if ((g_user_s.i_permissions & the_permission) == the_permission)
		return (true);
	else
		return (false);
}

void	ft_press_any_key_to_back_to_main_menu_of_user_management_system()
{
	cout << "\nPress (Enter ⏎) key to return to user management system main menu... ";
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.get();
	system("clear");
	ft_show_main_menu_for_system_users();
}

void ft_press_any_key_to_back_to_user_management_system_menu()
{
	cout << "\nPress (Enter ⏎) key to return to user management system main menu... ";
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.get();
	system("clear");
	ft_show_users_management_system();
}

void	ft_show_access_denied_message()
{
	cout << "\n------------------------------------\n";
    cout << "Access Denied, \nYou dont Have Permission To Do this,\nPlease Conact Your Admin.";
    cout << "\n------------------------------------\n";
}

void	ft_show_all_system_users_data()
{
	vector <s_user>	users_v_s;

	users_v_s = ft_v_convert_data_from_file_to_set_of_users();
	printf("\n================================================================================\n");
    printf("================================================================================\n");
    printf("\n\t\t\t\t\tUser List (%zu) User(s).\n", users_v_s.size());
    printf("================================================================================\n");
    printf("================================================================================\n");
    printf("| %-20s | %-12s | %-12s |\n", "Username", "Password", "Permissions");
    printf("================================================================================\n");
    for (const s_user& user_s : users_v_s) 
        ft_print_user_record_formatted(user_s);
    printf("================================================================================\n");
    printf("================================================================================\n");	
}

void ft_print_user_record_formatted(s_user user_s)
{
	printf("| %-20s | %-12s | %-12d |\n\n",
           user_s.str_username.c_str(),
           user_s.str_password.c_str(),
           user_s.i_permissions);
}

t_e_users_managing_options	ft_set_users_management_system_option()
{
	short	choice;

	printf("Please enter your choice [1 - 6]:  ");
	cin >> choice;
	return ((t_e_users_managing_options) choice);
}


bool	ft_find_user_and_get_ref(string str_username, vector <s_user> user_v_s, s_user &user_s)
{
	for (s_user &tmp_user_s : user_v_s)
	{
		if (tmp_user_s.str_username == str_username)
		{
			user_s = tmp_user_s;
			return (true);
		}
	}
	return (false);
}

/*bool	ft_find_client_and_get_ref(string str_username, vector <s_client> client_v_s, s_client client_s)
{
	for (s_client &tmp_client_s : client_v_s)
	{
		if (tmp_client_s.str_name == str_username)
		{
			client_s = tmp_client_s;
			return (true);
		}
	}
	return (false);
}*/

short	ft_get_system_user_main_menu_option()
{
	short	choice;

	choice = 10;
	while (!(choice >= 1 && choice <= 9))
	{
		printf("Please enter your choice [1 - 9]:  ");
		cin >> choice;
	}
	return (choice);
}

void	ft_show_all_clients_data()
{
	if (!ft_check_access_permission_of_user(show_clients_list_per))
	{
		ft_show_access_denied_message();
		ft_press_any_key_to_back_to_main_menu_of_user_management_system();
		return ;
	}
	vector <s_client> client_v_s;

	client_v_s = ft_v_convert_data_from_file_to_set_of_clients(CLIENTS_FILENAME);
	printf("\n__________________________________________________________________________________________________________________\n");
	printf("__________________________________________________________________________________________________________________\n");
	printf("\n\t\t\t\t\tClient List (%zu) Client(s).\n", client_v_s.size());
	printf("__________________________________________________________________________________________________________________\n");
	printf("__________________________________________________________________________________________________________________\n");
	printf("| %-15s | %-10s | %-40s | %-18s | %-15s |\n", "Account Number", "Pin Code", "Client Name", "Phone", "Balance");
	printf("__________________________________________________________________________________________________________________\n");
	for (s_client &client_s : client_v_s)
		ft_print_client_record_formatted(client_s);
	printf("__________________________________________________________________________________________________________________\n");
	printf("__________________________________________________________________________________________________________________\n");
	printf("__________________________________________________________________________________________________________________\n");
	printf("__________________________________________________________________________________________________________________\n");
}

void	ft_print_client_record_formatted(s_client client_s)
{
	printf("| %-15s | %-10s | %-40s | %-18s | %-15.2f |\n",
			client_s.str_id_nbr.c_str(),
			client_s.str_pin_nbr.c_str(),
			client_s.str_name.c_str(),
			client_s.str_phone_nbr.c_str(),
			client_s.d_balance);
}

void	press_any_key_to_get_main_menu()
{
	cout << "\nPress (Enter ⏎) key to return to the main menu... ";
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.get();
	system("clear");
	ft_show_main_menu_for_system_users();
}

void	ft_add_new_client()
{
	if (!ft_check_access_permission_of_user(add_new_client_per))
	{
		ft_show_access_denied_message();
		ft_press_any_key_to_back_to_main_menu_of_user_management_system();
		return ;
	}
	char	want_to_add_more_choice;

	ft_print_screen_header_inside_system_users("Add New Client Screen");
	want_to_add_more_choice = 'Y';
	while (toupper(want_to_add_more_choice) == 'Y')
	{
		ft_add_client_system();
		printf("\n\nThe client is addes successfully.\nDo you want to add more clients (y to proceed)?  ");
		cin >> want_to_add_more_choice;
	}
}

void	ft_add_client_system()
{
	s_client	client_s;

	client_s = ft_set_client_data();
	ft_add_client_record_to_file(client_s);
}

s_client	ft_set_client_data()
{
	s_client	client_s;
	char	want_to_back_to_main_menu_choice;

	want_to_back_to_main_menu_choice = 'z';
	printf("Enter ID Number: ");
	getline(cin >> ws, client_s.str_id_nbr);
	while (ft_check_is_client_exist_by_id_nbr(client_s.str_id_nbr))
	{
		printf("Enter Another ID Number Or Press `q` to quit:  ");
		getline(cin >> ws, client_s.str_id_nbr);
		want_to_back_to_main_menu_choice = client_s.str_id_nbr[0];
		if (toupper(want_to_back_to_main_menu_choice) == 'Q')
		{
			system("clear");
			ft_show_main_menu_for_system_users();
		}
	}
	printf("Enter PIN Number: ");
	getline(cin >> ws, client_s.str_pin_nbr);
	printf("Enter Name: ");
	getline(cin >> ws, client_s.str_name);
	printf("Enter Phone Number: ");
	getline(cin >> ws, client_s.str_phone_nbr);
	printf("Enter Balance: ");
	cin >> client_s.d_balance;
	return (client_s);
}

bool	ft_check_is_client_exist_by_id_nbr(string id_nbr)
{
	vector <s_client>   clients_records_v_s;

	clients_records_v_s = ft_v_convert_data_from_file_to_set_of_clients();
	for (s_client &client_s : clients_records_v_s)
		if (client_s.str_id_nbr == id_nbr)
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\nClient with ["
			<< client_s.str_id_nbr
			<< "] ID Number already exists!\n"
			<< "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n";
			return (true);
		}
	return (false);
}

void    ft_print_screen_header_inside_system_users(string str_screen_name)
{
	printf("%*s\n", 40, "=====================================");
	printf("%*s\n", 30, str_screen_name.c_str());
	printf("%*s\n\n", 34, "===============================================");
}

void	ft_delete_client()
{
	if (!ft_check_access_permission_of_user(delete_client_per))
	{
		ft_show_access_denied_message();
		ft_press_any_key_to_back_to_main_menu_of_user_management_system();
		return ;
	}
	vector <s_client>   clients_records_v_s;
	string	id_nbr_for_deletion;

	ft_print_screen_header_inside_system_users("Delete Client Screen");
	printf("Please enter ID Number of client in order to delete:  ");
	getline(cin >> ws, id_nbr_for_deletion);
	clients_records_v_s = ft_v_convert_data_from_file_to_set_of_clients();
	if (ft_find_client_and_get_ref(id_nbr_for_deletion, clients_records_v_s, g_client_s))
	{
		ft_print_client_details(g_client_s);
		ft_delete_client_by_id_nbr(id_nbr_for_deletion);
	}
}

void    ft_print_client_details(s_client client_s)
{
	printf("\n\n\nThe following are the Client details:\n\n");
	printf("%-20s %s\n", "Account ID Number:", client_s.str_id_nbr.c_str());
	printf("%-20s %s\n", "Account PIN Code:", client_s.str_pin_nbr.c_str());
	printf("%-20s %s\n", "Client Name:", client_s.str_name.c_str());
	printf("%-20s %s\n", "Client Phone Number:", client_s.str_phone_nbr.c_str());
	printf("%-20s %.2f\n", "Client Account Balance:", client_s.d_balance);
}

void	ft_delete_client_by_id_nbr(string id_nbr_for_deletion)
{
	vector <s_client>	clients_records_v_s;
	char	deletion_choice;

	clients_records_v_s = ft_v_convert_data_from_file_to_set_of_clients();
	deletion_choice = ft_set_deletion_choice();
	if (toupper(deletion_choice) == 'Y')
	{
		ft_set_deletion_mark_request(id_nbr_for_deletion, clients_records_v_s);
		ft_delete_marked_requested_clients_from_file(clients_records_v_s);
		printf("\n\nClient Deleted Successfully.\n");
	}

}

char	ft_set_deletion_choice()
{
	char	choice;

	printf("\n\nConfirming client deletion:\n");
	printf("Are you sure you want to delete this client? (Enter 'y' to proceed):  ");
	cin >> choice;
	return (choice);
}

void	ft_set_deletion_mark_request(const string &id_nbr_for_deletion, vector <s_client> &clients_records_v_s)
{
	for (s_client &client_s : clients_records_v_s)
	{
		if (client_s.str_id_nbr == id_nbr_for_deletion)
		{
			client_s.request_to_deletion = true;
			return ;
		}
	}
	return ;
}

void	ft_update_client()
{
	if (!ft_check_access_permission_of_user(update_client_per))
	{
		ft_show_access_denied_message();
		ft_press_any_key_to_back_to_main_menu_of_user_management_system();
		return ;
	}
	string  id_nbr_for_updation;
	vector <s_client>   clients_records_v_s;

	ft_print_screen_header_inside_system_users("Update Client Screen");
	clients_records_v_s = ft_v_convert_data_from_file_to_set_of_clients();
	printf("Please enter ID Number of client in order to update:  ");
	getline(cin >> ws, id_nbr_for_updation);
	if (ft_find_client_and_get_ref(id_nbr_for_updation, clients_records_v_s, g_client_s))
	{
		ft_print_client_details(g_client_s);
		ft_get_client_updated(id_nbr_for_updation, clients_records_v_s);
	}
}

void	ft_get_client_updated(string  id_nbr_for_updation, vector <s_client> clients_records_v_s)
{
	char	update_confirmation;

	update_confirmation = ft_set_updation_choice();
	if (toupper(update_confirmation) == 'Y')
	{
		for (s_client &client_s : clients_records_v_s)
		{
			if (client_s.str_id_nbr == id_nbr_for_updation)
			{
				client_s = ft_update_client_data(id_nbr_for_updation);
				ft_update_client_in_file(clients_records_v_s);
				g_client_s = client_s;
				return ;
			}
		}
		printf("\nClient with Account ID Number (%s) isn't exist.\n", id_nbr_for_updation.c_str());
	}
	else
		printf("\nClient data update cancelled.\n");
}

char	ft_set_updation_choice()
{
	char	choice;

	printf("\n\nConfirming client updation:\n");
	printf("\nAre you sure you want to update this client? (Enter 'y' to proceed):  ");
	cin >> choice;
	return (choice);
}

s_client	ft_update_client_data(string str_client_nbr)
{
	s_client	client_s;

	printf("\n\nPlease enter the updation of the client:\n");
	client_s.str_id_nbr = str_client_nbr;
	printf("PIN Number: ");
	getline(cin >> ws, client_s.str_pin_nbr);
	printf("Name: ");
	getline(cin >> ws, client_s.str_name);
	printf("Phone Number: ");
	getline(cin >> ws, client_s.str_phone_nbr);
	printf("Balance: ");
	cin >> client_s.d_balance;
	return (client_s);
}

void	ft_find_client()
{
	if (!ft_check_access_permission_of_user(find_client_per))
	{
		ft_show_access_denied_message();
		ft_press_any_key_to_back_to_main_menu_of_user_management_system();
		return ;
	}
	string	id_client_to_search_for;
	vector <s_client>	clients_records_v_s;

	ft_print_screen_header_inside_system_users("Find Client Screen");
	printf("Please enter ID Number of client in order to look for:  ");
	getline(cin >> ws, id_client_to_search_for);
	clients_records_v_s = ft_v_convert_data_from_file_to_set_of_clients();
	if (ft_find_client_and_get_ref(id_client_to_search_for , clients_records_v_s, g_client_s))
		ft_print_client_details(g_client_s);
	else
		printf("\nClient with Account ID Number (%s) isn't exist.\n", id_client_to_search_for.c_str());
}
