#include <iostream>
#include <cstdio>

struct Proposal {
    std::string name;
    float price;
    int met;
};

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N, P, t = 0;
    std::string name, line;
    while(std::cin >> N >> P &&(N!=0&&P!=0)) {
        if (t) {putchar('\n');}
        std::cin.ignore();
        for(int i=0;i<N;++i) {std::getline(std::cin, line);}
        
        Proposal win, cur;
        win.met = -1;
        for(int i=0;i<P;++i) {
            std::getline(std::cin, cur.name);
            std::cin >> cur.price >> cur.met;
            std::cin.ignore();
            for(int i=0;i<cur.met;++i) {std::getline(std::cin, line);}
            if (cur.met > win.met || (cur.met == win.met && cur.price < win.price)) {
                win = cur;
            }
        }
        std::cout << "RFP #" << ++t << std::endl;
        std::cout << win.name << std::endl;
    }
    return 0;
}
