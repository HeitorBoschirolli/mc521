#include<iostream>
#include<vector>

using namespace std;

int main() {

    while (true) {
        int n;
        cin >> n;

        if (n == -1) {
            break;
        }

        int temp;
        int times = 0;
        long total = 0;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            total += temp;
            if (total % 100 == 0) {
                total = 0;
                times++;
            }
        }
        cout << times << endl;
    }




    return 0;
}