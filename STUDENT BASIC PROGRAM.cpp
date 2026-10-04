//STUDENT BASIC PROGRAM

#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int rollNo;
    float marks[5], total, percentage;

public:
    // Constructor
    Student(string n, int r)
    {
        name = n;
        rollNo = r;
        total = 0;
        percentage = 0;
    }

    // Function to accept marks
    void acceptMarks()
    {
        total = 0;
        cout << "\nEnter marks of 5 subjects:\n";
        for (int i = 0; i < 5; i++)
        {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
            total += marks[i];
        }
    }

    // Function to display marks
    void displayMarks()
    {
        cout << "\nStudent Name: " << name;
        cout << "\nRoll No: " << rollNo;
        cout << "\nMarks of 5 Subjects:\n";

        for (int i = 0; i < 5; i++)
        {
            cout << "Subject " << i + 1 << ": " << marks[i] << endl;
        }
    }

    // Function to calculate and display percentage
    void displayPercentage()
    {
        percentage = total / 5;
        cout << "\nPercentage = " << percentage << "%" << endl;
    }
};

int main()
{
    string name;
    int roll;

    cout << "Enter Student Name: ";
    cin >> name;

    cout << "Enter Roll Number: ";
    cin >> roll;

    // Creating object using constructor
    Student s(name, roll);

    int choice;

    do
    {
        cout << "\n------ MENU ------";
        cout << "\n1. Enter Marks";
        cout << "\n2. Display Marks";
        cout << "\n3. Display Percentage";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            s.acceptMarks();
            break;

        case 2:
            s.displayMarks();
            break;

        case 3:
            s.displayPercentage();
            break;

        case 4:
            cout << "\nExiting Program...";
            break;

        default:
            cout << "\nInvalid Choice!";
        }

    } while (choice != 4);

    return 0;
}
