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
int n, a[maxN], tree[4*maxN], q;
int mex(int a, int b) {
    return a + b;
}
int query(int node, int l, int r, int u, int v) {
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return tree[node];
    int mid = (l + r) >> 1;
    int q_1 = query(node*2, l, mid, u, v);
    int q_2 = query(node*2 + 1, mid + 1, r, u, v);
    return mex(q_1, q_2);
}
void update(int node, int l, int r, int u, int x) {
    if (u > r || u < l) return;
    if (l == r) {
        if (u == l) tree[node] = x;
        return;
    }
    int mid = (l + r) >> 1;
    update(2 * node, l, mid, u, x);
    update(2 * node + 1, mid + 1, r, u, x);
    tree[node] = mex(tree[node * 2], tree[node * 2 + 1]);
    return;
}
signed main() {
    fastio;
    if (fopen("sqrt_a.inp", "r")) {
        freopen("sqrt_a.inp", "r", stdin);
        freopen("sqrt_a.out", "w", stdout);
    }
    cin >> n >> q;
    fto(i, 1, n) cin >> a[i], update(1, 1, n, i, a[i]);
    while (q--) {
        int type, u, v; cin >> type >> u >> v;
        if (type == 1) update(1, 1, n, u, v);
        else cout << query(1, 1, n, u, v) << "\n";
    }
    return 0;
}

