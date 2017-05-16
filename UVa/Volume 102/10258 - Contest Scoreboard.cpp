#include <iostream>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <vector>
#include <tuple>

struct Team {
    bool exist;
    bool AC[20];
    int tried[20];
    int id;
    int solved;
    int penalty;
} team[110];

struct Submission {
    int id;
    int problem;
    int time;
    char L;
    
    bool operator<(const Submission &rhs) const {
        return time < rhs.time;
    }
};

bool cmp(const Team *lhs, const Team *rhs) {
    return std::tie(rhs->solved, lhs->penalty, lhs->id)
    < std::tie(lhs->solved, rhs->penalty, rhs->id);
}
int main(int argc, const char * argv[]) {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    
    int N;
    std::string line;
    std::cin >> N;
    std::cin.ignore();
    std::getline(std::cin, line);
    while(N--) {
        memset(team, 0, sizeof(team));
        for(int i=0;i<110;++i) {team[i].id = i;}
        
        std::vector<Submission> submission;
        while(std::getline(std::cin, line) && line != "") {
            Submission s;
            std::stringstream ss(line);
            ss >> s.id >> s.problem >> s.time >> s.L;
            submission.push_back(s);
        }
        std::sort(submission.begin(), submission.end());
        
        std::vector<Team*> contestant;
        for(auto s : submission) {
            Team &t = team[s.id];
            if (!t.exist) {
                t.exist = true;
                contestant.push_back(&t);
            }
            if (!t.AC[s.problem]) {
                if (s.L == 'C') {
                    t.AC[s.problem] = true;
                    t.solved += 1;
                    t.penalty += (s.time + t.tried[s.problem] * 20);
                } else if (s.L == 'I') {
                    t.tried[s.problem] += 1;
                }
            }
        }
        std::sort(contestant.begin(), contestant.end(), cmp);
        for(auto c : contestant) {
            Team &t = *c;
            std::cout << t.id << ' ' << t.solved << ' ' << t.penalty << std::endl;
        }
        
        if (N) {std::cout << std::endl;}
    }
    return 0;
}
