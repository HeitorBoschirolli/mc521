#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int main() {

    int num_tests;
    cin >> num_tests;

    for (int k = 0; k < num_tests; k++) {

        string left;
        string right;
        string balance;

        vector<int> heavy(13, 0);
        vector<int> light(13, 0);
        vector<bool> ok(13, false);
        int ups_and_downs = 0;
        for (int i = 0; i < 3; i++) {
            cin >> left;
            cin >> right;
            cin >> balance;

            if (balance[0] == 'e') {
                for (int j = 0; j < left.size(); j++) {
                    ok[left[j] - 64] = true;
                    ok[right[j] - 64] = true;
                }
            }
            else if (balance[0] == 'u') {
                ups_and_downs++;
                for (int j = 0; j < left.size(); j++) {
                    heavy[left[j] - 64]++;
                    light[right[j] - 64]++;
                }
            }
            else {
                ups_and_downs++;
                for (int j = 0; j < left.size(); j++) {
                    light[left[j] - 64]++;
                    heavy[right[j] - 64]++;
                }
            }
        }

        char result = '?';
        bool is_heavy = false;

        for (int i = 1; i < heavy.size(); i++) {
            if (!ok[i] && heavy[i] == ups_and_downs) {
                is_heavy = true;
                result = i + 64;
                break;
            }
        }

        for (int i = 1; i < light.size(); i++) {
            if (!ok[i] && light[i] == ups_and_downs) {
                is_heavy = false;
                result = i + 64;
                break;
            }
        }

//        cout << "ok:" << endl;
//        for (int i = 0; i < ok.size(); i++) {
//            cout << ok[i] << " ";
//        }
//        cout << endl;
//
//        cout << "heavy:" << endl;
//        for (int i = 0; i < heavy.size(); i++) {
//            cout << heavy[i] << " ";
//        }
//        cout << endl;
//
//        cout << "light:" << endl;
//        for (int i = 0; i < light.size(); i++) {
//            cout << light[i] << " ";
//        }
//        cout << endl;

        if (is_heavy) {
            cout << result << " is the counterfeit coin and it is heavy." << endl;
        }
        else {
            cout << result <<  " is the counterfeit coin and it is light." << endl;
        }
    }

    return 0;
}