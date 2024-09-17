#ifndef CLIENTS_MANAGEMENT_H
 #define CLIENTS_MANAGEMENT_H

#include <vector>
#include <string>
#include "constants.h"

using namespace std;

struct	s_client
{
	string	str_id_nbr = "";
	string	str_pin_nbr;
	string	str_name;
	string	str_phone_nbr;
	double	d_balance;
	bool	request_to_deletion = false;
};

vector <string> ft_v_get_client_data_fields_from_line(string str_file_formatted_line, string str_fields_separator = "#//#");
s_client    ft_get_client_data_from_file_line(string str_file_formatted_line, string str_fields_separator = "#//#");
string  ft_convert_client_record_to_formatted_file_line(s_client client_s, string str_field_separator = "#//#");
void    ft_add_new_client();
void    ft_add_client_system(string str_filename = CLIENTS_FILENAME);
string  ft_convert_client_data_to_formatted_line(s_client client_s, string str_field_separator = "#//#");
s_client    ft_read_client_data();
bool    ft_check_is_client_exist_by_acc_nbr(string str_entered_id_nbr, string str_filename = CLIENTS_FILENAME);
void    ft_print_screen_header(string str_screen_name);
void    ft_print_client_details(s_client s_client);
s_client    ft_find_and_get_client(string str_acc_nbr, string str_filename = CLIENTS_FILENAME);
void    ft_delete_client();
string  ft_get_id_nbr();
void    ft_delete_client_by_id_nbr(string str_id_nbr);
char    ft_get_deletion_choice();
void    ft_set_deletion_request(string str_id_nbr, vector <s_client> &clients_v);
vector <s_client>   ft_update_client_data(string str_client_nbr, vector <s_client>   &clients_v);
s_client    ft_get_client_new_data(string str_client_nbr);
void    ft_update_client();
void    ft_get_client_updated();
char    ft_get_update_confirmation();
void    ft_find_client();


#endif
