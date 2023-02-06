#include<stdio.h>
#include<math.h>

struct Points{
    int x;
    int y;
};
int main()
{
    struct Points p = {p.x = 4, p.y = 6};
    struct Points *padd;
    padd = &p;
    printf("%p\n", padd);
    printf("%d %d\n", padd->x, padd->y);
    printf("%d %d\n", p.x, p.y);
    return 0;
}
