#include <iostream>
#include <string>

using namespace std;

short	ft_check_is_vowel(char entered_char);
short	ft_count_vowels_in_str(string entered_string);
string	ft_read_str();

int	main()
{
	string	entered_string;

	printf("\nProgram Takes string that you want to count vowels in\n");
	entered_string = ft_read_str();
	printf("\nThe vowels count in the string is: (%hd)\n", ft_count_vowels_in_str(entered_string));
	return (0);
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

short	ft_count_vowels_in_str(string entered_string)
{
	short	c;
	short	count;

	count = 0;
	c = -1;
	while (++c < entered_string.length())
	{
		if (ft_check_is_vowel(entered_string[c]))
			count++;
	}
	return (count);
}
