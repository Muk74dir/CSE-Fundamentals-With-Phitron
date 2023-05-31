#include<stdio.h>
void is_prime(int a, int b)
{
    for(int i=a; i<=b; i++){
        int cnt=1;
        for(int j=2; j*j<=i; j++){
            if(i%j==0){
                cnt = 0;
                break;
            }
        }
    if(cnt)printf("%d ", i);
    }
}

int main()
{
    int t, a, b;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &a, &b);
        is_prime(a, b);
        printf("\n");
    }
    return 0;
}
