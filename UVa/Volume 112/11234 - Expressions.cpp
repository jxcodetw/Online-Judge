#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>

class Node {
public:
    char c;
    Node *l, *r;
    Node(char c) : c(c), l(nullptr), r(nullptr) {}
};

const int MAX = 10000+10;
char buf[MAX];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int T, len;
    scanf("%d\n", &T);
    while(T--) {
        fgets(buf, sizeof(buf), stdin);
        len = (int)strlen(buf);
        buf[len-1] = '\0';
        len -= 1;
        
        // construct tree
        std::stack<Node*> S;
        for(int i=0;i<len;++i) {
            char c = buf[i];
            Node *node = new Node(c);
            if (c >= 'A' && c <= 'Z') {
                node->r = S.top();S.pop();
                node->l = S.top();S.pop();
            }
            S.push(node);
        }
        
        std::queue<Node*> Q;
        Q.push(S.top());
        while(!Q.empty()) {
            Node *node = Q.front();Q.pop();
            buf[--len] = node->c;
            if (node->l != nullptr) {Q.push(node->l);}
            if (node->r != nullptr) {Q.push(node->r);}
        }
        
        puts(buf);
    }
    return 0;
}
