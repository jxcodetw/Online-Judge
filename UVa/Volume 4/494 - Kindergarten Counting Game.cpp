#include <iostream>

int main(int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    
    std::string str;
    while(std::getline(std::cin, str)) {
        bool last = false;
        int cnt = 0;
        for(int i=0;i<str.length();++i) {
            bool tmp = isalpha(str[i]);
            if (last != tmp) {
                if (last == false) {
                    cnt += 1;
                }
                last = tmp;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
