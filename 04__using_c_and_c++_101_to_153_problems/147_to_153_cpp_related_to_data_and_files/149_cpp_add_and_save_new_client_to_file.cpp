#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

const string	CLIENTS_FILE_NAME = "Clients.txt";

struct	s_client
{
	string	str_account_id_nbr;
	string	str_client_name;
	string	str_client_phone_nbr;
	string	str_pin_nbr;
	double	account_balance;
	bool	request_account_delete = false;
};

s_client	ft_read_client_data_record()
{
	s_client	tmp_client;

	printf("Adding New Client:\n\n");
	printf("Enter Account ID Number: ");
	getline(cin >> ws, tmp_client.str_account_id_nbr);
	printf("Enter Account PIN Number: ");
	getline(cin >> ws, tmp_client.str_pin_nbr);
	printf("Enter Client Name: ");
	getline(cin >> ws, tmp_client.str_client_name);
	printf("Enter Client Phone Number: ");
	getline(cin >> ws, tmp_client.str_client_phone_nbr);
	printf("Enter \"%s\" Account Balance: ", tmp_client.str_client_name.c_str());
	cin >> tmp_client.account_balance;
	return (tmp_client);
}

string	ft_convert_client_data_to_formatted_line(s_client client_s, string str_field_separator = "#//#")
{
	string	formatted_data_line;

	formatted_data_line = "";
	formatted_data_line += client_s.str_account_id_nbr + str_field_separator;
	formatted_data_line += client_s.str_pin_nbr + str_field_separator;
	formatted_data_line += client_s.str_client_name + str_field_separator;
	formatted_data_line += client_s.str_client_phone_nbr + str_field_separator;
	formatted_data_line += to_string(client_s.account_balance) + str_field_separator;
	return (formatted_data_line);
}

void	ft_add_client_to_file(string file_name ,s_client client_s, string str_field_separator = "#//#")
{
	fstream	client_data_file;
	string formatted_data_line;

	client_data_file.open(file_name, ios::out | ios::app);
	formatted_data_line = ft_convert_client_data_to_formatted_line(client_s);
	if (client_data_file.is_open())
	{
		client_data_file << formatted_data_line << endl;
		client_data_file.close();
	}
}

void	ft_add_clients_to_file()
{
	char	add_more_clients;

	add_more_clients = 'Y';
	while (toupper(add_more_clients) == 'Y')
	{
		ft_add_client_to_file(CLIENTS_FILE_NAME, ft_read_client_data_record());
		printf("The client is addes successfully.\nDo you want to add more clients (Y or y to add more)? ");
		cin >> add_more_clients;
	}
}



int	main ()
{
	ft_add_clients_to_file();
	return (0);
}
