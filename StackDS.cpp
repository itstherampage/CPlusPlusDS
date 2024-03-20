#include <iostream>
#include <string>

/**************************************************************
 *                       Stack Data Structure                   *
 * Question: What is a stack data structure?                    *
 * Answer: A stack is a linear data structure that operates on  *
 *         a Last In First Out (LIFO) basis.                    *
 * Additional Information:                                     *
 *   - Elements are added onto the stack using the PUSH        *
 *     operation.                                              *
 *   - Items are removed from the top of the stack using the   *
 *     POP operation.                                          *
 * Youtube Title: What is Stack Data Structure? | Data Structure and Algorithms (DSA) | Part - 1
 * Author: Simple Snippets                                     *
 **************************************************************/

class Stack
{
private:
    struct Node
    {
        int data;
        Node *prev;
    };
    Node *topNode;
    int size = 0;

public:
    Stack() : topNode(nullptr) {}

    void push(int value)
    {
        // Allocate memory for a new node
        Node *newNode = new Node;

        // Set the data of the new node to the value passed as an argument
        newNode->data = value;

        // Link the new node to the rest of the list by pointing its next pointer to the current top node
        newNode->prev = topNode;

        // Update the topNode pointer to make the new node the top node of the stack
        topNode = newNode;
        size++;
    }

    void pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty. There is no top element.\n";
            return;
        }
        // Store the address of the top node in a temporary variable
        Node *temp = topNode;

        // Update the topNode pointer to point to the previous node
        topNode = topNode->prev;
        delete temp;
        size--;
    }

    int getSize()
    {
        return this->size;
    }

    int top() const
    {
        if (isEmpty())
        {
            throw std::out_of_range("Stack is empty. There is no top element.");
        }
        return topNode->data;
    }

    bool isEmpty() const
    {
        return topNode == nullptr;
    }
};

int main(int argc, char const *argv[])
{
    try
    {
        Stack myStack;

        myStack.push(10);
        myStack.push(30);
        myStack.push(20);
        myStack.push(100);

        std::cout << "Stack after pushing elements:\n";
        std::cout << "TOP: " << myStack.top() << std::endl;
        std::cout << "SIZE: " << myStack.getSize() << std::endl;

        myStack.pop();
        myStack.pop();

        std::cout << "Stack after popping elements:\n";
        std::cout << "TOP: " << myStack.top() << std::endl;
        std::cout << "SIZE: " << myStack.getSize() << std::endl;
        getchar();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}