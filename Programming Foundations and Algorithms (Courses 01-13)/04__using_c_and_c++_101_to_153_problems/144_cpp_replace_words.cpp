#include <vector>
#include <iostream>
#include <cctype>

using namespace std;

string	ft_read_string(string message)
{
	string	entered_str;

	printf("%s", message.c_str());
	getline(cin >> ws, entered_str);
	return (entered_str);
}

string	ft_replace_word_in_str(string entered_string, string string_to_replace, string string_replace_to)
{
	short	pos;

	pos = entered_string.find(string_to_replace);
	/*while (pos != std::string::npos)*/
	while (pos != -1)
	{
		entered_string = entered_string.replace(pos, string_to_replace.length(), string_replace_to);
		pos = entered_string.find(string_to_replace);
	}
	return (entered_string);
}

int	main()
{
	string	entered_string;
	string	string_to_replace;
	string	string_replace_to;

	entered_string = ft_read_string("Please enter the whole string:\n");
	string_to_replace = ft_read_string("Please enter a string to be found and replaced:\n");
	string_replace_to = ft_read_string("Please enter a string to replace to:\n");
	printf("\n\nThe Original string is: (%s)\n", entered_string.c_str());
	entered_string = ft_replace_word_in_str(entered_string, string_to_replace, string_replace_to);
	printf("\n\nThe string after replacing is: (%s)\n", entered_string.c_str());
	return (0);
}
