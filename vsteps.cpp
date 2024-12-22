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

const int oo = 14062008;
const int maxN = 100005;
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, k, f[maxN], a[maxN];
int main() {
    fastio;
    if (fopen("vsteps.inp", "r")) {
        freopen("vsteps.inp", "r", stdin);
        freopen("vsteps.out", "w", stdout);
    }
    cin >> n >> k;
    fto(i, 1, k) {
        int x; cin >> x;
        a[x] = 1;
    }
    f[1] = 1;
    fto(i, 2, n) {
        if (a[i]) continue;
        if (i - 1 >= 1 && a[i-1] == 0) f[i] = (f[i-1] + f[i]) % oo;
        if (i - 2 >= 1 && a[i-2] == 0) f[i] = (f[i-2] + f[i]) % oo;
    }
    cout <<  f[n] << "\n";
    return 0;
}

