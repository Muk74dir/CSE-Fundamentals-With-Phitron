#include<stdio.h>
#include<stdbool.h>
int main()
{
    int n;
    bool tgl = true;
    char c;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            printf(" ");
        }
        if(tgl)c ='^';
        else c = '*';
        for(int k=0; k<2*i-1; k++){
            printf("%c", c);
        }
        if(tgl)tgl=false;
        else tgl = true;
        printf("\n");
    }
    return 0;
}
