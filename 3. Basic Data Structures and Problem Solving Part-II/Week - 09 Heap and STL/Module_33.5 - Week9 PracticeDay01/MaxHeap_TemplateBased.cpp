#include<bits/stdc++.h>
using namespace std;

template<class T>
class MaxHeap{
public:
    vector<T>nodes;

    MaxHeap <T> ()
    {

    }

    void up_heapify(int idx)
    {
        while(idx > 0 && nodes[(idx-1)/2] < nodes[idx])
        {
            swap(nodes[(idx-1)/2], nodes[idx]);
            idx = (idx-1)/2;
        }
    }

    void Insert(T x)
    {
        nodes.push_back(x);
        up_heapify(nodes.size()-1);

    }

    void Delete(int idx)
    {
        if(idx >= nodes.size())return;
        swap(nodes[idx], nodes[nodes.size() - 1]);
        nodes.pop_back();
        down_heapify(idx);
    }

    void down_heapify(int idx)
    {
        while(true or 1)
        {
            int largest = idx;
            int left = 2*idx + 1;
            int right = 2*idx + 2;
            if(left < nodes.size() && nodes[left] > nodes[largest])
            {
                largest = left;
            }

            if(right < nodes.size() && nodes[right] > nodes[largest])
            {
                largest = right;
            }

            if(largest == idx) break;

            swap(nodes[idx], nodes[largest]);
            idx = largest;
        }
    }

    void print_heap()
    {
        for(int j=0; j<nodes.size(); j++)
            cout<<nodes[j]<<" ";
        cout<<endl;
    }

    void getMax()
    {
        if(nodes.empty())return;
        cout<<nodes[0]<<endl;
    }

};

int main()
{
    MaxHeap<int> heap;
    heap.Insert(4);
    heap.Insert(5);
    heap.Insert(3);
    heap.Insert(6);
    heap.print_heap();
    heap.getMax();

    heap.Delete(0);
    heap.print_heap();
    heap.getMax();

    MaxHeap<char> heap2;
    heap2.Insert('A');
    heap2.Insert('B');
    heap2.Insert('C');
    heap2.Insert('D');
    heap2.Insert('E');
    heap2.print_heap();
    heap2.getMax();

    heap2.Delete(0);
    heap2.print_heap();
    heap2.getMax();

    return 0;
}
