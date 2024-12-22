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
int a, b;
ll s, ans;
int main() {
    fastio;
    if (fopen("coci1617_r6_savrsen.inp", "r")) {
        freopen("coci1617_r6_savrsen.inp", "r", stdin);
        freopen("coci1617_r6_savrsen.out", "w", stdout);
    }
    cin >> a >> b;
    fto(num, a, b) {
        s = -num;
        fto(uoc, 1, sqrt(num)) {
            if (num % uoc == 0) {
                s += uoc;
                if (num / uoc == uoc) break;
                s += (num / uoc);
            }
        }
        ans += abs(num - s);
    }
    cout << ans << "\n";
    return 0;
}

