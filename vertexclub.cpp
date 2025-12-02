// 4)  Implementation of Singly Linked List to Manage ‘Vertex Club’ Membership Records.
// The Department of Computer Engineering has a student club named ‘Vertex Club’ for
// second, third, and final year students. The first member is the President and the last
// member is the Secretary. Write a C++ program to:
// ● Add/delete members (including President/Secretary)
// ● Count members
// ● Display members
// ● Concatenate two division lists
// Also implement: reverse, search by PRN, and sort by PRN operations.
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int prn;
    string name;
    int year;
    Node *next;
    Node(int p, const string &n, int y) : prn(p), name(n), year(y), next(nullptr) {}
};

int countMembers(Node *head)
{
    int c = 0;
    while (head)
    {
        ++c;
        head = head->next;
    }
    return c;
}

void display(Node *head)
{
    if (!head)
    {
        cout << "List empty.\n";
        return;
    }
    cout << "PRN\tName\tYear\n";
    while (head)
    {
        cout << head->prn << '\t' << head->name << '\t' << head->year << '\n';
        head = head->next;
    }
}

void addAtBeginning(Node *&head, int prn, const string &name, int year)
{
    Node *n = new Node(prn, name, year);
    n->next = head;
    head = n;
}

void addAtEnd(Node *&head, int prn, const string &name, int year)
{
    Node *n = new Node(prn, name, year);
    if (!head)
    {
        head = n;
        return;
    }
    Node *t = head;
    while (t->next)
        t = t->next;
    t->next = n;
}

bool insertAfterPRN(Node *head, int afterPRN, int prn, const string &name, int year)
{
    Node *t = head;
    while (t)
    {
        if (t->prn == afterPRN)
        {
            Node *n = new Node(prn, name, year);
            n->next = t->next;
            t->next = n;
            return true;
        }
        t = t->next;
    }
    return false;
}

bool deleteByPRN(Node *&head, int prn)
{
    if (!head)
        return false;
    if (head->prn == prn)
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
        return true;
    }
    Node *prev = head;
    Node *cur = head->next;
    while (cur)
    {
        if (cur->prn == prn)
        {
            prev->next = cur->next;
            delete cur;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    return false;
}

bool deleteFirst(Node *&head)
{
    if (!head)
        return false;
    Node *tmp = head;
    head = head->next;
    delete tmp;
    return true;
}

bool deleteLast(Node *&head)
{
    if (!head)
        return false;
    if (!head->next)
    {
        delete head;
        head = nullptr;
        return true;
    }
    Node *t = head;
    while (t->next->next)
        t = t->next;
    delete t->next;
    t->next = nullptr;
    return true;
}

void concatenate(Node *&a, Node *&b)
{
    if (!a)
    {
        a = b;
        b = nullptr;
        return;
    }
    Node *t = a;
    while (t->next)
        t = t->next;
    t->next = b;
    b = nullptr;
}

void reverseList(Node *&head)
{
    Node *prev = nullptr;
    Node *cur = head;
    while (cur)
    {
        Node *nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    head = prev;
}

Node *searchPRN(Node *head, int prn)
{
    while (head)
    {
        if (head->prn == prn)
            return head;
        head = head->next;
    }
    return nullptr;
}

void sortByPRN(Node *head)
{
    if (!head)
        return;
    bool swapped;
    do
    {
        swapped = false;
        Node *p = head;
        while (p->next)
        {
            if (p->prn > p->next->prn)
            {
                // swap data fields
                swap(p->prn, p->next->prn);
                swap(p->name, p->next->name);
                swap(p->year, p->next->year);
                swapped = true;
            }
            p = p->next;
        }
    } while (swapped);
}

void inputMember(int &prn, string &name, int &year)
{
    cout << "Enter PRN: ";
    cin >> prn;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Year (2/3/4): ";
    cin >> year;
    cin.ignore();
}

int main()
{
    Node *divisionA = nullptr;
    Node *divisionB = nullptr;
    int choice;
    cout << "Vertex Club Membership Manager)\n";
    do
    {
        cout << "\nMenu:\n"
             << "1. Add President to Division A\n"
             << "2. Add Secretary to Division A\n"
             << "3. Add member after a PRN in Division A\n"
             << "4. Delete by PRN from Division A\n"
             << "5. Delete President from Division A\n"
             << "6. Delete Secretary from Division A\n"
             << "7. Count members in Division A\n"
             << "8. Display Division A\n"
             << "9. Concatenate Division B into Division A\n"
             << "10. Reverse Division A\n"
             << "11. Search by PRN in Division A\n"
             << "12. Sort Division A by PRN\n"
             << "13. Quick populate Division B (for test concatenate)\n"
             << "0. Exit\n"
             << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        int prn, year, afterPRN;
        string name;
        bool ok;
        switch (choice)
        {
        case 1:
            inputMember(prn, name, year);
            addAtBeginning(divisionA, prn, name, year);
            cout << "President added.\n";
            break;
        case 2:
            inputMember(prn, name, year);
            addAtEnd(divisionA, prn, name, year);
            cout << "Secretary (or member) added at end.\n";
            break;
        case 3:
            cout << "Enter PRN after which to insert: ";
            cin >> afterPRN;
            cin.ignore();
            inputMember(prn, name, year);
            ok = insertAfterPRN(divisionA, afterPRN, prn, name, year);
            cout << (ok ? "Inserted.\n" : "PRN not found.\n");
            break;
        case 4:
            cout << "Enter PRN to delete: ";
            cin >> prn;
            cin.ignore();
            ok = deleteByPRN(divisionA, prn);
            cout << (ok ? "Deleted.\n" : "PRN not found.\n");
            break;
        case 5:
            ok = deleteFirst(divisionA);
            cout << (ok ? "President deleted.\n" : "List empty.\n");
            break;
        case 6:
            ok = deleteLast(divisionA);
            cout << (ok ? "Secretary deleted.\n" : "List empty.\n");
            break;
        case 7:
            cout << "Member count: " << countMembers(divisionA) << '\n';
            break;
        case 8:
            cout << "Division A members:\n";
            display(divisionA);
            break;
        case 9:
            cout << "Concatenating Division B into Division A...\n";
            concatenate(divisionA, divisionB);
            cout << "Done. Division B is now empty.\n";
            break;
        case 10:
            reverseList(divisionA);
            cout << "Division A reversed.\n";
            break;
        case 11:
            cout << "Enter PRN to search: ";
            cin >> prn;
            cin.ignore();
            {
                Node *found = searchPRN(divisionA, prn);
                if (found)
                    cout << "Found: " << found->prn << " " << found->name << " Year:" << found->year << '\n';
                else
                    cout << "Not found.\n";
            }
            break;
        case 12:
            sortByPRN(divisionA);
            cout << "Division A sorted by PRN.\n";
            break;
        case 13:
            addAtEnd(divisionB, 8001, "Alice B", 3);
            addAtEnd(divisionB, 8002, "Bob B", 2);
            addAtEnd(divisionB, 8003, "Charlie B", 4);
            cout << "Division B populated with 3 sample members.\n";
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    // cleanup: free nodes
    while (divisionA)
    {
        Node *t = divisionA;
        divisionA = divisionA->next;
        delete t;
    }
    while (divisionB)
    {
        Node *t = divisionB;
        divisionB = divisionB->next;
        delete t;
    }
    return 0;
}
