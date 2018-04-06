#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int size;

void count(vector< vector<int> > &adj_matrix, vector<bool> &visited, int num_vertices, int index) {

    size++;
    visited[index] = true;

    for (int i = 0; i < num_vertices; i++) {
        if (adj_matrix[index][i] == 1 && !visited[i]) {
            count(adj_matrix, visited, num_vertices, i);
        }
    }
}

int main() {

    while (true) {
        int num_vertices;
        int num_edges;

        cin >> num_vertices;
        cin >> num_edges;

        if (num_edges == 0 && num_vertices == 0) {
            break;
        }

        map <string, int> names;
        string temp;
        for (int i = 0; i < num_vertices; i++) {
            cin >> temp;
            names[temp] = i;
        }

        vector <vector <int> > adj_matrix(num_vertices, vector<int> (num_vertices, 0));

        int vertex1;
        int vertex2;
        string temp2;
        for (int i = 0; i < num_edges; i++) {
            cin >> temp;
            cin >> temp2;

            vertex1 = names[temp];
            vertex2 = names[temp2];

            adj_matrix[vertex1][vertex2] = 1;
            adj_matrix[vertex2][vertex1] = 1;
        }

        vector<bool> visited(num_vertices, false);

        int max_size = 0;
        for (int i = 0; i < num_vertices; i++) {
            if (visited[i] == false) {
                size = 0;
                count(adj_matrix, visited, num_vertices, i);
                if (size > max_size) {
                    max_size = size;
                }
            }
        }

        cout << max_size << endl;

    }


    return 0;
}