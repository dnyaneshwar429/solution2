// 1)Design and implement a smart college placement portal that uses advanced
// hashing techniques to efficiently manage student placement records with high
// performance and low collision probability, even under dynamic data growth.
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int id;
    string name;
    string branch;
    float cgpa;
    Node *next;
};

const int SIZE = 10;   
Node *hashTable[SIZE]; 

int hashFunction(int id)
{
    return id % SIZE;
}

void insertStudent(int id, string name, string branch, float cgpa)
{
    int index = hashFunction(id);

    Node *newNode = new Node;
    newNode->id = id;
    newNode->name = name;
    newNode->branch = branch;
    newNode->cgpa = cgpa;
    newNode->next = NULL;

    if (hashTable[index] == NULL)
    {
        hashTable[index] = newNode;
    }
    else
    {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }

    cout << "Record inserted!\n";
}

Node *searchStudent(int id)
{
    int index = hashFunction(id);
    Node *temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->id == id)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void deleteStudent(int id)
{
    int index = hashFunction(id);
    Node *temp = hashTable[index];
    Node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            if (prev == NULL) 
                hashTable[index] = temp->next;
            else
                prev->next = temp->next;

            delete temp;
            cout << "Record deleted!\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    cout << "Record not found!\n";
}

void displayTable()
{
    cout << "\n--- Hash Table Records ---\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Bucket " << i << ": ";
        Node *temp = hashTable[i];
        if (temp == NULL)
        {
            cout << "EMPTY\n";
            continue;
        }
        while (temp != NULL)
        {
            cout << " -> [ID:" << temp->id
                 << ", Name:" << temp->name
                 << ", Branch:" << temp->branch
                 << ", CGPA:" << temp->cgpa << "]";
            temp = temp->next;
        }
        cout << "\n";
    }
}

int main()
{
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = NULL;

    int choice;

    do
    {
        cout << "\n1. Insert Student\n2. Search Student\n3. Delete Student\n4. Display Table\n0. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int id;
            string name, branch;
            float cgpa;

            cout << "Enter ID: ";
            cin >> id;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Branch: ";
            cin >> branch;

            cout << "Enter CGPA: ";
            cin >> cgpa;

            insertStudent(id, name, branch, cgpa);
        }
        else if (choice == 2)
        {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;

            Node *s = searchStudent(id);
            if (s != NULL)
                cout << "Found: " << s->name << ", " << s->branch << ", CGPA = " << s->cgpa << "\n";
            else
                cout << "Record not found!\n";
        }
        else if (choice == 3)
        {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;

            deleteStudent(id);
        }
        else if (choice == 4)
        {
            displayTable();
        }

    } while (choice != 0);

    return 0;
}
