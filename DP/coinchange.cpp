#include <stdio.h>
#include <conio.h>

int max(int a,int b)
{
    if(a>b)return a;
    return b;
}

int brute_force(int w, int n)
{
    if(n<0)return 0;
    return max(brute_force(w -n, n-1), brute_force(w, n-1));
}
int main()
{
    int w=5,n=3;
    printf("%d",brute_force(w, n));
    return 0;
}