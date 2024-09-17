#include <string>
#include <iostream>

using namespace std;

char  ft_read_char() 
{ 
	char	c;
	cout << "Please Enter a Character?\n";
	cin >> c;
	return (c);
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

int	main(/*int ac, char **av*/)
{
	char	entered_char;
	char	converted_char;
	
	entered_char = ft_read_char();
	converted_char = ft_convert_character_case(entered_char);
	printf("\nThe original character is: (%c)", entered_char);
	printf("\nThe converted character is: (%c)\n", converted_char);
	return (0);
}
