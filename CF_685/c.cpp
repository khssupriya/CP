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
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ca[26] = {0}, cb[26] = {0};
    for(int i = 0; i < n; i ++) {
        ca[a[i] - 'a'] ++;
        cb[b[i] - 'a'] ++;
    }
    int f = 0;
    int mreq = 1000;
    for(int i = 0; i < 26; i ++) {
        if(ca[i] % k != cb[i] % k) {
            cout << "No";
            return;
        }
        if(ca[i] != cb[i]) {
            f = 1;
        }
        if(ca[i] < cb[i]) {
            mreq = min(mreq, i + 'a');
        }
    }
    if(!f) {
        cout << "Yes"; return;
    } 
    int c = 1;
    int mx = 0;
    for(int i = 1; i < n; i ++) {
        if(a[i] == a[i - 1]) {
            c ++;
            mx = max(mx, c);
        }
        else {
            c = 1;
        }
    }
    if(mx < k) {
        cout << "NO"; return;
    } 
    mx = 0;
    for(int i = 1; i < n; i ++) {
        if(b[i] == b[i - 1]) {
            c ++;
            mx = max(mx, c);
        }
        else {
            c = 1;
        }
    }
    if(mx < k) {
        cout << "NO"; return;
    } 
    c = 1;
    int mi = 1000;
    if(c == k) {
        mi = min(mi, (int)a[0]);
    }
    for(int i = 1; i < n; i ++) {
        if(a[i] == a[i - 1]) {
            c ++;
            if(c == k) {
                mi = min(mi, (int)a[i]);
            }
        }
        else c = 1;
    }
    if(mi < mreq) cout << "Yes";
    else cout << "No";    
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
