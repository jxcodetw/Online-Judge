#include <cstdio>
#include <climits>
#include <map>
#include <string>
#include <algorithm>

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    
    std::map<char, int> M;
    std::string bin = "BGC";
    for(int i=0;i<bin.length();++i) {
        M[bin[i]] = i;
    }
    std::sort(bin.begin(), bin.end());
    std::string sortedBin = bin;
    
    int input[9], sum[3];
    while(~scanf("%d", &input[0])) {
        for(int i=1;i<9;++i) {
            scanf("%d", &input[i]);
            if ((i+1) % 3 == 0) {
                sum[i/3] = input[i-2] + input[i-1] + input[i];
            }
        }
        
        int min = INT_MAX;
        
        std::string ans;
        bin = sortedBin;
        do {
            int move = 0;
            for(int i=0;i<3;++i) {
                move += sum[i] - input[M[bin[i]] + i * 3];
            }
            if (move < min) {
                min = move;
                ans = bin;
            }
        } while(std::next_permutation(bin.begin(), bin.end()));
        
        printf("%s %d\n", ans.c_str(), min);
    }
    return 0;
}
