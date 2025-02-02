#include <iostream>

# include "DS/clsDynamicArray.hpp"

int main (void)
{
    system("clear");


    clsDynamicArray <int> MyDynamicArr(5);

    std::cout << "Check is Dynamic Array Empty:\n";
    if (MyDynamicArr.isEmpty())
        std::cout << "Yes It is Empty.\n\n";
    else
        std::cout << "No It isn't Empty.\n\n";


    std::cout << "Checking the size of the Dynamic Array:  " << MyDynamicArr.Size() << "\n\n";
    

    MyDynamicArr.SetItem(0, 1);
    MyDynamicArr.SetItem(1, 2);
    MyDynamicArr.SetItem(2, 3);
    MyDynamicArr.SetItem(3, 4);
    MyDynamicArr.SetItem(4, 5);
    MyDynamicArr.PrintArray();

    std::cout << "Checking the size of the Dynamic Array:  " << MyDynamicArr.Size() << "\n\n";

    std::cout << "Item in index 2 is :  " << MyDynamicArr.GetItem(2) << "\n\n";

    std::cout << "Check is Dynamic Array (1) Empty:\n";
    if (MyDynamicArr.isEmpty())
        std::cout << "Yes It is Empty.\n\n";
    else
        std::cout << "No It isn't Empty.\n\n";
    


    clsDynamicArray <int> MyDynamicArr2(0);

    std::cout << "Check is Dynamic Array (2) Empty:\n";
    if (MyDynamicArr2.isEmpty())
        std::cout << "Yes It is Empty.\n\n";
    else
        std::cout << "No It isn't Empty.\n\n";



    std::cout << "------------------------\n\n";
    std::cout << "Array Resizing:\n\n";

    std::cout << "Array Before:\n";
    MyDynamicArr.PrintArray();
    std::cout << "(BEFORE): Checking the size of the Dynamic Array:  " << MyDynamicArr.Size() << "\n\n\n";

    MyDynamicArr.Resize(2);

    std::cout << "(AFTER Resizing To (2))::\n";
    MyDynamicArr.PrintArray();
    std::cout << "(AFTER Resizing To (2)): Checking the size of the Dynamic Array:  " << MyDynamicArr.Size() << "\n\n";

    MyDynamicArr.Resize(10);
    std::cout << "(AFTER Resizing To (10))::\n";
    MyDynamicArr.PrintArray();
    std::cout << "(AFTER Resizing To (10)): Checking the size of the Dynamic Array:  " << MyDynamicArr.Size() << "\n\n";


    clsDynamicArray <int> MyDynamicArr3(5);
    MyDynamicArr3.SetItem(0, 10);
    MyDynamicArr3.SetItem(1, 20);
    MyDynamicArr3.SetItem(2, 30);
    MyDynamicArr3.SetItem(3, 40);
    MyDynamicArr3.SetItem(4, 50);


    std::cout << "Dynamic Array:\n";
    MyDynamicArr3.PrintArray();
    std::cout << "Get Item of Index 2:   " <<  MyDynamicArr3.GetItem(2) << "\n\n";
    std::cout << "Get Item of Index 4:   " <<  MyDynamicArr3.GetItem(4) << "\n\n";


    std::cout << "------------------------\n\n";
    std::cout << "Array Reversing:\n\n";

    std::cout << "Before Reversing:\n";
    MyDynamicArr3.PrintArray();

    MyDynamicArr3.Reverse();

    std::cout << "\nAfter Reversing:\n";
    MyDynamicArr3.PrintArray();

    std::cout << "------------------------\n\n";
    std::cout << "Array Clearing:\n\n";
    std::cout << "Before Clearing:\n";
    MyDynamicArr3.PrintArray();

    MyDynamicArr3.Clear();

    std::cout << "After Clearing:\n";
    MyDynamicArr3.PrintArray();



    std::cout << "------------------------\n\n";

    clsDynamicArray <int> MyDynamicArr4(5);
    MyDynamicArr4.SetItem(0, 10);
    MyDynamicArr4.SetItem(1, 20);
    MyDynamicArr4.SetItem(2, 30);
    MyDynamicArr4.SetItem(3, 40);
    MyDynamicArr4.SetItem(4, 50);

    std::cout << "***** Array Before Deleting : *****\n";
    MyDynamicArr4.PrintArray();
    std::cout << "(Before Deleting): Checking the size of the Dynamic Array:  " << MyDynamicArr4.Size() << "\n\n";

    MyDynamicArr4.DeleteItemAt(2);

    std::cout << "***** Array After Deleting Item At (2): *****\n";
    MyDynamicArr4.PrintArray();
    std::cout << "(AFTER Deleting): Checking the size of the Dynamic Array:  " << MyDynamicArr4.Size() << "\n\n";

    MyDynamicArr4.DeleteItemAt(3);

    std::cout << "***** Array After Deleting Item At (3): *****\n";
    MyDynamicArr4.PrintArray();
    std::cout << "(AFTER Deleting): Checking the size of the Dynamic Array:  " << MyDynamicArr4.Size() << "\n\n";


    MyDynamicArr4.DeleteItemAt(0);

    std::cout << "***** Array After Deleting Item At (0): *****\n";
    MyDynamicArr4.PrintArray();
    std::cout << "(AFTER Deleting): Checking the size of the Dynamic Array:  " << MyDynamicArr4.Size() << "\n\n";



    std::cout << "------------------------\n\n";

    clsDynamicArray <int> DynamicArr5(5);
    DynamicArr5.SetItem(0, 10);
    DynamicArr5.SetItem(1, 20);
    DynamicArr5.SetItem(2, 30);
    DynamicArr5.SetItem(3, 40);
    DynamicArr5.SetItem(4, 50);

    std::cout << "***** Array Before Deleting : *****\n";
    DynamicArr5.PrintArray();
    std::cout << "(Before Deleting): Checking the size of the Dynamic Array:  " << DynamicArr5.Size() << "\n\n";

    DynamicArr5.DeleteFirstItem();

    std::cout << "***** Array After Deleting First Item: *****\n";
    DynamicArr5.PrintArray();
    std::cout << "(AFTER Deleting): Checking the size of the Dynamic Array:  " << DynamicArr5.Size() << "\n\n";

    DynamicArr5.DeleteLastItem();

    std::cout << "***** Array After Deleting Last Item: *****\n";
    DynamicArr5.PrintArray();
    std::cout << "(AFTER Deleting): Checking the size of the Dynamic Array:  " << DynamicArr5.Size() << "\n\n";

    DynamicArr5.DeleteFirstItem();
    DynamicArr5.DeleteLastItem();

    std::cout << "***** Array After Deleting First & Last Items: *****\n";
    DynamicArr5.PrintArray();
    std::cout << "(AFTER Deleting): Checking the size of the Dynamic Array:  " << DynamicArr5.Size() << "\n\n";


    std::cout << "\n\n------------------------\n\n\n\n";

    clsDynamicArray <int> DynamicArr6(5);
    DynamicArr6.SetItem(0, 10);
    DynamicArr6.SetItem(1, 20);
    DynamicArr6.SetItem(2, 30);
    DynamicArr6.SetItem(3, 40);
    DynamicArr6.SetItem(4, 50);

    std::cout << "***** Array Before: *****\n";
    DynamicArr6.PrintArray();

    std::cout << "Finding Number ((30)) --->>> (Getting Its Index):::\n\n";
    
    long index = DynamicArr6.Find(30);
    if (index == -1)
        std::cout << "Item ISNOT Found!!!\n\n";
    else
        std::cout << "Item IS Found at index ::   " <<  index << "\n\n";




    std::cout << "***** Array Before: *****\n";
    DynamicArr6.PrintArray();
    std::cout << "(Before Deleting): Checking the size of the Dynamic Array:  " << DynamicArr6.Size() << "\n\n";


    DynamicArr6.DeleteItem(30);
    std::cout << "***** Array After Deleting Specific Item (30): *****\n";
    DynamicArr6.PrintArray();
    std::cout << "(AFTER Deleting): Checking the size of the Dynamic Array:  " << DynamicArr6.Size() << "\n\n";

    DynamicArr6.DeleteItem(20);
    DynamicArr6.DeleteItem(50);

    std::cout << "***** Array After Deleting Elements (20 & 50) Item: *****\n";
    DynamicArr6.PrintArray();
    std::cout << "(AFTER Deleting): Checking the size of the Dynamic Array:  " << DynamicArr6.Size() << "\n\n";


    std::cout << "\n\n------------------------\n\n\n\n";

    clsDynamicArray <int> DynamicArr7(5);
    DynamicArr7.SetItem(0, 10);
    DynamicArr7.SetItem(1, 20);
    DynamicArr7.SetItem(2, 30);
    DynamicArr7.SetItem(3, 40);
    DynamicArr7.SetItem(4, 50);

    std::cout << "***** Array Before: *****\n";
    DynamicArr7.PrintArray();
    std::cout << "(Before Inserting): Checking the size of the Dynamic Array:  " << DynamicArr7.Size() << "\n\n";


    std::cout << "\n***** Array After Inserting (500) @ At Index (2): *****\n";
    DynamicArr7.InsertAt(2, 500);
    DynamicArr7.PrintArray();
    std::cout << "(After Inserting): Checking the size of the Dynamic Array:  " << DynamicArr7.Size() << "\n\n";


    std::cout << "\n***** Array After Inserting (100) @ At Index (1): *****\n";
    DynamicArr7.InsertAt(1, 100);
    DynamicArr7.PrintArray();
    std::cout << "(After Inserting): Checking the size of the Dynamic Array:  " << DynamicArr7.Size() << "\n\n";


    std::cout << "\n***** Array After Inserting (1000) @ At Index (6): *****\n";
    DynamicArr7.InsertAt(6, 1000);
    DynamicArr7.PrintArray();
    std::cout << "(After Inserting): Checking the size of the Dynamic Array:  " << DynamicArr7.Size() << "\n\n";



    std::cout << "\n***** Array After Inserting (8000) @ At Index (8): *****\n";
    if (!(DynamicArr7.InsertAt(8, 8000)))
    {
        DynamicArr7.PrintArray();
        std::cout << "(After Inserting): Checking the size of the Dynamic Array:  " << DynamicArr7.Size() << "\n\n";
    }
    else
        std::cout << "FAILED !!!!\n\n";






    std::cout << "\n\n------------------------\n\n\n\n";

    clsDynamicArray <int> DynamicArr8(5);
    DynamicArr8.SetItem(0, 10);
    DynamicArr8.SetItem(1, 20);
    DynamicArr8.SetItem(2, 30);
    DynamicArr8.SetItem(3, 40);
    DynamicArr8.SetItem(4, 50);

    
    std::cout << "***** Array Before: *****\n";
    DynamicArr8.PrintArray();
    std::cout << "(Before Inserting): Checking the size of the Dynamic Array:  " << DynamicArr8.Size() << "\n\n";


    std::cout << "\n***** Array After Inserting (0) @ At Begining of the Array: *****\n";
    DynamicArr8.InsertAtBegining(0);
    DynamicArr8.PrintArray();
    std::cout << "(After Inserting): Checking the size of the Dynamic Array:  " << DynamicArr8.Size() << "\n\n";


    std::cout << "\n\n***** Array After Inserting (111) @ At Begining of the Array: *****\n";
    DynamicArr8.InsertAtBegining(111);
    DynamicArr8.PrintArray();
    index = DynamicArr8.Find(111);
    std::cout << "111 IS Found at index ::   " <<  index << "\n\n";
    std::cout << "(After Inserting): Checking the size of the Dynamic Array:  " << DynamicArr8.Size() << "\n\n";


    std::cout << "\n\n***** Array After Inserting (500) Before Index (2): *****\n";
    DynamicArr8.InsertBefore(2, 500);
    DynamicArr8.PrintArray();
    index = DynamicArr8.Find(500);
    std::cout << "500 IS Found at index ::   " <<  index << "\n\n";
    std::cout << "(After Inserting): Checking the size of the Dynamic Array:  " << DynamicArr8.Size() << "\n\n";


    std::cout << "\n\n***** Array After Inserting (600) After Index (2): *****\n";
    DynamicArr8.InsertAfter(2, 600);
    DynamicArr8.PrintArray();
    index = DynamicArr8.Find(600);
    std::cout << "600 IS Found at index ::   " <<  index << "\n\n";
    std::cout << "(After Inserting): Checking the size of the Dynamic Array:  " << DynamicArr8.Size() << "\n\n";


    std::cout << "\n\n***** Array After Inserting (100000) At End : *****\n";
    DynamicArr8.InsertAtEnd(100000);
    DynamicArr8.PrintArray();
    index = DynamicArr8.Find(100000);
    std::cout << "100000 IS Found at index ::   " <<  index << "\n\n";
    std::cout << "(After Inserting): Checking the size of the Dynamic Array:  " << DynamicArr8.Size() << "\n\n";





    return (0);
}