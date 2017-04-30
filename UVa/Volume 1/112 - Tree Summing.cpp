#include <cstdio>
#include <cstdlib>

class Node {
public:
    int val;
    Node *l, *r;
};

char c;
int T;
bool found;

bool whitespace(char c) {
    return c == ' ' || c == '\n';
}

void nextChar() {
    while((c=getchar()) && whitespace(c));
}

void match(char tc) {
    nextChar();
    if (tc != c) {
        printf("expecting %c, %c\n", tc, c);
        exit(1);
    } else {
        nextChar();
    }
}

int parseNum() {
    if (c == EOF) {
        return -1;
    }
    int num = 0;
    bool neg = false;
    if (c == '-') {
        neg = true;
        nextChar();
    }
    while(c >= '0' && c <= '9') {
        num = num * 10 + c - '0';
        nextChar();
    }
    return neg ? -num : num;
}

Node* parseTree() {
    Node *node = nullptr;
    
    if (c != ')') {
        node = new Node();
        node->val = parseNum();
        nextChar();
        node->l = parseTree();
        nextChar();
        node->r = parseTree();
    }
    nextChar();
    return node;
}

void dfs(Node* node, int sum) {
    if (!found && node != nullptr) {
        sum += node->val;
        if (node->l == nullptr && node->r == nullptr) {
            if (sum == T) {
                found = true;
            }
        }
        dfs(node->l, sum);
        dfs(node->r, sum);
    }
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    while(scanf("%d", &T) == 1) {
        nextChar();
        nextChar();
        Node *root = parseTree();
        found = false;
        dfs(root, 0);
        if (found) {
            puts("yes");
        } else {
            puts("no");
        }
        ungetc(c, stdin);
    }
    return 0;
}
