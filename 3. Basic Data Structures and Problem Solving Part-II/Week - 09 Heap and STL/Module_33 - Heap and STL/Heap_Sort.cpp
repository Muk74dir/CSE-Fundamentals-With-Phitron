#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
public:
    vector<int>nodes;

    MaxHeap()
    {

    }

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

    //O(n)
    void print_heap()
    {
        for(int i=0; i<nodes.size(); i++)
            cout<<nodes[i]<<" ";
        cout<<endl;
    }

    void Delete(int idx){
        if(idx >= nodes.size()){cout<<"Doesn't Exist"<<endl;return;}
        swap(nodes[idx], nodes[nodes.size()-1]);
        nodes.pop_back();
        down_heapify(idx);
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
//O (n log n)
vector<int> heap_sort(vector<int>temp)
{
    MaxHeap mp;
    mp.build_from_array(temp);
    vector<int>ans;

    for(int i=0; i<temp.size(); i++)
        ans.push_back(mp.ExtractMax());

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    MaxHeap heap;
    vector<int>input = {1, 2, 3, 4, 10, 9, 5, 7};
    heap.build_from_array(input);
    heap.print_heap();

    vector<int>sorted_input = heap_sort(input);

    for(int j=0; j<sorted_input.size(); j++)
        cout<<sorted_input[j]<<" ";
    cout<<endl;


    return 0;
}
