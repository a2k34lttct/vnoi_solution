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
int n, ans;
string a, b;
struct Hash {
    int base, oo;
    vector<int> power, hash;
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
            power[i] = (power[i-1] * base) % oo;
            hash[i] = (hash[i-1] * base + (s[i] - 'a' + 1)) % oo;
        }
    }
    int get_hash(int l, int r) {
        return (hash[r] - (l - 1 >= 0 ? hash[l-1] : 0) * power[r - l + 1] + oo * oo) % oo;
    }
};
Hash str_a(311, oo);
Hash str_b(311, oo);
int check(int x) {
    fto(i, 0, n - 1) {
        int r = n - i - 1;
        int l = r - x + 1;
        if (str_a.get_hash(i, i + x - 1) == str_b.get_hash(l, r)) {
            return 1;
        }
    }
    return 0;
}
signed main() {
    fastio;
    if (fopen("paliny.inp", "r")) {
        freopen("paliny.inp", "r", stdin);
        freopen("paliny.out", "w", stdout);
    }
    cin >> n;
    cin >> a;
    fdto(i, n - 1, 0) b += a[i];
    str_a.hashing(a);
    str_b.hashing(b);
    // even palindrome
    int low = 0;
    int high = sz(a) - (sz(a) & 1);
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (mid & 1) ++mid;
        if (check(mid)) {
            ans = mid;
            low = mid + 1;
        } else high = mid - 2;
    }

    // odd palindrome
    low = 1;
    high = sz(a) - (sz(a) % 2 == 0);
    while (low <= high) {
       int mid = (low + high) >> 1;
       if (mid % 2 == 0) ++mid;
       if (check(mid)) {
           maximize(ans, mid);
           low = mid + 1;
       } else high = mid - 2;
    }
    cout << ans << "\n";
    return 0;
}

