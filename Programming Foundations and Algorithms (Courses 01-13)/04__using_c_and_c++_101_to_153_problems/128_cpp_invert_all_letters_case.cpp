#include <iostream>

using namespace std;

string	ft_read_str()
{
	string	entered_str;

	printf("Please enter the string:\n");
	getline(cin >> ws, entered_str);
	return (entered_str);
}

char	ft_convert_character_case(char entered_char)
{
	if (entered_char >= 'a' && entered_char <= 'z')
		return (entered_char - 32);
	else if (entered_char >= 'A' && entered_char <= 'Z')
		return (entered_char + 32);
	else
		return (entered_char);
}

void	ft_convert_all_letters_cases(string *entered_string)
{
	short	c;

	c = -1;
	while (++c < entered_string->length())
	{
		(*entered_string)[c] = ft_convert_character_case((*entered_string)[c]);
	}
}

int	main()
{
	string	entered_string;

	entered_string = ft_read_str();
	printf("\nThe entered string is:  (%s)\n", entered_string.c_str());
	ft_convert_all_letters_cases(&entered_string);
	printf("\nThe string after converting is:  (%s)\n", entered_string.c_str());
	return (0);
}

