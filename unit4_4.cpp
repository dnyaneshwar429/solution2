// 4) Write a program to illustrate operations on a BST holding numeric keys.
// The menu must include: • Insert • Delete • Find • Show
// 2) Write a Program to create a Binary Tree Search and Find Minimum/Maximum in
//  BST
#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int data)
    {
        this->data = data;
        right = nullptr;
        left = nullptr;
    }
};
Node *createNode(int data)
{
    Node *new_node = new Node(data);
}
Node *insertNode(Node *root, int data)
{
    if (root == nullptr)
        return createNode(data);
    if (data < root->data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);
    return root;
}
void Level_order(Node *root)
{
    if (root == nullptr)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {

        Node *curr = q.front();
        q.pop();

        cout << curr->data << " ";
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
    cout << endl;
}
int main()
{
    Node *root = nullptr;
    int choice, val;

    root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(4);
    root->left->right = createNode(7);
    root->right->left = createNode(15);
    root->right->right = createNode(30);

    while (true)
    {
        cout << endl
             << "--- BST Menu ---" << endl;
        cout << "1. Insert value" << endl;
        cout << "2. Level-order traversal" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input. Exiting." << endl;
            break;
        }

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            root = insertNode(root, val);
            cout << val << " inserted." << endl;
            break;

        case 2:
            cout << "Level-order: ";
            if (root == nullptr)
                cout << "Tree is empty.";
            else
                Level_order(root);
            cout << endl;
            break;

        case 3:
            cout << "Exiting." << endl;
            return 0;

        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
