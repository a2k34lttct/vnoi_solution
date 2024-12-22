/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define int long long
#define sz(a) a.size()
#define cell(a, i, j) a.cell[i][j]
#define ll long long
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define mem(x, a) memset(x, a, sizeof x)
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) {
    return l + rd() % (r - l + 1);
}
void sinhtest() {
    ofstream inp("sinh.inp");
    int n = rand(1, 10);
    int m = rand(n, 20);
    int a = rand(1, n);
    int b = rand(a, n);
    inp << n << " " << m << " " << a << " " << b << "\n";
    fto(i, 1, m) {
        int k = rand(1, m);
        fto(j, 1, k) inp << rand(1, 10) << " ";
        inp << "\n";
    }
    inp.close();
}
signed main() {
    fastio;
    fto(itest, 1, 10000) {
        sinhtest();
        system("sinhchuan.exe");
        system("sinhcham.exe");
        if (system("fc sinh.ans sinh.out") != 0) {
            cout << "TEST " << itest << ": WRONG ANSWER\n";
            return 0;
        }
    }
    return 0;
}
