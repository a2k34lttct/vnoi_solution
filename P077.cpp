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
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, m, a, b, matcha[maxN], matchb[maxN], vis[maxN], ans;
vector<int> adj[maxN];
int dfs(int u) {
    for (int v : adj[u]) {
        if (!vis[v]) {
            vis[v] = 1;
            if (!matchb[v] || dfs(matchb[v])) {
                matcha[u] = v;
                matchb[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    fastio;
    if (fopen("P077.inp", "r")) {
        freopen("P077.inp", "r", stdin);
        freopen("P077.out", "w", stdout);
    }
    cin >> n >> m >> a >> b;
    bool ok = false;
    fdto(i, b, a) {
        if (n % i == 0) {
            ok = true;
            cout << (n / i) << "\n";
            break;
        }
    }
    if (!ok) cout << -1 << "\n";
    fto(u, 1, n) {
        int k; cin >> k;
        fto(i, 1, k) {
            int v; cin >> v;
            adj[u].pb(v);
        }
    }
    fto(i, 1, n) {
        mem(vis, 0);
        if (dfs(i)) ++ans;
    }
    cout << ans << "\n";
return 0;
}

