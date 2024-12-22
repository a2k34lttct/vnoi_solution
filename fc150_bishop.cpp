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
int n, m, a[1005][1005], main_diag[2*1005], sub_diag[2*1005], ans, pos_main[1005][1005], pos_sub[1005][1005];
signed main() {
    fastio;
    if (fopen("fc150_bishop.inp", "r")) {
        freopen("fc150_bishop.inp", "r", stdin);
        freopen("fc150_bishop.out", "w", stdout);
    }
    cin >> n >> m;
    fto(i, 1, n) {
        fto(j, 1, m) cin >> a[i][j];
    }
    int cnt_diag = 1;
    fto(i, 1, m) {
        int r = 1;
        int c = i;
        int sum = 0;
        while (r <= n && c <= m) {
            pos_main[r][c] = cnt_diag;
            sum += a[r][c];
            ++r;
            ++c;
        }
        main_diag[cnt_diag++] = sum;
    }
    fto(i, 2, n) { 
        int r = i;
        int c = 1;
        int sum = 0;
        while (r <= n && c <= m) {
            pos_main[r][c] = cnt_diag;
            sum += a[r][c];
            ++r;
            ++c;
        }
        main_diag[cnt_diag++] = sum;
    }

    cnt_diag = 1;
    fto(i, 1, m) {
        int r = n;
        int c = i;
        int sum = 0;
        while (r >= 1 && c <= m) {
            pos_sub[r][c] = cnt_diag;
            sum += a[r][c];
            --r;
            ++c;
        }
        sub_diag[cnt_diag++] = sum;
    }
    fdto(i, n-1, 1) { 
        int r = i;
        int c = 1;
        int sum = 0;
        while (r >= 1 && c <= m) {
            pos_sub[r][c] = cnt_diag;
            sum += a[r][c];
            --r;
            ++c;
        }
        sub_diag[cnt_diag++] = sum;
    }
    ans = -5*oo;
    fto(i, 1, n) {
        fto(j, 1, m) {
            // if (i == 5 && j == 2) cout << i << " " << j << " " << main_diag[pos_main[i][j]] << " " << sub_diag[pos_sub[i][j]] << "\n";
            maximize(ans, main_diag[pos_main[i][j]] + sub_diag[pos_sub[i][j]] - a[i][j]);
        }
    }
    cout << ans << "\n";
    return 0;
}

