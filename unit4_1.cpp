// 1) Write a program to perform Binary Search Tree (BST) operations (Create, Insert,
// Delete, Levelwise  display )
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
}
Node *findMin(Node *root)
{
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}

Node *Delete(Node *root, int key)
{
    if (root == nullptr)
        return root;

    if (key < root->data)
        root->left = Delete(root->left, key);
    else if (key > root->data)
        root->right = Delete(root->right, key);

    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }

        else if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = Delete(root->right, temp->data);
    }
    return root;
}

int main()
{

    // level 1
    Node *root = createNode(10);

    // level 2
    root->left = createNode(5);
    root->right = createNode(20);

    // level 3
    root->left->left = createNode(4);
    root->left->right = createNode(7);
    root->right->left = createNode(15);
    root->right->right = createNode(30);

    Level_order(root);

    root = Delete(root, 20);
    cout << "\nAfter deleting 20: ";
    Level_order(root);

    return 0;
}
