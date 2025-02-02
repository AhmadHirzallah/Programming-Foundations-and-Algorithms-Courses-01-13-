#pragma once

#ifndef CLSQUEUE_HPP 
# define CLSQUEUE_HPP 

#include <iostream>
# include "clsDoublyLinkedList.hpp"

template <class T>
class clsQueue
{
protected:

            clsDoublyLinkedList <T>     _DoubleLinkedList;

public:

            short   push(T new_data)
            {
                _DoubleLinkedList.insertAtEnd(new_data);
                return 0;
            }


            long    size()
            {
                return (_DoubleLinkedList.Size());
            }


            T   front()
            {
                return (_DoubleLinkedList.GetItem(0));
            }


            T   back()
            {
                return (_DoubleLinkedList.GetItem(size() - 1));
            }


            short   pop()
            {
                return (_DoubleLinkedList.deleteFirstNode());

                /*if (!(_DoubleLinkedList.deleteFirstNode()));
                    return 0;   // Succeed
                return 1;*/
            }


            void    Print()
            {
                _DoubleLinkedList.Print();
            }
            

            short   isEmpty()
            {
                return (_DoubleLinkedList.isEmpty());
            }


            T   GetItem(long index)
            {
                return (_DoubleLinkedList.GetItem(index));
            }


            short   Reverse()
            {
                return (_DoubleLinkedList.Reverse());

                /*// if (!(_DoubleLinkedList.Reverse()))
                //     return (0);   // Succeed 
                // return (1);*/
            }


            short   UpdateItem(long index, T new_data)
            {
             //                  !!! This (return (...)) is 100% equal the below lines ( Better  also :) ) !!!
                // return (_DoubleLinkedList.UpdateItem(index, new_data));

                if (!(_DoubleLinkedList.UpdateItem(index, new_data)))
                    return (0);     // Succeed 
                return (1);
            }


            short   InsertAfter(long index, T new_data)
            {
                return (_DoubleLinkedList.insertAfterIndex(index, new_data));

                // if (!(_DoubleLinkedList.insertAfterIndex(index, new_data)))
                //     return (0);
                // return (1);
            }


            short   InsertAtFront(T Data)
            {
                return (_DoubleLinkedList.insertAtBegining(Data));

                // if (!(_DoubleLinkedList.insertAtBegining(Data)))
                //     return (0);    // Succeed 
                // return (1);
            }


            short   InsertAtBack(T Data)
            {
                return (push(Data));

                // return (_DoubleLinkedList.insertAtEnd(Data));

                // if (!(_DoubleLinkedList.insertAtEnd(Data)))
                //     return (0);    // Succeed 
                // return (1);
            }


            short   Clear()
            {
                _DoubleLinkedList.Clear();
                return 0;
            }





};

#endif