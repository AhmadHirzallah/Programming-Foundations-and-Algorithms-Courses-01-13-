#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const string	STR_CLIENTS_FILE_NAME = "Clients.txt";

struct	s_clients
{
	string	str_account_id_nbr;
	string	str_client_name;
	string	str_pin_nbr;
	string	str_client_phone_nbr;
	double	d_account_balance;
	bool	request_account_delete = false;
};

vector <string>	ft_v_str_convert_formatted_line_to_fields(string str_file_line, string str_fields_separator = "#//#")
{
	vector <string> v_str_client_data_fields;
	size_t	sep_length;
	size_t index;

	sep_length = str_fields_separator.length();
	while ((index = str_file_line.find(str_fields_separator)) != string::npos)
	{
		v_str_client_data_fields.emplace_back(str_file_line.substr(0, index));
		str_file_line.erase(0, index + sep_length);
	}
	if (!str_file_line.empty())
		v_str_client_data_fields.emplace_back(str_file_line);
	return (v_str_client_data_fields);
}

s_clients	ft_s_convert_formatted_data_line_to_client_record(string str_line, string str_fields_separator = "#//#")
{
	s_clients	tmp_s_client;
	vector <string>	v_data_fields;

	v_data_fields = ft_v_str_convert_formatted_line_to_fields(str_line);
	tmp_s_client.str_account_id_nbr = v_data_fields[0];
	tmp_s_client.str_pin_nbr = v_data_fields[1];
	tmp_s_client.str_client_name = v_data_fields[2];
	tmp_s_client.str_client_phone_nbr = v_data_fields[3];
	try {
        tmp_s_client.d_account_balance = stod(v_data_fields[4]);
    } catch (const invalid_argument& e) {
        cerr << "Invalid argument: " << v_data_fields[4] << " cannot be converted to double." << endl;
        // Handle the error appropriately, possibly setting account_balance to 0 or a default value
        tmp_s_client.d_account_balance = 0.0;
    }
	return (tmp_s_client);
}

vector <s_clients>	ft_v_s_convert_file_lines_to_clients_records(string str_file_name, string str_fields_separator = "#//#")
{
	fstream	client_data_file;
	vector <s_clients>	clients_data_records;
	s_clients	s_tmp_client;
	string	str_formatted_data_line;

	client_data_file.open(str_file_name, ios::in);
	if (client_data_file.is_open())
	{
		while (getline(client_data_file, str_formatted_data_line))
		{
			s_tmp_client = ft_s_convert_formatted_data_line_to_client_record(str_formatted_data_line);
			clients_data_records.emplace_back(s_tmp_client);
		}
		client_data_file.close();
	}
	return (clients_data_records);
}

void	ft_print_client_record(s_clients s_client)
{
    printf("| %-15s | %-10s | %-40s | %-18s | %-12.2f |\n",
            s_client.str_account_id_nbr.c_str(),
            s_client.str_pin_nbr.c_str(),
            s_client.str_client_name.c_str(),
            s_client.str_client_phone_nbr.c_str(),
            s_client.d_account_balance);
}

void	ft_show_all_clients_data(string str_file_name, string str_fields_separator = "#//#")
{
	vector <s_clients>	v_clients_data_records;
	
	v_clients_data_records = ft_v_s_convert_file_lines_to_clients_records(str_file_name);
    printf("\n__________________________________________________________________________________________________________________\n");
    printf("__________________________________________________________________________________________________________________\n");
	printf("\n\t\t\t\t\tClient List (%zu) Client(s).\n", v_clients_data_records.size());
    printf("__________________________________________________________________________________________________________________\n");
    printf("__________________________________________________________________________________________________________________\n");
    printf("| %-15s | %-10s | %-40s | %-18s | %-12s |\n", "Account Number", "Pin Code", "Client Name", "Phone", "Balance");
    printf("__________________________________________________________________________________________________________________\n");
	for (s_clients &client : v_clients_data_records)
    {
        ft_print_client_record(client);
    }
    printf("__________________________________________________________________________________________________________________\n");
    printf("__________________________________________________________________________________________________________________\n");
}

int	main ()
{
	ft_show_all_clients_data(STR_CLIENTS_FILE_NAME);
	return (0);
}
