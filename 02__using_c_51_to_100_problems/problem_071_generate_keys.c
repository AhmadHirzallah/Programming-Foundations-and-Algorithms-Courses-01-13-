#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void    *ft_malloc(int i_number_of_elements, int i_element_size);
char	*ft_p_generate_a_key(char    *p_generated_key, int *p_i_generated_random_nbr, int *from ,int *to);
int	*ft_p_generate_random_nbr_in_range(int *p_i_generated_random_nbr, int *from, int *to);
void	ft_generate_keys_in_count(short	keys_count, char *p_generated_key,  int *p_i_generated_random_nbr, int *from ,int *to);

int	main(int argc, char **argv)
{
	int	*p_i_generated_random_nbr;
	int	*from;
	int	*to;
	char	*p_generated_key;

	if (argc != 2)
	{
		printf("Please enter the number of keys as command line argument after file name.\nFor Example:\n\"./problem_071_generate_keys 5\"\nThis will generate 5 keys.\nGoodluck.\n");
		return (2);
	}

	srandom((unsigned)time(NULL));
	from = ft_malloc(1, sizeof(int));
	to = ft_malloc(1, sizeof(int));
	p_i_generated_random_nbr = ft_malloc(1, sizeof(int));
	p_generated_key = ft_malloc(20, sizeof(char));
	p_generated_key[19] = '\0';
	if (!p_i_generated_random_nbr || !from || !to || !p_generated_key)
		return (1);
	ft_generate_keys_in_count(atoi(argv[1]), p_generated_key, p_i_generated_random_nbr,from, to);
	free(p_i_generated_random_nbr);
	free(from);
	free(to);
	free(p_generated_key);
	return (0);
}

void	ft_generate_keys_in_count(short	keys_count, char *p_generated_key,  int *p_i_generated_random_nbr, int *from ,int *to)
{
	short	c;

	c = 0;
	while (c++ < keys_count)
	{
		p_generated_key = ft_p_generate_a_key(p_generated_key, p_i_generated_random_nbr, from, to);
		printf("Generated key number (%d) is:  %s\n", c, p_generated_key);
	}
}

char	*ft_p_generate_a_key(char    *p_generated_key, int *p_i_generated_random_nbr, int *from ,int *to)
{
	short	c;

	*from = (int)'A';
	*to = (int)'Z';
	c = 0;
	while (c < 20)
	{
		if (c == 4 || c == 9 || c == 14)
		{
			p_generated_key[c] = '-';
			c++;
			continue;
		}
		p_generated_key[c] = (char) *ft_p_generate_random_nbr_in_range(p_i_generated_random_nbr, from, to);
		c++;
	}
	return (p_generated_key);
}

int	*ft_p_generate_random_nbr_in_range(int *p_i_generated_random_nbr, int *from, int *to)
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


