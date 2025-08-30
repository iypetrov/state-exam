#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int x, int len, vector<vector<int>> adj) {
    vector<bool> visited(len, false);
    queue<int> q;
    q.push(x);
    visited[x] = true;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    return 0;
}
