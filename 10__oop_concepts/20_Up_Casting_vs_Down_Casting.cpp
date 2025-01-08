#include <iostream>

using	namespace std;

class	clsPerson
{
	private:
				string	_fullname = "Ahmad Hirzallah";
	
	public:
				string	fullname()
				{
					return (_fullname);
				}
};

class	clsEmployee : public clsPerson
{
	private:
				string	_title = "Web Developer";
	
	public:
				string	title()
				{
					return (_title);
				}
};

int	main(void)
{
	clsPerson				person1;
	clsEmployee	employee1;

	cout << person1.fullname() << endl;
	cout << employee1.fullname() << endl;
	cout << employee1.title() << endl;

	////upcasting
	//this will convert employee to person as pointer.

		clsPerson	*ptr_person2 = &employee1;
		cout << "\n\nPointer object: " << ptr_person2->fullname() << endl;



	////ERROR 
	////downcasting : you cannot convert person to employee

		//clsEmployee	*ptr_employee2 = &person1;
		//cout <<ptr_employee2->fullname();


	return (0);
}