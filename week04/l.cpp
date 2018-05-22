#include <iostream>
#include <algorithm>

#include <vector>
using namespace std;


int main() {

    long int n, i, aux;

    cin >> n;

    while (n != 0)  {
        vector <long int> idades (101, 0);
        for (i = 0; i < n; i++) {
            cin >> aux;
            idades[aux]++;
        }
        for (i = 1; i < 101; i++) {
            while (idades[i] > 0) {
                cout << i;
                if (n > 1) {
                    cout << " ";
                    n--;
                }
                idades[i]--;
            }
        }
        cout << endl;
        cin >> n;
    }
    

    return 0;
}