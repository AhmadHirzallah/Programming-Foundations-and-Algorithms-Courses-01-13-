#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

struct	s_client
{
	string	str_account_id_nbr;
	string	str_client_name;
	string	str_client_phone_nbr;
	long	l_pin_code;
	double	d_account_balance;
	bool	delete_request = false;
};

vector <string>	ft_v_str_split_formatted_line_to_fields (string str_data_line, const string str_field_separator = "#//#")
{
	vector <string>	v_str_client_data_record;
	string	str_tmp_word;
	short	pos;
	
	str_tmp_word = "";
	pos = 0;
	while ((pos = str_data_line.find(str_field_separator)) != -1)
	{
		str_tmp_word = str_data_line.substr(0, pos);
		if (str_tmp_word != "")
			v_str_client_data_record.emplace_back(str_tmp_word);
		str_data_line = str_data_line.erase(0, (pos + str_field_separator.length()));
	}
	if (str_data_line != "")
		v_str_client_data_record.emplace_back(str_data_line);
	return (v_str_client_data_record);
}

s_client	ft_s_extract_client_data_from_formatted_line(string str_data_line, const string str_field_separator = "#//#")
{
	vector <string>	v_splitted_client_data;
	s_client	s_tmp_client;

	v_splitted_client_data = ft_v_str_split_formatted_line_to_fields(str_data_line);
	s_tmp_client.str_account_id_nbr = v_splitted_client_data[0];
	s_tmp_client.str_client_name = v_splitted_client_data[1];
	s_tmp_client.str_client_phone_nbr = v_splitted_client_data[2];
	s_tmp_client.l_pin_code = stol(v_splitted_client_data[3]);
	s_tmp_client.d_account_balance= stod(v_splitted_client_data[4]);
	return (s_tmp_client);
}

void	ft_print_client_record(s_client s_tmp_client)
{
	printf("\n\nThe following is extracted client record:\n\n");
	printf("Account ID Number: \"%s\"\n", s_tmp_client.str_account_id_nbr.c_str());
	printf("Account PIN Number: \"%ld\"\n", s_tmp_client.l_pin_code);
	printf("Client Name: \"%s\"\n", s_tmp_client.str_client_name.c_str());
	printf("Client Phone Number: \"%s\"\n", s_tmp_client.str_client_phone_nbr.c_str());
	printf("Account PIN Number: \"%.3f\"\n\n", s_tmp_client.d_account_balance);
}

int	main ()
{
	string	str_data_line;
//	vector <string>	v_str_client_data_record;

	str_data_line = "A150#//#Mohammed Abu-Hadhoud#//#079939999#//#1234#//#5000.000000";
	printf("\nLine record is:\n\"%s\"\n\n", str_data_line.c_str());
	ft_print_client_record(ft_s_extract_client_data_from_formatted_line(str_data_line));
	
	return (0);
}
