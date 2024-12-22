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
int n, m, parent[maxN], ans, vis[maxN];
vector<pii> query;
vector<int> adj[maxN];
int find_set(int u) {
    return (u == parent[u] ? u : parent[u] = find_set(parent[u]));
}
void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        parent[b] = a;
        return;
    }
}
void dfs(int u, int p, int cnt) {
    vis[u] = cnt;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (vis[v]) {
            if (vis[v] % 2 != (cnt + 1) % 2) {
                ans = -oo;
                return;
            }
        }
        else {
            dfs(v, u, cnt + 1);
        }
    }
}

int main() {
    fastio;
    if (fopen("P56.inp", "r")) {
        freopen("P56.inp", "r", stdin);
        freopen("P56.out", "w", stdout);
    }
    cin >> n >> m;
    fto(i, 1, n) parent[i] = i;
    fto(i, 1, m) {
        char c;
        int u, v;
        cin >> c >> u >> v;
        if (c == 'S') union_set(u, v);
        else query.pb({u, v});
    }
    ans = oo;
    for (pii x : query) {
        int u = find_set(x.ff);
        int v = find_set(x.ss);
        if (u == v) {
            ans = 0;
            break;
        }
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if (ans == 0) {
        cout << ans << "\n";
        return 0;
    }
    ans = 0;
    fto(i, 1, n) {
        if (!vis[find_set(i)]) {
            dfs(find_set(i), find_set(i), 1);
            if (ans == -oo) break;
            ++ans;
        }
    }
    if (ans < 0) cout << 0 << "\n";
    else {
        if (ans == 0) cout << ans << "\n";
        else {
            cout << 1;
            fto(i, 1, ans) cout << 0;
        }
    }
    return 0;
}
