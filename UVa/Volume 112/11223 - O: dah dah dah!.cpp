#include <iostream>
#include <sstream>
#include <map>

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    std::map<std::string, char> r;
    r[".-"] = 'A', r["-..."] = 'B', r["-.-."] = 'C';
    r["-.."] = 'D', r["."] = 'E', r["..-."] = 'F';
    r["--."] = 'G', r["...."] = 'H', r[".."] = 'I';
    r[".---"] = 'J', r["-.-"] = 'K', r[".-.."] = 'L';
    r["--"] = 'M', r["-."] = 'N', r["---"] = 'O';
    r[".--."] = 'P', r["--.-"] = 'Q', r[".-."] = 'R';
    r["..."] = 'S', r["-"] = 'T', r["..-"] = 'U';
    r["...-"] = 'V', r[".--"] = 'W', r["-..-"] = 'X';
    r["-.--"] = 'Y', r["--.."] = 'Z', r["-----"] = '0';
    r[".----"] = '1', r["..---"] = '2', r["...--"] = '3';
    r["....-"] = '4', r["....."] = '5', r["-...."] = '6';
    r["--..."] = '7', r["---.."] = '8', r["----."] = '9';
    r[".-.-.-"] = '.', r["--..--"] = ',', r["..--.."] = '?';
    r[".----."] = '\'', r["-.-.--"] = '!', r["-..-."] = '/';
    r["-.--."] = '(', r["-.--.-"] = ')', r[".-..."] = '&';
    r["---..."] = ':', r["-.-.-."] = ';', r["-...-"] = '=';
    r[".-.-."] = '+', r["-....-"] = '-', r["..--.-"] = '_';
    r[".-..-."] = '\"', r[".--.-."] = '@';
    int N, t = 1;
    std::cin >> N;
    std::cin.ignore();
    std::string line, str;
    while(N--) {
        std::cout << "Message #" << t++ << std::endl;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        int idx = 0;
        while(idx < line.length()) {
            if (line[idx] == ' ') {
                idx+=1;
                std::cout << ' ';
            } else {
                str = "";
                while(line[idx] != ' ' && idx < line.length()) {
                    str += line[idx++];
                }
                idx += 1;
                std::cout << r[str];
            }
        }
        std::cout << std::endl;
        if (N) {std::cout << std::endl;}
    }
    return 0;
}
