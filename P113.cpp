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
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, m, f[25][(1 << 20) + 5];
vector<int> adj[25], path;
int dp(int i, int bit) {
    if (bit_count(bit) == n) return f[i][bit] = (i == n);
    if (f[i][bit] != -1) return f[i][bit];
    int res = 0;
    for (int v : adj[i]) {
        if (BIT(bit, v-1) == 0) maximize(res, dp(v, bit | MASK(v - 1)));
    }
    return f[i][bit] = res;
}
void backtrack(int u, int bit) {
    path.pb(u);
    if (bit_count(bit) == n) return;
    for (int v : adj[u]) {
        if (f[v][bit | MASK(v - 1)] == 1 && BIT(bit, v-1) == 0) {
            backtrack(v, bit | MASK(v - 1));
            return;
        }
    }
}
int main() {
    fastio;
    if (fopen("P113.inp", "r")) {
        freopen("P113.inp", "r", stdin);
        freopen("P113.out", "w", stdout);
    }
    cin >> n >> m;
    fto(i, 1, m) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    fto(i, 0, n) {
        fto(j, 0, (1 << 20) + 1) f[i][j] = -1;
    }
    int ans = dp(1, MASK(0));
    if (ans == 0) cout << -1 << "\n";
    else {
        fto(i, 1, n) sort(adj[i].begin(), adj[i].end());
        backtrack(1, MASK(0));
        for (int v : path) cout << v << " ";
    }
    return 0;
}