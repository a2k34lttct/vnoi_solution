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
int n, m, len;
string a, b, ans;
int main() {
    fastio;
    if (fopen("password.inp", "r")) {
        freopen("password.inp", "r", stdin);
        freopen("password.out", "w", stdout);
    }
    cin >> a >> n >> b >> m;
    if (sz(a) > sz(b)) swap(a, b), swap(n, m);
    if (n < sz(a) || m < sz(b)) cout << "!\n";
    else if (sz(a) < sz(b) && n > m) cout << "!\n";
    else {
        fto(i, 0, sz(a) - 1) {
            if (a[i] != b[i]) {
                ans = "!";
                break;
            } else ans += a[i];
        }
        if (ans[0] == '!') cout << ans << "\n";
        else {
            ans = b;
            int del = min(n - sz(a), sz(b) - sz(a));
            if (m - sz(b) >= del) {
                fto(i, 1, del) ans += "q";
                fto(i, 1, del) ans += "<";
            }
            cout << sz(ans) << "\n" << ans << "\n";
        }
    }
    return 0;
}

