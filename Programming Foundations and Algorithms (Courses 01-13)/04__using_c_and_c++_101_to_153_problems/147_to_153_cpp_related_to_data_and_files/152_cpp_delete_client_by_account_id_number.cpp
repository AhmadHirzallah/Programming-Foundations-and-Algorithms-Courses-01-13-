#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct	s_clients
{
	string	str_client_id_nbr;
	string	str_pin_nbr;
	string	str_client_name;
	string	str_client_phone_nbr;
	double	d_account_balance;
	bool	request_for_delete = false;
};

const string	STR_CLIENTS_FILENAME = "Clients.txt";

string	ft_get_client_id_nbr_to_delete()
{
	string	str_entered_acc_nbr;

	printf("\nPlease enter the client ID Number: ");
	getline(cin >> ws, str_entered_acc_nbr);
	return (str_entered_acc_nbr);
}

vector <string>	ft_get_client_data_fields_from_file_line(string str_file_line, string str_fields_separator = "#//#")
{
	vector <string>	v_str_data_fields;
	unsigned short	separator_len;
	size_t	index;

	separator_len = str_fields_separator.length();
	while ((index = str_file_line.find(str_fields_separator)) != string::npos)
	{
		v_str_data_fields.emplace_back(str_file_line.substr(0, index));
		str_file_line.erase(0, index + separator_len);
	}
	if (str_file_line != "")
		v_str_data_fields.emplace_back(str_file_line);
	return (v_str_data_fields);
}

s_clients	ft_s_get_client_data_from_file_line(string str_file_line, string str_fields_separator = "#//#")
{
	s_clients	s_tmp_client;
	vector <string>	v_str_data_fields;

	v_str_data_fields = ft_get_client_data_fields_from_file_line(str_file_line, str_fields_separator);
//	A000#//#1999#//#Ahmad Hirzallah#//#0792001744#//#99500.000000#//#	
	s_tmp_client.str_client_id_nbr = v_str_data_fields[0];
	s_tmp_client.str_pin_nbr = v_str_data_fields[1];
	s_tmp_client.str_client_name = v_str_data_fields[2];
	s_tmp_client.str_client_phone_nbr = v_str_data_fields[3];
	s_tmp_client.d_account_balance = stod(v_str_data_fields[4]);
	return (s_tmp_client);
}

vector <s_clients>	ft_v_s_get_clients_data_from_file(string str_file_name = STR_CLIENTS_FILENAME)
{
	fstream	file_client_data;
	vector <s_clients>	v_str_client_data_fields;
	s_clients	s_tmp_client;
	string	str_file_line;
	
	file_client_data.open(str_file_name, ios::in);
	if (file_client_data.is_open())
	{
		while (getline(file_client_data, str_file_line))
		{
			s_tmp_client = ft_s_get_client_data_from_file_line(str_file_line);
			v_str_client_data_fields.emplace_back(s_tmp_client);
		}
		file_client_data.close();
	}
	return (v_str_client_data_fields);
}

void	ft_print_client_data_details(s_clients &client)
{
	printf("\nThe following are the client details:\n\n");
	printf("%-20s %s\n", "Account ID Number:", client.str_client_id_nbr.c_str());
	printf("%-20s %s\n", "Account PIN Code:", client.str_pin_nbr.c_str());
	printf("%-20s %s\n", "Client Name:", client.str_client_name.c_str());
	printf("%-20s %s\n", "Client Phone Number:", client.str_client_phone_nbr.c_str());
	printf("%-20s %.2f\n", "Client Account Balance:", client.d_account_balance);
}

bool	ft_find_client(string str_acc_id_nbr, s_clients &client, string str_file_name = STR_CLIENTS_FILENAME)
{
	vector <s_clients>  v_all_clients;

	v_all_clients = ft_v_s_get_clients_data_from_file(str_file_name);
	for (s_clients &s_client : v_all_clients)
	{
		if (s_client.str_client_id_nbr == str_acc_id_nbr)
		{
			client = s_client;
			ft_print_client_data_details(client);
			return (true);
		}
	}
	printf ("\nClient with account number `%s` isn't exist.\n", str_acc_id_nbr.c_str());
	return (false);
}

void	ft_v_s_set_deletion_request(string str_acc_id_nbr, vector <s_clients>  &v_all_clients)
{
	for (s_clients &client : v_all_clients)
	{
		if (client.str_client_id_nbr == str_acc_id_nbr)
		{
			client.request_for_delete = true;
			return ;
		}
	}
	return ;
}

string	ft_convert_client_data_to_formatted_line(s_clients &client_s, string str_field_separator = "#//#")
{
	string	formatted_data_line;

	formatted_data_line = "";
	formatted_data_line += client_s.str_client_id_nbr+ str_field_separator;
	formatted_data_line += client_s.str_pin_nbr + str_field_separator;
	formatted_data_line += client_s.str_client_name + str_field_separator;
	formatted_data_line += client_s.str_client_phone_nbr + str_field_separator;
	formatted_data_line += to_string(client_s.d_account_balance) + str_field_separator;
	return (formatted_data_line);
}


void	ft_delete_file_record_and_recreate_file(vector <s_clients> &v_all_clients, string str_file_name = STR_CLIENTS_FILENAME)
{
	fstream	file_client_data;

	file_client_data.open(str_file_name, ios::out);
	if (file_client_data.is_open())
	{
		for (s_clients &s_client : v_all_clients)
		{
			if (s_client.request_for_delete != true)
				file_client_data << ft_convert_client_data_to_formatted_line(s_client) << endl;
		}
		file_client_data.close();
	}
}

void	ft_delete_client_by_id_nbr(string str_acc_id_nbr, string str_file_name = STR_CLIENTS_FILENAME)
{
	vector <s_clients>	v_all_clients;
	s_clients	s_client;
	char	confirm_deletion;

	confirm_deletion = 'N';
	v_all_clients = ft_v_s_get_clients_data_from_file(str_file_name);
	if (ft_find_client(str_acc_id_nbr, s_client))
	{
		printf("\nYou are about to permanently remove the account for this client. Please confirm that you wish to proceed, as this action cannot be undone (y/n): ");
		cin >> confirm_deletion;
		if (tolower(confirm_deletion) == 'y' )
		{
			ft_v_s_set_deletion_request(str_acc_id_nbr, v_all_clients);
			ft_delete_file_record_and_recreate_file(v_all_clients);
			v_all_clients = ft_v_s_get_clients_data_from_file(str_file_name);
			printf("\n\nClient Deleted Successfully.\n");
		}
	}
}

int	main ()
{
	ft_delete_client_by_id_nbr(ft_get_client_id_nbr_to_delete(), STR_CLIENTS_FILENAME);
	return (0);
}
