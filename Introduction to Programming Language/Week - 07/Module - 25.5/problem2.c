#include<stdio.h>
#include<math.h>
int i, j;

int largest(int n, int k, int x[]);
int smallest(int n, int k, int x[]);

int main()
{
    int n, k;
    scanf("%d", &n);
    int arr[n];
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);
    printf("%dth smallest element = %d", k, smallest(n, k, arr));
    printf("%dth largest element = %d\n", k, largest(n, k, arr));
    return 0;
}

int largest(int n, int k, int x[])
{
    int i=0, j=0, temp, ind=0, val;
    for(i=0; i<n-1; i++){
        val = x[i];
        for(j=i+1; j<n; j++){
            if(val > x[j]){
                ind = j;
                temp = val;
                val = x[j];
            }
            else
                continue;
            x[i] = val;
            x[ind] = temp;
        }
    }
    return x[k-1];
}

int smallest(int n, int k, int x[])
{
    int i=0, j=0, temp, ind=0, val;
    for(i=0; i<n-1; i++){
        val = x[i];
        for(j=i+1; j<n; j++){
            if(val < x[j]){
                ind = j;
                temp = val;
                val = x[j];
            }
            else
                continue;
            x[i] = val;
            x[ind] = temp;
        }
    }
    return x[k-1];

}
