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

string	ft_remove_punctuations_from_str(string entered_string)
{
	short	c;

	c = -1;
	while (++c < entered_string.length())
	{
		/*if ((entered_string[c] >= 33 && entered_string[c] <= 47)
				|| (entered_string[c] >= 58 && entered_string[c] <= 63))
			entered_string.erase(c--, 1);*/
		if (ispunct(entered_string[c]))
			entered_string.erase(c--, 1);

	}
	return (entered_string);
}

int	main()
{
	string	entered_string;

	entered_string = ft_read_string("Please enter the whole string:\n");
	printf("\n\nThe Original string is: (%s)\n", entered_string.c_str());
	entered_string = ft_remove_punctuations_from_str(entered_string);
	printf("\n\nThe string after removing punctuations is: (%s)\n", entered_string.c_str());
	return (0);
}

