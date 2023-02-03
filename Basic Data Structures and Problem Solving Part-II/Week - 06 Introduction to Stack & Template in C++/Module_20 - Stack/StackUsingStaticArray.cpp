#include<bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 5;
class Stack{
public:
    int a[MAX_SIZE];
    int stack_size;

    Stack()
    {
        stack_size = 0;
    }

    //Add an Element To The Stack O(1)
    void Push(int value){
        if(stack_size >= MAX_SIZE){
            cout<<"STACK IS FULL!!"<<endl;
            return;
        }
        stack_size++;
        a[stack_size - 1] = value;
    }

    // Delete The Top Most Element O(1)
    void Pop(){
        if(stack_size == 0){
            cout<<"STACK ALREADY EMTY"<<endl;
            return;
        }
        a[stack_size - 1] = 0;
        stack_size --;
    }

    //Return Top Element 0(1)
    void Top(){
        if(stack_size == 0){
            cout<<"STACK IS EMTY"<<endl;
            return;
        }
        cout<<a[stack_size - 1]<<endl;
    }

};

int main()
{
    Stack st;

    st.Push(10);
    st.Top();
    st.Push(20);
    st.Top();
    st.Push(30);
    st.Top();
    st.Push(40);
    st.Top();
    st.Push(50);
    st.Top();

    st.Push(200);
    st.Pop();
    st.Top();

    st.Pop();
    st.Pop();
    st.Pop();
    st.Pop();

    st.Top();
    st.Pop();


    return 0;
}
