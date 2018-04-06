#include <iostream>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;

unsigned long long total_digits;
unsigned long long divd;
deque<unsigned long long> all_divs;

void list_all(unsigned long long num_digits, unsigned long long number) {

    if (num_digits == total_digits) {
        if (number % divd == 0) {
            all_divs.push_back(number);
        }
        return;
    }

    list_all(num_digits + 1, number * 10 + 1);
    list_all(num_digits + 1, number * 10 + 2);

    return;
}

int main() {

    unsigned long long num_tests;
    cin >> num_tests;

    for (unsigned long long k = 1; k <= num_tests; k++) {
        all_divs.clear();

        unsigned long long q;
        cin >> total_digits;
        cin >> q;

        divd = (unsigned long long) pow(2, q);

        list_all(0, 0);

        cout << "Case " << k << ": ";
        if (all_divs.empty()) {
            cout << "impossible" << endl;
        }
        else if (all_divs.size() == 1) {
            cout << all_divs.front() << endl;
        }
        else {
            cout << *min_element(all_divs.begin(), all_divs.end()) << " " << *max_element(all_divs.begin(), all_divs.end()) << endl;
        }
    }
    return 0;
}