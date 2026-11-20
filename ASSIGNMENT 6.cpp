
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST
{
private:
    Node *root;

    Node *insert(Node *root, int value)
    {
        if (root == NULL)
        {
            return new Node(value);
        }

        if (value < root->data)
        {
            root->left = insert(root->left, value);
        }
        else if (value > root->data)
        {
            root->right = insert(root->right, value);
        }
        else
        {
            cout << "\nDuplicate value not inserted.\n";
        }

        return root;
    }

    Node *copyTree(Node *root)
    {
        if (root == NULL)
        {
            return NULL;
        }

        Node *newNode = new Node(root->data);

        newNode->left = copyTree(root->left);
        newNode->right = copyTree(root->right);

        return newNode;
    }

    int height(Node *root)
    {
        if (root == NULL)
            return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if (leftHeight > rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }

    void leaves(Node *root)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
        {
            cout << root->data << ", ";
            return;
        }

        leaves(root->left);
        leaves(root->right);
    }

public:
    BST()
    {
        root = NULL;
    }

    void createBST()
    {
        int n, value;

        cout << "\nEnter number of nodes: ";
        cin >> n;

        cout << "\nEnter node values:\n";

        for (int i = 1; i <= n; i++)
        {
            cin >> value;
            root = insert(root, value);
        }
    }

    void DisplayHeight()
    {
        cout << "\nHeight of tree: " << height(root) << endl;
    }

    void displayLeaves()
    {
        cout << "\nLeaf nodes: ";
        leaves(root);
        cout << endl;
    }

    void displayLevelWise()
    {
        if (root == NULL)
        {
            cout << "\nTree is empty.\n";
            return;
        }

        Node *queue[100];
        int front = 0;
        int rear = 0;

        queue[rear++] = root;

        cout << "\nLevel-Wise BST:\n";

        while (front < rear)
        {
            int nodesAtLevel = rear - front;

            cout << "Level: ";

            for (int i = 0; i < nodesAtLevel; i++)
            {
                Node *current = queue[front++];

                cout << current->data << " ";

                if (current->left != NULL)
                {
                    queue[rear++] = current->left;
                }

                if (current->right != NULL)
                {
                    queue[rear++] = current->right;
                }
            }

            cout << endl;
        }
    }

    BST *copyNewTree()
    {
        BST *newTree = new BST();

        newTree->root = copyTree(root);

        return newTree;
    }
};

int main()
{
    BST Tree;
    BST *newTree = NULL;

    int choice;

    do
    {
        cout << "\n======== BST Tree ========\n";
        cout << "1. Create Tree" << endl;
        cout << "2. Display Height" << endl;
        cout << "3. Display Leaves" << endl;
        cout << "4. Display Level Wise" << endl;
        cout << "5. Copy Display Height" << endl;
        cout << "6. Copy Display Leaves" << endl;
        cout << "7. Copy Display Level Wise" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Tree.createBST();

            if (newTree != NULL)
            {
                delete newTree;
            }

            newTree = Tree.copyNewTree();
            break;

        case 2:
            Tree.DisplayHeight();
            break;

        case 3:
            Tree.displayLeaves();
            break;

        case 4:
            Tree.displayLevelWise();
            break;

        case 5:
            if (newTree != NULL)
                newTree->DisplayHeight();
            break;

        case 6:
            if (newTree != NULL)
                newTree->displayLeaves();
            break;

        case 7:
            if (newTree != NULL)
                newTree->displayLevelWise();
            break;

        case 8:
            cout << "Exit" << endl;
            break;

        default:
            cout << "Invalid Input" << endl;
            break;
        }

    } while (choice != 8);

    delete newTree;

    return 0;
}
