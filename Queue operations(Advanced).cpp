/*Why Is the Queue Exceeding the Specified Size???
When you specify a size (e.g., n = 5) and then proceed to add more than five elements, the std::queue will continue to accept new elements beyond this limit.
This behavior occurs because std::queue is designed to grow dynamically, and it does not have a built-in mechanism to enforce a maximum size. 
Therefore, without explicit checks, the queue will not prevent you from adding more elements than the initially specified size.*/

#include <iostream>
#include <queue>
using namespace std;

void push(std::queue<int>& q, int x) {
    q.push(x);
    cout << x << " added to the queue.\n";
}

void pop(std::queue<int>& q) {
    if (q.empty()) {
        cout << "Queue Underflow. Can't pop!\n";
    } else {
        cout << q.front() << " removed from the queue.\n";
        q.pop();
    }
}

void frontElement(const std::queue<int>& q) {
    if (q.empty()) {
        cout << "Queue is empty.\n";
    } else {
        cout << "Front element: " << q.front() << endl;
    }
}

void backElement(const std::queue<int>& q) {
    if (q.empty()) {
        cout << "Queue is empty.\n";
    } else {
        cout << "Back element: " << q.back() << endl;
    }
}

void display(std::queue<int> q) {
    if (q.empty()) {
        cout << "Queue is empty.\n";
    } else {
        cout << "Queue elements: ";
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }
}

void size(const std::queue<int>& q) {
    cout << "Queue size: " << q.size() << endl;
}

void empty(const std::queue<int>& q) {
    if (q.empty()) {
        cout << "Queue is empty.\n";
    } else {
        cout << "Queue is not empty.\n";
    }
}

int main(void) {
    int choice, n, value;

    cout << "Enter the size of queue: ";
    cin >> n;
    queue <int> q;

    while(1)
    {
        cout << "Stack Operations: \n";
        cout << "1. push(), 2. pop(), 3. front(), 4. back(), 5. display(), 6. size(), 7. empty(), 8. exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch(choice)
        {
            case 1: 
                cout << "Enter value to push: ";
                cin >> value;
                push(q, value); 
                break;
            case 2: pop(q); break;
            case 3: frontElement(q); break;
            case 4: backElement(q); break;
            case 5: display(q); break;
            case 6: size(q); break;
            case 7: empty(q); break;
            case 8: printf("Exiting program.\n"); return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}
