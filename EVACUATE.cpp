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
int n, m, a[maxN], ans, query[maxN], largest[maxN], sz[maxN], parent[maxN];
pii edges[maxN];
int find_set(int u) {
    return (u == parent[u] ? u : parent[u] = find_set(parent[u]));
}
int union_set(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u != v) {
        sz[u] += sz[v];
        parent[v] = u;
        maximize(largest[u], largest[v]);
        return 1;
    }
    return 0;
}
signed main() {
    fastio;
    if (fopen("EVACUATE.inp", "r")) {
        freopen("EVACUATE.inp", "r", stdin);
        freopen("EVACUATE.out", "w", stdout);
    }
    cin >> n >> m;
    fto(i, 1, n) cin >> a[i], ans += a[i];
    fto(i, 1, m) cin >> edges[i].ff >> edges[i].ss;
    fto(i, 1, n) {
        largest[i] = a[i];
        sz[i] = 1;
        parent[i] = i;
    }
    fdto(i, m, 1) {
        query[i] = ans;
        int u = edges[i].ff;
        int v = edges[i].ss;
        ans -= largest[find_set(u)] * sz[find_set(u)];
        ans -= largest[find_set(v)] * sz[find_set(v)];
        if (union_set(edges[i].ff, edges[i].ss)) ans += largest[find_set(u)] * sz[find_set(u)];
        else {
            ans += largest[find_set(u)] * sz[find_set(u)];
            ans += largest[find_set(v)] * sz[find_set(v)];
        }
    }
    fto(i, 1, m) cout << query[i] << "\n";
    return 0;
}

