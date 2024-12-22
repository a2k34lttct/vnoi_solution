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
struct node {
    int u, v, w;
};
int test, n, m, k, c[maxN], cnt_sub2, parent[maxN];
vector<pii> adj[maxN];
vector<node> a, g;
namespace sub1 {
    void solve() {
        cout << adj[1][0].ss << "\n";
    }
}
namespace sub2 {
    void make_set() {
        fto(i, 1, n) parent[i] = i;
    }
    int find(int a) {
        if (a == parent[a]) return a;
        return parent[a] = find(parent[a]);
    }
    int union_set(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return 0;
        parent[b] = a;
        return 1;
    }

    bool cmp(node a, node b) {
        if (a.u == b.u) {
            if (a.v == b.v) return a.w < b.w;
            return a.v < b.v;
        }
        return a.u < b.u;
    }
    bool cmp2(node a, node b) {
        return a.w < b.w;
    }
    void solve() {
        if (m < n - 1) cout << -1 << "\n";
        else {
            ll ans = 0;
            fto(i, 1, n) {
                for (auto v : adj[i]) {
                    if (i < v.ff) {
                        node tmp = {i, v.ff, v.ss};
                        a.pb(tmp);
                    }
                }
            }
            sort(a.begin(), a.end(), cmp);
            g.pb(a[0]);
            fto(i, 1, sz(a) - 1) {
                if (a[i].u == a[i-1].u && a[i].v == a[i-1].v) continue;
                g.pb(a[i]);
            }
            sort(g.begin(), g.end(), cmp2);
            make_set();
            for (auto e : g) {
                if (!union_set(e.u, e.v)) continue;
                ans += e.w;
            }
            cout << ans << "\n";
        }
    }
}
int main() {
    fastio;
    if (fopen("GRAPHZIP.inp", "r")) {
        freopen("GRAPHZIP.inp", "r", stdin);
        freopen("GRAPHZIP.out", "w", stdout);
    }
    cin >> test;
    while (test--) {
        cin >> n >> m >> k;
        fto(i, 1, n) {
            cin >> c[i];
            cnt_sub2 += (c[i] == i);
        }
        fto(i, 1, m) {
            int u, v, w; cin >> u >> v >> w;
            adj[u].pb({v, w});
            adj[v].pb({u, w});
        }
        if (n == 2 && m == 1) sub1::solve();
        else if (cnt_sub2 == n) sub2::solve();
        else cout << -1 << "\n";
    }
    return 0;
}

