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
int n, m, s, t, vis[maxN];
struct node {
    int w, v, c;
};
vector<node> adj[maxN];
pii dis[maxN];
void dijkstra(int s) {
    priority_queue<pair<int, node>, vector<pair<int, node>>, greater<pair<int, node>>> Q;
    Q.push({0, {oo, oo, s}});
    dis[s].ff = dis[s].ss = 0;
    while (!Q.empty()) {
        auto t = Q.top(); Q.pop();
        int u = t.ss.v;
        if (vis[u]) continue;
        for (node x : adj[u]) {
            int v = x.v;
            if (x.c == 1) dis[v].ff = max(dis[v].ff, x.w);
            if (x.c == 1) dis[v].ss = max(dis[v].ss, x.w);
            Q.push({dis[v].ff + dis[v].ss, {dis[v].ff, dis[v].ss, v}});
        }
        vis[u] = 1;
    }
    cout << dis[t].ff + dis[t].ss << "\n";
    return;
}
int main() {
    fastio;
    if (fopen("voi20_bus.inp", "r")) {
        freopen("voi20_bus.inp", "r", stdin);
        freopen("voi20_bus.out", "w", stdout);
    }
    cin >> n >> m >> s >> t;
    fto(i, 1, m) {
        int c, u, v, w; cin >> c >> u >> v >> w;
        adj[u].pb({w, v, c});
        adj[v].pb({w, u, c});
    }
    fto(i, 1, n) dis[i].ff = dis[i].ss = oo;
    dijkstra(s);
    return 0;
}

