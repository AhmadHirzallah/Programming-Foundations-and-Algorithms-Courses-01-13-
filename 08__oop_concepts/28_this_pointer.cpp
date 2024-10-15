#include <iostream>

using namespace std;

class clsA {
public:
    int x = 1;

    void Print() {
        cout << "The value of x = " << x << endl;
    }
};

void	ft2(clsA &A1)
{
	A1.x = 200;
}





class	clsSample
{
	public:
			int	a;
			void	ft_show_address()
			{
				cout << "Address of the current object: " << this << endl;
			}
};

class	clsEmployee
{
	public:
			int ID;
			string Name;

			// clsEmployee(int id, string name)
			// {
			// 	this->ID = id;
			// 	this->name = name;
			// }
			clsEmployee(int ID, string Name)
			{
				// Using this to refer to class members
				this->ID = ID;
				this->Name = Name;
			}
			static void staticFunc()
			{
				// cout << this; // ERROR: static functions can't use this pointer
			}
			void nonStaticFunc() 
			{
				cout << "Non-static function, this points to: " << this << endl;
			}

			clsEmployee& setID(int id)
			{
				this->ID = id;
				return *this; // Returning the current object
			}

			static void	ft_print_info(clsEmployee &emp)
			{
				cout << "Employee ID: " << emp.ID << endl;
			}

			void	ft_print()
			{
				ft_print_info(*this);
			}
};





int	main(void)
{
	clsA A1;

	A1.Print();
	ft2(A1);
	A1.Print();
	cout <<"\n\n\n";








	clsSample obj1, obj2;
	obj1.a = 5;
	obj2.a = 10;
	obj1.ft_show_address();
	obj2.ft_show_address();

	clsEmployee Employee1(2134, "Ahmad Hirzallah");
	cout << "Name: " <<Employee1.Name << " / ID: " << Employee1.ID << endl << endl << endl;

	Employee1.nonStaticFunc();

	Employee1.setID(101).setID(102);
	cout <<"\n\n\nID: " << Employee1.ID << endl << endl << endl;

	Employee1.ft_print();

	return (0);
}

