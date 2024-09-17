#include "file_management.h"
#include "constants.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <s_client>	ft_v_convert_file_data_to_clients_data(string str_filename)
{
	fstream	file_clients_data;
	vector <s_client>	v_clients_s;
	string	str_formatted_file_line;

	file_clients_data.open(str_filename, ios::in);
	if (file_clients_data.is_open())
	{
		while(getline(file_clients_data, str_formatted_file_line))
			v_clients_s.emplace_back(ft_get_client_data_from_file_line(str_formatted_file_line));
		file_clients_data.close();
	}
	else
		printf("\nFailed to open the file. \n");
	return (v_clients_s);
}

void	ft_add_client_record_to_file(s_client client_s, string str_filename)
{
	fstream	file_clients_data;

	file_clients_data.open(str_filename, ios::out | ios::app);
	if (file_clients_data.is_open())
	{
		file_clients_data << ft_convert_client_record_to_formatted_file_line(client_s)<< endl;
		file_clients_data.close();
	}
}

void    ft_delete_requested_clients_from_file (vector <s_client> &clients_v, string str_filename)
{
	fstream	file_of_clients;

	file_of_clients.open(str_filename ,ios::out);
	if (file_of_clients.is_open())
	{
		for (s_client &client : clients_v)
		{
			if (client.request_to_deletion == false)
				file_of_clients << ft_convert_client_record_to_formatted_file_line(client) << endl;
		}
		file_of_clients.close();
	}
}

void	ft_update_client_data_in_file (vector <s_client> &clients_v, string str_filename)
{
	fstream	file_of_clients;

	file_of_clients.open(str_filename, ios::out | ios::trunc);
	if (file_of_clients.is_open())
	{
		for (s_client &client : clients_v)
			file_of_clients << ft_convert_client_record_to_formatted_file_line(client) << endl;
	}
	file_of_clients.close();
}
