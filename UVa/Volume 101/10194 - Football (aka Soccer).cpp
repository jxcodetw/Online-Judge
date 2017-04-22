#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>

class Team {
public:
    std::string name;
    std::string lex;
    int point;
    int win;
    int goalDiff;
    int goal;
    int goalAgainst;
    int gamePlayed;
    int tie;
    int loss;
    Team(){}
    Team(std::string name) {
        this->name = name;
        this->lex = name;
        for(int i=0;i<this->lex.length();++i) {
            lex[i] = toupper(lex[i]);
        }
        point = win = loss = tie= goalDiff = goal = goalAgainst = gamePlayed = 0;
    }
};

int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N, T, G;
    std::string line;
    std::cin >> N;
    std::cin.ignore();
    bool first = true;
    while(N--) {
        if (first) {
            first = false;
        } else {
            std::cout << std::endl;
        }
        std::getline(std::cin, line);
        std::cout << line << std::endl;
        
        std::cin >> T;
        std::cin.ignore();
        std::vector<Team> teams;
        std::map<std::string, int> Map;
        for(int i=0;i<T;++i) {
            std::getline(std::cin, line);
            Team t(line);
            teams.push_back(t);
            Map[line] = i;
        }
        
        std::cin >> G;
        std::cin.ignore();
        int g1, g2;
        Team *t1, *t2;
        for(int i=0;i<G;++i) {
            std::getline(std::cin, line);
            auto b = line.find('#')+1;
            t1 = &teams[Map[line.substr(0, b-1)]];
            auto e = line.find('@');
            std::stringstream ss1(line.substr(b, e-b));
            ss1 >> g1;
            b = e+1;
            e = line.find('#', b);
            t2 = &teams[Map[line.substr(e+1)]];
            std::stringstream ss2(line.substr(b, e-b));
            ss2 >> g2;
            t1->gamePlayed += 1;
            t2->gamePlayed += 1;
            t1->goal += g1;
            t2->goal += g2;
            t1->goalAgainst += g2;
            t2->goalAgainst += g1;
            t1->goalDiff += g1-g2;
            t2->goalDiff += g2-g1;
            if (g1 > g2) {
                t1->point += 3;
                t1->win += 1;
                t2->loss += 1;
            } else if (g2 > g1) {
                t2->point += 3;
                t2->win += 1;
                t1->loss += 1;
            } else {
                t1->point += 1;
                t2->point += 1;
                t1->tie += 1;
                t2->tie += 1;
            }
        }
        
        std::sort(teams.begin(), teams.end(), [](Team const &a, Team const &b) -> bool {
            if (a.point > b.point) {return true;}
            if (b.point > a.point) {return false;}
            
            if (a.win > b.win) {return true;}
            if (b.win > a.win) {return false;}
            
            if (a.goalDiff > b.goalDiff) {return true;}
            if (b.goalDiff > a.goalDiff) {return false;}
            
            if (a.goal > b.goal) {return true;}
            if (b.goal > a.goal) {return false;}
            
            if (a.gamePlayed < b.gamePlayed) {return true;}
            if (b.gamePlayed < a.gamePlayed) {return false;}
            
            if (a.lex < b.lex) {return true;}
            if (b.lex < a.lex) {return false;}
            
            return true;
        });
        
        Team *team;
        for(int i=0;i<teams.size();++i) {
            team = &teams[i];
            std::cout << i+1 << ") ";
            std::cout << team->name << " ";
            std::cout << team->point << "p, ";
            std::cout << team->gamePlayed << "g (";
            std::cout << team->win << "-";
            std::cout << team->tie << "-";
            std::cout << team->loss << "), ";
            std::cout << team->goalDiff << "gd (";
            std::cout << team->goal << "-";
            std::cout << team->goalAgainst << ")" << std::endl;
        }
    }
    
    return 0;
}
