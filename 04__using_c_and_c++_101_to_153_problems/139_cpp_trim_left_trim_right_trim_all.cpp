#include <iostream>
#include <cstdio>
#include <vector>
#include <cctype>

using namespace std;

string	ft_trim_left(string sentence) 
{
	string	str_trimmed;
	short	c;

	str_trimmed = sentence;
	c = -1;
    while (++c < sentence.length() && isspace(str_trimmed[c])) 
	;
	str_trimmed = str_trimmed.substr(c);
    return (str_trimmed);
}

string	ft_trim_right(string sentence) 
{
	short	c;
	string	str_trimmed;

	str_trimmed = "";
	c = sentence.length();
    while (--c >= 0 && isspace(sentence[c])) 
		;
	str_trimmed = sentence.substr(0, c + 1);
    return (str_trimmed);
}

string	ft_trim_left_and_right(string sentence)
{
	string	trimmed;
	
	trimmed = ft_trim_left(ft_trim_right(sentence));
	return (trimmed);
}

string	ft_read_string(string message)
{
	string	entered_str;
	
	printf("%s", message.c_str());
	getline(cin , entered_str);
	return (entered_str);
}

int	main()
{
	string	entered_str;
	string	left_trimmed;
	string	right_trimmed;
	string	trimmed;
	
	entered_str = ft_read_string("Please enter the string to count its words:\n");
	printf("Original string: '%s'\n", entered_str.c_str());
	left_trimmed =  ft_trim_left(entered_str);
	printf("Left trimmed: '%s'\n", left_trimmed.c_str());
	right_trimmed = ft_trim_right(entered_str);
	printf("Right trimmed: '%s'\n", right_trimmed.c_str());
	trimmed = ft_trim_left_and_right(entered_str);
	printf("Both sides trimmed: '%s'\n", trimmed.c_str());
	return (0);
}

