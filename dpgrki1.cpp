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
ll m, n, f[1005][1005], a[1005][1005], ans;
ll dp(int i, int j) {
    if (i > n || j > m || i == 0 || j == 0) return 0LL;
    if (f[i][j] != -1) return f[i][j];
    return f[i][j] = max({dp(i, j+1), dp(i-1, j+1), dp(i+1, j+1)}) + a[i][j];
}
int main() {
    fastio;
    if (fopen("dpgrki1.inp", "r")) {
        freopen("dpgrki1.inp", "r", stdin);
        freopen("dpgrki1.out", "w", stdout);
    }
    cin >> n >> m;
    fto(i, 1, n) {
        fto(j, 1, m) cin >> a[i][j], f[i][j] = -1;
    }
    fto(i, 1, m) maximize(ans, dp(i, 1));
    cout << ans << "\n";
    return 0;
}

