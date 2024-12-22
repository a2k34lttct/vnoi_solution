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
const int maxN = 100005;
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, q, a[maxN], gt[maxN];
struct smt {
    vector<int> tree;
    smt(int n) {
        tree.resize(4*n, 0);
    }
    void update(int node, int l, int r, int u, int v) {
        if (u > r || u < l) return;
        if (l == r) {
            if (u == l) tree[node] = v;
            return;
        }
        int mid = (l + r) >> 1;
        update(node << 1, l, mid, u, v);
        update(node << 1 | 1, mid+1, r, u, v);
        tree[node] = tree[node << 1] + tree[node << 1 | 1];
    }
    int query(int node, int l, int r, int u, int v) {
        if (u > r || v < l) return 0;
        if (u <= l && r <= v) return tree[node];
        int mid = (l + r) >> 1;
        return query(node << 1, l, mid, u, v) + query(node << 1 | 1, mid+1, r, u, v);
    }
};
int C(int k, int n) {
    if (n < k) return 0;
    int res = 1;
    fto(i, n-k+1, n) res *= i;
    fto(i, 1, k) res /= i;
    return res;
}
signed main() {
    fastio;
    if (fopen("fc147_eventuples.inp", "r")) {
        freopen("fc147_eventuples.inp", "r", stdin);
        freopen("fc147_eventuples.out", "w", stdout);
    }
    cin >> n >> q;
    smt tree_even(n), tree_odd(n);
    fto(i, 1, n) {
        int x; cin >> x;
        if (x & 1) tree_odd.update(1, 1, n, i, 1);
        else tree_even.update(1, 1, n, i, 1);
    }
    while (q--) {
        int l, r; cin >> l >> r;
        int query_odd = tree_odd.query(1, 1, n, l, r);
        int query_even = tree_even.query(1, 1, n, l, r);
        cout << C(3, query_even) + (query_odd - 1) * query_odd / 2 * query_even << "\n";
    }
    return 0;
}

