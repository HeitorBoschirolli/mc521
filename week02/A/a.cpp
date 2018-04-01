#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

struct number {
    long frequency;
    long value;
    long first_ap;
};

bool order (struct number a, struct number b) {
    if (a.frequency == b.frequency) {
        return a.first_ap < b.first_ap;
    }
    return a.frequency > b.frequency;
}

int main() {
    int n;
    int c;
    long temp;

    cin >> n;
    cin >> c;

    vector<struct number> values(n);

    for (int i = 0; i < n; i++) {
        values[i].frequency = 0;
        values[i].value = -1;
        values[i].first_ap = -1;
    }

    int sequence = 1;
    int achou = false;
    for (int i = 0; i < n; i++) {
        achou = false;
        cin >> temp;
        values[i].value = temp;
        values[i].frequency++;

        for (int j = 0; j < i; j++) {
            if (values[j].value == values[i].value) {
                values[i].frequency++;
                values[j].frequency++;
                values[i].first_ap = values[j].first_ap;
                achou = true;
            }
        }
        if (!achou) {
            values[i].first_ap = i;
        }
    }

    stable_sort(values.begin(), values.end(), order);

    for (int i = 0; i < n; i++) {
        cout << values[i].value << " ";
    }
    cout << endl;

    return 0;
}