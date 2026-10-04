// TICKET BOOKING COUNTER QUEUE PROGRAM

#include <iostream>
using namespace std;

#define MAX 5

class Queue
{
private:
    string queue[MAX];
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
    void enqueue(string customer)
    {
        if (rear == MAX - 1)
        {
            cout << "Queue Overflow! Counter queue is full." << endl;
            return;
        }

        if (front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = customer;

        cout << customer << " joined the ticket queue." << endl;
    }

    // Dequeue Operation
    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue Underflow! No customers in queue." << endl;
            return;
        }

        cout << queue[front] << " got the ticket and left the queue." << endl;
        front++;

        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }

    // Display Queue
    void display()
    {
        if (front == -1)
        {
            cout << "Queue is Empty." << endl;
            return;
        }

        cout << "\nCustomers in Queue:" << endl;

        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << endl;
        }
    }
};

int main()
{
    Queue q;
    int choice;
    string customer;

    do
    {
        cout << "\n------ TICKET COUNTER MENU ------" << endl;
        cout << "1. Enqueue Customer" << endl;
        cout << "2. Dequeue Customer" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Choice : ";
        cin >> choice;

        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Enter Customer Name : ";
            getline(cin, customer);
            q.enqueue(customer);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Program Ended." << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}
