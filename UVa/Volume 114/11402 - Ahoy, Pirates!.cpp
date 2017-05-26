#include <iostream>

const char NOP = 'X';
const char SET = 'F';
const char RESET = 'E';
const char FLIP = 'I';

int pirate[2000000];

struct Node {
    int val, len;
    Node *l, *r;
    char op;
    
    int getVal() {
        if (op == SET) {
            return len;
        } else if (op == RESET) {
            return 0;
        } else if (op == FLIP) {
            return len - val;
        }
        return val;
    }
    
    void changeVal(char o) {
        if (o == SET || o == RESET) {
            op = o;
        } else if (o == FLIP) {
            if (op == FLIP) {
                op = NOP;
            } else if (op == NOP) {
                op = FLIP;
            } else if (op == SET) {
                op = RESET;
            } else if (op == RESET) {
                op = SET;
            }
        }
    }
    
    void pull() {
        val = l->getVal() + r->getVal();
        op = NOP;
    }
    
    void push() {
        l->changeVal(op);
        r->changeVal(op);
    }
} segment_tree[8000000];

Node* build(int idx, int L, int R) {
    Node *now = &segment_tree[idx];
    now->op = NOP;
    now->len = 1;
    if (L == R) {
        now->val = pirate[L];
        return now;
    }
    
    int m = (L+R)/2, lidx = (idx<<1)+1, ridx=lidx+1;
    now->l = build(lidx, L, m);
    now->r = build(ridx,m+1, R);
    now->val = now->l->val + now->r->val;
    now->len = now->l->len + now->r->len;
    return now;
}

int query(Node *now, int L, int R, int x, int y) {
    if (y < L || x > R) {
        return 0;
    } else if (x<=L && R<=y) {
        return now->getVal();
    }
    now->push();
    int m = (L+R)/2;
    int ans = query(now->l,   L, m, x, y) +
              query(now->r, m+1, R, x, y);
    now->pull();
    return ans;
}

void update(Node *now, int L, int R, int x, int y, char op) {
    if (y < L || x > R) {
        return;
    } else if (x<=L && R<=y) {
        now->changeVal(op);
        return;
    }
    now->push();
    int m = (L+R)/2;
    update(now->l, L,   m, x, y, op);
    update(now->r, m+1, R, x, y, op);
    now->pull();
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int T, N, Q, rep;
    std::string str;
    std::cin >> T;
    for(int c=1;c<=T;++c) {
        std::cout << "Case " << c << ":" << std::endl;
        std::cin >> N;
        int idx = 0;
        while(N--) {
            std::cin >> rep >> str;
            while(rep--) {
                for(int i=0;i<str.size();++i) {
                    pirate[idx++] = str[i] - '0';
                }
            }
        }
        
        // build tree
        int N = idx;
        Node *root = build(0, 0, N - 1);
        
        std::cin >> Q;
        int q = 1, a, b;
        char op;
        while(Q--) {
            std::cin >> op >> a >> b;
            if (op == 'S') {
                std::cout << "Q" << q++ << ": ";
                std::cout << query(root, 0, N-1, a, b) << std::endl;
            } else {
                // update
                update(root, 0, N-1, a, b, op);
            }
        }
    }
    return 0;
}
