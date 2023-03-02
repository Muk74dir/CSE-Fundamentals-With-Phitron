#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
public:
    vector<int>nodes;

    MaxHeap()
    {

    }

    void up_heapify(int ind)
    {
        while(ind > 0 &&  nodes[ind] > nodes[(ind-1)/2])
        {
            swap(nodes[ind], nodes[(ind-1)/2]);
            ind = (ind-1) / 2;
        }
    }

    void Insert(int value)
    {
        nodes.push_back(value);
        up_heapify(nodes.size() - 1);
    }

    void down_heapify(int idx)
    {
        while(true)
        {
            int largest = idx;
            int left = 2*idx + 1;
            int right = 2*idx + 2;
            if(left < nodes.size() && nodes[largest] < nodes[left]){
                largest = left;
            }
            if(right < nodes.size() && nodes[largest] < nodes[right]){
                largest = right;
            }
            if(largest == idx){
                break;
            }
            swap(nodes[idx], nodes[largest]);
            idx = largest;
        }
    }

    void Delete(int idx)
    {
        swap(nodes[idx], nodes[nodes.size()-1]);
        nodes.pop_back();
        down_heapify(idx);
    }

    void build_from_array(vector<int>temp)
    {
        nodes = temp;
        int n = nodes.size() - 1;
        int last_non_leaf = n/2 - 1;
        for(int i=last_non_leaf; i>=0; i--){
            down_heapify(i);
        }
    }

    int getMax()
    {
        return nodes[0];
    }
};

class MinHeap{
public:
    MaxHeap mx;

    void insert(int x)
    {
        mx.Insert(-x);
    }
    void Delete(int idx)
    {
        mx.Delete(idx);
    }

    int getMin()
    {
        return -mx.getMax();
    }

};


int main()
{
    MinHeap mp;
    mp.insert(100);
    mp.insert(150);
    mp.insert(50);
    mp.insert(90);
    cout<<mp.getMin()<<endl;

    mp.Delete(0);
    cout<<mp.getMin()<<endl;

    mp.Delete(0);
    cout<<mp.getMin()<<endl;

    mp.Delete(0);
    cout<<mp.getMin()<<endl;

    return 0;
}
