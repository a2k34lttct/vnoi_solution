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
const int maxN = 100005;
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, q;
vector<string> s;
struct Hash {
    vector<int> power, hash;
    int base, mod;
    Hash(int _base, int _mod) {
        power.resize(100005);
        hash.resize(100005);
        base = _base;
        mod = _mod;
    }
    void hashing(const string &s) {
        power[0] = 1;
        hash[0] = s[0];
        fto(i, 1, sz(s) - 1) {
            power[i] = (power[i-1] * base) % mod;
            hash[i] = (hash[i-1] * base + s[i]) % mod;
        }
    }
    int get_hash(int l, int r) {
        return (hash[r] - (l - 1 < 0 ? 0 : hash[l-1]) * power[r - l + 1]  + mod * mod) % mod;
    }
};
signed main() {
    fastio;
    if (fopen("PREANDSUF.inp", "r")) {
        freopen("PREANDSUF.inp", "r", stdin);
        freopen("PREANDSUF.out", "w", stdout);
    }
    cin >> n >> q;
    int ok = 1;
    fto(i, 1, n) {
        string t; cin >> t;
        fto(i, 1, sz(t) - 1) {
            if (t[i] != t[i-1]) ok = 0;
        }
        s.pb(t);
    }
    Hash str(311, oo);
    while (q--) {
        int l, r; cin >> l >> r;
        --l; --r;
        set<int> ans;
        fto(i, l, r) {
            fto(j, l, r) {
                string a;
                fto(i_l, 0, sz(s[i]) - 1) {
                    a += s[i][i_l];
                    string b = "";
                    fdto(j_l, sz(s[j]) - 1, 0) {
                        b = s[j][j_l] + b;
                        string c = a + b;
                        str.hashing(c);
                        ans.insert(str.get_hash(0, sz(c) - 1));
                    }
                }
            }
        }
        cout << sz(ans) << "\n";
    }
    return 0;
}

