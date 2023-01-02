#include<stdio.h>
#include<math.h>
int i, j;
int counter(int n, int k, int x[])
{
    int ans=0;
    while(n--){
        if(x[i] != k)
            ans += 1;
    }
    return k;
}

int main()

{
    int n, k;
    scanf("%d", &n);
    int arr[n];
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);
    printf("%d", counter(n, k, arr));
    return 0;
}
