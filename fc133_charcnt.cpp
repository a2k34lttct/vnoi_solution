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
int n, q;
vector<bitset<26>> tree;
bitset<26> dv;
void update(int node, int l, int r, int u, int x) {
    if (u > r || u < l) return;
    if (l == r) {
        if (u == l) {
            tree[node] = dv;
            tree[node][x] = 1;
        }
        return;
    }
    int mid = (l + r) >> 1;
    update(node*2, l, mid, u, x);
    update(node*2+1, mid+1, r, u, x);
    tree[node] = tree[2*node] | tree[2*node+1];
}
bitset<26> query(int node, int l, int r, int u, int v) {
    if (u > r || v < l) return dv;
    if (u <= l && r <= v) return tree[node];
    int mid = (l + r) >> 1;
    return query(node*2, l, mid, u, v) | query(node*2+1, mid+1, r, u, v);
}
int main() {
    fastio;
    if (fopen("fc133_charcnt.inp", "r")) {
        freopen("fc133_charcnt.inp", "r", stdin);
        freopen("fc133_charcnt.out", "w", stdout);
    }
    cin >> n;
    tree.resize(4*n);
    fto(i, 1, n) {
        char c; cin >> c;
        update(1, 1, n, i, c - 'a');
    }
    cin >> q;
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int u;
            char c;
            cin >> u >> c;
            update(1, 1, n, u, c - 'a');
        }
        if (type == 2) {
            int l, r; cin >> l >> r;
            cout << query(1, 1, n, l, r).count() << "\n";
        }
    }
    return 0;
}

