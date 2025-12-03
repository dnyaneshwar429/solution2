// 4) Write a program to illustrate operations on a BST holding numeric keys.
// The menu must include: • Insert • Delete • Find • Show
// 2) Write a Program to create a Binary Tree Search and Find Minimum/Maximum in
//  BST
 // 4) BST Program with Insert, Delete, Find, Show
// Also Find Minimum & Maximum in BST

 #include <iostream>
#include <queue>
using namespace std;

class BSTNode
{
public:
    int key;
    BSTNode *left, *right;

    BSTNode(int k) : key(k), left(NULL), right(NULL) {}
};

class BST
{
public:
    BSTNode *root;

    BST() : root(NULL) {}

    // -------- INSERT --------
    BSTNode* insert(BSTNode* node, int key)
    {
        if (!node)
            return new BSTNode(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);

        return node;
    }

    void insertKey(int key)
    {
        root = insert(root, key);
    }

    // -------- FIND --------
    bool find(BSTNode* node, int key)
    {
        if (!node) return false;

        if (node->key == key) return true;

        if (key < node->key)
            return find(node->left, key);
        else
            return find(node->right, key);
    }

    // -------- MIN VALUE --------
    BSTNode* findMin(BSTNode* node)
    {
        while (node && node->left)
            node = node->left;
        return node;
    }

    // -------- DELETE --------
    BSTNode* deleteNode(BSTNode* node, int key)
    {
        if (!node) return NULL;

        if (key < node->key)
            node->left = deleteNode(node->left, key);

        else if (key > node->key)
            node->right = deleteNode(node->right, key);

        else
        {
            // Case 1: No child
            if (!node->left && !node->right)
                return NULL;

            // Case 2: One child
            else if (!node->left)
                return node->right;
            else if (!node->right)
                return node->left;

            // Case 3: Two children
            BSTNode* minNode = findMin(node->right);
            node->key = minNode->key;
            node->right = deleteNode(node->right, minNode->key);
        }
        return node;
    }

    void deleteKey(int key)
    {
        root = deleteNode(root, key);
    }

    // -------- SHOW TRAVERSALS --------
    void inorder(BSTNode* node)
    {
        if (!node) return;
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }

    void preorder(BSTNode* node)
    {
        if (!node) return;
        cout << node->key << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(BSTNode* node)
    {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->key << " ";
    }

    void levelorder()
    {
        if (!root) return;
        queue<BSTNode*> q;
        q.push(root);

        while (!q.empty())
        {
            BSTNode* curr = q.front();
            q.pop();

            cout << curr->key << " ";

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }

    // Show menu display
    void show()
    {
        cout << "\nInorder   : ";
        inorder(root);
        cout << "\nPreorder  : ";
        preorder(root);
        cout << "\nPostorder : ";
        postorder(root);
        cout << "\nLevelwise : ";
        levelorder();
        cout << "\n";
    }
};

// ================= MAIN =================
int main()
{
    BST tree;
    int choice, num;

    while (true)
    {
        cout << "\n====== BST MENU ======\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Find\n";
        cout << "4. Show\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number to insert: ";
            cin >> num;
            tree.insertKey(num);
            break;

        case 2:
            cout << "Enter number to delete: ";
            cin >> num;
            tree.deleteKey(num);
            break;

        case 3:
            cout << "Enter number to find: ";
            cin >> num;
            if (tree.find(tree.root, num))
                cout << "Found!\n";
            else
                cout << "Not Found.\n";
            break;

        case 4:
            tree.show();
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
