#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int gcd(int a, int b);
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, cnt=0;
        scanf("%d", &n);
        int arr[n];
        for(int i=1; i<=n; i++)
            scanf("%d", &arr[i]);
        for(int i=1; i<=n-1; i++){
            for(int j=i+1; j<=n; j++){
                if(gcd(arr[i], arr[j])==1)
                    cnt++;
            }
        }
        printf("%d\n", cnt*2);
    }
    return 0;
}

int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b, a%b);
}
