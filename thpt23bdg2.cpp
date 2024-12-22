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
int n, m, a[maxN], ans, cnt[maxN];
int check(int len) {
    int sum = 0;
    fto(i, 1, 1000000) cnt[i] = 0;
    fto(i, 1, len) {
        sum += !cnt[a[i]];
        cnt[a[i]] += 1;
    }
    int l = 1;
    int r = len;
    while (l < r && r <= n) {
        if (sum >= m) return 1;
        cnt[a[l]] -= 1;
        if (cnt[a[l]] == 0) --sum;
        ++l;
        ++r;
        if (cnt[a[r]] == 0) ++sum;
        cnt[a[r]] += 1;
    }
    return 0;
}
int main() {
    fastio;
    if (fopen("thpt23bdg2.inp", "r")) {
        freopen("thpt23bdg2.inp", "r", stdin);
        freopen("thpt23bdg2.out", "w", stdout);
    }
    cin >> n >> m;
    fto(i, 1, n) cin >> a[i];
    int low = m;
    int high = n;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (check(mid)) {
            ans = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    cout << ans << "\n";
    return 0;
}

