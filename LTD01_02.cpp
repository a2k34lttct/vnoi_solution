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

bool maximize(ll &a, ll b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
ll n, h[maxN], t_h[maxN], v[maxN], color[maxN], tree[4*maxN], ans;
void update(int node, int l, int r, int u, ll x) {
    if (u > r || u < l) return;
    if (l == r) {
        maximize(tree[node], x);
        return;
    }
    int mid = (l + r) >> 1;
    update(node*2, l, mid, u, x);
    update(node*2+1, mid+1, r, u, x);
    tree[node] = max(tree[node*2], tree[node*2+1]);
}
ll query(int node, int l, int r, int u, int v) {
    if (u > r || v < l) return 0LL;
    if (u <= l && r <= v) return tree[node];
    int mid = (l + r) >> 1;
    return max(query(node*2, l, mid, u, v), query(node*2+1, mid+1, r, u, v));
}
int main() {
    fastio;
    if (fopen("LTD01_02.inp", "r")) {
        freopen("LTD01_02.inp", "r", stdin);
        freopen("LTD01_02.out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, n) cin >> h[i], t_h[i] = h[i];
    fto(i, 1, n) cin >> v[i];
    sort(t_h+1, t_h+n+1);
    fto(i, 1, n) color[i] = color[i-1] + (t_h[i] != t_h[i-1]);
    fto(i, 1, n) {
        int low = 1;
        int high = n;
        int p = i;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (t_h[mid] >= h[i]) {
                p = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        h[i] = color[p];
    }
    fto(i, 1, n) {
        ll qu = query(1, 1, n, 1, h[i] - 1);
        maximize(ans, qu + v[i]);
        update(1, 1, n, h[i], qu + v[i]);
    }
    cout << ans << "\n";
    return 0;
}

