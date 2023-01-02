#include<stdio.h>
int main()
{
    int i=0, n, a=1, b=0, c=0;
    scanf("%d", &n);
    while(i<n){
        printf("%d ", c);// 0, 1, 1, 2, 3,
        c = a+b;//1, 1, 2, 3,
        a = b;//0, 1, 1, 2,
        b = c;//1, 1, 2, 3,
        i++;
    }




    return 0;
}
