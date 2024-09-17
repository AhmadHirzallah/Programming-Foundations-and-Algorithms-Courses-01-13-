#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <vector>
#include <string>
#include "clients_management.h"
#include "file_management.h"

using namespace std;

// Function declarations
string ft_set_id();
string ft_set_password();
void	ft_set_id_and_password(string &str_id, string &str_password);
bool	ft_perform_login_as_client(string &str_id, string &str_password);
void	ft_show_login();
bool    ft_perform_login_as_system_user(string &str_entered_username, string &str_entered_password);
char ft_back_after_login_fail_and_check_if_wanting_to_login_again();


#endif // MAIN_H
