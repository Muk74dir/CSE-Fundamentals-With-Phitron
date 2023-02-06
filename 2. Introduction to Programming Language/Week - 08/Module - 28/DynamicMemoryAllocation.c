#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int* ptr;
    ptr = (int*) malloc(n*sizeof(int)); // calloc(n, sizeof(int))
    for(int i=0; i<n; i++){
        scanf("%d", (ptr+i));
    }
    for(int j =0; j<n; j++){
        printf("%d", *(ptr+j));
    }

    ptr = realloc(ptr, (n+5)*sizeof(int));

    free(ptr);
    return 0;
}
