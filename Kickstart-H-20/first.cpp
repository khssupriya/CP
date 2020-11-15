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

int findy(int l, int r, int parity) {
    int count = 0;
    for(int i = l; i <= r; i ++) {
        if((i&1) == parity) {
            count ++;
        }
    }
    return count;
}

void solve() {
    string l, r;
    cin >> l >> r;
    int lc =  l.length();
    int rc = r.length();
    
    //make lenghts equal by adding 0s
    int diff = rc - lc;
    int off = diff;
    string str = "";
    while(diff --) str += "0";
    l = str + l;
    lc =  l.length();

    int pos = -1; //where we split into 3 parts
    for(int i = 0; i < lc; i ++) {
        if(l[i] == r[i]) { //only one num possible
            if((l[i] & 1) == ((i + 1) & 1)) {
                continue;
            } else {
                cout << 0;
                return;
            }
        } else { //important part when we have 3 parts
            pos = i;
            break;            
        }
    }


    if(pos == -1) { 
        cout << 0;
        return;
    }

    if(pos + 1 == lc) {
        cout << findy(l[lc - 1] - 48, r[rc - 1] - 48, lc & 1);
        return;
    }

    // [l[i], 9] - first part
    // [0, 9] - second part
    // [0, r[i]] - third part

    int c1 = 0;
    if((((l[pos] - 48)& 1) == ((pos + 1) & 1)) || l[pos] == '0') {
        c1 = 1;
        int f;
        if(l[pos] == '0') f = 1;
        else {
            f = ((pos + 1) & 1) ^ 1;
        }
        f(i, pos + 1, lc) {
            c1 *= findy(l[i] - 48, 9, f);
            f ^= 1;
            // cout << l[i] - 48 <<  (i + 1 + off) << " ";
        }
    }

    // cout << c1 << " ";

    int c2 = 0;
    for(int k = l[pos] - 48 + 1; k < r[pos] - 48; k ++) {
        if((k & 1) == (pos + 1) & 1) {
            int ct = 1;
            f(i, pos + 1, lc) {
                if(i == 0) {
                    ct *= findy(1, 9, (i + 1) & 1);
                } else {
                    ct *= findy(0, 9, (i + 1) & 1); 
                }       
            }
            c2 += ct;
        }
    }


    int c3 = 0;
    if(((r[pos] - 48)& 1) == ((pos + 1) & 1)) {
        c3 = 1;
        f(i, pos + 1, lc) {
            c3 *= findy(0, r[i] - 48, (i + 1) & 1);        
        }
    }

    // cout << c1 << " " << c2 << " " << c3 << " ";
    cout << c1 + c2 + c3;    
}

void pre_solve() {
    int t = 1;
    cin >> t;
    fortestcase {
        cout << "Case #" << tc << ": ";
        solve();
        cout << nl;
    }
}

int32_t main(int32_t argc, char** argv) {
    // fastio
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    pre_solve();

    // #ifndef ONLINE_JUDGE
    // freopen("../out.txt", "w", stdout);
    // //out.txt is where we get the log: SUCCESSFULLY deleted xyz.exe
    // thanos_snap(argv[0]);
    // #endif

    return 0;
}
