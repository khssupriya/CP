#include <iostream>
using namespace std;

const int MAXN = 1e6;
long long int dp[MAXN+1];

void solve()
{
    dp[2] = 1;
    dp[3] = 1;
    for(int i=4;i<=MAXN;i++){
        dp[i] = dp[i-2] + dp[i-3];
    }
}

int main(){
    int t;
    solve();
    while(t--)
    {
        int n;
        cin>>n;
        cout<<dp[n]<<endl;
    }
}