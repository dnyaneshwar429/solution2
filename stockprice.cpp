#include <iostream>
using namespace std;

class Node
{
public:
    float price;
    Node *next;

    Node(float price)
    {
        this->price = price;
        next = nullptr;
    }
};

void insert(Node *&head, float price)
{
    head = new Node(price);
}

void record(Node *&head, float price)
{
    if (head == NULL) {
        insert(head, price);
        return;
    }

    Node *new_node = new Node(price);
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

float remove(Node *&head)
{
    if (head == NULL)
        return -1; 

    // only one node
    if (head->next == NULL) {
        float n = head->price;
        delete head;
        head = NULL;
        return n;
    }

    Node *prev = head;
    Node *temp = head->next;
    while (temp->next)
    {
        prev = temp;
        temp = temp->next;
    }

    float n = temp->price;
    delete temp;
    prev->next = NULL;
    return n;
}

float latest(Node *&head)
{
    if (head == NULL)
        return -1;

    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }

    return temp->price;
}

bool isEmpty(Node *&head)
{
    if (head == NULL)
        return true;

    return false;
}

int main()
{
    Node *head = NULL;   

    record(head, 65);
    record(head, 104.5);
    record(head, 54.69);
    record(head, 329);

    cout << "Latest Stock : " << latest(head) << endl;

    remove(head);
    cout << "Latest Stock : " << latest(head) << endl;

    remove(head);
    remove(head);
    remove(head);
    cout << "Latest Stock : " << latest(head) << endl;

    if (isEmpty(head))
        cout << "No prices recorded." << endl;
    else
        cout << "Not empty!, latest stock is : " << latest(head) << endl;

    return 0;
}
