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
const int maxN = 1000005;
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, a[maxN], ans, mark, trace[maxN], kq[maxN];
vector<int> path;
void backtrack(int i) {
    path.pb(i);
    fdto(j, i-1, 1) {
        if (trace[j] + 1 == trace[i] && a[j] - 1 == a[i]) {
            backtrack(j);
            break;
        }
    }
    return;
}
int main() {
    fastio;
    if (fopen("bedao_r19_c.inp", "r")) {
        freopen("bedao_r19_c.inp", "r", stdin);
        freopen("bedao_r19_c.out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, n) cin >> a[i];
    ans = mark = 1;
    fto(i, 1, n) {
        int need = a[i] + 1;
        if (kq[need] == 0) maximize(kq[a[i]], 1), trace[i] = 1;
        else maximize(kq[a[i]], kq[need] + 1), trace[i] = kq[need] + 1;
        if (maximize(ans, kq[a[i]])) mark = i;
    }
    cout << ans << "\n";
    backtrack(mark);
    fdto(i, sz(path) - 1, 0) cout << path[i] << " ";
    cout << "\n";
    return 0;
}

