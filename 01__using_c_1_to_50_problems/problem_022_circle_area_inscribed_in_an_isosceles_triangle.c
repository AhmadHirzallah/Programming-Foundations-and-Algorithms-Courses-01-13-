#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void	*ft_p_v_malloc(int i_items_number, int i_item_size);
float	*ft_p_calculate_circle_area(float *p_f_base, float *p_f_sides);
void	*ft_p_read_triangle_base_and_sides(float *p_f_base, float *p_f_sides);

int	main(void)
{
	float	*p_f_area;
	float	*p_f_base;
	float	*p_f_sides;

	p_f_base = (float *)ft_p_v_malloc(1, sizeof(float));
	p_f_sides = (float *)ft_p_v_malloc(1, sizeof(float));
	if (!p_f_base || !p_f_sides)
	{
		printf("Memory Allocation Failed!\n");
		return (1);
	}
	ft_p_read_triangle_base_and_sides(p_f_base, p_f_sides);
	p_f_area = ft_p_calculate_circle_area(p_f_base, p_f_sides);
	printf("The triangle area is: %.3f\n", *p_f_area);
	free (p_f_base);
	free (p_f_sides);
	free (p_f_area);
	return (0);
}

float	*ft_p_calculate_circle_area(float *p_f_base, float *p_f_sides)
{
	float   *p_f_area;

	p_f_area = (float *)ft_p_v_malloc(1, sizeof(float));
	if (!p_f_area)
	{
		printf("Memory Allocation Failed!\n");
		return (NULL);
	}
	*p_f_area = M_PI * (pow(*p_f_base, 2) / 4) * ((2 * *p_f_sides - *p_f_base) / (2 * *p_f_sides + *p_f_base));
}

void	*ft_p_read_triangle_base_and_sides(float *p_f_base, float *p_f_sides)
{
	printf("Please enter the triangle base length: ");
	scanf("%f", p_f_base);
	printf("Please enter the triangle sides length: ");
	scanf("%f", p_f_sides);
}

void	*ft_p_v_malloc(int i_items_number, int i_item_size)
{
	void	*p_v;

	p_v = (void *)malloc(i_items_number * i_item_size);
	if (!p_v)
		return (NULL);
	return (p_v);
}
