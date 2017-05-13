#include <iostream>
#include <vector>
#include <stack>

struct Card {
    char rank, suit;
    Card() {}
    Card(const std::string &s) {
        rank=s[0];
        suit=s[1];
    }
    
    bool operator==(const Card &rhs) const {
        return rank == rhs.rank || suit == rhs.suit;
    }
};

void addCard(std::vector<std::stack<Card>> &Pile, const std::string &s) {
    Card c(s);
    std::stack<Card> S;
    S.push(c);
    Pile.push_back(S);
}

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);

    
    std::string s;
    while(std::cin >> s) {
        if (s == "#") {break;}
        
        std::vector<std::stack<Card>> Pile;
        addCard(Pile, s);
        for(int i=2;i<=52;++i) {
            std::cin >> s;
            addCard(Pile, s);
            bool move;
            do {
                move = false;
                for(int i=0;i<Pile.size();++i) {
                    if (i>=3 && Pile[i].top() == Pile[i-3].top()) {
                        Pile[i-3].push(Pile[i].top());
                    } else if (i>=1 && Pile[i].top() == Pile[i-1].top()) {
                        Pile[i-1].push(Pile[i].top());
                    } else {continue;}
                    Pile[i].pop();
                    if (Pile[i].empty()) {
                        Pile.erase(Pile.begin()+i);
                    }
                    move = true;
                    break;
                }
            } while(move);
        }
        std::cout << Pile.size() << " pile" << ((Pile.size()>1)?"s":"") << " remaining:";
        for(auto s : Pile) {
            std::cout << ' ' << s.size();
        }
        std::cout << std::endl;
    }
    
    return 0;
}
