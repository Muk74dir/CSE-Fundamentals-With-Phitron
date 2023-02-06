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
    T Top(){
        if(stack_size == 0){
            cout<<"STACK IS EMTY"<<endl;
            T a;
            return a;
        }
        return a[stack_size - 1];
    }

};

int main()
{
    Stack<int> main;
    main.Push(10);
    main.Push(20);
    main.Push(30);              //    [10, 20, 30. 40, 50]
    main.Push(40);
    main.Push(50);


    Stack<int> temp;
    for(int i =0; i<5; i++){
        cout<<main.Top()<<" ";
        temp.Push(main.Top());
        main.Pop();
    }

    cout<<endl;
    swap(temp, main);

    for(int i=0; i<5; i++){
        cout<<main.Top()<<" ";     //    [50, 40, 30, 20, 10]
        main.Pop();
    }

    return 0;
}
