#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Function to create a new node
Node* CreateNode(int value) {
    Node* newNode = new Node(value);

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Function to create the binary tree
Node* CreateTree() {
    int value;

    cout << "Enter value (-1 for no node): ";
    cin >> value;

    // If value is -1, there is no node
    if (value == -1) {
        return NULL;
    }

    // Create the current node
    Node* newNode = CreateNode(value);

    // Create left subtree
    cout << "Enter left child of " << value << endl;
    newNode->left = CreateTree();

    // Create right subtree
    cout << "Enter right child of " << value << endl;
    newNode->right = CreateTree();

    return newNode;
}

// Inorder Traversal
// Left -> Root -> Right
void Inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

// Preorder Traversal
// Root -> Left -> Right
void Preorder(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

// Postorder Traversal
// Left -> Right -> Root
void Postorder(Node* root) {
    if (root == NULL) {
        return;
    }

    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

// Main function
int main() {
    Node* root = NULL;

    cout << "Create Binary Tree" << endl;

    root = CreateTree();

    cout << "\nInorder Traversal: ";
    Inorder(root);

    cout << "\nPreorder Traversal: ";
    Preorder(root);

    cout << "\nPostorder Traversal: ";
    Postorder(root);

    return 0;
}
