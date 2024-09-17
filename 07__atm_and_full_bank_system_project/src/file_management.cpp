#include "file_management.h"
#include "constants.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <string>	ft_v_extract_data_fields_of_client_from_formatted_line(string str_formatted_line_of_file, string str_fields_separator)
{
	vector <string>	v_str_client_data_fields;
	short	index;
	short	len;

	len = str_fields_separator.length();
	while ((index = str_formatted_line_of_file.find(str_fields_separator)) != string::npos)
	{
		v_str_client_data_fields.emplace_back(str_formatted_line_of_file.substr(0, index));
		str_formatted_line_of_file.erase(0, index + len);
	}
	if (str_formatted_line_of_file != "")
		v_str_client_data_fields.emplace_back(str_formatted_line_of_file);
	return (v_str_client_data_fields);
}

vector <string>	ft_v_extract_data_fields_of_user_from_formatted_line(string str_formatted_line_of_file, string str_fields_separator)
{
	vector <string>	v_str_user_data_fields;
	short	index;
	short	len;

	len = str_fields_separator.length();
	while ((index = str_formatted_line_of_file.find(str_fields_separator)) != string::npos)
	{
		v_str_user_data_fields.emplace_back(str_formatted_line_of_file.substr(0, index));
		str_formatted_line_of_file.erase(0, index + len);
	}
	if (str_formatted_line_of_file != "")
		v_str_user_data_fields.emplace_back(str_formatted_line_of_file);
	return (v_str_user_data_fields);
}

s_client	ft_set_data_of_client_from_extracted_data_fields_of_clnt(vector <string> v_client_data_fields)
{
	s_client	client_s;

	client_s.str_id_nbr = v_client_data_fields[0];
	client_s.str_pin_nbr = v_client_data_fields[1];
	client_s.str_name = v_client_data_fields[2];
	client_s.str_phone_nbr = v_client_data_fields[3];
	client_s.d_balance = stod(v_client_data_fields[4]);
	return (client_s);
}

s_user	ft_set_data_of_user_from_extracted_data_fields_of_user(vector <string> v_str_user_data_fields)
{
	s_user  user_s;

	user_s.str_username = v_str_user_data_fields[0];
	user_s.str_password = v_str_user_data_fields[1];
	user_s.i_permissions = stoi(v_str_user_data_fields[2]);
	return (user_s);
}
	
/*vector <s_user>	ft_v_convert_data_from_file_to_set_of_users(string str_filename)
{
	fstream	file_users_streamer;
	vector <string>	v_str_users_data_fielded;
	vector <s_user>	users_v_s;
	s_user	user_s;
	string  str_formatted_line_of_file;

	file_users_streamer.open(str_filename, ios::in);
	if (file_users_streamer.is_open())
	{
		while(getline(file_users_streamer, str_formatted_line_of_file))
		{
			v_str_users_data_fielded = ft_v_extract_data_fields_of_user_from_formatted_line(str_formatted_line_of_file);
			user_s = ft_set_data_of_user_from_extracted_data_fields_of_user(v_str_users_data_fielded);
			users_v_s.emplace_back(user_s);
		}
		file_users_streamer.close();
	}
	else
		printf("\nFailed to open the file in ft_v_convert_data_from_file_to_set_of_users function. :( \n\n");
	file_users_streamer.close();
	return (users_v_s);
}*/

vector <s_client>	ft_v_convert_data_from_file_to_set_of_clients(string str_filename)
{
	fstream	file_clients_data;
	vector <s_client>	v_clients_s;
	vector <string>	v_str_client_data_fields;
	s_client	client_s;
	string  str_formatted_line_of_file;

	file_clients_data.open(str_filename, ios::in);
	if (file_clients_data.is_open())
	{
		while(getline(file_clients_data, str_formatted_line_of_file))
		{
			v_str_client_data_fields = ft_v_extract_data_fields_of_client_from_formatted_line(str_formatted_line_of_file);
			client_s = ft_set_data_of_client_from_extracted_data_fields_of_clnt(v_str_client_data_fields);
			v_clients_s.emplace_back(client_s);
		}
		file_clients_data.close();
	}
	else
		printf("\nFailed to open the file in ft_v_convert_data_from_file_to_clients_set. :( \n\n");
	file_clients_data.close();
	return (v_clients_s);
}
void	ft_deposit_balance_to_client_by_acc_nbr_in_file(string str_id_nbr, double d_converting_of_balance_val, string str_filename)
{
	vector <s_client>	all_clients_s;

	all_clients_s = ft_v_convert_data_from_file_to_set_of_clients(str_filename);
	for (s_client &client_s : all_clients_s)
	{
		if (str_id_nbr == client_s.str_id_nbr)
		{
			client_s.d_balance += d_converting_of_balance_val;
		}
	}
	ft_update_clients_data_in_a_file(all_clients_s, str_filename);
}

string ft_convert_client_record_to_formatted_line_of_file(s_client client_s, string str_field_separator)
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

void	ft_update_clients_data_in_a_file(vector <s_client> &clients_v, string str_filename)
{
	fstream	file_of_clients;

	file_of_clients.open(str_filename, ios::out | ios::trunc);
	if (file_of_clients.is_open())
	{
		for (s_client &client_s : clients_v)
		{
			if (client_s.request_to_deletion != true)
				file_of_clients << ft_convert_client_record_to_formatted_line_of_file(client_s) << endl;
		}
	}
	file_of_clients.close();
}

void	ft_update_user_in_a_file(vector <s_user> users_v_s, string str_filename)
{
	fstream	file_users_data;

	file_users_data.open(str_filename, ios::out | ios::trunc);
	if (file_users_data.is_open())
	{
		for (s_user &user_s: users_v_s)
		{
			if (user_s.b_mark_for_delete != true)
				file_users_data << ft_convert_user_record_to_formatted_file_line(user_s) << endl;
		}
	}
	file_users_data.close();
}

vector <s_user>	ft_v_convert_data_from_file_to_set_of_users(string str_filename)
{
	fstream	file_users_data;
	vector <s_user> user_v_s;
	vector <string>	v_str_user_data_fields;
	s_user	user_s;
	string  str_formatted_line_of_file;

	file_users_data.open(str_filename, ios::in);
	if (file_users_data.is_open())
	{
		while(getline(file_users_data, str_formatted_line_of_file))
		{
			v_str_user_data_fields = ft_v_extract_data_fields_of_user_from_formatted_line(str_formatted_line_of_file);
			user_s = ft_set_data_of_user_from_extracted_data_fields_of_user(v_str_user_data_fields);
			user_v_s.emplace_back(user_s);
		}
		file_users_data.close();
	}
	else
		printf("\nFailed to open the file in ft_v_convert_data_from_file_to_set_of_users. :( \n\n");
	file_users_data.close();
	return (user_v_s);
}

void	ft_add_user_record_to_file(s_user user_s, string str_filename)
{
	fstream	file_users_stream;

	file_users_stream.open(str_filename, ios::out | ios::app);
	if (file_users_stream.is_open())
		file_users_stream << ft_convert_user_record_to_formatted_file_line(user_s) << endl;
	file_users_stream.close();
}

string	ft_convert_user_record_to_formatted_file_line(s_user user_s, string str_field_separator)
{
	string  str_formatted_file_line;

	str_formatted_file_line = "";
	str_formatted_file_line += user_s.str_username + str_field_separator;
	str_formatted_file_line += user_s.str_password + str_field_separator;
	str_formatted_file_line += to_string(user_s.i_permissions) + str_field_separator;
	return (str_formatted_file_line);
}

void    ft_add_client_record_to_file(s_client client_s, string str_filename)
{
	fstream	file_clients_records;

	file_clients_records.open(str_filename, ios::out | ios::app);
	if (file_clients_records.is_open())
		file_clients_records << ft_convert_client_record_to_formatted_file_line(client_s) << endl;
	file_clients_records.close();
}

string	ft_convert_client_record_to_formatted_file_line(s_client client_s, string str_field_separator)
{
	string  str_formatted_file_line;

	str_formatted_file_line = "";
	str_formatted_file_line += client_s.str_id_nbr + str_field_separator;
	str_formatted_file_line += client_s.str_pin_nbr + str_field_separator;
	str_formatted_file_line += client_s.str_name + str_field_separator;
	str_formatted_file_line += client_s.str_phone_nbr + str_field_separator;
	str_formatted_file_line += to_string(client_s.d_balance) + str_field_separator;
	return (str_formatted_file_line);
}

void	ft_delete_marked_requested_clients_from_file(vector <s_client> &clients_v_s, string str_filename)
{
	fstream	file_of_clients;

	file_of_clients.open(str_filename, ios::out);
	if (file_of_clients.is_open())
	{
		for (s_client &client_s : clients_v_s)
		{
			if (client_s.request_to_deletion == false)
				file_of_clients << ft_convert_client_record_to_formatted_file_line(client_s) << endl;
		}
	}
	file_of_clients.close();
}

void	ft_delete_marked_user_from_file(vector <s_user> users_v_s, string str_filename)
{
	fstream	file_of_users_streamer;

	file_of_users_streamer.open(str_filename, ios::out);
	if (file_of_users_streamer.is_open())
	{
		for (s_user &user_s: users_v_s)
		{
			if (user_s.b_mark_for_delete != true)
				file_of_users_streamer << ft_convert_user_record_to_formatted_file_line(user_s) << endl;
		}
	}
	file_of_users_streamer.close();
}

void	ft_update_client_in_file(vector <s_client> client_v_s, string str_filename)
{
	fstream	file_of_clients;

	file_of_clients.open(str_filename, ios::out | ios::trunc);
	if (file_of_clients.is_open())
	{
		for (s_client &client_s : client_v_s)
			file_of_clients << ft_convert_client_record_to_formatted_file_line(client_s) << endl;
	}
	file_of_clients.close();
}

