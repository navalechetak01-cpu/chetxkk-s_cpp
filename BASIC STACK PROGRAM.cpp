//BASIC STACK PROGRAM:

#include <iostream>
using namespace std;

#define MAX 5

class Stack
{
private:
    int stack[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    // Push Operation
    void push(int value)
    {
        if (top == MAX - 1)
        {
            cout << "Stack Overflow!" << endl;
            return;
        }

        stack[++top] = value;
        cout << value << " inserted into stack." << endl;
    }

    // Pop Operation
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow!" << endl;
            return;
        }

        cout << stack[top--] << " removed from stack." << endl;
    }

    // Peek Operation
    void peek()
    {
        if (top == -1)
        {
            cout << "Stack is Empty." << endl;
            return;
        }

        cout << "Top Element = " << stack[top] << endl;
    }

    // Display Operation
    void display()
    {
        if (top == -1)
        {
            cout << "Stack is Empty." << endl;
            return;
        }

        cout << "\nStack Elements (Top to Bottom):" << endl;

        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << endl;
        }
    }
};

int main()
{
    Stack s;
    int choice, value;

    do
    {
        cout << "\n------ STACK MENU ------" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Integer: ";
            cin >> value;
            s.push(value);
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
