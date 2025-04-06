
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

    queue<int>q;
    for(int i = 0; i < 5; i++) q.push(i+1);

    cout << "Size of the queue is " << q.size() << endl;
    cout << "The elements of queue are: ";

    display(q);

    cout << "First element of the queue: " << q.front() << endl;
    cout << "Last element of the queue: " << q.back() << endl;

    if(!q.empty()) cout << "Queue is not empty" << endl;
    
    q.pop();
    q.pop();

    display(q);
    q.push(80);

    cout << "Size of the queue: " << q.size() << endl;
    cout << "The elements of the queue are: ";
    display(q);

    return 0;
}
