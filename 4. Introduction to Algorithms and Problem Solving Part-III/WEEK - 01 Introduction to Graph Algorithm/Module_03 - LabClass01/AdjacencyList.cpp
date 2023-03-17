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
    # Undirected + Unweighted

    Undirected:
    0 -> 1
    1 -> 0, 2, 3
    2 -> 1, 3
    3 -> 1, 2

    Directed :
      5
    0-->1  ::=   0 = {1, 5}

      2
    1-->2

      8
    2-->3

      9
    3-->1
        Time Complexity -> O(n^2) :::: Space Complexity -> O(n^2)
*/

int main()
{
    int nodes = 4;
    vector<int>adj_list[nodes];//O(n) //vector<pair>adj_list[nodes] for weighted

    //O(E * 2)  = O(E),  Worst Case : O(n^2)
    adj_list[0] = {1}; // O(1)
    adj_list[1] = {0, 2, 3};
    adj_list[2] = {1, 3};
    adj_list[3] = {1, 2};


    /* adj_list[3] = {1, 9} , {1, 2} // Pairwise, Directed + Weighted value (x, y)
     adj_list[3].push_back({1, 2});
     */


    //O(E * 2)  = O(E),  Worst Case : O(n^2)
    for(int i=0; i<nodes; i++){
        cout<<i<<" --> ";
        for(int j=0; j<adj_list[i].size(); j++){
            cout<<adj_list[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<endl;
    cout<<endl;

    vector<pair<int, int>>adj_list2[nodes];

    /*
    Directed :
      5
    0-->1  ::=   0 = {1, 5}

      2
    1-->2

      8
    2-->3

      9
    3-->1
      6
    3 -- 2
    */

    adj_list2[0].push_back({1, 5}); // (y, w) 0 to y with weighted value
    adj_list2[1].push_back({2, 2});
    adj_list2[2].push_back({3, 8});
    adj_list2[3] = {{2, 6}, {1, 9}};
    adj_list2[3].push_back({1, 9});

    for(int i=0; i<nodes; i++){
        cout<<i<<" --> ";
        for(int j=0; j<adj_list2[i].size(); j++){
            cout<<"TO "<<adj_list2[i][j].first<<" with value-> "<<adj_list2[i][j].second<<" ";
        }
        cout<<endl;
    }

    return 0;
}
