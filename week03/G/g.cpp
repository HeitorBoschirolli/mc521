#include <iostream>
#include <vector>

using namespace std;

int mod_exp(int x, int y, int n) {

    if (y == 1) {
        return x % n;
    }
    int a;
    if (y % 2 == 0) {
        a = mod_exp(x, y / 2, n) % n;
        return (a * a) % n;
    }
    else {
        int y_temp = y - 1;
        a = mod_exp(x, y_temp/2, n) % n;
        int result_temp = (a * a) % n;
        return ((x % n) * result_temp) % n;
    }
}

int main() {

    int num_tests;
    cin >> num_tests;

    for (int i = 0; i < num_tests; i++) {
        int x, y, n;
        cin >> x;
        cin >> y;
        cin >> n;

        int result = mod_exp(x, y, n);

        cout << result << endl;
    }

    return 0;
}