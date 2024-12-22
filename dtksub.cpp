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
int n, k, ans;
string s;
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
            power[i] = (power[i-1] * base) % oo;
            hash[i] = (hash[i-1] * base + s[i]) % oo;
        }
    }
    int get_hash(int l, int r) {
        return (hash[r] - (l - 1 < 0 ? 0 : hash[l-1]) * power[r - l + 1] + oo * oo) % oo;
    }
};
Hash str(311, oo);
unordered_map<int, int> cnt;
int check(int x) {
    fto(i, 0, sz(s) - 1) {
        ++cnt[str.get_hash(i, i + x - 1)];
        if (cnt[str.get_hash(i, i + x - 1)] >= k) {
            return 1;
        }
    }
    return 0;
}
signed main() {
    fastio;
    if (fopen("dtksub.inp", "r")) {
        freopen("dtksub.inp", "r", stdin);
        freopen("dtksub.out", "w", stdout);
    }
    cin >> n >> k;
    cin >> s;
    str.hashing(s);
    int low = 0;
    int high = sz(s);
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (check(mid)) {
            ans = mid;
            low = mid + 1;
        } else high = mid - 1;
    }
    cout << ans << "\n";
    return 0;
}

