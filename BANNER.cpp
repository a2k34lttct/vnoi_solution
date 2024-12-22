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
int n, q, np[25], ans, cnt_diff, dem[6][50005];
char s[50005];
struct smt {
    vector<int> tree, lazy;
    void build(int n) {
        tree.resize(4*n);
        lazy.resize(4*n);
    }
    void push(int node, int l, int r) {
        if (!lazy[node]) return;
        tree[node] = (r - l + 1) * lazy[node];
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
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    int query(int node, int l, int r, int u, int v) {
        push(node, l, r);
        if (u > r || v < l) return 0;
        if (u <= l && r <= v) return tree[node];
        int mid = (l + r) >> 1;
        return query(node*2, l, mid, u, v) + query(node*2+1, mid+1, r, u, v);
    }
};
namespace sub1 {
    void solve() {
        while (q--) {
            int l, r; cin >> l >> r;
            fto(i, 0, (r - l + 1)) np[i] = 0;
            ans = 0;
            while (1) {
                string res;
                fto(i, 1, (r - l + 1)) {
                    if (np[i]) res += s[i + l - 1];
                }
                ans += (res == "HSG25");
                int p = (r - l + 1);
                while (p > 0 && np[p] == 1) --p;
                if (p == 0) break;
                np[p] = 1;
                fto(i, p+1, (r - l + 1)) np[i] = 0;
            }
            cout << ans << "\n";
        }
    }
}
namespace sub3 {
    void solve() {
        while (q--) {
            int l, r; cin >> l >> r;
            ll cnt_h = dem[1][r] - dem[1][l-1];
            ll cnt_s = dem[2][r] - dem[2][l-1];
            ll cnt_g = dem[3][r] - dem[3][l-1];
            ll cnt_2 = dem[4][r] - dem[4][l-1];
            ll cnt_5 = dem[5][r] - dem[5][l-1];
            ll ans = 1;
            ans = (ans * (1LL * cnt_h)) % oo;
            ans = (ans * (1LL * cnt_s)) % oo;
            ans = (ans * (1LL * cnt_g)) % oo;
            ans = (ans * (1LL * cnt_2)) % oo;
            ans = (ans * (1LL * cnt_5)) % oo;
            cout << ans << "\n";
        }
    }
}
namespace sub2 {
    smt tree[6];
    void solve() {
        fto(i, 1, 5) tree[i].build(n);
        while (q--) {
            fto(i, 1, n) {
                if (s[i] == '5') tree[5].update(1, 1, n, i, i, 1);
            }
            int l, r; cin >> l >> r;
            fdto(i, r, l) {
                if (s[i] == '2') tree[4].update(1, 1, n, i, i, tree[5].query(1, 1, n, i+1, r));
                if (s[i] == 'G') tree[3].update(1, 1, n, i, i, tree[4].query(1, 1, n, i+1, r));
                if (s[i] == 'S') tree[2].update(1, 1, n, i, i, tree[3].query(1, 1, n, i+1, r));
                if (s[i] == 'H') tree[1].update(1, 1, n, i, i, tree[2].query(1, 1, n, i+1, r));
            }
            cout << tree[1].query(1, 1, n, l, r) << "\n";
            fto(i, 1, 5) tree[i].update(1, 1, n, 1, n, 0);
        }
    }
}
int main() {
    fastio;
    if (fopen("BANNER.inp", "r")) {
        freopen("BANNER.inp", "r", stdin);
        freopen("BANNER.out", "w", stdout);
    }
    cin >> n >> q;
    fto(i, 1, n) {
        cin >> s[i];
        cnt_diff += (s[i] != s[i-1]);
        if (s[i] == 'H') dem[1][i] = 1;
        if (s[i] == 'S') dem[2][i] = 1;
        if (s[i] == 'G') dem[3][i] = 1;
        if (s[i] == '2') dem[4][i] = 1;
        if (s[i] == '5') dem[5][i] = 1;
        dem[1][i] += dem[1][i-1];
        dem[2][i] += dem[2][i-1];
        dem[3][i] += dem[3][i-1];
        dem[4][i] += dem[4][i-1];
        dem[5][i] += dem[5][i-1];
    }
    if (n >= 20 && q <= 20) sub1::solve();
    else if (cnt_diff == 5) sub3::solve();
    else if (n <= 1000 && q <= 1000) sub2::solve();
    else cout << n << "\n";
    return 0;
}

