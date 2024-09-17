#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void    *ft_malloc(int i_number_of_elements, int i_element_size);
void    ft_print_aaa_to_zzz_pattern(char    *p_pattern_str);

int main(int argc, char **argv)
{
	char	*p_pattern_str;

    if (argc != 1)
    {
        printf("Please only enter the file name.\n");
        return (1);
    }
    p_pattern_str = (char *)ft_malloc(4, sizeof(char));
    if (!p_pattern_str)
        return (2);
	strcpy(p_pattern_str, "AAA");
	ft_print_aaa_to_zzz_pattern(p_pattern_str);
	free(p_pattern_str);
    return (0);
}

void    ft_print_aaa_to_zzz_pattern(char    *p_pattern_str)
{

    while (p_pattern_str[0] <= 'Z')
    {
		p_pattern_str[1] = 'A';
        while (p_pattern_str[1] <= 'Z')
        {
			p_pattern_str[2] = 'A';
			while (p_pattern_str[2] <= 'Z')
			{
				printf("%s\n", p_pattern_str);
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

