#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int x, int len, vector<vector<int>> adj) {
    vector<bool> visited(len, false);
    stack<int> s;
    s.push(x);

    while(!s.empty()) {
        int curr = s.top();
        s.pop();

        visited[curr] = true;
        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                s.push(neighbor);
            }
        }
    }
}

int main() {
    return 0;
}
