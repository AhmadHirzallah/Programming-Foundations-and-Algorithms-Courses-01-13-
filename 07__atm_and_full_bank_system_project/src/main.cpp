#include "clients_management.h"
#include "file_management.h"
#include "system_users_management.h"
#include "constants.h"
#include "interface.h"
#include "main.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string	ft_set_id()
{
	string	str_id;

	printf("|   Enter User ID: ");
	getline(cin >> ws, str_id);
	return (str_id);
}

string	ft_set_password()
{
	string	str_password;

	printf("\n|   Enter Password: ");
	getline(cin >> ws, str_password);
	return (str_password);
}

void	ft_set_id_and_password(string &str_id, string &str_password)
{
	str_id = ft_set_id();
	str_password = ft_set_password();
}

char ft_back_after_login_fail_and_check_if_wanting_to_login_again()
{
	char	want_to_login_again;
	cout << "\nInvalid Username/Password!\n\n";
	printf ("Do you want to login again (Press Y to proceed)?  ");
	cin >> want_to_login_again;
	cout << endl << endl;
	return (want_to_login_again);  // Indicate login failure
}



bool	ft_perform_login_as_client(string &str_id, string &str_password)
{
	vector <s_client>	v_clients_s;
	bool	login_failed;

	login_failed = true;
	v_clients_s = ft_v_convert_data_from_file_to_set_of_clients(CLIENTS_FILENAME);
	if(ft_find_client_and_get_ref(str_id ,v_clients_s, g_client_s))
	{
		if ((str_id == g_client_s.str_id_nbr) && (str_password == g_client_s.str_pin_nbr))
		{
			login_failed = false;
			ft_show_atm_main_menu_for_clients();
		}
		else
		{
			ft_show_login();
			return (false);
		}
	}
	else
	{
		ft_show_login();
		return (false);
	}
	return (true);
}

bool	ft_perform_login_as_system_user(string &str_entered_username, string &str_entered_password)
{
	vector <s_user>	user_v_s;
	bool	login_failed;

	login_failed = true;
	
	user_v_s = ft_v_convert_data_from_file_to_set_of_users(USERS_FILENAME);
	if (ft_find_user_and_get_ref(str_entered_username, user_v_s, g_user_s))
	{
		if ((str_entered_username == g_user_s.str_username) && (str_entered_password == g_user_s.str_password))
		{
			login_failed = false;
			ft_show_main_menu_for_system_users();
		}
		else
		{
			return (false);
		}
	}
	else
	{
		return (false);
	}
	return (true);
}


int	main ()
{
	ft_show_login();
	return (0);
}
