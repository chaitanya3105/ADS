#include <bits/stdc++.h>

using namespace std;

class Queue {
private:
    list<int> elements;

public:
    void insert(int value) {
        elements.push_back(value);
    }
    void remove() {
        if (isEmpty()) {
            cout << "Queue is empty. Unable to remove." << endl;
            return;
        }
        elements.pop_front();
    }
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue: ";
        for (int element : elements) {
            cout << element << " ";
        }
        cout << endl;
    }
    bool isEmpty() const {
        return elements.empty();
    }
};

int main() {
    Queue queue;
    int choice;
    int value;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                queue.insert(value);
                break;
            case 2:
                queue.remove();
                break;
            case 3:
                queue.display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

