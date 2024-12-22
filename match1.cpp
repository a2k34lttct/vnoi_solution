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
const int maxN = 305;
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, m, vis[maxN], matcha[maxN], matchb[maxN], ans;
vector<int> adj[maxN];
int dfs(int u) {
    if (!vis[u]) return 0;
    vis[u] = 1;
    for (int v : adj[u]) {
        if (!matchb[v] || dfs(matchb[v])) {
            matcha[u] = v ;
            matchb[v] = u;
            return 1;
        }
    }
    return 0;
}
int main() {
    fastio;
    if (fopen("match1.inp", "r")) {
        freopen("match1.inp", "r", stdin);
        freopen("match1.out", "w", stdout);
    }
    cin >> n >> m;
    int u, v;
    while (cin >> u >> v){
        adj[u].pb(v);
    }
    fto(i, 1, n) {
        mem(vis, 0);
        if (dfs(i)) ++ans;
    }
    cout << ans << "\n";
    fto(i, 1, n) {
        if (matcha[i]) cout << i << " " << matcha[i] << "\n";
    }
    return 0;
}

