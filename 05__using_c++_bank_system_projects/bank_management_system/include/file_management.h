#ifndef FILE_MANAGEMENT_H
 #define FILE_MANAGEMENT_H

#include <string>
#include <vector>
#include "clients_management.h"
#include "constants.h"

using namespace std;

vector <s_client>   ft_v_convert_file_data_to_clients_data(string str_filename = CLIENTS_FILENAME);
void    ft_add_client_record_to_file(s_client client_s, string str_filename = CLIENTS_FILENAME);
void    ft_delete_requested_clients_from_file (vector <s_client> &clients_v, string str_filename = CLIENTS_FILENAME);
void    ft_update_client_data_in_file (vector <s_client> &clients_v, string str_filename = CLIENTS_FILENAME);
#endif 
