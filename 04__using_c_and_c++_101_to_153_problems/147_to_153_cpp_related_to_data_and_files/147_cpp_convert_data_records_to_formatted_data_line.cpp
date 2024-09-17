#include <vector>
#include <iostream>
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

s_client	ft_read_client_data_record()
{
	s_client    client_s;

	printf("\nPlease enter the Client Data:\n");
	printf("\nPlease enter the ID Number: ");
	getline(cin >> ws, client_s.str_account_id_nbr);
	printf("\nPlease enter the PIN Number: ");
	cin >> client_s.l_pin_code;
	printf("\nPlease enter the Client Name: ");
	getline(cin >> ws, client_s.str_client_name);
	printf("\nPlease enter the Client Phone Number: ");
	getline(cin >> ws, client_s.str_client_phone_nbr);
	printf("\nPlease enter the Account Balance: ");
	cin >> client_s.d_account_balance;
	return (client_s);
}

string	ft_v_str_convert_data_record_to_line(s_client client_s, string str_separator = "#//#")
{
	string	str_client_data_line;

	str_client_data_line = "";
	str_client_data_line += client_s.str_account_id_nbr + str_separator;
	str_client_data_line += client_s.str_client_name + str_separator;
	str_client_data_line += client_s.str_client_phone_nbr + str_separator;
	str_client_data_line += to_string(client_s.l_pin_code) + str_separator;
	str_client_data_line += to_string(client_s.d_account_balance);
	return (str_client_data_line);
}

int	main ()
{
//	vector <s_client> v_clients_s;
//	s_client	client_s;
	string	str_client_data_line;

//	client_s = ft_read_client_data_record();
	str_client_data_line = ft_v_str_convert_data_record_to_line(ft_read_client_data_record());
	printf("\n\nClient Record for saving is:\n%s\n", str_client_data_line.c_str());
	return (0);
}
