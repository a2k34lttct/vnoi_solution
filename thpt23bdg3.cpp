#include <bits/stdc++.h>
#define int long long
#define fto(i, a, b) for (int i = a; i <= b; ++i)
using namespace std;
int n;
const int oo = 1000000007;
struct matrix {
    int cell[5][5];
};
matrix nhanmt(matrix A, matrix B) {
    matrix C;
    fto(i, 1, 2) {
        fto(j, 1, 2) {
            C.cell[i][j] = 0;
            fto(k, 1, 2) C.cell[i][j] = (A.cell[i][k] * B.cell[k][j] + C.cell[i][j]) % oo;
        }
    }
    return C;
}
matrix lt(matrix A, int x) {
    if (x == 1) return A;
    if (x & 1) return nhanmt(A, lt(A, x-1));
    matrix T = lt(A, x/2);
    return nhanmt(T, T);
}
signed main() {
    cin >> n;
    matrix A;
    A.cell[1][1] = 1; A.cell[1][2] = 1;
    A.cell[2][1] = 1; A.cell[2][2] = 0;
    if (n == 0) cout << 0 << "\n";
    else if (n <= 2) cout << 1;
    else {
        A = lt(A, n-1);
        cout << A.cell[1][1] << "\n";
    }
}
