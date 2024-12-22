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
const int maxN = 300005;
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, last, diameter, vis[maxN], dis[maxN];
vector<int> adj[maxN];
void dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v]) {
            maximize(dis[v], dis[u] + 1);
            dfs(v);
        }
    }
}
int main() {
    fastio;
    if (fopen("secondthread_tree_circumference.inp", "r")) {
        freopen("secondthread_tree_circumference.inp", "r", stdin);
        freopen("secondthread_tree_circumference.out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, n-1) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    last = 1;
    fto(i, 1, n) {
        if (dis[i] >= dis[last]) last = i;
    }
    mem(dis, 0);
    mem(vis, 0);
    dfs(last);
    fto(i, 1, n) maximize(diameter, dis[i]);
    cout << diameter * 3 << "\n";
    return 0;
}

