#include <iostream>
#include <cstring>

using namespace std;

class	clsPerson
{
	public:
			virtual void	ft_print()
			{
				cout << "Hi, I am person a person.\n";
			}
};

class	clsEmployee : public clsPerson
{
	public:
			void	ft_print()
			{
				printf("Hi, I am an employee..\n");
			}
};

class	clsStudent : public clsPerson
{
	public:
			void	ft_print()
			{
				printf("Hi, I am a student..\n");
			}
};

int	main()
{
	clsEmployee	EmployeeObj;
	clsStudent	StudentObj;

	EmployeeObj.ft_print();
	StudentObj.ft_print();


	clsPerson	*PersonPtr1;
	clsPerson	*PersonPtr2;

	PersonPtr1 = &EmployeeObj;
	PersonPtr2 = &StudentObj;

	PersonPtr1->ft_print();
	PersonPtr2->ft_print();

	return (0);
}