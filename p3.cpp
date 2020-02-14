#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    long long N;
    std::vector<long long> sir;
    long long dp;

    void findMaxim(const std::vector<long long> &sir) {
        std::vector<std::vector<std::pair<long long, long long>>> pos
        (sir.size(), std::vector<std::pair<long long, long long>>(sir.size()));
        // Initializam matricea pe diagonala cu elementele vectorului sir
        for (unsigned i = 0; i < sir.size(); i++) {
           // Primul element din pereche va fi numarul din sir
           pos[i][i].first = sir[i];
           // Al doilea element din pereche va fi 0
           pos[i][i].second = 0;
        }

        for (unsigned l = 2; l <= sir.size(); l++) {
            for (unsigned i = 0; i <= sir.size() - l; i++) {
                long long j = i + l - 1;
                // Folosim recurenta gasita in functie de pozitie
                if (sir[i] + pos[i + 1][j].second >
                   pos[i][j - 1].second + sir[j]) {
                   pos[i][j].first = sir[i] + pos[i + 1][j].second;
                   pos[i][j].second = pos[i + 1][j].first;
                } else {
                   pos[i][j].first = sir[j] + pos[i][j - 1].second;
                   pos[i][j].second = pos[i][j - 1].first;
                }
            }
        }
        dp = pos[0][sir.size() - 1].first - pos[0][sir.size() - 1].second;
    }

    void read_input() {
        std::ifstream fin("p3.in");
        fin >> N;
        long long n;
        for (long long i = 0; i < N; i++) {
            fin >> n;
            sir.push_back(n);
        }
        fin.close();
    }

    long long get_result() {
        findMaxim(sir);
        return dp;
    }

    void print_output(long long result) {
        std::ofstream fout("p3.out");
        fout << result;
        fout.close();
    }
};

int main() {
    Task task;
    task.solve();
    return 0;
}
