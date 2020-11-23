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
    string a, b;
    cin >> a >> b;
    int n = a.length();
    int c = 0;
    int f = 0;
    for(int i = 0; i < n ; i += 2) {
        if(a[i] == b[i] && f == 1) {
            c ++;
            f = 0;
        }
        if(a[i] != b[i]) f = 1;
    }
    if(f) c ++;
    f = 0;
    for(int i = 1; i < n ; i += 2) {
        if(a[i] == b[i] && f == 1) {
            c ++;
            f = 0;
        }
        if(a[i] != b[i]) f = 1;
    }
    if(f) c ++;
    cout << c;    
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
