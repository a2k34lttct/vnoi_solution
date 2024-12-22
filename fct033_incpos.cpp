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
int n, q, a[maxN], tree[4*maxN], lazy[4*maxN], ans;
void push(int node, int l, int r) {
    if (!lazy[node]) return;
    tree[node] += (r - l + 1) * lazy[node];
    if (l != r) {
        lazy[node << 1] += lazy[node];
        lazy[node << 1 | 1] += lazy[node];
    }
    lazy[node] = 0;
}
void update(int node, int l, int r, int u, int v, int x) {
    push(node, l, r);
    if (u > r || v < l) return;
    if (u <= l && r <= v) {
        lazy[node] += x;
        push(node, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    update(node << 1, l, mid, u, v, x);
    update(node << 1 | 1, mid + 1, r, u, v, x);
    tree[node] = (tree[node << 1] + tree[node << 1 | 1]);
}
int query(int node, int l, int r, int u, int v) {
    push(node, l, r);
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return tree[node];
    int mid = (l + r) >> 1;
    return query(node << 1, l, mid, u, v) + query(node << 1 | 1, mid + 1, r, u, v);
}
signed main() {
    fastio;
    // if (fopen("fct033_incpos.inp", "r")) {
    //     freopen("fct033_incpos.inp", "r", stdin);
    //     freopen("fct033_incpos.out", "w", stdout);
    // }
    cin >> n >> q;
    fto(i, 1, n) cin >> a[i];
    fto(i, 1, n-1) ans += (a[i] > a[i+1]);
    fto(i, 1, n) update(1, 1, n, i, i, a[i]);
    while (q--) {
        int l, r, x; cin >> l >> r >> x;
        int q_1, q_2;
        if (l > 1) {
            q_1 = query(1, 1, n, l-1, l-1);
            q_2 = query(1, 1, n, l, l);
            if (q_1 > q_2 && q_1 <= q_2 + x) --ans;
            if (q_1 <= q_2 && q_1 > q_2 + x) ++ans;
        }
        if (r < n) {
            q_1 = query(1, 1, n, r, r);
            q_2 = query(1, 1, n, r+1, r+1);
            if (q_1 > q_2 && q_1 + x <= q_2) --ans;
            if (q_1 <= q_2 && q_1 + x > q_2) ++ans;
        }
        cout << ans << "\n";
        update(1, 1, n, l, r, x);
    }
    return 0;
}

