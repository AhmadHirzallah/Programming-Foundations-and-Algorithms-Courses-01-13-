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

        // Copy Constructor
        cls_address(cls_address &old_object)
        {
            _address_line1 = old_object.address_line1();
            _address_line2 = old_object.address_line_2();
            _po_box = old_object.po_box();
            _zip_code = old_object.zip_code();
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
    cls_address ahmad_specific_add("Mohammad Alhajjaj Street/Shafa Badran", "CG 923", "7171", "5555");
    ahmad_specific_add.ft_print();
    
    cls_address cpy_ahmad_address_cls = ahmad_specific_add;
/*
      Compiler automatically create a ((copy constructor));
          and coppied all the members of the constructor 
            like addres line 1 , 2 , zip_code, po_box to the new created constructor

    - If this isn't done automatically; you need to create another constructor (with same name as functions overloading)
    - will have different parameters 
    - The copy constructor is always done automatically and you dont need to create it.
    - it (i dont know if shoud) have old object as parameter with reference to it. 
    - then you will assign the new object variables from old object vars
*/
    cls_address cpy_ahmad_address_cls2 = ahmad_specific_add;
    cpy_ahmad_address_cls2.ft_print();



    return (0);
}