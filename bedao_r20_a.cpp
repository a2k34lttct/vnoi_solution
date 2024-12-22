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
ll n, ans, test;
int main() {
    fastio;
    if (fopen("bedao_r20_a.inp", "r")) {
        freopen("bedao_r20_a.inp", "r", stdin);
        freopen("bedao_r20_a.out", "w", stdout);
    }
    cin >> test;
    while (test--) {
        cin >> n;
        ll sqrt_n = sqrt(n);
        if (sqrt_n * sqrt_n != n) cout << "0\n";
        else {
            ans = 0;
            fto(i, 1, sqrt(sqrt_n)) {
                if (sqrt_n % i == 0) {
                    if (i % 2 == 0 && (sqrt_n / i) % 2 == 0) ans += 2 - (sqrt_n / i == i);
                    if (n / i == i) break;
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}

