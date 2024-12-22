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
int n, a[maxN], ans;
struct Node {
    Node *child[2];
    int exists, prefix;
    Node() {
        exists = prefix = 0;
        child[0] = child[1] = NULL;
    }
};
struct Trie {
    Node *root;
    Trie() {
        root = new Node();
    }
    void insert(int &x) {
        Node *p = root;
        fdto(i, 31, 0) {
            int cur_bit = BIT(x, i);
            if (p -> child[cur_bit] == NULL) p -> child[cur_bit] = new Node();
            p = p -> child[cur_bit];
            ++p->prefix;
        }
        ++p->exists;
    }
    void del(int &x) {
        Node *p = root;
        fdto(i, 31, 0) {
            int cur_bit = BIT(x, i);
            if (p -> child[cur_bit] != NULL) {
                p = p -> child[cur_bit];
                --(p -> prefix);
            }
        }
        --(p -> exists);
        if (p -> exists == 0 && p -> prefix == 0 && p -> child[0] == NULL && p -> child[1] == NULL) delete(p);
    }
    int get(int &x, int r) {
        int res = r;
        Node *p = root;
        fdto(i, 31, 1) {
            int un_needed = BIT(x, i) ^ 1;
            if (p -> child[un_needed]) res -= p -> child[un_needed] -> prefix;
            p = p -> child[un_needed ^ 1];
        }
        return res;
    }
};
signed main() {
    fastio;
    if (fopen("fcc2023_xor01.inp", "r")) {
        freopen("fcc2023_xor01.inp", "r", stdin);
        freopen("fcc2023_xor01.out", "w", stdout);
    }
    cin >> n;
    Trie str;
    fto(i, 1, n) {
        cin >> a[i];
        str.insert(a[i]);
    }
    fto(i, 1, n) {
        ans += str.get(a[i], n - i + 1) - 1;
        str.del(a[i]);
    }
    cout << ans << "\n";
    return 0;
}

