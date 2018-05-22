#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
using namespace std;


int main() {
    string input;
    int num_changes;
    cin >> input;
    cin >> num_changes;

    int size = input.size();
    vector<int> inv (ceil(size/2), 0);
    int place, temp;

    for (int i = 0; i < num_changes; i++) {
        cin >> temp;
        inv[temp-1]++;

    }

    char temp2;
    int total = 0;
    for (int j = 0; j < ceil(size/2) ; j++) {

        if ((inv[j] + total) % 2 != 0) {
            temp2 = input[j];
            input[j] = input[size -1 - j];
            input[size - 1 - j] = temp2;

        }
        total += inv[j];
    }

    std::cout << input << endl;

    return 0;
}