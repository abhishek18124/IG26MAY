/*

https://cses.fi/problemset/task/1629/

input
3
3 5
4 9
5 8

output
2

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<pair<int, int>> movies(n);

	for (int i = 0; i < n; i++) {
		// storing as {end, start} for easy sorting
		int start, end;
		cin >> start >> end;
		movies[i] = {end, start};
	}

	sort(movies.begin(), movies.end()); // nlogn

	int maxMovies  = 0; // tracks maximum no. of movies
	int lastEnd = 0;

	for (int i = 0; i < n; i++) { // n
		int end   = movies[i].first;
		int start = movies[i].second;
		if (start >= lastEnd) {
			maxMovies++;
			lastEnd = end;
		}
	}

	cout << maxMovies << "\n";

	// time : nlogn + n ~ O(nlogn)

	return 0;
}