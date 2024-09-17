#include <iostream>

using namespace std;


class cls_person
{
private:
    int _id = 10;
    string  _firstname;
    string  _lastname;

// Making id a read only property because this is in private
void    set_id(int id)
{
    _id = id;
}

public:




// Property GET
int id()
{
    return (_id);
}


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
string  fullname()
{
    return (_firstname + " " + _lastname);
}



};



int main(void)
{
    cls_person  person1;
    
//Disabled - Read Only - 
//  person1.set_id(20);
 //Error //cout << person1._lastname;

    person1.set_firstname("Ahmad");
    person1.set_lastname("Hirzallah");
    cout << "ID is:   " << person1.id() << endl;
    cout << "Firstname is: " << person1.firstname() << endl;
    cout << "Lastname is: " << person1.lastname() << endl;
    cout << "Fullname is: " << person1.fullname() << endl;
    return (0);
}