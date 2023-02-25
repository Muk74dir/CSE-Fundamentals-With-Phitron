#include<bits/stdc++.h>
using namespace std;
template<class T>
class MinHeap{
public:
    vector<T>nodes;

    MinHeap()
    {

    }

    void up_heapify(int idx)
    {

        while(idx > 0 && nodes[idx] < nodes[(idx-1)/2])
        {
            swap(nodes[idx], nodes[(idx-1)/2]);
            idx = (idx-1) / 2;
        }
    }

    void Insert(T x)
    {
        nodes.push_back(x);
        up_heapify(nodes.size()-1);
    }
    void down_heapify(int idx)
    {
        while(true or 1)
        {
            int smallest = idx;
            int left = 2*idx + 1;
            int right = 2*idx + 2;
            if(left < nodes.size() && nodes[left] < nodes[smallest]){
                smallest = left;
            }
            if(right < nodes.size() && nodes[right] < nodes[smallest]){
                smallest = right;
            }
            if(smallest == idx)break;
            swap(nodes[smallest], nodes[idx]);
            idx = smallest;
        }
    }

    void Delete(int idx)
    {
        if(idx >= nodes.size()) return;
        swap(nodes[idx], nodes[nodes.size() - 1]);
        nodes.pop_back();
        down_heapify(idx);
    }

    void getMin()
    {
        if(nodes.empty())return;
        cout<<nodes[0]<<endl;
    }

    void print_heap()
    {
        for(int j=0; j<nodes.size(); j++)
            cout<<nodes[j]<<" ";
        cout<<endl;
    }
};

int main()
{
    MinHeap<int> heap;
    heap.Insert(20);
    heap.Insert(13);
    heap.Insert(9);
    heap.Insert(1);
    heap.print_heap();
    heap.getMin();

    heap.Delete(0);
    heap.print_heap();
    heap.getMin();

    MinHeap<char> heap2;
    heap2.Insert('A');
    heap2.Insert('B');
    heap2.Insert('Z');
    heap2.Insert('V');
    heap2.print_heap();
    heap2.getMin();

    heap2.Delete(0);
    heap2.print_heap();
    heap2.getMin();



    return 0;
}
