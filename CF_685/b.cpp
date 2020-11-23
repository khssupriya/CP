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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    while(q --) {
        int l, r;
        cin >> l >> r;
        l -= 1;
        r -= 1;
        int f = 0;
        for(int i = 0; i < l; i ++) {
            if(s[i] == s[l]) {
                f = 1;
            }
        }
        for(int i = s.length() - 1; i > r ; i --) {
            if(s[i] == s[r]) {
                f = 1;
            }
        }
        if(f) cout << "YES" << nl;
        else cout << "NO" << nl;
    }
}

void pre_solve() {
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++ tc) {
        // cout<<"Case #"<<tc<<": ";
        solve();
        // cout << nl;
    }
}

int32_t main(int32_t argc, char** argv) {
    IOS
    pre_solve();
    return 0;
}
