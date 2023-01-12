#include<stdio.h>
#include<stdbool.h>

void print_cell(int mat[][4], int n)
{
    printf("\n");
    for(int i=1; i<= n; i++){
        for(int j=1; j<=n; j++){
            if(mat[i][j] == 'X') mat[i][j] = 'X';
            if(mat[i][j] == 'O') mat[i][j] = 'O';
            printf("\t%c\t", mat[i][j]);
            if(j!=n)printf("|");
        }
        if(i!=n) printf("\n________________________________________________");
        printf("\n\n");
    }
}

int main()
{
    int n = 3;
    int mat[4][4];
    for(int i=1; i<= n; i++){
        for(int j=1; j<=n; j++){
            mat[i][j] = -1;
        }
    }
    bool player1 = true;
    bool player2 = false;

    while(true){
        int r, c;
        if(player1){
            print_cell(mat, n);
            printf("Player #1 [ X ] - Enter Row & Column : ");
            scanf("%d %d", &r, &c);
            mat[r][c] = 'X';
            printf("\n");
            player1 = false;
            player2 = true;
        }
        else{
            print_cell(mat, n);
            printf("Player #2 [ O ] - Enter Row & Column : ");
            scanf("%d %d", &r, &c);
            mat[r][c] = 'O';
            player2 = false;
            player1 = true;
        }
    }
    return 0;
}
