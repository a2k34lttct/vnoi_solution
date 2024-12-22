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
const int maxN = 105;
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, m, val[maxN], c[maxN], f[101][101][2001];
vector<int> adj[maxN];
int dp(int u, int p, int m) {
    if (f[u][p][m] != -1) return f[u][p][m];
    int res = 0;
    for (int v : adj[u]) {
        if (v == p || m - c[v] < 0) continue;
        maximize(res, dp(v, u, m - c[v]) + val[v]);
    }
    return f[u][p][m] = res;
}
int main() {
    fastio;
    if (fopen("kingdom.inp", "r")) {
        freopen("kingdom.inp", "r", stdin);
        freopen("kingdom.out", "w", stdout);
    }
    cin >> n >> m;
    fto(i, 2, n) cin >> val[i];
    fto(i, 2, n) cin >> c[i];
    fto(i, 1, n-1) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    fto(i, 0, n) {
        fto(j, 0, n) {
            fto(k, 0, m) f[i][j][k] = -1;
        }
    }
    cout << dp(1, 0, m) << "\n";
    return 0;
}

