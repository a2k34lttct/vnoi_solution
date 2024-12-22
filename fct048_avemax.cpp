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

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, k;
int a[maxN], ans, f[maxN];

int check(int x) {
    fto(i, 1, n) a[i] -= x, f[i] = 0;;
    fto(i, 1, n) f[i] = f[i-1] + a[i];
    int mn = oo;
    int l = 0;
    int r = 1;
    int ret = 0;
    while (l <= r) {
        if (r > n) break;
        mn = min(mn, f[l]);
        if (f[r] - mn >= 0) {
            ret = 1;
            break;
        }
        ++r;
        ++l;
    }
    fto(i, 1, n) a[i] += x;
    return ret;
}

int main() {
    fastio;
    if (fopen("rate.inp", "r")) {
        freopen("rate.inp", "r", stdin);
        freopen("rate.out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, n) cin >> a[i];
    int low = 0;
    int high = oo;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(mid)) {
            ans = mid;
            low = mid + 1;
        } else high = mid -1;
    }
    cout << ans << "\n";
    return 0;
}