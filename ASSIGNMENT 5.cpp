#include <iostream>
#include <stack>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert node into BST
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Non-recursive Inorder Traversal
void inorder(Node* root) {
    stack<Node*> s;
    Node* current = root;

    while (current != NULL || !s.empty()) {

        // Go to the leftmost node
        while (current != NULL) {
            s.push(current);
            current = current->left;
        }

        // Process the node
        current = s.top();
        s.pop();

        cout << current->data << " ";

        // Move to right subtree
        current = current->right;
    }
}

// Non-recursive Preorder Traversal
void preorder(Node* root) {
    if (root == NULL)
        return;

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* current = s.top();
        s.pop();

        cout << current->data << " ";

        // Push right first
        if (current->right != NULL)
            s.push(current->right);

        // Push left second
        if (current->left != NULL)
            s.push(current->left);
    }
}

// Main function
int main() {
    Node* root = NULL;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter nodes: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    return 0;
}
