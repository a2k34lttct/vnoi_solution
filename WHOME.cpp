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
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, m, p, c, a[maxN], s[maxN], f[maxN][70];
int dp(int i, int bit) {
    if (i > n) return bit_count(bit) == m ? 0 : (-1e18 + 7);
    if (f[i][bit] != -1) return f[i][bit];
    int res = dp(i+1, bit);
    fto(j, 1, m) {
        if (i + s[j] - 1 <= n) {
            int r = i + s[j] - 1;
            int add = p - (a[r] - a[i]) * (a[r] - a[i]) * c;
            maximize(res, dp(i + s[j], bit | MASK(j - 1)) + add);
        }
    }
    return f[i][bit] = res;
}
signed main() {
    fastio;
    if (fopen("WHOME.inp", "r")) {
        freopen("WHOME.inp", "r", stdin);
        freopen("WHOME.out", "w", stdout);
    }
    cin >> n >> m >> p >> c;
    fto(i, 1, n) cin >> a[i];
    fto(i, 1, m) cin >> s[i];
    sort(a+1, a+n+1);
    fto(i, 1, n) {
        fto(j, 0, 69) f[i][j] = -1;
    }
    // mem(f, -1);
    cout << dp(1, 0) << "\n";
    return 0;
}