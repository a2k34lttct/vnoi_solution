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
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(ll &a, ll b) {return (a > b ? (a = b) : 0);};
int n, m, vis[maxN];
ll ans, mn, a[maxN];
vector<int> adj[maxN];
void dfs(int u) {
    vis[u] = 1;
    minimize(mn, a[u]);
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
}
int main() {
    fastio;
    if (fopen("fct025_library.inp", "r")) {
        freopen("fct025_library.inp", "r", stdin);
        freopen("fct025_library.out", "w", stdout);
    }
    cin >> n >> m;
    fto(i, 1, n) cin >> a[i];
    fto(i, 1, m) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    fto(i, 1, n) {
        if (!vis[i]) {
            mn = 1e18;
            dfs(i);
            ans += mn;
        }
    }
    cout << ans << "\n";
    return 0;
}

