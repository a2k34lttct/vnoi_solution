/*Code by Hoang Thai*/
#include <bits/stdc++.h>

#define pb push_back
#define reverse(x) reverse(x.begin(), x.end())
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
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, a[205][205], ans, vis[405], matchA[405], matchB[405];
vector<int> adj[405];
int dfs(int u) {
    for (int v : adj[u]) {
        if (!vis[v]) {
            vis[v] = 1;
            if (matchB[v] == 0 || dfs(matchB[v])) {
                matchA[u] = v;
                matchB[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
int check(int x) {
    fto(i, 1, n) {
        if (sz(adj[i])) adj[i].clear();
        mem(matchA, 0);
        mem(matchB, 0);
    }
    fto(i, 1, n) {
        fto(j, 1, n) {
            if (a[i][j] >= x) adj[i].pb(j + n);
        }
    }

    int res = 0;
    fto(i, 1, n) {
        mem(vis, 0);
        if (dfs(i)) ++res;
    }
    return res == n;
}
int main() {
    fastio;
    if (fopen("P078.inp", "r")) {
        freopen("P078.inp", "r", stdin);
        freopen("P078.out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, n) {
        fto(j, 1, n) cin >> a[i][j];
    }
    int low = 0;
    int high = 20000;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (check(mid)) {
            ans = mid;
            low = mid + 1;
        } else high = mid - 1;
    }
    cout << ans << "\n";
    return 0;
}
