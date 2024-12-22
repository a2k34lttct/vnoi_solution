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
int n, a[maxN], b[maxN], color[maxN], ans, res;
vector<int> pos[maxN];
int main() {
    fastio;
    if (fopen("VIETDA.inp", "r")) {
        freopen("VIETDA.inp", "r", stdin);
        freopen("VIETDA.out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, n) cin >> a[i], b[i] = a[i];
    sort(b+1, b+n+1);
    fto(i, 1, n) {
        if (b[i] != b[i-1]) color[i] = color[i-1] + 1;
        else color[i] = color[i-1];
    }
    fto(i, 1, n) {
        int low = 1;
        int high = n;
        int p = 1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (b[mid] >= a[i]) {
                p = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        a[i] = color[p];
    }
    fto(i, 1, n) pos[a[i]].pb(i);
    fto(i, 1, color[n]) {
        for (int x : pos[i]) {
            if (x + 1 <= n) {
                if (a[x] < a[x+1]) ++res;
                else if (a[x] > a[x+1]) --res;
            }
            if (x - 1 >= 1) {
                if (a[x] < a[x-1]) ++res;
                else if (a[x] > a[x-1]) --res;
            }
        }
        maximize(ans, res);
    }
    cout << ans << "\n";
    return 0;
}

