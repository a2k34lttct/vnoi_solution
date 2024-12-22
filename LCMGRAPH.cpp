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
int n, k, a[maxN], np[10], dis[10][10], parent[maxN], num;
vector<int> b;
struct node {
    int u, v, w;
};
namespace sub1 {
    bool cmp(node a, node b) {return a.w < b.w;}
    void make_set() {
        fto(i, 1, n) parent[i] = i;
    }
    int find_set(int u) {
        return (u == parent[u] ? u : parent[u] = find_set(parent[u]));
    }
    int union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            parent[b] = a;
            return 1;
        }
        return 0;
    }
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }
    void solve() {
        ll ans = 1e18;
        sort(b.begin(), b.end());
        fto(i, 1, n) {
            fto(j, 1, n) {
                int l = min(i, j);
                int r = max(i, j);
                int _lcm = a[l];
                fto(k, l, r) _lcm = lcm(_lcm, a[k]);
                dis[i][j] = _lcm;
            }
        }
        string kq;
        while (1) {
            make_set();
            vector<int> add;
            vector<node> g;
            int p_b = 0;
            int cnt = 0;
            fto(i, 1, n) {
                if (np[i]) add.pb(i), p_b += (i == b[p_b]);
            }
            if (p_b >= k) {
                g.clear();
                fto(i, 0, sz(add) - 1) {
                    fto(j, 0, sz(add) - 1) {
                        if (i == j) continue;
                        if (add[i] > add[j]) continue;
                        node tmp = {add[i], add[j], dis[add[i]][add[j]]};
                        g.pb(tmp);
                    }
                }
                sort(g.begin(), g.end(), cmp);
                ll res = 0;
                string ret = "";
                for (auto e : g) {
                    if (union_set(e.u, e.v)) {
                        res += e.w;
                        ++cnt;
                        ret += (e.u + '0');
                        ret += " ";
                        ret += e.v + '0';
                        ret += "\n";
                    }
                }
                if (ans > res) {
                    ans = res;
                    num = cnt;
                    kq = ret;
                }
            }
            int p = n;
            while (p > 0 && np[p] == 1) --p;
            if (p == 0) break;
            np[p] = 1;
            fto(i, p+1, n) np[i] = 0;
        }
        cout << ans << "\n";
        cout << num << "\n";
        cout << kq << "\n";
    }
}
int main() {
    fastio;
    if (fopen("LCMGRAPH.inp", "r")) {
        freopen("LCMGRAPH.inp", "r", stdin);
        freopen("LCMGRAPH.out", "w", stdout);
    }
    cin >> n >> k;
    fto(i, 1, n) cin >> a[i];
    fto(i, 1, k) {
        int u; cin >> u;
        b.pb(u);
    }
    if (n <= 10) sub1::solve();
    else if (n <= 200) sub2::solve();
    return 0;
}