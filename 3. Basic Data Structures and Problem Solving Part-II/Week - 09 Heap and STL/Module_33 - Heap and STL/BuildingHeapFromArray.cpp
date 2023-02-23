#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
public:

    vector<int>nodes;

    // Time Complexity : O(N) [ not O(n log n) ]
    void build_from_array(vector<int> temp)
    {
        nodes = temp;
        int n = nodes.size();
        int last_NonLeaf_node = n/2 - 1;
        for(int j=last_NonLeaf_node; j>= 0; j--)
        {
            down_heapify(j);
        }
    }

    void down_heapify(int idx)
    {
        while(true or 1)
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
            if(idx == largest)break;
            swap(nodes[largest], nodes[idx]);
            idx = largest;
        }
    }

    void print_heap()
    {
        for(int i=0; i<nodes.size(); i++)
            cout<<nodes[i]<<" ";
        cout<<endl;
    }

};

int main()
{
    MaxHeap heap;
    vector<int>input = {1, 2, 3, 4, 10, 9, 8, 7};
    heap.build_from_array(input);
    heap.print_heap();


    return 0;
}
