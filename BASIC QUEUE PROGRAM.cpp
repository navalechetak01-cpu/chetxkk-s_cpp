//BASIC QUEUE PROGRAM:

#include <iostream>
using namespace std;

#define MAX 5

class Queue
{
private:
    int queue[MAX];
    int front;
    int rear;

public:
    // Constructor
    Queue()
    {
        front = -1;
        rear = -1;
    }

    // Enqueue Operation
    void enqueue(int value)
    {
        // Check if queue is full
        if (rear == MAX - 1)
        {
            cout << "\nQueue Overflow! Queue is Full." << endl;
            return;
        }

        // Insert first element
        if (front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = value;

        cout << value << " inserted into queue." << endl;
    }

    // Dequeue Operation
    void dequeue()
    {
        // Check if queue is empty
        if (front == -1)
        {
            cout << "\nQueue Underflow! Queue is Empty." << endl;
            return;
        }

        cout << queue[front] << " removed from queue." << endl;
        front++;

        // Reset queue when all elements are deleted
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }

    // Peek Operation
    void peek()
    {
        if (front == -1)
        {
            cout << "\nQueue is Empty." << endl;
            return;
        }

        cout << "Front Element = " << queue[front] << endl;
    }

    // Display Operation
    void display()
    {
        if (front == -1)
        {
            cout << "\nQueue is Empty." << endl;
            return;
        }

        cout << "\nQueue Elements: ";

        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    Queue q;
    int choice, value;

    do
    {
        cout << "\n------ QUEUE MENU ------" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
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
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.peek();
            break;

        case 4:
            q.display();
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
