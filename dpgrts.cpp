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
int n, m, a[105][105], f[105][105][105], ans;
int dp(int i, int l, int r) {
    if (i > n) return 0;
    if (f[i][l][r] != -1) return f[i][l][r];
    int res = 0;
    if (l != r) {
        if (1 <= l - 1 && r + 1 <= m) maximize(res, dp(i+1, l-1, r+1) + a[i][l] + a[i][r]);
        if (1 <= l - 1) maximize(res, dp(i+1, l-1, r) + a[i][l] + a[i][r]);
        if (1 <= l - 1 && 1 <= r - 1) maximize(res, dp(i+1, l-1, r-1) + a[i][l] + a[i][r]);

        if (r + 1 <= m) maximize(res, dp(i+1, l, r+1) + a[i][l] + a[i][r]);
        maximize(res, dp(i+1, l, r) + a[i][l] + a[i][r]);
        if (r - 1 >= l) maximize(res, dp(i+1, l, r-1) + a[i][l] + a[i][r]);

        if (l + 1 <= m && r + 1 <= m) maximize(res, dp(i+1, l+1, r+1) + a[i][l] + a[i][r]);
        if (l + 1 <= m) maximize(res, dp(i+1, l+1, r) + a[i][l] + a[i][r]);
        if (l + 1 <= r - 1) maximize(res, dp(i+1, l+1, r-1) + a[i][l] + a[i][r]);
    }
    else {
        if (l - 1 >= 1) maximize(res, dp(i+1, l-1, r) + a[i][l]);
        maximize(res, dp(i+1, l, l) + a[i][l]);
        if (r + 1 <= m ) maximize(res, dp(i+1, l, r+1) + a[i][l]);
    }
    return f[i][l][r] = res;
}
int main() {
    fastio;
    if (fopen("dpgrts.inp", "r")) {
        freopen("dpgrts.inp", "r", stdin);
        freopen("dpgrts.out", "w", stdout);
    }
    cin >> n >> m;
    fto(i, 1, n) {
        fto(j, 1, m) cin >> a[i][j];
    }
    fto(i, 1, n) {
        fto(j, 1, m) {
            fto(k, 1, m) f[i][j][k] = -1;
        }
    }
    fto(i, 1, m) {
        fto(j, i, m) maximize(ans, dp(1, i, j));
    }
    cout << ans << "\n";
    return 0;
}

