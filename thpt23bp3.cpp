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
const int maxN = 10000005;
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int a, b, ans;
bool nt[maxN];
int check(int x) {
    string s = to_string(x);
    int l = 0;
    int r = sz(s) - 1;
    while (l < r) {
        if (s[l] != s[r]) return 0;
        ++l;
        --r;
    }
    return 1;
}
signed main() {
    fastio;
    if (fopen("thpt23bp3.inp", "r")) {
        freopen("thpt23bp3.inp", "r", stdin);
        freopen("thpt23bp3.out", "w", stdout);
    }
    cin >> a >> b;
    nt[1] = 1;
    for (int i = 2; i <= maxN-5; ++i) {
        if (!nt[i]) {
            for (int j = i * 2; j <= maxN-5; j += i) nt[j] = 1;
        }
    }
    for (long long i = 1; i <= maxN-5; ++i) {
        if (!nt[i] && a <= i * i && i * i <= b && check(i)) ++ans;
    }
    cout << ans << "\n";
    return 0;
}
