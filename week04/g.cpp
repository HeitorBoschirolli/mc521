#include <iostream>
#include <algorithm>

using namespace std;


int main() {

    int n;
    long sum, prev_sum;

    cin >> n;
    while ( n ) {
    
        prev_sum = -1;
        sum = 0;

        while (prev_sum != sum) {

            prev_sum = sum;
            sum = 0;

            while (n) {

                sum += n % 10;
                n /= 10;
            }

            n = sum;

        }

        cout << n << endl;

        cin >> n;
    }


    return 0;
}