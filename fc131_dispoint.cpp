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
const int maxN = 200005;
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, ans, query[maxN];
pii coor[maxN];
vector<pii> add, subtract;
int main() {
    fastio;
    if (fopen("fc131_dispoint.inp", "r")) {
        freopen("fc131_dispoint.inp", "r", stdin);
        freopen("fc131_dispoint.out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, n) cin >> coor[i].ff;
    fto(i, 1, n) cin >> coor[i].ss;
    fto(i, 1, n) {
        add.pb({coor[i].ff + coor[i].ss, i});
        subtract.pb({coor[i].ff - coor[i].ss,i});
    }
    sort(add.begin(), add.end());
    sort(subtract.begin(), subtract.end());
    fto(i, 1, n) {
        ans = -oo;
        int sum = coor[i].ff + coor[i].ss;
        int _minus = coor[i].ff - coor[i].ss;
//        cout << "QUERY: " << i << " " << sum << " " << _minus << "\n";
        // add cases
        int right_bound = (i == add.back().ss ? add[sz(add) -2].ff : add.back().ff);
        int left_bound = (i == add[0].ss ? add[1].ff : add[0].ff);
//        cout << left_bound << " " << right_bound << "\n";
        maximize(ans, abs(sum - right_bound));
        maximize(ans, abs(sum - left_bound));

        // subtract cases
        right_bound = (i == subtract.back().ss ? subtract[sz(subtract) -2].ff : subtract.back().ff);
        left_bound = (i == subtract[0].ss ? subtract[1].ff : subtract[0].ff);
//        cout << left_bound << " " << right_bound << "\n";

        maximize(ans, abs(_minus - right_bound));
        maximize(ans, abs(_minus - left_bound));

        cout << ans << " ";
    }
    cout << "\n";
    return 0;
}
