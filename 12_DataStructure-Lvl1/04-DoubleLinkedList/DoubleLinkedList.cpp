#include <iostream>

class DoubleLinkedList
{

public:

        int value;
        DoubleLinkedList    *next;
        DoubleLinkedList    *prev;
};


int main ()
{
    system("clear");

    DoubleLinkedList    *Head;
    DoubleLinkedList    *Node1;
    DoubleLinkedList    *Node2;

    Head = new DoubleLinkedList();
    Node1 = new DoubleLinkedList();
    Node2 = new DoubleLinkedList();
    if (!Head || !Node1 || !Node2)
    {
        std::cout << "\nERROR 1\n";
        return 1;
    }

    (Head)->value = 1;
    (Node1)->value = 2;
    (Node2)->value = 3;

    (Head)->prev = nullptr;
    (Head)->next = Node1;
    
    (Node1)->prev = Head;
    (Node1)->next = Node2;

    (Node2)->prev = Node1;
    (Node2)->next = nullptr;

    DoubleLinkedList *Current = Head;

    while (Current)
    {
        std::cout << (Current)->value << "    ";
        Current = (Current)->next;
    }
    
    

    return 0;
}