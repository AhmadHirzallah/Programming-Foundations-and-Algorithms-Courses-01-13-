#include <iostream>
#include <string>

using namespace std;

enum	e_captial_or_small
{
	small_letter = 1,
	capital_letter
};

string	ft_read_str();
short	ft_count_small_letters(string entered_string);
short	ft_count_capital_letters(string entered_string);
short	ft_count_letter_of_a_type(string entered_string, e_captial_or_small e_is_capital_or_small);

int	main()
{
	string	entered_string;
	short	count_of;

	entered_string = ft_read_str();
	printf("\nThe entered string is:  (%s)\n", entered_string.c_str());
	printf("\nThe length of the string is: (%ld)", entered_string.length());
	printf("\nThe count of the capital letters in the string is: (%hd)", ft_count_letter_of_a_type(entered_string, e_captial_or_small::capital_letter));
	printf("\nThe count of the small letters in the string is: (%hd)\n", ft_count_letter_of_a_type(entered_string, e_captial_or_small::small_letter));
	return (0);
}

string	ft_read_str()
{
	string	entered_str;

	printf("Please enter the string:\n");
	getline(cin >> ws, entered_str);
	return (entered_str);
}

short	ft_count_letter_of_a_type(string entered_string, e_captial_or_small e_is_capital_or_small)
{
	if (e_is_capital_or_small == e_captial_or_small::small_letter)
		return (ft_count_small_letters(entered_string));
	else if (e_is_capital_or_small == e_captial_or_small::capital_letter)
		return (ft_count_capital_letters(entered_string));
	else 
		return (-1);
}

short	ft_count_capital_letters(string entered_string)
{
	short	c;
	short	count_of_capital_letters;

	count_of_capital_letters = 0;
	c = -1;
	while (++c < entered_string.length())
		if (entered_string[c] >= 'A' && entered_string[c] <= 'Z')
			count_of_capital_letters++;
	return (count_of_capital_letters);
}

short	ft_count_small_letters(string entered_string)
{
	short	c;
	short	count_of_small_letters;

	count_of_small_letters = 0;
	c = -1;
	while (++c < entered_string.length())
		if (entered_string[c] >= 'a' && entered_string[c] <= 'z')
			count_of_small_letters++;
	return (count_of_small_letters);
}
