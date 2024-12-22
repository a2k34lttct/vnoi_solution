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

const int oo = 998244353;
const int maxN = 100005;
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, q, k, a[maxN], tree[4*maxN], lazy[4*maxN];
namespace sub1 {
    void init(int node, int l, int r) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        init(node*2, l, mid);
        init(node*2+1, mid+1, r);
        tree[node] = (tree[node*2] + tree[node*2 + 1]) % oo;
    }
    void push(int node, int l, int r) {
        if (lazy[node] == 0) return;
        tree[node] += (r - l + 1) * lazy[node];
        if (l != r) {
            lazy[2*node] = lazy[node];
            lazy[2*node+1] = lazy[node];
        }
        lazy[node] = 0;
        return;
    }
    void update(int node, int l, int r, int u, int v, int x) {
        push(node, l, r);
        if (u > r || v < l) return;
        if (u <= l && r <= v) {
            lazy[node] = x;
            push(node, l, r);
            return;
        }
        int mid = (l + r) >> 1;
        update(node*2, l, mid, u, v, x);
        update(node*2+1, mid+1, r, u, v, x);
        tree[node] = (tree[node*2] + tree[node*2+1]) % oo;
    }
    ll query(int node, int l, int r, int u, int v) {
        push(node, l, r);
        if (u > r || v < l) return 0;
        if (u <= l && r <= v) return tree[node];
        int mid = (l + r) >> 1;
        return (1LL*query(node*2, l, mid, u, v) + 1LL*query(node*2+1, mid+1, r, u, v)) % oo;
    }
    void solve() {
        init(1, 1, n);
        while (q--) {
            int type; cin >> type;
            if (type == 1) {
                int u, v, x; cin >> u >> v >> x;
                update(1, 1, n, u, v, x);
            }
            else {
                int u, v; cin >> u >> v;
                int ans = 0;
                fto(i, u, v) {
                    if (i + k > v) break;
                    ll current = query(1, 1, n, i, i);
                    ans = (ans + (current * query(1, 1, n, i + k, v)) % oo) % oo;
                }
                cout << ans << "\n";
            }
        }
    }
}
int main() {
    fastio;
    if (fopen("SUMPROD.inp", "r")) {
        freopen("SUMPROD.inp", "r", stdin);
        freopen("SUMPROD.out", "w", stdout);
    }
    cin >> n >> q >> k;
    fto(i, 1, n) cin >> a[i];
    if (n <= 10000 && q <= 10000) sub1::solve();
    return 0;
}

