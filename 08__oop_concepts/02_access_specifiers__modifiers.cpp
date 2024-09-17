/*
 *	- IF YOU DECLARED A VARIABLE WITHOUT SPECIFING ANY MODIFIER SUCH AS (PUBLIC, PRIVATE , PROTECTED); IT WILL BE PRIVATE AUTOMATICALLY
 *	- with or without private; the compiler will consider all things are private implicitly.
 *	- These private members aren't benifit to you as a developer outside of the class; these are considered better just for internal use inside the class itself.
 *
 * WE CAN HAVE BENIFITS OF THE CLASS MEMBERS (1- DATA MEMBERS / 2- MEMBERS FUNCTIONS) 
 * 1- INSIDE THE CLASS ITSELF SO MEMBERS CAN BENIFIT FROM OTHER MEMBERS (FUNCTIONS AND DATA MEMBERS)
 * 2- OUT OF THE CLASS IN THE MAIN AS WE CAN CREATE AN OBJECT AND THIS OBJECT COULD BE CALLED WHEN WE WANT; AND THEN WE CAN USE THE (FUNCTIONS MEMBERS AND DATA MEMBERS) THAT ARE ACCESSABLE
 * 3- ALL OTHER CALSSES THAT INHERET THIS SPECIFIC CLASS (INHERETING CLASSES) CAN BENEFIT ALSO FROM THE MEMBERS OF THE MAIN CLASS.
 */

/*
 *	WE HAVE 3 TYPES OF ACCESS SPECIFIERS (TO MEMBERS : FUNCTIONS AND DATA MEMBERS):
 *		1- PRIVATE (JUST INSIDE THE CLASS ITSELF, All members in the same class can reach other members if it is private) / No one can reach these members out of this class NOR An inheriting class.
 *		2- PROTECTED (JUST INSIDE : A- CLASS ITSELF		B- AND INHERITING CLASSES FROM CLASS ITSELF) / These members considered as private to all the members out of the class ,
 *		But members are Reachable from: Same class all members AND Inheriting classes from the class itself 
 *		So it is private to outside; and public to class itself and inheriting classes.
 *		3- PUBLIC (ALL CAN HAVE ACCESS): Accessable to all: For: 1- Outside of the class	2- Class members itself		3- Inheriting Classes.
 */

#include <iostream>

using namespace std;

class	cls_person
{

	int	variable2 = 100;
	int	function0()
	{
		return (25);
	}
	
private:

	int	variable1 = 5;

	int	function1()
	{
		return (50);
	}

public:

	string	firstname;	//Data member
	string	lastname;	// Data Member

	string	get_fullname()	//Member Function
	{
		return (firstname + lastname);
	}
	float	function2()
	{
		return (function1() + variable1 + variable2);
	}

protected:

	int	variable3 = 88;

	float	funtction3()
	{
		return (function2() + variable3);
	}
		
};

int	main()
{
	cls_person	person_ahmad;
	person_ahmad.firstname = "Ahmad";
	person_ahmad.lastname= "Hirzallah";
	cout << endl << person_ahmad.function2() << endl << endl;
	cout << person_ahmad.firstname << endl;
	cout << person_ahmad.lastname<< endl;
	cout << person_ahmad.get_fullname() << endl<< endl<< endl;

	return (0);
}
