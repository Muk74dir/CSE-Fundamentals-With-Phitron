#include<stdio.h>

int main()
{
    int i, j, n, k;
    scanf("%d %d", &n, &k);
    int arr[n+1];
    for(i=2, j=0; i<=n; i+=2, j++){
        printf("%d ",i);
        arr[j] = i;
    }
    for(i=1, j; i<=n; i+=2, j++){
        printf("%d ",i);
        arr[j] = i;
    }
    printf("\nThe %dth element in this sequence is %d.", k, arr[k-1]);

    return 0;
}
