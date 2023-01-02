#include<stdio.h>
#include<math.h>
int i, j;

void nto1(int x);

int main()
{
    int n;
    scanf("%d", &n);
    nto1(n);
    return 0;
}

void nto1(int x)
{
    if(x>0){
        printf("%d ", x);
        nto1(x-1);
    }
}
