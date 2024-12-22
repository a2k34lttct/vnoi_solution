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
string a, b;
int n, m, ans;
vector<int> pos[30];
int tree[5001];
int main() {
    fastio;
    if (fopen("P236.inp", "r")) {
        freopen("P236.inp", "r", stdin);
        freopen("P236.out", "w", stdout);
    }
    cin >> a >> b;
    if (sz(a) < sz(b)) swap(a, b);
    a = '@' + a;
    b = '@' + b;
    n = sz(a);
    m = sz(b);
    fto(i, 1, n - 1) pos[a[i] - 'A' + 1].pb(i);
    fto(i, 0, 5000) tree[i] = oo;
    fto(i, 1, m - 1) {
        if (sz(pos[b[i] - 'A' + 1])) {
            minimize(tree[1], pos[b[i] - 'A' + 1][0]);
            ans = 1;
        }
    }
    fto(i, 2, m) {
        fto(j, i, m - 1) {
            int add = tree[i-1];
            if (add == oo) continue;
            int low = 0;
            int high = sz(pos[b[j] - 'A' + 1]) - 1;
            int p = -1;
            while (low <= high) {
                int mid = (low + high) >> 1;
                if (pos[b[j] - 'A' + 1][mid] > add) {
                    p = pos[b[j] - 'A' + 1][mid];
                    high = mid - 1;
                } else low = mid + 1;
            }
            if (p != -1) {
                tree[i] = min(tree[i], p);
                maximize(ans, i);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
