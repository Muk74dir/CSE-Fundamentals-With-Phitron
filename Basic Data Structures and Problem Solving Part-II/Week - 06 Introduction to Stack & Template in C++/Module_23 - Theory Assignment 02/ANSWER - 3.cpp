#include<bits/stdc++.h>
using namespace std;

template <class T>
class Stack{
public:
    Stack()
    {
    }

    T print(T value)
    {
        return value;
    }
};
int main()
{
    Stack<int> int_stack;
    cout<<int_stack.print(5)<<endl;

    Stack<char> char_stack;
    cout<<char_stack.print('M')<<endl;

    Stack<double> real_stack;
    cout<<real_stack.print(10.99)<<endl;
}
