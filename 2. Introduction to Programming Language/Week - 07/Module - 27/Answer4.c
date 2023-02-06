#include <stdio.h>

void even_numbers(int x);

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        even_numbers(n/4);
    }
}

void even_numbers(int x)
{
    printf("%d %d %d %d\n", x-3, x-1, x+1, x+3);
}
