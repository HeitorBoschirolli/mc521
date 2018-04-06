#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctype.h>
#include <stdio.h>

using namespace std;

int main() {
//    string input;
//    vector<string> words;
    while (true) {
        string s;
        getline(cin, s);
        string stop = "*";
        if (s == stop) {
            break;
        }

        istringstream iss(s);

        vector<string> subs;
        do {
            string temp;
            iss >> temp;
            subs.push_back(temp);
        } while (iss);

//    for (int i = 0; i < subs.size(); i++){
//        cout << subs[i] << endl;
//    }

        char letter = subs[0][0];
        bool is_it = true;
        for (int i = 1; i < subs.size() - 1; i++) {
            if (letter != tolower(subs[i][0]) && letter != toupper(subs[i][0])) {
                is_it = false;
                break;
            }
        }

        if (is_it == false) {
            cout << "N" << endl;
        } else {
            cout << "Y" << endl;
        }
    }

    return 0;
}