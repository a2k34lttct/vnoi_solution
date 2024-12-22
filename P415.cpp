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
const int maxN = 1000005;
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
struct node {
    int x1, y1, x2, y2;
};
int n, k, tree[4*maxN], lazy[4*maxN], ans;
node a[maxN];
int getId(int i, int j) {
    return (i - 1) * 1000 + j;
}
void push(int node, int l, int r) {
    if (lazy[node] == 0) return;
    tree[node] += (r - l + 1);
    if (l != r) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
    return;
}
void update(int node, int l, int r, int u, int v) {
    push(node, l, r);
    if (u > r || v < l) return;
    if (u <= l && r <= v) {
        lazy[node] += 1;
        push(node, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    update(node*2, l, mid, u, v);
    update(node*2+1, mid+1, r, u, v);
    tree[node] = tree[node*2] + tree[node*2+1];
}
int query(int node, int l, int r, int u, int v) {
    push(node, l, r);
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return tree[node];
    int mid = (l + r) >> 1;
    return query(node*2, l, mid, u, v) + query(node*2+1, mid+1, r, u, v);
}
int main() {
    fastio;
    // if (fopen("P415.inp", "r")) {
    //     freopen("P415.inp", "r", stdin);
    //     freopen("P415.out", "w", stdout);
    // }
    cin >> n >> k;
    fto(i, 1, n) cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
    fto(i, 1, n) {
        fdto(j, a[i].y2, a[i].y1) {
            int right = getId(j, a[i].x2);
            int left = getId(j, a[i].x1);
            update(1, 1, maxN - 5, left, right);
        }
    }
    fto(i, 1, maxN - 5) {
        if (query(1, 1, maxN-5, i, i) == k) {
            ++ans;
        }
    }
    cout << ans << "\n";
    return 0;
}

