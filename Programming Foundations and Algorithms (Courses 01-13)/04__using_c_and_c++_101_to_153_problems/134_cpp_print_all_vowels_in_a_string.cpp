#include <iostream>
#include <string>

using namespace std;

short	ft_check_is_vowel(char entered_char);
string	ft_read_str();
string	ft_get_all_vowels_in_str(string entered_string);
void	ft_print_vowels_in_str(string entered_string);

int	main()
{
	string	entered_string;

	printf("\nProgram Takes string that you want to count vowels in\n");
	entered_string = ft_read_str();
	entered_string = ft_get_all_vowels_in_str(entered_string);
	ft_print_vowels_in_str(entered_string);
	return (0);
}

void	ft_print_vowels_in_str(string entered_string)
{
	short	c;

	printf("\nThe vowels in the string are:\n");
	c = -1;
	while (++c < entered_string.length())
	{
		if (c != entered_string.length() - 1)
			printf("%c\t", entered_string[c]);
		else
			printf("%c", entered_string[c]);
	}
	printf("\n");
}

string	ft_read_str()
{
	string	entered_str;

	printf("Please enter the string:\n");
	getline(cin >> ws, entered_str);
	return (entered_str);
}

short	ft_check_is_vowel(char entered_char)
{
	/*const char	vowels[] = {'a', 'A', 'e', 'E', 'o', 'O', 'i', 'I', 'u', 'U'};*/
	const char* vowels = "aAeEoOiIuU";	
	while (*vowels)
		if (entered_char == *vowels)
			return (1);
		else
			vowels++;
	return (0);
}

string	ft_get_all_vowels_in_str(string entered_string)
{
	short	c;
	string	vowels_in_str;

	vowels_in_str = "";
	c = -1;
	while (++c < entered_string.length())
	{
		if (ft_check_is_vowel(entered_string[c]))
			vowels_in_str += entered_string[c];
	}
	return (vowels_in_str);
}

