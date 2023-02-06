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

int winner (int mat[][4], int n)
{
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(mat[i][1] == mat[i][2] && mat[i][2] == mat[i][3] && mat[i][1] != -1)return 0;
            else if(mat[1][j] == mat[2][j] && mat[2][j] == mat[3][j] && mat[1][j] != -1)return 0;
            else if(mat[1][3] == mat[2][2] && mat[3][1] == mat[1][3] && mat[1][3] != -1)return 0;
            else if(mat[1][1] == mat[2][2] && mat[2][2] == mat[3][3] && mat[1][1] != -1)return 0;
        }
    }
    return -1;
}

int main()
{
    int n = 3, cnt;
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
        if(cnt==9){
            print_cell(mat, n);
            printf("\n\t\t!! NO WINNER \n \t\t PLAY AGAIN !!\n");
            break;
        }
        if(player1){
            Flag1:
            print_cell(mat, n);
            printf("Player #1 [ X ] - Enter Row & Column : ");
            scanf("%d %d", &r, &c);
            if(mat[r][c] == -1)mat[r][c] = 'X';
            else{
                printf("\n\t\t!! WRONG MOVE\n \t\t TRY AGAIN !!\n");
                goto Flag1;
            }
            printf("\n");
            if(winner(mat, n) == 0){
                print_cell(mat, n);
                printf("\n\t\t!! Player1 WON \n \t\t CONGRATULATION !!\n");
                break;
            }
            cnt++;
            player1 = false;
            player2 = true;
        }
        else{
            Flag2:
            print_cell(mat, n);
            printf("Player #2 [ O ] - Enter Row & Column : ");
            scanf("%d %d", &r, &c);
            if(mat[r][c] == -1)mat[r][c] = 'O';
            else{
                printf("\n\t\t!! WRONG MOVE\n \t\t TRY AGAIN !!\n");
                goto Flag2;
            }
            printf("\n");
            if(winner(mat, n)==0){
                print_cell(mat, n);
                printf("\n\t\t!! Player2 WON \n \t\t CONGRATULATION !!\n");
                break;
            }
            cnt++;
            player2 = false;
            player1 = true;
        }
    }
    return 0;
}
