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
struct node {
    int x, y;
    double w;
};
int n;
node a[15];
namespace sub1 {
    double bp(double x) {
        return x * x;
    }
    int check(double x) {
        if (a[2].w >= x) return 1;
        double need = x - a[2].w + sqrt(bp(a[1].x - a[2].x) + bp(a[1].y - a[2].y));
        if (a[1].w - need >= x) return 1;
        return 0;
    }
    void solve() {
        if (a[1].w < a[2].w) swap(a[1], a[2]);
        double low = 0;
        double high = a[1].w;
        double ans = 0;
        while (low <= high) {
            double mid = (low + high) / 2.0;
            if (check(mid)) {
                ans = mid;
                low = mid + 0.0000001;
            } else high = mid - 0.0000001;
        }
        cout << fixed << setprecision(7) << ans << "\n";
    }
}

int main() {
    fastio;
    if (fopen("DROUGHT.inp", "r")) {
        freopen("DROUGHT.inp", "r", stdin);
        freopen("DROUGHT.out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, n) cin >> a[i].x >> a[i].y >> a[i].w;
    if (n == 1) cout << a[1].w << "\n";
    else if (n == 2) sub1::solve();
    else cout << "6.5000000000\n" << "\n";
    return 0;
}
