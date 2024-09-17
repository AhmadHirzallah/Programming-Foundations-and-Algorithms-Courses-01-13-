/*
    Static variables inside function; like static x; 
        - When function scope is ended/finshed every variable and object will be destroyed;
            -   Unless (باستثناء) it was static; the static lifetime is (Project complete lifetime).

        - When we create 10 object of specific class; like object1,object2,object3 ...;
        - Every object will have a class variable like obj1.var1, obj2.var1, obj3.var1;
        - Every object is separated from each others; and when object call scope ends;
            - the variable will be ended and terminated
        - We need variable shared to all object of specific class which willnot be destroyed;
            - Like global variable only at class level to every object of this class على مستوى الكلاس 
            - So it is shared at class lvl to all the objects. (Not only object level; it is class level)
        * This is called (static member) of class;

        * in (C++) it is called (static)  /  * in (C#, Visual Basic) is called (shared)
        
        //static variable initialisation outside the class - Because it is same as global variable but just for a class
// And its lifetime will be program lifetime as int clsA::counter = 0; 
and this should be before calling any function (also main function considered function) so it is above it 

So Global/static var of class should be initialized befor any call in the system;otherwise errors will appear then it will life time will be progr. lifetime

*/

using namespace std;

#include <iostream>

class   clsA
{
    // If we have 10 objects of this class we will have (10) (var) variables;
    int _var;    
    // If we have 10 objects of the class we will have (1) (counter) variable which is shared at class level for all objects

    public:

        static int  counter;
        clsA()
        {
             counter++;
        }

        void    ft_set_var(int read_var)
        {
            _var = read_var;
        }

        void    ft_print()
        {
            printf("\n____________\nvar variable = %d\ncounter variable = %d\n\n", _var, counter);
        }

};


int clsA::counter = 0; //static variable initialisation outside the class - Because it is same as global variable but just for a class
// And its lifetime will be program lifetime


int main(void)
{
    clsA A1_cls;
    A1_cls.ft_set_var(3);
    A1_cls.ft_print();
    clsA A2_cls;
    A2_cls.ft_set_var(5);
    A2_cls.ft_print();
    A1_cls.ft_print();
    clsA A3_cls;
    A3_cls.ft_set_var(19);
    A3_cls.ft_print();
    A2_cls.ft_print();
    A1_cls.ft_print();
    clsA A4_cls;
    A4_cls.ft_set_var(100);
    A4_cls.ft_print();
    A3_cls.ft_print();
    A2_cls.ft_print();
    A1_cls.ft_print();

    cout << "\nafter chaning the static member counter in one object:\n";
    A1_cls.counter = 10000;
    A4_cls.ft_print();
    A3_cls.ft_print();
    A2_cls.ft_print();
    A1_cls.ft_print();



    return (0);
}