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
const int maxN = 300005;
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};

int n, q, timer, tin[maxN], tout[maxN];
double tree[4*maxN];
vector<int> adj[maxN];

void dfs(int u, int p) {
    tin[u] = timer++;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    tout[u] = timer - 1;
}

void update(int node, int l, int r, int u, double v) {
    if (u > r || u < l) return;
    if (l == r) {
        if (u == l) tree[node] = v;
        return;
    }
    int mid = (l + r) >> 1;
    update(node << 1, l, mid, u, v);
    update(node << 1 | 1, mid + 1, r, u, v);
    tree[node] = (tree[node << 1] + tree[node << 1 | 1]);
}

double query(int node, int l, int r, int u, int v) {
    if (u > r|| v < l) return 0;
    if (u <= l && r <= v) return tree[node];
    int mid = (l + r) >> 1;
    return query(node << 1, l, mid, u, v) + query(node << 1 | 1, mid + 1, r, u, v);
}

int main() {
    fastio;
    if (fopen("secondthread_tree_richtree.inp", "r")) {
        freopen("secondthread_tree_richtree.inp", "r", stdin);
        freopen("secondthread_tree_richtree.out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, n - 1) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if (n == 1) return 0;
    timer = 1;
    dfs(1, 0);
    cin >> q;
    while (q--) {
        int t, x, y; cin >> t >> x >> y;
        if (t == 1) update(1, 1, timer, tin[x], log10(y));
        else {
            double q_x = query(1, 1, timer, tin[x], tout[x]);
            double q_y = query(1, 1, timer, tin[y], tout[y]);
            if (q_x - q_y <= 9.0) cout << fixed << setprecision(7) << pow(10, q_x - q_y) << "\n";
            else cout << 1000000000 << "\n";
        }
    }
    return 0;
}

