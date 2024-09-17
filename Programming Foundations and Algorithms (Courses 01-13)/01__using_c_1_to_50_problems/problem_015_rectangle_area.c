#include <stdio.h>
#include <stdlib.h>


void	ft_print_rectangle_area(float f_area);
float	ft_str_to_float(const char *str);
void	ft_read_2_f_numbers(float *p_f_len, float *p_f_wid);
float	ft_calculate_rectangle_area(float *p_f_1, float *p_f_2);

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Error!\nPlease enter the Length and the Width (Command-line Arguments) after program name");
			return (1);
	}
	float	*p_f_length;
	float	*p_f_width;

	p_f_length = (float *)malloc(sizeof(float));
	p_f_width= (float *)malloc(sizeof(float));
	if (p_f_length == NULL || p_f_width == NULL)
	{
		printf("ERROR!\n Memory allocation failed.\n");
		return (2);
	}
//	ft_read_2_f_numbers(p_f_length, p_f_width);
	*p_f_length = (float)ft_str_to_float(argv[1]);
	*p_f_width = (float)ft_str_to_float(argv[2]);
	ft_print_rectangle_area(ft_calculate_rectangle_area(p_f_length, p_f_width));
	free(p_f_length);
	free(p_f_width);
	return (0);
}
/*
void	ft_read_2_f_numbers(float *p_f_len, float *p_f_wid)
{
	printf("Please enter the length of the rectangle: ");
	scanf("%f", p_f_len);
	printf("Please enter the width of the rectangle: ");
	scanf("%f", p_f_wid);
}
*/

float	ft_str_to_float(const char *str) 
{
    float	result;
    int	sign;
    int	decimal_places;
    
	result = 0.0;
	sign = 1;
	decimal_places = 0;
    if (*str == '-')
	{
        sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9') 
	{
        result = result * 10 + (*str - '0');
        str++;
    }
    if (*str == '.') 
	{
        str++;
        while (*str >= '0' && *str <= '9') {
            result = result * 10 + (*str - '0');
            decimal_places++;
            str++;
        }
    }
    result *= sign;
    for (int i = 0; i < decimal_places; i++) 
	{
        result /= 10;
    }
    return (result);
}

float	ft_calculate_rectangle_area(float *p_f_1, float *p_f_2)
{
		return (*p_f_1 * *p_f_2);
}

void	ft_print_rectangle_area(float f_area)
{
	printf("Rectangle Area is: %.*f\n", 3, f_area);
}
