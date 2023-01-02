#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int c = n;
    int p = n;
    while (p >= 4){
        c += (p / 4);
        p = (p/4) + ( p % 4 );
    }
    printf("%d", c);

    getch();
}
