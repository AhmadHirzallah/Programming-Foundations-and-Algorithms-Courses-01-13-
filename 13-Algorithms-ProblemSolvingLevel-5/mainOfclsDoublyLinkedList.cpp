#include <iostream>

# include "DS/clsDoublyLinkedList.hpp"

void    essentialsTest()
{
    clsDoublyLinkedList <int> MyDblLinkedList;

    MyDblLinkedList.insertAtBegining(10);
    MyDblLinkedList.insertAtBegining(15);
    MyDblLinkedList.printListDetails();
    MyDblLinkedList.printList();






    clsDoublyLinkedList<int>::Node     *Node1 = MyDblLinkedList.FindNode(10);
    std::cout << "\nis 10 exist\n" << std::endl;
    MyDblLinkedList.insertAfterNode(Node1, 20);
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


}


void    sizeTests()
{
    clsDoublyLinkedList <double> MyDblyLinkedList;

    MyDblyLinkedList.insertAtBegining(12.5);
    MyDblyLinkedList.printList();
    std::cout << "The size of the Doubly Linked List is:  " << MyDblyLinkedList.Size() << "\n\n";

    MyDblyLinkedList.insertAtEnd(11);
    MyDblyLinkedList.insertAtEnd(22);
    MyDblyLinkedList.insertAtEnd(33);
    MyDblyLinkedList.insertAtEnd(44);
    MyDblyLinkedList.printList();
    std::cout << "The size of the Doubly Linked List is:  " << MyDblyLinkedList.Size() << "\n\n";


    clsDoublyLinkedList <double>::Node  *FindedNode = MyDblyLinkedList.FindNode(11);

    MyDblyLinkedList.insertAfterNode(FindedNode, 15);
    MyDblyLinkedList.printList();
    std::cout << "The size of the Doubly Linked List is:  " << MyDblyLinkedList.Size() << "\n\n";

    FindedNode = MyDblyLinkedList.FindNode(12.5);
    MyDblyLinkedList.insertBefore(FindedNode, 6.25);
    FindedNode = MyDblyLinkedList.FindNode(15);
    MyDblyLinkedList.insertBefore(FindedNode, 14.87);
    MyDblyLinkedList.printList();
    std::cout << "The size of the Doubly Linked List is:  " << MyDblyLinkedList.Size() << "\n\n";


    MyDblyLinkedList.deleteFirstNode();
    MyDblyLinkedList.deleteFirstNode();
    MyDblyLinkedList.printList();
    std::cout << "The size of the Doubly Linked List is:  " << MyDblyLinkedList.Size() << "\n\n";



    MyDblyLinkedList.deleteLastNode();
    MyDblyLinkedList.deleteLastNode();
    MyDblyLinkedList.printList();
    std::cout << "The size of the Doubly Linked List is:  " << MyDblyLinkedList.Size() << "\n\n";


    FindedNode = MyDblyLinkedList.FindNode(14.87);
    MyDblyLinkedList.deleteNode(FindedNode);
    MyDblyLinkedList.printList();
    std::cout << "The size of the Doubly Linked List is:  " << MyDblyLinkedList.Size() << "\n\n";

    FindedNode = MyDblyLinkedList.FindNode(15);
    MyDblyLinkedList.deleteNode(FindedNode);
    FindedNode = MyDblyLinkedList.FindNode(11);
    MyDblyLinkedList.deleteNode(FindedNode);
    MyDblyLinkedList.printList();
    std::cout << "The size of the Doubly Linked List is:  " << MyDblyLinkedList.Size() << "\n\n";


    FindedNode = MyDblyLinkedList.FindNode(22);
    MyDblyLinkedList.deleteNode(FindedNode);
    MyDblyLinkedList.printList();
    std::cout << "The size of the Doubly Linked List is:  " << MyDblyLinkedList.Size() << "\n\n";
}


void    isEmptyTests()
{
    clsDoublyLinkedList <std::string> MyDbly;

    if(MyDbly.isEmpty())
        std::cout << "\n((The Linked List is Empty.)) :( :(\n\n";
    else 
        std::cout << "\n((The Linked List ISN'T Empty.)) :) :)\n\n";

    MyDbly.insertAtBegining("Ahmad");
    MyDbly.insertAtBegining("Ali");
    MyDbly.insertAtBegining("Mahmoud");
    MyDbly.printList();
    std::cout << "The size of the Doubly Linked List is:  " << MyDbly.Size() << "\n\n";
    if(MyDbly.isEmpty())
        std::cout << "\n((The Linked List is Empty.)) :( :(\n\n";
    else 
        std::cout << "\n((The Linked List ISN'T Empty.)) :) :)\n\n";


    MyDbly.deleteFirstNode();
    MyDbly.deleteFirstNode();
    MyDbly.deleteFirstNode();

    MyDbly.printList();
    std::cout << "The size of the Doubly Linked List is:  " << MyDbly.Size() << "\n\n";
    if(MyDbly.isEmpty())
        std::cout << "\n((The Linked List is Empty.)) :( :(\n\n";
    else 
        std::cout << "\n((The Linked List ISN'T Empty.)) :) :)\n\n";

    return;
}


void    clearTests()
{
    clsDoublyLinkedList <float> Dbly;
    Dbly.insertAtBegining(10);
    Dbly.insertAtBegining(11.1);
    Dbly.insertAtBegining(15.6);
    Dbly.insertAtBegining(19.99);
    Dbly.insertAtEnd(99);
    std::cout << "The size of the Doubly Linked List is:  " << Dbly.Size() << "\n\n";
    if(Dbly.isEmpty())
        std::cout << "\n((The Linked List is Empty.)) :( :(\n\n";
    else 
        std::cout << "\n((The Linked List ISN'T Empty.)) :) :)\n\n";
    

    std::cout << "\nPerforming Clear on Linked List:  \n\n";
    Dbly.Clear();
    std::cout << "The size of the Doubly Linked List is:  " << Dbly.Size() << "\n\n";
    if(Dbly.isEmpty())
        std::cout << "\n((The Linked List is Empty.)) :( :(\n\n";
    else 
        std::cout << "\n((The Linked List ISN'T Empty.)) :) :)\n\n";
}


void    reverseTests()
{
    clsDoublyLinkedList <int> Dbly;
    Dbly.insertAtBegining(1);
    Dbly.insertAtEnd(20);
    Dbly.insertAtEnd(30);
    Dbly.insertAtEnd(40);
    std::cout << "Printing Before Reversing:";
    Dbly.printList();

    std::cout << "\n\nPrinting After Reversing:";
    Dbly.Reverse();
    Dbly.printList();
}


void    GetNodeTests()
{
    clsDoublyLinkedList <int> Dbly;

    Dbly.insertAtEnd(1);
    Dbly.insertAtEnd(2);
    Dbly.insertAtEnd(3);
    Dbly.insertAtEnd(4);
    Dbly.printList();

    int index = 0;
    clsDoublyLinkedList <int>::Node *ANode;
    if (ANode = Dbly.GetNode(index))
        std::cout<<"\n\nThe Node at the index: " << index << "  is:   " << ANode->data;
    else
        std::cout<<"(No Node; Error Happend)";

    index = 2;
    if (ANode = Dbly.GetNode(index))
        std::cout<<"\n\nThe Node at the index: " << index << "  is:   " << ANode->data;
    else
        std::cout<<"(No Node; Error Happend)";

    index = 3;
    if (ANode = Dbly.GetNode(index))
        std::cout<<"\n\nThe Node at the index: " << index << "  is:   " << ANode->data;
    else
        std::cout<<"(No Node; Error Happend)";

    index = 5;
    if (ANode = Dbly.GetNode(index))
        std::cout<<"\n\nThe Node at the index: " << index << "  is:   " << ANode->data;
    else
        std::cout<<"\n\n(No Node; Error Happend)";


    index = -1;
    if (ANode = Dbly.GetNode(index))
        std::cout<<"\n\nThe Node at the index: " << index << "  is:   " << ANode->data;
    else
        std::cout<<"\n\n(No Node; Error Happend)";

    std::cout<<"\n\n";
}


void    GetItemTests()
{
    clsDoublyLinkedList <int> Dbly;
    int index;

    Dbly.insertAtEnd(1);
    Dbly.insertAtEnd(2);
    Dbly.insertAtEnd(3);
    Dbly.insertAtEnd(4);
    Dbly.printList();
    
    index = 0;
    printf("The Data of the Index (%i) is (%i)\n\n", index, Dbly.GetItem(index));
    index = 2;
    printf("The Data of the Index (%i) is (%i)\n\n", index, Dbly.GetItem(index));
    index = 3;
    printf("The Data of the Index (%i) is (%i)\n\n", index, Dbly.GetItem(index));
    index = 5;
    printf("The Data of the Index (%i) is (%i)\n\n", index, Dbly.GetItem(index));
    index = -1;
    printf("The Data of the Index (%i) is (%i)\n\n", index, Dbly.GetItem(index));
    
}


void    UpdateItemTests()
{
    clsDoublyLinkedList <std::string> Dbly;

    Dbly.insertAtEnd("Ahmad");
    Dbly.insertAtEnd("Basim");
    Dbly.insertAtEnd("Chagi");
    Dbly.insertAtEnd("Diab");
    Dbly.insertAtEnd("Eyad");
    Dbly.printList();

    Dbly.UpdateItem(0, "Ahmad Omar Hirzallah");
    Dbly.printList();

    Dbly.UpdateItem(4, "Eyad Majdi");
    Dbly.printList();

    Dbly.UpdateItem(2, "Chagi Next HaHa");
    Dbly.printList();
}


void    insertAfterUsingIndex()
{
    clsDoublyLinkedList <std::string> Dbly;

    Dbly.insertAtBegining("Ahmad");
    Dbly.insertAtEnd("Bassim");
    Dbly.insertAtEnd("Cacaroto");
    Dbly.insertAtEnd("Diab");
    Dbly.insertAtEnd("Eyad");
    Dbly.printList();

    Dbly.insertAfterIndex(0, "Ahmad Brother");
    Dbly.printList();

    Dbly.insertAfterIndex(2, "I am Middle HAHA");
    Dbly.printList();

    Dbly.insertAfterIndex(6, "I am Last HAHA");
    Dbly.printList();
}

int main ()
{
    system("clear");

    // essentialsTest();

    // sizeTests();

    // isEmptyTests();

    // clearTests();

    // reverseTests();

    // GetNodeTests();

    // GetItemTests();

    // UpdateItemTests();
    
    insertAfterUsingIndex();

    



    return 0;
}