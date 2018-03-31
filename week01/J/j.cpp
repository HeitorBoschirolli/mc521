#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
    int num_vectors;

    cin >> num_vectors;

    vector<int> a(num_vectors);
    vector<int> b(num_vectors);
    vector<int> c(num_vectors);
    vector<int> d(num_vectors);

    for (int i = 0; i < num_vectors; i++) {
        cin >> a[i];
        cin >> b[i];
        cin >> c[i];
        cin >> d[i];
    }

    vector<int> ab(num_vectors * num_vectors);

    for (int i = 0; i < num_vectors; i++) {
        for (int j = 0; j < num_vectors; j++) {
            ab[num_vectors * i + j] = a[i] + b[j];
        }
    }

    vector<int>().swap(a);
    vector<int>().swap(b);

    vector<int> cd(num_vectors * num_vectors);
    for (int i = 0; i < num_vectors; i++) {
        for (int j = 0; j < num_vectors; j++) {
            cd[num_vectors * i + j] = c[i] + d[j];
        }
    }

    vector<int>().swap(a);
    vector<int>().swap(b);

    sort(ab.begin(), ab.end()); // nao precisa disso
    sort(cd.begin(), cd.end());

    int num_respostas = 0;
    for (int i = 0; i < num_vectors * num_vectors; i++) {
        long is_there = binary_search(cd.begin(), cd.end(), -ab[i]);
        long low = lower_bound(cd.begin(), cd.end(), -ab[i]) - cd.begin();
        long up = upper_bound(cd.begin(), cd.end(), -ab[i]) - cd.begin();

        if (is_there) {
            for (int j = low; j < up; j++) {
                num_respostas++;
            }
        }
    }

    cout << num_respostas << endl;

    return 0;
}