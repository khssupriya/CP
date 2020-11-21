#include <bits/stdc++>
#include <stdio.h>
using namespace std;
#define ll long long int

//naive-approach...
ll max_value(ll n){
    if(n == 0)return 0LL;
    ll k = max_value(n/2) + max_value(n/3) + max_value(n/4);
    return max(n,k);
}

unordered_map<ll, ll> val;
unordered_map<ll, ll> vis;

//Memoisation approach :)
ll Max_value(ll n)
{
    if(n==0)
        return 0LL;
    if(vis[n]==0)
    {
        ll k = Max_value(n/2) + Max_value(n/3) + Max_Value(n/4);
        val[n] = max(n,k);
        vis[n] = 1;
    }
    return val[n];
}


int main(){
    ll n;
    while(scanf("%lld",&n)!=0)
    {
        cout<<Max_value(n);
    }
}