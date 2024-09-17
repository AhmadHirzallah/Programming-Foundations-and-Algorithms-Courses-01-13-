#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void    *ft_malloc(int i_number_of_elements, int i_element_size);
void    ft_check_password_in_aaatozzz_pattern(char *p_chosen_password ,char *p_pattern_str);

int main(int argc, char **argv)
{
	char	*p_pattern_str;
	char	*p_chosen_password;

    if (argc != 2)
    {
        printf("Please only enter the 3 Letters Password (ALL CAPITALS) after file name.\n");
        return (1);
    }
    p_pattern_str = (char *)ft_malloc(4, sizeof(char));
    if (!p_pattern_str)
        return (2);
	p_chosen_password = argv[1];
	strcpy(p_pattern_str, "AAA");
	ft_check_password_in_aaatozzz_pattern(p_chosen_password, p_pattern_str);
	free(p_pattern_str);
    return (0);
}

void    ft_check_password_in_aaatozzz_pattern(char *p_chosen_password ,char *p_pattern_str)
{
	long	l;

	l = 0;
    while (p_pattern_str[0] <= 'Z')
    {
		p_pattern_str[1] = 'A';
        while (p_pattern_str[1] <= 'Z')
        {
			p_pattern_str[2] = 'A';
			while (p_pattern_str[2] <= 'Z')
			{
				++l;
				if (strcmp(p_pattern_str, p_chosen_password) == 0)
				{
					printf("Password is %s, found after %ld trials\n", p_chosen_password, l);
					return ;
				}
				else if (strcmp(p_pattern_str, p_chosen_password) != 0)
					printf("Trial [%ld]: %s\n", l, p_pattern_str);
				p_pattern_str[2]++;
			}
			p_pattern_str[1]++;
        }
		p_pattern_str[0]++;
    }
}

void    *ft_malloc(int i_number_of_elements, int i_element_size)
{
    void    *p_v;

    p_v = (void *)malloc(i_number_of_elements * i_element_size);
    if (!p_v)
    {
        printf("Unfortunatelly; Memory allocation failed.\n");
        return (NULL);
    }
    return (p_v);
}


