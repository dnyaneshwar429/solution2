 #include <iostream>
using namespace std;

class student {
public:
    string name;
    int marks;
};

// function to swap two students
void swapStudent(student &a, student &b) {
    student temp = a;
    a = b;
    b = temp;
}

// partition function
int partition(student s[], int low, int high) {
    int pivot = s[high].marks;  // choose last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (s[j].marks < pivot) {   // ascending order
            i++;
            swapStudent(s[i], s[j]);
        }
    }

    swapStudent(s[i + 1], s[high]); // place pivot correct position
    return i + 1;
}

// quick sort function
void quickSort(student s[], int low, int high) {
    if (low < high) {
        int pi = partition(s, low, high);

        quickSort(s, low, pi - 1);   // left side
        quickSort(s, pi + 1, high);  // right side
    }
}

int main() {
    student s[20];

    // input
    for (int i = 0; i < 20; i++) {
        cout << "Enter name: ";
        cin >> s[i].name;
        cout << "Enter marks: ";
        cin >> s[i].marks;
    }

    // quick sort call
    quickSort(s, 0, 19);

    // output
    cout << "\nSorted by marks (ascending):\n";
    for (int i = 0; i < 20; i++) {
        cout << s[i].name << " " << s[i].marks << endl;
    }

    return 0;
}
