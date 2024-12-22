/*Code by Hoang Thai*/
#include <bits/stdc++.h>

#define pb push_back
#define ff first
#define ss second
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define bit_count(x) __builtin_popcount(x)
#define bit_countll(x) __builtin_popcountll(x)

#define fto(i, a, b) for (int i = (int) a; i <= (int) b; ++i)
#define fdto(i, a, b) for (int i = (int) a; i >= (int) b; --i)

#define pii pair<int, int>
#define pq priority_queue<pii, vector<pii>, greater<pii>>
#define ll long long
#define db double

#define sz(a) (int) a.size()

#define mem(x, a) memset(x, a, sizeof x)
#define rem(a, x) a.resize(x+1);


#define yes "YES"
#define no "NO"

#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

const int oo = 1000000007;
const int maxN = 100005;
const int INF = 10000000;
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User

bool maximize(ll &a, ll b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
long long n, k, ans, f[3][2701];
bool prime[10000001];
int start;
vector<int> num;
long long dp(int i, int r) {
    if (i == 3) return (r == 0 ? 1 : -INF);
    if (f[i][r] != -1) return f[i][r];
    ll res = 1;
    ll prod = 0;
    fto(j, 1, r) {
        if (prod == 0) prod = num[i];
        else prod *= num[i];
        if (prod > n) break;
        ll tmp = prod * dp(i+1, r - j);
        if (i != 0) {
            if (tmp <= n) maximize(res, tmp);
        }
        else {
            if (tmp == n) maximize(res, tmp);
        }
    }
    return f[i][r] = res;
}
int main() {
    fastio;
//    if (fopen("olp_kc24_prime.inp", "r")) {
//        freopen("olp_kc24_prime.inp", "r", stdin);
//        freopen("olp_kc24_prime.out", "w", stdout);
//    }
    cin >> n >> k;
    fto(i, 2, INF) prime[i] = 1;
    fto(i, 2, INF) {
        if (prime[i]) {
            for (int j = i*2; j <= INF; j += i) prime[j] = 0;
        }
    }
    fto(i, 2, INF) {
        if (prime[i]) num.pb(i);
    }
    while (sz(num) >= 3) {
        if (num[0] > n) break;
        mem(f, -1);
        maximize(ans, dp(0, k));
        num.erase(num.begin());
    }
    cout << ans << "\n";
    return 0;
}

