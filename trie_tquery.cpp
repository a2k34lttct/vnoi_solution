/*Code by Hoang Thai*/
#include <bits/stdc++.h>

#define pb push_back
#define reverse(x) reverse(x.begin(), x.end())
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
const int maxN = 2;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};

struct Node {
    Node *child[maxN];
    int exist, prefix, sum, num;
    Node() {
        exist = prefix = sum = num = 0;
        fto(i, 0, 1) child[i] = NULL;
    }
};

struct Trie {
    Node *root;
    Trie() {
        root = new Node();
    }

    void insert(int n) {
        Node *p = root;
        fdto(i, 31, 0) {
            int bit = BIT(n, i);
            if (p->child[bit] == NULL) p->child[bit] = new Node();
            p = p -> child[bit];
            p -> sum += n;
            ++p -> prefix;
        }
        p -> num = n;
        ++p -> exist;
    }

    bool search(int n) {
        Node *p = root;
        fdto(i, 31, 0) {
            int bit = BIT(n, i);
            if (p -> child[bit] == NULL) return 0;
            p = p->child[bit];
        }
        return (p -> exist > 0);
    }

    void remove(int n) {
        if (!search(n)) return;
        Node *p = root;
        fdto(i, 31, 0) {
            int bit = BIT(n, i);
            p-> child[bit] -> prefix--;
            p-> child[bit] -> sum -= n;
            if (p -> child[bit] -> prefix == 0) {
                p -> child[bit] = NULL;
                return;
            }
            p = p -> child[bit];
        }
        --p -> exist;
    }

    int Sum(int n) {
        Node *p = root;
        int res = 0;
        fdto(i, 31, 0) {
            int bit = BIT(n, i);
            if (bit) {
                if (p -> child[0]) res += p -> child[0] -> sum;
                if (p -> child[1]) p = p -> child[1];
                else return res;
            }
            else {
                if (p -> child[0]) p = p -> child[0];
                else return res;
            }
        }
        res += p->sum;
        return res;
    }

    int getSum(int l, int r) {
        if (l == 0) return Sum(r);
        return Sum(r) - Sum(l-1);
    }

    int FindKth(int n) {
        Node *p = root;
        fdto(i, 31, 0) {
            if (p->child[0]) {
                if (p->child[0]->prefix >= n) p = p->child[0];
                else if (p->child[1]) {
                    n -= p->child[0]->prefix;
                    p = p->child[1];
                }
            }
            else p = p->child[1];            
        }
        return p->num;
    }

    int compute(int n) {
        Node *p = root;
        if (p->child[0] == NULL) return n;
        int x = 0;
        fdto(i, 31, 0) {
            int bit = BIT(n, i);
            if (p->child[!bit] != NULL) bit = !bit;
            if (bit) x += MASK(i);
            p = p->child[bit];
        }
        return (n^x);
    }
};

Trie trie;
int n, T, x;

void solve() {
    int type; cin >> type;
    if (type == 1) {
        int x; cin >> x;
        trie.insert(x);
    }
    if (type == 2) {
        int x; cin >> x;
        trie.remove(x);
    }
    if (type == 3) {
        int l, r; cin >> l >> r;
        cout << trie.getSum(l, r) << endl;
    }
    if (type == 4) {
        int k; cin >> k;
        cout << trie.FindKth(k) << endl;
    }
    if (type == 5) {
        int a; cin >> a;
        cout << trie.compute(a) << endl;
    }
}

signed main() {
    fastio;
    if (fopen("trie_tquery.inp", "r")) {
        freopen("trie_tquery.inp", "r" ,stdin);
        freopen("trie_tquery.out", "w" ,stdout);
    }
    cin >> T;
    while (T--) solve();
    return 0;
}