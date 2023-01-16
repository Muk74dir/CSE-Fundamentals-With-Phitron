#include<stdio.h>
int main()
{
    int t, cnt=0;
    scanf("%d", &t);
    getchar();
    char s[t];
    int temp[26] = {0};
    for(int i=0; i<t; i++)
        scanf("%c", &s[i]);
    for(int j=0; j<t; j++){
        int ind = s[j] - 'a';
        temp[ind]++;
    }
    for(int k=0; k<26; k++)
        if(temp[k]==1)cnt++;
    printf("%d\n", cnt);
    return 0;

}
