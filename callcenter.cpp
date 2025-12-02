// 3) In a call center, customer calls are handled on a first-come, first-served basis.
// Implement a queue system using Linked list where:
// • Each customer call is enqueued as it arrives.
// • Customer service agents dequeue calls to assist customers.
// • If there are no calls, the system waits.
#include <iostream>
using namespace std;

class Node {
public:
    int id;
    string name;
    Node* next;

    Node(int id, string name) {
        this->id = id;
        this->name = name;
        next = NULL;
    }
};

void enqueue(Node*& front, int id, string name) {
    Node* temp = new Node(id, name);

    if (front == NULL) {
        front = temp;
        return;
    }

    Node* t = front;
    while (t->next != NULL)
        t = t->next;

    t->next = temp;
}

void dequeue(Node*& front) {
    if (front == NULL) {
        cout << "No calls in queue" << endl;
        return;
    }

    Node* temp = front;
    cout << "Assisting call from " << temp->name << " (ID: " << temp->id << ")" << endl;

    front = front->next;
    delete temp;
}

void display(Node* front) {
    if (front == NULL) {
        cout << "No waiting calls" << endl;
        return;
    }

    cout << "Calls in queue:" << endl;
    while (front != NULL) {
        cout << front->id << " - " << front->name << endl;
        front = front->next;
    }
}

int main() {
    Node* front = NULL;
    int choice, id = 1;
    string name;

    while (true) {
        cout << "1. Add Call" << endl;
        cout << "2. Assist Next Call" << endl;
        cout << "3. View Waiting Calls" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter customer name: ";
            cin >> name;
            enqueue(front, id++, name);
        }
        else if (choice == 2) {
            dequeue(front);
        }
        else if (choice == 3) {
            display(front);
        }
        else if (choice == 4) {
            cout << "Exiting" << endl;
            break;
        }
        else {
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
