#include <iostream>
#include <cstring>

bool v[26];
int cnt[26];

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N;
    std::string question, guess;
    while(std::cin >> N && N != -1) {
        std::cin >> question >> guess;
        memset(v, 0, sizeof(v));
        memset(cnt, 0, sizeof(cnt));
        
        for(int i=0;i<question.length();++i) {
            cnt[question[i]-'a'] += 1;
        }
      
        int correctCnt = 0, wrongCnt = 0;
        for(int i=0;i<guess.length() && correctCnt != question.length() && wrongCnt < 7; ++i) {
            char c = guess[i] - 'a';
            if (v[c] == false) {
                v[c] = true;
                if (cnt[c] > 0) {
                    correctCnt += cnt[c];
                } else {
                    wrongCnt += 1;
                }
            }
        }
        std::cout << "Round " << N << std::endl;
        if (wrongCnt == 7) {
            std::cout << "You lose." << std::endl;
        } else if (correctCnt == question.length()) {
            std::cout << "You win." << std::endl;
        } else {
            std::cout << "You chickened out." << std::endl;
        }
    }
    return 0;
}
