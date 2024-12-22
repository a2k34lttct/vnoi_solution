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
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
struct node {
    int p, x, d;
};
int n, l, sum, _time, ans;
node a[maxN];
vector<pii> b;
vector<int> pos, neg;
bool cmp(node a, node b) {
    return a.x < b.x;
}
deque<int> energy;
int main() {
    fastio;
    // if (fopen("sinh.inp", "r")) {
    //     freopen("sinh.inp", "r", stdin);
    //     freopen("sinh.out", "w", stdout);
    // }
    cin >> n >> l;
    fto(i, 1, n) {
        cin >> a[i].p >> a[i].x >> a[i].d;
        sum += a[i].p;
    }
    sort(a+1, a+n+1, cmp);
    sum = (sum >> 1) + (sum & 1);
    fto(i, 1, n) {
        if (a[i].d < 0) b.pb({a[i].x, -1});
        else b.pb({l - a[i].x, 1});
    }
    sort(b.begin(), b.end());
    fto(i, 1, n) energy.pb(a[i].p);
    for (pii t : b) {
        if (t.ss == -1) {
            sum -= energy.front();
            energy.pop_front();
        }
        else {
            sum -= energy.back();
            energy.pop_back();
        }
        if (sum <= 0) {
            _time = t.ff;
            break;
        }
    }
    fto(i, 1, n) {
        if (a[i].d == -1) neg.pb(a[i].x);
    }
    fto(i, 1, n) {
        if (a[i].d == 1) {
            int low = 0;
            int high = sz(neg) - 1;
            int p = -1;
            while (low <= high) {
                int mid = (low + high) >> 1;
                if (neg[mid] >= a[i].x) {
                    p = mid;
                    high = mid - 1;
                } else low = mid + 1;
            }
            if (p == -1) continue;
            low = p;
            high = sz(neg) - 1;
            int k = 0;
            while (low <= high) {
                int mid = (low + high) >> 1;
                if (neg[mid] - a[i].x <= 2*_time) {
                    low = mid + 1;
                    k = mid;
                } else high = mid - 1;
            }
            ans += k - p + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}