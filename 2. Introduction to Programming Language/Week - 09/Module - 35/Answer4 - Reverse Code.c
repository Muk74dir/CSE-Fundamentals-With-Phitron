#include<stdio.h>
#include<stdbool.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        while(true){
            int alp;
            alp = n%10;
            n /= 10;
            if(alp == 0) break;
            printf("%c",64+alp);
        }
        printf("\n");

    }
    return 0;
}
