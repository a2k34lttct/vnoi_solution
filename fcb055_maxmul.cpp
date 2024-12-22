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

const ll oo = 1000000007;
const int maxN = 100005;
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, q;
ll a[maxN], f[maxN];
ll lt(ll a, ll b) {
    if (b == 0) return 1LL;
    if (b & 1) return (a * lt(a, b-1)) % oo;
    ll t = lt(a, b / 2);
    return (t * t) % oo;
}
ll nhan(ll a, ll b) {
    if (b == 0) return 0;
    if (b & 1) return (a + nhan(a, b - 1)) % oo;
    ll t = lt(a, b / 2);
    return (t + t) % oo;
}
int main() {
    fastio;
    if (fopen("fcb055_maxmul.inp", "r")) {
        freopen("fcb055_maxmul.inp", "r", stdin);
        freopen("fcb055_maxmul.out", "w", stdout);
    }
    cin >> n;
    f[0] = 1;
    fto(i, 1, n) cin >> a[i], f[i] = (f[i-1] * a[i]) % oo;
    cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        cout << (f[l + r - 1] * lt(f[l-1], oo-2)) % oo << "\n";
        // cout << nhan(f[r], lt(f[l-1], oo-2)) << "\n";
    }
    return 0;
}

