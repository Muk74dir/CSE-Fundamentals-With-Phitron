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
