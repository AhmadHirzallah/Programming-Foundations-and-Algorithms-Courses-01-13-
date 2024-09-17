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

vector<string> ft_v_words_spliting_getting_tokens(string &entered_str)
{
	vector<string>	words;
	size_t	word_start_index;
	bool	is_word;
	short	c;
	short	word_len;

	word_start_index = 0;
	word_len = 0;
	is_word = false;
	c = -1;
	while(++c < entered_str.length())
	{
		if (isspace(entered_str[c]) && is_word)
		{
				word_len = c - word_start_index;
				words.emplace_back(entered_str.substr(word_start_index, word_len));
				is_word = false;
		}
		else if (!is_word && !isspace(entered_str[c]))
		{
			word_start_index = c;
			is_word = true;
		}
	}
	if (is_word)
	{
		word_len = entered_str.length() - word_start_index;
		words.emplace_back(entered_str.substr(word_start_index, word_len));
	}
	return (words);
}

string	ft_get_str_of_vector_elements(vector<string> &v_string, string delimiter = " ") 
{
	string	str_of_vector;
	short	c;
	
	c = -1;
	str_of_vector = "";

	while (++c < v_string.size())
		if (c != (v_string.size() - 1))
			str_of_vector += v_string[c] + delimiter; 
		else
			str_of_vector += v_string[c];
	return (str_of_vector);
}

string	ft_set_word_to_lower_case(string word)
{
	short	c;

	c = -1;
	while (++c < word.length())
		if (word[c] >= 'A' && word[c] <= 'Z')
			word[c] = tolower(word[c]);
	return (word);
}

string	ft_replace_word_in_str(string entered_string, string str_to_replace, string str_replace_to, bool case_sensitive = true)
{
	vector<string>  words;
	string	word_after;

	words = ft_v_words_spliting_getting_tokens(entered_string);
	for (string &word : words)
	{
		if (case_sensitive)
		{
			if (word == str_to_replace)
				word = str_replace_to;
		}
		else
		{
			if (ft_set_word_to_lower_case(word) == ft_set_word_to_lower_case(str_to_replace))
				word = str_replace_to;
		}
	}
	word_after = ft_get_str_of_vector_elements(words, " ");
	return (word_after);
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
	printf("\n\nThe string after replacing (Case Sensitive) is: (%s)\n", entered_string.c_str());
	entered_string = ft_replace_word_in_str(entered_string, string_to_replace, string_replace_to, false);
	printf("\n\nThe string after replacing (Case Insensitive) is: (%s)\n", entered_string.c_str());
	return (0);
}

