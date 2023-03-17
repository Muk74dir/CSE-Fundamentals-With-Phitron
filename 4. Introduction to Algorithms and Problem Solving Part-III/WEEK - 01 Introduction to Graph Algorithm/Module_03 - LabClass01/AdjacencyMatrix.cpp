#include<bits/stdc++.h>
using namespace std;


/*
    Graph Representation
    ====================

    Topic : Adjacency Matrix [2D Array]

    0........1
            / \
           2...3

    # Total Node : 4
    # Total Edge : 4
    # Undirected + Unweighted

    Matrix  : Nodes * Nodes : 4x4

    Matrix[i][j] = 1 if(i->j has a edge)

    0->1
    1->0
    1->2
    2->1
    1->3
    3->1
    2->3
    3->2

            Time Complexity -> O(n^2) :::: Space Complexity -> O(n^2)
*/

int main()
{
    int nodes = 4; //O(1)
    int matrix[nodes][nodes]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //O(n^2)     :: O(n^2)


    //O(E) E -> Edge , E -> n^2 === O(n^2)
    // A ---- B
    // n ---- n
    // n x n = n^2
    //
    matrix[0][1] = 1; //O(1)
    matrix[1][0] = 1;

    matrix[1][2] = 1;
    /**/matrix[2][1] = 5 ; ///if Directed and Weighted

    matrix[1][3] = 1;
    matrix[3][1] = 1;

    matrix[2][3] = 1;
    matrix[3][2] = 1;

    for(int i=0; i<nodes; i++){     //O(n^2)
        for(int j=0; j<nodes; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}
