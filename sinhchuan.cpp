#include <bits/stdc++.h>
#define maxN 105

using namespace std;

int n, m, u, v, ans, cnt, f[maxN], a[maxN][maxN], k[maxN], q[maxN];

int findGift(int pos, int lt, int dem) {
    q[dem] = a[pos][lt];
    int bf = f[a[pos][lt]];
    if (k[bf] <= 1) return 0;
    for (int i = 1; i <= k[bf]; ++i) {
        int ok = 1;
        for (int j = 1; j <= dem; ++j) {
            if (a[bf][i] == q[j]) ok = 0;
        }
        if (ok == 0) continue;
        if (a[bf][i] == a[pos][lt]) continue;
        if (f[a[bf][i]] == 0) {
            f[a[bf][i]] = bf;
            f[a[pos][lt]] = pos;
            return 1;
        }
        else {
            if (findGift(bf, i, dem+1)) {
                f[a[pos][lt]] = pos;
                return 1;
            }
        }
    }
    return 0;
}
void solve(int j) {
    for (int i = 1; i <= n; ++i) {
        int ok = 0;
        if (k[i] >= 1) {
            for (int j = 1; j <= k[i]; ++j) {
                if (ok == 1) continue;
                if (f[a[i][j]] == 0) {
                    f[a[i][j]] = i;
                    ++cnt;
                    ok = 1;
                } else {
                    if (findGift(i, j, 1)) {
                        ++cnt;
                        ok = 1;
                    }
                }
            }
        }
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("sinh.inp", "r", stdin);
    freopen("sinh.ans", "w", stdout);
    memset(f, 0, sizeof(f));
    cin >> n >> m >> u >> v;
    for (int i = 1; i <= n; ++i) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; ++j) {
            cin >> a[i][j];
        }
    }
    ans = 0;
    for (int i = v; i >= u; --i) {
        if (n % i == 0) {
            ans = n/i;
            break;
        }
    }
    if (ans <= 0) cout << -1 << "\n";
    else cout << ans << "\n";
    cnt = 0;
    solve(1);
    cout << cnt << "\n";
    return 0;
}
