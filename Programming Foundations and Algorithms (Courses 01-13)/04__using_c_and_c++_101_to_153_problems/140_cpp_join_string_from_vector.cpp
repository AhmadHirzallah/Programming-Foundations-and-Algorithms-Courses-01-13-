#include <string>
#include <iostream>
#include <vector>

using namespace std;

string	ft_get_str_of_vector_elements(vector<string> &v_string, string delimiter = " ") 
{
	string	str_of_vector;
	short	c;
	
	c = -1;
	str_of_vector = "";

	while (++c < v_string.size())
		if (c != (v_string.size() - 1))
			str_of_vector += v_string[c] + delimiter; 
		else
			str_of_vector += v_string[c];
	return (str_of_vector);
}

int main()
{
    vector<string>	v_string;
	string	str_of_vector;

	v_string = {"Mohammad", "Ahmad", "Leen", "Maher", "Waleed"};
	str_of_vector = ft_get_str_of_vector_elements(v_string);
	printf("The string of vector is: '%s'\n", str_of_vector.c_str());
	str_of_vector = ft_get_str_of_vector_elements(v_string, " ||--|| ");
	printf("\nThe 2'nd string of vector is: '%s'\n", str_of_vector.c_str());
	str_of_vector = ft_get_str_of_vector_elements(v_string, ",");
	printf("\nThe 2'nd string of vector is: '%s'\n", str_of_vector.c_str());
	str_of_vector = ft_get_str_of_vector_elements(v_string, " ### ");
	printf("\nThe 2'nd string of vector is: '%s'\n", str_of_vector.c_str());
    return (0);
}

