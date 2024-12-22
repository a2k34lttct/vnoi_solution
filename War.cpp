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

const ll oo = 100000000007;
const int maxN = 405;
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int T, n, m, vis[maxN];
ll sum, ans;
vector<pair<int, ll>> adj[maxN];

namespace sub2 {
    ll dfs(int i, int j) {
        if (i == j) return oo;
        vis[i] = 1;
        ll res = 0;
        for (auto v : adj[i]) {
            if (vis[v.ff]) continue;
            ll t = dfs(v.ff, j);
            cout << "POINT: " << i << " -> TO: " << v.ff << " " << t << " " << v.ss << "\n";
            res += min(t, v.ss);
        }
        return res;
    }

    void solve() {
        int cnt = 0;
        fto(i, 1, n) {
            fto(j, i+1, n) {
                fto(k, 1, n) vis[k] = 0;
                ll t = dfs(i, j) - 1;
                if (T == 1) ans = min(ans, t);
                else ans += t;
                ++cnt;
                cout << i << " " << j << " " << t << "\n";
            }
        }
        if (T == 1) cout << ans << "\n";
        else {
            ans = ans * n * (n-1) / cnt;
            cout << ans << "\n";
        }
        return;
    }
}

int main() {
    fastio;
    if (fopen("War.inp", "r")) {
        freopen("War.inp", "r", stdin);
        freopen("War.out", "w", stdout);
    }
    cin >> T >> n >> m;
    if (T == 1) ans = oo;
    else ans = 0;
    fto(i, 1, m) {
        int u, v;
        ll w; cin >> u >> v >> w;
        ++u; ++v;
        sum += w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    if (n <= 50) sub2::solve();
    else cout << 0 << "\n";
    return 0;
}
