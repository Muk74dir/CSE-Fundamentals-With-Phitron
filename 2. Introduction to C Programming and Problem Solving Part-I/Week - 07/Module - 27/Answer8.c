#include<stdio.h>
int i, j;
void wrng_prs(int x, char s[]);
int main()
{
    char s[1000];
//    s[0] = '\0';
    scanf("%s", &s);
    int l = strlen(s);
    wrng_prs(l, s);
    return 0;
}
void wrng_prs(int x, char s[])
{
    for(i=0; i<x; i++){
        if((i+1)%2==0){
            printf("%c", s[i]);
            printf("%c", s[i]);
        }
        else
            printf("%c", s[i]);

    }
}
