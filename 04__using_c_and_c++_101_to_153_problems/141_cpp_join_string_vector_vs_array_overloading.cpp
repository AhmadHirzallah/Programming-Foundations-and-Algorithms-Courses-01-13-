#include <string>
#include <iostream>
#include <vector>

using namespace std;

string	ft_str_join(vector<string> &v_string, string delimiter = " ") 
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

string	ft_str_join(string arr_string[], short	len, string delimiter = " ") 
{
	string	str_of_array;
	short	c;

	str_of_array = "";
	c = -1;
	while (++c < len) 
		if (c != len - 1) 
			str_of_array += arr_string[c] + delimiter; 
		else
			str_of_array += arr_string[c];
	return (str_of_array);
}

int main()
{
    vector<string>	v_string;
	string	arr_string[5];
	string	str_of_vector;
	string	str_of_array_strings;
	short	len;

	v_string = {"Mohammad", "Ahmad", "Leen", "Maher", "Waleed"};

	printf("\n__________\nVector of strings Section:");
	str_of_vector = ft_str_join(v_string);
	printf("The string of vector is: '%s'\n", str_of_vector.c_str());
	str_of_vector = ft_str_join(v_string, " ||--|| ");
	printf("\nThe string of vector is: '%s'\n", str_of_vector.c_str());
	str_of_vector = ft_str_join(v_string, ",");
	printf("\nThe string of vector is: '%s'\n", str_of_vector.c_str());
	str_of_vector = ft_str_join(v_string, " ### ");
	printf("\nThe string of vector is: '%s'\n", str_of_vector.c_str());
	printf("\n__________\n");
	printf("Array of strings Section:\n");
	arr_string[0] = "Mohammad";
    arr_string[1] = "Ahmad";
    arr_string[2] = "Leen";
    arr_string[3] = "Maher";
    arr_string[4] = "Waleed";
    len = 5;
	str_of_array_strings = ft_str_join(arr_string, 5);	
	printf("\nThe string of array is: '%s'\n", str_of_array_strings.c_str());
	str_of_array_strings = ft_str_join(arr_string, 5, ",");	
	printf("\nThe string of array is: '%s'\n", str_of_array_strings.c_str());
	str_of_array_strings = ft_str_join(arr_string, 5, "||--||");	
	printf("\nThe string of array is: '%s'\n", str_of_array_strings.c_str());
	str_of_array_strings = ft_str_join(arr_string, 5, " ### ");	
	printf("\nThe string of array is: '%s'\n", str_of_array_strings.c_str());
    return (0);
}


