#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	vector<vector<int>> a(10);
	vector<bool> visited((int) s.size(), false);
	// create a graph wherein the characters (digits) from the string contain their current indices
	for (int i = 1; i < (int) s.size(); i++) {
		a[s[i] - '0'].emplace_back(i);
	}
	vector<int> distance((int) s.size(), 0);
	// set the distance of the first element to 0 (starting position)
	distance[0] = 0;
	// visit the first element (starting position)
	visited[0] = true;
	queue<int> q;
	// insert the index 0 (starting position) into the queue
	q.push(0);
	// use BFS to calculate the minimum distance from the first to the last index
	while (!q.empty()) {
		int index = q.front();
		if (index == (int) s.size() - 1) {
			// if we have reached the last index, then break the loop
			break;
		}
		q.pop();
		// visit the adjacent vertices of the current vertex
		int u = s[index] - '0';
		for (int v = 0; v < (int) a[u].size(); v++) {
			if (!visited[a[u][v]]) {
				visited[a[u][v]] = true;
				q.push(a[u][v]);
				// the distance to the next adjacent vertex would be the (current distance + 1)
				distance[a[u][v]] = distance[index] + 1;
			}
		}
		// clear the adjacent vertices visited
		a[u].clear();
		// visit the previous index (since they are connected)
		if (index - 1 >= 0 && !visited[index - 1]) {
			visited[index - 1] = true;
			q.push(index - 1);
			distance[index - 1] = distance[index] + 1;
		}
		// visit the next index (since they are connected)
		if (index + 1 < (int) s.size() && !visited[index + 1]) {
			visited[index + 1] = true;
			q.push(index + 1);
			distance[index + 1] = distance[index] + 1;
		}
	}
	// output the value at the last index
	cout << distance[(int) s.size() - 1] << '\n';
	return 0;
}
