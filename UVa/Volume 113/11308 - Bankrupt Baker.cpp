#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

struct Recipe {
    std::string name;
    int cost;
    
    bool operator<(const Recipe &rhs) const {
        return std::tie(cost, name) < std::tie(rhs.cost, rhs.name);
    }
};

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int T, m, n, b, c, k, x;
    std::cin >> T;
    std::string title, ingredient, name;
    while(T--) {
        std::cin.ignore();
        std::getline(std::cin, title);
        for(int i=0;i<title.length();++i) {
            if (title[i] >= 'a' && title[i] <= 'z') {
                title[i] += 'A' - 'a';
            }
        }
        std::cout << title << std::endl;
        std::cin >> m >> n >> b;
        
        std::map<std::string, int> M;
        while(m--) {
            std::cin >> ingredient >> c;
            M[ingredient] = c;
        }
        
        std::vector<Recipe> recipe;
        for(int i=0;i<n;++i) {
            std::cin.ignore();
            int cost = 0;
            std::getline(std::cin, name);
            std::cin >> k;
            while(k--) {
                std::cin >> ingredient >> x;
                cost += M[ingredient] * x;
            }
            
            if (cost <= b) {
                recipe.push_back({name, cost});
            }
        }
        
        if (recipe.size() == 0) {
            std::cout << "Too expensive!" << std::endl;
        } else {
            std::sort(recipe.begin(), recipe.end());
            for(auto r : recipe) {
                std::cout << r.name << std::endl;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
