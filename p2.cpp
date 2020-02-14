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
    long long N, k;
    std::vector<long long> sir;
    long long solution;

    void read_input() {
        std::ifstream fin("p2.in");
        fin >> N >> k;
        long long n;
        for (int i = 0; i < N; i++) {
            fin >> n;
            sir.push_back(n);
            std::cout << n << " ";
        }
        fin.close();
    }
    // Comparator, sortam in ordine descrescatoare
    static bool comparator(long long ob1, long long ob2) {
        return (ob1 > ob2);
    }

    long long findSolution(const std::vector<long long> &sir) {
        std::vector<std::vector<long long>> dp
        (k + 1, std::vector<long long>(sir.size()));
        printf("\n ");
        // Completam prima linie a matricei dp
        long long sum_Tzugu = 0;
        long long sum_Ritza = 0;
        long long i;
        for (i = 0; i < sir.size(); ++i) {
               if (!(i & 1)) {
                   sum_Tzugu += sir[i];
               } else {
                   sum_Ritza += sir[i];
               } 
           dp[0][i] = sum_Tzugu - sum_Ritza;
        }
        // Continuam sa completam si celelalte linii (1 -> k)
        for (long long i = 1; i <= k; i++) {
            unsigned l;
            // Eliminam elemente pe fiecare linie pana la k
            // Adica punem 0 pe primele i pozitii de pe linia i
            for (l = 0; l < i; l++) {
                    dp[i][l] = 0;
            }
            // Completez in continuare, dupa ce am eliminat i elemente
            for (unsigned j = l; j < sir.size(); j++) {
                long long number;
                if ((j - i) % 2 == 0) {
                    // Daca e pozitie para, adun
                    number = dp[i][j - 1] + sir[j];
                } else {
                    // Daca e pozitie impara, scad
                    number = dp[i][j - 1] - sir[j];
                }
                dp[i][j] = std::max(number, dp[i - 1][j - 1]);
            }
        }
        return dp[k][sir.size() - 1];
    }

    long long get_result() {
        // Sortam in ordine descrescatoare
        std::sort(sir.begin(), sir.end(), comparator);
        solution = findSolution(sir);
        return solution;
    }

    void print_output(long long result) {
        std::ofstream fout("p2.out");
        fout << result;
        fout.close();
    }
};

int main() {
    Task task;
    task.solve();
    return 0;
}
