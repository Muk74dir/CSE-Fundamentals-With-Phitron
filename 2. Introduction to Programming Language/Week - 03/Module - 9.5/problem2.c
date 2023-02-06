#include<stdio.h>
int main()
{
    int i, n, k, p, ad;
    scanf("%d", &n);
    int arr[n];
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);
    for(i=0; i<k; i++){
        scanf("%d %d", &p, &ad);
        arr[p] += ad;
    }
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
