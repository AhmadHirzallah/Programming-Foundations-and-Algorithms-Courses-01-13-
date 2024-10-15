#include <iostream>

using namespace std;

class	clsPerson
{
	class	clsAddress
	{
		public:
				string address_line1;
				string address_line2;
				string city;
				string country;

				void	ft_print_address()
				{
					cout <<"\nAddress:\n";
					cout << address_line1 << endl;
					cout << address_line2<< endl;
					cout << city << endl;
					cout << country << endl;
				}
	};
	
	public:
			string fullname;
			clsAddress Address;
			clsPerson()
			{
				fullname = "Mohammed Abuhadhoud";
				Address.address_line1 = "Building 1";
				Address.address_line2 = "Ali Alzadik Street";
				Address.city = "Dubai";
				Address.country = "UAE";
			}

};

int	main (void)
{
	clsPerson Person;

	cout << "Address Class reaching by Person Class:\n" 
		<< "["<< Person.Address.address_line1 << "/" << Person.Address.address_line2
		<< "/" << Person.Address.city << "/" << Person.Address.country << "]" << endl;

	cout << "\n-----------\n";
	Person.Address.ft_print_address();
	cout << "\n-----------\n";

	cout << "Person Name: " << Person.fullname << endl << endl;
	return (0);
}
/*

>- Like we declare int char or any datatype and we can do anything we want as properties set and get and specifiers asd private and public ; 
then  the sstructure is a data type and can be do the same as any datatype;

>- Can we declare class inside class;?  
We know that the class is a data type like structure int boolean string
so we can declare class inside class;
As like as structure address we can declare class inside the class

>- in the internall  cllass we can do whatever we want as createing constuctors and get and set properties and we can do any OOP rule we want
>- The outer class clsPerson is called the inclusor (المحتوي) and clsAddress is called inner class
>- we have defined the clsADdress and it is defined as datatype inside person class (class inside class)
>- So we create object of the class inside the class
>- The code is better now ; we can see that printaddress function is now more appropiat organization because it belongs to the address not to the person ; and it is printing address it should be  related to address object
>- The code become organized;
>- So ; The concept ; the Nested class or inner class is consider and dealt with as a class.
>- We can see that if we want we can also create a constructor inside the inner class like clsAddress class having st_address structor of the string variables;
>- We can also create a constructor inside inner class and create object with addresses and city and country and all vars making validation of the object before creating ; (No object can be empty)

*/