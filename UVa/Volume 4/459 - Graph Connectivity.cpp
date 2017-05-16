#include <iostream>
#include <algorithm>


int group;
int p[30], r[30];

int _find(int n) {
    return (n == p[n]) ? n : (p[n] = _find(p[n]));
}

void _union(int a, int b) {
    int pa = _find(a);
    int pb = _find(b);
    if (pa != pb) {
        group -= 1;
        if (r[pa] > r[pb]) {
            r[pa] += r[pb];
            p[pb] = pa;
        } else {
            r[pb] += r[pa];
            p[pa] = pb;
        }
    }
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N;
    std::string line;
    std::cin >> N;
    std::cin.ignore();
    std::getline(std::cin, line);
    while(N--) {
        std::getline(std::cin, line);
        group = line[0] - 'A' + 1;
        for(int i=0;i<group;++i) {
            p[i] = i;
            r[i] = 1;
        }
        while(std::getline(std::cin, line) && line != "") {
            _union(line[0]-'A', line[1]-'A');
        }
        std::cout << group << std::endl;
        if (N) {std::cout << std::endl;}
    }
    return 0;
}
