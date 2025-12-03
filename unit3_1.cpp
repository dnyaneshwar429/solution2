//WAP to build a simple stock price tracker that keeps a history of daily stock prices 
// entered by the user. To allow users to go back and view or remove the most recent price, 
// implement a stack using a linked list to store these integer prices. 
// Implement the following operations: 
// a. record(price) – Add a new stock price (an integer) to the stack. 
// b. remove() – Remove and return the most recent price (top of the stack). 
// c. latest() – Return the most recent stock price without removing it. 
// d. isEmpty() – Check if there are no prices recorded.//
  /*
1) WAP to build a simple stock price tracker that keeps a history of daily stock prices
entered by the user. To allow users to go back and view or remove the most recent price,
implement a stack using a linked list to store these integer prices.
Implement the following operations:
a. record(price) – Add a new stock price (an integer) to the stack.
b. remove() – Remove and return the most recent price (top of the stack).
c. latest() – Return the most recent stock price without removing it.
d. isEmpty() – Check if there are no prices recorded.
*/

#include<iostream>
using namespace std;

class Node
{
public:
	int price;
	Node* next;

	Node(int price = 0, Node* next = NULL): price(price), next(next) { }
};

class Tracker
{
	Node* base;
public:

	Tracker()
	{
		base = new Node(-1);
	}

	bool isEmpty()
	{
		return base->next == NULL;
	}

	void Record(int price)
	{
		base->next = new Node(price, base->next);
	}

	int Remove()
	{
		if (isEmpty())
		{
			cout << "Stack is empty" << endl;
			return -1;
		}

		Node* curr = base->next;
		base->next = curr->next;

		int price = curr->price;
		delete curr;

		return price;
	}

	int Latest()
	{
		if (isEmpty())
		{
			cout << "Stack is empty" << endl;
			return;
		}

		return base->next->price;
	}
};

int main() {
    Tracker t;
    int choice, price;

    while (true) {
        cout << "\n--- Stock Price Tracker ---\n";
        cout << "1. Record Price\n";
        cout << "2. Remove Latest Price\n";
        cout << "3. Show Latest Price\n";
        cout << "4. Check if Empty\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter price: ";
            cin >> price;
            t.Record(price);
            cout << "Recorded.\n";
            break;

        case 2:
            price = t.Remove();
            if (price != -1)
                cout << "Removed price: " << price << endl;
            break;

        case 3:
            if (!t.isEmpty())
                cout << "Latest price: " << t.Latest() << endl;
            else
                cout << "Stack is empty.\n";
            break;

        case 4:
            if (t.isEmpty())
                cout << "No prices recorded.\n";
            else
                cout << "Stack has prices.\n";
            break;

        case 5:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice.\n";
        }
    }
}
