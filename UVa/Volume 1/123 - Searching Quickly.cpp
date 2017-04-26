#include <cctype>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>

void strLower(std::string &str) {
    for(int i=0;i<str.length();++i) {
        str[i] = tolower(str[i]);
    }
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    std::string line, word;
    std::vector<std::string> title;
    std::set<std::string> ignore;
    std::map<std::string, std::set<int>> keyword;
    // ignore list
    while(std::getline(std::cin, line) && line != "::") {
        strLower(line);
        ignore.insert(line);
    }
    // titles
    while(std::getline(std::cin, line)) {
        strLower(line);
        std::stringstream ss(line);
        while(ss >> word) {
            if (ignore.find(word) == ignore.end()) {
                auto iter = keyword.find(word);
                if (iter == keyword.end()) {
                    std::set<int> s;
                    s.insert((int)title.size());
                    keyword.insert(std::make_pair(word, s));
                } else {
                    iter->second.insert((int)title.size());
                }
            }
        }
        title.push_back(line);
    }
    
    std::string output;
    for(auto s : keyword) {
        word = s.first;
        for(auto idx : s.second) {
            line = title[idx];
            size_t pos = line.find(word, 0);
            while(pos != std::string::npos) {
                output = line;
                for(size_t i=pos;i<pos+word.length();++i) {
                    output[i] = toupper(output[i]);
                }
                if (pos+word.length() >= output.length() ||
                    output[pos+word.length()] == ' ') {
                    std::cout << output << std::endl;
                }
                pos = line.find(word, pos+1);
            }
        }
    }
    return 0;
}
