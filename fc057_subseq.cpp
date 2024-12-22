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
struct quest {
    int num, l, r;
};
int n, q, a[maxN], b[maxN], color[maxN];
vector<int> pos[maxN];
vector<quest> question;
bool cmp(quest a, quest b) {return a.r < b.r;}
int main() {
    fastio;
    if (fopen("fc057_subseq.inp", "r")) {
        freopen("fc057_subseq.inp", "r", stdin);
        freopen("fc057_subseq.out", "w", stdout);
    }
    cin >> n >> q;
    fto(i, 1, n) cin >> a[i], b[i] = a[i];
    sort(b+1, b+n+1);
    fto(i, 1, n) color[i] = color[i-1] + (b[i] != b[i-1]);
    fto(i, 1, n) {
        int low = 1;
        int high = n;
        int p = i;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (b[mid] >= a[i]) {
                p = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        a[i] = color[p];
    }
    fto(i, 1, q) {
        int l, r; cin >> l >> r;
        quest tmp;
        tmp.l = l; tmp.r = r; tmp.num = i;
        question.pb(tmp);
    }
    sort(question.begin(), question.end(), cmp);
    
    return 0;
}

