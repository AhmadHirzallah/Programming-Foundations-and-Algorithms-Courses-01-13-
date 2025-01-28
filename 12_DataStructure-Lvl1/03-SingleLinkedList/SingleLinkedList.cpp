#include <iostream>

class SingleLinkedList
{
private:
    /* data */

public:

    int data;
    SingleLinkedList *next;
};



int main()
{
    system("clear");



    SingleLinkedList    *Node1;
    SingleLinkedList    *Node2;
    SingleLinkedList    *Node3;

    Node1 = new SingleLinkedList();
    Node2 = new SingleLinkedList();
    Node3 = new SingleLinkedList();

    Node1->data = 1;
    Node2->data = 2;
    Node3->data = 3;

    Node1->next = Node2;
    Node2->next = Node3;
    Node3->next = nullptr;

    std::cout << "Printing Linked List Elemenets:   ";
    
    SingleLinkedList *Head = Node1;

    while(Head)     // Head != NULL is same
    {
        std::cout << Head->data << "  " ; 
        Head = Head->next;
    }
    std::cout << "\n\n\n";

    return (0);    
}