#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

void resetMap(int (&map)[26][26], int (&deg)[26]) {
    for(int i=0;i<26;++i) {
        deg[i] = 0;
        for(int j=0;j<26;++j) {
            map[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }
}

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    
    const int MAX = 256;
    
    char buf[MAX];
    int sum = 0;
    int map[26][26];
    int deg[26];
    resetMap(map, deg);
    while(~scanf("%s", buf)) {
        do {
            int len = (int)strlen(buf);
            int i = buf[0] - 'a';
            int j = buf[len-1] - 'a';
            
            if (map[i][j] == INT_MAX) {
                deg[i] += 1;
                deg[j] += 1;
            }
            
            map[i][j] = std::min(map[i][j], len);
            map[j][i] = std::min(map[j][i], len);
            sum += len;
        } while(scanf("%s", buf) && strcmp(buf, "deadend"));
        
        int odeg[2], idx = 0;
        for(int i=0;i<26;++i) {
            if (deg[i] % 2 == 1) {
                odeg[idx++] = i;
            }
        }
        
        if (idx > 0) {
            for(int k=0;k<26;++k) {
                for(int i=0;i<26;++i) {
                    for(int j=0;j<26;++j) {
                        if (map[i][k] != INT_MAX && map[k][j] != INT_MAX) {
                            map[i][j] = std::min(map[i][j], map[i][k] + map[k][j]);
                        }
                    }
                }
            }
            
            sum += map[odeg[0]][odeg[1]];
        }
        
        printf("%d\n", sum);
        
        sum = 0;
        resetMap(map, deg);
    }
    
    return 0;
}
