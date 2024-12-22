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
const int maxN = 5001;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
struct Hash {
    vector<int> power, hash;
    int base, mod;
    Hash(int _base, int _mod) {
        base = _base;
        mod = _mod;
    }
    void hashing(const string &s) {
        power.resize(sz(s));
        hash.resize(sz(s));
        power[0] = 1;
        hash[0] = s[0];
        fto(i, 1, sz(s) - 1) {
            power[i] = (power[i-1] * base) % mod;
            hash[i] = (hash[i-1] * base + s[i]) % mod;
        }
    }
    int get_hash(int l, int r) {
        return (hash[r] - (l - 1 < 0 ? 0 : hash[l-1]) * power[r - l + 1] + mod * mod) % mod;
    }
};


string a, b;
int q, l, r, last, f[maxN][maxN], kq[maxN];
Hash str_a(311, 1049), str_b(311, 1049);

int check(int i, int j) {
    int j_rev = sz(a) - i - 1;
    int i_rev = j_rev - (j - i + 1) + 1;
    return (str_a.get_hash(i, j) == str_b.get_hash(i_rev, j_rev));
}

signed main() {
    fastio;
    if (fopen("fc038_palind.inp", "r")) {
        freopen("fc038_palind.inp", "r", stdin);
        freopen("fc038_palind.out", "w", stdout);
    }
    cin >> a;
    fdto(i, sz(a) - 1, 0) b += a[i];
    str_a.hashing(a);
    str_b.hashing(b);
    int n = sz(a);
    fto(j, 0, n - 1) {
        fto(i, 0, j) kq[i] += check(i, j);
        fdto(i, j, 0) {
            if (i == j) f[i][j] = kq[i];
            else f[i][j] = f[i+1][j] + kq[i];
        }
    }
    cin >> q;
    while (q--) {
        cin >> l >> r;
        cout << f[l-1][r-1] << "\n";
    }
    return 0;
}
