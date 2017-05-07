#include <iostream>
#include <vector>
#include <queue>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N, M, n;
    while(std::cin >> N >> M && (N!=0&&M!=0)) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> head, knight;
        for(int i=0;i<N;++i) {
            std::cin >> n;
            head.push(n);
        }
        for(int i=0;i<M;++i) {
            std::cin >> n;
            knight.push(n);
        }
        
        int sum = 0;
        while(!head.empty() && !knight.empty()) {
            if (knight.top() >= head.top()) {
                sum += knight.top();
                knight.pop();
                head.pop();
            } else {
                knight.pop();
            }
        }
        if (head.empty()) {
            std::cout << sum << std::endl;
        } else {
            std::cout << "Loowater is doomed!" << std::endl;
        }
    }
    return 0;
}
