#include<bits/stdc++.h>
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
      if(b & 1)return (t * a) % m;
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
const ll sz = 3e+5 + 100;

//ie6 and 1e+6 (notice: no space) are same

int fact[sz], invfact[sz];

void pre_process(int n) {
    fact[0] = invfact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % mod2;
        invfact[i] = power(fact[i], mod2 - 2, mod2);
    }
}

int ncr(int n, int r) {
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    return fact[n] * invfact[r] % mod2 * invfact[n - r] % mod2;
}

void solve() {
    int n;
    cin >> n;
    pre_process(2 * n + 1);
    int a[sz];
    f(i, 0, 2 * n) cin >> a[i];
    stable_sort(a, a + 2 * n);
    int x = 0;
    f(i, 0, n) x = (x + abs(a[i] - a[n + i])) % mod2;
    cout << ncr(2 * n, n) * x % mod2;      
}

void pre_solve() {
  int t = 1;
  // cin >> t;
  fortestcase {
      // cout<<"Case #"<<tc<<": ";
      solve();
      cout << nl;
  }
}

int32_t main(int32_t argc, char** argv) {
//   fastio
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
