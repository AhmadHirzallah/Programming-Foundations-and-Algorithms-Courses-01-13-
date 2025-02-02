#pragma once
# ifndef CLSSTACK_HPP
# define CLSSTACK_HPP

# include "clsDoublyLinkedList.hpp"

template <class T>
class clsStack
{

private:

clsDoublyLinkedList <T>     _DoublyLinkedList;

public:

        short   push(T pushed_data)
        {  

            if (!(_DoublyLinkedList.insertAtBegining(pushed_data)))
                return (0);
            return (1);
        }


        long    size()
        {
            return (_DoublyLinkedList.Size());
        }


        T   top()
        {
            return (_DoublyLinkedList.GetItem(0));
        }


        T   bottom()
        {
            return (_DoublyLinkedList.GetItem(size() - 1));
        }


        short   pop()
        {
            if (!(_DoublyLinkedList.deleteFirstNode()));
                return 0;   // Succeed
            return 1;
        }


        void    Print()
        {
            _DoublyLinkedList.Print();
        }


        short   isEmpty()
        {
            return (_DoublyLinkedList.isEmpty());
        }


        T   GetItem(long index)
        {
            return (_DoublyLinkedList.GetItem(index));
        }


        short   Reverse()
        {
            if(!(_DoublyLinkedList.Reverse()))
                return (0);
            return (1);
        }


        short   UpdateItem(long index, T new_data)
        {
            if (!(_DoublyLinkedList.UpdateItem(index, new_data)))
                return (0);
            return (1);
        }


        short   InsertAfter(long index, T new_data)
        {
            if (!(_DoublyLinkedList.insertAfterIndex(index, new_data)))
                return (0);
            return (1);
        }


        short   InsertAtTop(T insert_val)
        {
            return (push(insert_val));
            /*    // if (!(_DoublyLinkedList.insertAtBegining(insert_val)))
            //     return (0);
            // return (1);  */
        }


        short   InsertAtFront(T insert_val)
        {
            return (push(insert_val));
            // return (InsertAtTop(insert_val));
        }


        short   InsertAtBottom(T insert_val)
        {
            if (!(_DoublyLinkedList.insertAtEnd(insert_val)))
                return (0);
            return (1);
        }


        short   InsertAtBack(T insert_val)
        {
            return (InsertAtBottom(insert_val));
        }


        short   Clear()
        {
            return (_DoublyLinkedList.Clear());
        }

};

#endif