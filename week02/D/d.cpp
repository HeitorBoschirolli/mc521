#include <iostream>
#include <vector>

using namespace std;

int num_vertices, num_edges;
vector<bool> visited; // false indicates that the vertex was not visited

bool tree (vector< vector<int> > adj, int index, int node_pre) {
    bool return_value = true;

    visited[index] = true;

    for(int j = 1; j <= num_vertices && return_value; j++){
        if (adj[index][j] == 1) {
            int next_node = j;
            if (visited[next_node] == true && next_node != node_pre) {
                return_value = false;
            } else if (visited[next_node] == false) {
                return_value = tree(adj, next_node, index);
            }
        }
    }

    return return_value;
}

int main() {

    int case_num = 1;
    while (true) {
        cin >> num_vertices;
        cin >> num_edges;

        //vis.assign(num_vertices,0);
        if (num_vertices == 0 && num_edges == 0) {
            break;
        }

        visited.clear();
        for (int i = 0; i <= num_vertices; i++) {
            visited.push_back(false);
        }

        vector< vector<int> > adj(num_vertices + 1, vector<int> (num_vertices + 1, 0));
        for (int i = 1; i <= num_edges; i++) {
            int vertex1;
            int vertex2;
            cin >> vertex1;
            cin >> vertex2;

            adj[vertex1][vertex2] = 1;
            adj[vertex2][vertex1] = 1;
        }

        int num_trees = 0;
        for (int i = 1; i <= num_vertices; i++) {
            if (!visited[i]) {
                if (tree(adj, i, -1)) {
                    num_trees++;
                }
            }
        }

        cout << "Case " << case_num << ": ";
        if (num_trees == 0) {
            cout << "No trees." << endl;
        }
        else if (num_trees == 1) {
            cout << "There is one tree." << endl;
        }
        else {
            cout << "A forest of " << num_trees << " trees." << endl;
        }

        case_num++;
    }

    return 0;
}