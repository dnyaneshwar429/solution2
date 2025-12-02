//bubblesort using double ll
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Insert at end of DLL
void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Bubble sort for doubly linked list
void bubbleSort(Node* head) {
    if (!head) return;

    bool swapped;
    Node* ptr;

    do {
        swapped = false;
        ptr = head;

        while (ptr->next != nullptr) {
            if (ptr->data > ptr->next->data) {
                // swap the data
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = true;
            }
            ptr = ptr->next;
        }

    } while (swapped);
}

// Display DLL
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insertAtEnd(head, 5);
    insertAtEnd(head, 1);
    insertAtEnd(head, 4);
    insertAtEnd(head, 2);
    insertAtEnd(head, 8);

    cout << "Before sorting: ";
    display(head);

    bubbleSort(head);

    cout << "After sorting: ";
    display(head);

    return 0;
}
