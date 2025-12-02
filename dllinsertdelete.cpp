// 2) WAP to create a doubly linked list and perform following operations on it.A) Insert (all cases) 2. Delete (all cases).
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};
void traverse(Node *head)
{

    Node *temp = head;
    cout << "NULL--";
    while (temp)
    {
        cout << temp->data << "--";
        temp = temp->next;
    }
    cout << " NULL " << endl;
}
void insert_head(Node *&head, int val)
{
    Node *new_node = new Node(val);
    if (head)
    {
        head->prev = new_node;
        new_node->next = head;
    }
    head = new_node;
}
void Insert_at_k(Node *&head, int val, int k)
{
    if (k <= 0)
    {
        cout << "Position invalid " << endl;
        return;
    }
    if (k == 1)
    {
        insert_head(head, val);
        return;
    }

    Node *new_node = new Node(val);
    Node *temp = head;
    int count = 1;
    while (temp && count < (k - 1))
    {
        temp = temp->next;
        count++;
    }
    if (temp == nullptr)
    {
        cout << "Position Out of range" << endl;
        delete new_node;
        return;
    }
    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next = new_node;
}
void delete_head(Node *&head)
{
    Node *temp = head;
    head = temp->next;
    head->prev = nullptr;
    free(temp);
}
void delete_node_at_k(Node *&head, int k)
{
    if (k == 1)
    {
        delete_head(head);
        return;
    }
    int count = 1;
    Node *prev = head;
    while (prev && count < (k - 1))
    {
        prev = prev->next;
        count++;
    }
    Node *curr = prev->next;
    Node *next = curr->next;
    prev->next = next;
    next->prev = prev;
    free(curr);
}
int main()
{

    Node *head = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);

    head->next = n2;
    n2->next = n3;
    n2->prev = head;
    n3->prev = n2;

    traverse(head);

    Insert_at_k(head, 4, 3);
    traverse(head);

    delete_node_at_k(head, 1);
    traverse(head);

    return 0;
}
