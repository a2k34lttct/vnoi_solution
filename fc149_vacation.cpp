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
int n, d, ans;
bitset<105> bit[105];
bitset<105> a;
int main() {
    fastio;
    if (fopen("fc149_vacation.inp", "r")) {
        freopen("fc149_vacation.inp", "r", stdin);
        freopen("fc149_vacation.out", "w", stdout);
    }
    cin >> n >> d;
    fto(i, 1, n) {
        fto(j, 1, d) {
            char c; cin >> c;
            if (c == 'o') bit[i][j] = 1;
        }
    }
    a = bit[1];
    fto(i, 2, n) {
        a &= bit[i];
    }
    int cnt = 0;
    fto(i, 1, n+1) {
        if (a[i]) ++cnt;
        else {
            maximize(ans, cnt);
            cnt = 0;
        }
    }
    cout << ans << "\n";
    return 0;
}

