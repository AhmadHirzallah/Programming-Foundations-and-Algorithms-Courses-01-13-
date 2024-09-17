#include <iostream>
#include <string>

using namespace std;

void	ft_print_is_vowel_result(short result, char entered_char);
short	ft_check_is_vowel(char entered_char);

int	main()
{
	char	entered_char;

	printf("\nPlease enter the character that you want to check:\n");
	cin >> entered_char;
	ft_print_is_vowel_result(ft_check_is_vowel(entered_char), entered_char);
	return (0);
}

void	ft_print_is_vowel_result(short result, char entered_char)
{
	if (result)
		printf("\nThe letter (%c) is a (Vowel)\n", entered_char);
	else
		printf("\nThe letter (%c) isn't a (Vowel)\n", entered_char);


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
