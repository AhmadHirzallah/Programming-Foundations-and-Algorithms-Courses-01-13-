/*
    -   Destructor is opposite of constructure which means destruction (تدمير) عكس بناء

    -   When we call function from main and go to it; then back to main; the variables of the function will be destructed.

    -   When we have object (person of cls_person) and it is in memory and inside function call;
     then when we end the function call and get out of the scope of the main we will destroy (destructes) objects of classes also!

    -   So Objects and Variables will be destructed/destroyed in these cases; 
        -   When the object (of any class) is destroyed; this will be done through/using calling (Always at end method called in object)
            -   this method will destroy/destruct the object (of any class)
    
    -   We only can have (one destructor) inside the class and NO OVERLOADING and NO PARAMETERS or return PARAMETERS !
    -   We create an destructor using class name prefixed by (~ : Telda) like : (~clsPerson()) ; so this method will be called at end before the complete terminating of the object 
    -   You can benifit from destructors ; like to save data on files or database or closing an connection or destroying or releasing objects and more
    -   when you dynamically allocate memory for object like :
- void    ft_call_ptr_of_object()
{
    clsPerson *PtrPerson_cls = new clsPerson;
}
-No Destructor will be called or excecuted; because this is a dynamically allocated pointer on the run time ; 
- With pointers you have to manually by your hands delete it like : 
- void    ft_call_ptr_of_object_with_release_free_delete()
{
    clsPerson *PtrPerson_cls = new clsPerson;
    delete PtrPerson_cls;
}
and when we call the delete function of the pointer; the destructor will be called.
*/

/*
    Some Advantages of Destructor;
        1-  You need to save data on files or database or close a connection or destruct and release data variables and objects ;
        and do Anything you want; When you end of function and object of class will be killed.
*/

#include <iostream>

using namespace std;

class   clsPerson
{
    public:
        string  fullname;

        clsPerson()
        {
            printf("\n-----------------\nStart: Ahmad Hirzallah Constructor.\n");
            printf("Hi, I'm Constructor.\n");
        }
        /*
            Calling Destructor at the end of calling the class (After defining it!).

            It is written as (Telda (~) + Class Name (as clsPerson))

           Object of the Class سيتم مناداة هذه الميثود آخر شيء قبل ان يتم تدمير ال أوبجيكت 
        */  
        ~clsPerson()
        {
            printf("\nEnd: Ahmad Hirzallah Destructor.\n");
            printf("Hi, I'm Destructor\n\n");
        }
};

void    ft_call_random_object()
{
    clsPerson Ahmad;
}

void    ft_call_ptr_of_object()
{
    clsPerson *PtrPerson_cls = new clsPerson;
}

void    ft_call_ptr_of_object_with_release_free_delete()
{
    clsPerson *PtrPerson_cls = new clsPerson;
    delete PtrPerson_cls;
}

int main (void)
{

    /*
        This is memory allocated pointer; It is reserved/allocated dynamically;
         it will not be destructed automatically as random variables
        
        You need to handle releasing be deleting/freeing the allocated memory by your hands.
    */ 
    printf("1- Function call with random object:\n");
    ft_call_random_object();
    printf("\n\n\n2- Function call with ptr object without deleting/releasing:\n");
    ft_call_ptr_of_object();
    printf("\n\n\n3- Function call with ptr object with deleting/releasing:\n");
    ft_call_ptr_of_object_with_release_free_delete();

    return (0);
}
