#include <iostream>
#include <string>

class List
{
private:
    struct Node
    {
        int data;
        Node *next;
    };

    Node *head;

public:
    List()
    {
        head = nullptr;
    };

    void addNode(int addData)
    {
        Node *newNode = new Node;
        newNode->data = addData;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;

            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    };

    void deleteNode(int delData)
    {

        Node *current = head;
        Node *previous = nullptr;

        while (current != nullptr && current->data != delData)
        {
            previous = current;
            current = current->next;
        }
        if (current == nullptr)
        {
            std::cout << delData << " was not in the list.\n";
            return;
        }
        else
        {
            previous->next = current->next;
            delete current;
            std::cout << delData << " has been deleted.\n";
        }
    };

    void printList()
    {
        if (head == nullptr)
        {
            std::cout << "The list is empty" << std::endl;
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
};
int main(int argc, char const *argv[])
{

    List l;

    l.addNode(3);
    l.addNode(5);
    l.addNode(10);
    l.addNode(50);
    l.printList();
    l.deleteNode(10);
    l.printList();

    return 0;
}