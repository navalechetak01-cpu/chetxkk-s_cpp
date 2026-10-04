// SINGLY LINKED LIST PROGRAM

#include <iostream>
using namespace std;

// Node Structure
struct Node
{
    int bookID;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    // Constructor
    LinkedList()
    {
        head = NULL;
    }

    // Insert at Beginning
    void insertBeginning(int value)
    {
        Node *newNode = new Node;

        newNode->bookID = value;
        newNode->next = head;
        head = newNode;

        cout << value << " inserted at beginning." << endl;
    }

    // Insert at End
    void insertEnd(int value)
    {
        Node *newNode = new Node;

        newNode->bookID = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        cout << value << " inserted at end." << endl;
    }

    // Delete from Beginning
    void deleteBeginning()
    {
        if (head == NULL)
        {
            cout << "List is Empty." << endl;
            return;
        }

        Node *temp = head;

        cout << temp->bookID << " deleted from beginning." << endl;

        head = head->next;
        delete temp;
    }

    // Display List
    void display()
    {
        if (head == NULL)
        {
            cout << "List is Empty." << endl;
            return;
        }

        Node *temp = head;

        cout << "\nBook IDs in Library:\n";

        while (temp != NULL)
        {
            cout << temp->bookID << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList list;
    int choice, value;

    do
    {
        cout << "\n------ LIBRARY MENU ------" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Delete from Beginning" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Book ID : ";
            cin >> value;
            list.insertBeginning(value);
            break;

        case 2:
            cout << "Enter Book ID : ";
            cin >> value;
            list.insertEnd(value);
            break;

        case 3:
            list.deleteBeginning();
            break;

        case 4:
            list.display();
            break;

        case 5:
            cout << "Program Ended." << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
