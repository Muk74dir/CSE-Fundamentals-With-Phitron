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
    //O(Log N)
    void Delete(int idx){
        if(idx >= nodes.size()){cout<<"Doesn't Exist"<<endl;return;}
        swap(nodes[idx], nodes[nodes.size()-1]);
        nodes.pop_back();
        down_heapify(idx);
    }
    //O(Log N)
    void down_heapify(int idx){
        while (true)
        {
            int largest = idx;
            int left = 2*idx + 1;
            int right = 2*idx + 2;

            if(left < nodes.size() && nodes[left] > nodes[largest]){
                largest = left;
            }
            if(right < nodes.size() && nodes[right] > nodes[largest]){
                largest = right;
            }

            if(largest == idx){break;}

            swap(nodes[idx], nodes[largest]);
            idx = largest;
        }
    }
    //O (1)
    int getMax()
    {
        if(nodes.empty())
        {
            cout<<"Heap is Empty"<<endl;
            return -1;
        }
        return nodes[0];
    }
    //O (Log N)
    int ExtractMax()
    {
        if(nodes.empty())
        {
            cout<<"Heap is Empty"<<endl;
            return -1;
        }
        int root = nodes[0];
        Delete(0);
        return root;
    }

};


int main()
{
    MaxHeap heap;
    heap.Insert(4);
    heap.Insert(7);
    heap.Insert(9);
    heap.Insert(1);
    heap.Insert(10);
    heap.Insert(20);
    heap.Insert(30);

    heap.print_heap();
    cout<<"Max Element : "<<heap.getMax()<<endl;

    heap.ExtractMax();

    heap.print_heap();
    cout<<"Max Element : "<<heap.getMax()<<endl;

    heap.ExtractMax();

    heap.print_heap();
    cout<<"Max Element : "<<heap.getMax()<<endl;

    heap.ExtractMax();

    heap.print_heap();
    cout<<"Max Element : "<<heap.getMax()<<endl;


    return 0;
}
