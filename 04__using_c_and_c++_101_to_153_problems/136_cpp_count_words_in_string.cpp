#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

short	ft_count_words(string sentence) 
{
    short	count = 0;
    short	in_word = 0;
	short	c;

	c = -1;
    while (++c < sentence.length()) 
	{
        if (sentence[c] >= 9 && sentence[c] <= 13
				|| sentence[c] == 32) 
            in_word = 0;
		else if (!in_word)
		{
            in_word = 1;
            count++;
        }
    }
    return (count);
}

void	ft_print_words_count_result(string &entered_str)
{
	printf("The count of words in the string (%s) is: (%hd)\n", entered_str.c_str(), ft_count_words(entered_str));
}

string	ft_read_string(string message)
{
	string	entered_str;
	
	printf("%s", message.c_str());
	getline(cin >> ws, entered_str);
	return (entered_str);
}

int	main(int ac, char **av)
{
	string	entered_str;
	
	entered_str = ft_read_string("Please enter the string to count its words:\n");
	ft_print_words_count_result(entered_str);
	return (0);
}
