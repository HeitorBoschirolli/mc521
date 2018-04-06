#include <iostream>
#include <vector>

using namespace std;

int main() {

    int num_testes;

    cin >> num_testes;

    while(num_testes--) {

        int r, c;
        cin >> r;
        cin >> c;
        vector<vector<char> > map(r, vector<char>(c));
        vector<vector<char> > map_copy(r, vector<char>(c));

        char temp;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> temp;
                map[i][j] = temp;
                map_copy[i][j] = temp;
            }
        }

        int changes = 1;
        while (changes != 0) {
            changes = 0;
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    int num_civ = 0;
                    char civ = '.';
                    if (map[i][j] == '.') {
                        if (i >= 1 && map[i - 1][j] != '#' && map[i - 1][j] != '*' && map[i - 1][j] != '.') {
                            num_civ++;
                            civ = map[i - 1][j];
                        }
                        if (j >= 1 && map[i][j - 1] != '#' && map[i][j - 1] != '*' && map[i][j - 1] != '.') {
                            if (civ != map[i][j - 1]) {
                                num_civ++;
                                civ = map[i][j - 1];
                            }
                        }
                        if (i < r - 1 && map[i + 1][j] != '#' && map[i + 1][j] != '*' && map[i + 1][j] != '.') {
                            if (civ != map[i + 1][j]) {
                                num_civ++;
                                civ = map[i + 1][j];
                            }
                        }
                        if (j < c - 1 && map[i][j + 1] != '#' && map[i][j + 1] != '*' && map[i][j + 1] != '.') {
                            if (civ != map[i][j+1]) {
                                num_civ++;
                                civ = map[i][j + 1];
                            }
                        }
                        if (num_civ == 1) {
                            map_copy[i][j] = civ;
                            changes++;
                        }
                        else if (num_civ >= 2) {
                            changes++;
                            map_copy[i][j] = '*';
                        }
                    }
                }
            }

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    map[i][j] = map_copy[i][j];
                }
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << map[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}