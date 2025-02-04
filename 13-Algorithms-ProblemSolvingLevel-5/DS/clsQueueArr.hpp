#pragma once

#ifndef CLSQUEUEARR_HPP
# define CLSQUEUEARR_HPP

#include <iostream>
# include "clsDynamicArray.hpp"






template <class T>
class clsQueueArr
{
protected:

           clsDynamicArray <T>  DynamicArr;




public:

            short   push(T new_data)
            {
                return (DynamicArr.InsertAtEnd(new_data));
            }


            long    size()
            {
                return (DynamicArr.Size());
            }


            T   front()
            {
                return (DynamicArr.GetItem(0));
            }


            T   back()
            {
                return (DynamicArr.GetItem(DynamicArr.Size() - 1));
            }


            short   pop()
            {
                return (DynamicArr.DeleteFirstItem());
            }


            void    Print()
            {
                DynamicArr.Print();
            }
            

            short   isEmpty()
            {
                return (DynamicArr.isEmpty());
            }


            T   GetItem(long index)
            {
                return (DynamicArr.GetItem(index));
            }


            short   Reverse()
            {
                return (DynamicArr.Reverse());
            }


            short   UpdateItem(long index, T new_data)
            {
                return (DynamicArr.SetItem(index, new_data));
            }


            short   InsertAfter(long index, T new_data)
            {
                return (DynamicArr.InsertAfter(index, new_data));
            }


            short   InsertAtFront(T Data)
            {
                return (DynamicArr.InsertAtBegining(Data));
            }


            short   InsertAtBack(T Data)
            {
                return (push(Data));
            }


            void   Clear()
            {
                DynamicArr.Clear();
            }





};

#endif