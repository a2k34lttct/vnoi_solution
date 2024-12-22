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
int n, d, a[maxN], ans, sum;
map<int, int> num;
namespace case_0 {
    int check(int x) {

    }
    void solve() {
        int low = 0;
        int high = n / 2;
        ans = 1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (check(mid)) {
                maximize(ans, mid);
                low = mid + 1;
            } else high = mid - 1;
        }
        cout << ans << "\n";
        return;
    }
}
int main() {
    fastio;
    if (fopen("PAIR.inp", "r")) {
        freopen("PAIR.inp", "r", stdin);
        freopen("PAIR.out", "w", stdout);
    }
    cin >> n >> d;
    fto(i, 1, n) cin >> a[i], sum += a[i], ++num[a[i]];
    sort(a+1, a+n+1);
    if (d == 0) case_0::solve();
    return 0;
}

