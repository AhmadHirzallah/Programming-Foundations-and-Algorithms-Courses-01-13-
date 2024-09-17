#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void	*ft_v_malloc(int i_elements_count, int i_element_size);
float	*ft_calculate_circle_area(float *p_f_side_len);
void	ft_read_square_side_len(float *p_f_side_len);

int	main(void)
{
	float	*p_f_area;
	float	*p_f_side_len;

	p_f_side_len = (float *)ft_v_malloc(1, sizeof(float));
	ft_read_square_side_len(p_f_side_len);
	p_f_area = ft_calculate_circle_area(p_f_side_len);
	printf("The Area of the circle which is inscribed in square is: %.3f\n", *p_f_area);
	free(p_f_area);
	free(p_f_side_len);
	return (0);
}

float	*ft_calculate_circle_area(float *p_f_side_len)
{
	float	*p_f_circle_area;

	p_f_circle_area = (float *)ft_v_malloc(1, sizeof(float));
	if (!p_f_circle_area)
		return (NULL);
	*p_f_circle_area = M_PI * pow((*p_f_side_len / 2), 2);
	return (p_f_circle_area);
}

void	*ft_v_malloc(int i_elements_count, int i_element_size)
{
	void	*p_v;

	p_v = malloc(i_elements_count * i_element_size);
	if (!p_v)
		return (NULL);
	return (p_v);
}

void	ft_read_square_side_len(float *p_f_side_len)
{
	printf("Please enter the side length of the squared that inscribe around the circle: ");
	scanf("%f", p_f_side_len);
}
