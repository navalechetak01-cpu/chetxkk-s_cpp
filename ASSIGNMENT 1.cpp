// LIBRARY STACK PROGRAM

#include <iostream>
using namespace std;

#define MAX 5

class Stack
{
private:
    string stack[MAX];
    int top;

public:
    // Constructor
    Stack()
    {
        top = -1;
    }

    // Return Book (Push)
    void push(string book)
    {
        if (top == MAX - 1)
        {
            cout << "Stack Overflow! No space for more books." << endl;
            return;
        }

        top++;
        stack[top] = book;
        cout << "\"" << book << "\" returned successfully." << endl;
    }

    // Arrange Book (Pop)
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow! No books to arrange." << endl;
            return;
        }

        cout << "\"" << stack[top] << "\" arranged on shelf." << endl;
        top--;
    }

    // Top Book (Peek)
    void peek()
    {
        if (top == -1)
        {
            cout << "Stack is Empty." << endl;
            return;
        }

        cout << "Top Book = " << stack[top] << endl;
    }

    // Display Stack
    void display()
    {
        if (top == -1)
        {
            cout << "Stack is Empty." << endl;
            return;
        }

        cout << "\nReturned Books (Top to Bottom)\n";

        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << endl;
        }
    }
};

int main()
{
    Stack s;
    int choice;
    string book;

    do
    {
        cout << "\n------ LIBRARY STACK MENU ------" << endl;
        cout << "1. Return Book" << endl;
        cout << "2. Arrange Book" << endl;
        cout << "3. Top Book" << endl;
        cout << "4. Display Stack" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Choice : ";
        cin >> choice;

        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Enter Book Name : ";
            getline(cin, book);
            s.push(book);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            s.display();
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
