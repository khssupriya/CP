#include <stdio.h>
#include <conio.h>

int max(int a,int b)
{
    if(a>b)return a;
    return b;
}

int val[3] = {60, 100, 120};
int wt[3] = {10, 20, 30};

int brute_force(int w, int n) //generating all possible subsets
{
    if(n<0)return 0;
    return max(brute_force(w -wt[n],n-1), brute_force(w,n-1));
}

int dp[1000][1000];

int dp_force(int n, int w)
{
    for(int i=0;i<n;i++)
    {
        if(i >= wt[])
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<w;j++)
        {

        }
    }
}



int main()
{
    return 0;
}