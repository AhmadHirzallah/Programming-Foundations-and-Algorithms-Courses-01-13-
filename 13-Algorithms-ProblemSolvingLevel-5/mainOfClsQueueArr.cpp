#include <iostream>
#include "DS/clsQueueArr.hpp"

// ft_read_printSeparator: prints a separator and test header
void ft_read_printSeparator(const char* testName)
{
    std::cout << "========================================\n";
    std::cout << "TEST: " << testName << "\n";
    std::cout << "========================================\n";
}

// Test function for push, size, front and back
void ft_read_testPushFrontBack()
{
    ft_read_printSeparator("push, size, front and back");

    clsQueueArr<int> queue;

    // Push some data into the queue using while loop iteration (simulate repetitive push)
    int counter = 0;
    while (counter < 5)
    {
        short result = queue.push(counter * 10);
        std::cout << "Pushed " << counter * 10 << " (result: " << result << ")\n";
        counter++;
    }

    // Check size
    std::cout << "Size of queue: " << queue.size() << "\n";
    // Check front and back values
    std::cout << "Front of queue: " << queue.front() << "\n";
    std::cout << "Back of queue: " << queue.back() << "\n";

    std::cout << "\nCurrent queue contents:\n";
    queue.Print();
    std::cout << "\n\n";
}

// Test function for pop
void ft_read_testPop()
{
    ft_read_printSeparator("pop");

    clsQueueArr<int> queue;
    // Insert elements
    int counter = 0;
    while (counter < 5)
    {
        queue.push((counter + 1) * 5);
        counter++;
    }

    std::cout << "Initial queue contents:\n";
    queue.Print();
    std::cout << "\n";

    // Pop one element and print the new front
    short popResult = queue.pop();
    std::cout << "Pop result: " << popResult << "\n";
    std::cout << "Queue after one pop:\n";
    queue.Print();
    std::cout << "\nNew front: " << queue.front() << "\n\n";
}

// Test function for isEmpty and Clear
void ft_read_testIsEmptyClear()
{
    ft_read_printSeparator("isEmpty and Clear");

    clsQueueArr<int> queue;

    std::cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << "\n";

    // Push some items
    int value = 100;
    int count = 0;
    while (count < 3)
    {
        queue.push(value + count);
        count++;
    }

    std::cout << "After pushing 3 items, is queue empty? " 
              << (queue.isEmpty() ? "Yes" : "No") << "\n";

    std::cout << "Queue before Clear:\n";
    queue.Print();
    std::cout << "\nClearing queue...\n";
    queue.Clear();
    std::cout << "Queue after Clear:\n";
    queue.Print();
    std::cout << "\nIs queue empty? " << (queue.isEmpty() ? "Yes" : "No") << "\n\n";
}

// Test function for GetItem and UpdateItem
void ft_read_testGetUpdateItem()
{
    ft_read_printSeparator("GetItem and UpdateItem");

    clsQueueArr<int> queue;

    // Push data
    int count = 0;
    while (count < 5)
    {
        queue.push((count + 1) * 3);
        count++;
    }

    std::cout << "Initial queue contents:\n";
    queue.Print();
    std::cout << "\n";

    // Get item at index 2
    int item = queue.GetItem(2);
    std::cout << "Item at index 2: " << item << "\n";

    // Update item at index 2
    short updateResult = queue.UpdateItem(2, 999);
    std::cout << "Update item at index 2 to 999 (result: " << updateResult << ")\n";

    std::cout << "Queue after update:\n";
    queue.Print();
    std::cout << "\n\n";
}

// Test function for InsertAfter and InsertAtFront
void ft_read_testInsertFunctions()
{
    ft_read_printSeparator("InsertAfter and InsertAtFront");

    clsQueueArr<int> queue;

    // Push initial items
    int count = 0;
    while (count < 4)
    {
        queue.push((count + 1) * 10);
        count++;
    }

    std::cout << "Initial queue contents:\n";
    queue.Print();
    std::cout << "\n";

    // Insert after index 1
    short insertAfterResult = queue.InsertAfter(1, 555);
    std::cout << "Insert 555 after index 1 (result: " << insertAfterResult << ")\n";

    std::cout << "Queue after InsertAfter:\n";
    queue.Print();
    std::cout << "\n";

    // Insert at front
    short insertAtFrontResult = queue.InsertAtFront(777);
    std::cout << "Insert 777 at front (result: " << insertAtFrontResult << ")\n";
    short insertAtBackResult = queue.InsertAtBack(100000);
    std::cout << "Insert 100000 at back (result: " << insertAtBackResult << ")\n";

    std::cout << "Queue after InsertAtFront & InsertAtBack:\n";
    queue.Print();
    std::cout << "\n\n";
}

// Test function for Reverse
void ft_read_testReverse()
{
    ft_read_printSeparator("Reverse");

    clsQueueArr<int> queue;

    // Push data
    int count = 0;
    while (count < 6)
    {
        queue.push((count + 1) * 2);
        count++;
    }

    std::cout << "Queue before Reverse:\n";
    queue.Print();
    std::cout << "\n";

    short reverseResult = queue.Reverse();
    std::cout << "Reverse result: " << reverseResult << "\n";

    std::cout << "Queue after Reverse:\n";
    queue.Print();
    std::cout << "\n\n";
}

// Main function: calls all test functions modularly.
int main()
{
    std::cout << "Starting tests for clsQueueArr...\n\n";

    // ft_read_testPushFrontBack();

    // ft_read_testPop();

    // ft_read_testIsEmptyClear();

    // ft_read_testGetUpdateItem();

    // ft_read_testInsertFunctions();

    ft_read_testReverse();

    std::cout << "All tests completed.\n";
    return 0;
}
