#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <cstdio>
#include <limits>

using namespace std;

int main() {

    int n, m, k;
    cin >> n >> m >> k;

    vector < deque < pair <int, int> > > adj (n + 1);
    int temp1;
    int temp2;
    int temp3;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &temp1, &temp2, &temp3);
        adj[temp1].push_back(make_pair(temp2, temp3));
        adj[temp2].push_back(make_pair(temp1, temp3));
    }

    vector <int> storages(k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &temp1);
        storages[i] = temp1;
    }

    sort(storages.begin(), storages.end());

    int min = numeric_limits<int>::max();
    vector <int> :: iterator it;
    pair <int, int> city;
    for (int i = 0; i < k; i++) {
        while (!adj[storages[i]].empty()) {
            city = adj[storages[i]].front();
            adj[storages[i]].pop_front();

            if (!binary_search(storages.begin(), storages.end(), city.first)) {
                if (city.second < min) {
                    min = city.second;
                }
            }
        }
    }

    if (min < numeric_limits<int>::max())
        cout << min << endl;
    else
        cout << "-1\n";

    return 0;
}