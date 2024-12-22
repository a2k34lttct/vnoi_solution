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
const int maxN = 100005;
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, k, f[1005][1005], gt[1005];
vector<string> str; 
vector<int> a;
int lt(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return (a * lt(a, b - 1)) % oo;
    int t = lt(a, b / 2);
    return (t * t) % oo;
}
int C(int k, int n) {
    return ((gt[n] * lt((gt[k] * gt[n - k]) % oo, oo - 2))) % oo;
}
int dp(int i, int r) {
    if (r < 0) return 0;
    if (i == sz(a)) return (r == 0);
    if (f[i][r] != -1) return f[i][r];
    int res = dp(i+1, r);
    fto(j, 1, a[i]) res = (res + dp(i+1, r - j * (j-1) / 2) * C(j, a[i])) % oo;
    return f[i][r] = res;
}
signed main() {
    fastio;
    if (fopen("thpt23bp4.inp", "r")) {
        freopen("thpt23bp4.inp", "r", stdin);
        freopen("thpt23bp4.out", "w", stdout);
    }
    cin >> n >> k;
    fto(i, 1, n) {
        string s; cin >> s;
        sort(s.begin(), s.end());
        str.pb(s);
    }
    sort(str.begin(), str.end());
    str.pb("HUYBEO");
    int cnt = 1;
    string c = str[0];
    fto(i, 1, sz(str) - 1) {
        if (str[i] == c) ++cnt;
        else {
            a.pb(cnt);
            cnt = 1;
            c = str[i];
        }
    }
    gt[0] = 1;
    fto(i, 1, 1000) gt[i] = (gt[i-1] * i) % oo;
    fto(i, 0, sz(a)) {
        fto(j, 0, k) f[i][j] = -1;
    }
    cout << dp(0, k) << "\n";
    return 0;
}

