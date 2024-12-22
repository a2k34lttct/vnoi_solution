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
int n;
string s, rev_s;
int main() {
    fastio;
    if (fopen("bedao_m24_a.inp", "r")) {
        freopen("bedao_m24_a.inp", "r", stdin);
        freopen("bedao_m24_a.out", "w", stdout);
    }
    cin >> n;
    int ok = 1;
    cin >> s;
    reverse(s.begin(), s.end());
    rev_s = s;
    reverse(s.begin(), s.end());
    int cnt = 1;
    fto(i, 1, n-1) cnt += (s[i] == s[i-1]);
    if (cnt == n) {
        cout << 0 << "\n";
        return 0;
    }
    fto(i, 0, n-1) {
        if (s[i] != rev_s[i]) {
            ok = 0;
            break;
        }
    }
    cout << n - ok << "\n";
    return 0;
}

