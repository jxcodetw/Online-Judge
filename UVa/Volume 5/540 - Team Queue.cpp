#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <map>

char cmd[100];
bool TQ[1000+10];
std::vector<std::queue<int>> V;

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    
    int T, scen = 0, n, id;
    while(scanf("%d", &T) == 1 && T != 0) {
        printf("Scenario #%d\n", ++scen);
        memset(TQ, 0, sizeof(TQ));
        std::queue<std::queue<int>*> Q;
        std::map<int, int> M;
        V.clear();
        
        for(int i=0;i<T;++i) {
            scanf("%d", &n);
            std::queue<int> q;
            V.push_back(q);
            for(int j=0;j<n;++j) {
                scanf("%d", &id);
                M.insert(std::make_pair(id, i));
            }
        }
        
        while(scanf("%s", cmd) == 1 && strcmp(cmd, "STOP")) {
            scanf("%d", &id);
            int t = M[id];
            if (strcmp(cmd, "ENQUEUE") == 0) {
                V[t].push(id);
                if (!TQ[t]) {
                    TQ[t] = true;
                    Q.push(&V[t]);
                }
            } else {
                std::queue<int>* q = Q.front();
                id = q->front();
                printf("%d\n", id);
                q->pop();
                if (q->empty()) {
                    TQ[M[id]] = false;
                    Q.pop();
                }
            }
        }
        putchar('\n');
    }
    return 0;
}
