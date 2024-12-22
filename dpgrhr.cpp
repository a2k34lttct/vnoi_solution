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
int T, n, m, a[505][505], f[505][505];
int check(int x) {
    fto(i, 1, n) {
        fto(j, 1, m) f[i][j] = -oo;
    }
    f[1][1] = x;
    fto(i, 1, n) {
        fto(j, 1, m) {
            if (i == 1 && j == 1) continue;
            if (i-1 > 0 && f[i-1][j] > 0) f[i][j] = max(f[i][j], f[i-1][j] + a[i][j]);
            if (j-1 > 0 && f[i][j-1] > 0) f[i][j] = max(f[i][j], f[i][j-1] + a[i][j]);
        }
    }
    return (f[n][m] > 0);
}
int main() {
    fastio;
    if (fopen("dpgrhr.inp", "r")) {
        freopen("dpgrhr.inp", "r", stdin);
        freopen("dpgrhr.out", "w", stdout);
    }
    cin >> T;
    while (T--) {
        cin >> n >> m;
        fto(i, 1, n) {
            fto(j, 1, m) cin >> a[i][j];
        }
        int low = 0;
        int high = oo;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (check(mid)) {
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}

