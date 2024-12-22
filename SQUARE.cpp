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

const ll oo = 1000000000 + 9999;
const int maxN = 100005;
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
struct node {
    int u, v, x;
};
int n, m, T, pro[50][50], b[50][50], np[25];
ll lt(ll a, ll b) {
    if (b == 0LL) return 1LL;
    if (b % 2 != 0) return (a * lt(a, b-1)) % oo;
    ll t = lt(a, b / 2);
    return (t * t) % oo;
}
namespace sub1 {
    pii revId(int s) {
        // getId(i, j) = (i - 1) * m + j
        int y = (s % m == 0 ? m : s % m);
        int x = (s - y) / m + 1;
        return {x, y};
    }
    void solve() {
        ll ans = 0;
        while (T--) {
            int u, v, x; cin >> u >> v >> x;
            pro[u][v] = x + 1;
        }
        while (1) {
            bool ok = 1;
            fto(i, 1, n*m) {
                pii coor = revId(i);
                if (pro[coor.ff][coor.ss]) {
                    if (pro[coor.ff][coor.ss] != np[i]) ok = 0;
                }
                b[coor.ff][coor.ss] = np[i];
            }
            
            fto(i, 1, n-1) {
                fto(j, 1, m - 1) {
                    if ((b[i][j] + b[i+1][j] + b[i][j+1] + b[i+1][j+1]) & 1) ok = 0;
                }
            }
            ans += 1LL*ok;
            int p = n * m;
            while (p > 0 && np[p] == 1) --p;
            if (p == 0) break;
            np[p] = 1;
            fto(i, p+1, n*m) np[i] = 0;
        }
        cout << (ans % oo) << "\n";
    }
}

namespace sub2 {
    void solve() {
        cout << lt(2, n + m - 1) << "\n";
    }
}

namespace sub3 {
    void solve() {
        cout << lt(2, n + m - 2) << "\n";
    }
}

namespace sub4 {
    void solve() {
        cout << lt(2, n + m - 3) << "\n";
    }
}

int main() {
    fastio;
    if (fopen("SQUARE.inp", "r")) {
        freopen("SQUARE.inp", "r", stdin);
        freopen("SQUARE.out", "w", stdout);
    }
    cin >> n >> m >> T;
    if (n == 1) cout << (lt(2, m) - (1LL * T) + oo) % oo << "\n";
    else if (m == 1) cout << (lt(2, n) - (1LL * T) + oo) % oo << "\n";
    else if (n * m <= 20) sub1::solve();
    else if (T == 0) sub2::solve();
    else if (T == 1) sub3::solve();
    else if (T == 2) sub4::solve();
    return 0;
}

