#include<stdio.h>
#include<math.h>
struct Points{
    float x;
    float y;
};

struct Triangle{
    struct Points A;
    struct Points B;
    struct Points C;
};

struct Points centroid (struct Triangle t)
{
    struct Points ans;
    ans.x = (t.A.x+t.B.x+t.C.x)/3;
    ans.y = (t.A.y+t.B.y+t.C.y)/3;
    return ans;
}

int main()
{
    struct Points a= {2, 3}, b = {3, 4}, c = {4, 5};
    struct Triangle t = {a, b, c};
    struct Points answer = centroid(t);
    printf("Answer is = (%.2f, %.2f)", answer.x, answer.y);
    return 0;
}
