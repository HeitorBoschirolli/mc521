#include <vector>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

#define infinite 2000000000000
#define free -1
#define blocked -2
#define white 1
#define gray 2
#define black 3

long long rows;
long long cols;
vector < vector <long long> > city;
vector < vector <long long> > colors;
vector < vector <long long> > dists;
vector < vector <long long> > n_paths;
queue < pair <long long, long long> > q;

void clear(queue< pair <long long, long long> > &q) {
   std::queue< pair <long long, long long> > empty;
   std::swap( q, empty );
}

void bfs() {

	while (!q.empty()) {
		pair <long long, long long> u = q.front();
		q.pop();

		if ((u.second + 1 <= cols) && (city[u.first][u.second + 1] == free)) {
			if (colors[u.first][u.second + 1] == white) {
				colors[u.first][u.second + 1] = gray;
				dists[u.first][u.second + 1] = dists[u.first][u.second] + 1;
				q.push(make_pair(u.first, u.second + 1));
				n_paths[u.first][u.second + 1] = n_paths[u.first][u.second];
			}
			else if (dists[u.first][u.second + 1] == dists[u.first][u.second] + 1) {
				n_paths[u.first][u.second + 1] += n_paths[u.first][u.second];
			}
		}
		// if ((u.second - 1 >= 1) && (city[u.first][u.second - 1] == free)) {
		// 	if (colors[u.first][u.second - 1] == white) {
		// 		colors[u.first][u.second - 1] = gray;
		// 		dists[u.first][u.second - 1] = dists[u.first][u.second] + 1;
		// 		q.push(make_pair(u.first, u.second - 1));
		// 		n_paths[u.first][u.second - 1] = n_paths[u.first][u.second];
		// 	}
		// 	else if (dists[u.first][u.second - 1] == dists[u.first][u.second] + 1) {
		// 		n_paths[u.first][u.second - 1] += n_paths[u.first][u.second];
		// 	}
		// }
		if ((u.first + 1 <= rows) && (city[u.first + 1][u.second] == free)) {
			if (colors[u.first + 1][u.second] == white) {
				colors[u.first + 1][u.second] = gray;
				dists[u.first + 1][u.second] = dists[u.first][u.second] + 1;
				q.push(make_pair(u.first + 1, u.second));
				n_paths[u.first + 1][u.second] = n_paths[u.first][u.second];
			}
			else if (dists[u.first + 1][u.second] == dists[u.first][u.second] + 1)  {
				n_paths[u.first + 1][u.second] += n_paths[u.first][u.second];	
			}
		}
		// if ((u.first - 1 >= 1) && (city[u.first - 1][u.second] == free)) {
		// 	if (colors[u.first - 1][u.second] == white) {
		// 		colors[u.first - 1][u.second] = gray;
		// 		dists[u.first - 1][u.second] = dists[u.first][u.second] + 1;
		// 		q.push(make_pair(u.first - 1, u.second));
		// 		n_paths[u.first - 1][u.second] = n_paths[u.first][u.second];
		// 	}
		// 	else if (dists[u.first - 1][u.second] == dists[u.first][u.second] + 1){
		// 		n_paths[u.first - 1][u.second] += n_paths[u.first][u.second];
		// 	}
		// }
		colors[u.first][u.second] = black;
	}
}

int main() {

	long long t;
	cin >> t;
	bool first = true;
	while (t--) {
		cin >> rows;
		cin >> cols;

		city.clear();
		colors.clear();
		dists.clear();
		clear(q);

		city.assign(rows + 1, vector <long long> (cols + 1, free)); // vector starting from 1
		colors.assign(rows + 1, vector <long long> (cols + 1, white)); // also starting from 1
		dists.assign(rows + 1, vector <long long> (cols + 1, infinite)); // from 1...
		n_paths.assign(rows + 1, vector <long long> (cols + 1, 0)); // from 1...

		n_paths[1][1] = 1;
		colors[1][1] = gray;
		dists[1][1] = 0;
		q.push(make_pair(1, 1));

        int x, y;
		scanf(" ");
		for (long long i = 1; i <= rows; i++) {
			string b_streets;
			getline(cin, b_streets);
			stringstream sin(b_streets);
			sin >> x;
			while (sin >> y) {
				city[x][y] = blocked;
			}
		}

		if (city[1][1] == blocked)
			cout << 0 << endl;
		else {
			bfs();

			if (!first)
				cout << endl;
			cout << n_paths[rows][cols] << endl;
		}

		first = false;

	}

	return 0;
}