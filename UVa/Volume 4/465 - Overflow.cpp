#include <cstdio>
#include <climits>

char buf[2000];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    double n1, n2;
    char op;
    while(fgets(buf, sizeof(buf), stdin)) {
        sscanf(buf, "%lf %c %lf", &n1, &op, &n2);
        printf("%s", buf);
        if (n1 > INT_MAX) {
            puts("first number too big");
        }
        if (n2 > INT_MAX) {
            puts("second number too big");
        }
        if ((op == '+' && n1 + n2 > INT_MAX) ||
            (op == '*' && n1 * n2 > INT_MAX)) {
            puts("result too big");
        }
    }
    return 0;
}
