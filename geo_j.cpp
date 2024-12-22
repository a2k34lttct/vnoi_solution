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
double a1, b1, c1, a2, b2, c2, x, y;
int main() {
    fastio;
    if (fopen("geo_j.inp", "r")) {
        freopen("geo_j.inp", "r", stdin);
        freopen("geo_j.out", "w", stdout);
    }
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    x = (b2*c1 - b1*c2) / (a2*b1 - a1*b2);
    y = (a1*c2 - a2*c1) / (a2*b1 - a1*b2);
    cout << fixed << setprecision(6) << x << " " << y << "\n";
    return 0;
}
