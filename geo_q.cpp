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
double x_1, y_1, x_2, y_2, x_3, y_3;
int main() {
    fastio;
    if (fopen("geo_q.inp", "r")) {
        freopen("geo_q.inp", "r", stdin);
        freopen("geo_q.out", "w", stdout);
    }
    cin >> x_3 >> y_3 >> x_1 >> y_1 >> x_2 >> y_2;
    if (x_1 == x_2) {
        if (y_1 > y_2) swap(y_1, y_2);
        if (x_3 != x_1) cout << no << "\n";
        else cout << (y_1 <= y_3 && y_3 <= y_2 ? yes : no) << "\n";
    }
    else if (y_1 == y_2) {
        if (x_1 > x_2) swap(x_1, x_2);
        if (y_3 != y_1) cout << no << "\n";
        else cout << (x_1 <= x_3 && x_3 <= x_2 ? yes : no) << "\n";
    }
    else {
        // double a = (y_1 - y_2) / (x_1 - x_2);
        // double b = (y_1 - x_1 * a);
        if ((y_1 - y_2) / (x_1 - x_2) * x_3 + (y_1 - x_1 * (y_1 - y_2) / (x_1 - x_2)) == y_3 && min(x_1, x_2) <= x_3 && x_3 <= max(x_1, x_2) && min(y_1, y_2) <= y_3 && y_3 <= max(y_1, y_2)) cout << yes << "\n";
        else cout << no << "\n";
    }
    return 0;
}
