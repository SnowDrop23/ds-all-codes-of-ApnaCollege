
#include <iostream>
#include <queue>
using namespace std;

void display(queue<int>q)
{
    queue<int>q1 = q;
    while(!q1.empty())
    {
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << endl;
}

int main()
{
    int x;

    queue<int>q;
    cout << "Enter queue elements: ";
    for(int i = 0; i < 5; i++) 
    {
        cin >> x;
        q.push(x);
    }

    cout << "Size of the queue is " << q.size() << endl;
    cout << "The elements of queue are: ";

    display(q);

    cout << "First element of the queue: " << q.front() << endl;
    cout << "Last element of the queue: " << q.back() << endl;

    if(!q.empty()) cout << "Queue is not empty" << endl;
    
    cout << q.front() << " popped from queue." << endl;
    q.pop();

    cout << q.front() << " popped from queue." << endl;
    q.pop();

    cout << "The elements of the queue are: ";
    display(q);
    q.push(80);
    cout << q.back() << " pushed in the queue." << endl;

    cout << "Size of the queue: " << q.size() << endl;
    cout << "The elements of the queue are: ";
    display(q);

    return 0;
}
