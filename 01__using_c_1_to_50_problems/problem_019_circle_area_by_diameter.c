#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float	*ft_calculate_circle_area(float *p_f_diameter);
void	ft_read_circle_diameter(float *p_f_diameter);
void	*ft_generic_malloc(int i_elements_count, int i_element_size);

int	main(void)
{
	float	*p_f_diameter;
	float	*p_f_result;

	p_f_diameter = (float *)ft_generic_malloc(1, sizeof(float));
	if (!p_f_diameter)
		return (1);
	ft_read_circle_diameter(p_f_diameter);
	p_f_result = ft_calculate_circle_area(p_f_diameter);
	printf("The Circle area is: %.3f\n", *p_f_result);
	free(p_f_diameter);
	free(p_f_result);
	return (0);
}

float	*ft_calculate_circle_area(float *p_f_diameter)
{
	float	*p_f_area;

	p_f_area = ft_generic_malloc(1, sizeof(float));
	if (!p_f_area)
		return (NULL);
	*p_f_area = (M_PI * pow(*p_f_diameter, 2)) / 4.0;
	return (p_f_area);
}

void	ft_read_circle_diameter(float *p_f_diameter)
{
	printf("Please enter the diameter of the circle: ");
	scanf("%f", p_f_diameter);
}

void	*ft_generic_malloc(int i_elements_count, int i_element_size)
{
	void	*p_v;

	p_v = (malloc(i_elements_count * i_element_size));
	if (p_v == NULL)
	{
		fprintf(stderr, "Memory allocation failed.\n");
		return (NULL);
	}
	return (p_v);
}
