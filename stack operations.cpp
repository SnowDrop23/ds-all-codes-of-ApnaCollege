#include <iostream>
#include <stack>

using namespace std;

int main() 
{
	stack <int> s;
    int x;
    for(int i = 0; i < 5; i++) 
    {
        cin >> x;
        s.push(x);
    }

    cout << "The size of stack: " << s.size() << endl;
    cout << "The topmost element of the stack is: "  << s.top() << endl;

    s.pop();
    s.pop();

   cout << "Stack elements after pop operation: ";
   while(!s.empty())
   {
       cout << s.top() << " ";
       s.pop();
   }
   
}
