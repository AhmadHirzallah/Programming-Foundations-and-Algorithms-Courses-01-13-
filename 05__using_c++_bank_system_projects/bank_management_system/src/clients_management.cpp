#include "clients_management.h"
#include "file_management.h"
#include "constants.h"
#include "user_interface.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <string>	ft_v_get_client_data_fields_from_line(string str_file_formatted_line, string str_fields_separator)
{
	vector <string>	v_client_data_fields;
	short	index;
	short	len;

	len = str_fields_separator.length();
	while ((index = str_file_formatted_line.find(str_fields_separator)) != string::npos)
	{
		v_client_data_fields.emplace_back(str_file_formatted_line.substr(0, index));
		str_file_formatted_line.erase(0, index + len);
	}
	if (str_file_formatted_line != "")
		v_client_data_fields.emplace_back(str_file_formatted_line);
	return (v_client_data_fields);
}

s_client	ft_get_client_data_from_file_line(string str_file_formatted_line, string str_fields_separator)
{
	s_client client_s;
	vector <string>	v_client_data_fields;

	v_client_data_fields = ft_v_get_client_data_fields_from_line(str_file_formatted_line, str_fields_separator);
	client_s.str_id_nbr = v_client_data_fields[0];
	client_s.str_pin_nbr = v_client_data_fields[1];
	client_s.str_name = v_client_data_fields[2];
	client_s.str_phone_nbr = v_client_data_fields[3];
	client_s.d_balance = stod(v_client_data_fields[4]);
	return (client_s);
}

s_client	ft_read_client_data()
{
	s_client	entered_client_s;
	char	want_to_back_to_main_menu;

	want_to_back_to_main_menu = 'z';
	ft_print_screen_header("Add New Client Screen");
	printf("Enter ID Number: ");
	entered_client_s.str_id_nbr = ft_get_id_nbr();
	while (ft_check_is_client_exist_by_acc_nbr(entered_client_s.str_id_nbr))
	{

		cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\nClient with [" << entered_client_s.str_id_nbr << "] ID Number already exists!\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\nPlease enter another Account ID Number or enter `Q` to back to main menu: ";
		getline(cin >> ws, entered_client_s.str_id_nbr);
		want_to_back_to_main_menu = entered_client_s.str_id_nbr[0];
		if (toupper(want_to_back_to_main_menu) == 'Q')
			ft_show_main_menu();
	}
	printf("Enter PIN Number: ");
	getline(cin >> ws, entered_client_s.str_pin_nbr);
	printf("Enter Name: ");
	getline(cin >> ws, entered_client_s.str_name);
	printf("Enter Phone Number: ");
	getline(cin >> ws, entered_client_s.str_phone_nbr);
	printf("Enter Balance: ");
	cin >> entered_client_s.d_balance;
	return (entered_client_s);
}

string	ft_convert_client_record_to_formatted_file_line(s_client client_s, string str_field_separator)
{
	string	str_formatted_file_line;

	str_formatted_file_line = "";
	str_formatted_file_line += client_s.str_id_nbr + str_field_separator;
	str_formatted_file_line += client_s.str_pin_nbr + str_field_separator;
	str_formatted_file_line += client_s.str_name + str_field_separator;
	str_formatted_file_line += client_s.str_phone_nbr + str_field_separator;
	str_formatted_file_line += to_string(client_s.d_balance) + str_field_separator;
	return (str_formatted_file_line);
}

void	ft_add_client_system(string str_filename)
{
	s_client	client_s;

	client_s = ft_read_client_data();
	ft_add_client_record_to_file(client_s);
}

void	ft_add_new_client()
{
	char	want_to_add_more_clients;

	want_to_add_more_clients = 'Y';
	while (toupper(want_to_add_more_clients) == 'Y')
	{
		ft_add_client_system();
		printf("\n\nThe client is addes successfully.\nDo you want to add more clients (Y/N)? ");
		cin >> want_to_add_more_clients;
	}
}

s_client	ft_find_and_get_client(string str_acc_nbr, string str_filename)
{
	vector <s_client>	v_clients_records_s;
	s_client	client_founded_s;

	v_clients_records_s = ft_v_convert_file_data_to_clients_data(str_filename);
	for (s_client &client_s : v_clients_records_s)
	{
		if (client_s.str_id_nbr == str_acc_nbr)
		{
			client_founded_s = client_s;
			return (client_founded_s);
		}
	}
	return (client_founded_s);
}

bool	ft_check_is_client_exist_by_acc_nbr(string str_entered_id_nbr, string str_filename)
{
	vector <s_client>	v_clients_records_s;

	v_clients_records_s = ft_v_convert_file_data_to_clients_data(str_filename);
	for (s_client &client_s : v_clients_records_s)
		if (client_s.str_id_nbr == str_entered_id_nbr)
			return (true);
	return (false);
}

void	ft_print_screen_header(string str_screen_name)
{
	printf("%*s\n", 40, "=====================================");
    printf("%*s\n", 30, str_screen_name.c_str());
    printf("%*s\n\n", 34, "===============================================");
}

string	ft_get_id_nbr()
{
	string	str_id_nbr;

	printf("\nPlease enter Account ID Number: ");
	getline(cin >> ws, str_id_nbr);
	return (str_id_nbr);
}

void	ft_delete_client()
{
	vector <s_client>	clients_v;
	s_client	client_s;
	string	str_entered_id_nbr;

	
	ft_print_screen_header("Delete Client Screen");
	clients_v = ft_v_convert_file_data_to_clients_data();
	str_entered_id_nbr = ft_get_id_nbr();
	if (ft_check_is_client_exist_by_acc_nbr(str_entered_id_nbr))
	{
		client_s = ft_find_and_get_client(str_entered_id_nbr);
		ft_print_client_details(client_s);
		ft_delete_client_by_id_nbr(str_entered_id_nbr);
	}
	else
	{
		printf("\nClient with Account ID Number (%s) isn't exist.\n", str_entered_id_nbr.c_str());
		return ;
	}
}

void	ft_print_client_details(s_client s_client)
{
	printf("\nThe following are the Client details:\n");
	printf("%-20s %s\n", "Account ID Number:", s_client.str_id_nbr.c_str());
	printf("%-20s %s\n", "Account PIN Code:", s_client.str_pin_nbr.c_str());
	printf("%-20s %s\n", "Client Name:", s_client.str_name.c_str());
	printf("%-20s %s\n", "Client Phone Number:", s_client.str_phone_nbr.c_str());
	printf("%-20s %.2f\n", "Client Account Balance:", s_client.d_balance);
}

void	ft_set_deletion_request(string str_id_nbr, vector <s_client> &clients_v)
{
	clients_v = ft_v_convert_file_data_to_clients_data();
	for (s_client &client : clients_v)
	{
		if (client.str_id_nbr == str_id_nbr)
		{
			client.request_to_deletion = true;
			return ;
		}
	}
	return ;
}

char	ft_get_deletion_choice()
{
	char	choice;

	printf("\n\nConfirm Client Deletion\n");
	printf("Are you sure you want to delete this client? (Enter 'Y' to confirm): ");
	cin >> choice;
	return (choice);
}

void	ft_delete_client_by_id_nbr(string str_id_nbr)
{
	vector <s_client>   clients_v;
	char	choice;

	choice = ft_get_deletion_choice();
	if (toupper(choice) == 'Y')
	{
		ft_set_deletion_request(str_id_nbr, clients_v);
		ft_delete_requested_clients_from_file(clients_v);
		printf("\n\nClient Deleted Successfully.\n");
	}
}

void	ft_update_client()
{
	ft_print_screen_header("Update Client Screen");	
	ft_get_client_updated();

}

void	ft_get_client_updated()
{
	string	str_id_nbr;
	vector <s_client>   clients_v;
	char	update_confirmation;

	update_confirmation = 'z';
	clients_v = ft_v_convert_file_data_to_clients_data();
	str_id_nbr = ft_get_id_nbr();
	if (ft_check_is_client_exist_by_acc_nbr(str_id_nbr))
	{
		ft_print_client_details(ft_find_and_get_client(str_id_nbr));
		update_confirmation = ft_get_update_confirmation();
		if (toupper(update_confirmation) == 'Y')
		{

			for (s_client &client : clients_v)
			{
				if (client.str_id_nbr == str_id_nbr)
				{
					client = ft_get_client_new_data(str_id_nbr); 
					break;
				}
			}
			ft_update_client_data_in_file(clients_v);
		}
		else
            printf("\nClient data update cancelled.\n");
	}
	else
		printf("\nClient with Account ID Number (%s) isn't exist.\n", str_id_nbr.c_str()); 
}

char	ft_get_update_confirmation()
{
	char	update_confirmation;
	
	printf("\n\nDo you want to update the client's information? (Enter 'Y' to confirm): ");
	cin >> update_confirmation;
	return (update_confirmation);
}

s_client	ft_get_client_new_data(string str_client_nbr)
{
	s_client	client_s;

	client_s.str_id_nbr = str_client_nbr;
	printf("\n\nPlease enter the updation of the client:\n");
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

vector <s_client>	ft_update_client_data(string str_client_nbr, vector <s_client>   &clients_v)
{
	for (s_client &client : clients_v)
	{
		if (client.str_id_nbr == str_client_nbr)
		{
			client = ft_get_client_new_data(str_client_nbr); 
			return (clients_v);
		}
	}
	return (clients_v);
}

void	ft_find_client()
{
	string	str_id_nbr;

	str_id_nbr = ft_get_id_nbr();
	if (ft_check_is_client_exist_by_acc_nbr(str_id_nbr))
		ft_print_client_details(ft_find_and_get_client(str_id_nbr));
	else
		printf("\nClient with Account ID Number (%s) doesn't exist.\n", str_id_nbr.c_str());
}
