#include <string>
#include <iostream>

class DoublyLinkedList
{
private:
    struct Node
    {
        int data;
        struct Node *next;
        struct Node *prev;
    };

public:
    struct Node *head;
    struct Node *tail;
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    };

    void AddNodeToEnd(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
        tail = newNode;
    };

    void DeleteNode(int data)
    {
        if (head == nullptr)
        {
            std::cout << "The list is currently empty\n";
        }
        else
        {
            Node *current = head;
            Node *previous = nullptr;
            // Traversing the list
            while (current->next != nullptr && current->data != data)
            {
                previous = current;
                current = current->next;
            }
            // If the node exists
            if (current != nullptr)
            {
                // If the current is the headnode, change the linking
                if (previous == nullptr)
                {
                    head = current->next;
                }
                else
                {
                    previous->next = current->next;
                    if (current->next != nullptr)
                    {
                        current->next->prev = previous;
                    }
                }
                delete current;
                std::cout << "Node with data " << data << " has been deleted.\n";
            }
            else
            {
                std::cout << "Node with data " << data << " not found.\n";
            }
        }
    }

    void printListFromHead()
    {
        if (head == nullptr)
        {
            std::cout << "The list is currently empty.\n";
        }
        else
        {
            Node *current = head;
            while (current != nullptr)
            {
                std::cout << current->data << std::endl;
                current = current->next;
            }
        }
    }

    void printListFromTail()
    {
        if (tail == nullptr)
        {
            std::cout << "The list is currently empty.\n";
        }
        else
        {
            Node *current = tail;
            while (current != nullptr)
            {
                std::cout << current->data << std::endl;
                current = current->prev;
            }
        }
    }
};

int main(int argc, char const *argv[])
{

    DoublyLinkedList List;

    List.AddNodeToEnd(10);
    List.AddNodeToEnd(20);
    List.AddNodeToEnd(50);

    List.printListFromHead();
    List.printListFromTail();
    List.DeleteNode(20);
    List.printListFromHead();
    List.DeleteNode(50);
    List.printListFromHead();
    List.DeleteNode(10);
    List.printListFromHead();

    return 0;
}