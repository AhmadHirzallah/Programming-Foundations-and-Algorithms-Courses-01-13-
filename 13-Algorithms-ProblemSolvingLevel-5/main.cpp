#include <iostream>

# include "DS/clsDoublyLinkedList.hpp"

int main ()
{
    system("clear");




    clsDoublyLinkedList <int> MyDblLinkedList;

    MyDblLinkedList.insertAtBegining(10);
    MyDblLinkedList.insertAtBegining(15);
    MyDblLinkedList.printListDetails();
    MyDblLinkedList.printList();






    clsDoublyLinkedList<int>::Node     *Node1 = MyDblLinkedList.FindNode(10);
    std::cout << "\nis 10 exist\n" << std::endl;
    MyDblLinkedList.insertAfter(Node1, 20);
    MyDblLinkedList.printList();





    std::cout << "\nis 10 exist\n" << std::endl;
    if(MyDblLinkedList.isNodeExist(10))
        std::cout << "Yes\n\n" << std::endl;
    else
        std::cout << "No\n\n" << std::endl;



    std::cout << "is 90 exist\n" << std::endl;
    if(MyDblLinkedList.isNodeExist(90))
        std::cout << "Yes\n\n" << std::endl;
    else
        std::cout << "No\n\n" << std::endl;

    





    std::cout << "\nInsert Before\n" << std::endl;
    std::cout << "\nBefore Insert Before :\n" << std::endl;
    MyDblLinkedList.printList();

    std::cout << "\nAfter Insert Before 10 a 100 :" << std::endl;
    Node1 = MyDblLinkedList.FindNode(10);
    MyDblLinkedList.insertBefore(Node1, 100);
    MyDblLinkedList.printList();

    
    std::cout << "\nInsert At End:" << std::endl;
    MyDblLinkedList.insertAtEnd(9999999);
    MyDblLinkedList.printList();
    MyDblLinkedList.printListDetails();





    std::cout << "\nDelete First Node :" << std::endl;
    MyDblLinkedList.deleteFirstNode();
    MyDblLinkedList.printList();
    MyDblLinkedList.printListDetails();





    std::cout << "\nDelete Specific Node :" << std::endl;
    Node1 = MyDblLinkedList.FindNode(20);
    MyDblLinkedList.deleteNode(Node1);
    MyDblLinkedList.printList();
    MyDblLinkedList.printListDetails();




    std::cout << "\nDelete Specific Node :" << std::endl;
    Node1 = MyDblLinkedList.FindNode(100);
    MyDblLinkedList.deleteNode(Node1);
    MyDblLinkedList.printList();
    MyDblLinkedList.printListDetails();




    std::cout << "\nDelete Last Node :" << std::endl;
    MyDblLinkedList.deleteLastNode();
    MyDblLinkedList.printList();
    MyDblLinkedList.printListDetails();



    return 0;
}