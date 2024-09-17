#include <iostream>
#include "my_time_lib.h"
#include <vector>

using namespace std;
using namespace my_time_lib;

/*
string	ft_replace_words_in_str(string str, string str_replace, string str_replace_to)
{
	short	index;

	while ((index = str.find(str_replace)) != std::string::npos)
		str = str.replace(index, str_replace.length(), str_replace_to);
	return (str);
}

string	ft_format_str_date(s_date date_s, string str_date_format = "dd/mm/yyyy")
{
	string	str_formatted_date;

	str_formatted_date = "";
	str_formatted_date = ft_replace_words_in_str(str_date_format, "dd", to_string(date_s.day));
	str_formatted_date = ft_replace_words_in_str(str_formatted_date, "mm", to_string(date_s.month));
	str_formatted_date = ft_replace_words_in_str(str_formatted_date, "yyyy", to_string(date_s.year));
	return (str_formatted_date);
}
*/

int	main ()
{
	string	str_date;
	s_date	date_s;

	str_date = ft_read_date_string();
	date_s = ft_convert_str_date_to_date_s(str_date, "/");
	printf("\n\n%s\n\n", ft_format_str_date(date_s).c_str());
	printf("\n\n%s\n\n", ft_format_str_date(date_s, "yyyy/dd/mm").c_str());
	printf("\n\n%s\n\n", ft_format_str_date(date_s, "mm/dd/yyyy").c_str());
	printf("\n\n%s\n\n", ft_format_str_date(date_s, "mm-dd-yyyy").c_str());
	printf("\n\n%s\n\n", ft_format_str_date(date_s, "dd-mm-yyyy").c_str());
	printf("\n\n%s\n\n", ft_format_str_date(date_s, "Day: dd, Month: mm, Year: yyyy").c_str());
	return (0);
}
