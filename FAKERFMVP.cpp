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
const int maxN = 200005;
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int Test, n, m, p, ans, vis[maxN], ok;
vector<int> adj[maxN];
namespace sub123 {
    void dfs(int u, int p) {
        vis[u] += 1;
        for (int v : adj[u]) {
            if (v == p) continue;
            if (vis[v] == 2) {
                ok = -1;
                return;
            }
            dfs(v, u);
        }
    }
    int dfs_ans(int u, int p) {
        int res = 0;
        for (int v : adj[u]) {
            if (v == p) continue;
            maximize(res, dfs_ans(v, u) + 1);
        }
        return res;
    }
    void solve() {
        ans = 0;
        fto(i, 1, n) {
            fto(j, 1, n) vis[j] = 0;
            ok = 0;
            dfs(i, 0);
            if (ok == -1) {
                cout << -1 << "\n";
                return;
            }
        }
        fto(i, 1, n) maximize(ans, dfs_ans(i, 0));
        cout << ans << "\n";
    }
}
namespace sub45 {
    void dfs(int u, int p) {
        vis[u] += 1;
        for (int v : adj[u]) {
            if (v != p) {
                if (vis[v] == 2) {
                    ok = -1;
                    return;
                }
                dfs(v, u);
            }
        }
    }
    int dfs_ans(int u, int p) {
        int res = 0;
        for (int v : adj[u]) {
            if (v == p) continue;
            maximize(res, dfs_ans(v, u) + 1);
        }
        return res;
    }
    void dfs_direct(int u) {
        vis[u] = 1;
        for(int v : adj[u]) {
            if (vis[v] == 0) dfs_direct(v);
            else if (vis[v] == 1) ok = -1;
        }
        vis[u] = 2;
    }
    void solve() {
        fto(i, 1, n) vis[i] = 0;
        ok = 0;
        ans = 0;
        if (p == 0) dfs(1, 0);
        else if (m == 0) dfs_direct(1);
        if (ok == -1) cout << -1 << "\n";
        else {
            fto(i, 1, n) vis[i] = 0;
            fto(i, 1, n) {
                if (p == 0) {
                    if (sz(adj[i]) == 1) {
                        maximize(ans, dfs_ans(i, 0));
                    }
                }
                if (m == 0) maximize(ans, dfs_ans(i, 0));
            }
            cout << ans << "\n";
        }
    }
}
int main() {
    fastio;
    freopen("FAKERFMVP.inp", "r", stdin);
    freopen("FAKERFMVP.out", "w", stdout);
    cin >> Test;
    fto(test, 1, Test) {
        cin >> n >> m >> p;
        fto(i, 1, n) adj[i].clear();
        fto(i, 1, m) {
            int u, v; cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        fto(i, 1, p) {
            int u, v; cin >> u >> v;
            adj[u].pb(v);
        }
        if (m == 0 && p == 0) cout << 0 << "\n";
        else if (p == 0|| m == 0) sub45::solve();
        else if (n <= 1000 && m <= 1000 && p <= 1000) sub123::solve();
    }
    return 0;
}

