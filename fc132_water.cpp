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
int n, a[maxN], ans, parent[maxN][2], f[maxN][2], sum[maxN];
int dp(int i, int r) {
    if (i >= n) return 0;
    if (f[i][r] != -1) return f[i][r];
    int res = 0;
    if (parent[i] != -1) {
        int f_1 = -oo;
        int f_2 = -oo;
        f_1 = dp(parent[i] + 1, r) + a[i] * (parent[i] - i - 1) - (sum[parent[i]] - sum[i-1]);
        if (r == 1) f_2 = dp(parent[i] + 1, r) + (a[i] + 1) * (parent[i] - i - 1) - (sum[parent[i]] - sum[i-1]);
    }
}
signed main() {
    fastio;
    if (fopen("fc132_water.inp", "r")) {
        freopen("fc132_water.inp", "r", stdin);
        freopen("fc132_water.out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, n) cin >> a[i], sum[i] = sum[i-1] + a[i];
    fto(i, 1, n) parent[i] = i;
    fdto(i, n - 1, 1) {
        if (a[i] < a[i+1]) parent[i] = i + 1;
        else {
            if (a[parent[i+1]] >= a[i]) parent[i] = parent[i+1];
        }
    }
    fto(i, 1, n) f[i][0] = f[i][1] = -1;
    cout << dp(1, 1) << "\n";
    return 0;
}

