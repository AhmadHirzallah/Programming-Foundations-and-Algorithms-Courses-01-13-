#include <iostream>
#include "StringHistory.hpp"

// ft_read_printSeparator: Prints a clear header for each test.
void ft_read_printSeparator(const char* testName)
{
    std::cout << "\n========================================\n";
    std::cout << "TEST: " << testName << "\n";
    std::cout << "========================================\n";
}

// ft_read_EssentialTests: Tests basic SetValue and GetValue functionality.
void ft_read_EssentialTests()
{
    ft_read_printSeparator("Essential Tests: SetValue and GetValue");

    // Create a StringHistory object with an initial value.
    StringHistory history("Initial");
    std::cout << "Initial Value: " << history.GetValue() << "\n";

    // Change the value a few times.
    const char* newValues[] = {"First Change", "Second Change", "Third Change"};
    int i = 0;
    int n = 3; // number of changes
    while (i < n)
    {
        std::cout << "\nSetting Value to: " << newValues[i] << "\n";
        history.SetValue(newValues[i]);
        std::cout << "Current Value: " << history.GetValue() << "\n";
        i = i + 1;
    }
}

// ft_read_UndoRedoTests: Tests the Undo and Redo functionality.
void ft_read_UndoRedoTests()
{
    ft_read_printSeparator("Undo and Redo Tests");

    // Create a StringHistory object with an initial value.
    StringHistory history("Start");

    std::cout << "Value At Start : " << history.GetValue() << "\n\n";
    // Change the value several times.
    const char* changes[] = {"One", "Two", "Three", "Four"};
    int i = 0;
    int n = 4;
    while (i < n)
    {
        if (i == 0)
            std::cout << "\nStarting value From: " << changes[i] << "\n";
        else
            std::cout << "\nChanging value to: " << changes[i] << "\n";

        history.SetValue(changes[i]);
        std::cout << "Value now: " << history.GetValue() << "\n";
        i++;
    }

    // Undo changes one by one.
    std::cout << "\nPerforming Undo operations:\n";
    i = 0;
    // We'll perform three undo operations.
    while (i < 4)
    {
        history.Undo();
        std::cout << "After Undo " << i + 1 << ": " << history.GetValue() << "\n";
        i = i + 1;
    }

    std::cout << "\n\n\nLast Value After 4 Undos "  << ": " << history.GetValue() << "\n\n";

    // Redo changes one by one.
    std::cout << "\nPerforming Redo operations:\n";
    i = 0;
    // We'll perform two redo operations.
    while (i < 3)
    {
        history.Redo();
        std::cout << "After Redo " << i + 1 << ": " << history.GetValue() << "\n";
        i = i + 1;
    }

    std::cout << "\n\n\nLast Value After 3 Redos "  << ": " << history.GetValue() << "\n\n";
}

int main()
{
    std::cout << "Starting tests for StringHistory...\n";

    // Run Essential Tests.
    ft_read_EssentialTests();

    // Run Undo/Redo Tests.
    ft_read_UndoRedoTests();

    std::cout << "\nAll tests completed.\n";
    return 0;
}
