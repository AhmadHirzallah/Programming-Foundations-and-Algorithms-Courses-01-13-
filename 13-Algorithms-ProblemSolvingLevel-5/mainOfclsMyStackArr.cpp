#include <iostream>
#include "DS/clsStackArr.hpp"

// ft_read_printSeparator: Prints a clear header for each test.
void ft_read_printSeparator(const char* testName)
{
    std::cout << "========================================\n";
    std::cout << "TEST: " << testName << "\n";
    std::cout << "========================================\n";
}

// ft_read_EssentialTests: Tests the most fundamental operations of clsStackArr.
void ft_read_EssentialTests()
{
    ft_read_printSeparator("Essential Tests for clsStackArr");

    clsStackArr<int> myStack;

    // Push items into the stack using a while loop.
    int items[5] = {10, 20, 30, 40, 50};
    int i = 0;
    while (i < 5)
    {
        short result = myStack.push(items[i]);
        std::cout << "Pushed " << items[i] << " (result: " << result << ")\n";
        i = i + 1;
    }

    std::cout << "\nStack Before Pop:\n";
    myStack.Print();

    std::cout << "\nStack Size: " << myStack.size() << "\n";
    std::cout << "Stack Top (Front): " << myStack.top() << "\n";
    std::cout << "Stack Bottom (Back): " << myStack.bottom() << "\n";

    // Pop one element.
    short popResult = myStack.pop();
    std::cout << "\nPop result: " << popResult << "\n";
    std::cout << "\nStack After Popping:\n";
    myStack.Print();

    std::cout << "\n\n";
}

// ft_read_ExtensionsTests: Tests extended operations such as GetItem, Reverse, UpdateItem, and various insertions.
void ft_read_ExtensionsTests()
{
    ft_read_printSeparator("Extensions Tests for clsStackArr");

    clsStackArr<int> MyStack;

    // Push items 1 to 6 into the stack using a while loop.
    int value = 1;
    while (value <= 6)
    {
        short result = MyStack.push(value);
        std::cout << "Pushed " << value << " (result: " << result << ")\n";
        value = value + 1;
    }

    std::cout << "\nStack Before Operations:\n";
    MyStack.Print();
    std::cout << "\nStack Size: " << MyStack.size() << "\n";
    std::cout << "Stack Top: " << MyStack.top() << "\n";
    std::cout << "Stack Bottom: " << MyStack.bottom() << "\n";

    // Pop one element.
    short popResult = MyStack.pop();
    std::cout << "\nPop result: " << popResult << "\n";
    std::cout << "\nStack After Popping:\n";
    MyStack.Print();

    // Extension 1: GetItem tests.
    std::cout << "\nItem at index 2 is: " << MyStack.GetItem(2) << "\n";
    std::cout << "Item at index 4 is: " << MyStack.GetItem(4) << "\n";

    // Extension 2: Reverse the stack.
    short reverseResult = MyStack.Reverse();
    std::cout << "\nReverse result: " << reverseResult << "\n";
    std::cout << "\nStack After Reversing:\n";
    MyStack.Print();

    // Extension 3: Update items at indices 0 and 2.
    short updateResult1 = MyStack.UpdateItem(0, 11);
    short updateResult2 = MyStack.UpdateItem(2, 33);
    std::cout << "\nUpdate results: index 0 (" << updateResult1 << "), index 2 (" << updateResult2 << ")\n";
    std::cout << "\nStack After Updating items (indices 0 to 11 & 2 to 33):\n";
    MyStack.Print();

    // Extension 4: Insert after specified indices.
    short insertAfterResult1 = MyStack.InsertAfter(0, 111);
    short insertAfterResult2 = MyStack.InsertAfter(5, 222);
    std::cout << "\nInsertAfter results: after index 0 a 111 (" << insertAfterResult1 << "), after index 5 a 222 (" << insertAfterResult2 << ")\n";
    std::cout << "\nStack After Inserting items after indices 0 & 5:\n";
    MyStack.Print();

    // Extension 5: Insert at front and at top.
    short insertAtFrontResult = MyStack.InsertAtFront(101);
    short insertAtTopResult = MyStack.InsertAtTop(202);
    std::cout << "\nInsertAtFront result: " << insertAtFrontResult << ", InsertAtTop result: " << insertAtTopResult << "\n";
    std::cout << "\nStack After Inserting items at Front (Top):\n";
    MyStack.Print();
    std::cout << "Item at index 4 is: " << MyStack.GetItem(4) << "\n";

    // Extension 6: Insert at back and at bottom.
    short insertAtBackResult = MyStack.InsertAtBack(808);
    short insertAtBottomResult = MyStack.InsertAtBottom(909);
    std::cout << "\nInsertAtBack result: " << insertAtBackResult << ", InsertAtBottom result: " << insertAtBottomResult << "\n";
    std::cout << "\nStack After Inserting items at Back (Bottom):\n";
    MyStack.Print();
    std::cout << "Item at index 10 is: " << MyStack.GetItem(10) << "\n";

    // Extension 7: Clear the stack.
    MyStack.Clear();
    std::cout << "\nStack After Clearing all items:\n";
    MyStack.Print();

    std::cout << "\n\n";
}

// Main function: calls both the essential and extension test suites.
int main()
{
    std::cout << "Starting tests for clsStackArr...\n\n";

    // ft_read_EssentialTests();
    ft_read_ExtensionsTests();

    std::cout << "All tests completed.\n";
    return 0;
}
