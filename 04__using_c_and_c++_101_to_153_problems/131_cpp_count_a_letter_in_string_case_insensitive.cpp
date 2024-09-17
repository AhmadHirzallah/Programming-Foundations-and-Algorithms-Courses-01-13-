#include <iostream>
#include <string>

using namespace std;

enum	e_captial_or_small
{
	small_letter = 1,
	capital_letter
};

string	ft_read_str();
short	ft_count_specific_character_in_str(string entered_string, char entered_char);
short	ft_count_specific_character_case_insensitive(string entered_string, char entered_char);

int	main()
{
	string	entered_string;
	char	entered_char;
	short	count_of;

	entered_string = ft_read_str();
	printf("\nPlease enter the character that you want to count:\n");
	cin >> entered_char;
	printf("\nThe entered string is:  (%s)\n", entered_string.c_str());
	printf("\nThe length of the string is: (%ld)", entered_string.length());
	printf("\nThe letter (%c) count is : (%hd)", entered_char, ft_count_specific_character_in_str(entered_string, entered_char));
	printf("\nThe letter (%c) count [in case insensitive] is: (%hd)\n", entered_char, ft_count_specific_character_case_insensitive(entered_string, entered_char));
	return (0);
}

string	ft_read_str()
{
	string	entered_str;

	printf("Please enter the string:\n");
	getline(cin >> ws, entered_str);
	return (entered_str);
}

short	ft_count_specific_character_in_str(string entered_string, char entered_char)
{
	short	c;
	short	count_of_the_character;

	count_of_the_character = 0;
	c = -1;
	while (++c < entered_string.length())
		if (entered_string[c] == entered_char)
			count_of_the_character++;
	return (count_of_the_character);
}

short	ft_count_specific_character_case_insensitive(string entered_string, char entered_char)
{
	short	c;
	short	count_of_the_character;

	count_of_the_character = 0;
	c = -1;
	while (++c < entered_string.length())
		if (tolower(entered_string[c]) == tolower(entered_char))
			count_of_the_character++;
	return (count_of_the_character);
}
