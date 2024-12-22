/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
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
const int maxN = 10001;
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int T, k, a[maxN], n, accept[maxN][14], f[maxN][4096], ans, lt[14];
string s, rev_s;
struct Hash {
    ll base, oo;
    vector<ll> power, hash;
    Hash(int _base, int _mod) {
        base = _base;
        oo = _mod;
    }
    void hashing(const string &s) {
        power.resize(n+5);
        hash.resize(n+5);
        power[0] = 1;
        hash[0] = (s[0] - 'a' + 1);
        fto(i, 1, n) {
            power[i] = (power[i-1] * base);
            hash[i] = (hash[i-1] * base + (s[i] - 'a' + 1));
        }
    }
    int get_hash(int l, int r) {
        return (hash[r] - (l - 1 >= 0 ? hash[l-1] : 0) * power[r - l + 1]);
    }
};
int dp(int i, int bit) {
    if (bit == lt[k-1]) return 1;
    if (i > n) return 0;
    if (f[i][bit] != -1) return f[i][bit];
    int res = dp(i+1, bit);
    fto(j, 0, k-1) {
        if (BIT(bit, j) == 0 && accept[i][j]) maximize(res, dp(i + a[j], bit | MASK(j)));
        if (res) break;
    }
    return f[i][bit] = res;
}
signed main() {
    fastio;
    if (fopen("olp_ct22_cutstr.inp", "r")) {
        freopen("olp_ct22_cutstr.inp", "r", stdin);
        freopen("olp_ct22_cutstr.out", "w", stdout);
    }
    cin >> s;
    n = sz(s) - 1;
    fdto(i, n, 0) rev_s += s[i];

    Hash str_1(311, oo), str_2(311, oo);
    str_1.hashing(s);
    str_2.hashing(rev_s);
    lt[0] = 1;
    fto(i, 1, 13) lt[i] = lt[i-1] * 2;
    fto(i, 1, 13) lt[i] += lt[i-1];
    cin >> T;
    while (T--) {
        cin >> k;
        fto(i, 0, k-1) cin >> a[i];
        fto(i, 0, n) {
            fto(j, 0, k-1) accept[i][j] = 0;
            fto(j, 0, lt[k-1]) f[i][j] = -1;
        }

        fto(i, 0, n) {
            fto(j, 0, k-1) {
                int rev_i = n - i;
                if (str_1.get_hash(i, i + a[j] - 1) == str_2.get_hash(rev_i - a[j] + 1, rev_i)) {
                    accept[i][j] = 1;
                }
            }
        }

        cout << (dp(0, 0) == 0 ? "NO" : "YES") << "\n";
    }
    return 0;
}
