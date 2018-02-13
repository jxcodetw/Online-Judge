#include <iostream>
#include <climits>
#include <queue>
#include <vector>

int f[] = {2, 3, 5, 7};

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    
    std::vector<int> T;
    std::priority_queue<int, std::vector<int>, std::greater<int>> PQ;
    PQ.push(1);
    
    while(T.size() < 5842) {
        int num = PQ.top();
        T.push_back(num);
        
        for(int i=0;i<4;++i) {
            if (num > INT_MAX / f[i]) {
                break;
            }
            PQ.push(num * f[i]);
        }
        while(PQ.top() == num) {
            PQ.pop();
        }
    }
    int N;
    while(std::cin >> N && N != 0) {
        std::cout << "The " << N;
        if (N % 10 == 1 && N % 100 != 11) {
            std::cout << "st";
        } else if (N % 10 == 2 && N % 100 != 12) {
            std::cout << "nd";
        } else if (N % 10 == 3 && N % 100 != 13) {
            std::cout << "rd";
        } else {
            std::cout << "th";
        }
        std::cout << " humble number is " << T[N-1] << "." << std::endl;
    }
    return 0;
}
