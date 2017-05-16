#include <iostream>
#include <algorithm>
#include <sstream>

int group;
int p[1000001], r[1000001];

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
        std::cin >> group;
        std::cin.ignore();
        for(int i=1;i<=group;++i) {
            p[i] = i;
            r[i] = 1;
        }
        int succ = 0, fail = 0;
        while(std::getline(std::cin, line) && line != "") {
            std::stringstream ss(line);
            char type;
            int a, b;
            ss >> type >> a >> b;
            if (type == 'c') {
                _union(a, b);
            } else {
                if (_find(a) == _find(b)) {
                    succ += 1;
                } else {
                    fail += 1;
                }
            }
        }
        std::cout << succ << ',' << fail << std::endl;
        if (N) {std::cout << std::endl;}
    }
    return 0;
}
