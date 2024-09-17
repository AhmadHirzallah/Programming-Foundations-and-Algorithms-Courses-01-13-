#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float   *ft_p_calculate_circle_area(float *p_f_side1, float *p_f_side2, float *p_f_side3);
void    *ft_p_v_malloc(int i_items_number, int i_item_size);
void    *ft_p_read_triangle_3sides(float *p_f_side1, float *p_f_side2, float *p_f_side3);

int main(void)
{
    float   *p_f_area;
	float	*p_f_side1;
	float	*p_f_side2;
	float	*p_f_side3;

    p_f_side1 = (float *)ft_p_v_malloc(1, sizeof(float));
    p_f_side2 = (float *)ft_p_v_malloc(1, sizeof(float));
    p_f_side3 = (float *)ft_p_v_malloc(1, sizeof(float));
    if (!p_f_side1 || !p_f_side2 || !p_f_side3)
    {
        printf("Memory Allocation Failed!\n");
        return (1);
    }
    ft_p_read_triangle_3sides(p_f_side1, p_f_side2, p_f_side3);
    p_f_area = ft_p_calculate_circle_area(p_f_side1, p_f_side2, p_f_side3);
    printf("The triangle area is: %.3f\n", *p_f_area);
    free (p_f_side1);
    free (p_f_side2);
    free (p_f_side3);
    free (p_f_area);
    return (0);
}

float   *ft_p_calculate_circle_area(float *p_f_side1, float *p_f_side2, float *p_f_side3)
{
    float   *p_f_area;
	float	f_tmp;
	float	f_p;

    p_f_area = (float *)ft_p_v_malloc(1, sizeof(float));
    if (!p_f_area)
    {
        printf("Memory Allocation Failed!\n");
        return (NULL);
    }
	f_p = (*p_f_side1 + *p_f_side2 + *p_f_side3) / 2;
	f_tmp = (*p_f_side1 * *p_f_side2 * *p_f_side3) / (4 * sqrt(f_p * (f_p - *p_f_side1) * (f_p - *p_f_side2) * (f_p - *p_f_side3)));
    *p_f_area = M_PI * pow(f_tmp, 2);
	return (p_f_area);
}

void    *ft_p_read_triangle_3sides(float *p_f_side1, float *p_f_side2, float *p_f_side3)
{
    printf("Please enter the triangle 1'st side length: ");
    scanf("%f", p_f_side1);
    printf("Please enter the triangle 2'nd sides length: ");
    scanf("%f", p_f_side2);
    printf("Please enter the triangle 3'rd sides length: ");
    scanf("%f", p_f_side3);
}

void    *ft_p_v_malloc(int i_items_number, int i_item_size)
{
	void	*p_v;

	p_v = (void *)malloc(i_items_number * i_item_size);
	if (!p_v)
		return (NULL);

	return (p_v);
}

