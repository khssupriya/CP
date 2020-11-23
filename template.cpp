#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define llu unsigned long long
#define ll long long
#define nl '\n'

const ll mod=1e9 + 7;
const ll mod2 = 998244353;

//--------------------------------------------

#define int long long
const ll sz = 1e6 + 100;

//1 2 3 4 5 6
int dp[sz];

int get(int n) {
    if(dp[n] != -1) {
        return dp[n];
    }
    if(n == 0) return 1;
    int sum = 0;
    for(int i = 1; i <= 6; i ++) {
        if(n >= i) sum = (sum + get(n - i)) % mod;
        else break;
    }
    return dp[n] = sum;
}


void solve() {
    int n;
    cin >> n;
    memset(dp, -1, (n + 1) * sizeof(int));
    cout << get(n);
}

void pre_solve() {
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++ tc) {
        // cout<<"Case #"<<tc<<": ";
        solve();
        cout << nl;
    }
}

int32_t main() {
    IOS
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    pre_solve();
    return 0;
}
