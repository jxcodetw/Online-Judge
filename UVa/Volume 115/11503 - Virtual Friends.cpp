#include <iostream>
#include <algorithm>
#include <map>

int id;
int p[200010], r[200010];

int _find(int n) {
    return (n == p[n]) ? n : (p[n] = _find(p[n]));
}

void _union(int a, int b) {
    int pa = _find(a);
    int pb = _find(b);
    if (pa != pb) {
        // make sure pa has more member
        if (r[pa] < r[pb]) {
            std::swap(pa, pb);
        }
        r[pa] += r[pb];
        p[pb] = pa;
    }
    std::cout << r[pa] << std::endl;
}

std::map<std::string, int> M;
int getID(std::string &name) {
    auto iter = M.find(name);
    int res;
    if (iter == M.end()) {
        res = id;
        M.insert(std::make_pair(name, id));
        p[id] = id;
        r[id] = 1;
        id += 1;
    } else {
        res = iter->second;
    }
    return res;
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N, T;
    std::cin >> T;
    while(T--) {
        std::cin >> N;
        id = 0;
        M.clear();
        std::string a, b;
        while(N--) {
            std::cin >> a >> b;
            _union(getID(a), getID(b));
        }
    }
    return 0;
}
