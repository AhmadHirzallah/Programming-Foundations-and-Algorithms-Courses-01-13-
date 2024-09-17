#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

const string	CLIENTS_FILENAME = "Clients.txt";

struct	s_client
{
	string	str_id_nbr;
	string	str_pin_nbr;
	string	str_name;
	string	str_phone_nbr;
	double	d_account_balance;
	bool	request_for_delete = false;
};

vector <string>	ft_get_str_client_data_fields(string str_formatted_file_line, string str_fields_separator = "#//#")
{
	vector <string>	v_str_client_data_fields;
	unsigned short	fields_separator_len;
	short	index;

	fields_separator_len = str_fields_separator.length();
	while ((index = str_formatted_file_line.find(str_fields_separator)) != string::npos)
	{
		v_str_client_data_fields.emplace_back(str_formatted_file_line.substr(0, index));
		str_formatted_file_line.erase(0, index + fields_separator_len);
	}
	if (str_formatted_file_line != "")
		v_str_client_data_fields.emplace_back(str_formatted_file_line);
	return (v_str_client_data_fields);
}

s_client	ft_get_client_data_from_line(string str_formatted_file_line, string str_fields_separator = "#//#")
{
	s_client client_s;
	vector <string>	v_str_client_data_fields;

	v_str_client_data_fields = ft_get_str_client_data_fields(str_formatted_file_line);
	client_s.str_id_nbr = v_str_client_data_fields[0];
	client_s.str_pin_nbr = v_str_client_data_fields[1];
	client_s.str_name = v_str_client_data_fields[2];
	client_s.str_phone_nbr = v_str_client_data_fields[3];
	client_s.d_account_balance = stod(v_str_client_data_fields[4]);
	return (client_s);
}

vector <s_client>	ft_v_get_clients_from_file(string str_filename = CLIENTS_FILENAME)
{
	fstream	file_of_clients;
	vector <s_client>	v_clients_s;
	string	str_formatted_file_line;

	file_of_clients.open(str_filename, ios::in);
	if (file_of_clients.is_open())
	{
		while(getline(file_of_clients, str_formatted_file_line))
		{
			v_clients_s.emplace_back(ft_get_client_data_from_line(str_formatted_file_line));
		}
		file_of_clients.close();
	}
	return (v_clients_s);
}

bool	ft_search_if_client_exist (string str_acc_nbr, s_client &client_s, string str_filename = CLIENTS_FILENAME)
{
	vector <s_client>   v_clients_s;

	v_clients_s = ft_v_get_clients_from_file(str_filename);
	for (s_client &client_s2 : v_clients_s)
	{
		if (client_s2.str_id_nbr == str_acc_nbr)
		{
			client_s = client_s2;
			return (true);
		}
	}
	return (false);
}

void	ft_print_client_data_details(s_client client)
{
	printf("\nThe following are the client details\n\n");
	printf("%-30s: %s\n", "Account ID Number", client.str_id_nbr.c_str());
	printf("%-30s: %s\n", "Account PIN Number", client.str_pin_nbr.c_str());
	printf("%-30s: %s\n", "Client Name", client.str_name.c_str());
	printf("%-30s: %s\n", "Client Phone Number", client.str_phone_nbr.c_str());
	printf("%-30s: %.2f\n", "Client Account Balance", client.d_account_balance);
}

s_client	ft_get_client_info_updation(string str_acc_nbr)
{
	s_client    client_s;

	client_s.str_id_nbr = str_acc_nbr;
	printf("\n\nPlease enter the updation of the client:\n");
	printf("PIN Number: ");
	getline(cin >> ws, client_s.str_pin_nbr);
	printf("Client Name: ");
	getline(cin >> ws, client_s.str_name);
	printf("Phone Number: ");
	getline(cin >> ws, client_s.str_phone_nbr);
	printf("Account Balance: ");
	cin >> client_s.d_account_balance;
	return (client_s);
}

string	ft_get_formatted_line_from_client_data(s_client client_s, string str_fields_separator = "#//#")
{
	string	str_formatted_client_data_line;

	str_formatted_client_data_line = "";
	str_formatted_client_data_line += client_s.str_id_nbr + str_fields_separator;
	str_formatted_client_data_line += client_s.str_pin_nbr + str_fields_separator;
	str_formatted_client_data_line += client_s.str_name + str_fields_separator;
	str_formatted_client_data_line += client_s.str_phone_nbr + str_fields_separator;
	str_formatted_client_data_line += to_string(client_s.d_account_balance) + str_fields_separator;
	return (str_formatted_client_data_line);
}

void	ft_update_clients_file(vector <s_client> v_clients_s, string str_filename = CLIENTS_FILENAME, string str_fields_separator = "#//#")
{
	fstream	file_of_clients;

	file_of_clients.open(str_filename, ios::out | ios::trunc);
	if (file_of_clients.is_open())
	{
		for (s_client &client_s : v_clients_s)
			file_of_clients << ft_get_formatted_line_from_client_data(client_s) << endl;
		file_of_clients.close();
	}
}

void	ft_update_client_by_acc_nbr(string str_acc_nbr, string str_filename = CLIENTS_FILENAME)
{
	vector <s_client>	v_clients_s;
	s_client	client_s;
	char	confirm_update;

	confirm_update = 'N';
	v_clients_s = ft_v_get_clients_from_file(str_filename);
	if (ft_search_if_client_exist(str_acc_nbr, client_s))
	{
		ft_print_client_data_details(client_s);
		printf("\nAre you sure that you want to update this client (Y/N)? ");
		cin >> confirm_update;
		if (toupper(confirm_update) == 'Y')
		{
			for (s_client &client_s : v_clients_s)
				if (client_s.str_id_nbr == str_acc_nbr)
				{
					client_s = ft_get_client_info_updation(str_acc_nbr);
					break ;
				}
			ft_update_clients_file(v_clients_s, str_filename);
			printf("\n\nClient Updated Successfully.\n");
		}
	}
	else
	{
		printf("\n\nClient with account number `%s` isn't found.\n", str_acc_nbr.c_str());
	}
}

string	ft_get_account_nbr()
{
	string	str_acc_nbr;

	printf("Please enter the account ID Number: ");
	getline(cin >> ws, str_acc_nbr);
	return (str_acc_nbr);
}

int	main ()
{
	ft_update_client_by_acc_nbr(ft_get_account_nbr());
	return (0);
}
