#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define llu unsigned long long
#define ll long long
#define nl '\n'

const ll mod=1e9 + 7;
const ll mod2 = 998244353;

//-------------------------------------------------------------------------------------

#define int long long
const ll sz = 2e5 + 100;

void solve() {
    int n;
    cin >> n;
    if(n == 1) {
        cout << 0;
        return;
    }
    if(n == 2) {
        cout << 1;
        return;
    }
    if(n == 3) {
        cout << 2;
        return;
    }
    if(n&1) {
        cout << 3;
    } else {
        cout << 2;
    }
}

void pre_solve() {
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++ tc) {
        // cout<<"Case #"<<tc<<": ";
        solve();
        cout << nl;
    }
}

int32_t main(int32_t argc, char** argv) {
    IOS
    pre_solve();
    return 0;
}
