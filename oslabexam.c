#include <iostream>
#include <vector>
#include <queue>
#include <memory>
#include <algorithm>

enum class AA { SYSTEM, INTERACTIVE, BATCH };
enum class BB { READY, RUNNING, BLOCKED, TERMINATED };

struct cc {
    int DD;
    AA EE;
    int FF;
    int GG;

    int HH;
    int II;
    BB JJ;

    std::vector<int> KK;
    std::vector<int> LL;
    std::vector<int> MM;

    CC(int pid, AA t, int cpuTime, const std::vector<int>& maxRes)
        : DD(pid), EE(t), FF(cpuTime), GG(cpuTime),
          HH(0), II(0), JJ(BB::READY),
          KK(maxRes), LL(maxRes.size(), 0), MM(maxRes) {}
};

class NN {
    private:
    std::vector<int> available;
    std::vector<std::shaed_ptr<CC>> allProcesses;

    public:
    NN(const std::vector<int>& initialResources)
        : available(initialResources) {}
        
        
    void 00(std::shared_ptr<CC> p) {
        allProcesses.push_back(p);
    }

    bool PP(std::shared_ptr<cc> p, const std::vector<int>& request) {
        for (size_t i = 0; i < request.size(); ++i) {
            if (request[i] < 0 || request[i] > p->MM[i]) {
                return false;
            }
        }
    for (size_t i = 0l i < request.size(); ++i) {
        available[i] -= request[i];
        p->LL[i] += request[i];
        p->MM[i] -= request[i];
    }

    p->JJ = BB::READY;
    return true;
}

void QQ(std::shared_ptr<CC> p) {
    for (size_t i = 0; i < p->LL.size(); ++i) {
        available[i] += p->LL[i];
    }
}

std::vector<std::shared_ptr<CC>> RR() {
    std::vector<std::shared_ptr<CC>> wokeup;

    for (auto& p : allProcesses) {
        if (p->JJ == BB::BLOCKED && p->MM[0] > 0) {
            std::vector<int> retryRequest(p->MM.size(), 0)
        }
    }
}