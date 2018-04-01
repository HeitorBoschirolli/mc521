#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct num_pow {
    int num;
    int power;
} typedef num_pow;

bool sort_func (num_pow i, num_pow j) {
    return i.num < j.num;
}

int main() {
    int num_testes;
    cin >> num_testes;

    for (int i = 0; i < num_testes; i++) {
        int n, a, b;
        cin >> n;
        cin >> a;
        cin >> b;

        int prev = 1;
        int curr = 1;
        int temp;
        for (int j = 3; j <= n; j++) {
            temp = curr;
            curr = prev + curr;
            prev = temp;
        }

        vector<num_pow> fact_a;
        int size = a;
        for (int j = 2; j <= a; j++) {
            bool found = false;
            while (a % j == 0) {
                for (int k = 0; k < fact_a.size(); k++) {
                    if (fact_a[k].num == j) {
                        fact_a[k].power += prev;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    num_pow temp;
                    temp.num = j;
                    temp.power = prev;
                    fact_a.push_back(temp);
                }
                a /= j;
            }
        }

        size = b;
        for (int j = 2; j <= size; j++) {
            bool found = false;
            while (b % j == 0) {
                for (int k = 0; k < fact_a.size(); k++) {
                    if (fact_a[k].num == j) {
                        fact_a[k].power += curr;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    num_pow temp;
                    temp.num = j;
                    temp.power = curr;
                    fact_a.push_back(temp);
                }
                b /= j;
            }
        }

        sort (fact_a.begin(), fact_a.end(), sort_func);

        for (int j = 0; j < fact_a.size(); j++) {
            cout << fact_a[j].num << " " << fact_a[j].power << endl;
        }
        cout << endl;
    }

    return 0;
}