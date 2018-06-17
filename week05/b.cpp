#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    unsigned long long n_tests;
    cin >> n_tests;

    vector <unsigned long long> triangles (1000000 + 3, 0);

    triangles[0] = 0;
    triangles[1] = 0;
    triangles[2] = 0;

    while (n_tests--) {
        unsigned long long n_sticks;
        cin >> n_sticks;

        if (triangles[n_sticks] != 0)
            cout << triangles[n_sticks] << endl;

        else {
            unsigned long long temp;
            for (unsigned long long i = 3; i <= n_sticks; i++) {
                if (i % 2 == 1) {
                    temp = floor(i / 2) * (floor(i / 2) - 1);
                } else {
                    temp = floor(i / 2) * (floor(i / 2) - 1) - (floor(i / 2) - 1);
                }
                triangles[i] = triangles[i - 1] + temp;
            }

            cout << triangles[n_sticks] << endl;
        }
    }


    return 0;
}