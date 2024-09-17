#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const string	STR_CLIENTS_FILENAME = "Clients.txt";

struct	s_clients
{
	string	str_account_id_nbr;
	string	str_pin_nbr;
	string	str_client_name;
	string	str_client_phone_nbr;
	double	d_account_balance;
	bool	request_to_delete_account = false;
};

vector <string> ft_v_str_extract_client_data_fields_from_formatted_line(string str_formatted_line, string str_fields_separator = "#//#")
{
	vector <string> v_str_client_data_fields;
	short	separtor_len;
	size_t	index;

	separtor_len = str_fields_separator.length();
	while ((index = str_formatted_line.find(str_fields_separator)) != string::npos)
	{
		v_str_client_data_fields.emplace_back(str_formatted_line.substr(0, index));
		str_formatted_line.erase(0, index + separtor_len);
	}
	if (str_formatted_line != "")
		v_str_client_data_fields.emplace_back(str_formatted_line);
	return (v_str_client_data_fields);
}

s_clients	ft_s_get_client_data_from_line(string str_formatted_line)
{
	s_clients	s_tmp_client_data;
	vector <string> v_str_client_data_fields;
//	A000#//#1999#//#Ahmad Hirzallah#//#0792001744#//#99500.000000#//#
	v_str_client_data_fields = ft_v_str_extract_client_data_fields_from_formatted_line(str_formatted_line); 
	s_tmp_client_data.str_account_id_nbr = v_str_client_data_fields[0];
	s_tmp_client_data.str_pin_nbr = v_str_client_data_fields[1];
	s_tmp_client_data.str_client_name = v_str_client_data_fields[2];
	s_tmp_client_data.str_client_phone_nbr = v_str_client_data_fields[3];
	s_tmp_client_data.d_account_balance = stod(v_str_client_data_fields[4]);
	return (s_tmp_client_data);
}

vector <s_clients>	ft_v_s_get_all_clients_data_from_file(string str_file_name)
{
	fstream	client_data_file;
	vector <s_clients>	v_clients_data_records;
	s_clients	s_tmp_client;
	string	str_formatted_data_line;

	client_data_file.open(str_file_name, ios::in);
	if (client_data_file.is_open())
	{
		while (getline(client_data_file, str_formatted_data_line))
		{
			s_tmp_client = ft_s_get_client_data_from_line(str_formatted_data_line);
			v_clients_data_records.emplace_back(s_tmp_client);
		}
		client_data_file.close();
	}
	return (v_clients_data_records);
}

void	ft_print_searched_account_details(s_clients s_client)
{
	printf("The following are account details:\n\n");
	printf("%-45s: %s\n", "Account Number", s_client.str_account_id_nbr.c_str());
	printf("%-45s: %s\n", "PIN Number", s_client.str_pin_nbr.c_str());
	printf("%-45s: %s\n", "Client Name", s_client.str_client_name.c_str());
	printf("%-45s: %s\n", ("`" + s_client.str_client_name + "`" + " Phone Number").c_str(), s_client.str_client_phone_nbr.c_str());
	printf("%-45s: %.2f\n", ("`" + s_client.str_client_name + "`" +" Balance").c_str(), s_client.d_account_balance);
}

string	ft_ask_for_searched_account_id_nbr()
{
	string	str_entered_accont_id;

	printf("Please enter account number: ");
	getline(cin >> ws, str_entered_accont_id);
	return (str_entered_accont_id);
}

bool	ft_find_client_by_account_nbr_from_file(string str_searched_account_id, s_clients &s_search_client, string str_file_name = STR_CLIENTS_FILENAME)
{
	fstream	client_data_file;
	vector <s_clients> v_clients_data_records;

	v_clients_data_records = ft_v_s_get_all_clients_data_from_file(STR_CLIENTS_FILENAME);
	for (s_clients &s_client : v_clients_data_records)
	{
		if (s_client.str_account_id_nbr == str_searched_account_id)
		{
			ft_print_searched_account_details(s_client);
			s_search_client = s_client;
			return (true);
		}
	}
	printf("\n\nClient with Account ID Number `%s` isn't found!\n", str_searched_account_id.c_str());
	return (false);
}

int	main ()
{
	s_clients	s_search_client;

	ft_find_client_by_account_nbr_from_file(ft_ask_for_searched_account_id_nbr(), s_search_client);
	return (0);
}
