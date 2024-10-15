#include <iostream>

using namespace std;

class	clsPerson
{
	struct st_address
	{
		string address_line1;
		string address_line2;
		string city;
		string country;
	};
	
	public :
			string	fullname;
			st_address address;
			
			clsPerson()
			{
				fullname = "Ahmad Hirzallah";
				address.address_line1 = "Building 1";
				address.address_line2 = "Shafa Badran St.";
				address.city = "Amman";
				address.country = "Jordan";
			};
	void	ft_print_address()
	{
		cout <<"\nAddress:\n";
		cout << address.address_line1 << endl;
		cout << address.address_line2<< endl;
		cout << address.city << endl;
		cout << address.country << endl;
	}
};

int	main(void)
{
	clsPerson PersonObj;

	PersonObj.ft_print_address();
	cout << "\nAccessing Struct inside Class:\n" << PersonObj.address.address_line1 << "/" 
		<< PersonObj.address.address_line2 << "/" 
		<< PersonObj.address.city << "/"
		<< PersonObj.address.country << endl << endl;

	return (0);
}
