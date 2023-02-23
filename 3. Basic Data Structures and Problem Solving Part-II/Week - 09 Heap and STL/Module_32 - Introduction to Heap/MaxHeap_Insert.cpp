#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
public:
    vector<int>nodes;

    MaxHeap()
    {

    }
    //O (Log N)
    void up_heapify(int idx)
    {
        while(idx > 0 && nodes[idx] > nodes[(idx-1)/2]){
            swap(nodes[idx], nodes[(idx-1)/2]);
            idx = (idx-1)/2;
        }
    }

    //O(Log N)
    void Insert(int x)
    {
        nodes.push_back(x);
        up_heapify(nodes.size()-1);
    }

    //O(n)
    void print_heap()
    {
        for(int i=0; i<nodes.size(); i++)
            cout<<nodes[i]<<" ";
        cout<<endl;
    }
};


int main()
{
    MaxHeap mp;
    mp.Insert(4);
    mp.Insert(7);
    mp.Insert(9);
    mp.Insert(1);
    mp.Insert(10);
    mp.print_heap();

    return 0;
}
