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
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, m, q, row[2005], col[2005];
signed main() {
    fastio;
    if (fopen("fct054_bquery.inp", "r")) {
        freopen("fct054_bquery.inp", "r", stdin);
        freopen("fct054_bquery.out", "w", stdout);
    }
    cin >> n >> m >> q;
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int r, x; cin >> r >> x;
            row[r] += x;
        }
        if (type == 2) {
            int c, x; cin >> c >> x;
            col[c] += x;
        }
        if (type == 3) {
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            int mx_row = -oo;
            int mx_col = -oo;
            fto(i, x1, x2) maximize(mx_row, row[i]);
            fto(i, y1, y2) maximize(mx_col, col[i]);
            cout << mx_row + mx_col << "\n";
        }
    }
    return 0;
}
