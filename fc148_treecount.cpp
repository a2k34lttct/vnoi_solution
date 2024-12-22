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
int n, a[maxN], tin[maxN], tout[maxN], timer, tree[4*maxN], ans[maxN];
vector<int> adj[maxN], et;
vector<pii> quest;

void update(int node, int l, int r, int u, int v) {
    if (u > r || u < l) return;
    if (l == r) {
        if (u == l) tree[node]= v;
        return;
    }
    int mid = (l + r) >> 1;
    update(node*2, l, mid, u, v);
    update(node*2+1, mid+1, r, u, v);
    tree[node] = tree[node*2] + tree[node*2 + 1];
}
int query(int node, int l, int r, int u, int v) {
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return tree[node];
    int mid = (l + r) >> 1;
    return query(node*2, l, mid, u, v) + query(node*2+1, mid+1, r, u, v);
}

void euler_tour(int u, int p) {
    tin[u] = timer++;
    et.pb(u);
    for (int v : adj[u]) {
        if (v == p) continue;
        euler_tour(v, u);
    }
    tout[u] = timer;
    return;
}
int main() {
    fastio;
    if (fopen("fc148_treecount.inp", "r")) {
        freopen("fc148_treecount.inp", "r", stdin);
        freopen("fc148_treecount.out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, n) cin >> a[i];
    fto(i, 2, n) {
        int u; cin >> u;
        adj[u].pb(i);
        adj[i].pb(u);
    }
    timer = 1;
    euler_tour(1, 0);
    fto(i, 1, n) quest.pb({a[i], i});
    sort(quest.begin(), quest.end());
    fdto(i, sz(quest) - 1, 0) {
        pii x = quest[i];
        ans[x.ss] = query(1, 1, n, tin[x.ss], tout[x.ss] - 1);
        update(1, 1, n, tin[x.ss], 1);
    }
    fto(i, 1, n) cout << ans[i] << "\n";
    return 0;
}

