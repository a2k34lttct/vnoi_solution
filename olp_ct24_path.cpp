/*Code by Hoang Thai*/
#include <bits/stdc++.h>

#define pb push_back
#define reverse(x) reverse(x.begin(), x.end())
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
#define int long long
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
const int maxN = 1000005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, m, k, ban[1005][1005], f[1005][1005], gt[2*maxN+10];
vector<pii> disable;
int lt(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return (a * lt(a, b-1)) % oo;
    int t = lt(a, b >> 1);
    return (t * t) % oo;
}
int count_ways(int i, int j, int l, int r) {
    return (gt[l + r - i - j] * lt((gt[l-i] * gt[r-j]) % oo, oo - 2)) % oo;
}
namespace sub1 {
    int dp(int i, int j) {
        if (ban[i][j]) return 0;
        if (i == n && j == m) return 1;
        if (f[i][j] != -1) return f[i][j];
        int res = 0;
        if (i + 1 <= n) res = (res + dp(i+1, j)) % oo;
        if (j + 1 <= m) res = (res + dp(i, j+1)) % oo;
        return f[i][j] = res;
    }
    void solve() {
        fto(i, 1, n) {
            fto(j, 1, m) f[i][j] = -1;
        }
        cout << dp(1, 1) << "\n";
    }
}
namespace sub3 {
    void solve() {
        cout << count_ways(1, 1, n, m) << "\n";
    }
}
namespace sub4 {
    void solve() {
        int ans = count_ways(1, 1, n, m);
        for (auto x : disable) {
            ans = (ans - max(count_ways(1, 1, x.ff, x.ss), count_ways(x.ff, x.ss, n, m)) + oo) % oo;
        }
        cout << ans << "\n";
    }
}
signed main() {
    fastio;
    if (fopen("olp_ct24_path.inp", "r")) {
        freopen("olp_ct24_path.inp", "r", stdin);
        freopen("olp_ct24_path.out", "w", stdout);
    }
    cin >> n >> m >> k;
    fto(i, 1, k) {
        int u, v; cin >> u >> v;
        ban[u][v] = 1;
        disable.pb({u, v});
    }
    if (ban[1][1] == 1) {
        cout << 0 << "\n";
        return 0;
    }
    if (n <= 1000 && m <= 1000) {
        sub1::solve();
        return 0;
    }
    gt[1] = 1;
    fto(i, 2, 2 * max(m, n) + 5) gt[i] = (gt[i-1] * i) % oo;
    if (k == 0) sub3::solve();
    else sub4::solve();
    return 0;
}
