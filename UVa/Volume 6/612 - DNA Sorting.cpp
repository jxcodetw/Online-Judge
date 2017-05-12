#include <iostream>
#include <algorithm>
#include <vector>

struct DNA {
    int rank;
    std::string seq;
    DNA(std::string seq) : seq(seq) {
        rank = 0;
        for(int i=0;i<seq.length();++i) {
            for(int j=i+1;j<seq.length();++j) {
                if (seq[i] > seq[j]) {
                    rank += 1;
                }
            }
        }
    }
    
    bool operator<(const DNA& rhs) const {
        return rank < rhs.rank;
    }
};

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int M, n, m;
    std::cin >> M;
    while(M--) {
        std::vector<DNA> dna;
        std::cin >> n >> m;
        std::string seq;
        for(int i=0;i<m;++i) {
            std::cin >> seq;
            dna.push_back(DNA(seq));
        }
        
        std::stable_sort(dna.begin(), dna.end());
        
        for(auto d : dna) {
            std::cout << d.seq << std::endl;
        }
        
        if (M) {std::cout << std::endl;}
    }
    return 0;
}
