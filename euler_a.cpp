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
const int maxN = 200005;
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};

int n, q, timer, a[maxN], depth[maxN], tin[maxN], head[maxN], heavy[maxN], sz[maxN], parent[maxN], tree[4*maxN];
vector<int> adj[maxN];

void update(int node, int l, int r, int u, int v) {
    if (u > r || u < l) return;
    if (l == r) {
        if (u == l) tree[node] = v;
        return;
    }
    int mid = (l + r) >> 1;
    update(node*2, l, mid, u, v);
    update(node*2+1, mid+1, r, u, v);
    tree[node] = tree[node*2] + tree[node*2+1];
    return;
}

int query(int node, int l, int r, int u, int v) {
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return tree[node];
    int mid = (l + r) >> 1;
    return query(node*2, l, mid, u, v) + query(node*2+1, mid+1, r, u, v);
}

void dfs_hld(int u, int p) {
    tin[u] = ++timer;
    head[u] = p;
    if (heavy[u]) dfs_hld(heavy[u], p);
    for (int v : adj[u]) {
        if (v == parent[u] || v == heavy[u]) continue;
        dfs_hld(v, v);
    }
    return;
}

void dfs_sz(int u, int p) {
    sz[u] = 1;
    depth[u] = depth[p] + 1;
    parent[u] = p;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs_sz(v, u);
        sz[u] += sz[v];
        if (!heavy[u] || sz[heavy[u]] < sz[v]) heavy[u] = v;
    }
    return;
}


signed main() {
    fastio;
    if (fopen("euler_a.inp", "r")) {
        freopen("euler_a.inp", "r", stdin);
        freopen("euler_a.out", "w", stdout);
    }
    cin >> n >> q;
    fto(i, 1, n) cin >> a[i];
    fto(i, 1, n-1) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs_sz(1, 0);
    dfs_hld(1, 0);
    fto(i, 1, n) update(1, 1, n, tin[i], a[i]);
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int s, x; cin >> s >> x;
            update(1, 1, n, tin[s], x);
        }
        else {
            int u; cin >> u;
            cout << query(1, 1, n, tin[u], tin[u] + sz[u] - 1) << "\n";
        }
    }
    return 0;
}

