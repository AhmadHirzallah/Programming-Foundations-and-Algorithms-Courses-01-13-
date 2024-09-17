#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void	ft_read_diag_and_side_of_rect(float *p_f_diag, float *p_f_side_l);
void	*ft_generic_malloc(int num_elements, int element_size);
float	ft_calculate_rectangle_area(float *p_f_diag, float *p_f_side_l);

int	main(void)
{
	float	*p_f_diagonal;
	float	*p_f_side_len;

	p_f_diagonal = (float *)ft_generic_malloc(1, sizeof(float));
	p_f_side_len = (float *)ft_generic_malloc(1, sizeof(float));

	if (p_f_diagonal == NULL || p_f_side_len == NULL)
		return (1);
	ft_read_diag_and_side_of_rect(p_f_diagonal, p_f_side_len);
	printf("The rectangle area is: %.2f\n", ft_calculate_rectangle_area(p_f_diagonal, p_f_side_len));
	free(p_f_diagonal);
	free(p_f_side_len);
	return (0);
}

void	ft_read_diag_and_side_of_rect(float *p_f_diag, float *p_f_side_l)
{
	printf("Please enter the diagonal: ");
	scanf("%f", p_f_diag);
	printf("Please enter the side: ");
	scanf("%f", p_f_side_l);
}

void	*ft_generic_malloc(int num_elements, int element_size)
{
    void	*p_v;
	p_v = malloc(num_elements * element_size);
    if (p_v == NULL)
	{
        fprintf(stderr, "Memory allocation failed.\n");
        return (NULL);
    }
    return (p_v);
}

float	ft_calculate_rectangle_area(float *p_f_diag, float *p_f_side_l)
{
	return (sqrt(pow(*p_f_diag, 2) - pow(*p_f_side_l, 2)) * (*p_f_side_l));
}
