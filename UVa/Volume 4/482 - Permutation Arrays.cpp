#include <iostream>
#include <vector>
#include <sstream>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    
    int N, n;
    std::cin >> N;
    std::cin.ignore();
    while(N--) {
        std::string strp, strf;
        std::getline(std::cin, strp);
        std::getline(std::cin, strp);
        std::getline(std::cin, strf);
        std::stringstream ssp(strp);
        std::stringstream ssf(strf);
        std::vector<int> vp;
        while(ssp >> n) {
            vp.push_back(n);
        }
        std::vector<int> p;
        p.resize(vp.size());
        for(int i=0;i<vp.size();++i) {
            p[vp[i]-1] = i;
        }
        
        std::string f;
        std::vector<std::string> vf;
        while(ssf >> f) {
            vf.push_back(f);
        }
        
        for(int i : p) {
            std::cout << vf[i] << std::endl;
        }
        if (N) {std::cout << std::endl;}
    }
    return 0;
}
