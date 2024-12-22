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
int n, tin[maxN], sum[maxN], tout[maxN], sz[maxN], tree[4*maxN], lazy[4*maxN], timer, k;
ll s, a[maxN];
vector<int> adj[maxN], trace;
void dfs(int u, int p) {
    tin[u] = timer++;
    sum[u] = a[u];
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
        sum[u] += sum[v];
    }
    tout[u] = timer - 1;
    return;
}
void push(int node, int l, int r) {
    if (lazy[node] != 0) {
        tree[node] += (r - l + 1) * lazy[node];
        if (l != r) {
            lazy[2 * node] = lazy[node];
            lazy[2 * node + 1] = lazy[node];
        }
        lazy[node] = 0;
    }
}
int query(int node, int l, int r, int u, int v) {
    if (l > v || u > r || l > r || u > v) return 0;
    push(node, l, r);
    if (u <= l && r <= v) return tree[node];
    int mid = (l + r) >> 1;
    int q_1 = query(node*2, l, mid, u, v);
    int q_2 = query(node*2 + 1, mid + 1, r, u, v);
    return q_1 + q_2;
}
void update(int node, int l, int r, int u, int v, int x) {
    push(node, l, r);
    if (l > v || u > r || l > r || u > v) return;
    if (u <= l && r <= v) {
        lazy[node] = x;
        push(node, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    update(2 * node, l, mid, u, v, x);
    update(2 * node + 1, mid + 1, r, u, v, x);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
    return;
}
int cmp(int a, int b) {return sum[a] < sum[b];}
int main() {
    fastio;
    if (fopen("et13.inp", "r")) {
        freopen("et13.inp", "r", stdin);
        freopen("et13.out", "w", stdout);
    }
    cin >> n >> k;
    fto(i, 1, n) cin >> a[i], s += a[i];
    fto(i, 1, n-1) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    timer = 1;
    dfs(1, 0);
    fto(i, 1, n) trace.pb(i);
    sort(trace.begin(), trace.end(), cmp);
    int ans = -oo;
    for (int u : trace) {
        maximize(ans, s);
        if (k == 0 || query(1, 1, timer, tin[u], tin[u]) == -1) continue;
        if (sum[u] >= 0) break;
        s -= sum[u];
        k -= 1;
        update(1, 1, timer, tin[u], tout[u], -1);
    }
    cout << ans << "\n";
    return 0;
}