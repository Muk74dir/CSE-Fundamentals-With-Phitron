#include<bits/stdc++.h>
using namespace std;
/*
    Graph Representation
    ====================

    Topic : Adjacency List -> Linked List / C++ Vector

    0........1
            / \
           2...3

    # Total Node : 4
    # Total Edge : 4
    # Unweighted :

    [
        [0, 1]
        [1, 2]
        [1, 3]
        [2, 3]
    ]

    # Weighted :
    [
        [0, 1, 5(W)]
        [1, 2, 9]
        [1, 3, 4]
        [2, 3, 2]
    ]

        Time Complexity -> O(n^2) :::: Space Complexity -> O(n^2)
*/

int main()
{
    int nodes = 4;
    vector<vector<int>>edge_list;

    /*
        OR,
    vector<vector<int>>edge_list = {
        {0, 1},
        {1, 2},
        {1, 3},
        {2, 3}

    };
    */


    //Time : O(E) WorstCase : O(n^2), Space : O(E)
    // Unweighted
    edge_list.push_back({0, 1});
    edge_list.push_back({1, 2});
    edge_list.push_back({1, 3});
    edge_list.push_back({2, 3});


    for(int i=0; i<edge_list.size(); i++){
        cout<<"From : "<<edge_list[i][0]<<" TO : "<<edge_list[i][1]<<endl;
    }


    cout<<endl;
    cout<<endl;
    cout<<endl;


    // Weighted :
    vector<vector<int>>edge_list2 =
    {
        {0, 1, 6},
        {1, 2, 2},
        {1, 3, 9},
        {2, 3, 4}
    };

    for(int i=0; i<edge_list2.size(); i++){
        cout<<"From : "<<edge_list2[i][0]<<" TO : "<<edge_list2[i][1]<<" W. Value -> "<<edge_list2[i][2]<<endl;
    }

    return 0;
}
