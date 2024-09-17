#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void    *ft_malloc(int i_number_of_elements, int i_element_size);
char	*ft_p_generate_a_key();
int	*ft_p_generate_random_nbr_in_range(int *from, int *to);
void	ft_generate_keys_in_count(short	keys_count, char *p_generated_key,  int *p_i_generated_random_nbr, int *from ,int *to);
void	ft_fill_array_with_keys(char keys_array[100][20], int i_len);
void	ft_print_2d_array_elements(char keys_array[100][20], short entered_len);

char	keys_array[100][20];
int	*p_i_generated_random_nbr;
int	i_len;
int	*from;
int	*to;

int	main(int argc, char **argv)
{

	if (argc != 2)
	{
		printf("Please enter the number of keys as command line argument after file name.\nFor Example:\n\"./problem_071_generate_keys 5\"\nThis will generate 5 keys.\nGoodluck.\n");
		return (2);
	}
	srandom((unsigned)time(NULL));
	from = ft_malloc(1, sizeof(int));
	to = ft_malloc(1, sizeof(int));
	p_i_generated_random_nbr = ft_malloc(1, sizeof(int));
	if (!p_i_generated_random_nbr || !from || !to)
		return (1);
	i_len = atoi(argv[1]);
	ft_fill_array_with_keys(keys_array, i_len);
	ft_print_2d_array_elements(keys_array, i_len);
	free(p_i_generated_random_nbr);
	free(from);
	free(to);
	return (0);
}

void	ft_print_2d_array_elements(char keys_array[100][20], short entered_len)
{
    short	c;

	c = 0;
    while (c < entered_len)
    {
        printf("Array[%hd] element: %s\n", c + 1, keys_array[c]);
		printf("\n");
        c++;
    }
}

char	*ft_p_generate_a_key()
{
	static char	str_generated_key[20];
	short	c;

	*from = (int)'A';
	*to = (int)'Z';
	c = 0;
	while (c < 19)
	{
		if (c == 4 || c == 9 || c == 14)
		{
			str_generated_key[c] = '-';
			c++;
			continue;
		}
		str_generated_key[c] = (char) *ft_p_generate_random_nbr_in_range(from, to);
		c++;
	}
	str_generated_key[c] = '\0'; // Null-terminate the string
	return (str_generated_key);
}

void	ft_fill_array_with_keys(char keys_array[100][20], int i_len)
{
	short	c;

	c = -1;
	while (++c < i_len)
		strcpy(keys_array[c], ft_p_generate_a_key());
}

int	*ft_p_generate_random_nbr_in_range(int *from, int *to)
{	
	*p_i_generated_random_nbr = random() % (*to - *from + 1) + *from;
	return (p_i_generated_random_nbr);
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



