#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<unsigned long long> perms(5001);
    vector<unsigned long long> nums(5001);

    while (true) {
        unsigned long long n;

        string value;
        getline(cin, value);

        if ((value[0] - '0') == 0)
            break;

        for (unsigned long long i = 0; i < value.size(); i++) {
            nums[i] = (unsigned long long int)value[i] - '0';
        }

        if (value.size() == 1) {
            cout << 1 << endl;
        }
        else {
            perms[0] = 1;
            perms[1] = 2;
            if (((10 * nums[0] + nums[1]) > 26) || (nums[1] == 0)) {
                perms[1] = 1;
            }
            else if ((value.size() >= 3)){
                if (nums[2] == 0)
                    perms[1] = 1;
            }
            for (unsigned long long i = 2; i < value.size(); i++) {
                if (((10 * nums[i-1] + nums[i]) > 26) || (nums[i] == 0)) {
                    perms[i] = perms[i-1];
                }
                else if ((i < (value.size()-1)) && (nums[i+1] == 0)){
                    perms[i] = perms[i-1];
                    // perms[i-1] = perms[i-2];
                }
                else if (nums[i-1] == 0){
                    perms[i] = perms[i-1];
                }
                else {
                    perms[i] = perms[i-2] + perms[i-1];
                }
            }

            cout << perms[value.size()-1] << endl;
        }
    }

    return 0;
}
