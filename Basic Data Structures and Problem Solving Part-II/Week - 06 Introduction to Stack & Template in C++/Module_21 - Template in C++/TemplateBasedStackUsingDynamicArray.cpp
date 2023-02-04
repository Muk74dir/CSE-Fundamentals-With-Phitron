#include<bits/stdc++.h>
using namespace std;
template <class T>
class Stack{
public:
    T *a;
    int stack_size;
    int cap;

    Stack()
    {
        a = new T[1];
        cap = 1;
        stack_size = 0;
    }
    //Makes the array capacity multiplied by 2
    void IncreaseSize(){
        T *temp;
        temp = new T[cap * 2];
        for(int i=0; i<cap; i++)
            temp[i] = a[i];
        swap(a, temp);
        delete []temp;
        cap *= 2;
    }

    //Add an Element To The Stack O(1)
    void Push(T value){
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
    Stack<double>st;

    cout<<"FOR DOUBLE : -"<<endl;
    st.Push(10.5);
    st.Top();
    st.Push(20.96);
    st.Top();
    st.Push(30.36);
    st.Top();
    st.Push(40.12);
    st.Top();
    st.Push(50.3);
    st.Top();

    st.Pop();
    st.Top();

    st.Pop();
    st.Pop();
    st.Pop();
    st.Pop();

    st.Top();
    st.Pop();
    cout<<endl;

    Stack<char> st2;
    cout<<"FOR CHAR : -"<<endl;
    st2.Push('a');
    st2.Top();
    st2.Push('b');
    st2.Top();
    st2.Push('c');
    st2.Top();
    st2.Push('d');
    st2.Top();
    st2.Push('f');
    st2.Top();

    st2.Pop();
    st2.Top();

    st2.Pop();
    st2.Pop();
    st2.Pop();
    st2.Pop();

    st2.Top();
    st2.Pop();
    cout<<endl;

    Stack<string> st3;
    cout<<"FOR STRING : -"<<endl;
    st3.Push("AGbd");
    st3.Top();
    st3.Push("asfbg");
    st3.Top();
    st3.Push("safgd");
    st3.Top();
    st3.Push("thjt");
    st3.Top();
    st3.Push("hjutkr");
    st3.Top();

    st3.Pop();
    st3.Top();

    st3.Pop();
    st3.Pop();
    st3.Pop();
    st3.Pop();

    st3.Top();
    st3.Pop();
    cout<<endl;

    return 0;
}
