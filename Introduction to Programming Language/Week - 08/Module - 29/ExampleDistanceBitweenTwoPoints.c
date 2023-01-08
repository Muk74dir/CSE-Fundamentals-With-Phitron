#include<stdio.h>
#include<math.h>

struct Points{

    int x;
    int y;

};

double distance(struct Points p, struct Points q)
{
    return sqrt(pow(p.x-q.x,2) + pow(p.y-q.y,2));
}

int main()
{
    struct Points p1, p2;
    scanf("%d %d", &p1.x, &p1.y);
    scanf("%d %d", &p2.x, &p2.y);
    printf("Distance --- > %lf", distance(p1, p2));
    return 0;
}
