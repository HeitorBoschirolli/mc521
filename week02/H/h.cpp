#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    while (true) {
        int n;
        cin >> n;

        if (n == 0) {
            break;
        }

        vector<int> numbers(n);
        for (int i = 0; i < numbers.size(); i++) {
            cin >> numbers[i];
        }

        int custo = 0;
        int temp;
        int curr_size = numbers.size();
        while (curr_size > 1) {
            sort(numbers.rbegin(), numbers.rend());
            temp = numbers[numbers.size() - 1] + numbers[numbers.size() - 2];
            numbers.pop_back();
            numbers[numbers.size() - 1] = temp;
            custo += temp;
            curr_size = numbers.size();
        }
        cout << custo << endl;

    }

    return 0;
}