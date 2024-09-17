#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef enum	t_e_palindrome_or_not
{
	palindrome = 1,
	not_palindrome = 0
}	t_e_palindrome_or_not;	

void	ft_fill_i_array_with_random_nbrs_ranged1to100(int i_array[100], short   *entered_len, short *from, short *to);
t_e_palindrome_or_not	*ft_check_array_is_palindrom(int i_array[100], short array_len);
int	*ft_p_generate_random_nbr_in_range(int *p_i_generated_random_nbr, int *from, int *to);
void    *ft_malloc(int i_number_of_elements, int i_element_size);
void	ft_print_array_elements(int i_array[100], short entered_len);
void	ft_print_is_palindrom_result(int i_array[100], t_e_palindrome_or_not *p_e_is_palindrome);

int	i_array[100];
short	entered_len;
int *p_i_generated_random_nbr;
t_e_palindrome_or_not	*p_e_is_palindrome;

int	main(int argc, char **argv)
{
	short	*from;
	short	*to;

	srand((unsigned)time(NULL));
	entered_len = 0;
	p_i_generated_random_nbr = ft_malloc(1, sizeof(int));
	p_e_is_palindrome = ft_malloc(1, sizeof(t_e_palindrome_or_not));
	from = ft_malloc(1, sizeof(short));
	to = ft_malloc(1, sizeof(short));
	if (!p_i_generated_random_nbr || !from || !to)
		return (2);
	entered_len = (short)atoi(argv[1]);
	ft_fill_i_array_with_random_nbrs_ranged1to100(i_array, &entered_len, from, to);
	printf("The array elements:\n");
	ft_print_array_elements(i_array, entered_len);
	printf("\n");
	ft_print_is_palindrom_result(i_array, p_e_is_palindrome);
	free(p_i_generated_random_nbr);
	free(p_e_is_palindrome);
	free(from);
	free(to);
	return (0);
}

void	ft_print_is_palindrom_result(int i_array[100], t_e_palindrome_or_not *p_e_is_palindrome)
{
	*p_e_is_palindrome = *ft_check_array_is_palindrom(i_array, entered_len);
	if (*p_e_is_palindrome == palindrome)
		printf("\nYes; Array is palindrome.\n");
	else if (*p_e_is_palindrome == not_palindrome)
		printf("\nNo; Array ISN'T palindrome.\n");
}

t_e_palindrome_or_not	*ft_check_array_is_palindrom(int i_array[100], short array_len)
{
	short	c;

	c = 0;
	if (array_len == 1)
	{
		*p_e_is_palindrome = palindrome;
		return (p_e_is_palindrome);
	}

	while (c < array_len)
	{
		if (i_array[c] != i_array[array_len - 1 - c])
		{
			*p_e_is_palindrome = not_palindrome;
			return (p_e_is_palindrome);
		}
		c++;
	}
			*p_e_is_palindrome = palindrome;
			return (p_e_is_palindrome);
}

void	ft_fill_i_array_with_random_nbrs_ranged1to100(int i_array[100], short   *entered_len, short *from, short *to)
{
	short	l;
	*from = 1;
	*to = 5;

	l = 0;
	while (l < *entered_len)
	{
		i_array[l++] = *ft_p_generate_random_nbr_in_range(p_i_generated_random_nbr, (int *)from, (int *)to);
	}
}

void ft_print_array_elements(int i_array[100], short entered_len)
{
    short	c;

    c = 0;
    while (c < entered_len)
    {
        printf("%d  ", i_array[c]);
        c++;
    }
    printf("\n");
}

int	*ft_p_generate_random_nbr_in_range(int *p_i_generated_random_nbr, int *from, int *to)
{	
	*p_i_generated_random_nbr = rand() % (*to - *from + 1) + *from;
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




