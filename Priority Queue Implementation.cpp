/* Priority queue is Dynamic Container, so we can add as much element as we need beyond its size.
 "A priority_queue is a dynamic container in C++. This means you can add (push) as many elements as 
needed, and it will automatically grow in size without any predefined limit." */
#include <iostream>
#include <queue>
using namespace std;


int main()
{
    priority_queue<int>pq;
    int x;

    for(int i = 0; i < 5; i++)
    {
        cin >> x;
        pq.push(x);
    }

    cout << "The size of queue is: " << pq.size() << endl;
    cout << "The highest priority element of the queue is: " << pq.top() << endl;
    
    cout << pq.top() << " is popped out from the queue." << endl;
    pq.pop();

    cout << pq.top() << " is popped out from the queue." << endl;
    pq.pop();

    pq.push(20);
    cout << pq.top() << " is pushed in the queue." << endl;
    pq.push(28);
    cout << pq.top() << " is pushed in the queue." << endl;
    pq.push(80);
    cout << pq.top() << " is pushed in the queue." << endl;
    pq.push(98);
    cout << pq.top() << " is pushed in the queue." << endl;


    if(!pq.empty()) cout << "The new size of the queue is " << pq.size() << endl;

    cout << "The elements of the queue: ";
    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
