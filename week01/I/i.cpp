#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

list<int> change(list<int> some_list, int index) {
    list<int> sequence = some_list;

    int temp;
    for (int i = 0; i < index; i++) {
        temp = sequence.front();
        sequence.pop_front();
        sequence.push_back(temp);
    }
    sequence.pop_front();

    return sequence;
}

int max(list<int> some_list) {
    list<int> other_list = some_list;
    int curr_max = other_list.front();
    int index = 0;
    other_list.pop_front();

    int i = 1;
    while(!other_list.empty()) {
        if (curr_max < other_list.front()) {
            index = i;
            curr_max = other_list.front();
        }
        other_list.pop_front();
        i++;
    }

    return index;
}

int main() {
    int num_tests, num_jobs, position;

    cin >> num_tests;

    list<int> sequence;

    for (int i = 0; i < num_tests; i++) {
        sequence.clear();
        int time = 1;
        cin >> num_jobs;
        cin >> position;

        int temp;
        for (int j = 0; j < num_jobs; j++) {
            cin >> temp;
            sequence.push_back(temp);
        }
//        cout << "pru" << endl;
        while (true) {
//                    cout << "i: " << i << endl;
            //        for (auto v : sequence)
            //            cout << v << " ";
            //        cout << "..." <<position << endl;
            int index = max(sequence);
            if (index == position) {
                //            cout << "if" << endl;
                break;
            } else if (index > position) {
                //            cout << "else if" << endl;
                position += sequence.size() - index - 1;
                time++;
            } else {
                //            cout << "else" << endl;
                position -= index + 1;
                time++;
            }

            sequence = change(sequence, index);
        }
        cout << time << endl;
    }
    return 0;
}