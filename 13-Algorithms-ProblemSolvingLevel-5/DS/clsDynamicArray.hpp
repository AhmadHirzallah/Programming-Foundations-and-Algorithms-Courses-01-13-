#pragma once

#ifndef CLSDYNAMICARRAY_HPP
# define CLSDYNAMICARRAY_HPP

template <class T>
class clsDynamicArray
{
protected:

        long    _size = 0;
        T   *_DynamicArr;
        T   *_TempDynmcArr;

        short   _isIndexOutOfRange(long index)
        {
            return ((index >= _size) || (index < 0));
        }

public:


        clsDynamicArray (long size = 0)
        {
            (this->_size) = ((size <= 0) ?    0 : size);
            _DynamicArr = new T[_size];

            /*
            if (size < 0)
                this->_size = 0
            else
                this->_size = size;
            */
        }


        ~clsDynamicArray()
        {
            delete[] _DynamicArr;
        }



        long    Size()
        {
            return (_size);
        }


        short   SetSize(long new_size)
        {
            _size = new_size;
            return (0);
        }


        short   isEmpty()
        {
            return (Size() == 0);
        }


        short   SetItem(long index, T data)
        {
            if (_isIndexOutOfRange(index))
                return (1);                 //  Out Failed Out of Range.
            if (!isEmpty())
                _DynamicArr[index] = data;

            return (0);
        }


        void    PrintArray()
        {
            for (long i = 0 ; i < Size() ; i++)
                std::cout << this->_DynamicArr[i] << "    ";

            std::cout << "\n\n";
        }


        short   Resize(long new_size)
        {
            if (new_size < 0)
                new_size = 0;

            _TempDynmcArr = new T[new_size];

            if (!_TempDynmcArr)
                return (1);

            SetSize(new_size);
            new_size = (new_size > Size()) ? Size() : new_size;
            
            for (long i = 0 ; i < new_size; i++)
                _TempDynmcArr[i] = _DynamicArr[i];

            delete[] _DynamicArr;
            _DynamicArr = _TempDynmcArr;

            return (0);
        }


        T   GetItem(long index)
        {
            return (_DynamicArr[index]);
        }


        short   Reverse()
        {
            if (!_DynamicArr || Size() <= 1)
                return (1);
            
            _TempDynmcArr = new T[Size()];
            if (!(_TempDynmcArr))
                return (2);

            for (long i = 0 ; i < Size() ; i++)
                _TempDynmcArr[i] = _DynamicArr[Size() - i - 1];
            
            delete[] _DynamicArr;
            _DynamicArr = _TempDynmcArr;

            return (0);
        }


        void   Clear()
        {
            if (_DynamicArr)
            {
                delete[] this->_DynamicArr;
                _DynamicArr = nullptr;
            }
            // _DynamicArr = new T[Size()];         // No need to reallocate an empty array.
            SetSize(0);
        }


        short   DeleteItemAt(long index)
        {
            if (_isIndexOutOfRange(index))
                return (1);

            try
            {
                _TempDynmcArr = new T[Size() - 1]; // Use exception handling for new
            } catch (const std::bad_alloc&)
            {
                return (2); // Handle allocation failure
            }

            long i = 0;
            while (i < index) 
            {
                _TempDynmcArr[i] = _DynamicArr[i];
                i++;
            }

            while (i < (Size() - 1))
            {
                _TempDynmcArr[i] = _DynamicArr[i + 1];
                i++;
            }

            /*
            for (long i = 0 ; i < index ; i++)
                _TempDynmcArr[i] = _DynamicArr[i];
            
            for (long i = index ;  i < (Size() - 1)  ; i++)
                _TempDynmcArr[i] = _DynamicArr[i + 1];
            */
            
            delete[] _DynamicArr;
            _DynamicArr = _TempDynmcArr;

            SetSize(Size() - 1);
            return (0);
        }


        short   DeleteFirstItem()
        {
            return (DeleteItemAt(0));
        }


        short   DeleteLastItem()
        {
            return (DeleteItemAt(Size() - 1));
        }


        long    Find(T Item)
        {
            for (long index = 0 ; index < Size() ; index++)
            {
                if (Item == this->_DynamicArr[index])
                    return (index);
            }

            return (-1);
        }



        short DeleteItem(T Item)
        {
            long index = Find(Item);

            if (index == -1)
                return (-1);

            return (DeleteItemAt(index));
        }


        short   InsertAt(long index, T Data)
        {
            if (_isIndexOutOfRange(index) && !(index == Size()))
                return (1);

            SetSize(Size() + 1);
            try
            {
                _TempDynmcArr = new T[Size()];
            }
            catch(const std::bad_alloc&)
            {
                return (2);
            }
            
            for (long i = 0; i < index ; i++)
                _TempDynmcArr[i] = _DynamicArr[i];

            _TempDynmcArr[index] = Data;

            for (long i = (index + 1) ; i < Size() ; i++)
                _TempDynmcArr[i] = _DynamicArr[i - 1];
            
            delete[] _DynamicArr;
            _DynamicArr = _TempDynmcArr;

            return (0);
        }


        short   InsertAtBegining(T Data)
        {
            return (InsertAt(0, Data));
        }

        
        short   InsertBefore(long index, T Data)
        {
            return (InsertAt((index - 1) , Data));
        }


        short   InsertAfter(long index, T Data)
        {
            return (InsertAt((index + 1) , Data));
        }


        short   InsertAtEnd(T Data)
        {
            return (InsertAt(Size(), Data));
        }





};

#endif