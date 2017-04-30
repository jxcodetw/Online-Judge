#include <cstdio>

char buf[2000];
int idx, ans;

class Matrix {
public:
    int row, col;
    Matrix() {}
};
Matrix M[256];
Matrix failMatrix;

Matrix parseMatrix() {
    return M[buf[idx++]];
}

Matrix parseExpression() {
    if (buf[idx] >= 'A' && buf[idx] <= 'Z') {
        return parseMatrix();
    } else if (buf[idx] == '(') {
        idx += 1;
        Matrix m1 = parseExpression();
        Matrix m2 = parseExpression();
        if (m1.row == -1 || m2.row == -1) {
            return failMatrix;
        }
        if (buf[idx] == ')') {
            idx += 1;
            if (m1.col == m2.row) {
                Matrix m;
                m.row = m1.row;
                m.col = m2.col;
                ans += m1.row * m1.col * m2.col;
                return m;
            }
        }
    }
    return failMatrix;
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    failMatrix.row = -1;
    failMatrix.col = -1;
    int N, r, c;
    char label;
    scanf("%d\n", &N);
    while(N--) {
        scanf("%c %d %d\n", &label, &r, &c);
        M[label].row = r;
        M[label].col = c;
    }
    while(fgets(buf, sizeof(buf), stdin)) {
        idx = 0;
        ans = 0;
        Matrix m = parseExpression();
        if (m.row == -1) {
            puts("error");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}
