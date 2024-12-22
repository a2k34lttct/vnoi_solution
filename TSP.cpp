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
int n, dis[11][11], f[11][(1 << 10) + 5];
vector<int> adj[11];
int dp(int i, int bit) {
    if (bit_count(bit) == n) return (i == 1 ? 0 : oo);
    if (f[i][bit] != -1) return f[i][bit];
    int res = oo;
    for (int v : adj[i]) {
        if (BIT(bit, v - 1) == 0) {
            minimize(res, dp(v, bit | MASK(v - 1)) + dis[i][v]);
        }
    }
    return f[i][bit] = res;
}
signed main() {
    fastio;
    if (fopen("TSP.inp", "r")) {
        freopen("TSP.inp", "r", stdin);
        freopen("TSP.out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, n) {
        fto(j, 1, n) cin >> dis[i][j], adj[i].pb(j);
    }
    mem(f, -1);
    cout << dp(1, 0) << "\n";
    return 0;
}

