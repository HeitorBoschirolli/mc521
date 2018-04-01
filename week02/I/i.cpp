#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

struct team {
    int id;
    deque <int> team_queue;
} typedef team;

int main() {
    int number_of_the_scenario = 1;
    while (true) {
        int num_teams;
        cin >> num_teams;

        if (num_teams == 0) {
            break;
        }

        cout << "Scenario #" << number_of_the_scenario << endl;
        number_of_the_scenario++;

        deque<team> queue;
        deque<team> all_teams;

        for (int i = 0; i < num_teams; i++) {
            int num_members;

            cin >> num_members;
            deque<int> members;
            for (int j = 0; j < num_members; j++) {
                int temp;
                cin >> temp;

                members.push_back(temp);
            }

            sort (members.begin(), members.end());
            team curr_team;
            curr_team.id = i;
            curr_team.team_queue = members;
            all_teams.push_back(curr_team);
        }

        while (true) {
            string action;
            cin >> action;

            if (!action.compare("STOP")) {
                break;
            }

            if (!action.compare("ENQUEUE")) {
                int element;
                cin >> element;
                int element_id;
//                cout << "you are about to enqueue" << endl;
                bool found_id = false;

                // descobre o id do elemento que quer entrar na fila
                bool is_there;
                int index;
                for (int i = 0; i < all_teams.size() && !found_id; i++) {
                    is_there = binary_search(all_teams[i].team_queue.begin(), all_teams[i].team_queue.end(), element);
                    if (is_there) {
                        index = lower_bound(all_teams[i].team_queue.begin(), all_teams[i].team_queue.end(), element)
                                - all_teams[i].team_queue.begin();
                        element_id = all_teams[i].id;
//                        cout << "id:" << element_id << endl;
                        break;
                    }
//                    for (int j = 0; j < all_teams[i].team_queue.size() && !found_id; j++) {
//                        if (all_teams[i].team_queue[j] == element) {
//                            element_id = all_teams[i].id;
//                            found_id = true;
//                        }
//                    }
                }

                // verifica se tem alguem com esse id na fila
                bool found_team = false;
                for (int i = 0; i < queue.size(); i++) {
                    if (queue[i].id == element_id) {
                        queue[i].team_queue.push_back(element);
                        found_team = true;
                        break;
                    }
                }
                if (!found_team) {
                    team temp_team;
                    deque<int> temp_team_queue;

                    temp_team_queue.push_back(element);
                    temp_team.id = element_id;
                    temp_team.team_queue = temp_team_queue;

                    queue.push_back(temp_team);
                }
            }
            else {
//                cout << "you are about to dequeue" << endl;
                cout << queue[0].team_queue.front() << endl;
                queue[0].team_queue.pop_front();
                if (queue[0].team_queue.size() == 0) {
                    queue.pop_front();
                }
            }
        }
        cout << endl;
    }

    return 0;
}