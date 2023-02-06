#include<stdio.h>
int main()
{
    int i, j, n, arr[500];
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    for(i=0; i<n; i++){
        printf("%d - ", i+1);
        for(j=0; j<n; j++){
            if(i != j){
                printf("%d ", arr[j]);
            }
        }
        printf("\n");
    }

    return 0;
}
