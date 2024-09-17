/*
    
    -  It is foribidden to have an empty object; for example like empty string as data printed when we run a program;

    -  Always Object indicated and refers to an entity so it cant be an empty thing.

    -  So if we have an (address (location) obj) of (address (location) class) It should be filled and refers to a real life object

    -  You have to  be  blocked  from creating an empty object; Using OOP and Classes ومفاهيم برمجية

    -  (Constructor من يقوم بالبناء (إسم مفعول)) word comes from (Construction : بناء)

    -  Constructor is always exist when you create any object of any class; ALways Created; 
        - If you dont define your constructor the compiler will do this (Automatically) and it will be hidden.

    -  Constructor is like a method or function that will be called; whenever you create object of class
        -   And always there is a default constructor that is hidden if you don't create one.

    -   It is like a function  (Or can be called it is a function - it is special type of fnctions members) - without datatype and have the same name of the class
            -   It also can to not take any parameter; like: cls_person(no_parameter) --> cls_person() 
            
            -   Or it can take parameters as :  clsAddress(stringAddressLine1, stringAddressLine2, stringPOBox, stringZipCode)
                - Having like this constructor will override (اللغاء الكونستركتر العام) the default constructor of the class that is empty of parameters.


    -   We can take advantage of a function that can be called always (Should be called) whenever we create an Object from Class
    -   The advantage of cons is it prevent creating empty obj of class
    -   cons should always be under public ; not priva or protected

*/

#include <iostream>

using namespace std;

class   cls_address
{
    private:
            string  _address_line1;
            string  _address_line2;
            string  _po_box;
            string  _zip_code;

    public:

/*
        cls_address()
        {
            printf("Hi; I am the constructor of the class !\n\n");
        }
*/
        //  Now; No one can create any object of the address unless the data of the object is sent and read and entered; 
            // - So objects always should be filled and not empty
            //      - So we achieved our goal that objects cant be empty.
        cls_address(string address_line1, string address_line2, string po_box, string zip_code)
        {
            _address_line1 = address_line1;
            _address_line2 = address_line2;
            _po_box = po_box;
            _zip_code = zip_code;
        }

            void    set_address_line1(string read_address)
            {
                _address_line1 = read_address;
            }

            string  address_line1()
            {
                return (_address_line1);
            }

            void    set_address_line2(string read_address)
            {
                _address_line2 = read_address;
            }

            string  address_line_2()
            {
                return (_address_line2);
            }

            void  set_po_box(string read_po_box)
            {
                _po_box = read_po_box;
            }

            string  po_box()
            {
                return (_po_box);
            }

            void    set_zip_code(string read_zip_code)
            {
                _zip_code = read_zip_code;
            }

            string  zip_code()
            {
                return (_zip_code);
            }

            void    ft_print()
            {
                printf("\nAddress Details:\n\n");
                printf("_________________________\n\n");
                printf("Address Line 1:  %s\n", _address_line1.c_str());
                printf("Address Line 2:  %s\n", _address_line2.c_str());
                printf("POBox Number:  %s\n", _po_box.c_str());
                printf("Zip Code:  %s\n\n\n", _zip_code.c_str());
            }
};

int main (void)
{
    cls_address ahmad_address("Jordan", "Amman", "7171", "1234");
    ahmad_address.ft_print();
    cls_address ahmad_specific_add("Mohammad Alhajjaj Street/Shafa Badran", "CG 923", "7171", "5555");
    ahmad_specific_add.ft_print();


    return (0);
}