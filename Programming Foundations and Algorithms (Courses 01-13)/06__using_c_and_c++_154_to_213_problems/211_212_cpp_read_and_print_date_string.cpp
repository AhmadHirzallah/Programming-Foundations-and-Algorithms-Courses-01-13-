#include <iostream>
#include "my_time_lib.h"
#include <vector>

using namespace std;
using namespace my_time_lib;
/*
string	ft_read_date_string(string message = "\nPlease Enter Date (dd/mm/yyyy):  ")
{
	string str_date;

	printf("%s", message.c_str());
	getline(cin >> ws, str_date);
	return (str_date);
}

vector <string>	ft_v_str_convert_str_date_to_fields(string str_date, string str_fields_separator)
{
	vector <string> v_str_date_fields;
	short	index;
	short	len;

	len = str_fields_separator.length();
	while ((index = str_date.find(str_fields_separator)) != string::npos)
	{
		v_str_date_fields.emplace_back(str_date.substr(0, index));
		str_date.erase(0, index + len);
	}
	if (str_date != "")
		v_str_date_fields.emplace_back(str_date);
	return (v_str_date_fields);
}

s_date	ft_convert_str_date_to_date_s(string str_date, string str_fields_separator = "/")
{
	s_date	date_s;
	vector <string> v_str_date_fields;

	v_str_date_fields = ft_v_str_convert_str_date_to_fields(str_date, str_fields_separator);
	date_s.day = (short)stoi(v_str_date_fields[0]);
	date_s.month = (short)stoi(v_str_date_fields[1]);
	date_s.year = (short)stoi(v_str_date_fields[2]);
	return (date_s);
}

void	ft_print_date_separately(s_date date_s)
{
	printf("\n\nDay: (%hd)\nMonth: (%hd)\nYear: (%hd)\n\n", date_s.day, date_s.month, date_s.year);
}

string	ft_convert_date_s_to_str_date(s_date date_s)
{
	return (to_string(date_s.day) + "/" + to_string(date_s.month) + "/" + to_string(date_s.year));
}
*/

int     main (void)
{
	string str_date;
	s_date	date_s;

	str_date = ft_read_date_string();
	date_s = ft_convert_str_date_to_date_s(str_date, "/");
	ft_print_date_separately(date_s);
	printf("\nYou entered:  %s\n\n", ft_convert_date_s_to_str_date(date_s).c_str());
	return (0);
}
