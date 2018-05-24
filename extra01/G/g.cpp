#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool possible;

void operands (vector<int> &numbers, vector<int> &operators) {
    int total = numbers[0];

    for (int i = 0; i < 4; i++) {
        if (operators[i] == 0) {
            total += numbers[i + 1];
        }
        else if (operators[i] == 1) {
            total *= numbers[i + 1];
        }
        else {
            total -= numbers[i + 1];
        }
    }

    if (total == 23) {
        possible = true;
    }

    if (!possible) {
        if (operators[3] < 2) {
            operators[3]++;
            operands(numbers, operators);
            operators[3]--;
        }
        if (operators[2] < 2) {
            operators[2]++;
            operands(numbers, operators);
            operators[2]--;
        }
        if (operators[1] < 2) {
            operators[1]++;
            operands(numbers, operators);
            operators[1]--;
        }
        if (operators[0] < 2) {
            operators[0]++;
            operands(numbers, operators);
            operators[0]--;
        }
    }
}

void attempt2 (vector<int> &numbers) {

    vector<int> operators(4);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    operators[0] = i;
                    operators[1] = j;
                    operators[2] = k;
                    operators[3] = l;

                    int total = numbers[0];
                    for (int i = 0; i < 4; i++) {
                        if (operators[i] == 0) {
                            total += numbers[i + 1];
                        }
                        else if (operators[i] == 1) {
                            total *= numbers[i + 1];
                        }
                        else {
                            total -= numbers[i + 1];
                        }
                    }

                    if (total == 23) {
                        possible = true;
                    }
                }
            }
        }
    }
}


int main() {

    while (true) {
        vector<int> numbers(5);

        for (int i = 0; i < 5; i++) {
            cin >> numbers[i];
        }

        bool all_zeros = true;
        for (int i = 0; i < 5; i++) {
            if (numbers[i] != 0) {
                all_zeros = false;
            }
        }
        if (all_zeros) {
            break;
        }

        possible = false;
        sort(numbers.begin(), numbers.end());
        do {
//            vector<int> operators(4, 0);
            attempt2(numbers);
        } while (next_permutation(numbers.begin(), numbers.end()));

        if (possible) {
            cout << "Possible\n";
        }
        else {
            cout << "Impossible\n";
        }

    }

    return 0;
}