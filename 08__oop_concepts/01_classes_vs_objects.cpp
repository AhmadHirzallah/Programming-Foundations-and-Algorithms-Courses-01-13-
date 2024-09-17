// From structs and datatypes; we will have variables; But from classes we will have objects.

// Anything declared and defined inside the Class is (Private member , function)
	// So it cant be reached outside the class; only accessed from inside the class
	//	To reach them ; we can declare and define them under (Public:)

// ---------------------------------

//	Members:
//		 	1) Data Members: Any Variable declared inside the class that holds data; Like (first_name, last_name)
//	 		2) Member Methods Or Member Functions or Function Members: Any Function or Procedure declared inside class; Like (full_name)
				//		We cant hold data in them (Member Methods)	

#include <iostream>

using namespace std;

class cls_person
{
	public:
		string	first_name;
		string	last_name;
		string	full_name ()
		{
			return (first_name + " " + last_name);
		}

};

int	main (void)
{
	cls_person	person1;

	person1.first_name = "Ahmad";
	person1.last_name = "Hirzallah";
	cout << person1.full_name() << endl;
	return(0);
}
