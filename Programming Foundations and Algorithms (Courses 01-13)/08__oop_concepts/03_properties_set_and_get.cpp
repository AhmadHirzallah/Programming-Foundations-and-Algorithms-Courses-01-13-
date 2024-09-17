
#include <iostream>

using namespace std;


class cls_person
{
private:
    string  _firstname;
    string  _lastname;


public:
// Property SET
void    set_firstname(string firstname)
{
    _firstname = firstname;
}

// Property GET
string  firstname()
{
    return (_firstname);
}
// SET
void    set_lastname(string lastname)
{
    _lastname = lastname;    
}
//GET
string  lastname()
{
    return (_lastname);
}

// GET
string  ft_get_fullname()
{
    return (_firstname + " " + _lastname);
}



};



int main(void)
{
    cls_person  person1;
    
    person1.set_firstname("Ahmad");
    person1.set_lastname("Hirzallah");
    cout << "Firstname is: " << person1.firstname() << endl;
    cout << "Lastname is: " << person1.lastname() << endl;
    cout << "Fullname is: " << person1.ft_get_fullname() << endl<< endl<< endl;
;
    return (0);
}

