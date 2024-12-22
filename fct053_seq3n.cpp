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
const int maxN = 300005;
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User

bool maximize(ll &a, ll b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
ll n, a[maxN], mx_sum, mn_sum, mx_val[maxN], mn_val[maxN], ans;
multiset<ll> mx;
multiset<ll, greater<ll>> mn;
int main() {
    fastio;
    if (fopen("fct053_seq3n.inp", "r")) {
        freopen("fct053_seq3n.inp", "r", stdin);
        freopen("fct053_seq3n.out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, 3*n) cin >> a[i];
    fto(i, 1, 3*n) {
        if (sz(mx) < n) {
            mx.insert(a[i]);
            mx_sum += a[i];
        }
        else {
            if (*mx.begin() < a[i]) {
                mx_sum -= *mx.begin();
                mx_sum += a[i];
                mx.erase(mx.begin());
                mx.insert(a[i]);
            }
        }
        mx_val[i] = mx_sum;
    }
    fdto(i, 3*n, 1) {
        if (sz(mn) < n) {
            mn.insert(a[i]);
            mn_sum += a[i];
        }
        else {
            if (*mn.begin() > a[i]) {
                mn_sum -= *mn.begin();
                mn_sum += a[i];
                mn.erase(mn.begin());
                mn.insert(a[i]);
            }
        }
        mn_val[i] = mn_sum;
    }
    mn_val[3*n+1] = 1e18;
    ans = -1e18;
    fto(i, 1, 3*n) maximize(ans, mx_val[i] - mn_val[i+1]);
    cout << ans << "\n";
    return 0;
}

