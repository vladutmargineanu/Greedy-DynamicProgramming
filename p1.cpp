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
    int N;
    std::vector<int> sir;

    void read_input() {
        std::ifstream fin("p1.in");
        fin >> N;
        int n;
        for (int i = 0; i < N; i++) {
            fin >> n;
            sir.push_back(n);
        }
        fin.close();
    }
    // Comparator pentru sortare in ordine descrescatoare
    static bool comparator(int ob1, int ob2) {
        return (ob1 > ob2);
    }

    int get_result() {
        // Sortam in ordine descrescatoare
        std::sort(sir.begin(), sir.end(), comparator);

        int sum_Tzugu = 0;
        int sum_Ritza = 0;
        // Pe pozitiile pare sunt elementele pe care le alege Tzugu
        // Pe pozitiile impare sunt elementele pe care le alege Ritza
        for (int i = 0; i < N; i++) {
            if (!(i & 1)) {
                sum_Tzugu += sir[i];
            } else {
                sum_Ritza += sir[i];
            }
        }

        return sum_Tzugu - sum_Ritza;
    }

    void print_output(int result) {
        std::ofstream fout("p1.out");
        fout << result;
        fout.close();
    }
};

int main() {
    Task task;
    task.solve();
    return 0;
}