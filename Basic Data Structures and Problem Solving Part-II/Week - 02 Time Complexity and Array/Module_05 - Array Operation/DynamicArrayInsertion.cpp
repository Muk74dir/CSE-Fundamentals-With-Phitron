#include<bits/stdc++.h>
using namespace std;

class Array{                        //Memory Complexity : O(n)
private:
    int *ptr;
    int cap;
    int sz;

    void Increment_cap(){
        cap = cap*2;
        int *temp = new int[cap];
        for(int i=0; i<sz; i++){
            temp[i] = ptr[i];
        }
        delete [] ptr;
        ptr = temp;
    }
public:
    Array()
    {
        ptr = new int[1];
        sz = 0;
        cap = 1;
    }
    void Push_back(int x){                  //Time Complexity : O(nlogn)
        if(cap == sz){
            Increment_cap();
        }
        ptr[sz] = x;
        sz++;
    }

    void Insert(int ind, int x){            //Time Complexity : O(sz)
        if(cap == sz){
            Increment_cap();
        }
        for(int i=sz-1; i>=sz; i--){
            ptr[i+1] = ptr[i];
        }
        ptr[ind] = x;
    }

    void print(){                       //Time Complexity : O(sz)
        for(int i=0; i<sz; i++)
            cout<<ptr[i]<<" ";
        cout<<endl;
    }

    void Pop_back(){                //Time Complexity : O(1)
        if(sz==0){
            cout<<"ERROR"<<endl;return;
        }
        sz--;
    }

    void Erase(int ind){                //Time Complexity : O(sz)
        if(sz<=ind){
            cout<<"ERROR"<<endl;return;
        }
        for(int i=ind; i<sz; i++){
            ptr[i] = ptr[i+1];
        }
        sz--;
    }

};

int main()
{
    Array a;

    a.Push_back(10);
    a.Push_back(20);
    a.Push_back(30);
    a.Push_back(40);
    a.Push_back(50);
    a.print();


    a.Insert(1, 100);
    a.print();

    a.Pop_back();
    a.print();

    a.Erase(3);
    a.print();

}
