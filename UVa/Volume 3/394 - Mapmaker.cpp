#include <iostream>
#include <map>

class Array {
public:
    std::string name;
    int B, D, E;
    int L[20], U[20], C[20];
    
    Array(std::string name, int B, int E, int D) : name(name), B(B), E(E), D(D) {
        int l, u;
        for(int i=1;i<=D;++i) {
            std::cin >> l >> u;
            L[i] = l;
            U[i] = u;
        }
        C[D] = E;
        for(int i=D-1;i>=1;--i) {
            C[i] = C[i+1] * (U[i+1] - L[i+1] +1);
        }
        C[0] = B;
        for(int i=1;i<=D;++i) {
            C[0] -= C[i] * L[i];
        }
    }
    
    void ref() {
        int addr = C[0], idx;
        std::cout << name << '[';
        for(int i=1;i<=D;++i) {
            std::cin >> idx;
            addr += C[i] * idx;
            if (i != 1) {
                std::cout << ", ";
            }
            std::cout << idx;
        }
        std::cout << "] = " << addr << std::endl;
    }
};

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int B, D, E, N, R;
    std::string name;
    std::map<std::string, Array*> M;
    std::cin >> N >> R;
    while(N--) {
        std::cin >> name >> B >> E >> D;
        M.insert(std::make_pair(name, new Array(name, B, E, D)));
    }
    while(R--) {
        std::cin >> name;
        M.find(name)->second->ref();
    }
    return 0;
}

