#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector <int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    int prev = numbers[0];
    int cost = 0;
    for (int i = 1; i < n; i++) {
        if (prev == numbers[i]) {
            numbers[i]++;
            cost++;
        }
        else if (numbers[i] < prev) {
            int temp = prev - numbers[i];
            numbers[i] += temp;
            cost += temp;
            numbers[i]++;
            cost++;
        }
        prev = numbers[i];
    }

    cout << cost << endl;

    return 0;
}