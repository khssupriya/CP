#include "bits/stdc++.h"
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define setprs(x) cout << fixed << setprecision(x)
#define fortestcase for(int tc = 1; tc <= t; ++tc)
#define fs(i, s) for(ll i = 0; s[i]!='\0'; ++i)
#define fr(i, a, b) for(ll i = a; i >= b; --i)
#define f(i, a, b) for(ll i = a; i < b; ++i)
#define c1(x) __builtin_popcountll(x)
#define umi unordered_map<int, int>
#define umax(a, b) a = max(a, b)
#define umin(a, b) a = min(a, b)
#define llu unsigned long long
#define gcd(a,b) __gcd(a,b)
#define omi map<int, int>
#define eb emplace_back
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define sec second
#define fir first
#define nl '\n'

const ll mod=1e9 + 7;
const ll mod2 = 998244353;
const double PI =3.14159265;

const int MAX = INT_MAX;
const int MIN = INT_MIN;
const ll LL_MAX = LLONG_MAX;
const ll LL_MIN = LLONG_MIN;
const llu LLU_MAX = ULLONG_MAX;

void thanos_snap(string path) { //full path to the exe file
  string fname = ""; //file name without extension
  int j = 0;
  fr(i, path.length() - 1, 0) {
      if(path[i] == '\"')
          break;
      fname += path[i];
  }
  reverse(fname.begin(), fname.end());

  string command("Taskkill /F /IM " +  fname + ".exe && del " + fname + ".exe");
  //command to kill the running exe file and delete it

  system(&command[0]);
}

ll power(ll a, ll b, ll m = mod){
    if(b == 0)return 1;
    else if(b == 1)return a % m;
    else {
        ll t = power(a, b >> 1, m);
        t = (t * t) % m;
        if(b & 1) return (t * a) % m;
        else return t;
    }
} 

vector<int> primes;
void seives(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i <= n; i ++) {
        if(is_prime[i]) {
            for(int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    f(i, 1, n + 1) {
        if(is_prime[i]) {
            primes.eb(i);
        }
    }
}

//-------------CHECK CONSTRAINTS--------------------------
//-------------MULTI TESTS & GLOBALS----------------------

#define int long long
const ll sz = 2e5 + 100;

void solve() {
    int n, m;
    cin >> n >> m;
    char a[n + 1][m + 1];
    f(i, 0, n) f(j, 0, m) cin >> a[i][j];
    vector<vector<int>> v(3 * n * m + 1);
    int no = -1;
    // (m - 2) * (n - 2) matrix
    for(int i = 0;i < n - 2; i ++) for(int j = 0; j < m - 2; j ++) {
        if(a[i][j] == '1') {
            no ++;
            v[no].pb(i + 1);
            v[no].pb(j + 1);
            v[no].pb(i + 2);
            v[no].pb(j + 1);
            v[no].pb(i + 1);
            v[no].pb(j + 2);
            if(a[i][j] == '0') a[i][j] = '1';
            else a[i][j] = '0';
            if(a[i + 1][j] == '0') a[i + 1][j] = '1';
            else a[i + 1][j] = '0';
            if(a[i][j + 1] == '0') a[i][j + 1] = '1';
            else a[i][j + 1] = '0';
        }                
    }
    //last two rows
    for(int j = 0; j < m - 2; j ++) {
        if(a[n - 2][j] == '1' && a[n - 1][j] == '1') {
            no ++;
            v[no].pb(n - 2 + 1);
            v[no].pb(j + 1);
            v[no].pb(n - 1 + 1);
            v[no].pb(j + 1);
            v[no].pb(n - 2 + 1);
            v[no].pb(j + 1 + 1);
            if(a[n - 2][j] == '0') a[n - 2][j] = '1';
            else a[n - 2][j] = '0';
            if(a[n - 1][j] == '0') a[n - 1][j] = '1';
            else a[n - 1][j] = '0';
            if(a[n - 2][j + 1] == '0') a[n - 2][j + 1] = '1';
            else a[n - 2][j + 1] = '0';
        } else if(a[n - 2][j] == '1') {
            no ++;
            v[no].pb(n - 2 + 1);
            v[no].pb(j + 1);
            v[no].pb(n - 1 + 1);
            v[no].pb(j + 1 + 1);
            v[no].pb(n - 2 + 1);
            v[no].pb(j + 1 + 1);
            if(a[n - 2][j] == '0') a[n - 2][j] = '1';
            else a[n - 2][j] = '0';
            if(a[n - 1][j + 1] == '0') a[n - 1][j + 1] = '1';
            else a[n - 1][j + 1] = '0';
            if(a[n - 2][j + 1] == '0') a[n - 2][j + 1] = '1';
            else a[n - 2][j + 1] = '0';
        }else if(a[n - 1][j] == '1') {
            no ++;
            v[no].pb(n - 1 + 1);
            v[no].pb(j + 1);
            v[no].pb(n - 1 + 1);
            v[no].pb(j + 1 + 1);
            v[no].pb(n - 2 + 1);
            v[no].pb(j + 1 + 1);
            if(a[n - 1][j] == '0') a[n - 1][j] = '1';
            else a[n - 1][j] = '0';
            if(a[n- 1][j + 1] == '0') a[n - 1][j + 1] = '1';
            else a[n - 1][j + 1] = '0';
            if(a[n - 2][j + 1] == '0') a[n - 2][j + 1] = '1';
            else a[n - 2][j + 1] = '0';
        }
    }
    //last two cols
    for(int i = 0; i < n - 2; i ++) {
        if(a[i][m - 2] == '1' && a[i][m - 1] == '1') {
            no ++;
            v[no].pb(i + 1);
            v[no].pb(m - 2 + 1);
            v[no].pb(i + 1);
            v[no].pb(m - 1 + 1);
            v[no].pb(i + 1 + 1);
            v[no].pb(m - 1 + 1);
            if(a[i][m - 2] == '0') a[i][m - 2] = '1';
            else a[i][m - 2] = '0';
            if(a[i][m - 1] == '0') a[i][m - 1] = '1';
            else a[i][m - 1] = '0';
            if(a[i + 1][m - 1] == '0') a[i + 1][m - 1] = '1';
            else a[i + 1][m - 1] = '0';
        } else if(a[i][m - 2] == '1') {
            no ++;
            v[no].pb(i + 1);
            v[no].pb(m - 2 + 1);
            v[no].pb(i + 1 + 1);
            v[no].pb(m - 2 + 1);
            v[no].pb(i + 1 + 1);
            v[no].pb(m - 1 + 1);
            if(a[i][m - 2] == '0') a[i][m - 2] = '1';
            else a[i][m - 2] = '0';
            if(a[i + 1][m - 2] == '0') a[i + 1][m - 2] = '1';
            else a[i + 1][m - 2] = '0';
            if(a[i + 1][m - 1] == '0') a[i + 1][m - 1] = '1';
            else a[i + 1][m - 1] = '0';
        }else if(a[i][m - 1] == '1') {
            no ++;
            v[no].pb(i + 1);
            v[no].pb(m - 1 + 1);
            v[no].pb(i + 1 + 1);
            v[no].pb(m - 2 + 1);
            v[no].pb(i + 1 + 1);
            v[no].pb(m - 1 + 1);
            if(a[i][m - 1] == '0') a[i][m - 1] = '1';
            else a[i][m - 1] = '0';
            if(a[i + 1][m - 2] == '0') a[i + 1][m - 2] = '1';
            else a[i + 1][m - 2] = '0';
            if(a[i + 1][m - 1] == '0') a[i + 1][m - 1] = '1';
            else a[i + 1][m - 1] = '0';
        }
    }
    int i = n - 2;
    int j = m - 2;
    int one = 0;
    f(p, 0, 2) {
        f(q, 0, 2) {
            if(a[i + p][j + q] == '1') one ++;
        }
    }
    if(one != 0) {
        if(one == 4) {
            no ++;
            int count = 0;
            f(p, 0, 2) {
                f(q, 0, 2) {
                    int x = i + p, y = j + q;
                    if(a[x][y] == '1' && count < 3) {
                        count ++;
                        v[no].pb(x + 1);
                        v[no].pb(y + 1);  
                        a[x][y] = '0';                    
                    }
                }
            }
            one = 1;
        }
        if(one <= 2) {
            if(one == 1) {
                no ++;
                int count = 0;
                f(p, 0, 2) {
                    f(q, 0, 2) {
                        if(a[i + p][j + q] == '1') {
                            v[no].pb(i + p + 1);
                            v[no].pb(j + q + 1);  
                            a[i + p][j + q] = '0';                      
                        } else if(count < 2) {
                            count ++;
                            v[no].pb(i + p + 1);
                            v[no].pb(j + q + 1);
                            a[i + p][j + q] = '1'; 
                        }
                    }
                }
            }
            no ++;
            int count = 0;
            f(p, 0, 2) {
                f(q, 0, 2) {
                    if(a[i + p][j + q] == '0') {
                        v[no].pb(i + p + 1);
                        v[no].pb(j + q + 1); 
                        a[i + p][j + q] = '1';  
                        } else if(count < 1) {
                            count ++;
                        v[no].pb(i + p + 1);
                        v[no].pb(j + q + 1); 
                        a[i + p][j + q] = '0'; 
                        }
                }
            }
        }
        no ++;
        f(p, 0, 2) {
            f(q, 0, 2) {
                int x = i + p, y = j + q;
                if(a[x][y] == '1') {
                    v[no].pb(x + 1);
                    v[no].pb(y + 1);  
                    a[x][y] = '0';                    
                }
            }
        }
    }
    cout << no + 1 << nl;
    f(i, 0, no + 1) {
        for(int x : v[i]) {
            cout << x << " ";
        }
        cout <<nl;
    }
}

void pre_solve() {
    int t = 1;
    cin >> t;
    fortestcase {
        // cout<<"Case #"<<tc<<": ";
        solve();
        // cout << nl;
    }
}

int32_t main(int32_t argc, char** argv) {
    // fastio
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    pre_solve();

    #ifndef ONLINE_JUDGE
    freopen("../out.txt", "w", stdout);
    //out.txt is where we get the log: SUCCESSFULLY deleted xyz.exe
    thanos_snap(argv[0]);
    #endif

    return 0;
}
