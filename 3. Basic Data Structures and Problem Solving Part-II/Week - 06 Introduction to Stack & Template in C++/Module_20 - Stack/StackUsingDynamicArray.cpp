#include<bits/stdc++.h>
using namespace std;

class Stack{
public:
    int *a;
    int stack_size;
    int cap;

    Stack()
    {
        a = new int[1];
        cap = 1;
        stack_size = 0;
    }
    //Makes the array capacity multiplied by 2
    void IncreaseSize(){
        int *temp;
        temp = new int [cap * 2];
        for(int i=0; i<cap; i++)
            temp[i] = a[i];
        swap(a, temp);
        delete []temp;
        cap *= 2;
    }

    //Add an Element To The Stack O(1)
    void Push(int value){
        if(stack_size >= cap){
            IncreaseSize();
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
