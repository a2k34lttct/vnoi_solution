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
const int maxN = 1000005;
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, a[maxN], ans;
struct smt {
    vector<int> tree;
    int type;
    smt(int n, int _type) {
        tree.resize(4*n);
        type = _type;
    }
    int mex(int a, int b) {return (type == 0 ? max(a, b) : (a + b));}
    void init(int node, int l, int r) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        init(node*2, l, mid);
        init(node*2+1, mid+1, r);
        tree[node] = mex(tree[node*2], tree[node*2 + 1]);
    }
    int query(int node, int l, int r, int u, int v) {
        if (u > r || v < l) return (type == 0 ? -oo : 0);
        if (u <= l && r <= v) return tree[node];
        int mid = (l + r) >> 1;
        return mex(query(node*2, l, mid, u, v), query(node*2+1, mid+1, r, u, v));
    }
};
signed main() {
    fastio;
    if (fopen("fc132_water.inp", "r")) {
        freopen("fc132_water.inp", "r", stdin);
        freopen("fc132_water.out", "w", stdout);
    }
    cin >> n;
    smt tree_1(n, 0), tree_2(n, 1);
    fto(i, 1, n) cin >> a[i];
    tree_1.init(1, 1, n);
    tree_2.init(1, 1, n);
    fto(i, 1, n) {
        ++a[i];
        fto(j, i + 2, n) {
            int num = tree_1.query(1, 1, n, i + 1, j - 1);
            if (a[i] >= num && a[j] >= num) maximize(ans, (min(a[i], a[j])) * (j - i - 1) - tree_2.query(1, 1, n, i + 1, j - 1));
        }
    }
    cout << ans << "\n";
    return 0;
}

