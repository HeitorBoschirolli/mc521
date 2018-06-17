#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool distribute (vector<int> &locations, int num_cows, int max_min_distance) {

    int cows_left = num_cows - 1; // the first cow is in the first position
    int last_occupied = locations[0];

    for (int i = 1; i < locations.size(); i++) {
        if ((locations[i] - last_occupied) >= max_min_distance) {
            cows_left--;
            last_occupied = locations[i];
        }
    }

    if (cows_left <= 0) {
        return true;
    }
    else {
        return false;
    }
}

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n, c;
        cin >> n >> c;

        vector <int> locations (n);
        int temp;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            locations[i] = temp;
        }

        sort(locations.begin(), locations.end());
        int max = locations[locations.size() - 1];
        int min = 1;

        int mid;
        while (min != max) {
            if (mid == ((min + max)/2)) {
                break;
            }
            mid = (min + max)/2;
            if (distribute(locations, c, mid)) {
                min = mid;
            }
            else {
                max = mid;
            }
        }

        cout << mid << endl;


    }

    return 0;
}