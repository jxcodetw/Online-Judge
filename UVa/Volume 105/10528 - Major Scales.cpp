#include <iostream>
#include <sstream>
#include <vector>
#include <set>

int step[] = {2,2,1,2,2,2,1};
std::string note[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
const int SLEN = sizeof(step) / sizeof(step[0]);
const int NLEN = sizeof(note) / sizeof(note[0]);
std::set<std::string> majorScale[NLEN];

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    for(int i=0;i<NLEN;++i) {
        int s = i;
        for(int j=0;j<SLEN;++j) {
            majorScale[i].insert(note[s%NLEN]);
            s += step[j];
        }
    }
    
    std::string line, str;
    while(std::getline(std::cin, line) && line != "END") {
        std::stringstream ss(line);
        std::vector<std::string> nts;
        while(ss >> str) {
            nts.push_back(str);
        }
        bool hasOutput = false;
        for(int i=0;i<NLEN;++i) {
            bool allIn = true;
            for(auto nt : nts) {
                if (majorScale[i].find(nt) == majorScale[i].end()) {
                    allIn = false;
                    break;
                }
            }
            if (allIn) {
                if (!hasOutput) {hasOutput=true;}
                else {std::cout << ' ';}
                std::cout << note[i];
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
