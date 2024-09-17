#ifndef FILE_MANAGEMENT_H
#define FILE_MANAGEMENT_H

#include <string>
#include <vector>
#include "client_struct.h"
#include "constants.h"

using namespace std;

vector<string> ft_v_extract_data_fields_of_client_from_formatted_line(string str_formatted_line_of_file, string str_fields_separator = "#//#");
s_client ft_set_data_of_client_from_extracted_data_fields_of_clnt(vector<string> v_client_data_fields);
vector<s_client> ft_v_convert_data_from_file_to_set_of_clients(string str_filename = CLIENTS_FILENAME);
void    ft_deposit_balance_to_client_by_acc_nbr_in_file(string str_id_nbr, double d_converting_of_balance_val, string str_filename = CLIENTS_FILENAME);
void    ft_update_clients_data_in_a_file(vector <s_client> &clients_v, string str_filename = CLIENTS_FILENAME);
string ft_convert_client_record_to_formatted_line_of_file(s_client client_s, string str_field_separator = "#//#");
vector <string> ft_v_extract_data_fields_of_user_from_formatted_line(string str_formatted_line_of_file, string str_fields_separator = "#//#");
s_user  ft_set_data_of_user_from_extracted_data_fields_of_user(vector <string> v_str_user_data_fields);
void    ft_add_client_record_to_file(s_client client_s, string str_filename = CLIENTS_FILENAME);
string  ft_convert_client_record_to_formatted_file_line(s_client client_s, string str_field_separator = "#//#");
void    ft_delete_marked_requested_clients_from_file(vector <s_client> &clients_v_s, string str_filename = CLIENTS_FILENAME);
void	ft_update_client_in_file(vector <s_client> client_v_s, string str_filename = CLIENTS_FILENAME);
void    ft_add_user_record_to_file(s_user user_s, string str_filename = USERS_FILENAME);
string  ft_convert_user_record_to_formatted_file_line(s_user user_s, string str_field_separator = "#//#");
vector <s_user>	ft_v_convert_data_from_file_to_set_of_users(string str_filename = USERS_FILENAME);
void	ft_delete_user();
vector <s_user>	ft_mark_user_for_deletion(string username_for_deletion);
void	ft_delete_user_after_marking(vector <s_user> users_v_s);
void	ft_delete_marked_user_from_file(vector <s_user> users_v_s, string str_filename = USERS_FILENAME);
void	ft_update_user_in_a_file(vector <s_user> users_v_s, string str_filename = USERS_FILENAME);

#endif
