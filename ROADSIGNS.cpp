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
const int maxN = 400005;
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
struct node {
    int u, v, x;
};
int n, cnt_same_a, cnt_same_b, ways, ans;
node a[maxN];
namespace sub1 {
    void solve() {
        cout << 2 << " " << 2*(n - 1) << "\n";
    }
}
namespace sub3 {
    int check(int len) {
        map<pii, int> mp;
        int cnt_ways = 0;
        fto(i, 1, n) {
            int L_i = a[i].x - a[i].u;
            int R_i = -oo;
            fto(j, i+1, n+1) {
                int L_j = a[j].x - a[j].u;
                int R_j = a[j].x + a[j].v;
                if (L_j == L_i || R_j == R_i) continue;
                else {
                    if (R_i == -oo) R_i = R_j;
                    else {
                        if (j - i >= len) {
                            if (!mp[{L_i, R_i}]) {
                                ++cnt_ways;
                                mp[{L_i, R_i}] = 1;
                            }
                        }
                        break;
                    }
                }
            }

            L_i = -oo;
            R_i = a[i].x + a[i].v;
            fto(j, i+1, n+1) {
                int L_j = a[j].x - a[j].u;
                int R_j = a[j].x + a[j].v;
                if (L_j == L_i || R_j == R_i) continue;
                else {
                    if (L_i == -oo) L_i = L_j;
                    else {
                        if (j - i >= len) {
                            if (!mp[{L_i, R_i}]) {
                                ++cnt_ways;
                                mp[{L_i, R_i}] = 1;
                            }
                        }
                        break;
                    }
                }
            }
        }
        if (cnt_ways) {
            ways = cnt_ways;
            return 1;
        }
        return 0;
    }
    void solve() {
        int low = 1;
        int high = n;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (check(mid)) {
                ans = mid;
                low = mid + 1;
            } else high = mid - 1;
        }
        cout << ans << " " << ways << "\n";
    }
}
int main() {
    fastio;
    if (fopen("ROADSIGNS.inp", "r")) {
        freopen("ROADSIGNS.inp", "r", stdin);
        freopen("ROADSIGNS.out", "w", stdout);
    }
    cin >> n;
    cnt_same_a = cnt_same_b = 1;
    fto(i, 1, n) {
        cin >> a[i].x >> a[i].u >> a[i].v;
        if (a[i].u == a[i-1].u) ++cnt_same_a;
        if (a[i].v == a[i-1].v) ++cnt_same_b;
    }
    if (cnt_same_a == cnt_same_b && cnt_same_a == n) sub1::solve();
    else (n <= 300) sub3::solve();
    return 0;
}
