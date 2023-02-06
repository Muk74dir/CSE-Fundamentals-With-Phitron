#include<stdio.h>
#include<math.h>
int i, j;
void max_min_finder(int n, int arr[], int* p, int* q);
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int maxx, minn;
    max_min_finder(n, arr, &maxx, &minn);
    printf("%d %d", maxx, minn);
    return 0;
}
void max_min_finder(int n, int arr[], int* p, int *q)
{
    *p = arr[0];
    *q = arr[0];
    for(i=0; i<n; i++){
        if(arr[i] > *p)
            *p = arr[i];
        if(arr[i] < *q)
            *q = arr[i];
    }
}
